// tiny_obj_loader.cpp

#include "tiny_obj_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

namespace tinyobj {

    bool ObjLoader::LoadObj(
            mesh_t& mesh,
            const std::string& filename
    ) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }

        std::string line;
        std::vector<float> temp_vertices;
        std::vector<float> temp_normals;
        std::vector<float> temp_texcoords;
        std::vector<unsigned int> vertexIndices, normalIndices, texcoordIndices;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            if (type == "v") {
                float x, y, z;
                iss >> x >> y >> z;
                temp_vertices.push_back(x);
                temp_vertices.push_back(y);
                temp_vertices.push_back(z);
            } else if (type == "vn") {
                float x, y, z;
                iss >> x >> y >> z;
                temp_normals.push_back(x);
                temp_normals.push_back(y);
                temp_normals.push_back(z);
            } else if (type == "vt") {
                float u, v;
                iss >> u >> v;
                temp_texcoords.push_back(u);
                temp_texcoords.push_back(v);
            } else if (type == "f") {
                unsigned int vertexIndex[3], texcoordIndex[3], normalIndex[3];
                for (int i = 0; i < 3; i++) {
                    iss >> vertexIndex[i];
                    if (iss.peek() == '/') {
                        iss.ignore();
                        if (iss.peek() != '/') {
                            iss >> texcoordIndex[i];
                        }
                        if (iss.peek() == '/') {
                            iss.ignore();
                            iss >> normalIndex[i];
                        }
                    }
                    vertexIndices.push_back(vertexIndex[i] - 1);
                    if (!temp_texcoords.empty()) {
                        texcoordIndices.push_back(texcoordIndex[i] - 1);
                    }
                    if (!temp_normals.empty()) {
                        normalIndices.push_back(normalIndex[i] - 1);
                    }
                }
            }
        }

        for (unsigned int i = 0; i < vertexIndices.size(); i++) {
            unsigned int vertexIndex = vertexIndices[i];
            mesh.vertices.push_back(temp_vertices[vertexIndex * 3]);
            mesh.vertices.push_back(temp_vertices[vertexIndex * 3 + 1]);
            mesh.vertices.push_back(temp_vertices[vertexIndex * 3 + 2]);
        }

        for (unsigned int i = 0; i < normalIndices.size(); i++) {
            unsigned int normalIndex = normalIndices[i];
            mesh.normals.push_back(temp_normals[normalIndex * 3]);
            mesh.normals.push_back(temp_normals[normalIndex * 3 + 1]);
            mesh.normals.push_back(temp_normals[normalIndex * 3 + 2]);
        }

        for (unsigned int i = 0; i < texcoordIndices.size(); i++) {
            unsigned int texcoordIndex = texcoordIndices[i];
            mesh.texcoords.push_back(temp_texcoords[texcoordIndex * 2]);
            mesh.texcoords.push_back(temp_texcoords[texcoordIndex * 2 + 1]);
        }

        for (unsigned int i = 0; i < vertexIndices.size(); i++) {
            mesh.indices.push_back(i);
        }

        file.close();
        return true;
    }

} // namespace tinyobj

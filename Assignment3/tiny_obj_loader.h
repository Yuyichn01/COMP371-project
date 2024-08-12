// tiny_obj_loader.h

#pragma once

#include <string>
#include <vector>

namespace tinyobj {

    typedef struct {
        std::string name;

        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> texcoords;

        std::vector<unsigned int> indices;
    } mesh_t;

    class ObjLoader {
    public:
        static bool LoadObj(
                mesh_t& mesh,
                const std::string& filename
        );
    };

} // namespace tinyobj

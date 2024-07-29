#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
GLuint loadShader(const char* path, GLenum shaderType);
GLuint createShaderProgram();

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float vertices[] = {
        // positions         // colors
        0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f
};

glm::mat4 transform = glm::mat4(1.0f);

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Assignment", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Build and compile the shader program
    GLuint shaderProgram = createShaderProgram();

    // Set up vertex data, buffers, and configure vertex attributes
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Activate shader
        glUseProgram(shaderProgram);

        // Pass transformation matrix to the shader
        GLuint transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        // Render the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Deallocate resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    float translationSpeed = 0.05f;
    float rotationAngle = glm::radians(30.0f);
    float scaleFactor = 1.1f;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        transform = glm::translate(transform, glm::vec3(0.0f, translationSpeed, 0.0f));
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        transform = glm::translate(transform, glm::vec3(0.0f, -translationSpeed, 0.0f));
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        transform = glm::translate(transform, glm::vec3(-translationSpeed, 0.0f, 0.0f));
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        transform = glm::translate(transform, glm::vec3(translationSpeed, 0.0f, 0.0f));

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        transform = glm::rotate(transform, rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        transform = glm::rotate(transform, -rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        transform = glm::scale(transform, glm::vec3(scaleFactor, scaleFactor, scaleFactor));
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        transform = glm::scale(transform, glm::vec3(1.0f / scaleFactor, 1.0f / scaleFactor, 1.0f / scaleFactor));
}

GLuint loadShader(const char* path, GLenum shaderType)
{
    std::ifstream shaderFile;
    shaderFile.open(path);
    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    std::string shaderCode = shaderStream.str();
    shaderFile.close();

    const char* shaderSource = shaderCode.c_str();
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader;
}

GLuint createShaderProgram()
{
    GLuint vertexShader = loadShader("shader.vs", GL_VERTEX_SHADER);
    GLuint fragmentShader = loadShader("shader.fs", GL_FRAGMENT_SHADER);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

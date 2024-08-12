cmake_minimum_required(VERSION 3.10)
project(OpenGLAssignment)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(OpenGLAssignment main.cpp)

# Specify GLFW paths
set(GLFW_INCLUDE_DIR /opt/homebrew/Cellar/glfw/3.4/include)
set(GLFW_LIBRARY /opt/homebrew/Cellar/glfw/3.4/lib/libglfw.3.4.dylib)
include_directories(${GLFW_INCLUDE_DIR})
target_link_libraries(OpenGLAssignment ${GLFW_LIBRARY})

# Specify GLEW paths
set(GLEW_INCLUDE_DIR /opt/homebrew/Cellar/glew/2.2.0_1/include)
set(GLEW_LIBRARY /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
include_directories(${GLEW_INCLUDE_DIR})
target_link_libraries(OpenGLAssignment ${GLEW_LIBRARY})

# Specify GLM path
set(GLM_INCLUDE_DIR /opt/homebrew/Cellar/glm/1.0.1/include)
include_directories(${GLM_INCLUDE_DIR})

# Link OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(OpenGLAssignment ${OPENGL_LIBRARIES})


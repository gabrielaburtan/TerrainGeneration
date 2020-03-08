cmake_minimum_required(VERSION 3.9)
project(TerrainGeneration)


#GLFW additions
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

#GLFW paths
include_directories(_external)
add_library(_external/glfw-3.2.1.bin.WIN32/lib-vc2015)
target_link_libraries(_external/glfw-3.2.1.bin.WIN32/lib-vc2015)
include_directories(_external/glfw-3.2.1.bin.WIN32/include)

#GLEW
include_directories(_external)
include_directories(_external/glew-2.1.0/lib/Release/x64)
include_directories(_external/glew-2.1.0/include)

#STBImage
include_directories(_external)
include_directories(_external/STBFolder)

#Link GLM library
include_directories(_external)
include_directories(_external/glm/glm)

#GLAD
include_directories(_external)
include_directories(_external/glad/include)
                
#My shader loader
include_directories(TerrainGeneration)

#My sources files
set(SOURCE_FILES TerrainGeneration/Main.cpp  TerrainGeneration/Camera.cpp TerrainGeneration/Shader.cpp)

#Input files to copy
configure_file(TerrainGeneration/resources/terrain.vert TerrainGeneration/resources/terrain.vert COPYONLY)
configure_file(TerrainGeneration/resources/terrain.frag TerrainGeneration/resources/terrain.frag COPYONLY)


add_executable(TerrainGeneration ${SOURCE_FILES} ${GLAD})

target_link_libraries( TerrainGeneration PRIVATE glfw3 )

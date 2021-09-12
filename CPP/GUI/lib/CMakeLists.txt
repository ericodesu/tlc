set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")

#### START OPENGL ####

find_package(OpenGL REQUIRED)

#### END OPENGL ####

#### START GLFW ####

set(GLFW_DIR "${LIB_DIR}/glfw")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("${GLFW_DIR}")

#### END GLFW ####

#### START IMGUI ####

set(IMGUI_DIR "${LIB_DIR}/imgui")

file(GLOB IMGUI_HEADER_FILES "${IMGUI_DIR}/*.h")
file(GLOB IMGUI_SOURCE_FILES "${IMGUI_DIR}/*.cpp")

add_library(imgui ${IMGUI_HEADER_FILES}
                                   ${IMGUI_SOURCE_FILES}
                                   "${IMGUI_DIR}/backends/imgui_impl_glfw.h"
                                   "${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
                                   "${IMGUI_DIR}/backends/imgui_impl_opengl2.h"
                                   "${IMGUI_DIR}/backends/imgui_impl_opengl2.cpp"
)

target_include_directories(imgui PUBLIC "${IMGUI_DIR}")
target_include_directories(imgui PUBLIC "${IMGUI_DIR}/backends")

target_link_libraries(imgui glfw)

#### END IMGUI ####

target_link_libraries(${PROJECT_NAME} OpenGL::GL imgui)
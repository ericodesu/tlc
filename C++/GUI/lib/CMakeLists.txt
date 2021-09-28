set(THIRPARTY_LIBRARIES_DIR "${PROJECT_SOURCE_DIR}/lib")

#### START OPENGL ####

find_package(OpenGL REQUIRED)

#### END OPENGL ####

#### START GLFW ####

set(GLFW_DIR "${THIRPARTY_LIBRARIES_DIR}/glfw")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("${GLFW_DIR}")

#### END GLFW ####

#### START IMGUI ####

set(IMGUI_ROOT_DIR "${THIRPARTY_LIBRARIES_DIR}/imgui")
set(IMGUI_BACKENDS_DIR "${IMGUI_ROOT_DIR}/backends")

file(GLOB IMGUI_ROOT_HEADER_LIST "${IMGUI_ROOT_DIR}/*.h")
file(GLOB IMGUI_ROOT_SOURCE_LIST "${IMGUI_ROOT_DIR}/*.cpp")

set(IMGUI_BACKENDS_HEADER_LIST "${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.h"
															 "${IMGUI_BACKENDS_DIR}/imgui_impl_opengl2.h"
)
set(IMGUI_BACKENDS_SOURCE_LIST "${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.cpp"
															 "${IMGUI_BACKENDS_DIR}/imgui_impl_opengl2.cpp"
)

set(IMGUI_ROOT_LIST ${IMGUI_ROOT_HEADER_LIST}
									   ${IMGUI_ROOT_SOURCE_LIST}	
)
set(IMGUI_BACKENDS_LIST ${IMGUI_BACKENDS_HEADER_LIST}
											   ${IMGUI_BACKENDS_SOURCE_LIST}
)

add_library(imgui STATIC ${IMGUI_ROOT_LIST}
                                                ${IMGUI_BACKENDS_LIST}
)

target_include_directories(imgui PUBLIC "${IMGUI_ROOT_DIR}")
target_include_directories(imgui PUBLIC "${IMGUI_BACKENDS_DIR}")

target_link_libraries(imgui glfw)

#### END IMGUI ####

target_link_libraries(${PROJECT_NAME} OpenGL::GL imgui)
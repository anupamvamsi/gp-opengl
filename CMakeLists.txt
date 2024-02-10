# minimum version
cmake_minimum_required(VERSION 3.12)

# ---------------------------------------------------------------------------------------------
# PROJECT SPECIFIC

# project name - just put a long name.
project(Learning_Open_GL_Linux)

# add an executable "learning_open_gl_linux" with src/main.cpp
add_executable(learning_open_gl_linux src/main.cpp)

# ---------------------------------------------------------------------------------------------
# GLFW3 
# ---------------------------------------------------------------------------------------------

# link the custom built GLFW3 files from https://www.glfw.org/download.html
target_link_libraries(learning_open_gl_linux PRIVATE /home/pum/gl-libs/glfw3/src/libglfw3.a)
target_include_directories(learning_open_gl_linux PRIVATE /home/pum/glfw-3.3.9/include)

# ---------------------------------------------------------------------------------------------
# GLAD
# ---------------------------------------------------------------------------------------------

# include glad header files (downloaded from https://glad.dav1d.de/)
include_directories(/home/pum/glad/include)

# make the glad file a library called 'glad'
add_library(glad /home/pum/glad/src/glad.c)

# link the custom library, 'glad' to the target
target_link_libraries(learning_open_gl_linux PRIVATE glad)

# ---------------------------------------------------------------------------------------------
# WAYLAND
# ---------------------------------------------------------------------------------------------

# IMPORTANT: linking error will occur if the following wayland libraries are not included!
target_link_libraries(learning_open_gl_linux PRIVATE 
    wayland-client
    wayland-egl
    xkbcommon)

# Add the following lines to link against Wayland libraries
# find_package(Wayland REQUIRED) - this doesn't work when uncommented, causes an error.
include_directories(${WAYLAND_CLIENT_INCLUDE_DIR})
include_directories(${WAYLAND_EGL_INCLUDE_DIR})
include_directories(${XKB_COMMON_INCLUDE_DIR})

# ---------------------------------------------------------------------------------------------
# minimum version
cmake_minimum_required(VERSION 3.12)

# ---------------------------------------------------------------------------------------------
# VARIABLES
# ---------------------------------------------------------------------------------------------
set(MY_PROJECT_NAME Learning_Open_GL_Linux)
set(MY_EXE_NAME exe)
set(MY_HOME_DIR /home/pum)
set(MY_LIBS_LOCN_PREFIX ${MY_HOME_DIR}/gl-libs)

# ---------------------------------------------------------------------------------------------
# PROJECT SPECIFIC
# ---------------------------------------------------------------------------------------------

# project name - just put a long name.
project(MY_PROJECT_NAME)

# add an executable "${MY_EXE_NAME}" with src/main.cpp
add_executable(${MY_EXE_NAME} src/main.cpp)

# ---------------------------------------------------------------------------------------------
# GLFW3 
# ---------------------------------------------------------------------------------------------

# link the custom built GLFW3 files from https://www.glfw.org/download.html
target_link_libraries(${MY_EXE_NAME} PRIVATE ${MY_LIBS_LOCN_PREFIX}/glfw3/src/libglfw3.a)
target_include_directories(${MY_EXE_NAME} PRIVATE ${MY_HOME_DIR}/glfw-3.3.9/include)

# ---------------------------------------------------------------------------------------------
# GLAD
# ---------------------------------------------------------------------------------------------

# include glad header files (downloaded from https://glad.dav1d.de/)
include_directories(${MY_LIBS_LOCN_PREFIX}/glad/include)

# make the glad file a library called 'glad'
add_library(glad ${MY_LIBS_LOCN_PREFIX}/glad/src/glad.c)

# link the custom library, 'glad' to the target
target_link_libraries(${MY_EXE_NAME} PRIVATE glad)

# ---------------------------------------------------------------------------------------------
# WAYLAND
# ---------------------------------------------------------------------------------------------

# IMPORTANT: linking error will occur if the following wayland libraries are not included!
target_link_libraries(${MY_EXE_NAME} PRIVATE 
    wayland-client
    wayland-egl
    xkbcommon)

# Add the following lines to link against Wayland libraries
# find_package(Wayland REQUIRED) - this doesn't work when uncommented, causes an error.
include_directories(${WAYLAND_CLIENT_INCLUDE_DIR})
include_directories(${WAYLAND_EGL_INCLUDE_DIR})
include_directories(${XKB_COMMON_INCLUDE_DIR})

# ---------------------------------------------------------------------------------------------
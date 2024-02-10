# Project setup

## Build and run the project
- Clone the repository.
- Go into the root of the repository.
- Build:
    - mkdir build && cd build
    - cmake ..
    - make
    - ./learning_open_gl_linux &

## Current dev machine:
pum@Utopia:~$ neofetch
            .-/+oossssoo+/-.               pum@Utopia 
        `:+ssssssssssssssssss+:`           ---------- 
      -+ssssssssssssssssssyyssss+-         OS: Ubuntu 22.04.3 LTS x86_64 
    .ossssssssssssssssssdMMMNysssso.       Host: ROG Strix G513QE_G513QE 1.0 
   /ssssssssssshdmmNNmmyNMMMMhssssss/      Kernel: 5.15.0-94-generic 
  +ssssssssshmydMMMMMMMNddddyssssssss+     Uptime: 2 hours, 38 mins 
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/    Packages: 1687 (dpkg), 11 (snap) 
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Shell: bash 5.1.16 
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   Resolution: 1920x1080 
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   DE: GNOME 42.9 
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   WM: Mutter 
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   WM Theme: Adwaita 
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Theme: Yaru-dark [GTK2/3] 
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/    Icons: Yaru [GTK2/3] 
  +sssssssssdmydMMMMMMMMddddyssssssss+     Terminal: tmux 
   /ssssssssssshdmNNNNmyNMMMMhssssss/      CPU: AMD Ryzen 5 5600H with Radeon Graphics (12) @ 3.300GHz 
    .ossssssssssssssssssdMMMNysssso.       GPU: AMD ATI 06:00.0 Cezanne 
      -+sssssssssssssssssyyyssss+-         GPU: NVIDIA GeForce RTX 3050 Ti Mobile 
        `:+ssssssssssssssssss+:`           Memory: 6495MiB / 15385MiB 
            .-/+oossssoo+/-.

## Download, compile and build GLFW3

### Download
- Download GLFW3 source - https://www.glfw.org/download.html
- Download CMake - https://cmake.org/download/
    - Shell script will install binaries for Linux
        - Pre-requisites: sudo apt install g++ make
        - Install: sudo sh cmake-3.28.3-linux-x86_64.sh --prefix=/usr/local/ --exclude-subdir
        - Verify: cmake --version

### Build
- Check if you are on wayland / x11
    - echo $XDG_SESSION_TYPE
    - env | grep -E -i 'x11|xorg|wayland'
- Install pre-requisites on Wayland:
    - sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules
- Might need this!
    - sudo apt install pkg-config
- Run CMake
    - cmake -S path/to/glfw -B path/to/build -D GLFW_USE_WAYLAND=1
    - Run Make in path/to/build: make
- A static .a file libglfw3.a should be created in path/to/build/src/
    - Use this in the CMakeLists.txt
    
#### Try this if it doesn't compile maybe?
- Make sure you have OpenGL libraries
    - Install: sudo apt-get install libgl1-mesa-dev

## GLAD (from learnopengl.com)
- Go to https://glad.dav1d.de/ 
- Make sure the language is set to C++, and in the API section select an OpenGL version of at least 3.3 (which is what we'll be using; higher versions are fine as well). Also make sure the profile is set to Core and that the Generate a loader option is ticked. Ignore the extensions (for now) and click Generate to produce the resulting library files. 
- Make sure you use the GLAD1 version from: https://glad.dav1d.de/ as linked above. There's also a GLAD2 version that won't compile here.
- GLAD by now should have provided you a zip file containing two include folders, and a single glad.c file. Copy both include folders (glad and KHR) into your include(s) directory (or add an extra item pointing to these folders), and add the glad.c file to your project.
    - Check CMakeLists.txt for this - we use include_directories(glad_include_dir), add_library(glad_src_c_file), target_link_libraries(link_glad_library_to_the_target_exe_file)

## Wayland
- If a linking error happens, make sure you link with the Wayland libraries: wayland-client, wayland-egl and xkbcommon
    - Check CMakeLists.txt
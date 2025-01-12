cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(2dc2p VERSION 1.0.1 LANGUAGES C CXX)

enable_language(C)
enable_language(CXX)

# Enable C++11 (or later)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define a list of source files
set(SOURCES
    src/ball.cpp
    src/entity.cpp
    src/main.cpp
    src/render_window.cpp
    src/tools.cpp
    src/Vector.cpp
    src/scene.cpp
    # Add other source files here
)

include_directories(include)

# Find SDL2 package (you may need to adjust this based on your setup)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# For SDL2 installation via pkg-config (on Linux/macOS)
if (NOT SDL2_FOUND)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
endif()
    include_directories(${SDL2_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS})

if (NOT SDL2_image_FOUND)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2_image REQUIRED sdl2)
endif()
    include_directories(${SDL2_image_INCLUDE_DIRS})
    link_directories(${SDL2_image_LIBRARY_DIRS})

if (NOT SDL2_ttf_FOUND)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2_ttf REQUIRED sdl2)
endif()
    include_directories(${SDL2_ttf_INCLUDE_DIRS})
    link_directories(${SDL2_ttf_LIBRARY_DIRS})

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the SDL2 libraries
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)

# Additional configuration for platforms
if(WIN32)
    # Windows-specific settings (if needed)
    message(STATUS "Configuring for Windows...")
elseif(APPLE)
    # macOS-specific settings (if needed)
    message(STATUS "Configuring for macOS...")
elseif(UNIX)
    # Linux-specific settings (if needed)
    message(STATUS "Configuring for Linux...")
endif()

# Optionally, enable debugging symbols for better debugging during development
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug build enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

# Install the binary (optional)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Enable testing (optional)
enable_testing()
add_test(NAME app_test COMMAND ${PROJECT_NAME})

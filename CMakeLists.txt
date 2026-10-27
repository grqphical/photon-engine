cmake_minimum_required(VERSION 3.20)

project(PhotonEngine
    VERSION 1.0.0
    DESCRIPTION "A raytracing engine"
    LANGUAGES CXX
)

# C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile_commands.json for tooling (clangd, clang-tidy, etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
        Debug Release RelWithDebInfo MinSizeRel)
endif()

# Shared warnings/debug/sanitizer settings, applied only to our own targets
# (so they don't leak into GoogleTest)
add_library(project_options INTERFACE)

# raytracing library
add_library(libphoton
    src/image.cpp
    src/vector3.cpp
    src/ray.cpp
    src/renderer.cpp
    src/camera.cpp
    src/scene.cpp
    src/image_writer/ppm_writer.cpp
    src/objects/sphere.cpp
)

target_include_directories(libphoton PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(libphoton PUBLIC cxx_std_23)
target_link_libraries(libphoton PRIVATE project_options)

# Executable
add_executable(photon
    src/main.cpp
)

target_include_directories(photon PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(photon PUBLIC libphoton project_options)

# Warnings
if(MSVC)
    target_compile_options(libphoton PRIVATE /W4)
    target_compile_options(photon PRIVATE /W4)
else()
    target_compile_options(libphoton PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(photon PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_compile_definitions(photon PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
)
target_compile_definitions(libphoton PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
)

if(NOT MSVC)
    target_compile_options(photon PRIVATE
        $<$<CONFIG:Debug>:-g3 -O0>
    )
    target_compile_options(libphoton PRIVATE
        $<$<CONFIG:Debug>:-g3 -O0>
    )

    if(ENABLE_SANITIZERS)
        target_compile_options(photon PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined -fno-omit-frame-pointer>
        )
        target_link_options(photon PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
        )
        target_compile_options(libphoton PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined -fno-omit-frame-pointer>
        )
        target_link_options(libphoton PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
        )
    endif()
endif()

include(CTest)  # defines BUILD_TESTING (ON by default) and calls enable_testing()
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

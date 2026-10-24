include(FetchContent)

# Avoid a warning about download timestamps on CMake 3.24+
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.tar.gz
)

# On Windows, use the same runtime library as the rest of the project
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(unit_tests
    test_vector3.cpp
    test_ray.cpp
)

target_link_libraries(unit_tests PRIVATE
    libraytracer
    project_options
    GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

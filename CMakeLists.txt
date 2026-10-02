cmake_minimum_required(VERSION 3.20)

project(factory_sim
	VERSION 0.1.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(factory_sim
    src/Main.cpp
    src/Machine.cpp
    src/Simulation.cpp
    src/MachineManager.cpp
)

target_include_directories(factory_sim
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)


# Tests
enable_testing()

find_package(GTest REQUIRED)

add_executable(factory_tests
    tests/MachineBehavior.cpp
    tests/SimulationEventDriver.cpp
    src/Machine.cpp
    src/Simulation.cpp
    src/MachineManager.cpp
)

target_include_directories(factory_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(factory_tests
    PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(factory_tests)

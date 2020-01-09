cmake_minimum_required(VERSION 3.10)

# set the project name
project(tutorial VERSION 2.1235)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

include_directories( src )

# add the executable
add_executable(cpp-train ./src/main.cxx)

configure_file(./src/mainConfig.h.in mainConfig.h)

target_include_directories(cpp-train PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

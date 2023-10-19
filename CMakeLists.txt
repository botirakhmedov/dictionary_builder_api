cmake_minimum_required(VERSION 3.21)

project(
    "cpptemplate"
    VERSION 1.0.0
    LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(USE_CPM "Whether to use CPM." OFF)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." ON)

option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)

option(ENABLE_SANITIZE_ADDR "Enable address sanitize." ON)
option(ENABLE_SANITIZE_UNDEF "Enable undefined sanitize." ON)
option(ENABLE_SANITIZE_LEAK "Enable leak sanitize (Gcc/Clang only)." ON)
option(ENABLE_SANITIZE_THREAD "Enable thread sanitize (Gcc/Clang only)." OFF)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)

option(ENABLE_LTO "Enable to add Link Time Optimization." ON)

# Set git modules path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(Tools)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizers)
    add_sanitizer_flags()
endif()

if(ENABLE_LTO)
    include(LTO)
endif()

if(USE_CPM)
    message(STATUS "Using CPM")
    include(CPM)
endif()

add_clang_format_target()


# SUB DIRECTORIES

add_subdirectory(configured)
add_subdirectory(app)

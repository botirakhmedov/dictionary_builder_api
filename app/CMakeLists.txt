project(api
    VERSION 1.0.0
    LANGUAGES C CXX)

set(SERVER_EXECUTABLE_NAME "pai")

set(EXE_SOURCES
    "main.cpp")
set(EXE_INCLUDES
    "./")
set(EXE_CONFIG_INCLUDES
    "${CMAKE_BINARY_DIR}/configured_files/include")

# Create the executable
add_executable(${SERVER_EXECUTABLE_NAME} ${EXE_SOURCES})

target_include_directories(${SERVER_EXECUTABLE_NAME} PUBLIC
    ${EXE_INCLUDES}
    ${EXE_CONFIG_INCLUDES}
    )


if (ENABLE_WARNINGS)
    target_set_warnings(
        ${SERVER_EXECUTABLE_NAME}
        ENABLE_WARNINGS
        ENABLE_WARNINGS_AS_ERRORS
    )
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        ${SERVER_EXECUTABLE_NAME}
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${SERVER_EXECUTABLE_NAME})
endif()

# target_link_libraries(${SERVER_EXECUTABLE_NAME} PUBLIC
#     boost_asio
#     fmt::fmt
#     )
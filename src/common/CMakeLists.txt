set(COMMON_LIBRARY_NAME common)

#add_subdirectory(DTO)

set(COMMON_LIB_SOURCES
    "WordDto.cpp"
    )

set(COMMON_LIB_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}")
    #"${CMAKE_CURRENT_SOURCE_DIR}/DTO/")

# Create the library
add_library(${COMMON_LIBRARY_NAME} STATIC ${COMMON_LIB_SOURCES})

target_include_directories(${COMMON_LIBRARY_NAME} PUBLIC
    ${COMMON_LIB_INCLUDES}
    )

## link libs
find_package(oatpp  1.3.0 REQUIRED)

target_link_libraries(${COMMON_LIBRARY_NAME}
        # Oat++
        PUBLIC oatpp::oatpp
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(${COMMON_LIBRARY_NAME} INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()

if (ENABLE_WARNINGS)
    target_set_warnings(
        ${COMMON_LIBRARY_NAME}
        ENABLE_WARNINGS
        ENABLE_WARNINGS_AS_ERRORS
    )
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        ${COMMON_LIBRARY_NAME}
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${COMMON_LIBRARY_NAME})
endif()

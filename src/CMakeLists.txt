set(SOURCES
    polynomial.cpp
    )

if(CMAKE_EXTRA_GENERATOR OR MSVC_IDE)
    message(STATUS "Adding header files to project")
    file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.hpp")
    if(MSVC_IDE)
        source_group("Header Files" FILES ${HEADERS})
    endif()
    list(APPEND SOURCES ${CUKE_HEADERS})
endif()

add_library(polynomial STATIC ${SOURCES})

if(MINGW)
    list(APPEND DEP_LIBRARIES ws2_32)
endif(MINGW)

target_link_libraries(polynomial PRIVATE ${DEP_LIBRARIES})

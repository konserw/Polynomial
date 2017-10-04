cmake_minimum_required(VERSION 3.1)

project(Polynomial)

option(DISABLE_UNIT_TESTS  "Disable unit tests" OFF)
option(VALGRIND_TESTS      "Run tests within Valgrind" OFF)
option(ENABLE_EXAMPLES     "Enable the examples" OFF)

set(GMOCK_VER "1.8.0")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

#
# Generic Compiler Flags
#

#if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} -Wall -Wextra -Werror ${CMAKE_CXX_FLAGS}")
#    # TODO: A better fix should handle ld's --as-needed flag
#    if(UNIX AND NOT APPLE)
#        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Xlinker '--no-as-needed'")
#    endif()
#elseif(MSVC)
#    set(CMAKE_CXX_FLAGS "-DNOMINMAX ${CMAKE_CXX_FLAGS}") # exclude M$ min/max macros
#    set(CMAKE_CXX_FLAGS "/wd4996 ${CMAKE_CXX_FLAGS}") # don't warn about use of plain C functions without (non-portable) "_s" suffix
#    #set(CMAKE_CXX_FLAGS_DEBUG "/analyze ${CMAKE_CXX_FLAGS_DEBUG}")
#endif()

#
# Colored Terminal Output
#

if(UNIX AND (
       (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9))
    AND CMAKE_GENERATOR STREQUAL "Ninja")
  # These compilers generate coloured output, but by default only when their output channel is a
  # terminal (TTY/PTY). Ninja however captures all output in a pipe (per-subprocess), disabling
  # coloured compiler diagnostics. We forcefully enable it because Ninja, since 1.0.0
  # (ninja-build/ninja#198) takes care to strip VT100 CSI control sequences from the output if Ninja
  # itself is writing to a pipe instead of a terminal. As a result this should give us the best of
  # both worlds: coloured output when we're running in a terminal, plain output for editors, IDEs,
  # etc.
  set(CMAKE_CXX_FLAGS "-fdiagnostics-color=always ${CMAKE_CXX_FLAGS}" CACHE STRING "" FORCE)
endif()

#
# Valgrind
#

if(VALGRIND_TESTS)
    find_package(Valgrind REQUIRED)
    set(VALGRIND_ARGS --error-exitcode=2 --leak-check=full --undef-value-errors=no)
    if(NOT VALGRIND_VERSION_STRING VERSION_LESS 3.9)
        # Valgrind 3.9 no longer shows all leaks unless asked to
        list(APPEND VALGRIND_ARGS --show-leak-kinds=all)
    endif()
    function(add_test name)
        if(NOT name STREQUAL "NAME")
            _add_test(${VALGRIND_EXECUTABLE} ${VALGRIND_ARGS} ${ARGV})
            return()
        endif()

        set(TEST_ARGS ${ARGV})
        list(FIND TEST_ARGS COMMAND COMMAND_IDX)
        if(COMMAND_IDX EQUAL -1)
            message(AUTHOR_WARNING "Weird command-line given to add_test(), not injecting valgrind")
            _add_test(${ARGV})
            return()
        endif()

        # We want to operate on the COMMAND, not the 'COMMAND' keyword preceding it
        math(EXPR COMMAND_IDX "${COMMAND_IDX} + 1")

        # Keep add_test() behaviour of replacing COMMANDs, when executable targets, with their output files
        list(GET TEST_ARGS ${COMMAND_IDX} COMMAND)
        if(TARGET ${COMMAND})
            get_target_property(COMMAND_TYPE ${COMMAND} TYPE)
            if(COMMAND_TYPE STREQUAL "EXECUTABLE")
                # Inserting first, removing the original only after that, because inserting to the end of the list doesn't work
                math(EXPR ORIG_COMMAND_IDX "${COMMAND_IDX} + 1")
                list(INSERT TEST_ARGS ${COMMAND_IDX} "$<TARGET_FILE:${COMMAND}>")
                list(REMOVE_AT TEST_ARGS ${ORIG_COMMAND_IDX})
            endif()
        endif()

        # Insert the valgrind command line, before the command to execute
        list(INSERT TEST_ARGS ${COMMAND_IDX} ${VALGRIND_EXECUTABLE} ${VALGRIND_ARGS})

        _add_test(${TEST_ARGS})
    endfunction()
endif()

#
# Polynomial 
#

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})
add_subdirectory(src)

#
# Tests
#

if(DISABLE_UNIT_TESTS)
    message(STATUS "Skipping unit tests")
else()
    if(NOT GMOCK_ROOT)
        set(GMOCK_ROOT "${CMAKE_CURRENT_BINARY_DIR}/gmock")
    endif()
    find_package(GMock REQUIRED)
    if(GMOCK_FOUND)
        set(GMOCK_LIBRARIES
            GTest::GTest
            GMock::GMock
            GMock::Main
            )
    endif()

    enable_testing()
    add_subdirectory(tests)
endif()

#
# Examples
#

if(ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif()

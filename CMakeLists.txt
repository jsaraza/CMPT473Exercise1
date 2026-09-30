cmake_minimum_required(VERSION 4.0...4.2)

project(google-test-exercise
  VERSION 0.2
  DESCRIPTION "unit testing and continuous integration"
  LANGUAGES CXX
)

if(PROJECT_IS_TOP_LEVEL)
  if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not supported by the exercise.")
  endif()

  get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
  if(NOT is_multi_config AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
      STRINGS Debug Release RelWithDebInfo MinSizeRel)
  endif()

  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  set(CMAKE_COLOR_DIAGNOSTICS ON)
endif()


add_library(google_test_exercise_warnings INTERFACE)
add_library(google_test_exercise::warnings ALIAS google_test_exercise_warnings)
target_compile_options(google_test_exercise_warnings INTERFACE
  $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall;-Wextra;-Wconversion>
)


option(GOOGLE_TEST_EXERCISE_ENABLE_SANITIZERS
  "Build Debug configurations with AddressSanitizer and UBSan" ON)
add_library(google_test_exercise_sanitizers INTERFACE)
add_library(google_test_exercise::sanitizers ALIAS google_test_exercise_sanitizers)
if(GOOGLE_TEST_EXERCISE_ENABLE_SANITIZERS)
  set(google_test_exercise_sanitizer_flags
    $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU,Clang,AppleClang>>:-fsanitize=address,undefined;-fno-omit-frame-pointer>
  )
  target_compile_options(google_test_exercise_sanitizers INTERFACE ${google_test_exercise_sanitizer_flags})
  target_link_options(google_test_exercise_sanitizers INTERFACE ${google_test_exercise_sanitizer_flags})
endif()


add_subdirectory(lib)


option(BUILD_TESTING "Build the unit tests" ON)
if(BUILD_TESTING)
  include(CTest)
  add_subdirectory(test)
endif()

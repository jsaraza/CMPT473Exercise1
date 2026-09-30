add_subdirectory(gtest EXCLUDE_FROM_ALL)

add_executable(runAllTests
  Dummy.cpp
  # You can create new source files for your tests and add them here,
  # or you can add your tests to Dummy.cpp. Either way will work.
)

target_link_libraries(runAllTests
  PRIVATE
    GTest::gmock GTest::gtest GTest::gtest_main
    google_test_exercise::simple
    google_test_exercise::warnings
    google_test_exercise::sanitizers
)

add_test(NAME AllTests
  COMMAND runAllTests
)

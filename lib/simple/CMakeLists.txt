# Configure the library to be tested
add_library(google_test_exercise_simple)
add_library(google_test_exercise::simple ALIAS google_test_exercise_simple)

target_sources(google_test_exercise_simple
  PRIVATE
    Parallelogram.cpp
    Matthews.cpp
    Awards.cpp
  PUBLIC
    FILE_SET HEADERS
      BASE_DIRS include
      FILES
        include/Awards.h
        include/Matthews.h
        include/Parallelogram.h
)

target_compile_features(google_test_exercise_simple PUBLIC cxx_std_23)
target_link_libraries(google_test_exercise_simple
  PRIVATE
    google_test_exercise::warnings
    google_test_exercise::sanitizers
)

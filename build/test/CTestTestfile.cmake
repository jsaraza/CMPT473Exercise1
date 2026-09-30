# CMake generated Testfile for 
# Source directory: /home/jms40/Documents/CMPT473/Exercise1/test
# Build directory: /home/jms40/Documents/CMPT473/Exercise1/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[AllTests]=] "/home/jms40/Documents/CMPT473/Exercise1/build/test/runAllTests")
set_tests_properties([=[AllTests]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/jms40/Documents/CMPT473/Exercise1/test/CMakeLists.txt;17;add_test;/home/jms40/Documents/CMPT473/Exercise1/test/CMakeLists.txt;0;")
subdirs("gtest")

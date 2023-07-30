cmake_minimum_required(VERSION 3.17)

add_executable("27_Homework_Task1" main.cpp  functions.cpp )
target_include_directories("27_Homework_Task1" PUBLIC ${MY_INCLUDE_DIR} ${MY_CLASS_DIR})
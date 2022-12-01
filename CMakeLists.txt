cmake_minimum_required(VERSION 3.23)
project(student_info_conduct)

set(CMAKE_CXX_STANDARD 14)

add_executable(student_info_conduct student.h student.cpp students_list.cpp students_list.h main.cpp UI.cpp UI.h)

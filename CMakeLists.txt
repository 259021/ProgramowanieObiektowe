project(OwnExcel)
cmake_minimum_required(VERSION 3.17)

include_directories("Source Files")
include_directories("Header Files")
#add_library(OwnExcelLibs "Source Files/array.cpp" "Source Files/array_display.cpp" "Source Files/menu.cpp")

add_executable(OwnExcel "Source Files/main.cpp" "Source Files/array.cpp" "Source Files/array_display.cpp" "Source Files/menu.cpp")


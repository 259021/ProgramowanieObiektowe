project(OwnExcel)
cmake_minimum_required(VERSION 3.17)

include_directories("Source Files")
include_directories("Header Files")

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

add_executable(OwnExcel "Source Files/main.cpp" "Source Files/array.cpp" "Source Files/array_display.cpp" "Source Files/menu.cpp" Models/Identifier.cpp Models/Identifier.h)

target_link_libraries(OwnExcel ${CURSES_LIBRARIES})

option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)

    set( DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../OwnExcel/docs )

    #Configure pdf export
    set( DOXYGEN_GENERATE_LATEX YES)
    set( DOXYGEN_LATEX_OUTPUT latex)
    set( DOXYGEN_LATEX_SOURCE_CODE YES)
    set( DOXYGEN_USE_PDFLATEX YES)

    doxygen_add_docs( doxygen ${RPP_PROJECT_SOURCE_DIR} )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

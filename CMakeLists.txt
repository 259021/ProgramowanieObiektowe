project(OwnExcel)
cmake_minimum_required(VERSION 3.16)

#macos setup start
include_directories(/usr/local/opt/ncurses/include)

link_directories(/usr/local/opt/ncurses/lib)
#add_executable(OwnExcel main.c)

#macos setup end


include_directories("Source Files")
include_directories("Header Files")

find_package(Curses REQUIRED)
find_library(MENU_LIBRARY menu)

include_directories(${CURSES_INCLUDE_DIR})

add_executable(OwnExcel "Source Files/main.cpp" "Source Files/array.cpp" "Source Files/array_display.cpp" "Source Files/menu.cpp" Models/Identifier.cpp Models/Identifier.h "Source Files/operation_handler.cpp" "Header Files/operation_handler.h")

target_link_libraries(OwnExcel ${MENU_LIBRARY} ${CURSES_LIBRARIES})
#Macos setup changes
target_link_libraries(OwnExcel menu ncurses)
#Macos setup changes
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

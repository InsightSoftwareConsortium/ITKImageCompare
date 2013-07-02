cmake_minimum_required(VERSION 2.8)

find_package( ITK 4 REQUIRED )
include( ${ITK_USE_FILE} )

if( NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY )
  set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )
endif()

add_subdirectory( src )

enable_testing()
if( BUILD_TESTING )
  add_subdirectory( test )
endif()

cmake_minimum_required(VERSION 2.8)

find_package( ITK 4 REQUIRED )
include( ${ITK_USE_FILE} )

add_executable( ImageCompare ImageCompare.cxx )
target_link_libraries( ImageCompare ${ITK_LIBRARIES} )

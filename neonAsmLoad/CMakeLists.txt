cmake_minimum_required(VERSION 2.8)
project( neonAsmLoad )
SET( CMAKE_CXX_FLAGS  "-mfpu=neon -mfloat-abi=hard" )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( neonAsmLoad neonAsmLoad.cpp )
target_link_libraries( neonAsmLoad ${OpenCV_LIBS} )

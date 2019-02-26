
cmake_minimum_required (VERSION 2.6)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project (MagickChess)
include_directories("./include")
add_executable(a.out main.cpp ./src/Board.cpp )
#
#IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
#	  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
#		${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
#		${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
#	)
#ENDIF() 

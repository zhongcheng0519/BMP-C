# src
#  |-CMakeLists.txt

set (the_target "bmpC")

if (UNIX)
	set (CMAKE_C_COMPILER gcc)
endif()

aux_source_directory (. SRC_LIST)
source_group("Src" FILES ${SRC_LIST})

file(GLOB INCLUDE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
source_group("Include" FILES ${INCLUDE_LIST})

add_executable(${the_target} ${SRC_LIST})
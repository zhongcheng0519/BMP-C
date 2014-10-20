# ----------------------------------------------------------------------------
#  Root CMake file for BMP-C
#
#    From the off-tree build directory, invoke:
#      $ cmake <PATH_TO_BMP-C_ROOT>
#
#
#   - Support: Zhong Cheng<zhongcheng0519@163.com>
#
# ----------------------------------------------------------------------------

# make endif() possible
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)

message ("Your directory name should not contain 'space' or Chinese Charactor")

message (STATUS "source directory is:   ${CMAKE_SOURCE_DIR}")
message (STATUS "build directory  is:   ${CMAKE_BINARY_DIR}")
message (STATUS "CMAKE_BUILD_TYPE is:   ${CMAKE_BUILD_TYPE}")

# Add these standard paths to the search paths for FIND_LIBRARY
# to find libraries from these locations first
if(UNIX)
  set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /lib /usr/lib)
endif()

# it _must_ go before PROJECT(gg_image) in order to work
# where to install the restribution file(s)
if (NOT CMAKE_INSTALL_PREFIX)
	if (WIN32)
		set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "" FORCE)
	elseif (UNIX)
		set (CMAKE_INSTALL_PREFIX "/usr/local" CACHE INTERNAL "" FORCE)
	endif (WIN32)
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
set(CMAKE_C_FLAGS_MINSIZEREL "" CACHE INTERNAL "" FORCE)
set(CMAKE_C_FLAGS_RELWITHDEBINFO "" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_FLAGS_MINSIZEREL "" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "" CACHE INTERNAL "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "" CACHE INTERNAL "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "" CACHE INTERNAL "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL "" CACHE INTERNAL "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO "" CACHE INTERNAL "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL "" CACHE INTERNAL "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "" CACHE INTERNAL "" FORCE)

project (BMP_C)

cmake_minimum_required (VERSION 2.4)

if(MSVC)
	set(CMAKE_USE_RELATIVE_PATHS ON CACHE INTERNAL "" FORCE)
endif()

# --------------------------------------------------------------
# Indicate CMake 2.7 and above that we don't want to mix relative
#  and absolute paths in linker lib lists.
# Run "cmake --help-policy CMP0003" for more information.
# --------------------------------------------------------------
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif()



# ----------------------------------------------------------------------------
#  Current version number:
# ----------------------------------------------------------------------------
set (BMP_C_VERSION "0.1.0")

string(REGEX MATCHALL "[0-9]" BMP_C_VERSION_PARTS "${BMP_C_VERSION}")

list(GET BMP_C_VERSION_PARTS 0 BMP_C_VERSION_MAJOR)
list(GET BMP_C_VERSION_PARTS 1 BMP_C_VERSION_MINOR)
list(GET BMP_C_VERSION_PARTS 2 BMP_C_VERSION_PATCH)

set(BMP_C_SOVERSION "${BMP_C_VERSION_MAJOR}.${BMP_C_VERSION_MINOR}")

if(WIN32)
	# Postfix of DLLs:
	set(BMP_C_DLLVERSION "${BMP_C_VERSION_MAJOR}${BMP_C_VERSION_MINOR}${BMP_C_VERSION_PATCH}")
	set(BMP_C_DEBUG_POSTFIX d)
else()
	# Postfix of so's:
	set(BMP_C_DLLVERSION "")
	set(BMP_C_DEBUG_POSTFIX)
endif()

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE PATH "" FORCE)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE PATH "" FORCE)

message (STATUS "library output path is:    ${LIBRARY_OUTPUT_PATH}")

add_subdirectory (src)

if (UNIX)
    set (CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -g")
    set (CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS}")
endif (UNIX)

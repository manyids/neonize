# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/odroid/CV/neonize/neonAsmXEdge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odroid/CV/neonize/neonAsmXEdge/build

# Include any dependencies generated for this target.
include CMakeFiles/neonAsmXEdgeVidStrong.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/neonAsmXEdgeVidStrong.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/neonAsmXEdgeVidStrong.dir/flags.make

CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o: CMakeFiles/neonAsmXEdgeVidStrong.dir/flags.make
CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o: ../neonAsmXEdgeVidStrong.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/CV/neonize/neonAsmXEdge/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o -c /home/odroid/CV/neonize/neonAsmXEdge/neonAsmXEdgeVidStrong.cpp

CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/CV/neonize/neonAsmXEdge/neonAsmXEdgeVidStrong.cpp > CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.i

CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/CV/neonize/neonAsmXEdge/neonAsmXEdgeVidStrong.cpp -o CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.s

CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.requires:
.PHONY : CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.requires

CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.provides: CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.requires
	$(MAKE) -f CMakeFiles/neonAsmXEdgeVidStrong.dir/build.make CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.provides.build
.PHONY : CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.provides

CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.provides.build: CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o

# Object files for target neonAsmXEdgeVidStrong
neonAsmXEdgeVidStrong_OBJECTS = \
"CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o"

# External object files for target neonAsmXEdgeVidStrong
neonAsmXEdgeVidStrong_EXTERNAL_OBJECTS =

neonAsmXEdgeVidStrong: CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o
neonAsmXEdgeVidStrong: CMakeFiles/neonAsmXEdgeVidStrong.dir/build.make
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_videostab.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_videoio.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_video.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_ts.a
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_superres.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_stitching.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_shape.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_photo.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_objdetect.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_ml.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_imgproc.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_highgui.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_flann.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_features2d.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_core.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_calib3d.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_features2d.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_ml.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_highgui.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_videoio.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_flann.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_video.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_imgproc.so.3.0.0
neonAsmXEdgeVidStrong: /usr/local/lib/libopencv_core.so.3.0.0
neonAsmXEdgeVidStrong: CMakeFiles/neonAsmXEdgeVidStrong.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable neonAsmXEdgeVidStrong"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/neonAsmXEdgeVidStrong.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/neonAsmXEdgeVidStrong.dir/build: neonAsmXEdgeVidStrong
.PHONY : CMakeFiles/neonAsmXEdgeVidStrong.dir/build

CMakeFiles/neonAsmXEdgeVidStrong.dir/requires: CMakeFiles/neonAsmXEdgeVidStrong.dir/neonAsmXEdgeVidStrong.cpp.o.requires
.PHONY : CMakeFiles/neonAsmXEdgeVidStrong.dir/requires

CMakeFiles/neonAsmXEdgeVidStrong.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/neonAsmXEdgeVidStrong.dir/cmake_clean.cmake
.PHONY : CMakeFiles/neonAsmXEdgeVidStrong.dir/clean

CMakeFiles/neonAsmXEdgeVidStrong.dir/depend:
	cd /home/odroid/CV/neonize/neonAsmXEdge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/CV/neonize/neonAsmXEdge /home/odroid/CV/neonize/neonAsmXEdge /home/odroid/CV/neonize/neonAsmXEdge/build /home/odroid/CV/neonize/neonAsmXEdge/build /home/odroid/CV/neonize/neonAsmXEdge/build/CMakeFiles/neonAsmXEdgeVidStrong.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/neonAsmXEdgeVidStrong.dir/depend


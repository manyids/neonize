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
CMAKE_SOURCE_DIR = /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/build

# Include any dependencies generated for this target.
include CMakeFiles/neonAsmLoad.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/neonAsmLoad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/neonAsmLoad.dir/flags.make

CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o: CMakeFiles/neonAsmLoad.dir/flags.make
CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o: ../neonAsmLoad.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o -c /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/neonAsmLoad.cpp

CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/neonAsmLoad.cpp > CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.i

CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/neonAsmLoad.cpp -o CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.s

CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.requires:
.PHONY : CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.requires

CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.provides: CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.requires
	$(MAKE) -f CMakeFiles/neonAsmLoad.dir/build.make CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.provides.build
.PHONY : CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.provides

CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.provides.build: CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o

# Object files for target neonAsmLoad
neonAsmLoad_OBJECTS = \
"CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o"

# External object files for target neonAsmLoad
neonAsmLoad_EXTERNAL_OBJECTS =

neonAsmLoad: CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o
neonAsmLoad: CMakeFiles/neonAsmLoad.dir/build.make
neonAsmLoad: /usr/local/lib/libopencv_videostab.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_videoio.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_video.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_ts.a
neonAsmLoad: /usr/local/lib/libopencv_superres.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_stitching.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_shape.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_photo.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_objdetect.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_ml.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_imgproc.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_highgui.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_flann.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_features2d.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_core.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_calib3d.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_features2d.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_ml.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_highgui.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_videoio.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_flann.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_video.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_imgproc.so.3.0.0
neonAsmLoad: /usr/local/lib/libopencv_core.so.3.0.0
neonAsmLoad: CMakeFiles/neonAsmLoad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable neonAsmLoad"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/neonAsmLoad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/neonAsmLoad.dir/build: neonAsmLoad
.PHONY : CMakeFiles/neonAsmLoad.dir/build

CMakeFiles/neonAsmLoad.dir/requires: CMakeFiles/neonAsmLoad.dir/neonAsmLoad.cpp.o.requires
.PHONY : CMakeFiles/neonAsmLoad.dir/requires

CMakeFiles/neonAsmLoad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/neonAsmLoad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/neonAsmLoad.dir/clean

CMakeFiles/neonAsmLoad.dir/depend:
	cd /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/build /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/build /home/odroid/CV/b4Sight/Tools/neon_testbed/neonAsmLoad/build/CMakeFiles/neonAsmLoad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/neonAsmLoad.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/openailab/cases/rs485

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/openailab/cases/rs485/build

# Include any dependencies generated for this target.
include CMakeFiles/rs485.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rs485.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rs485.dir/flags.make

CMakeFiles/rs485.dir/main.cpp.o: CMakeFiles/rs485.dir/flags.make
CMakeFiles/rs485.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/openailab/cases/rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rs485.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rs485.dir/main.cpp.o -c /home/openailab/cases/rs485/main.cpp

CMakeFiles/rs485.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rs485.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/openailab/cases/rs485/main.cpp > CMakeFiles/rs485.dir/main.cpp.i

CMakeFiles/rs485.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rs485.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/openailab/cases/rs485/main.cpp -o CMakeFiles/rs485.dir/main.cpp.s

CMakeFiles/rs485.dir/rs485_common.cpp.o: CMakeFiles/rs485.dir/flags.make
CMakeFiles/rs485.dir/rs485_common.cpp.o: ../rs485_common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/openailab/cases/rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rs485.dir/rs485_common.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rs485.dir/rs485_common.cpp.o -c /home/openailab/cases/rs485/rs485_common.cpp

CMakeFiles/rs485.dir/rs485_common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rs485.dir/rs485_common.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/openailab/cases/rs485/rs485_common.cpp > CMakeFiles/rs485.dir/rs485_common.cpp.i

CMakeFiles/rs485.dir/rs485_common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rs485.dir/rs485_common.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/openailab/cases/rs485/rs485_common.cpp -o CMakeFiles/rs485.dir/rs485_common.cpp.s

# Object files for target rs485
rs485_OBJECTS = \
"CMakeFiles/rs485.dir/main.cpp.o" \
"CMakeFiles/rs485.dir/rs485_common.cpp.o"

# External object files for target rs485
rs485_EXTERNAL_OBJECTS =

rs485: CMakeFiles/rs485.dir/main.cpp.o
rs485: CMakeFiles/rs485.dir/rs485_common.cpp.o
rs485: CMakeFiles/rs485.dir/build.make
rs485: CMakeFiles/rs485.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/openailab/cases/rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable rs485"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rs485.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rs485.dir/build: rs485

.PHONY : CMakeFiles/rs485.dir/build

CMakeFiles/rs485.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rs485.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rs485.dir/clean

CMakeFiles/rs485.dir/depend:
	cd /home/openailab/cases/rs485/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/openailab/cases/rs485 /home/openailab/cases/rs485 /home/openailab/cases/rs485/build /home/openailab/cases/rs485/build /home/openailab/cases/rs485/build/CMakeFiles/rs485.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rs485.dir/depend


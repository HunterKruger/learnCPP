# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/FY/Desktop/CPP/Seance2/e2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/e2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/e2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/e2.dir/flags.make

CMakeFiles/e2.dir/main.cpp.o: CMakeFiles/e2.dir/flags.make
CMakeFiles/e2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/e2.dir/main.cpp.o"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/e2.dir/main.cpp.o -c /Users/FY/Desktop/CPP/Seance2/e2/main.cpp

CMakeFiles/e2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/e2.dir/main.cpp.i"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/FY/Desktop/CPP/Seance2/e2/main.cpp > CMakeFiles/e2.dir/main.cpp.i

CMakeFiles/e2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/e2.dir/main.cpp.s"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/FY/Desktop/CPP/Seance2/e2/main.cpp -o CMakeFiles/e2.dir/main.cpp.s

CMakeFiles/e2.dir/ensemble.cpp.o: CMakeFiles/e2.dir/flags.make
CMakeFiles/e2.dir/ensemble.cpp.o: ../ensemble.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/e2.dir/ensemble.cpp.o"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/e2.dir/ensemble.cpp.o -c /Users/FY/Desktop/CPP/Seance2/e2/ensemble.cpp

CMakeFiles/e2.dir/ensemble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/e2.dir/ensemble.cpp.i"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/FY/Desktop/CPP/Seance2/e2/ensemble.cpp > CMakeFiles/e2.dir/ensemble.cpp.i

CMakeFiles/e2.dir/ensemble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/e2.dir/ensemble.cpp.s"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/FY/Desktop/CPP/Seance2/e2/ensemble.cpp -o CMakeFiles/e2.dir/ensemble.cpp.s

# Object files for target e2
e2_OBJECTS = \
"CMakeFiles/e2.dir/main.cpp.o" \
"CMakeFiles/e2.dir/ensemble.cpp.o"

# External object files for target e2
e2_EXTERNAL_OBJECTS =

e2: CMakeFiles/e2.dir/main.cpp.o
e2: CMakeFiles/e2.dir/ensemble.cpp.o
e2: CMakeFiles/e2.dir/build.make
e2: CMakeFiles/e2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable e2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/e2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/e2.dir/build: e2

.PHONY : CMakeFiles/e2.dir/build

CMakeFiles/e2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/e2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/e2.dir/clean

CMakeFiles/e2.dir/depend:
	cd /Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/FY/Desktop/CPP/Seance2/e2 /Users/FY/Desktop/CPP/Seance2/e2 /Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug /Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug /Users/FY/Desktop/CPP/Seance2/e2/cmake-build-debug/CMakeFiles/e2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/e2.dir/depend


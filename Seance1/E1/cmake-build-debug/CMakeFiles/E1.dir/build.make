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
CMAKE_SOURCE_DIR = /Users/FY/Desktop/CPP/Seance1/E1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/FY/Desktop/CPP/Seance1/E1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/E1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/E1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E1.dir/flags.make

CMakeFiles/E1.dir/main.cpp.o: CMakeFiles/E1.dir/flags.make
CMakeFiles/E1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/FY/Desktop/CPP/Seance1/E1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/E1.dir/main.cpp.o"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/E1.dir/main.cpp.o -c /Users/FY/Desktop/CPP/Seance1/E1/main.cpp

CMakeFiles/E1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/E1.dir/main.cpp.i"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/FY/Desktop/CPP/Seance1/E1/main.cpp > CMakeFiles/E1.dir/main.cpp.i

CMakeFiles/E1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/E1.dir/main.cpp.s"
	/usr/local/Cellar/gcc@4.9/4.9.4_1/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/FY/Desktop/CPP/Seance1/E1/main.cpp -o CMakeFiles/E1.dir/main.cpp.s

# Object files for target E1
E1_OBJECTS = \
"CMakeFiles/E1.dir/main.cpp.o"

# External object files for target E1
E1_EXTERNAL_OBJECTS =

E1: CMakeFiles/E1.dir/main.cpp.o
E1: CMakeFiles/E1.dir/build.make
E1: CMakeFiles/E1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/FY/Desktop/CPP/Seance1/E1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable E1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/E1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E1.dir/build: E1

.PHONY : CMakeFiles/E1.dir/build

CMakeFiles/E1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/E1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/E1.dir/clean

CMakeFiles/E1.dir/depend:
	cd /Users/FY/Desktop/CPP/Seance1/E1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/FY/Desktop/CPP/Seance1/E1 /Users/FY/Desktop/CPP/Seance1/E1 /Users/FY/Desktop/CPP/Seance1/E1/cmake-build-debug /Users/FY/Desktop/CPP/Seance1/E1/cmake-build-debug /Users/FY/Desktop/CPP/Seance1/E1/cmake-build-debug/CMakeFiles/E1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/E1.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/aquir/AppData/Local/JetBrains/CLion2023.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/aquir/AppData/Local/JetBrains/CLion2023.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/uber.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/uber.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/uber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uber.dir/flags.make

CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o: CMakeFiles/uber.dir/flags.make
CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o: /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/practicaUber/GrafoUber.cpp
CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o: CMakeFiles/uber.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o -MF CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o.d -o CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o -c /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/practicaUber/GrafoUber.cpp

CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.i"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/practicaUber/GrafoUber.cpp > CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.i

CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.s"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/practicaUber/GrafoUber.cpp -o CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.s

# Object files for target uber
uber_OBJECTS = \
"CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o"

# External object files for target uber
uber_EXTERNAL_OBJECTS =

uber.exe: CMakeFiles/uber.dir/practicaUber/GrafoUber.cpp.o
uber.exe: CMakeFiles/uber.dir/build.make
uber.exe: CMakeFiles/uber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable uber.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uber.dir/build: uber.exe
.PHONY : CMakeFiles/uber.dir/build

CMakeFiles/uber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uber.dir/clean

CMakeFiles/uber.dir/depend:
	cd /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/cmake-build-debug /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/cmake-build-debug /cygdrive/c/Users/aquir/OneDrive/Desktop/GitHub/uber/cmake-build-debug/CMakeFiles/uber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uber.dir/depend


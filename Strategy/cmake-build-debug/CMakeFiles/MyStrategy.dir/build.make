# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Soft\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Soft\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\Strategy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\Strategy\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyStrategy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyStrategy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyStrategy.dir/flags.make

CMakeFiles/MyStrategy.dir/main.cpp.obj: CMakeFiles/MyStrategy.dir/flags.make
CMakeFiles/MyStrategy.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Strategy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyStrategy.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MyStrategy.dir\main.cpp.obj -c D:\CLionProjects\Strategy\main.cpp

CMakeFiles/MyStrategy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyStrategy.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Strategy\main.cpp > CMakeFiles\MyStrategy.dir\main.cpp.i

CMakeFiles/MyStrategy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyStrategy.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Strategy\main.cpp -o CMakeFiles\MyStrategy.dir\main.cpp.s

# Object files for target MyStrategy
MyStrategy_OBJECTS = \
"CMakeFiles/MyStrategy.dir/main.cpp.obj"

# External object files for target MyStrategy
MyStrategy_EXTERNAL_OBJECTS =

MyStrategy.exe: CMakeFiles/MyStrategy.dir/main.cpp.obj
MyStrategy.exe: CMakeFiles/MyStrategy.dir/build.make
MyStrategy.exe: CMakeFiles/MyStrategy.dir/linklibs.rsp
MyStrategy.exe: CMakeFiles/MyStrategy.dir/objects1.rsp
MyStrategy.exe: CMakeFiles/MyStrategy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\Strategy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyStrategy.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyStrategy.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyStrategy.dir/build: MyStrategy.exe

.PHONY : CMakeFiles/MyStrategy.dir/build

CMakeFiles/MyStrategy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyStrategy.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyStrategy.dir/clean

CMakeFiles/MyStrategy.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\Strategy D:\CLionProjects\Strategy D:\CLionProjects\Strategy\cmake-build-debug D:\CLionProjects\Strategy\cmake-build-debug D:\CLionProjects\Strategy\cmake-build-debug\CMakeFiles\MyStrategy.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyStrategy.dir/depend


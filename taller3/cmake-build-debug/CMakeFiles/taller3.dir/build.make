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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/taller3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/taller3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/taller3.dir/flags.make

CMakeFiles/taller3.dir/main.cpp.obj: CMakeFiles/taller3.dir/flags.make
CMakeFiles/taller3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/taller3.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\taller3.dir\main.cpp.obj -c C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\main.cpp

CMakeFiles/taller3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taller3.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\main.cpp > CMakeFiles\taller3.dir\main.cpp.i

CMakeFiles/taller3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taller3.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\main.cpp -o CMakeFiles\taller3.dir\main.cpp.s

# Object files for target taller3
taller3_OBJECTS = \
"CMakeFiles/taller3.dir/main.cpp.obj"

# External object files for target taller3
taller3_EXTERNAL_OBJECTS =

taller3.exe: CMakeFiles/taller3.dir/main.cpp.obj
taller3.exe: CMakeFiles/taller3.dir/build.make
taller3.exe: C:/MinGW/lib/libfreeglut.a
taller3.exe: CMakeFiles/taller3.dir/linklibs.rsp
taller3.exe: CMakeFiles/taller3.dir/objects1.rsp
taller3.exe: CMakeFiles/taller3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable taller3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\taller3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/taller3.dir/build: taller3.exe

.PHONY : CMakeFiles/taller3.dir/build

CMakeFiles/taller3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\taller3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/taller3.dir/clean

CMakeFiles/taller3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3 C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3 C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\cmake-build-debug C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\cmake-build-debug C:\Users\Alejandro\Documents\Semestre_1_2020\ComputacionGrafica\ComputacionGrafica\taller3\cmake-build-debug\CMakeFiles\taller3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/taller3.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\filip\Documents\GitHub\FEUP-DA-proj1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proj1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proj1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj1.dir/flags.make

CMakeFiles/proj1.dir/src/main.cpp.obj: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/src/main.cpp.obj: C:/Users/filip/Documents/GitHub/FEUP-DA-proj1/src/main.cpp
CMakeFiles/proj1.dir/src/main.cpp.obj: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj1.dir/src/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/src/main.cpp.obj -MF CMakeFiles\proj1.dir\src\main.cpp.obj.d -o CMakeFiles\proj1.dir\src\main.cpp.obj -c C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\main.cpp

CMakeFiles/proj1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/src/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\main.cpp > CMakeFiles\proj1.dir\src\main.cpp.i

CMakeFiles/proj1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/src/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\main.cpp -o CMakeFiles\proj1.dir\src\main.cpp.s

CMakeFiles/proj1.dir/data_structures/Graph.cpp.obj: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/data_structures/Graph.cpp.obj: C:/Users/filip/Documents/GitHub/FEUP-DA-proj1/data_structures/Graph.cpp
CMakeFiles/proj1.dir/data_structures/Graph.cpp.obj: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proj1.dir/data_structures/Graph.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/data_structures/Graph.cpp.obj -MF CMakeFiles\proj1.dir\data_structures\Graph.cpp.obj.d -o CMakeFiles\proj1.dir\data_structures\Graph.cpp.obj -c C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\data_structures\Graph.cpp

CMakeFiles/proj1.dir/data_structures/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/data_structures/Graph.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\data_structures\Graph.cpp > CMakeFiles\proj1.dir\data_structures\Graph.cpp.i

CMakeFiles/proj1.dir/data_structures/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/data_structures/Graph.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\data_structures\Graph.cpp -o CMakeFiles\proj1.dir\data_structures\Graph.cpp.s

CMakeFiles/proj1.dir/data_structures/read.cpp.obj: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/data_structures/read.cpp.obj: C:/Users/filip/Documents/GitHub/FEUP-DA-proj1/data_structures/read.cpp
CMakeFiles/proj1.dir/data_structures/read.cpp.obj: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/proj1.dir/data_structures/read.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/data_structures/read.cpp.obj -MF CMakeFiles\proj1.dir\data_structures\read.cpp.obj.d -o CMakeFiles\proj1.dir\data_structures\read.cpp.obj -c C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\data_structures\read.cpp

CMakeFiles/proj1.dir/data_structures/read.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/data_structures/read.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\data_structures\read.cpp > CMakeFiles\proj1.dir\data_structures\read.cpp.i

CMakeFiles/proj1.dir/data_structures/read.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/data_structures/read.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\data_structures\read.cpp -o CMakeFiles\proj1.dir\data_structures\read.cpp.s

CMakeFiles/proj1.dir/src/ex1.cpp.obj: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/src/ex1.cpp.obj: C:/Users/filip/Documents/GitHub/FEUP-DA-proj1/src/ex1.cpp
CMakeFiles/proj1.dir/src/ex1.cpp.obj: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/proj1.dir/src/ex1.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/src/ex1.cpp.obj -MF CMakeFiles\proj1.dir\src\ex1.cpp.obj.d -o CMakeFiles\proj1.dir\src\ex1.cpp.obj -c C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\ex1.cpp

CMakeFiles/proj1.dir/src/ex1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/src/ex1.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\ex1.cpp > CMakeFiles\proj1.dir\src\ex1.cpp.i

CMakeFiles/proj1.dir/src/ex1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/src/ex1.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\ex1.cpp -o CMakeFiles\proj1.dir\src\ex1.cpp.s

CMakeFiles/proj1.dir/src/ex3.cpp.obj: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/src/ex3.cpp.obj: C:/Users/filip/Documents/GitHub/FEUP-DA-proj1/src/ex3.cpp
CMakeFiles/proj1.dir/src/ex3.cpp.obj: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/proj1.dir/src/ex3.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/src/ex3.cpp.obj -MF CMakeFiles\proj1.dir\src\ex3.cpp.obj.d -o CMakeFiles\proj1.dir\src\ex3.cpp.obj -c C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\ex3.cpp

CMakeFiles/proj1.dir/src/ex3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/src/ex3.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\ex3.cpp > CMakeFiles\proj1.dir\src\ex3.cpp.i

CMakeFiles/proj1.dir/src/ex3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/src/ex3.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\src\ex3.cpp -o CMakeFiles\proj1.dir\src\ex3.cpp.s

# Object files for target proj1
proj1_OBJECTS = \
"CMakeFiles/proj1.dir/src/main.cpp.obj" \
"CMakeFiles/proj1.dir/data_structures/Graph.cpp.obj" \
"CMakeFiles/proj1.dir/data_structures/read.cpp.obj" \
"CMakeFiles/proj1.dir/src/ex1.cpp.obj" \
"CMakeFiles/proj1.dir/src/ex3.cpp.obj"

# External object files for target proj1
proj1_EXTERNAL_OBJECTS =

proj1.exe: CMakeFiles/proj1.dir/src/main.cpp.obj
proj1.exe: CMakeFiles/proj1.dir/data_structures/Graph.cpp.obj
proj1.exe: CMakeFiles/proj1.dir/data_structures/read.cpp.obj
proj1.exe: CMakeFiles/proj1.dir/src/ex1.cpp.obj
proj1.exe: CMakeFiles/proj1.dir/src/ex3.cpp.obj
proj1.exe: CMakeFiles/proj1.dir/build.make
proj1.exe: CMakeFiles/proj1.dir/linkLibs.rsp
proj1.exe: CMakeFiles/proj1.dir/objects1.rsp
proj1.exe: CMakeFiles/proj1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable proj1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proj1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj1.dir/build: proj1.exe
.PHONY : CMakeFiles/proj1.dir/build

CMakeFiles/proj1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proj1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proj1.dir/clean

CMakeFiles/proj1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\filip\Documents\GitHub\FEUP-DA-proj1 C:\Users\filip\Documents\GitHub\FEUP-DA-proj1 C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug C:\Users\filip\Documents\GitHub\FEUP-DA-proj1\cmake-build-debug\CMakeFiles\proj1.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/proj1.dir/depend


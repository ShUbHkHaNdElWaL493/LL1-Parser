# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /home/shubh_khandelwal/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/shubh_khandelwal/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/shubh_khandelwal/Documents/C/LL1 Parser/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/shubh_khandelwal/Documents/C/LL1 Parser/build"

# Include any dependencies generated for this target.
include CMakeFiles/LL1_parser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LL1_parser.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LL1_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LL1_parser.dir/flags.make

CMakeFiles/LL1_parser.dir/LL1_parser.c.o: CMakeFiles/LL1_parser.dir/flags.make
CMakeFiles/LL1_parser.dir/LL1_parser.c.o: /home/shubh_khandelwal/Documents/C/LL1\ Parser/src/LL1_parser.c
CMakeFiles/LL1_parser.dir/LL1_parser.c.o: CMakeFiles/LL1_parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/shubh_khandelwal/Documents/C/LL1 Parser/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LL1_parser.dir/LL1_parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LL1_parser.dir/LL1_parser.c.o -MF CMakeFiles/LL1_parser.dir/LL1_parser.c.o.d -o CMakeFiles/LL1_parser.dir/LL1_parser.c.o -c "/home/shubh_khandelwal/Documents/C/LL1 Parser/src/LL1_parser.c"

CMakeFiles/LL1_parser.dir/LL1_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LL1_parser.dir/LL1_parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/shubh_khandelwal/Documents/C/LL1 Parser/src/LL1_parser.c" > CMakeFiles/LL1_parser.dir/LL1_parser.c.i

CMakeFiles/LL1_parser.dir/LL1_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LL1_parser.dir/LL1_parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/shubh_khandelwal/Documents/C/LL1 Parser/src/LL1_parser.c" -o CMakeFiles/LL1_parser.dir/LL1_parser.c.s

# Object files for target LL1_parser
LL1_parser_OBJECTS = \
"CMakeFiles/LL1_parser.dir/LL1_parser.c.o"

# External object files for target LL1_parser
LL1_parser_EXTERNAL_OBJECTS =

LL1_parser: CMakeFiles/LL1_parser.dir/LL1_parser.c.o
LL1_parser: CMakeFiles/LL1_parser.dir/build.make
LL1_parser: include/libparse_LL1.a
LL1_parser: include/libfirst_follow.a
LL1_parser: include/libdatatypes.a
LL1_parser: CMakeFiles/LL1_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/shubh_khandelwal/Documents/C/LL1 Parser/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LL1_parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LL1_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LL1_parser.dir/build: LL1_parser
.PHONY : CMakeFiles/LL1_parser.dir/build

CMakeFiles/LL1_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LL1_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LL1_parser.dir/clean

CMakeFiles/LL1_parser.dir/depend:
	cd "/home/shubh_khandelwal/Documents/C/LL1 Parser/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shubh_khandelwal/Documents/C/LL1 Parser/src" "/home/shubh_khandelwal/Documents/C/LL1 Parser/src" "/home/shubh_khandelwal/Documents/C/LL1 Parser/build" "/home/shubh_khandelwal/Documents/C/LL1 Parser/build" "/home/shubh_khandelwal/Documents/C/LL1 Parser/build/CMakeFiles/LL1_parser.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/LL1_parser.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maria/Downloads/text-adventure-starting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maria/Downloads/text-adventure-starting/build

# Include any dependencies generated for this target.
include CMakeFiles/text_adventure.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/text_adventure.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/text_adventure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/text_adventure.dir/flags.make

CMakeFiles/text_adventure.dir/codegen:
.PHONY : CMakeFiles/text_adventure.dir/codegen

CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o: CMakeFiles/text_adventure.dir/flags.make
CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o: /Users/maria/Downloads/text-adventure-starting/src/text-adventure.cpp
CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o: CMakeFiles/text_adventure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maria/Downloads/text-adventure-starting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o -MF CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o.d -o CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o -c /Users/maria/Downloads/text-adventure-starting/src/text-adventure.cpp

CMakeFiles/text_adventure.dir/src/text-adventure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/text_adventure.dir/src/text-adventure.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maria/Downloads/text-adventure-starting/src/text-adventure.cpp > CMakeFiles/text_adventure.dir/src/text-adventure.cpp.i

CMakeFiles/text_adventure.dir/src/text-adventure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/text_adventure.dir/src/text-adventure.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maria/Downloads/text-adventure-starting/src/text-adventure.cpp -o CMakeFiles/text_adventure.dir/src/text-adventure.cpp.s

# Object files for target text_adventure
text_adventure_OBJECTS = \
"CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o"

# External object files for target text_adventure
text_adventure_EXTERNAL_OBJECTS =

text_adventure: CMakeFiles/text_adventure.dir/src/text-adventure.cpp.o
text_adventure: CMakeFiles/text_adventure.dir/build.make
text_adventure: CMakeFiles/text_adventure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maria/Downloads/text-adventure-starting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable text_adventure"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/text_adventure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/text_adventure.dir/build: text_adventure
.PHONY : CMakeFiles/text_adventure.dir/build

CMakeFiles/text_adventure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/text_adventure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/text_adventure.dir/clean

CMakeFiles/text_adventure.dir/depend:
	cd /Users/maria/Downloads/text-adventure-starting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maria/Downloads/text-adventure-starting /Users/maria/Downloads/text-adventure-starting /Users/maria/Downloads/text-adventure-starting/build /Users/maria/Downloads/text-adventure-starting/build /Users/maria/Downloads/text-adventure-starting/build/CMakeFiles/text_adventure.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/text_adventure.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_SOURCE_DIR = /home/mfracker/csce/personal/FrackDB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mfracker/csce/personal/FrackDB/build

# Include any dependencies generated for this target.
include frackdb/evaluation/CMakeFiles/evaluation.dir/depend.make

# Include the progress variables for this target.
include frackdb/evaluation/CMakeFiles/evaluation.dir/progress.make

# Include the compile flags for this target's objects.
include frackdb/evaluation/CMakeFiles/evaluation.dir/flags.make

frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o: frackdb/evaluation/CMakeFiles/evaluation.dir/flags.make
frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o: ../frackdb/evaluation/comparison.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mfracker/csce/personal/FrackDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evaluation.dir/comparison.cc.o -c /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/comparison.cc

frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evaluation.dir/comparison.cc.i"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/comparison.cc > CMakeFiles/evaluation.dir/comparison.cc.i

frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evaluation.dir/comparison.cc.s"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/comparison.cc -o CMakeFiles/evaluation.dir/comparison.cc.s

frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.requires:

.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.requires

frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.provides: frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.requires
	$(MAKE) -f frackdb/evaluation/CMakeFiles/evaluation.dir/build.make frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.provides.build
.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.provides

frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.provides.build: frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o


frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o: frackdb/evaluation/CMakeFiles/evaluation.dir/flags.make
frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o: ../frackdb/evaluation/condition.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mfracker/csce/personal/FrackDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evaluation.dir/condition.cc.o -c /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/condition.cc

frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evaluation.dir/condition.cc.i"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/condition.cc > CMakeFiles/evaluation.dir/condition.cc.i

frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evaluation.dir/condition.cc.s"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/condition.cc -o CMakeFiles/evaluation.dir/condition.cc.s

frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.requires:

.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.requires

frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.provides: frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.requires
	$(MAKE) -f frackdb/evaluation/CMakeFiles/evaluation.dir/build.make frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.provides.build
.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.provides

frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.provides.build: frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o


frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o: frackdb/evaluation/CMakeFiles/evaluation.dir/flags.make
frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o: ../frackdb/evaluation/identifier.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mfracker/csce/personal/FrackDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evaluation.dir/identifier.cc.o -c /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/identifier.cc

frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evaluation.dir/identifier.cc.i"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/identifier.cc > CMakeFiles/evaluation.dir/identifier.cc.i

frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evaluation.dir/identifier.cc.s"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mfracker/csce/personal/FrackDB/frackdb/evaluation/identifier.cc -o CMakeFiles/evaluation.dir/identifier.cc.s

frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.requires:

.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.requires

frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.provides: frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.requires
	$(MAKE) -f frackdb/evaluation/CMakeFiles/evaluation.dir/build.make frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.provides.build
.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.provides

frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.provides.build: frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o


# Object files for target evaluation
evaluation_OBJECTS = \
"CMakeFiles/evaluation.dir/comparison.cc.o" \
"CMakeFiles/evaluation.dir/condition.cc.o" \
"CMakeFiles/evaluation.dir/identifier.cc.o"

# External object files for target evaluation
evaluation_EXTERNAL_OBJECTS =

frackdb/evaluation/libevaluation.a: frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o
frackdb/evaluation/libevaluation.a: frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o
frackdb/evaluation/libevaluation.a: frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o
frackdb/evaluation/libevaluation.a: frackdb/evaluation/CMakeFiles/evaluation.dir/build.make
frackdb/evaluation/libevaluation.a: frackdb/evaluation/CMakeFiles/evaluation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mfracker/csce/personal/FrackDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libevaluation.a"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && $(CMAKE_COMMAND) -P CMakeFiles/evaluation.dir/cmake_clean_target.cmake
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/evaluation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
frackdb/evaluation/CMakeFiles/evaluation.dir/build: frackdb/evaluation/libevaluation.a

.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/build

frackdb/evaluation/CMakeFiles/evaluation.dir/requires: frackdb/evaluation/CMakeFiles/evaluation.dir/comparison.cc.o.requires
frackdb/evaluation/CMakeFiles/evaluation.dir/requires: frackdb/evaluation/CMakeFiles/evaluation.dir/condition.cc.o.requires
frackdb/evaluation/CMakeFiles/evaluation.dir/requires: frackdb/evaluation/CMakeFiles/evaluation.dir/identifier.cc.o.requires

.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/requires

frackdb/evaluation/CMakeFiles/evaluation.dir/clean:
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation && $(CMAKE_COMMAND) -P CMakeFiles/evaluation.dir/cmake_clean.cmake
.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/clean

frackdb/evaluation/CMakeFiles/evaluation.dir/depend:
	cd /home/mfracker/csce/personal/FrackDB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mfracker/csce/personal/FrackDB /home/mfracker/csce/personal/FrackDB/frackdb/evaluation /home/mfracker/csce/personal/FrackDB/build /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation /home/mfracker/csce/personal/FrackDB/build/frackdb/evaluation/CMakeFiles/evaluation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : frackdb/evaluation/CMakeFiles/evaluation.dir/depend


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
include frackdb/querying/CMakeFiles/querying.dir/depend.make

# Include the progress variables for this target.
include frackdb/querying/CMakeFiles/querying.dir/progress.make

# Include the compile flags for this target's objects.
include frackdb/querying/CMakeFiles/querying.dir/flags.make

frackdb/querying/CMakeFiles/querying.dir/select.cc.o: frackdb/querying/CMakeFiles/querying.dir/flags.make
frackdb/querying/CMakeFiles/querying.dir/select.cc.o: ../frackdb/querying/select.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mfracker/csce/personal/FrackDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object frackdb/querying/CMakeFiles/querying.dir/select.cc.o"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/querying && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/querying.dir/select.cc.o -c /home/mfracker/csce/personal/FrackDB/frackdb/querying/select.cc

frackdb/querying/CMakeFiles/querying.dir/select.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/querying.dir/select.cc.i"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/querying && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mfracker/csce/personal/FrackDB/frackdb/querying/select.cc > CMakeFiles/querying.dir/select.cc.i

frackdb/querying/CMakeFiles/querying.dir/select.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/querying.dir/select.cc.s"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/querying && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mfracker/csce/personal/FrackDB/frackdb/querying/select.cc -o CMakeFiles/querying.dir/select.cc.s

frackdb/querying/CMakeFiles/querying.dir/select.cc.o.requires:

.PHONY : frackdb/querying/CMakeFiles/querying.dir/select.cc.o.requires

frackdb/querying/CMakeFiles/querying.dir/select.cc.o.provides: frackdb/querying/CMakeFiles/querying.dir/select.cc.o.requires
	$(MAKE) -f frackdb/querying/CMakeFiles/querying.dir/build.make frackdb/querying/CMakeFiles/querying.dir/select.cc.o.provides.build
.PHONY : frackdb/querying/CMakeFiles/querying.dir/select.cc.o.provides

frackdb/querying/CMakeFiles/querying.dir/select.cc.o.provides.build: frackdb/querying/CMakeFiles/querying.dir/select.cc.o


# Object files for target querying
querying_OBJECTS = \
"CMakeFiles/querying.dir/select.cc.o"

# External object files for target querying
querying_EXTERNAL_OBJECTS =

frackdb/querying/libquerying.a: frackdb/querying/CMakeFiles/querying.dir/select.cc.o
frackdb/querying/libquerying.a: frackdb/querying/CMakeFiles/querying.dir/build.make
frackdb/querying/libquerying.a: frackdb/querying/CMakeFiles/querying.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mfracker/csce/personal/FrackDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libquerying.a"
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/querying && $(CMAKE_COMMAND) -P CMakeFiles/querying.dir/cmake_clean_target.cmake
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/querying && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/querying.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
frackdb/querying/CMakeFiles/querying.dir/build: frackdb/querying/libquerying.a

.PHONY : frackdb/querying/CMakeFiles/querying.dir/build

frackdb/querying/CMakeFiles/querying.dir/requires: frackdb/querying/CMakeFiles/querying.dir/select.cc.o.requires

.PHONY : frackdb/querying/CMakeFiles/querying.dir/requires

frackdb/querying/CMakeFiles/querying.dir/clean:
	cd /home/mfracker/csce/personal/FrackDB/build/frackdb/querying && $(CMAKE_COMMAND) -P CMakeFiles/querying.dir/cmake_clean.cmake
.PHONY : frackdb/querying/CMakeFiles/querying.dir/clean

frackdb/querying/CMakeFiles/querying.dir/depend:
	cd /home/mfracker/csce/personal/FrackDB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mfracker/csce/personal/FrackDB /home/mfracker/csce/personal/FrackDB/frackdb/querying /home/mfracker/csce/personal/FrackDB/build /home/mfracker/csce/personal/FrackDB/build/frackdb/querying /home/mfracker/csce/personal/FrackDB/build/frackdb/querying/CMakeFiles/querying.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : frackdb/querying/CMakeFiles/querying.dir/depend


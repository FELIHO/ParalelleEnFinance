# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /user/8/felihol/ParalleleFinance/ParalelleProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /user/8/felihol/ParalleleFinance/ParalelleProject/build

# Include any dependencies generated for this target.
include CMakeFiles/mc-example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mc-example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mc-example.dir/flags.make

CMakeFiles/mc-example.dir/src/mc_example.cpp.o: CMakeFiles/mc-example.dir/flags.make
CMakeFiles/mc-example.dir/src/mc_example.cpp.o: ../src/mc_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mc-example.dir/src/mc_example.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mc-example.dir/src/mc_example.cpp.o -c /user/8/felihol/ParalleleFinance/ParalelleProject/src/mc_example.cpp

CMakeFiles/mc-example.dir/src/mc_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mc-example.dir/src/mc_example.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /user/8/felihol/ParalleleFinance/ParalelleProject/src/mc_example.cpp > CMakeFiles/mc-example.dir/src/mc_example.cpp.i

CMakeFiles/mc-example.dir/src/mc_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mc-example.dir/src/mc_example.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /user/8/felihol/ParalleleFinance/ParalelleProject/src/mc_example.cpp -o CMakeFiles/mc-example.dir/src/mc_example.cpp.s

CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.o: CMakeFiles/mc-example.dir/flags.make
CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.o: ../src/3rdparty/jlparser/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.o -c /user/8/felihol/ParalleleFinance/ParalelleProject/src/3rdparty/jlparser/parser.cpp

CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /user/8/felihol/ParalleleFinance/ParalelleProject/src/3rdparty/jlparser/parser.cpp > CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.i

CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /user/8/felihol/ParalleleFinance/ParalelleProject/src/3rdparty/jlparser/parser.cpp -o CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.s

# Object files for target mc-example
mc__example_OBJECTS = \
"CMakeFiles/mc-example.dir/src/mc_example.cpp.o" \
"CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.o"

# External object files for target mc-example
mc__example_EXTERNAL_OBJECTS =

mc-example: CMakeFiles/mc-example.dir/src/mc_example.cpp.o
mc-example: CMakeFiles/mc-example.dir/src/3rdparty/jlparser/parser.cpp.o
mc-example: CMakeFiles/mc-example.dir/build.make
mc-example: /matieres/WMMF9M11/pnl/lib/libpnl.so
mc-example: /usr/lib64/libblas.so
mc-example: /usr/lib64/liblapack.so
mc-example: /usr/lib64/libblas.so
mc-example: /usr/lib64/openmpi/lib/libmpi.so
mc-example: src/libPricer.a
mc-example: src/libOptions.a
mc-example: /usr/lib64/liblapack.so
mc-example: /usr/lib64/openmpi/lib/libmpi.so
mc-example: CMakeFiles/mc-example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable mc-example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mc-example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mc-example.dir/build: mc-example

.PHONY : CMakeFiles/mc-example.dir/build

CMakeFiles/mc-example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mc-example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mc-example.dir/clean

CMakeFiles/mc-example.dir/depend:
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /user/8/felihol/ParalleleFinance/ParalelleProject /user/8/felihol/ParalleleFinance/ParalelleProject /user/8/felihol/ParalleleFinance/ParalelleProject/build /user/8/felihol/ParalleleFinance/ParalelleProject/build /user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles/mc-example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mc-example.dir/depend

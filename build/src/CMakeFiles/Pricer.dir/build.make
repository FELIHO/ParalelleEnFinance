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
include src/CMakeFiles/Pricer.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Pricer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Pricer.dir/flags.make

src/CMakeFiles/Pricer.dir/BlackScholesModel.cpp.o: src/CMakeFiles/Pricer.dir/flags.make
src/CMakeFiles/Pricer.dir/BlackScholesModel.cpp.o: ../src/BlackScholesModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Pricer.dir/BlackScholesModel.cpp.o"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pricer.dir/BlackScholesModel.cpp.o -c /user/8/felihol/ParalleleFinance/ParalelleProject/src/BlackScholesModel.cpp

src/CMakeFiles/Pricer.dir/BlackScholesModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pricer.dir/BlackScholesModel.cpp.i"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /user/8/felihol/ParalleleFinance/ParalelleProject/src/BlackScholesModel.cpp > CMakeFiles/Pricer.dir/BlackScholesModel.cpp.i

src/CMakeFiles/Pricer.dir/BlackScholesModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pricer.dir/BlackScholesModel.cpp.s"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /user/8/felihol/ParalleleFinance/ParalelleProject/src/BlackScholesModel.cpp -o CMakeFiles/Pricer.dir/BlackScholesModel.cpp.s

src/CMakeFiles/Pricer.dir/MonteCarlo.cpp.o: src/CMakeFiles/Pricer.dir/flags.make
src/CMakeFiles/Pricer.dir/MonteCarlo.cpp.o: ../src/MonteCarlo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/Pricer.dir/MonteCarlo.cpp.o"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pricer.dir/MonteCarlo.cpp.o -c /user/8/felihol/ParalleleFinance/ParalelleProject/src/MonteCarlo.cpp

src/CMakeFiles/Pricer.dir/MonteCarlo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pricer.dir/MonteCarlo.cpp.i"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /user/8/felihol/ParalleleFinance/ParalelleProject/src/MonteCarlo.cpp > CMakeFiles/Pricer.dir/MonteCarlo.cpp.i

src/CMakeFiles/Pricer.dir/MonteCarlo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pricer.dir/MonteCarlo.cpp.s"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /user/8/felihol/ParalleleFinance/ParalelleProject/src/MonteCarlo.cpp -o CMakeFiles/Pricer.dir/MonteCarlo.cpp.s

src/CMakeFiles/Pricer.dir/HedgePortfolio.cpp.o: src/CMakeFiles/Pricer.dir/flags.make
src/CMakeFiles/Pricer.dir/HedgePortfolio.cpp.o: ../src/HedgePortfolio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/Pricer.dir/HedgePortfolio.cpp.o"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pricer.dir/HedgePortfolio.cpp.o -c /user/8/felihol/ParalleleFinance/ParalelleProject/src/HedgePortfolio.cpp

src/CMakeFiles/Pricer.dir/HedgePortfolio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pricer.dir/HedgePortfolio.cpp.i"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /user/8/felihol/ParalleleFinance/ParalelleProject/src/HedgePortfolio.cpp > CMakeFiles/Pricer.dir/HedgePortfolio.cpp.i

src/CMakeFiles/Pricer.dir/HedgePortfolio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pricer.dir/HedgePortfolio.cpp.s"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /user/8/felihol/ParalleleFinance/ParalelleProject/src/HedgePortfolio.cpp -o CMakeFiles/Pricer.dir/HedgePortfolio.cpp.s

src/CMakeFiles/Pricer.dir/FakeRnd.cpp.o: src/CMakeFiles/Pricer.dir/flags.make
src/CMakeFiles/Pricer.dir/FakeRnd.cpp.o: ../src/FakeRnd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/Pricer.dir/FakeRnd.cpp.o"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pricer.dir/FakeRnd.cpp.o -c /user/8/felihol/ParalleleFinance/ParalelleProject/src/FakeRnd.cpp

src/CMakeFiles/Pricer.dir/FakeRnd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pricer.dir/FakeRnd.cpp.i"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /user/8/felihol/ParalleleFinance/ParalelleProject/src/FakeRnd.cpp > CMakeFiles/Pricer.dir/FakeRnd.cpp.i

src/CMakeFiles/Pricer.dir/FakeRnd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pricer.dir/FakeRnd.cpp.s"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /user/8/felihol/ParalleleFinance/ParalelleProject/src/FakeRnd.cpp -o CMakeFiles/Pricer.dir/FakeRnd.cpp.s

src/CMakeFiles/Pricer.dir/PnlRand.cpp.o: src/CMakeFiles/Pricer.dir/flags.make
src/CMakeFiles/Pricer.dir/PnlRand.cpp.o: ../src/PnlRand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/Pricer.dir/PnlRand.cpp.o"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pricer.dir/PnlRand.cpp.o -c /user/8/felihol/ParalleleFinance/ParalelleProject/src/PnlRand.cpp

src/CMakeFiles/Pricer.dir/PnlRand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pricer.dir/PnlRand.cpp.i"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /user/8/felihol/ParalleleFinance/ParalelleProject/src/PnlRand.cpp > CMakeFiles/Pricer.dir/PnlRand.cpp.i

src/CMakeFiles/Pricer.dir/PnlRand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pricer.dir/PnlRand.cpp.s"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /user/8/felihol/ParalleleFinance/ParalelleProject/src/PnlRand.cpp -o CMakeFiles/Pricer.dir/PnlRand.cpp.s

# Object files for target Pricer
Pricer_OBJECTS = \
"CMakeFiles/Pricer.dir/BlackScholesModel.cpp.o" \
"CMakeFiles/Pricer.dir/MonteCarlo.cpp.o" \
"CMakeFiles/Pricer.dir/HedgePortfolio.cpp.o" \
"CMakeFiles/Pricer.dir/FakeRnd.cpp.o" \
"CMakeFiles/Pricer.dir/PnlRand.cpp.o"

# External object files for target Pricer
Pricer_EXTERNAL_OBJECTS =

src/libPricer.a: src/CMakeFiles/Pricer.dir/BlackScholesModel.cpp.o
src/libPricer.a: src/CMakeFiles/Pricer.dir/MonteCarlo.cpp.o
src/libPricer.a: src/CMakeFiles/Pricer.dir/HedgePortfolio.cpp.o
src/libPricer.a: src/CMakeFiles/Pricer.dir/FakeRnd.cpp.o
src/libPricer.a: src/CMakeFiles/Pricer.dir/PnlRand.cpp.o
src/libPricer.a: src/CMakeFiles/Pricer.dir/build.make
src/libPricer.a: src/CMakeFiles/Pricer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/user/8/felihol/ParalleleFinance/ParalelleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libPricer.a"
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Pricer.dir/cmake_clean_target.cmake
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pricer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Pricer.dir/build: src/libPricer.a

.PHONY : src/CMakeFiles/Pricer.dir/build

src/CMakeFiles/Pricer.dir/clean:
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Pricer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Pricer.dir/clean

src/CMakeFiles/Pricer.dir/depend:
	cd /user/8/felihol/ParalleleFinance/ParalelleProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /user/8/felihol/ParalleleFinance/ParalelleProject /user/8/felihol/ParalleleFinance/ParalelleProject/src /user/8/felihol/ParalleleFinance/ParalelleProject/build /user/8/felihol/ParalleleFinance/ParalelleProject/build/src /user/8/felihol/ParalleleFinance/ParalelleProject/build/src/CMakeFiles/Pricer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Pricer.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aelysium/CLionProjects/suggest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aelysium/CLionProjects/suggest/cmake-build-debug

# Include any dependencies generated for this target.
include google_tests/CMakeFiles/google_tests_run.dir/depend.make

# Include the progress variables for this target.
include google_tests/CMakeFiles/google_tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include google_tests/CMakeFiles/google_tests_run.dir/flags.make

google_tests/CMakeFiles/google_tests_run.dir/TrieTest.cpp.o: google_tests/CMakeFiles/google_tests_run.dir/flags.make
google_tests/CMakeFiles/google_tests_run.dir/TrieTest.cpp.o: ../google_tests/TrieTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aelysium/CLionProjects/suggest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object google_tests/CMakeFiles/google_tests_run.dir/TrieTest.cpp.o"
	cd /home/aelysium/CLionProjects/suggest/cmake-build-debug/google_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/google_tests_run.dir/TrieTest.cpp.o -c /home/aelysium/CLionProjects/suggest/google_tests/TrieTest.cpp

google_tests/CMakeFiles/google_tests_run.dir/TrieTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_tests_run.dir/TrieTest.cpp.i"
	cd /home/aelysium/CLionProjects/suggest/cmake-build-debug/google_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aelysium/CLionProjects/suggest/google_tests/TrieTest.cpp > CMakeFiles/google_tests_run.dir/TrieTest.cpp.i

google_tests/CMakeFiles/google_tests_run.dir/TrieTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_tests_run.dir/TrieTest.cpp.s"
	cd /home/aelysium/CLionProjects/suggest/cmake-build-debug/google_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aelysium/CLionProjects/suggest/google_tests/TrieTest.cpp -o CMakeFiles/google_tests_run.dir/TrieTest.cpp.s

# Object files for target google_tests_run
google_tests_run_OBJECTS = \
"CMakeFiles/google_tests_run.dir/TrieTest.cpp.o"

# External object files for target google_tests_run
google_tests_run_EXTERNAL_OBJECTS =

google_tests/google_tests_run: google_tests/CMakeFiles/google_tests_run.dir/TrieTest.cpp.o
google_tests/google_tests_run: google_tests/CMakeFiles/google_tests_run.dir/build.make
google_tests/google_tests_run: Trie_lib/libTrie_lib.a
google_tests/google_tests_run: lib/libgtestd.a
google_tests/google_tests_run: lib/libgtest_maind.a
google_tests/google_tests_run: lib/libgtestd.a
google_tests/google_tests_run: google_tests/CMakeFiles/google_tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aelysium/CLionProjects/suggest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable google_tests_run"
	cd /home/aelysium/CLionProjects/suggest/cmake-build-debug/google_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/google_tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
google_tests/CMakeFiles/google_tests_run.dir/build: google_tests/google_tests_run

.PHONY : google_tests/CMakeFiles/google_tests_run.dir/build

google_tests/CMakeFiles/google_tests_run.dir/clean:
	cd /home/aelysium/CLionProjects/suggest/cmake-build-debug/google_tests && $(CMAKE_COMMAND) -P CMakeFiles/google_tests_run.dir/cmake_clean.cmake
.PHONY : google_tests/CMakeFiles/google_tests_run.dir/clean

google_tests/CMakeFiles/google_tests_run.dir/depend:
	cd /home/aelysium/CLionProjects/suggest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aelysium/CLionProjects/suggest /home/aelysium/CLionProjects/suggest/google_tests /home/aelysium/CLionProjects/suggest/cmake-build-debug /home/aelysium/CLionProjects/suggest/cmake-build-debug/google_tests /home/aelysium/CLionProjects/suggest/cmake-build-debug/google_tests/CMakeFiles/google_tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : google_tests/CMakeFiles/google_tests_run.dir/depend


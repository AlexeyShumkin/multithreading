# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/awl/projects/multithreading/thread_pool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/awl/projects/multithreading/thread_pool/build

# Include any dependencies generated for this target.
include CMakeFiles/pool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pool.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pool.dir/flags.make

CMakeFiles/pool.dir/main.cpp.o: CMakeFiles/pool.dir/flags.make
CMakeFiles/pool.dir/main.cpp.o: ../main.cpp
CMakeFiles/pool.dir/main.cpp.o: CMakeFiles/pool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/multithreading/thread_pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pool.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pool.dir/main.cpp.o -MF CMakeFiles/pool.dir/main.cpp.o.d -o CMakeFiles/pool.dir/main.cpp.o -c /home/awl/projects/multithreading/thread_pool/main.cpp

CMakeFiles/pool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pool.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/multithreading/thread_pool/main.cpp > CMakeFiles/pool.dir/main.cpp.i

CMakeFiles/pool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pool.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/multithreading/thread_pool/main.cpp -o CMakeFiles/pool.dir/main.cpp.s

CMakeFiles/pool.dir/pool.cpp.o: CMakeFiles/pool.dir/flags.make
CMakeFiles/pool.dir/pool.cpp.o: ../pool.cpp
CMakeFiles/pool.dir/pool.cpp.o: CMakeFiles/pool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/multithreading/thread_pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pool.dir/pool.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pool.dir/pool.cpp.o -MF CMakeFiles/pool.dir/pool.cpp.o.d -o CMakeFiles/pool.dir/pool.cpp.o -c /home/awl/projects/multithreading/thread_pool/pool.cpp

CMakeFiles/pool.dir/pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pool.dir/pool.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/multithreading/thread_pool/pool.cpp > CMakeFiles/pool.dir/pool.cpp.i

CMakeFiles/pool.dir/pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pool.dir/pool.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/multithreading/thread_pool/pool.cpp -o CMakeFiles/pool.dir/pool.cpp.s

CMakeFiles/pool.dir/handler.cpp.o: CMakeFiles/pool.dir/flags.make
CMakeFiles/pool.dir/handler.cpp.o: ../handler.cpp
CMakeFiles/pool.dir/handler.cpp.o: CMakeFiles/pool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/multithreading/thread_pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pool.dir/handler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pool.dir/handler.cpp.o -MF CMakeFiles/pool.dir/handler.cpp.o.d -o CMakeFiles/pool.dir/handler.cpp.o -c /home/awl/projects/multithreading/thread_pool/handler.cpp

CMakeFiles/pool.dir/handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pool.dir/handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/multithreading/thread_pool/handler.cpp > CMakeFiles/pool.dir/handler.cpp.i

CMakeFiles/pool.dir/handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pool.dir/handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/multithreading/thread_pool/handler.cpp -o CMakeFiles/pool.dir/handler.cpp.s

# Object files for target pool
pool_OBJECTS = \
"CMakeFiles/pool.dir/main.cpp.o" \
"CMakeFiles/pool.dir/pool.cpp.o" \
"CMakeFiles/pool.dir/handler.cpp.o"

# External object files for target pool
pool_EXTERNAL_OBJECTS =

pool: CMakeFiles/pool.dir/main.cpp.o
pool: CMakeFiles/pool.dir/pool.cpp.o
pool: CMakeFiles/pool.dir/handler.cpp.o
pool: CMakeFiles/pool.dir/build.make
pool: CMakeFiles/pool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/awl/projects/multithreading/thread_pool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable pool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pool.dir/build: pool
.PHONY : CMakeFiles/pool.dir/build

CMakeFiles/pool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pool.dir/clean

CMakeFiles/pool.dir/depend:
	cd /home/awl/projects/multithreading/thread_pool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/awl/projects/multithreading/thread_pool /home/awl/projects/multithreading/thread_pool /home/awl/projects/multithreading/thread_pool/build /home/awl/projects/multithreading/thread_pool/build /home/awl/projects/multithreading/thread_pool/build/CMakeFiles/pool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pool.dir/depend

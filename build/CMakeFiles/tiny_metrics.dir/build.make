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
CMAKE_SOURCE_DIR = /home/rga/metricsDb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rga/metricsDb/build

# Include any dependencies generated for this target.
include CMakeFiles/tiny_metrics.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tiny_metrics.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tiny_metrics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tiny_metrics.dir/flags.make

CMakeFiles/tiny_metrics.dir/main.cpp.o: CMakeFiles/tiny_metrics.dir/flags.make
CMakeFiles/tiny_metrics.dir/main.cpp.o: ../main.cpp
CMakeFiles/tiny_metrics.dir/main.cpp.o: CMakeFiles/tiny_metrics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rga/metricsDb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tiny_metrics.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tiny_metrics.dir/main.cpp.o -MF CMakeFiles/tiny_metrics.dir/main.cpp.o.d -o CMakeFiles/tiny_metrics.dir/main.cpp.o -c /home/rga/metricsDb/main.cpp

CMakeFiles/tiny_metrics.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_metrics.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rga/metricsDb/main.cpp > CMakeFiles/tiny_metrics.dir/main.cpp.i

CMakeFiles/tiny_metrics.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_metrics.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rga/metricsDb/main.cpp -o CMakeFiles/tiny_metrics.dir/main.cpp.s

CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o: CMakeFiles/tiny_metrics.dir/flags.make
CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o: ../metrics-db.cpp
CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o: CMakeFiles/tiny_metrics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rga/metricsDb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o -MF CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o.d -o CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o -c /home/rga/metricsDb/metrics-db.cpp

CMakeFiles/tiny_metrics.dir/metrics-db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_metrics.dir/metrics-db.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rga/metricsDb/metrics-db.cpp > CMakeFiles/tiny_metrics.dir/metrics-db.cpp.i

CMakeFiles/tiny_metrics.dir/metrics-db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_metrics.dir/metrics-db.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rga/metricsDb/metrics-db.cpp -o CMakeFiles/tiny_metrics.dir/metrics-db.cpp.s

CMakeFiles/tiny_metrics.dir/file-writer.cpp.o: CMakeFiles/tiny_metrics.dir/flags.make
CMakeFiles/tiny_metrics.dir/file-writer.cpp.o: ../file-writer.cpp
CMakeFiles/tiny_metrics.dir/file-writer.cpp.o: CMakeFiles/tiny_metrics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rga/metricsDb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tiny_metrics.dir/file-writer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tiny_metrics.dir/file-writer.cpp.o -MF CMakeFiles/tiny_metrics.dir/file-writer.cpp.o.d -o CMakeFiles/tiny_metrics.dir/file-writer.cpp.o -c /home/rga/metricsDb/file-writer.cpp

CMakeFiles/tiny_metrics.dir/file-writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_metrics.dir/file-writer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rga/metricsDb/file-writer.cpp > CMakeFiles/tiny_metrics.dir/file-writer.cpp.i

CMakeFiles/tiny_metrics.dir/file-writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_metrics.dir/file-writer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rga/metricsDb/file-writer.cpp -o CMakeFiles/tiny_metrics.dir/file-writer.cpp.s

CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o: CMakeFiles/tiny_metrics.dir/flags.make
CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o: ../labels-writer.cpp
CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o: CMakeFiles/tiny_metrics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rga/metricsDb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o -MF CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o.d -o CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o -c /home/rga/metricsDb/labels-writer.cpp

CMakeFiles/tiny_metrics.dir/labels-writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_metrics.dir/labels-writer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rga/metricsDb/labels-writer.cpp > CMakeFiles/tiny_metrics.dir/labels-writer.cpp.i

CMakeFiles/tiny_metrics.dir/labels-writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_metrics.dir/labels-writer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rga/metricsDb/labels-writer.cpp -o CMakeFiles/tiny_metrics.dir/labels-writer.cpp.s

# Object files for target tiny_metrics
tiny_metrics_OBJECTS = \
"CMakeFiles/tiny_metrics.dir/main.cpp.o" \
"CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o" \
"CMakeFiles/tiny_metrics.dir/file-writer.cpp.o" \
"CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o"

# External object files for target tiny_metrics
tiny_metrics_EXTERNAL_OBJECTS =

tiny_metrics: CMakeFiles/tiny_metrics.dir/main.cpp.o
tiny_metrics: CMakeFiles/tiny_metrics.dir/metrics-db.cpp.o
tiny_metrics: CMakeFiles/tiny_metrics.dir/file-writer.cpp.o
tiny_metrics: CMakeFiles/tiny_metrics.dir/labels-writer.cpp.o
tiny_metrics: CMakeFiles/tiny_metrics.dir/build.make
tiny_metrics: CMakeFiles/tiny_metrics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rga/metricsDb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable tiny_metrics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tiny_metrics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tiny_metrics.dir/build: tiny_metrics
.PHONY : CMakeFiles/tiny_metrics.dir/build

CMakeFiles/tiny_metrics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tiny_metrics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tiny_metrics.dir/clean

CMakeFiles/tiny_metrics.dir/depend:
	cd /home/rga/metricsDb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rga/metricsDb /home/rga/metricsDb /home/rga/metricsDb/build /home/rga/metricsDb/build /home/rga/metricsDb/build/CMakeFiles/tiny_metrics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tiny_metrics.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/bbk/ProgramFiles/CLion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bbk/ProgramFiles/CLion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TextureLoader.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TextureLoader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TextureLoader.dir/flags.make

CMakeFiles/TextureLoader.dir/main.cpp.o: CMakeFiles/TextureLoader.dir/flags.make
CMakeFiles/TextureLoader.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TextureLoader.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TextureLoader.dir/main.cpp.o -c /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/main.cpp

CMakeFiles/TextureLoader.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextureLoader.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/main.cpp > CMakeFiles/TextureLoader.dir/main.cpp.i

CMakeFiles/TextureLoader.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextureLoader.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/main.cpp -o CMakeFiles/TextureLoader.dir/main.cpp.s

# Object files for target TextureLoader
TextureLoader_OBJECTS = \
"CMakeFiles/TextureLoader.dir/main.cpp.o"

# External object files for target TextureLoader
TextureLoader_EXTERNAL_OBJECTS =

TextureLoader: CMakeFiles/TextureLoader.dir/main.cpp.o
TextureLoader: CMakeFiles/TextureLoader.dir/build.make
TextureLoader: /usr/lib/x86_64-linux-gnu/libGL.so
TextureLoader: /usr/lib/x86_64-linux-gnu/libGLU.so
TextureLoader: /usr/lib/x86_64-linux-gnu/libSDL2.so
TextureLoader: CMakeFiles/TextureLoader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TextureLoader"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TextureLoader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TextureLoader.dir/build: TextureLoader

.PHONY : CMakeFiles/TextureLoader.dir/build

CMakeFiles/TextureLoader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TextureLoader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TextureLoader.dir/clean

CMakeFiles/TextureLoader.dir/depend:
	cd /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/cmake-build-debug /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/cmake-build-debug /home/bbk/CLionProjects/OpenGLPlayground/TextureLoader/cmake-build-debug/CMakeFiles/TextureLoader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TextureLoader.dir/depend

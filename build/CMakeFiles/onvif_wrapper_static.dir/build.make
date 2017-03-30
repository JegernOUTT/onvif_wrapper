# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build

# Include any dependencies generated for this target.
include CMakeFiles/onvif_wrapper_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/onvif_wrapper_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/onvif_wrapper_static.dir/flags.make

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o: CMakeFiles/onvif_wrapper_static.dir/flags.make
CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o: ../source/OnvifClientPtz.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o -c /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientPtz.cpp

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientPtz.cpp > CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.i

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientPtz.cpp -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.s

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.requires:

.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.requires

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.provides: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.requires
	$(MAKE) -f CMakeFiles/onvif_wrapper_static.dir/build.make CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.provides.build
.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.provides

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.provides.build: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o


CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o: CMakeFiles/onvif_wrapper_static.dir/flags.make
CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o: ../source/Onvif.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o -c /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/Onvif.cpp

CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/Onvif.cpp > CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.i

CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/Onvif.cpp -o CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.s

CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.requires:

.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.requires

CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.provides: CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.requires
	$(MAKE) -f CMakeFiles/onvif_wrapper_static.dir/build.make CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.provides.build
.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.provides

CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.provides.build: CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o


CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o: CMakeFiles/onvif_wrapper_static.dir/flags.make
CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o: ../source/OnvifClientImaging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o -c /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientImaging.cpp

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientImaging.cpp > CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.i

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientImaging.cpp -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.s

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.requires:

.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.requires

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.provides: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.requires
	$(MAKE) -f CMakeFiles/onvif_wrapper_static.dir/build.make CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.provides.build
.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.provides

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.provides.build: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o


CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o: CMakeFiles/onvif_wrapper_static.dir/flags.make
CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o: ../source/OnvifClientMedia.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o -c /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientMedia.cpp

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientMedia.cpp > CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.i

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientMedia.cpp -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.s

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.requires:

.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.requires

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.provides: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.requires
	$(MAKE) -f CMakeFiles/onvif_wrapper_static.dir/build.make CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.provides.build
.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.provides

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.provides.build: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o


CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o: CMakeFiles/onvif_wrapper_static.dir/flags.make
CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o: ../source/OnvifClientDevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o -c /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientDevice.cpp

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientDevice.cpp > CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.i

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/source/OnvifClientDevice.cpp -o CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.s

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.requires:

.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.requires

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.provides: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.requires
	$(MAKE) -f CMakeFiles/onvif_wrapper_static.dir/build.make CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.provides.build
.PHONY : CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.provides

CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.provides.build: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o


# Object files for target onvif_wrapper_static
onvif_wrapper_static_OBJECTS = \
"CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o" \
"CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o" \
"CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o" \
"CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o" \
"CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o"

# External object files for target onvif_wrapper_static
onvif_wrapper_static_EXTERNAL_OBJECTS =

libonvif_wrapper_static.a: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o
libonvif_wrapper_static.a: CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o
libonvif_wrapper_static.a: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o
libonvif_wrapper_static.a: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o
libonvif_wrapper_static.a: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o
libonvif_wrapper_static.a: CMakeFiles/onvif_wrapper_static.dir/build.make
libonvif_wrapper_static.a: CMakeFiles/onvif_wrapper_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libonvif_wrapper_static.a"
	$(CMAKE_COMMAND) -P CMakeFiles/onvif_wrapper_static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/onvif_wrapper_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/onvif_wrapper_static.dir/build: libonvif_wrapper_static.a

.PHONY : CMakeFiles/onvif_wrapper_static.dir/build

CMakeFiles/onvif_wrapper_static.dir/requires: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientPtz.cpp.o.requires
CMakeFiles/onvif_wrapper_static.dir/requires: CMakeFiles/onvif_wrapper_static.dir/source/Onvif.cpp.o.requires
CMakeFiles/onvif_wrapper_static.dir/requires: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientImaging.cpp.o.requires
CMakeFiles/onvif_wrapper_static.dir/requires: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientMedia.cpp.o.requires
CMakeFiles/onvif_wrapper_static.dir/requires: CMakeFiles/onvif_wrapper_static.dir/source/OnvifClientDevice.cpp.o.requires

.PHONY : CMakeFiles/onvif_wrapper_static.dir/requires

CMakeFiles/onvif_wrapper_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/onvif_wrapper_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/onvif_wrapper_static.dir/clean

CMakeFiles/onvif_wrapper_static.dir/depend:
	cd /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build /home/svakhreev/Projects/CameraManagerCore/3rdParty/onvif_wrapper/build/CMakeFiles/onvif_wrapper_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/onvif_wrapper_static.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/39348/Documents/progetti_c/sdl-blank-prj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build

# Include any dependencies generated for this target.
include CMakeFiles/SDLWindowPrj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SDLWindowPrj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDLWindowPrj.dir/flags.make

CMakeFiles/SDLWindowPrj.dir/src/main.c.obj: CMakeFiles/SDLWindowPrj.dir/flags.make
CMakeFiles/SDLWindowPrj.dir/src/main.c.obj: CMakeFiles/SDLWindowPrj.dir/includes_C.rsp
CMakeFiles/SDLWindowPrj.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SDLWindowPrj.dir/src/main.c.obj"
	"D:/Program Files/LLVM/bin/clang.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SDLWindowPrj.dir/src/main.c.obj -c C:/Users/39348/Documents/progetti_c/sdl-blank-prj/src/main.c

CMakeFiles/SDLWindowPrj.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SDLWindowPrj.dir/src/main.c.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_C_CREATE_PREPROCESSED_SOURCE

CMakeFiles/SDLWindowPrj.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SDLWindowPrj.dir/src/main.c.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_C_CREATE_ASSEMBLY_SOURCE

# Object files for target SDLWindowPrj
SDLWindowPrj_OBJECTS = \
"CMakeFiles/SDLWindowPrj.dir/src/main.c.obj"

# External object files for target SDLWindowPrj
SDLWindowPrj_EXTERNAL_OBJECTS =

SDLWindowPrj.exe: CMakeFiles/SDLWindowPrj.dir/src/main.c.obj
SDLWindowPrj.exe: CMakeFiles/SDLWindowPrj.dir/build.make
SDLWindowPrj.exe: ../cmake/sdl2/lib/x64/SDL2.lib
SDLWindowPrj.exe: ../cmake/sdl2_image/lib/x64/SDL2_image.lib
SDLWindowPrj.exe: ../cmake/sdl2_ttf/lib/x64/SDL2_ttf.lib
SDLWindowPrj.exe: ../cmake/sdl2_mixer/lib/x64/SDL2_mixer.lib
SDLWindowPrj.exe: CMakeFiles/SDLWindowPrj.dir/linklibs.rsp
SDLWindowPrj.exe: CMakeFiles/SDLWindowPrj.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SDLWindowPrj.exe"
	"D:/Program Files/LLVM/bin/clang.exe" -fuse-ld=lld-link -nostartfiles -nostdlib -g -Xclang -gcodeview -O0 -D_DEBUG -D_DLL -D_MT -Xclang --dependent-lib=msvcrtd @CMakeFiles/SDLWindowPrj.dir/objects1.rsp -o SDLWindowPrj.exe -Xlinker /implib:SDLWindowPrj.lib -Xlinker /pdb:C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build/SDLWindowPrj.pdb -Xlinker /version:0.0  @CMakeFiles/SDLWindowPrj.dir/linklibs.rsp
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2/lib/x64/SDL2.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_image/lib/x64/SDL2_image.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_image/lib/x64/libjpeg-9.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_image/lib/x64/libpng16-16.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_image/lib/x64/libtiff-5.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_image/lib/x64/libwebp-7.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_image/lib/x64/zlib1.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_ttf/lib/x64/SDL2_ttf.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_ttf/lib/x64/libfreetype-6.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_ttf/lib/x64/zlib1.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/SDL2_mixer.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libFLAC-8.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libmodplug-1.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libmpg123-0.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libogg-0.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libopus-0.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libopusfile-0.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libvorbis-0.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_if_different C:/Users/39348/Documents/progetti_c/sdl-blank-prj/cmake/sdl2_mixer/lib/x64/libvorbisfile-3.dll C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build
	"C:/Program Files/CMake/bin/cmake.exe" -E cmake_echo_color --cyan "Copy Resources..."
	"C:/Program Files/CMake/bin/cmake.exe" -E copy_directory C:/Users/39348/Documents/progetti_c/sdl-blank-prj/resources C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build/resources

# Rule to build all files generated by this target.
CMakeFiles/SDLWindowPrj.dir/build: SDLWindowPrj.exe

.PHONY : CMakeFiles/SDLWindowPrj.dir/build

CMakeFiles/SDLWindowPrj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDLWindowPrj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDLWindowPrj.dir/clean

CMakeFiles/SDLWindowPrj.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/39348/Documents/progetti_c/sdl-blank-prj C:/Users/39348/Documents/progetti_c/sdl-blank-prj C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build C:/Users/39348/Documents/progetti_c/sdl-blank-prj/build/CMakeFiles/SDLWindowPrj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDLWindowPrj.dir/depend


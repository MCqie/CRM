# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\program\Jetbrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\program\Jetbrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ProgramData\ClionProj\Socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ProgramData\ClionProj\Socket\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Socket.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Socket.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Socket.dir\flags.make

CMakeFiles\Socket.dir\main.cpp.obj: CMakeFiles\Socket.dir\flags.make
CMakeFiles\Socket.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProgramData\ClionProj\Socket\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Socket.dir/main.cpp.obj"
	D:\program\VS\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Socket.dir\main.cpp.obj /FdCMakeFiles\Socket.dir\ /FS -c D:\ProgramData\ClionProj\Socket\main.cpp
<<

CMakeFiles\Socket.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Socket.dir/main.cpp.i"
	D:\program\VS\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Socket.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProgramData\ClionProj\Socket\main.cpp
<<

CMakeFiles\Socket.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Socket.dir/main.cpp.s"
	D:\program\VS\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Socket.dir\main.cpp.s /c D:\ProgramData\ClionProj\Socket\main.cpp
<<

# Object files for target Socket
Socket_OBJECTS = \
"CMakeFiles\Socket.dir\main.cpp.obj"

# External object files for target Socket
Socket_EXTERNAL_OBJECTS =

Socket.exe: CMakeFiles\Socket.dir\main.cpp.obj
Socket.exe: CMakeFiles\Socket.dir\build.make
Socket.exe: CMakeFiles\Socket.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ProgramData\ClionProj\Socket\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Socket.exe"
	"D:\program\Jetbrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Socket.dir --rc="D:\Windows Kits\10\bin\10.0.18362.0\x86\rc.exe" --mt="D:\Windows Kits\10\bin\10.0.18362.0\x86\mt.exe" --manifests  -- D:\program\VS\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Socket.dir\objects1.rsp @<<
 /out:Socket.exe /implib:Socket.lib /pdb:D:\ProgramData\ClionProj\Socket\cmake-build-debug\Socket.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Socket.dir\build: Socket.exe

.PHONY : CMakeFiles\Socket.dir\build

CMakeFiles\Socket.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Socket.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Socket.dir\clean

CMakeFiles\Socket.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\ProgramData\ClionProj\Socket D:\ProgramData\ClionProj\Socket D:\ProgramData\ClionProj\Socket\cmake-build-debug D:\ProgramData\ClionProj\Socket\cmake-build-debug D:\ProgramData\ClionProj\Socket\cmake-build-debug\CMakeFiles\Socket.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Socket.dir\depend


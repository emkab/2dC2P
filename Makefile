# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/emkab/dev/2dc2p

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/emkab/dev/2dc2p

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running tests..."
	/opt/homebrew/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/opt/homebrew/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/opt/homebrew/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/emkab/dev/2dc2p/CMakeFiles /Users/emkab/dev/2dc2p//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/emkab/dev/2dc2p/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named 2dc2p

# Build rule for target.
2dc2p: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 2dc2p
.PHONY : 2dc2p

# fast build rule for target.
2dc2p/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/build
.PHONY : 2dc2p/fast

src/ball.o: src/ball.cpp.o
.PHONY : src/ball.o

# target to build an object file
src/ball.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/ball.cpp.o
.PHONY : src/ball.cpp.o

src/ball.i: src/ball.cpp.i
.PHONY : src/ball.i

# target to preprocess a source file
src/ball.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/ball.cpp.i
.PHONY : src/ball.cpp.i

src/ball.s: src/ball.cpp.s
.PHONY : src/ball.s

# target to generate assembly for a file
src/ball.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/ball.cpp.s
.PHONY : src/ball.cpp.s

src/entity.o: src/entity.cpp.o
.PHONY : src/entity.o

# target to build an object file
src/entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/entity.cpp.o
.PHONY : src/entity.cpp.o

src/entity.i: src/entity.cpp.i
.PHONY : src/entity.i

# target to preprocess a source file
src/entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/entity.cpp.i
.PHONY : src/entity.cpp.i

src/entity.s: src/entity.cpp.s
.PHONY : src/entity.s

# target to generate assembly for a file
src/entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/entity.cpp.s
.PHONY : src/entity.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/renderWindow.o: src/renderWindow.cpp.o
.PHONY : src/renderWindow.o

# target to build an object file
src/renderWindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/renderWindow.cpp.o
.PHONY : src/renderWindow.cpp.o

src/renderWindow.i: src/renderWindow.cpp.i
.PHONY : src/renderWindow.i

# target to preprocess a source file
src/renderWindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/renderWindow.cpp.i
.PHONY : src/renderWindow.cpp.i

src/renderWindow.s: src/renderWindow.cpp.s
.PHONY : src/renderWindow.s

# target to generate assembly for a file
src/renderWindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/renderWindow.cpp.s
.PHONY : src/renderWindow.cpp.s

src/tools.o: src/tools.cpp.o
.PHONY : src/tools.o

# target to build an object file
src/tools.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/tools.cpp.o
.PHONY : src/tools.cpp.o

src/tools.i: src/tools.cpp.i
.PHONY : src/tools.i

# target to preprocess a source file
src/tools.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/tools.cpp.i
.PHONY : src/tools.cpp.i

src/tools.s: src/tools.cpp.s
.PHONY : src/tools.s

# target to generate assembly for a file
src/tools.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/tools.cpp.s
.PHONY : src/tools.cpp.s

src/vector.o: src/vector.cpp.o
.PHONY : src/vector.o

# target to build an object file
src/vector.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/vector.cpp.o
.PHONY : src/vector.cpp.o

src/vector.i: src/vector.cpp.i
.PHONY : src/vector.i

# target to preprocess a source file
src/vector.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/vector.cpp.i
.PHONY : src/vector.cpp.i

src/vector.s: src/vector.cpp.s
.PHONY : src/vector.s

# target to generate assembly for a file
src/vector.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/2dc2p.dir/build.make CMakeFiles/2dc2p.dir/src/vector.cpp.s
.PHONY : src/vector.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... 2dc2p"
	@echo "... src/ball.o"
	@echo "... src/ball.i"
	@echo "... src/ball.s"
	@echo "... src/entity.o"
	@echo "... src/entity.i"
	@echo "... src/entity.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/renderWindow.o"
	@echo "... src/renderWindow.i"
	@echo "... src/renderWindow.s"
	@echo "... src/tools.o"
	@echo "... src/tools.i"
	@echo "... src/tools.s"
	@echo "... src/vector.o"
	@echo "... src/vector.i"
	@echo "... src/vector.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


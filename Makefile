# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andersalho/Documents/Aalto-yliopisto/Cpp-kansio/project/tower-defense-2020-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andersalho/Documents/Aalto-yliopisto/Cpp-kansio/project/tower-defense-2020-2

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.17.3/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.17.3/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/andersalho/Documents/Aalto-yliopisto/Cpp-kansio/project/tower-defense-2020-2/CMakeFiles /Users/andersalho/Documents/Aalto-yliopisto/Cpp-kansio/project/tower-defense-2020-2/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/andersalho/Documents/Aalto-yliopisto/Cpp-kansio/project/tower-defense-2020-2/CMakeFiles 0
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
# Target rules for targets named TowerDefense

# Build rule for target.
TowerDefense: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TowerDefense
.PHONY : TowerDefense

# fast build rule for target.
TowerDefense/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/build
.PHONY : TowerDefense/fast

src/bullet.o: src/bullet.cpp.o

.PHONY : src/bullet.o

# target to build an object file
src/bullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/bullet.cpp.o
.PHONY : src/bullet.cpp.o

src/bullet.i: src/bullet.cpp.i

.PHONY : src/bullet.i

# target to preprocess a source file
src/bullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/bullet.cpp.i
.PHONY : src/bullet.cpp.i

src/bullet.s: src/bullet.cpp.s

.PHONY : src/bullet.s

# target to generate assembly for a file
src/bullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/bullet.cpp.s
.PHONY : src/bullet.cpp.s

src/enemy.o: src/enemy.cpp.o

.PHONY : src/enemy.o

# target to build an object file
src/enemy.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/enemy.cpp.o
.PHONY : src/enemy.cpp.o

src/enemy.i: src/enemy.cpp.i

.PHONY : src/enemy.i

# target to preprocess a source file
src/enemy.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/enemy.cpp.i
.PHONY : src/enemy.cpp.i

src/enemy.s: src/enemy.cpp.s

.PHONY : src/enemy.s

# target to generate assembly for a file
src/enemy.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/enemy.cpp.s
.PHONY : src/enemy.cpp.s

src/game_field.o: src/game_field.cpp.o

.PHONY : src/game_field.o

# target to build an object file
src/game_field.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/game_field.cpp.o
.PHONY : src/game_field.cpp.o

src/game_field.i: src/game_field.cpp.i

.PHONY : src/game_field.i

# target to preprocess a source file
src/game_field.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/game_field.cpp.i
.PHONY : src/game_field.cpp.i

src/game_field.s: src/game_field.cpp.s

.PHONY : src/game_field.s

# target to generate assembly for a file
src/game_field.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/game_field.cpp.s
.PHONY : src/game_field.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/tower.o: src/tower.cpp.o

.PHONY : src/tower.o

# target to build an object file
src/tower.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/tower.cpp.o
.PHONY : src/tower.cpp.o

src/tower.i: src/tower.cpp.i

.PHONY : src/tower.i

# target to preprocess a source file
src/tower.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/tower.cpp.i
.PHONY : src/tower.cpp.i

src/tower.s: src/tower.cpp.s

.PHONY : src/tower.s

# target to generate assembly for a file
src/tower.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TowerDefense.dir/build.make CMakeFiles/TowerDefense.dir/src/tower.cpp.s
.PHONY : src/tower.cpp.s

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
	@echo "... TowerDefense"
	@echo "... src/bullet.o"
	@echo "... src/bullet.i"
	@echo "... src/bullet.s"
	@echo "... src/enemy.o"
	@echo "... src/enemy.i"
	@echo "... src/enemy.s"
	@echo "... src/game_field.o"
	@echo "... src/game_field.i"
	@echo "... src/game_field.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/tower.o"
	@echo "... src/tower.i"
	@echo "... src/tower.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


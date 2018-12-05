# By Cody Lee - Fall 2018
# a makefile that compiles code located in a source code directory into
# compartamentalized subdirectories for executables and object files
# commented for maximum understandability explained in easy english

# define a variable name corresponding to a path to a directory
SRC_DIR = src
# define a variable name corresponding to a path to a directory
OBJ_DIR = obj
# define a variable name corresponding to a path to a directory
BINDIR = bin

# Define the compilers being used for C and C++ files
CC       = gcc
# Define the compilers being used for C and C++ files
CXX      = g++
# This specifies we will compile with c++11 warn all
CXXFLAGS = -std=c++11 -Wall
# This includes the OpenGL libraries
LDLIBS   = -lglut -lGL -lGLU -lm 

################################################################################
# How to compile all files in /src to /obj and link with /bin
# https://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in
################################################################################
# a definition of a shortcut to all .cpp files contained in SRCDR
SRCS  := $(wildcard $(SRC_DIR)/*.cpp)
# a definition of a shortcut to all .h files contained in SRC_DIR
HEADERS := $(wildcard $(SRC_DIR)/*.h)
# a definition of a shortcut to all .o files contained in OBJ_DIR
# all OBJ_DIR files will be named after the corresponding .cpp files which are
# encapusalated by our defition of SRCS located in SRC_DIR
OBJS  := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Defines our executable name
TARGET = demo

# master call that is used whenever no arguement to make is specified
all: $(BINDIR)/$(TARGET)

# links compiled executable file to files in OBJS directory
# uses our compiler to create .o files dependent on our LDLIBS libraries
$(BINDIR)/$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

# method explained in line order: 
# -p creates the intermediate directories for a new directory if they do not already exist.
# creates a new directory at OBJ_DIR to hold .o files
# $@ is the name of the file being generated
# $< the first prerequisite (usually the source file)
$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# method explained in line order:
# removes *.o files such as "src.o" from OBJ_DIR
clean:
	rm -f $(OBJ_DIR)/*.o

# method explained in line order:
# removes *.out files such as "a.out" from BINDIR
# removes *.exe files such as "bin.exe" from BINDIR
# removes TARGET file such as "demo" from BINDIR
# deletes the OBJ_DIR which contains .o files
pristine:
	rm -f $(BINDIR)/*.out 
	rm -f $(BINDIR)/*.exe
	rm -f $(BINDIR)/$(TARGET)
	rm -rf $(OBJ_DIR)

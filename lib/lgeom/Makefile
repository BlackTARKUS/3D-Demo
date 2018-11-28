# a library structure that defines common, non-project specific code in
# lib/lgeom, and project specific code in src/
# enables cross compiling between cpp and c and sets the GCC compiler to always
# use the -Warn All flag so I can get useful information on what I broke. 

# src/ should hold .cpp, .c and .h files, the .h files are located with
# the INCLUDES sctoin, and the .cpp and .c are compiled into .o files as part
# of the SOURCES section. When compiled an executable named "demo" will appear
# in the bin/ directory which can be ran to test the project. .o files are
# stored in their own directory which is generated at compile time for the sake
# of neatness. These .o files are deleted when clean: is called, but to delete
# their dirctory one must run pristine:

CC       = gcc
CXX      = g++
CFLAGS   = -Wall
CXXFLAGS = -std=c++11 -Wall
LDLIBS   = -lglut -lGL -lGLU -lm
INCLUDE  = -I./

SRCDIR  = src
OBJDIR  = obj
INCDIR  = include
LIBDIR  = lib
BINDIR  = $(LIBDIR)

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

TARGET = $(BINDIR)/liblgeom.a
HEADERS  := $(INCLUDES:$(SRCDIR)/%.h=$(INCDIR)/lgeom/%.h)

all: $(OBJECTS) $(TARGET) $(HEADERS)
ifeq ($(LIBDEST),)
else
	cp -r $(LIBDIR)/* $(LIBDEST)
endif
ifeq ($(INCLUDEDEST),)
else
	cp -r $(INCDIR)/* $(INCLUDEDEST)
endif

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	ar -rc $@ $^
	ranlib $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(HEADERS): $(INCDIR)/lgeom/%.h : $(SRCDIR)/%.h
	@mkdir -p $(INCDIR)/lgeom
	@sed -e "/^\/\/\/.*$$/d" $< >> $@

clean:
	rm -f $(OBJDIR)/*.o

pristine: clean
	rm -rf $(OBJDIR)
	rm -f $(BINDIR)/*.out
	rm -f $(BINDIR)/*.exe
	rm -f *.exe
	rm -f $(BINDIR)/$(TARGET)
	rm -rf $(BINDIR)
	rm -rf $(INCDIR)/lgeom

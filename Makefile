SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBDIR = lib
BINDIR = bin

CC       = gcc
CXX      = g++
CXXFLAGS = -std=c++11 -Wall -I$(INCDIR)
LDLIBS   = -lglut -lGL -lGLU -lm -L$(LIBDIR) -llgeom

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

TARGET = demo

export LIBDEST = "$(shell pwd)/$(LIBDIR)"
export INCLUDEDEST = "$(shell pwd)/$(INCDIR)"

all: liblgeom $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDLIBS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

liblgeom:
	$(MAKE) -C lib/lgeom

clean:
	rm -f $(OBJDIR)/*.o
	$(MAKE) clean -C lib/lgeom

pristine: clean
	rm -f $(BINDIR)/*.out
	rm -f $(BINDIR)/*.exe
	rm -f $(BINDIR)/$(TARGET)
	rm -rf $(OBJDIR)
	rm -f lib/liblgeom.a
	rm -rf include/lgeom*
	$(MAKE) pristine -C lib/lgeom

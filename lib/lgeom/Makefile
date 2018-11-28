
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

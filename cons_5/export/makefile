# makefile written for gnu make
SRCDIR = ./src
BINDIR = ./bin
BUILDDIR = ./build
INCLDIR = ./include
LIBDIR = ./lib
CXX = g++
CPPFLAGS = -I$(INCLDIR) -I$(INCLDIR)/xmlrpc
DEBUG = -g
OPTIMIZE = -O2
GCCWARN = -Wall
CXXFLAGS = $(DEBUG) $(GCCWARN) $(OPTIMIZE)

LIB = $(LIBDIR)/xmlrpc.a
SYSTEMLIBS = -lws2_32

LDLIBS = $(LIB) $(SYSTEMLIBS)

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SOURCES))
EXECUTABLE = $(BUILDDIR)/server

all: $(LIB) $(EXECUTABLE)

$(LIB):
	cd $(LIBDIR) && $(MAKE)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: all clean

clean:
	rm -f $(BINDIR)/*.o $(EXECUTABLE)
	cd $(LIBDIR) && $(MAKE) clean

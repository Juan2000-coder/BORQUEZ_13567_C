# makefile written for gnu make
SRCDIR = ./src
BINDIR = ./bin
BUILDDIR = ./build
INCLDIR = ../include
CXX		= g++
CPPFLAGS	= -I$(INCLDIR) -I$(INCLDIR)/xmlrpc
DEBUG		= -g
OPTIMIZE	= -O2
GCCWARN		= -Wall
CXXFLAGS	= $(DEBUG) $(GCCWARN) $(OPTIMIZE)

LIB		= ../lib/xmlrpc.a
SYSTEMLIBS	= -lws2_32

LDLIBS		= $(LIB) $(SYSTEMLIBS)

SOURCES		= $(wildcard $(SRCDIR)/*cpp)
OBJECTS		= $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SOURCES))
EXECUTABLE = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.exe, $(SOURCES))

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@


$(BUILDDIR)/%.exe:	$(BINDIR)/%.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDLIBS)


.PHONY: all clean

all:		$(EXECUTABLE)

clean:
	rm -f $(BINDIR)/*.o
	rm -f $(BUILDDIR)/*.exe

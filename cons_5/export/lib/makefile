# makefile written for gnu make
CXX		= g++
SRCDIR	= ../src/xmlrpc
INCDIR	= ../include
BINDIR = ../bin/xmlrpc
LIBDIR = ../lib
CPPFLAGS	= -I$(INCDIR) -I$(INCDIR)/xmlrpc
DEBUG		= -g
OPTIMIZE	= -O2
GCCWARN		= -Wall -Wstrict-prototypes
CXXFLAGS	= $(DEBUG) $(GCCWARN) $(OPTIMIZE)

LIB		= $(LIBDIR)/xmlrpc.a

SYSTEMLIBS	= -lws2_32
LDLIBS		= $(LIB) $(SYSTEMLIBS)

SOURCES		= $(wildcard $(SRCDIR)/*cpp)
OBJECTS		= $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SOURCES))

all:		$(LIB)

$(LIB):		$(OBJECTS)
	$(AR) $(ARFLAGS) $(LIB) $(OBJECTS)

$(BINDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@
	
doc doxygen:
	cd src && doxygen Doxyfile

clean:
	rm -f $(BINDIR)/*.o
	rm -f $(LIBDIR)/*.a
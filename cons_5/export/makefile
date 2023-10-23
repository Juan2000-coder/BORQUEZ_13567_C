# makefile written for gnu make
CXX		= g++ 
INCLUDE1	= ./include
INCLUDE2	= ./include/xmlrcp	
CPPFLAGS	= -I$(INCLUDE1) -I$(INCLUDE2)
DEBUG		= -g
OPTIMIZE	= -O2
GCCWARN		= -Wall
CXXFLAGS	= $(DEBUG) $(GCCWARN) $(OPTIMIZE) $(CPPFLAGS)

LIB		= ./build/libXmlRpc.a

# Add your system-dependent network libs here
# Solaris: -lsocket -lnsl
SYSTEMLIBS	= -lws2_32

LDLIBS		= $(LIB) $(SYSTEMLIBS)

SRCS		= $(wildcard ./src/*.cpp)
OBJS 		= $(SRCS:src/.cpp=build/.o)
EXE			= ./Server

all:		$(EXE)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXE):	$(OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) -o $@

clean:
	rm -f $(OBJS) $(EXE)

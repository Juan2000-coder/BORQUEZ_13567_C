# makefile written for gnu make
CXX		= g++ 
INCLUDE		= ./include
CPPFLAGS	= -I$(INCLUDE)
DEBUG		= -g
OPTIMIZE	= -O2
GCCWARN		= -Wall
CXXFLAGS	= $(DEBUG) $(GCCWARN) $(OPTIMIZE) $(CPPFLAGS)

LIB		= ./libXmlRpc.a

# Add your system-dependent network libs here
# Solaris: -lsocket -lnsl
SYSTEMLIBS	= -lws2_32

LDLIBS		= $(LIB) $(SYSTEMLIBS)

SRCS		= $(wildcard ./src/*.cpp)
OBJS 		= $(SRCS:.cpp=.o)
EXE			= ./build/HolaServer

all:		$(EXE)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXE):	$(OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) -o $@

clean:
	rm -f $(OBJS) $(EXE)

# makefile written for gnu make
SRCDIR = ./src
BINDIR = ./bin
BUILDDIR = ./build
INCLDIR = ./include
LIBDIR = ./lib
CXX = g++
CPPFLAGS = -I$(INCLDIR)/server -I$(INCLDIR)/client -I$(INCLDIR)/xmlrpc
DEBUG = -g
OPTIMIZE = -O2
GCCWARN = -Wall
CXXFLAGS = $(DEBUG) $(GCCWARN) $(OPTIMIZE)

LIB = $(LIBDIR)/xmlrpc.a
SYSTEMLIBS = -lws2_32

LDLIBS = $(LIB) $(SYSTEMLIBS)

SERVERSOURCES = $(wildcard $(SRCDIR)/server/*.cpp)
CLIENTSOURCES = $(wildcard $(SRCDIR)/client/*.cpp)


SERVEROBJECTS = $(patsubst $(SRCDIR)/server/%.cpp, $(BINDIR)/server/%.o, $(SERVERSOURCES))
CLIENTOBJECTS = $(patsubst $(SRCDIR)/client/%.cpp, $(BINDIR)/client/%.o, $(CLIENTSOURCES))



SERVEREXECUTABLE = $(BUILDDIR)/server
CLIENTEXECUTABLE = $(BUILDDIR)/client



all: $(LIB) $(SERVEREXECUTABLE) $(CLIENTEXECUTABLE)

$(LIB):
	cd $(LIBDIR) && $(MAKE)

$(BINDIR)/server/%.o: $(SRCDIR)/server/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(BINDIR)/client/%.o: $(SRCDIR)/client/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(SERVEREXECUTABLE): $(SERVEROBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

$(CLIENTEXECUTABLE): $(CLIENTOBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

$(XMLRPCOBJECTS):$(LIB)
.PHONY: all clean

clean:
	rm -f $(BINDIR)/server/*.o $(SERVEREXECUTABLE)
	rm -f $(BINDIR)/client/*.o $(CLIENTEXECUTABLE)
	cd $(LIBDIR) && $(MAKE) clean
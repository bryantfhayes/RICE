SOURCES=$(wildcard src/*.cpp)
OBJS=$(SOURCES:.cpp=.o)

APP=rougelike

# compiler options : add debug information in debug mode
# optimize speed and size in release mode
ifneq (,$(findstring debug,$(MAKECMDGOALS)))
	CFLAGS=-g
else
	CFLAGS=-O0
endif

# linker options : OS dependant
ifeq ($(shell sh -c 'uname -s'),Linux)
	LIBFLAGS=-L. -ltcod_debug -ltcodxx_debug -Wl,-rpath=.
else
	LIBFLAGS=-L. -ltcod -ltcodxx -Wall
endif

debug : $(APP)
release : $(APP)

$(APP): $(OBJS)
	g++ -g $(OBJS) -o $(APP) -Wall $(LIBFLAGS) $(CFLAGS)

src/%.o: src/%.cpp
	g++ -g $< -c -o $@ -Iinclude -Wall $(CFLAGS)

clean:
	rm -f $(APP) $(OBJS)

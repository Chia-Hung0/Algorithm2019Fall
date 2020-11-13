# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O3

all	: cb
	@echo -n ""

# optimized version
cb	: cycle_breaking_opt.o
			$(CC) $(OPTFLAGS) cycle_breaking_opt.o -o cb
cycle_breaking_opt.o 	   	: src/cycle_breaking.cpp
			$(CC) $(CFLAGS) $< -o $@
#sort_tool_opt.o	: src/sort_tool.cpp src/sort_tool.h
#			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@

# DEBUG Version
dbg : cb_dbg
	@echo -n ""

cb_dbg	: cycle_breaking_dbg.o
			$(CC) $(DBGFLAGS) cycle_breaking_dbg.o -o cb_dbg
cycle_breaking_dbg.o 	   	: src/cycle_breaking.cpp
			$(CC) $(CFLAGS) $< -o $@
#sort_tool_dbg.o	: src/sort_tool.cpp src/sort_tool.h
#			$(CC) $(CFLAGS) $(DBGFLAGS) $< -o $@


# clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*


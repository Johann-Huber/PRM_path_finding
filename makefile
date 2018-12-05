CC = g++
CFLAGS = -g -Wall
SRCS = main.cpp Map.cpp MapTree.cpp
PROG = path_finding

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
	
	
clean :
	rm -f $(PROG) *.o

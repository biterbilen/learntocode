# 
CC  = gcc #c99
CXX = g++
OBJC = clang
# CXXFLAGS = -std=c++11 -fpermissive

all: TAGS a.out

a.out: a.o
	$(CXX) $^ $(LDFLAGS) -o $@
%.o: %.cpp
	$(CXX)  -c $(CXXFLAGS) -o $@ $< -MMD
%.o: %.c
	$(CC)  -c $(CFLAGS) -o $@ $< 
%.o: %.m
	$(OBJC)  -c $(CFLAGS) -o $@ $< 

TAGS:
	-@gtags
clean:
	-rm -f *.o
	-rm -f core GPATH GRTAGS GSYMS GTAGS
	-rm -f a.out

-include $(wildcard *.d)

CXX := g++ -std=c++11
MAKE ?= make

CFLAGS := 

LDFLAGS := -fopenmp

LIBS := 

BUILT_LIBS :=

OBJS := *.o 

all:
	$(MAKE) app

app :
	$(CXX) $(CFLAGS) -c main.cpp $(LDFLAGS)
	$(CXX) $(OBJS) $(LIBS) $(BUILT_LIBS) -o run $(LDFLAGS)

clean:
	rm -f *.a
	rm -f *.o
	rm -f run

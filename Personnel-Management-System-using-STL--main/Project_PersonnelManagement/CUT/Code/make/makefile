OBJS = main.o
O = -lpthread
HEAD = personnel.hpp
CL = *.o
GC = g++ -c
GO = g++ -o
T = test

test: $(OBJS)  $(HEAD)
	$(GO) test $(OBJS) $(O)

main.o: main.cpp
	$(GC) main.cpp $(O)

cl:
	rm $(CL)
	rm $(T)


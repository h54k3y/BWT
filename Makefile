.PHONY: all
all: a.out 

a.out: main.o naive.o BWT.o
	g++ -o $@ $^

main.o: main.cpp naive.cpp BWT.cpp
	g++ -c -o $@ $<

.PHONY: clean
clean:
	$(RM) main.o naive.o BWT.o a.out 

naive.o: naive.hpp
main.o: naive.hpp
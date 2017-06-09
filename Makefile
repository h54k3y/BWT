.PHONY: all
all: a.out 

a.out: naive_main.o naive.o
	g++ -o $@ $^

sa.o: naive.cpp
	g++ -c -o $@ $<

main.o: naive.cpp
	g++ -c -o $@ $<

.PHONY: clean
clean:
	$(RM) naive_main.o naive.o a.out 

naive.o: naive.hpp
naive_main.o: naive.hpp
prog: main.o vybor.o
	g++ -o prog main.o vybor.o
main.o: main.cpp
	g++ -g -c main.cpp
vybor.o: vybor.cpp
	g++ -g -c vybor.cpp
clean:
	rm -rf prog *.o


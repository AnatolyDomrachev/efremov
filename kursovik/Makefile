prog: main.o vybor.o reshenie.o sohr_vost.o vvod.o vyvod.o
	g++ -o prog main.o vybor.o reshenie.o sohr_vost.o vvod.o vyvod.o
main.o: main.cpp
	g++ -g -c main.cpp
vybor.o: vybor.cpp
	g++ -g -c vybor.cpp
reshenie.o: reshenie.cpp
	g++ -g -c reshenie.cpp
sohr_vost.o: sohr_vost.cpp
	g++ -g -c sohr_vost.cpp
vvod.o: vvod.cpp
	g++ -g -c vvod.cpp
vyvod.o: vyvod.cpp
	g++ -g -c vyvod.cpp
clean:
	rm -rf prog *.o

# compila todos los archivos de la lista enlazada
all: solitario
solitario: main.o Carta.o
	g++ main.o -o Solitario
	./Solitario
main.o: main.cpp
	g++ -c main.cpp
Carta.o: Carta.cpp
	g++ -c Carta.cpp
clean:
	rm -rf *o Solitario
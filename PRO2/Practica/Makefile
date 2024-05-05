OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Bicicleta.o Estacion.o Bicicletas.o Estaciones.o
	g++ -o program.exe *.o 

Estacion.o: Estacion.cc 
	g++ -c Estacion.cc $(OPCIONS) 
	
Bicicleta.o: Bicicleta.cc 
	g++ -c Bicicleta.cc $(OPCIONS) 

Bicicletas.o: Bicicletas.cc 
	g++ -c Bicicletas.cc $(OPCIONS) 

Estaciones.o: Estaciones.cc
	g++ -c  Estaciones.cc $(OPCIONS) 

program.o: program.cc
	g++ -c program.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe

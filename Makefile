all: petfera

funcionario.o: funcionario.cpp
				g++ -std=c++0x -c -Wall funcionario.cpp

veterinario.o: veterinario.cpp funcionario.cpp
				g++ -std=c++0x -c -Wall veterinario.cpp

tratador.o: tratador.cpp funcionario.cpp
				g++ -std=c++0x -c -Wall tratador.cpp

animal.o: animal.cpp veterinario.cpp tratador.cpp
				g++ -std=c++0x -c -Wall animal.cpp

administrador.o: administrador.cpp animal.cpp veterinario.cpp tratador.cpp
				g++ -std=c++0x -c -Wall administrador.cpp

main.o: main.cpp administrador.cpp
				g++ -std=c++0x -c -Wall main.cpp
	
petfera: main.o administrador.o animal.o funcionario.o tratador.o veterinario.o
				g++ -std=c++0x -o petfera main.o administrador.o funcionario.o

clean:
		rm -rf *.o
		rm petfera
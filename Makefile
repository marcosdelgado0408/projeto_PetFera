all: petfera

main.o: main.cpp administrador.h
		g++ main.cpp -c

administrador.o: administrador.cpp administrador.h exoticos.h veterinario.h tratador.h
					g++ administrador.cpp -c

animal.o: animal.cpp animal.h veterinario.h tratador.h
			g++ animal.cpp -c

funcionario.o: funcionario.h
				g++ funcionario.cpp -c

tratador.o: tratador.h funcionario.h
				g++ tratador.cpp -c

veterinario.o: veterinario.h funcionario.h
				g++ veterinario.cpp -c

petfera: main.o administrador.o animal.o funcionario.o tratador.o veterinario.o
			g++ main.o administrador.o animal.o funcionario.o tratador.o veterinario.o -o petfera

clean:
		rm -rf *.o
		rm petfera
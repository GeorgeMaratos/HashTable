#Written by George Maratos
make: main.c
	gcc main.c hFunctions.c -o debugging 

clean: debugging 
	rm debugging

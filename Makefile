make: main.c
	gcc main.c hFunctions.c -o debugging 

clean: main
	rm debugging

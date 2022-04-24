all: summer_camp.all

summer_camp.all: readline.o request.o summer_camp.o
	gcc readline.o request.o summer_camp.o -o summer_camp

readline.o: readline.c
	gcc -c readline.c -o readline.o

request.o: request.c
	gcc -c request.c  -o request.o

summer_camp.o: summer_camp.c
	gcc -c summer_camp.c  -o summer_camp.o

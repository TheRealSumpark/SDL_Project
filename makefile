prog:options.o main.o
	gcc options.o main.o -o prog -g
main.o:main.c
	gcc -c main.c -g 
options.o:options.c
	gcc -c options.c -g

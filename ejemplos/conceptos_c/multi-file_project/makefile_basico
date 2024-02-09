app.out: main.o helper1.o helper2.o
	gcc -o app.out main.o helper1.o helper2.o -lm

main.o: main.c
	gcc -O -Wall -c main.c

helper1.o: helper1.c
	gcc -O -Wall -c helper1.c

helper2.o: helper2.c
	gcc -O -Wall -c helper2.c

clean:
	rm -f main.c helper1.o helper1.o app.out
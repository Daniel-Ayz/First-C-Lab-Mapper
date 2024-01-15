all: count-words addresses

count-words: count-words.o
	gcc -g -m32 -Wall -o count-words count-words.o

count-words.o: count-words.c
	gcc -g -m32 -Wall -c -o count-words.o count-words.c

addresses: addresses.o
	gcc -g -m32 -Wall -o addresses addresses.o

addresses.o: addresses.c
	gcc -g -m32 -Wall -c -o addresses.o addresses.c

base: base.o
	gcc -g -m32 -Wall -o base base.o

base.o: base.c
	gcc -g -m32 -Wall -c -o base.o base.c

menu_map: menu_map.o
	gcc -g -m32 -Wall -o menu_map menu_map.o

menu_map.o: menu_map.c
	gcc -g -m32 -Wall -c -o menu_map.o menu_map.c

.PHONY: clean

clean:
	rm -f *.o count-words addresses base menu_map

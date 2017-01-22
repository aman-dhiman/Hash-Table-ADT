main:
	gcc -g src/linkedList.c src/main.c src/menu.c -Wall -ansi -pedantic -Iinclude -o bin/run
list test:
	gcc src/linkedList.c src/test.c -Wall -ansi -pedantic -Iinclude -o bin/test

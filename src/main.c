#include "linkedListH.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]){
    node * newNode = createList();
    char option;
    char filename[100];
    long pNum;

    readParse (argc, argv[1], newNode);
    printScreen();
    while ((option = getchar()) != 'q') {
        if (option == '1') {
            printf ("Please enter the location of the file:\n");
            scanf ("%s", filename);
            readParse (2, filename, newNode);
        }
        else if (option == '2') {
            addEntry (newNode);
        }
        else if (option == '3') {
            printf ("Please enter the phone number for which you"
                    " need the data for:\n");
            scanf ("%ld", &pNum);
            lookup (newNode, pNum);
        }
        else if (option == '4') {
            printList (newNode);
        }
        else
        {
            printf ("Invalid input. Please try again. Press Enter to"
                    " continue\n");
            getchar();
        }
        getchar();
        printf("\033[2J");
        printScreen();
    }

    destroyList (newNode);
    return 0;
}


#include "linkedListH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    node * newNode = createList();
    node * temp;
    addLast (newNode, 34456353654, "Glebe", "Davidson");
    addFront (newNode, 57452352352, "Jack", "Sparrow");
    addMid (newNode, 3954536363, "Lets", "Go", 3);
    addSorted (newNode, 4637426457, "Noddy", "Maan");
    addSorted (newNode, 9842928523, "Pluto", "Ryerson");
    printList (newNode);
    printf ("\n");
    temp = removeFront (newNode);
    printList (newNode);
    printf ("\n");
    temp = getFirst (newNode);
    printf ("Num: %ld, Name: %s %s\n", temp->pNumber, temp->fName, temp->lName);
    destroyList (newNode);
    return 0;
}

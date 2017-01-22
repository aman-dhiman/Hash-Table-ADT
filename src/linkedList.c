#include "linkedListH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node * createList () {
    node * head = initNode (0, "NA", "NA");
    return head;
}

void addFront (node * head, long pNum, char * firstN, char * lastN) {
    node * newNode = initNode (pNum, firstN, lastN);
    newNode->next = head->next;
    head->next = newNode;
    head->pNumber++;
}

void addLast (node * head, long pNum, char * firstN, char * lastN) {
    node * newNode = initNode (pNum, firstN, lastN);
    node * temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    head->pNumber++;
}

void addMid (node * head, long pNum, char * firstN, char * lastN, int index) {
    node * newNode = initNode (pNum, firstN, lastN);
    node * temp = head;
    int i = 0;
    while (i < index-1) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    head->pNumber++;
}

void addSorted (node * head, long pNum, char * firstN, char * lastN) {
    int index = 1;
    node * temp = head;
    if (head->next != NULL) {
        temp = head->next;
    }
    while ((temp->next != NULL)&&
           ((strcmp (firstN, temp->fName) > 0)||
           ((strcmp (firstN, temp->fName) == 0)&&
            (strcmp (lastN, temp->lName) > 0)))) {
        temp = temp->next;
        index++;
    }
    if ((head->next != NULL)&&(temp->next == NULL)&&
           ((strcmp (firstN, temp->fName) > 0)||
           ((strcmp (firstN, temp->fName) == 0)&&
            (strcmp (lastN, temp->lName) > 0)))) {
        index++;
    }

    if (index == 1) {
        addFront (head, pNum, firstN, lastN);
    }
    else if (index > head->pNumber) {
        addLast (head, pNum, firstN, lastN);
    }
    else {
        addMid (head, pNum, firstN, lastN, index);
    }
}

node * removeFront (node * head) {
    node * temp = head->next;
    head->next = temp->next;
    temp->next = NULL;
    head->pNumber--;
    return temp;
}

node * getFirst (node * head) {
    return head->next;
}

long getLength (node * head) {
    return head->pNumber;
}

void printList (node * head) {
    node * current = head->next;
    printf("\033[2J");
    while (current != NULL) {
        printf ("%s %s: %ld\n", current->fName, current->lName, current->pNumber);
        current = current->next;
    }
    printf ("\nPress Enter to go to the main menu\n");
    getchar();
}

node * initNode (long pNum, char * firstN, char * lastN) {
    node * newNode = malloc (sizeof (node));
    newNode->pNumber = pNum;
    newNode->fName = malloc (sizeof (char) * 50);
    newNode->lName = malloc (sizeof (char) * 50);
    strcpy (newNode->fName, firstN);
    strcpy (newNode->lName, lastN);
    newNode->next = NULL;
    newNode->side = NULL;
    return (newNode);
}

void destroyList (node * head) {
    if (head == NULL) {
        return;
    }
    else
    {
        destroyList (head->next);
    }
    free (head->fName);
    head->fName = NULL;
    free (head->lName);
    head->lName = NULL;
    head->next = NULL;
    head->side = NULL;
    free (head);
    head = NULL;
}



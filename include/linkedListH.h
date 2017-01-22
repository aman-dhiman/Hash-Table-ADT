struct listNode {
    long pNumber;
    char * fName;
    char * lName;
    struct listNode * next;
    struct listNode * side;
};

typedef struct listNode node;

node * createList();
void addFront (node * head, long pNum, char * firstN, char * lastN);
void addLast (node * head, long pNum, char * firstN, char * lastN);
void addMid (node * head, long pNum, char * firstN, char * lastN, int index);
void addSorted (node * head, long pNum, char * firstN, char * lastN);
node * removeFront (node * head);
node * getFirst (node * head);
long getLength (node * head);
void printList (node * head);
node * initNode (long pNum, char * firstN, char * lastN);
void destroyList (node * head);


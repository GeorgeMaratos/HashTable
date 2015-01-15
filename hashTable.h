//This is the headerfile for the hash project
#define DEBUG 1

typedef struct node
{
  int val;
  struct node *next;
}Node;

typedef struct head
{
  int size, capacity;
  struct node **list;
}Head;

//functions from hFunctions.c
Head *makeTable();
int hashFunction(int val, int (*f)(int));
void insertValue(int index, int value, Head *hd);
void addValue(int value, int (*f)(int), Head *hd);
void printTable(Head *hd);
void interface(int (*f)(int), Head *table);

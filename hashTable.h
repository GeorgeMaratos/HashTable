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

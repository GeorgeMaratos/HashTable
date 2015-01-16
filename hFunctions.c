//this is the hash table project
#include<stdlib.h>
#include<stdio.h>
#include"hashTable.h"

//memory allocation
Head*
makeTable(int sz)
{
  //variables
  int i;
  Head *table;
  //ops
  table = malloc(sizeof(Head));
  table->size = 0;
  table->capacity = sz;
  if(DEBUG) printf("Hash Table Allocated Size: %d\n", table->capacity);
  table->list = malloc(sizeof(Node*) * sz);
  for(i=0;i<sz;i++)
    table->list[i] = NULL;
  //return
  return table;
}

Node *
makeNode(int value)
{
  //variables
  Node *nd;
  //ops
  nd = malloc(sizeof(Node));
  nd->val = value;
  nd->next = NULL;
}

//hash function
int
hashFunction(int val,int (*f)(int))
{
  //variables
  int ret;
  //ops
  ret = f(val);
  //return
  return ret;
}

//hash table ops

//Insert Function for chaining
void
insertCValue(int index, int value, Head *hd)
{
  //variables
  Node *ptr, *nd;
  //ops
  if(hd->list[index] == NULL)
  {
    if(DEBUG) printf("Inserting [%d] into [%d]\n", value , index);
    nd = makeNode(value);
    hd->list[index] = nd;
    hd->size++;
    return;
  }
  else
  {
    if(DEBUG) printf("Collision detected at [%d] Insert into end of list\n", index);
    ptr = hd->list[index];
    while(ptr->next != NULL)
      ptr = ptr->next;
    nd = makeNode(value);
    ptr->next = nd;
    hd->size++;
    return;
  }
}
//Insert Function for open addressing
void
insertValue(int index, int value, Head *hd)
{
  //variables
  Node *nd;
  //ops
  if(index == hd->capacity) 
  {
   if(DEBUG) printf("No space for [%d]\n", value);
   return;
  }
  if(hd->list[index] != NULL)
  {
    if(DEBUG) printf("index [%d] full\n", index);
    insertValue(index + 1, value, hd);
  }
  else
  {
    if(DEBUG) printf("Inserting value [%d] at index [%d]\n", value, index); 
    nd = makeNode(value);
    hd->list[index] = nd;
  }
}
//wrapper function for recursive open addressing insertion function
void 
addValue(int value, int (*f)(int), Head *hd)
{
  //variables
  int index;
  //ops
  index = hashFunction(value,f) % hd->capacity;
  if(DEBUG) printf("value [%d] hash [%d]\n",value, index);
//  insertValue(index, value, hd);
  insertCValue(index, value, hd);
}
//debugging functions
void
printTable(Head *hd)
{
  //variables
  int i;
  Node *ptr;
  //ops
  if(hd == NULL) return;
  if(hd->list == NULL) return;
  if(DEBUG)
  { 
    printf("Printing Table\n");
    printf("Capacity: %d\n", hd->capacity);
  }
  for(i=0;i<10;i++)
  {
    if(hd->list[i] != NULL)
    {
      printf("%d: ", i);
      ptr = hd->list[i];
      do
      {
        printf("[%d] ->", hd->list[i]->val);
        ptr = ptr->next;
      }
      while(ptr != NULL);
      printf("\n");
    }
  } 
}
void
interface(int (*f)(int), Head *table)
{
  //variables
  int input;
  //ops
  printf("Hash Table Debugging\n");
  for(;;)
  {
    printf("Enter Value: ");
    scanf("%d", &input);
    switch(input)
    {
      case 0: return;
      default:
	addValue(input, f, table);
	break;
    }
  }
}

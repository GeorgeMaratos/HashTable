//this is the hash table project
#include<stdlib.h>
#include<stdio.h>
#include"hashTable.h"

//memory allocation
Head*
makeTable()
{
  //variables
  int i;
  Head *table;
  //ops
  table = malloc(sizeof(Head));
  table->size = 0;
  table->capacity = 10;
  if(DEBUG) printf("Hash Table Allocated Size: %d\n", table->capacity);
  table->list = malloc(sizeof(Node*) * 10);
  for(i=0;i<10;i++)
    table->list[i] = NULL;
  //return
  return table;
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
    nd = malloc(sizeof(Node));
    nd->val  = value;
    nd->next = NULL;
    hd->list[index] = nd;
  }
}

void 
addValue(int value, int (*f)(int), Head *hd)
{
  //variables
  int index;
  //ops
  index = hashFunction(value,f) % hd->capacity;
  if(DEBUG) printf("value [%d] hash [%d]\n",value, index);
  insertValue(index, value, hd);
}
//debugging functions
void
printTable(Head *hd)
{
  //variables
  int i;
  //ops
  if(hd == NULL) return;
  if(hd->list == NULL) return;
  if(DEBUG)
  { 
    printf("Printing Table\n");
    printf("Capacity: %d\n", hd->capacity);
  }
  for(i=0;i<hd->capacity;i++)
  {
    if(hd->list[i] != NULL)
      printf("%d\n", i);
  }
}
void
interface(int (*f)(int), Head *table)
{
  //variables
  int input;
  //ops
  printf("Hash Table Debugging\n");
  table = makeTable();
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

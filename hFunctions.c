//this is the hash table project
#include<stdlib.h>
#include<stdio.h>
#include"hashTable.h"

//memory allocation
Head*
makeTable()
{
  //variables
  Head *table;
  //ops
  table = malloc(sizeof(Head));
  table->size = 0;
  table->capacity = 10;
  table->list = malloc(sizeof(Node*) * 10);
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
  if(index == hd->capacity) return;
  if(hd->list[index] != NULL) insertValue(index + 1, value, hd);
  else
  {
    nd = malloc(sizeof(Node));
    nd->val  = value;
    nd->next = NULL;
    hd->list[index] = nd;
  }
}

//debugging function
void
printTable(Head *hd)
{
  //variables
  int i;
  //ops
  if(hd == NULL) return;
  if(hd->list == NULL) return;
  for(i=0;i<capacity;i++)
  {
    if(hd->list[i] != NULL)
      printf("%d : %d\n", i, hd->list[i]->val);
  }
}

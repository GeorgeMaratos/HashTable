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

//hash table operations
void
insertVal(int value, Head *hd)
{
  //variables
  Node *nd;
  //ops
  nd = malloc(sizeof(Node));
  nd->val = value;
  nd->next = NULL;
  hd->list[hd->size++] = nd;
}


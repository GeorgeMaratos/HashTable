#include<stdlib.h>
#include<stdio.h>
#include"hashTable.h"
int hasher(int value)
{
  //variables
  int ret;
  //ops
  ret = value;
}

void main()
{
  //variables
  Head *table;
  //ops
  table = makeTable();
  interface(hasher,table);
  if(DEBUG) printTable(table); 	
}

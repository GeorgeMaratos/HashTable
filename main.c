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
  int input;
  Head *table;
  //ops
  printf("Hash Table Debugging\n");
  table = makeTable();
  for(;;)
  {
    printf("Enter Value: ");
    scanf("%d", &input);
    switch(input)
    {
      case 0: continue;
      default:
	addValue(input, hasher, table);
	break;
    }
  }
  if(DEBUG) printTable(table); 	
}

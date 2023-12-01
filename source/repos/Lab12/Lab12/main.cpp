//
//  main.cpp
//  Lab9
//
//  Created by Computer Science on 2/1/16.
//  Copyright (c) 2016 Computer Science. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using std::string;

int main(int argc, const char * argv[])
{
  LinkedList<string> list1;

  for (int i = 0; i < 10; i++)
  {
	  list1.InsertAtHead("fuck");
  }
  list1.Print();
  while(!list1.isEmpty())
  {
	  list1.RemoveHead();
  }
  list1.Print();

  //placed in scope to test destructor
  {
	  LinkedList<uint64_t> list2;
	  for (int i = 0; i < 10; i++)
	  {
		  list2.InsertAtHead(i);
	  }
	  list2.Print();
	  /*while (!list2.isEmpty())
	  {
		  list2.RemoveHead();
	  }*/
	  list2.Print();
  }//destructor deletes list2

  return 0;
}

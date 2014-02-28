#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
		string str;
		Node* ptrNext;
} *NodePtr;

void deleteList(NodePtr& m_Head);	
void Print(NodePtr m_Head);
bool Insert(NodePtr& m_Head, string str);

//ToDo:  implement this function to return the number of node from the head station
// return -1 when cannot find the distance between str and the head
int Access(NodePtr m_Head, string str);
int AccessIgnoreCase(NodePtr m_Head, string str);
string stringToLower(string str);


#endif

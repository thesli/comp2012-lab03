#include "List.h"

void deleteList(NodePtr& m_Head)
{
	NodePtr ptrTemp;
	while (m_Head != NULL)
	{
		ptrTemp = m_Head;
		m_Head = m_Head->ptrNext;
		delete ptrTemp;
	}
}


void Print(NodePtr m_Head)
{
	NodePtr ptrTemp = m_Head;
	while(ptrTemp != NULL)
	{
		cout << ptrTemp->str << "->";
		ptrTemp = ptrTemp->ptrNext;
	}
    cout << "NIL" << endl;
}

int Access(NodePtr m_Head, string str)
{
	if (m_Head == NULL)		// empty list
		return -1;
	else {
		if (m_Head->str == str) {
			return 0;
		}
		else {
			int count = 0;
			NodePtr temp = m_Head;
            while(temp->ptrNext!=NULL){
            	if(temp->str == str){
            		return count;
            	}else{
            		count++;
            		temp = temp->ptrNext;
            	}
            }
            if(temp->str == str){
            	return count;
            }
		}
		return -1;
	}
}

int AccessIgnoreCase(NodePtr m_Head, string str)
{
	str = stringToLower(str);
	if (m_Head == NULL)		// empty list
		return -1;
	else {
		if (stringToLower(m_Head->str) == str) {
			return 0;
		}
		else {
			int count = 0;
			NodePtr temp = m_Head;
            while(temp->ptrNext!=NULL){
            	if(stringToLower(temp->str) == str){
            		return count;
            	}else{
            		count++;
            		temp = temp->ptrNext;
            	}
            }
            if(stringToLower(temp->str) == str){
            	return count;
            }
		}
		return -1;
	}
}

string stringToLower(string str){		
	for (int i = 0; str[i] != '\0'; i++)
	{	
		str[i] = (char)tolower(str[i]);
	}	
	return str;
}

bool Insert(NodePtr& m_Head, string str)
{
	if (str == "q") {
		cerr << "invalid string\n";
		return false;
	}

	if (m_Head == NULL) {	// empty list
		m_Head = new Node;
		m_Head->str = str;
		m_Head->ptrNext = NULL;
	}
	else {
		//Create new node
		NodePtr ptrNew = new Node;
		ptrNew->str = str;
		ptrNew->ptrNext = NULL;

		NodePtr ptrTemp = m_Head;
		while (ptrTemp->ptrNext != NULL)
		{
			if (ptrTemp->str == str)	// discard duplicated node
				return false;
			ptrTemp = ptrTemp->ptrNext;
		}
		if (ptrTemp->str == str)	// checking the last node
			return false;

		//Append to last
		ptrTemp->ptrNext = ptrNew;
	}
	return true;
}

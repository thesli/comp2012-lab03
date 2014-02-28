#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "List.h"
using namespace std;

#define STATION_FILE "station.txt"

NodePtr InitList() {
        NodePtr head=NULL;
	ifstream fin(STATION_FILE);
	if ( !fin ) {
		cerr << "error: unable to open input file " << STATION_FILE << "\n";
		exit (-1);
	}

    int intNum;
    fin >> intNum;	
    
	for(int i=0; i<intNum; i++)
	{
	    string temp;
        fin >> temp;
        if (!Insert (head, temp))
        {
            cout << "Some error in input file "  << STATION_FILE << "\n";
            exit(-1);
        }
	}
    return head;
}

int main()
{
	string strStation;
	int intCost;	
	NodePtr list=NULL;
	list=InitList();

    cout << "Input the name of station for the distance from the first station (in term of station)\n";
    cout << "Type q to exit \n\n";
	while (true) {
		intCost = -1;		

		Print(list);
		cout << "Station > ";

		cin >> strStation;
		
		//Exit
		if (strStation == "q" || strStation == "Q")
			break;
		intCost = AccessIgnoreCase(list,strStation);
		if (intCost != -1) {
			cout << intCost <<"\n\n";
        } else {
            cout << "No such station !\n\n";
        }
	}
        deleteList(list);
	return 0;
}

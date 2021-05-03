#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;


class contacts
{
protected:
	struct Node
	{
		string key;
		string name;
		string contact;
		string contact2;
		string address;
		Node* next;
	};

	Node* listheadptr;
	Node* hashtable[20];

public:
	
	string data[20][5];
	int index;

	contacts()
	{
		listheadptr = NULL;		
	}
	
	void addnode()
	{
		int addr;
		ifstream read;
		read.open("data.txt");

		Node* ptrNew = new Node;


		read >> ptrNew->key;
		read >> ptrNew->name;

		addr=hashfunction(ptrNew->name);

		read >> ptrNew->contact;
		read >> ptrNew->contact2;
		read >> ptrNew->address;

		ptrNew->next = NULL;

		Node* ptr = NULL;

		if (listheadptr == NULL)
		{
			listheadptr = ptrNew;
			return;
		}

		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = ptrNew;

		mapping(addr);

	}


	void storedata()
	{
		ifstream reader;
		reader.open("data.txt");

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (!reader.eof())
				{
					reader >> data[i][j];
				}
			}
		}
	}


	int hashfunction(string namee)
	{
		int sum = 0;
		int k;

		for (int x = 0; x < namee.length(); x++)
		{
			char n = namee.at(x);
			sum = sum + int(n);
		}

		k = sum % 20;

		return k;
	}



	void mapping(int ind)
	{
		hashtable[ind] = listheadptr;
	}

	void display(string Namee)
	{
		Node* ptrTemp = hashtable[hashfunction(Namee)];
		cout << endl;
		while (ptrTemp != NULL)
		{
			cout << ptrTemp->key << " ";
			cout << ptrTemp->name << " ";
			cout << ptrTemp->contact << " ";
			cout << ptrTemp->contact2 << " ";
			cout << ptrTemp->address << " ";
			ptrTemp = ptrTemp->next;
		}


	}

	
};

int main()
{
	int sum = 0;
	int index;
	int keyy;
	contacts caller;

	
	caller.addnode();
	caller.addnode();
	caller.addnode();

	caller.display("Ted");


}


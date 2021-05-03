//Muhammad Hasan Khan    2019328
//Muhammad Tashfeen      2019213


#include <iostream>
#include <time.h>
#include <string>
using namespace std;


class oneway                                                   //the code uses chaining method to solve collisions
{
	oneway* headptr;
	
	oneway *hashtable[10];
	int key;
	string address, name, phone2, phone;
	oneway* next;

public:

	oneway()                                                                             //Constructor
	{
		headptr = NULL;
	}




	void addnode(string num, string nam, string addr, string ph2)                       //creates the new node and stores the values
	{
		oneway* newptr;
		newptr = new oneway;

		newptr->key = keygen(nam);
		newptr->phone = num;
		newptr->name = nam;
		newptr->address = addr;
		newptr->phone2 = ph2;

		if (hashtable[newptr->key] != NULL)
		{
			oneway* temp;
			temp = hashtable[newptr->key];
			hashtable[newptr->key] = newptr;
			newptr->next = temp;
		}

		else
		{
			hashtable[newptr->key] = newptr;
			newptr->next = NULL;
		}

	}





	void deletenode(string namee)                      //node deleted through the name of person
	{

		int keyyy = keygen(namee);

		oneway* current = hashtable[keyyy];

		oneway* temp;

		
		if (current != NULL && current->name == namee)
		{
			temp = current;

			current = current->next;

			hashtable[keyyy] = current;

			delete temp;
			cout << "\nNode successfully deleted! \n";
			return;
		}

		else
		{
			while (current->next != NULL)
			{
				temp = current;
				current = current->next;

				if (current->name == namee)
				{
					temp->next = current->next;
					delete current;
					cout << "\nNode successfully deleted! \n";
					return;

				}
			}

		}

	}




	void search(string nam)                                //search with O(n). Loop starts the search from the address at hastable[key]
	{
		int keyyy = keygen(nam);                          //key generated through name

		oneway* current = hashtable[keyyy];

		oneway* temp;

		

		if (current != NULL && current->name == nam)
		{
			cout << "\nKey: "<< current->key<<"\nName: " << current->name << "\nPrimary-Contact: " << current->phone << "\nSecondary-Contact: " << current->phone2 << "\nAddress: " << current->address <<"\n";
			cout << endl;
			return;
		}

		else
		{
			while (current->next != NULL)
			{
				current = current->next;

				if (current->name == nam)
				{
					cout << "\nKey: " << current->key << "\nName: " << current->name << "\nPrimary-Contact: " << current->phone << "\nSecondary-Contact: " << current->phone2 << "\nAddress: " << current->address << "\n";
					cout << endl;
					return;

				}
			}
		}
	}




	void display()
	{


		for (int i = 0; i < 10; i++)
		{
			oneway* temp = hashtable[i];
			oneway* x = temp;

			while (temp != NULL )
			{
				cout << "\nKey: " << temp->key << "\nName: " << temp->name << "\nPrimary-Contact: " << temp->phone << "\nSecondary-Contact: " << temp->phone2 << "\nAddress: " << temp->address << "\n";
				cout << endl;
				temp = temp->next;
			}
		}
		

	}

	

	int keygen(string x)                                     //Keys generated(0-9) from names using radix notation  
	{
		int keyy=0;
		for (int i = 0; i < x.length(); i++)
		{
			if (i == 0)
			{
				keyy == keyy + (128 * int(x[i]));
			}
			else
			{
				keyy = keyy + int(x[i]);
			}
			
		}
		
		keyy = keyy % 10;
		return keyy;
	}
};


int main()
{
	oneway caller;
	int choice;


	do         //Menu derived code. 
	{
		cout << "--------------------------------------------\n";
		cout << "1) Display all contacts" << endl;
		cout << "2) Search" << endl;
		cout << "3) Add a contact" << endl;
		cout << "4) Delete a contact" << endl;
		cout << "5) Exit" << endl;
		cin >> choice;

		if (choice == 1)
		{
			system("CLS");
			caller.display();
			cout << endl;
		}

		if (choice == 2)
		{
			string keynum;
			system("CLS");

			cin.ignore();

			cout << "Enter the Name of the contact to be displayed: ";
			
			getline(cin, keynum);
			caller.search(keynum);
			cout << endl;
		}

		if (choice == 3)
		{
			system("CLS");
			string nameeee, contacttt1, contacttt2, addressss;
			cin.ignore();
			cout << "\nName: ";
			getline(cin,nameeee);


			cout << "\nContact1: ";
			getline(cin, contacttt1);


			cout << "\nContact2: ";
			getline(cin, contacttt2);

			cout << "\nAddress: ";
			getline(cin, addressss);

			system("CLS");

			caller.addnode(contacttt1, nameeee, addressss, contacttt2);
			cout << "Success!\n";
		}

		if (choice == 4)
		{
			cin.ignore();
			string keynum;
			system("CLS");
			cout << "Enter the Name of the Contact to be deleted: ";

			getline(cin, keynum);

			caller.deletenode(keynum);
			


			cout << endl;
		}

	} while (choice != 5);
}
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class oneway
{
	oneway* headptr;
	string phone;
	string address,name,email;
	oneway* next;

public:

	oneway()
	{
		headptr = NULL;
	}

	void addnode(string num, string nam, string addr, string mail)
	{
		oneway* newptr;
		newptr= new oneway;

		newptr->next = headptr;
		headptr = newptr;

		newptr->phone = num;
		newptr->name = nam;
		newptr->address = addr;
		newptr->email = mail;

	}

	void deletenode(string namee)
	{
		oneway* current =headptr;
		oneway* temp;

		if (current != NULL && current->name == namee)
		{
			headptr = current->next;
			delete current;
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

	void display()
	{
		oneway* tempp = headptr;

		while (tempp != NULL)
		{
			cout << tempp->name<<"\t"<< tempp->address<<"\t"<< tempp->phone<<"\t"<< tempp->email<<"\n";
			cout << endl;
			tempp = tempp->next;
		}

	}

	void insert(string naam, string newnum)
	{
		oneway* current = headptr;

		if (current != NULL && current->name == naam)
		{
			current->phone = newnum;
			return;
		}

		else
		{
			while (current->next != NULL)
			{
				current = current->next;

				if (current->name == naam)
				{
					current->phone = newnum;
					return;

				}
			}
		}
	}

	void search(string nam)
	{
		oneway* current = headptr;

		if (current != NULL && current->name == nam)
		{
			cout << "\nPhone of the person is: " << current->phone << endl;
			return;
		}

		else
		{
			while (current->next != NULL)
			{
				current = current->next;

				if (current->name == nam)
				{
					cout << "\nPhone of the person is: " << current->phone << endl;
					return;

				}
			}
		}
	}

};

class twoway
{
	twoway* headptr;
	string phone;
	string address, name, email;
	twoway* next,*previous;

public:

	twoway()
	{
		headptr = NULL;
	}

	void addnode(string num, string nam, string addr, string mail)
	{
		twoway* newptr;
		newptr = new twoway;
		twoway* temp;

		if (headptr == NULL)
		{
			newptr->next = headptr;
			newptr->previous = NULL;
			headptr = newptr;

			newptr->phone = num;
			newptr->name = nam;
			newptr->address = addr;
			newptr->email = mail;
		}

		else
		{
			newptr->next = headptr;
			temp = newptr->next;
			newptr->previous = NULL;

			temp->previous = newptr;
			headptr = newptr;

			newptr->phone = num;
			newptr->name = nam;
			newptr->address = addr;
			newptr->email = mail;
		}

	}

	void deletenode(string namee)
	{
		twoway* current = headptr;
		twoway* temp,*temp2;

		if (current != NULL && current->name == namee)
		{
			temp2 = current->next;
			headptr = current->next;
			if (temp2 != NULL)
			{
				temp2->previous = NULL;
				return;
			}
			
			delete current;
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
					temp2 = current->next;
					temp->next = current->next;

					if (temp2 != NULL)
					{
						temp2->previous = temp->next;
						return;
					}
					
					delete current;
					cout << "\nNode successfully deleted! \n";
					return;
				}

				
			}
		}

	}

	void displayyy()
	{
		twoway* tempp = headptr;

		while (tempp != NULL)
		{
			cout << tempp->name << "\t" << tempp->address << "\t" << tempp->phone << "\t" << tempp->email << "\n";
			cout << endl;
			tempp = tempp->next;
		}

	}

	void insert(string naam, string newnum)
	{
		twoway* current = headptr;

		if (current != NULL && current->name == naam)
		{
			current->phone = newnum;
			return;
		}

		else
		{
			while (current->next != NULL)
			{
				current = current->next;

				if (current->name == naam)
				{
					current->phone = newnum;
					return;

				}
			}
		}
	}

	void search(string nam)
	{
		twoway* current = headptr;

		if (current != NULL && current->name == nam)
		{
			cout << "\nPhone of the person is: " << current->phone << endl;
			return;
		}

		else
		{
			while (current->next != NULL)
			{
				current = current->next;

				if (current->name == nam)
				{
					cout << "\nPhone of the person is: " << current->phone << endl;
					return;

				}
			}
		}
	}

};

int main()
{
	twoway accesss;
	oneway access;
	int choice=0;
	int choice2 = 0;
	string nameee, addresss, phoneee, emaill;

	cout << "1) One Way" << endl << "2) Two Way" << endl << "3) Exit" << endl;
	cin >> choice2;
	system("CLS");
	do
	{
		

		if (choice2 == 1)
		{
			cout << "1) Add new contact" << endl << "2) Update number of a contact" << endl << "3) Delete a contact" << endl << "4) Display" << endl << "5) Exit" << endl;
			cin >> choice;

			switch (choice)
			{

			case 1:
			{
				
				system("CLS");

				
				cin.ignore();

				cout << "Name: ";
				getline(cin, nameee);

				cout << "\nAddress: ";
				getline(cin, addresss);

				cout << "\nEmail: ";
				getline(cin, emaill);

				cout << "\nPhone No: ";
				getline(cin, phoneee);

				cout << endl;

				auto start = high_resolution_clock::now();
				access.addnode(phoneee, nameee, addresss, emaill);

				cout << endl << "Contact Added Successfully!" << endl;

				auto stop = high_resolution_clock::now();

				auto duration = duration_cast<microseconds>(stop - start);

				cout<<"\nProcessing time of the function: "<<duration.count()<<" microseconds"<<endl << endl;
				break;

			}

			case 2:
			{
				system("CLS");

				
				cout << "Enter the name of the person: ";
				cin >> nameee;
				cout << "\nEnter the new Number: ";
				cin >> phoneee;

				auto start = high_resolution_clock::now();
				access.insert(nameee, phoneee);

				cout << "\nNumber Updated Successfully!\n\n";

				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<microseconds>(stop - start);

				cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;

				break;

			}

			case 3:
			{
				system("CLS");

				
				cout << "Enter contact name to be deleted: ";
				cin >> nameee;

				auto start = high_resolution_clock::now();
				access.deletenode(nameee);

				
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<microseconds>(stop - start);

				cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;
				break;

			}

			case 4:
			{
				system("CLS");
				int choooos;

				cout << "1) Display All" << "\n2) Specific Phone Number\n";
				cin >> choooos;

				if (choooos == 1)
				{
					system("CLS");
					cout << "Name  Address  Phone  Email\n";
					auto start = high_resolution_clock::now();
					access.display();

					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);

					cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;
					break;
				}

				else if (choooos == 2)
				{
					system("CLS");
					cout << endl << "Name of the person who's contact is to be displayed: ";
					cin >> nameee;
					cout << endl;
					cout << "Name  Address  Phone  Email\n";

					auto start = high_resolution_clock::now();
					access.search(nameee);

					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);

					cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;
					break;
				}
				

			}

			case 5:
			{
				exit(1);

			}

			}
		}

		else if (choice2 == 2)
		{
		cout << "1) Add new contact" << endl << "2) Update number of a contact" << endl << "3) Delete a contact" << endl << "4) Display" << endl << "5) Exit" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
		{
			system("CLS");
			cin.ignore();

			cout << "Name: ";
			getline(cin, nameee);

			cout << "\nAddress: ";
			getline(cin, addresss);

			cout << "\nEmail: ";
			getline(cin, emaill);

			cout << "\nPhone No: ";
			getline(cin, phoneee);

			cout << endl;

			auto start = high_resolution_clock::now();
			accesss.addnode(phoneee, nameee, addresss, emaill);
			cout << endl << "Contact Added Successfully!" << endl << endl;
			
			auto stop = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(stop - start);

			cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;
			break;

		}

		case 2:
		{
			system("CLS");
			cout << "Enter the name of the person: ";
			cin >> nameee;
			cout << "\nEnter the new Number: ";
			cin >> phoneee;

			auto start = high_resolution_clock::now();
			accesss.insert(nameee, phoneee);

			cout << "\nNumber Updated Successfully!\n\n";

			auto stop = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(stop - start);

			cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;
			break;

		}

		case 3:
		{
			system("CLS");

			cout << "Enter contact name to be deleted: ";
			cin >> nameee;

			auto start = high_resolution_clock::now();
			accesss.deletenode(nameee);

			auto stop = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(stop - start);

			cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;

			break;

		}

		case 4:
		{
			system("CLS");
			int choooos;

			cout << "1) Display All" << "\n2) Specific Phone Number\n";
			cin >> choooos;

			if (choooos == 1)
			{
				system("CLS");
				cout << "Name  Address  Phone  Email\n";

				auto start = high_resolution_clock::now();
				accesss.displayyy();

				auto stop = high_resolution_clock::now();

				auto duration = duration_cast<microseconds>(stop - start);

				cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;
				break;
			}

			else if (choooos == 2)
			{
				system("CLS");
				cout << endl << "Name of the person who's contact is to be displayed: ";
				cin >> nameee;
				cout << endl;
				cout << "Name  Address  Phone  Email\n";

				auto start = high_resolution_clock::now();
				accesss.search(nameee);

				auto stop = high_resolution_clock::now();

				auto duration = duration_cast<microseconds>(stop - start);

				cout << "\nProcessing time of the function: " << duration.count() << " microseconds" << endl << endl;
				break;
				
			}
			

		}

		case 5:
		{
			exit(1);
		}

		}
		}



	} while (choice != 5);



}
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;


class AddressBook
{
private:
	string dataa[150][13];

public:

	AddressBook()
	{

	}


	void adddata(string key,string fname,string lname, string saddress, string city, string prov, string zipcode,string gender, string day, string memb,string phone, string month, string year )
	{
		int index;
		for (int i = 0; i < 150; i++)
		{
			if (dataa[i][0] == "")
			{
				index = i;
				break;
			}
		}

		dataa[index][0] = key;
		dataa[index][1] = fname;
		dataa[index][2] = lname;
		dataa[index][3] = saddress;
		dataa[index][4] = city;
		dataa[index][5] = prov;
		dataa[index][6] = zipcode;
		dataa[index][7] = gender;
		dataa[index][8] = day;
		dataa[index][9] = memb;
		dataa[index][10] = phone;
		dataa[index][11] = month;
		dataa[index][12] = year;
		
	}

	void store()
	{
		ofstream write;
		int index;

		write.open("xyz.txt", ios::trunc);

		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				write << dataa[i][j]<<" ";
			}
		}
	}

	void read()
	{
		ifstream read;

		read.open("xyz.txt");

		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				
				read >> dataa[i][j];
				
			}
		}
	}

	void display()
	{
		

		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				if (dataa[i][j] != " ")
				{
					cout << dataa[i][j] << " ";
				}
				
			}
			cout << endl;
		}
	}

	void lastname(string last)
	{
		for (int i = 0; i < 150; i++)
		{
			if (last == dataa[i][2])
			{
				cout << "Key: " << dataa[i][0] << endl;
				cout << "First Name: " << dataa[i][1] << endl;
				cout << "Last Name: " << dataa[i][2] << endl;
				cout << "Street Address: " << dataa[i][3] << endl;
				cout << "City: " << dataa[i][4] << endl;
				cout << "Province: " << dataa[i][5] << endl;
				cout << "Zip Code: " << dataa[i][6] << endl;
				cout << "Gender: " << dataa[i][7] << endl;
				cout << "DOB: " << dataa[i][8]<<"-"<<dataa[i][11]<<"-"<<dataa[i][12] << endl;
				cout << "Closeness: " << dataa[i][9] << endl;
				cout << "Phone Number: " << dataa[i][10] << endl;
			}
		}
	}

	void displayspecifics(string keyy)
	{
		for (int i = 0; i < 150; i++)
		{
			if (keyy == dataa[i][0])
			{
				cout << "Gender: " << dataa[i][7] << endl;
				cout << "Street Address: " << dataa[i][3] << endl;
				cout << "City: " << dataa[i][4] << endl;
				cout << "Province: " << dataa[i][5] << endl;
				cout << "Zip Code: " << dataa[i][6] << endl;
				cout << "Phone Number: " << dataa[i][10] << endl;
				cout << "DOB: " << dataa[i][8] << "-" << dataa[i][11] << "-" << dataa[i][12] << endl;
			}
		}
	}

	void birthdays()
	{
		string keys[150];

		string month; 
		string lmonth;

		cout << "Enter the month:";
		cin >> lmonth;

		system("CLS");


		cout << "Names of people having birthdays in this month: " << endl;
		for (int i = 0; i < 150; i++)
		{
			if (lmonth == dataa[i][11])
			{
				cout << dataa[i][0] << " " << dataa[i][1] << endl;
			}
		}
	}
	void membss()
	{
		int choice = 0;
		cout << "Enter the people you want to display in terms of closeness: " << endl;
		cout << "1) Family\n 2) Friends\n 3)Business Associate\n";

		cin >> choice;
		system("CLS");

		if (choice == 1) 
		{
			cout << "All your Family Members are:\n";
			for (int i = 0; i < 150; i++)
			{
				if (dataa[i][9] == "Family" || dataa[i][9] == "family")
				{
					cout << dataa[i][0] << " " << dataa[i][1] << endl;
				}
			}
		}

		if (choice ==2)
		{
			cout << "All your Friends are:\n";
			for (int i = 0; i < 150; i++)
			{
				if (dataa[i][9] == "Friend" || dataa[i][9] == "friend")
				{
					cout << dataa[i][0] << " " << dataa[i][1] << endl;
				}
			}
		}

		if (choice ==3)
		{
			cout << "All your Associates are:\n";
			for (int i = 0; i < 150; i++)
			{
				if (dataa[i][9] == "Associate" || dataa[i][9] == "associate")
				{
					cout << dataa[i][0] << " " << dataa[i][1] << endl;
				}
			}
		}
	}

	void samegender()
	{
		int choice = 0;

		cout << "Enter the people you want to display in terms of Gender: " << endl;
		cout << "1) Male\n 2) Female\n";

		cin >> choice;
		system("CLS");

		if (choice ==1)
		{
			cout << "All your Male contacts are:\n";
			for (int i = 0; i < 150; i++)
			{
				if (dataa[i][7] == "Male" || dataa[i][7] == "male")
				{
					cout << dataa[i][0] << " " << dataa[i][1] << endl;
				}
			}
		}

		if (choice == 2)
		{
			cout << "All your Friends are:\n";
			for (int i = 0; i < 150; i++)
			{
				if (dataa[i][7] == "Friend" || dataa[i][7] == "friend")
				{
					cout << dataa[i][0] << " " << dataa[i][1] << endl;
				}
			}
		}
	}


	/*void lastname()
	{
		string last1, last2;
		string names[150];
		char sortedinit[150];

		int start;
		int end;

		cout << "Enter the last name of the starting person: ";
		cin >> last1;
		cout << "\nEnter the last name of the ending person: ";
		cin >> last2;

		for (int i = 0; i < 150; i++)
		{
			if (last1 == dataa[i][1])
			{
				start = i;
			}

			if (last2 == dataa[i][1])
			{
				end = i;
			}
		}

		for (int i = start; i < end; i++)
		{
			names[i] = dataa[i][1];
			int n = dataa[i][1].length() + 1;
			char* initials  = new char[n];
			strcpy(initials, dataa[i][1].c_str());

			sortedinit[i] = initials[0];
		}



		for (int i = start; i < end - 1; i++)
		{
			for (int j = start; j < end - i - 1; j++)
			{
				if (sortedinit[j] > sortedinit[j + 1])
				{
					int temp = sortedinit[j];
					sortedinit[j] = sortedinit[j + 1];
					sortedinit[j + 1] = temp;
				}
			}
		}

		system("CLS");
		cout << "Names between these alphabetically arranged are: ";
		for (int i = start; i < end; i++)
		{
			names[i] = dataa[i][1];
			int n = dataa[i][1].length() + 1;
			char* initials = new char[n];
			strcpy(initials, dataa[i][1].c_str());

			if (sortedinit[i] == initials[0])
			{
				cout << endl << names[i];
			}
		}
		cout << endl;

		
	}*/

	void deletecont(string n)
	{
		for (int i = 0; i < 150; i++)
		{
			if (n == dataa[i][0])
			{
				dataa[i][0] = "";
				dataa[i][1] = "";
				dataa[i][2] = "";
				dataa[i][3] = "";
				dataa[i][4] = "";
				dataa[i][5] = "";
				dataa[i][6] = "";
				dataa[i][7] = "";
				dataa[i][8] = "";
				dataa[i][9] = "";
				dataa[i][10] = "";
				dataa[i][11] = "";
				dataa[i][12] = "";
			}
		}
	}

	void update(string n, string fname, string lname, string saddress, string city, string prov, string zipcode, string gender, string day, string memb, string phone, string month, string year)
	{
		for (int i = 0; i < 150; i++)
		{
			if (n == dataa[i][0])
			{
				dataa[i][0] = n;
				dataa[i][1] = fname;
				dataa[i][2] = lname;
				dataa[i][3] = saddress;
				dataa[i][4] = city;
				dataa[i][5] = prov;
				dataa[i][6] = zipcode;
				dataa[i][7] = gender;
				dataa[i][8] = day;
				dataa[i][9] = memb;
				dataa[i][10] = phone;
				dataa[i][11] = month;
				dataa[i][12] = year;
			}
		}
	}


};

int main()
{
	AddressBook caller;
	int choice;

	do
	{
		cout << "1) Add a contact\n2) Delete a contact\n3) Update a contact\n4) Display\n5) Exit\n";
		cin >> choice;


		if (choice == 4)
		{
			system("CLS");
			char choicee;
			cout << "4) Display:\n a-Display Specifics\n b-Search By Lastname\n c-Names having bdays in a month\n d-Same status Names\n e-Same Genders\n f-Sorted between two last names\n";
			cin >> choicee;

			if (choicee == 'a')
			{
				caller.display();
			}

			if (choicee == 'b')
			{
				string keyyyy;
				cout << "Enter key of contact:";
				cin >> keyyyy;
				caller.displayspecifics(keyyyy);
			}

			if (choicee == 'c')
			{
				caller.birthdays();
			}

			if (choicee == 'd')
			{
				caller.membss();
			}

			if (choicee == 'e')
			{
				caller.samegender();
			}

			if (choicee == 'f')
			{
				
			}
		
		}


		if (choice == 1)
		{
			string key;
			
			string fname, lname, keyyyyy, contact, date, month, year, saddress, city, prov, zipcode, gender, memb;
			system("CLS");
			cout << "Enter the First name: ";
			cin >> fname;

			cout << "\nEnter the last name: ";
			cin >> lname;

			cout << "\nENter the key: ";
			cin >> keyyyyy;

			cout << "\nEnter the DOB (01 May 2000)";
			cin >> date;
			cin >> month;
			cin >> year;


			cout << "\nEnter Street Address: ";
			cin >> saddress;

			cout << "\n Enter Zipcode: ";
			cin >> zipcode;
			cout << "\n Enter province: ";
			cin >> prov;

			cout << "\n Enter city: ";
			cin >> city;

			cout << "\nEnter Gender: ";
			cin >> gender;

			cout << "\n Enter Status:";
			cin >> memb;

			cout << "\n Enter COntact:";
			cin >> contact;

			caller.adddata(key, fname, lname, saddress, city, prov, zipcode, gender, date, memb, contact, month, year);

		}


		if (choice == 2)
		{
			string num;
			cout << "Enter the keyy: ";
			cin >> num;
			caller.deletecont(num);
			caller.store();

		}

		if (choice == 3)
		{
			string numberrr;
			string fname, lname, numberr, contact, date, month, year, saddress, city, prov, zipcode, gender, memb;



			cout << "Enter the key of contact you want to update: ";
			cin >> numberr;

			cout << "Enter the First name: ";
			cin >> fname;

			cout << "\nEnter the last name: ";
			cin >> lname;

			cout << "\nEnter the DOB (01 May 2000)";
			cin >> date;
			cin >> month;
			cin >> year;


			cout << "\nEnter Street Address: ";
			cin >> saddress;

			cout << "\n Enter Zipcode: ";
			cin >> zipcode;
			cout << "\n Enter province: ";
			cin >> prov;

			cout << "\n Enter city: ";
			cin >> city;

			cout << "\nEnter Gender: ";
			cin >> gender;

			cout << "\n Enter Status:";
			cin >> memb;

			cout << "\n Enter COntact:";
			cin >> contact;

			caller.update(numberr, fname, lname, saddress, city, prov, zipcode, gender, date, memb, contact, month, year);
		}
	} while (choice != 5);

	
	

	
}

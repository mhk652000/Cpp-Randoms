//Muhammad Hasan Khan       2019328


#include <iostream>
#include <list>
using namespace std;

class grp
{
	string data;
	grp* next;
	grp* forward;
	grp* head;
	int distance;

public:

	grp()
	{
		head = NULL;
	}

	grp* addnode(string value)                                                        //used to create new nodes       
	{
		grp* temp, * s;
		temp = new grp;
		if (temp == NULL)
		{
			cout << "Memory not allocated " << endl;
			return 0;
		}
		else
		{
			temp->data = value;
			temp->next = NULL;
			temp->forward = NULL;
			return temp;
		}
	}

	void insert_edge(string x, string y, int z)                                         //routes created
	{
		grp* ptr = head;
		grp* temp, * s;


		temp = addnode(y);


		while (ptr->data != x)
		{
			ptr = ptr->next;
		}
		if (ptr->forward == NULL)
		{
			ptr->distance = z;
			ptr->forward = temp;
		}
		else
		{
			s = ptr;
			while (s->forward != NULL)
			{
				s = s->forward;
			}
			s->forward = temp;
			s->distance = z;
		}
	}



	void insert_vertex(string value)                                   //adds the cities
	{
		grp* temp, * s;
		temp = addnode(value);


		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			s = head;

			while (s->next != NULL)
			{
				s = s->next;
			}
			s->next = temp;

		}
	}


	void displaygraph()                                                      //displays the graph
	{
		grp* ptr, * ptr1;

		for (ptr = head; ptr != NULL; ptr = ptr->next)
		{
			for (ptr1 = ptr; ptr1 != NULL; ptr1 = ptr1->forward)
			{
				cout <<ptr1->data << "-->" << "(" << ptr1->distance << ")";
			}
			cout << endl;
		}
	}



};



int main()
{

	grp caller;
	int choice;
	string cityy1,city2;
	int dist;
	do                                                       //menu driven code
	{
		cout << "--------------------------------------------\n";
		cout << "1) Display the graph" << endl;
		cout << "2) Add city" << endl;
		cout << "3) Create a route" << endl;
		cout << "4) Exit" << endl;
		cin >> choice;

		if (choice == 1)
		{
			system("CLS");
			caller.displaygraph();
		}

		else if (choice == 2)
		{
			system("CLS");
			cout << "Enter the city name: ";
			cin >> cityy1;
			caller.insert_vertex(cityy1);
			system("CLS");
			cout << "Success!" << endl<<endl;
		}

		else if (choice == 3)
		{
			system("CLS");
			cout << "Enter the city from which you want to create a route: ";
			cin >> cityy1;

			cout <<endl<< "Enter the city to which the route reaches to: ";
			cin >> city2;

			cout << endl << "Enter distance of the route: ";
			cin >> dist;
			caller.insert_edge(cityy1, city2, dist);

			system("CLS");
			cout << "Success!" << endl << endl;
		}

	} while (choice != 4);
}


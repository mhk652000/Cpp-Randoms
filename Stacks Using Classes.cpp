#include <iostream>
using namespace std;


class stackk
{
	int n;
	int stck[100];
	int top;

public:

	stackk()
	{
		n = 100;
		top = -1;
	}

	void push()
	{
		int val;
		cout << "\n Insert a value to push: ";
		cin >> val;

		if (top == n - 1)
		{
			cout << "\nStack Overflow!\n";
		}

		else
		{
			top++;
			stck[top] = val;
			cout << "\nSuccess!\n";
		}
	}

	void pop()
	{
		if (top <= -1)
		{
			cout << "\nStack Underflow\n";
		}
		else
		{
			cout << "\nThe popped element is: " << stck[top] << endl;
			top--;
		}
	}

	void display()
	{
		for (int i = top; i >= 0; i--)
		{
			cout << stck[i] << "\t";
		}
		cout << endl;
	}
};

int main()
{
	stackk access;
	int choice;
	do
	{
		cout << "1) Push \n2) Pop \n3)Display \n4)Exit \n";
		cin >> choice;

		switch(choice)
		{
		case 1:
		{
			access.push();
			cout << endl;
			break;
		}

		case 2:
		{
			access.pop();
			cout << endl;
			break;
		}

		case 3:
		{
			access.display();
			cout << endl;
			break;
		}
		case 4:
		{
			exit(1);
		}

		default:
		{
			cout << "\nWrong Input\n";
		}
		}
	} while (choice != 4);
}
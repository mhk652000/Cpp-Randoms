#include <iostream>
#include <cstring>
#include <ctype.h>
#include <string>
#include <sstream> 


//     Muhammad Hasan Khan 2019328
//     Muhammad Tashfeen 2019213



using namespace std;




template <class X>

class stack
{
private:

	struct node
	{
		X data;
		node* prev, * next;

	};

	node* tail, * head;

public:

	stack()
	{
		tail = NULL;
		head = NULL;
	}

	void push(X a)
	{
		node* temp = new node;
		temp->data = a;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
			tail->next = head;
			head->prev = tail;

		}

	}

	char top()
	{
		return head->data;
	}


	void pop()
	{

		if (head == NULL)
		{
			cout << "Stack Empty" << endl;
		}
		else
		{
			node* temp;

			if (head == tail)
			{
				temp = head;
				head = NULL;
				tail = NULL;

				delete temp;

			}

			else
			{

				temp = head;
				head = head->next;
				head->prev = tail;
				tail->next = head;
				delete temp;

			}

		}

	}

	bool isempty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void display()
	{
		if (isempty())
		{
			cout << "Stack Empty";
		}
		else
		{

			node* temp;
			temp = head;
			while (temp != tail)
			{
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout << temp->data;
		}

	}

};

bool opening(char str)
{
	if (str == '(')
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool prec(char top, char str)
{
	if (top == '*')
	{
		return true;
	}
	if (top == '/')
	{
		if (str == '*')
			return false;
		else

			return true;
	}
	if (top == '-')
	{
		if (str == '*' || str == '/')
			return false;
		else
			return true;
	}
	if (top == '+')
	{
		return false;
	}

}

bool operators(char a)                         //operator overloading
{
	if (a == '+')
	{
		return true;
	}
	if (a == '-')
	{
		return true;
	}
	if (a == '*')
	{
		return true;
	}
	if (a == '/')
	{
		return true;
	}

	else
	{
		return false;
	}

}


string toprefix(string str)
{
	stack<char> S;
	string counter;

	for (int i = 0; i < str.length(); i++)
	{

		if (isdigit(str[i]) || (str[i] == '-' && str[i - 1] == '(') || str[0] == '-' && str[i] != '+')
		{
			counter = counter + str[i];
		}
		else if (str[i] != '(' && str[i] != ')')
		{
			counter = counter + " ";

			while (!S.isempty() && prec(S.top(), str[i]) && !opening(S.top()))
			{
				counter = counter + S.top();
				S.pop();
			}
			S.push(str[i]);
		}

		if (str[i] == '(')
		{

			S.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (!S.isempty() && !opening(S.top()))
			{

				counter = counter + S.top();

				S.pop();
			}
			S.pop();
		}
	}
	while (!S.isempty())
	{
		counter = counter + S.top();
		S.pop();
	}

	return counter;
}

int operate(int a, int b, char str)
{
	if (str == '+')
	{
		return a + b;
	}
	if (str == '*')
	{
		return a * b;
	}
	if (str == '/')
	{
		return (b / a);
	}
	if (str == '-')
	{
		return b - a;
	}
}

void evaluate(string str)
{
	stack<int> s;
	int res;
	string append;

	for (int i = 0; i < str.length(); i++)
	{

		if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1])))
		{
			if (str[i] == '-' && isdigit(str[i + 1]))
			{
				append = append + str[i];
				i++;
			}
			while (str[i] != ' ' && !operators(str[i]))
			{
				append = append + str[i];

				i++;
			}

			stringstream write(append);
			int x = 0;
			write >> x;
			s.push(x);

			append.clear();
		}

		if (operators(str[i]))
		{
			int a, b;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			res = operate(a, b, str[i]);
			s.push(res);
		}
	}
	s.display();

}


int main()
{

	string input;
	cout << "Input Infix Expression: ";
	getline(cin, input);
	cout << "Infix: " << input << "    Post Fix: " << toprefix(input);
	cout << "\nAnswer: "; evaluate(toprefix(input));

}



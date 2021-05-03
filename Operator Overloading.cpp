#include <iostream>
using namespace std;

class dummy
{
private:
	char* list;
	int size;

public:
	dummy()
	{
		size = 50;
		list = new char[size]();
	}
	dummy(char arr[])
	{
		int i;
		for (i = 0; arr[i] != '\0'; i++);
		size = i;
		list = new char[size + 1]();
		for (int j = 0; j < size; j++)
		{
			list[j] = arr[j];
		}

	}

	dummy(int Size)
	{
		size = Size;
		list = new char[size + 1]();
	}


	friend ostream& operator << (ostream&, const dummy&);
	friend istream& operator >> (istream&, const dummy&);

	dummy operator + (dummy& dumb)
	{

		char* temp = new char[50]();
		for (int i = 0; i < size; i++)
		{

			temp[i] = list[i];

		}

		for (int i = 0; i < dumb.size; i++)
		{

			temp[size + i] = dumb.list[i];

		}

		dummy result(temp);

		delete[] temp;
		return result;
	}

	dummy operator += (dummy& dumb)
	{

		char* temp = new char[50]();
		for (int i = 0; i < size; i++)
		{

			temp[i] = list[i];

		}

		for (int i = 0; i < dumb.size; i++)
		{

			temp[size + i] = dumb.list[i];

		}
		size = size + dumb.size;
		list = temp;
		return *this;
	}


	bool operator ==(const dummy& d)
	{

		if (size != d.size)
		{
			cout << "False" << endl;
			return false;
		}
		for (int i = 0; i < size; i++)
		{
			if (list[i] != d.list[i])
			{
				cout << "False" << endl;
				return false;
			}
		}

		cout << "True" << endl;
		return true;
	}

	bool operator !=(const dummy& d)
	{

		if (size != d.size)
		{
			cout << "True" << endl;
			return true;
		}
		for (int i = 0; i < size; i++)
		{
			if (list[i] != d.list[i])
			{
				cout << "True" << endl;
				return true;
			}
		}

		cout << "False" << endl;
		return false;
	}

	bool operator >(const dummy& d)
	{

		if (list > d.list)
		{
			cout << "True" << endl;
			return true;
		}

		cout << "False" << endl;
		return false;
	}

	bool operator <(const dummy& d)
	{

		if (list < d.list)
		{
			cout << "True" << endl;
			return true;
		}

		cout << "False" << endl;
		return false;
	}

	char& operator[](int i)
	{
		if (i > size)
		{
			cout << "Index out of bounds" << endl;
			return list[0];
		}
		return list[i];
	}

	dummy operator()(int s, int e)
	{
		char* temp = new char[50]();
		for (int i = s; i <= e; i++)
		{
			temp[i] = this->list[i];
		}
		dummy result(temp);
		delete[] temp;
		return  result;
	}

	dummy& operator << (int n)
	{
		char* temp = new char[n + 1]();
		for (int i = 0; i < n; i++)
		{
			temp[i] = list[i];
		}
		int i;
		for (i = 0; i < size - n; i++)
		{
			list[i] = list[n + i];
		}
		list[i] = { '\0' };
		this->size = (size - n);
		dummy result(temp);
		delete[] temp;
		return result;
	}

	dummy& operator >> (int n)
	{
		char* temp = new char[n + 1]();
		for (int i = 0; i < n; i++)
		{
			temp[i] = list[size - i - 1];
		}
		int i;
		for (i = 0; i < size - n; i++);

		list[i] = { '\0' };
		this->size = (size - n);
		dummy result(temp);
		delete[] temp;
		return result;
	}

	int SizeOfString(string st)
	{
		int i;
		for (i = 0; st[i] != '\0'; i++);
		return i;

	}
	int SizeOfCharacterArray(char st[])
	{
		int i;
		for (i = 0; st[i] != '\0'; i++);
		return i;

	}

	~dummy()
	{

	}



};
ostream& operator<<(ostream& output, const dummy& op)
{
	output << op.list;
	return output;
}

istream& operator>>(istream& input, const dummy& op)
{
	input >> op.list;
	return input;
}


int main()
{

	char A[20] = "ABCDEFGHI";
	char B[20] = "JKLMNOPQR";
	char C[20] = "STUVWXYZ";

	dummy a(A), b(B), c;

	cout << "Before applying + operator" << endl;
	cout << a << endl;
	cout << b << endl;
	c = a + b;

	cout << "After applying + operator" << endl;
	cout << c << endl;


	cout << "\nBefore applying += operator" << endl;
	cout << a << endl;
	cout << b << endl;
	a += b;

	cout << "After applying += operator" << endl;
	cout << a;


	dummy d(A);
	cout << "\n\nBefore applying == operator" << endl;
	cout << d << endl;
	cout << b << endl;

	cout << "After applying == operator" << endl;
	d == b;


	cout << "\nBefore applying != operator" << endl;
	cout << d << endl;
	cout << b << endl;

	cout << "After applying != operator" << endl;
	d != b;


	cout << "\nBefore applying > operator" << endl;
	cout << d << endl;
	cout << b << endl;

	cout << "After applying > operator" << endl;
	d > b;


	cout << "\nBefore applying < operator" << endl;
	cout << d << endl;
	cout << b << endl;

	cout << "After applying < operator" << endl;
	d < b;

	cout << "\nGet specific character by using []" << endl;
	cout << d << endl;
	char e = d[1];
	cout << e << endl;

	cout << "\nSet specific character by using []" << endl;
	cout << d << endl;
	d[1] = 'A';
	cout << d << endl;
	d[1] = 'B';


	cout << "\nGet substring by using ()" << endl;
	cout << d << endl;
	dummy f = d(0, 4);
	cout << f << endl;


	cout << "\nLeft shifting string by using <<" << endl;
	cout << "Before" << endl;
	cout << d << endl;
	f = d << 2;

	cout << "After" << endl;
	cout << f << endl;
	cout << d << endl;

	cout << "\nRight shifting string by using >>" << endl;
	cout << "Before" << endl;
	cout << b << endl;
	f = b >> 2;
	cout << "After" << endl;
	cout << f << endl;
	cout << b << endl;


}
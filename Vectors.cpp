#include <iostream>
#include <vector>
using namespace std;


vector <int> vector1;
vector <int> vector2;
vector <int> vector3;





int main()
{
	

	for (int i = 0; i < 10; i++)
	{
		vector1.push_back(i);
		vector2.push_back(i + 10);
		vector3.push_back(i);
	}

	cout << "Vector1: ";
	for (int i = 0; i < 10; i++)
	{
		cout<<" "<<vector1.at(i);
	}

	cout <<endl<< "Vector2: ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << vector2.at(i);
	}

	cout << endl << "Vector3: ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << vector3.at(i);
	}



	cout << endl;

	if (vector1 == vector2)
	{
		cout << endl << "Vector1 is equals to Vector2";
	}

	if (vector1 != vector2)
	{
		cout << endl << "Vector1 is not equals to Vector2";
	}

	if (vector1.at(1) > vector2.at(1))
	{
		cout << endl << "Vector1 is greater than Vector2";
	}

	if (vector2.at(1) > vector1.at(1))
	{
		cout << endl << "Vector2 is greater than Vector1";
	}

	if (vector1.at(1) >= vector2.at(1))
	{
		cout << endl << "Vector1 is greater than and equals to Vector2";
	}

	if (vector2.at(1) >= vector1.at(1))
	{
		cout << endl << "Vector2 is greater than and equals to Vector1";
	}





	if (vector1 == vector3)
	{
		cout << endl << "Vector1 is equals to Vector3";
	}

	if (vector1 != vector3)
	{
		cout << endl << "Vector1 is not equals to Vector3";
	}

	if (vector1.at(1) > vector3.at(1))
	{
		cout << endl << "Vector1 is greater than Vector3";
	}

	if (vector3.at(1) > vector1.at(1))
	{
		cout << endl << "Vector3 is greater than Vector1";
	}

	if (vector1.at(1) >= vector3.at(1))
	{
		cout << endl << "Vector1 is greater than and equals to Vector3";
	}

	if (vector3.at(1) >= vector1.at(1))
	{
		cout << endl << "Vector3 is greater than and equals to Vector1";
	}




	if (vector2 == vector3)
	{
		cout << endl << "Vector2 is equals to Vector3";
	}

	if (vector2 != vector3)
	{
		cout << endl << "Vector2 is not equals to Vector3";
	}

	if (vector2.at(1) > vector3.at(1))
	{
		cout << endl << "Vector2 is greater than Vector3";
	}

	if (vector3.at(1) > vector2.at(1))
	{
		cout << endl << "Vector3 is greater than Vector2";
	}

	if (vector2.at(1) >= vector3.at(1))
	{
		cout << endl << "Vector2 is greater than and equals to Vector3";
	}

	if (vector3.at(1) >= vector2.at(1))
	{
		cout << endl << "Vector3 is greater than and equals to Vector2";
	}


		
}


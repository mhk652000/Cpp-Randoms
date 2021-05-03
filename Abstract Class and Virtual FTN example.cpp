#include <iostream>
using namespace std;

// Abstract class
class Calculate
{
protected:
    int num1, num2, result;
public:

    void setvar(int n,int o)
    {
        num1 = n;
        num2 = o;
    }

    int getresult()
    {
       return operation();
    }


    // virtual Function
    virtual int operation() = 0;
};

class Add : public Calculate
{
public:
    int operation()
    {
        result = (num1 + num2);
        return result;
    }
};

class Subtract : public Calculate
{
public:
    int operation()
    {
        result = (num1 - num2);
        return result;
    }
};

int main()
{
    int n1, n2;
    Add plus;
    Subtract minus;
    char choice='y';

    while (choice == 'y')
    {
        cout << "Enter two numbers seperated by space: ";
        cin >> n1 >> n2;


        cout << endl << endl;


        plus.setvar(n1, n2);

        cout << "Result of Summation: " << plus.getresult();

        minus.setvar(n1, n2);

        cout << "\nResult of Substraction: " << minus.getresult();


        cout << endl << endl << "Do you wanna try again? (y/n): ";
        cin >> choice;

        cout << endl << endl;

    }
    return 0;
}
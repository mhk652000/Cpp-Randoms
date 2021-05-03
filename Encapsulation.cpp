#include <iostream>
#include<string>
using namespace std;



class encapsulation
{
private:
    char* chararray=new char[50];
    int size;

public:
    encapsulation(int x=0)
    {
        size = x;

        for (int i = 0; i < 50; i++)
        {
            chararray[i] = '0';
        }
    }

    encapsulation(char arr2[])
    {
        for (int i = 0; i < 50; i++)
        {
            chararray[i] = arr2[i];
        }
    }

    int stringsize()
    {
        int count=0;
        for (int i = 0; i < 50; i++)
        {
            if (chararray[i] != '0')
            {
                count++;
            }
        }
        return count;
    }

    void print()
    {
       
    }

    encapsulation operator +(encapsulation& A)
    {
        encapsulation result;
        
        result.chararray = A.chararray;


        return result;
    }

   
    friend istream& operator >> (istream& in, encapsulation& X);
    friend ostream& operator << (ostream& out, encapsulation& Y);
   
};

istream& operator >> (istream& in, encapsulation& X)
{
    cout << "Enter your string: ";
    in >> X.chararray;
    return in;
}

ostream& operator << (ostream& out, encapsulation& Y)
{
    out << endl<<"String is: ";
    for (int i = 0; i < 50; i++)
    {
        
        if (Y.chararray[i] != '0')
        {
            out << Y.chararray[i];
        }
    }
    return out;
}






int main()
{
    encapsulation a,b,c;
    cin>>a;
    cout << a;
    cin >> b;
    cout << b;

    c = a + b;
    cout << c;
}

#include <iostream>
#include <string>
using namespace std;

class package
{
protected:
    string name, adress, city;
    int zipcode;

public:
    package()
    {
    }
    package(string x,string y,string z, int n)
    {
        name = x;
        adress = y;
        city = z;
        zipcode = n;
    }

    void display()
    {
        cout<<"\nName = "<<name;
        cout << "\nAddress = " << adress;
        cout << "\nCity = " << city;
        cout << "\nzipcode = " << zipcode;
    }

    int calculatecost(int weight)
    {
        float cost = weight * 5;
        return cost;
    }
};

class twodaypackage:public package
{
protected:
    int fee;
public:

    twodaypackage()
    {
        fee = 10;
    }

    int calculatecost(int weight)
    {
        float cost = (weight * 5)+fee;
        return cost;
    }

};

class overnightpackage :public package
{
protected:
    int fee;

public:

    overnightpackage()
    {
        fee = 10;
    }

    int calculatecost(int weight)
    {
        float cost = (weight * 10) + fee;
        return cost;
    }


};



int main()
{
    string sname,rname, sadress,radress, scity,rcity;
    int szipcode,rzipcode;
    float weight;
    
    int choice=0;
    cout << "Welcome to Package Delivery service! Our rate chart is as follows:" <<endl<<endl;
    cout << "1)Two-Day Delivery:         5rs/Ounce + 10Rs Fee." << endl;
    cout << "2)Over-Night Delivery:      10rs/Ounce + 10Rs Fee." << endl;

    cout << "\nPlease Select One: ";
    cin >> choice;

    system("CLS");

    cout << "YOUR INFORMATION";
    cout << endl<<endl<< "Enter your name: ";
    cin >> sname;
    cin.ignore();
    cout << endl << "Enter your Adress: ";
    getline(cin, sadress);

    cout << endl << "Enter your City: ";
    cin >> scity;
    cout << endl << "Enter your zipcode: ";
    cin >> szipcode;

    cout <<endl<<endl<< "RECIEVERS INFORMATION";
    cout << endl << endl << "Enter reciever name: ";
    cin >> rname;
    cin.ignore();

    cout << endl << "Enter reciever Adress: ";
    getline(cin, radress);

    cout << endl << "Enter reciever City: ";
    cin >> rcity;
    cout << endl << "Enter reciever zipcode: ";
    cin >> rzipcode;

    

    cout << "\nEnter the weight of the product(ounces): ";
    cin >> weight;

    package sender(sname, sadress, scity, szipcode);
    package reciever(rname, radress, rcity, rzipcode);

    system("CLS");

    


    if (choice == 1)
    {
        sender.display();
        twodaypackage parcel;
        cout << "SendersINFO: " << endl;

        cout << endl << endl << "RecieversINFO: ";
        reciever.display();
        cout << endl << "Total Cost of Service: " << parcel.calculatecost(weight);
    }

    else if (choice == 2)
    {
        
            overnightpackage parcel;
            cout << "SendersINFO: " << endl;
            sender.display();
            cout << endl << endl << "RecieversINFO: ";
            reciever.display();
            cout << "\n---------------------------------------\n";
            cout << "Total Cost of Service: " << parcel.calculatecost(weight)<<"Rs";
    }


}
#include <iostream>
using namespace std;




int calculatebill(int cake, int topping)
{
    int sum = 0;
    sum = cake + topping;
    return sum;
}

int main()
{
    int choice = 0;
    int choicee = 0;
    do 
    {
        cout << "Welcome to MakeitSweet!" << endl;
        cout << "Choose any one:" << endl;
        cout << "1) Fruit Cakes \n2) Dry Cakes \n3) Chocolate Cakes \n4) Exit\n";
        cin >> choice;


        if (choice == 1)
        {
            int sum = 0;
            int toppingg=0;
            int a=0, b=0;
            system("CLS");
            cout << "Types of Fruit Cakes:" << endl;
            cout << "1) Apple Cake (1000)" << endl;
            cout << "2) Banana Cake (1200)" << endl;
            cout << "3) Strawberry Cake (1500)" << endl;
            cout << "4) Blueberry Cake (2000)" << endl;

            cin >> choicee;

            cout << endl << "Select Topping: " << endl;
            cout << "1) Icing(700)\n2) ChocolateChips(400)\n3) Icing+ChocolateChips(1100)\n4) NoTopping(50)\n";
            cin >> toppingg;

            if(choicee==1)
            {
                a = 1000;

                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }

            if (choicee == 2)
            {
                a = 1200;

                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }

            if (choicee == 3)
            {
                a = 1500;
                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }

            if (choicee == 4)
            {
                a = 2000;
                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }

           

        }

        if (choice == 2)
        {
            int toppingg = 0;
            int sum = 0;
            int a=0, b=0;
            system("CLS");
            cout << "Types of Dry Cakes:" << endl;
            cout << "1) Almond Cake (700)" << endl;
            cout << "2) Tea Cake (500)" << endl;
            cout << "3) Salty Cake (600)" << endl;

            cin >> choicee;

            cout << endl << "Select Topping: " << endl;
            cout << "1) Icing(700)\n2) ChocolateChips(400)\n3) Icing+ChocolateChips(1100)\n4) NoTopping(50)\n";
            cin >> toppingg;

            if (choicee == 1)
            {
                a = 700;
                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }

            if (choicee == 2)
            {
                a = 500;

                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }

            if (choicee == 3)
            {
                a = 600;

                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }

            

        }

        if (choice == 3)
        {
            int toppingg = 0;
            int sum = 0;
            int a = 0, b = 0;
            system("CLS");
            cout << "Types of Chocolate Cakes:" << endl;
            cout << "1) Dark Cake (1500)" << endl;
            cout << "2) Mouse Cake (2500)" << endl;

            cin >> choicee;

            cout << endl << "Select Topping: " << endl;
            cout << "1) Icing(700)\n2) ChocolateChips(400)\n3) Icing+ChocolateChips(1100)\n4) NoTopping(50)\n";
            cin >> toppingg;

            if (choicee == 1)
            {
                a = 1500;
                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }

            }

            if (choicee == 2)
            {
                a = 2500;
                if (toppingg == 1)
                {
                    sum = calculatebill(a, 700);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 2)
                {
                    sum = calculatebill(a, 400);
                    cout << "The bill for your cake is:" << sum << endl;
                }
                if (toppingg == 3)
                {
                    sum = calculatebill(a, 1100);
                    cout << "The bill for your cake is:" << sum << endl;
                }

                if (toppingg == 4)
                {
                    sum = calculatebill(a, 50);
                    cout << "The bill for your cake is:" << sum << endl;
                }
            }
           
        }

    } while (choice != 4);
    



}

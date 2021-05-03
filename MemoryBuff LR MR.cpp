// Muhammad Hasan Khan (2019328)



#include <iostream>
using namespace std;

template <class X>          // used generic class instead of generic function. (compile time polymorphism)

class pointvars
{
protected:
    X* front;                      //added flexibility to the data type
    X* back;
    X* middle;                        //pointers to store refrences of recent, middle and least recent and frequent pages
    X memorybuff[3];
    X pagenum;
    int chk;
    X limit;
    int frequency[3];

public:
    pointvars(int x)                  //constructor
    {
        for (int i = 0; i < 3; i++)
        {
            memorybuff[i] = NULL;
            frequency[i] = 0;
        }

        chk = x;

        if (chk == 1)
        {
            limit = 9;
        }
        if (chk == 2)
        {
            limit = 'j';
        }
    }
    pointvars()                         //default constructor with no values
    {
    }

    void LRfunction()                      //LEAST RECENT function.
    {

        do
        {
            front = &memorybuff[0];

            middle = &memorybuff[1];

            back = &memorybuff[2];

            if (chk == 1)
            {
                cout << "Enter page number (from 1-9): ";
            }

            if (chk == 2)
            {
                cout << "Enter page number (from a-j): ";
            }

            cin >> pagenum;

            if (pagenum > limit)
            {
                exit(0);
            }
            cout << endl;

            int checker = 5;

            for (int j = 0; j < 3; j++)              //loops to see if the memorybuff array is full or empty
            {
                if (pagenum != memorybuff[j] && pagenum <= limit && memorybuff[j] == NULL)
                {
                    checker = 1;
                }

                else if (pagenum == memorybuff[j] && pagenum <= 9)
                {
                    checker = 0;
                }
            }

            if (checker == 1)             //if array is empty, user defined values are stored in it using pointers
            {


                if (memorybuff[0] == NULL)
                {
                    front = &pagenum;
                    memorybuff[0] = *front;
                }

                if (memorybuff[1] == NULL && memorybuff[0] != pagenum && memorybuff[2] != pagenum)
                {
                    middle = front;
                    memorybuff[1] = *middle;

                    front = &pagenum;
                    memorybuff[0] = *front;
                }

                if (memorybuff[2] == NULL && memorybuff[0] != pagenum && memorybuff[1] != pagenum)
                {
                    back = middle;
                    memorybuff[2] = *back;

                    middle = front;
                    memorybuff[1] = *middle;

                    front = &pagenum;
                    memorybuff[0] = *front;
                }

                if (memorybuff[2] == NULL && memorybuff[0] == pagenum && memorybuff[1] != pagenum)
                {
                    front = &pagenum;
                    memorybuff[0] = *front;

                    middle = &memorybuff[1];
                    back = &memorybuff[2];
                }

                if (memorybuff[2] == NULL && memorybuff[0] != pagenum && memorybuff[1] == pagenum)
                {
                    memorybuff[1] = *front;

                    front = &pagenum;
                    memorybuff[0] = *front;

                    middle = &memorybuff[1];

                }




                cout << "Most Recently Used Page: " << memorybuff[0] << endl;
                cout << "Least Recently Used Page: ";

                if (memorybuff[2] != NULL)
                {
                    cout << memorybuff[2] << endl;
                }

                else
                {
                    if (memorybuff[1] != NULL)
                    {
                        cout << memorybuff[1] << endl;
                    }

                    else
                    {
                        cout << memorybuff[0] << endl;
                    }

                }
            }





            if (checker != 1)                //if array is full, values are added or updated using pointers 
            {
                if (pagenum == memorybuff[0])
                {

                    front = &memorybuff[0];

                    middle = &memorybuff[1];

                    back = &memorybuff[2];


                    cout << "Most Recently Used Page: " << memorybuff[0] << endl;
                    cout << "Least Recently Used Page: ";
                    if (memorybuff[2] != NULL)
                    {
                        cout << memorybuff[2] << endl;
                    }

                    else
                    {
                        if (memorybuff[1] != NULL)
                        {
                            cout << memorybuff[1] << endl;
                        }

                        else
                        {
                            cout << memorybuff[0] << endl;
                        }

                    }
                }

                if (pagenum == memorybuff[1])                      //loops to process user defined input according to the instructions
                {
                    front = &memorybuff[0];

                    middle = &memorybuff[1];

                    back = &memorybuff[2];


                    memorybuff[1] = *front;

                    memorybuff[0] = pagenum;


                    front = &memorybuff[0];

                    middle = &memorybuff[1];

                    back = &memorybuff[2];


                    cout << "Most Recently Used Page: " << memorybuff[0] << endl;
                    cout << "Least Recently Used Page: ";
                    if (memorybuff[2] != NULL)
                    {
                        cout << memorybuff[2] << endl;
                    }

                    else
                    {
                        if (memorybuff[1] != NULL)
                        {
                            cout << memorybuff[1] << endl;
                        }

                        else
                        {
                            cout << memorybuff[0] << endl;
                        }

                    }

                }


                if (pagenum == memorybuff[2])
                {

                    front = &memorybuff[0];

                    middle = &memorybuff[1];

                    back = &memorybuff[2];

                    memorybuff[2] = *middle;

                    memorybuff[1] = *front;

                    memorybuff[0] = pagenum;


                    front = &memorybuff[0];

                    middle = &memorybuff[1];

                    back = &memorybuff[2];



                    cout << "Most Recently Used Page: " << memorybuff[0] << endl;    //printing recently and least recently used pages
                    cout << "Least Recently Used Page: ";
                    if (memorybuff[2] != NULL)
                    {
                        cout << memorybuff[2] << endl;
                    }

                    else
                    {
                        if (memorybuff[1] != NULL)
                        {
                            cout << memorybuff[1] << endl;
                        }

                        else
                        {
                            cout << memorybuff[0] << endl;
                        }

                    }
                }


                if (pagenum != memorybuff[2] && pagenum != memorybuff[1] && pagenum != memorybuff[0])
                {


                    front = &memorybuff[0];

                    middle = &memorybuff[1];

                    back = &memorybuff[2];


                    memorybuff[2] = *middle;

                    memorybuff[1] = *front;

                    memorybuff[0] = pagenum;


                    front = &memorybuff[0];

                    middle = &memorybuff[1];

                    back = &memorybuff[2];



                    cout << "Most Recently Used Page: " << memorybuff[0] << endl;
                    cout << "Least Recently Used Page: ";
                    if (memorybuff[2] != NULL)
                    {
                        cout << memorybuff[2] << endl;
                    }

                    else
                    {
                        if (memorybuff[1] != NULL)
                        {
                            cout << memorybuff[1] << endl;
                        }

                        else
                        {
                            cout << memorybuff[0] << endl;
                        }

                    }
                }



            }


            cout << "Memory Buffer Contains Pages: ";    //printing pages
            for (int i = 0; i < 3; i++)
            {
                if (memorybuff[i] != NULL)
                {
                    cout << memorybuff[i] << " ";
                }

            }
            cout << endl << endl;




        } while (pagenum << 10);
    }



    void LFfunctionn()                         //LEAST FREQUENCY function
    {
        do
        {
            front = &memorybuff[0];

            middle = &memorybuff[1];

            back = &memorybuff[2];

            if (chk == 1)
            {
                cout << "Enter page number (from 1-9): ";
            }

            if (chk == 2)
            {
                cout << "Enter page number (from a-j): ";
            }
            cin >> pagenum;

            if (pagenum > limit)
            {
                exit(0);
            }
            cout << endl;

            int checker = 5;

            for (int j = 0; j < 3; j++)                       //to check if array is full or empty
            {
                if (pagenum != memorybuff[j] && pagenum <= 9 && memorybuff[j] == NULL)
                {
                    checker = 1;
                }

                else if (pagenum == memorybuff[j] && pagenum <= 9)
                {
                    checker = 0;
                }
            }

            if (checker == 1)                    //if empty, stored  user input through pointers
            {
                if (memorybuff[0] == NULL)
                {
                    front = &pagenum;
                    memorybuff[0] = *front;
                    frequency[0]++;
                }

                else
                {
                    if (memorybuff[1] == NULL)
                    {
                        if (memorybuff[0] == pagenum)
                        {
                            frequency[0]++;
                        }

                        else
                        {
                            middle = &pagenum;
                            memorybuff[1] = *middle;
                            frequency[1]++;
                        }
                    }

                    else
                    {
                        if (memorybuff[0] == pagenum)
                        {
                            frequency[0]++;
                        }

                        else if (memorybuff[1] == pagenum)
                        {
                            frequency[1]++;
                        }

                        else
                        {
                            back = &pagenum;
                            memorybuff[2] = *back;
                            frequency[2]++;


                        }
                    }
                }

            }




            if (checker != 1)                       //if not empty, updated the array by storing the user input through pointers
            {
                for (int i = 0; i < 3; i++)
                {
                    if (pagenum == memorybuff[i])
                    {
                        frequency[i]++;
                    }
                }


                if (memorybuff[0] != pagenum && memorybuff[1] != pagenum && memorybuff[2] != pagenum)
                {
                    int index = 0;
                    int smallest = frequency[0];

                    for (int i = 0; i < 3; i++)                  //loop1 to handle same frequency exception
                    {
                        if (frequency[i] < smallest)
                        {
                            smallest = frequency[i];
                            index = i;
                        }
                    }

                    for (int i = 0; i < 3; i++)                    //loop2 to handle same frequency exception
                    {
                        if (frequency[i] == frequency[index])
                        {
                            if (i < index)
                            {
                                index = i;
                            }
                        }

                    }

                    frequency[index] = 0;

                    memorybuff[index] = pagenum;                  
                    frequency[index] = frequency[index] + 1;            
                }

            }


            cout << "Memory Buffer Contains Pages: ";             //printing pages
            for (int i = 0; i < 3; i++)
            {
                if (memorybuff[i] != NULL)
                {
                    cout << memorybuff[i] << " ";
                }

            }
            cout << endl;

            cout << "Frequency Buffer Contains Occurences: ";           //printing frequency
            for (int i = 0; i < 3; i++)
            {
                if (memorybuff[i] != NULL)
                {
                    cout << frequency[i] << " ";
                }

            }
            cout << endl<<endl;


        } while (pagenum << 10);
    }
};




int main()
{

    int choice = 0;                                       //Menu driven code. 
    cout << "Choose ONE Algorithm:" << endl;
    cout << " 1) Least Recently Used" << endl;
    cout << " 2) Least Frequently Used" << endl;
    cin >> choice;


    if (choice == 1)
    {
        system("CLS");
        int x;
        cout << "Which data type do you want to use? " << endl;
        cout << "1) Int" << endl;
        cout << "2) Char" << endl;

        cin >> x;

        system("CLS");

        if (x == 1)
        {
            pointvars<int> A(1);          //calling object and sending value to constructor that determines if data type is char or int
            A.LRfunction();

        }

        if (x == 2)
        {
            pointvars<char> A(2);
            A.LRfunction();
        }
    }

    if (choice == 2)
    {
        system("CLS");
        int x;
        cout << "Which data type do you want to use? " << endl;
        cout << "1) Int" << endl;
        cout << "2) Char" << endl;

        cin >> x;

        if (x == 1)
        {
            pointvars<int> A(1);
            A.LFfunctionn();
        }

        if (x == 2)
        {
            pointvars<char> A(2);
            A.LFfunctionn();
        }
    }

}

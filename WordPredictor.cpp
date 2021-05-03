#include <iostream>           // Muhammad Hasan Khan 2019328   
                              
#include <cstring>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class text
{
    string words[100];
    char input[100];
    int counter;
    int check;
    int i;
    string predictor[27][5];
    string predicted[4];
    string message;

public:

    text()
    {
        i = 0;
        counter = 0;
        predictor[0][0] = " ";
        predictor[0][1] = "Hello";
        predictor[0][2] = "Dear";
        predictor[0][3] = "Where";
        predictor[0][4] = "How";

        predicted[0] = "Hello";
        predicted[1] = "Dear";
        predicted[2] = "Where";
        predicted[3] = "How";

        check = 0;
    }





    void fileinput()
    {
        ifstream file;
        file.open("words.txt");
        int j = 1;
        while (!file.eof())
        {
            file >> predictor[j][0];
            file >> predictor[j][1];
            file >> predictor[j][2];
            file >> predictor[j][3];
            file >> predictor[j][4];
            j++;
        }
    }





    void display()
    {
        cout << "Press the numbers to fill in the words: \n";
        for (int a = 0; a < 4; a++)
        {
            cout << a + 1 << ") " << predicted[a] << endl;
        }

        cout << endl << endl;
        cout << "Enter your text message and press ~ to send: ";
        cout << message;
    }




    void inputt(int x)
    {
        int i = x;
        do
        {
            input[i] = _getch();
            cout << input[i];

            if (i == 0)
            {
                analyze(input[i], 1);
            }

            else
            {
                analyze(input[i], 0);
            }

            
        } while (input[i] != '`');
        
        
    }

    void analyze(char c,int firstletter)
    {
        if (c == ' ')
        {
            addtomessage(c);
            if (firstletter == 1)
            {
               predictwords(c);
            }
           
            system("CLS");
            display();
            inputt(0);
        }

        else
        {
            if (firstletter == 1)
            {
                if (c == '`')
                {
                    cout << endl << "Message Sent!";
                    exit(0);
                }

                else if (c == '1')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[0].length(); x++)
                    {
                        message.push_back(predicted[0][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }

                else if (c == '2')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[1].length(); x++)
                    {
                        message.push_back(predicted[1][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }

                else if (c == '3')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[2].length(); x++)
                    {
                        message.push_back(predicted[2][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }

                else if (c == '4')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[3].length(); x++)
                    {
                        message.push_back(predicted[3][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }
                addtomessage(c);
                if (firstletter == 1)
                {
                    predictwords(c);
                }
                system("CLS");
                display();
                inputt(1);
            }

            else
            {
                if (c == '`')
                {
                    cout << endl << "Message Sent!";
                    exit(0);
                }

                else if (c == '1')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[0].length(); x++)
                    {
                        message.push_back(predicted[0][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }

                else if (c == '2')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[1].length(); x++)
                    {
                        message.push_back(predicted[1][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }

                else if (c == '3')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[2].length(); x++)
                    {
                        message.push_back(predicted[2][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }

                else if (c == '4')
                {
                    if (message != "")
                    {
                        message.pop_back();
                    }

                    for (int x = 0; x < predicted[3].length(); x++)
                    {
                        message.push_back(predicted[3][x]);
                    }

                    system("CLS");
                    display();
                    inputt(0);
                }

                else
                {
                    addtomessage(c);
                    system("CLS");
                    display();
                    inputt(1);
                }
                
            }
            

        }
        
        
    }


    void addtomessage(char x)
    {
        message.push_back(x);
    }



    void predictwords(char y)
    {
        for (int n = 0; n < 27; n++)
        {
            char x;
            x = predictor[n][0][0];
            if (x == y)
            {
                predicted[0] = predictor[n][1];
                predicted[1] = predictor[n][2];
                predicted[2] = predictor[n][3];
                predicted[3] = predictor[n][4];
            }
        }
    }

};




int main()
{
    text caller;

    caller.fileinput();
    caller.display();
    caller.inputt(0);
}


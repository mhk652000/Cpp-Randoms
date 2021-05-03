#include <iostream>
using namespace std;

class person
{
protected:
    string profession;
    int age;

public:

    void walk()
    {
        cout <<endl<< "I can talk";
    }

    void talk()
    {
        cout <<endl<< "I can walk";
    }
};

class mathsteacher:public person
{
public:

    mathsteacher()
    {

        profession = "Teacher";
        age = 37;

    }
    void teachmaths()
    {
        cout <<endl<< "I can teach maths";
    }

    void agenprof()
    {
        cout << "My Profession is: " << profession;
        cout << endl << "My Age is: " << age;
    }
    
};

class footballer:public person
{
public:
    footballer()
    {

        profession = "Football Player";
        age = 22;

    }
    void playfootball()
    {
        cout <<endl<< "I can play football";
    }

    void agenprof()
    {
        cout << "My Profession is: " << profession;
        cout <<endl<< "My Age is: " << age;
    }
};

int main()
{
    footballer player;

    player.agenprof();
    player.walk();
    player.talk();
    player.playfootball();

    cout << "\n----------------------------------\n";

    mathsteacher teacher;

    teacher.agenprof();
    teacher.walk();
    teacher.talk();
    teacher.teachmaths();

}


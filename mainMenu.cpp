#include <iostream>

using namespace std;

void howToPlay()
{
    cout << "Write some stuff here" << endl;
}

bool mainMenu()
{
    while(true)
    {
        cout << "------------------------" << endl;
        cout << "Welcome to <name>" << endl;
        cout << "Please select an option" << endl;
        cout << "1. Play" << endl;
        cout << "2. How to play" << endl;
        cout << "3. Quit" << endl;
        cout << "------------------------" << endl;

        int x;
        cin >> x;

        if(x==1)    //starts the game
        {
            return true;
        }   
        else if(x==2)   //prints the rules
        {
            howToPlay();
        }
        else if(x==3)   //closes the program
        {
            return false;
        }
        
        if(x !=2)   //2 is a valid input so it is excluded
        {
            cout << "Not a valid input" << endl;   
            cin.clear();    //cin is cleared so x can be reset
            cin.ignore();
        }
    }
}

int main()
{
    while(mainMenu())   //the player can choose to close the game
    {
        
    }
    return 0;
}

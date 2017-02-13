#include <iostream>

using namespace std;

int gridSize = 15;

void howToPlay()
{
    cout << "------------------------RULES------------------------" << endl;
    cout << "This is a turn based fighter game." << endl;
    cout << "The aim is to eliminate the other players units." << endl;
    cout << "Each unit has a movement speed. Each turn it can move that many tiles." << endl;
    cout << "Each unit has an attack stat and a defense stat." << endl;
    cout << "To destroy an enemy unit, the attack stat must be higher." << endl;
    cout << "If the defending enemy has a higer defense than the attacker's attack, both units survive" << endl;
    cout << "Ranged units can leave a space between it and the enemy when it attacks" << endl;
    cout << endl;
    cout << "------------------------UNITS------------------------" << endl;
    cout << endl;
    cout << "------------------------MELEE------------------------" << endl;
    cout << "KNIGHT - K" << endl;
    cout << "TEMPLAR - T" << endl;
    cout << "BERZERKER - B" << endl;
    cout << "------------------------RANGE------------------------" << endl;
    cout << endl;
    cout << "ARCHER - A" << endl;
    cout << "CROSSBOW - C" << endl;
    cout << "MAGE - M" << endl;
}

bool mainMenu()
{
    while(true)
    {
        cout << "------------------------" << endl;
        cout << "Welcome to TBF" << endl;
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
            
            cout << string( 100, '\n' );
            cout << "Not a valid input" << endl;   
            cin.clear();    //cin is cleared so x can be reset
            cin.ignore();
        }
    }
}

void grid()
{
    for(int y = 0; y < gridSize; y++)
    {
        for(int i = 0; i < gridSize;i++)
        {
            cout << "▄▄▄▄";
        }
        cout << "▄▄▄▄▄▄▄" << endl;
        
        for(int x = 0; x < gridSize; x++)
        {
            cout << "▓    ";
        }
        cout << endl;
        for(int x = 0; x < gridSize; x++)
        {
            cout << "▓    ";
        }
        cout << endl;
    }
}

int main()
{
    while(mainMenu())   //the player can choose to close the game
    {
        grid();
    }
    return 0;
}

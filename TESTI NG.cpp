#include <iostream>
#include <array>

using namespace std;

#include "libsqlite.hpp"

array<int, 2> playerPosition;
array<int, 2> comPosition;

int gridSize = 10;
bool playing = true;
int movesLeft = 3;

class Ranged {   
   private:
        int health;
        int movement;
};

class Meele {
    private:
        int health;
        int movement;
};
           
class Mage: Ranged {
    private:
        int Attack;
        int Defence;
    public:
        void setStats()
        {
            sqlite::sqlite db( "Characters.db" );    // open database

            auto cur = db.get_statement();            // create query
            cur->set_sql( "SELECT * FROM Characters WHERE ID = 1;" );
            cur->prepare();                            // run query
    
            cur->step();
            Attack = cur->get_int(10);
            Defence = cur-> get_int(0);
        }
};   

class Crossbow: Ranged {
    private:
        int Attack ;
        int Defence;
    public:
        void setStats()
        {
            sqlite::sqlite db( "Characters.db" );    // open database

            auto cur = db.get_statement();            // create query
            cur->set_sql( "SELECT * FROM Characters WHERE ID = 2;" );
            cur->prepare();                            // run query
    
            cur->step();
            Attack = cur->get_int(6);
            Defence = cur-> get_int(7);
        }
};
    
class Archer: Ranged {
    private:
        int Attack ;
        int Defence;
    public:
        void setStats()
        {
            sqlite::sqlite db( "Characters.db" );    // open database

            auto cur = db.get_statement();            // create query
            cur->set_sql( "SELECT * FROM Characters WHERE ID = 3;" );
            cur->prepare();                            // run query
    
            cur->step();
            Attack = cur->get_int(3);
            Defence = cur-> get_int(10);
        }
};
    
    
class Knight: Meele {
    private:
        int Attack ;
        int Defence;
    public:
        void setStats()
        {
            sqlite::sqlite db( "Characters.db" );    // open database

            auto cur = db.get_statement();            // create query
            cur->set_sql( "SELECT * FROM Characters WHERE ID = 4;" );
            cur->prepare();                            // run query
    
            cur->step();
            Attack = cur->get_int(10);
            Defence = cur-> get_int(8);
        }
};

    
class Berserker: Meele {
    private:
        int Attack ;
        int Defence;
    public:
        void setStats()
        {
            sqlite::sqlite db( "Characters.db" );    // open database

            auto cur = db.get_statement();            // create query
            cur->set_sql( "SELECT * FROM Characters WHERE ID = 5;" );
            cur->prepare();                            // run query
    
            cur->step();
            Attack = cur->get_int(12);
            Defence = cur-> get_int(5);
        }
};
    
    
class Templar: Meele {
    private:
        int Attack ;
        int Defence;
    public:
        void setStats()
        {
            sqlite::sqlite db( "Characters.db" );    // open database

            auto cur = db.get_statement();            // create query
            cur->set_sql( "SELECT * FROM Characters WHERE ID = 6;" );
            cur->prepare();                            // run query
    
            cur->step();
            Attack = cur->get_int(8);
            Defence = cur-> get_int(12);
        }
};
    
bool checkMove(int direction)
{
    if(playerPosition[1] == 0 && direction == 3)
    {
        return false;
    }
    else if(playerPosition[1] == gridSize - 1 && direction == 4)
    {
        return false;
    }
    else if(playerPosition[2] == 1 && direction == 1)
    {
        return false;
    }
    else if(playerPosition[2] == gridSize - 1 && direction == 2)
    {
        return false;
    }

    return true;
}

bool checkAttack()
{
    if((abs(playerPosition[1] - comPosition[1]) == 1 && playerPosition[2] == comPosition[2]) || (abs(playerPosition[2] - comPosition[2]) == 1 && playerPosition[1] == comPosition[1]))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void grid()
{
    for(int y = 0; y < 10; y++)
    {
        cout << "----------------------------------------" << endl;
        for(int x = 0; x < 10; x++)
        {
            cout << "|";

            if(x == playerPosition[1] && y == playerPosition[2])
            {
                cout << "PP";
            }

            else if(x == comPosition[1] && y == comPosition[2])
            {
                cout << "CP";
            }
            else
            {
                cout << "  ";
            }

               cout << "|" ;
        }
        cout << endl;
    }
}

void comEdgeCheck(){    //function to not let computer get out of the grid

    int xVal = rand() % 5 + 1;
    int yVal = rand() % 5 + 1;

    if(comPosition[1] > 6 && comPosition[1] <= 9){
        comPosition[1] -= xVal;
    }
    else if(comPosition[1] >= 0 && comPosition[1] < 3){
        comPosition[1] += xVal;
    }

    if(comPosition[2] > 6 && comPosition[2] <= 9){
        comPosition[2] -= yVal;
    }
    else if(comPosition[2] >= 0 && comPosition[2] < 3){
        comPosition[2] += yVal;
    }

    if(comPosition[1] > 9){
        comPosition[1] -= 5;
    }
    else if(comPosition[1] < 0){
        comPosition[1] += 5;
    }

    if(comPosition[2] > 9){
        comPosition[2] -= 5; //make sure it is within the boundaries
    }
    else if(comPosition[2] < 0){
        comPosition[2] += 5;
    }

}

void ComAggression(){

    int xVal = rand() % 5 + 1;
    int yVal = rand() % 5 + 1;
    int Distance = rand() % 3 + 1;
    int Direction = rand() % 4 + 1;

    if((comPosition[1] == playerPosition[1] + Distance) || (comPosition[1] == playerPosition[1] - Distance)){
        if(Direction == 1){
            comPosition[2] -= 1;    //if player is near computer, let computer move away or toward player
        }
        else if(Direction == 2){
            comPosition[2] += 1;
        }
        else if(Direction == 3){
            comPosition[1] -= 1;
        }
        else if(Direction == 4){
            comPosition[1] += 1;
        }
    }

    else if((comPosition[2] == playerPosition[2] + Distance) || (comPosition[2] == playerPosition[2] - Distance)){
        if(Direction == 1){
            comPosition[2] -= 1;
        }                                 //check Y axis for player
        else if(Direction == 2){
            comPosition[2] += 1;
        }
        else if(Direction == 3){
            comPosition[1] -= 1;
        }
        else if(Direction == 4){
            comPosition[1] += 1;
        }
    }

}

void comMove(){

    int xVal = rand() % 5 + 1;
    int yVal = rand() % 5 + 1;

    if(playerPosition[1] <= 5){
        comPosition[1] -= xVal;  //allow computer to move depending on player position on X axis
        comPosition[2] += yVal;

        comEdgeCheck(); //perform both checks
        ComAggression();
    }
    else if(playerPosition[1] > 5){
        comPosition[1] += xVal;
        comPosition[2] += yVal;

        comEdgeCheck();       //perform both checks
        ComAggression();
    }

    if(playerPosition[2] <= 5){
        comPosition[1] += xVal; //allow computer to move depending on player position on Y axis
        comPosition[2] -= yVal;

        comEdgeCheck();    //perform both checks
        ComAggression();
    }
    else if(playerPosition[2] > 5){
        comPosition[1] += xVal;
        comPosition[2] += yVal;

        comEdgeCheck();    //perform both checks
        ComAggression();
    }
}

void movePlayer()
{
    int i;
    do
    {
        grid();
        cout << "You have " << movesLeft << " moves left" << endl;
        cout << "Select an option: " << endl;
        cout << "1. UP" << endl;
        cout << "2. DOWN" << endl;
        cout << "3. LEFT" << endl;
        cout << "4. RIGHT" << endl;
        cout << "5. END TURN" << endl;
        cin >> i;
    } while(checkMove(i) == false && i < 6);

    if(i == 1)
    {
        playerPosition[2] -= 1;
        movesLeft -= 1;
    }
    else if(i == 2)
    {
        playerPosition[2] += 1;
        movesLeft -= 1;
    }
    else if(i == 3)
    {
        playerPosition[1] -= 1;
        movesLeft -= 1;
    }
    else if(i == 4)
    {
        playerPosition[1] += 1;
        movesLeft -= 1;
    }
    else if(i == 5)
    {
        movesLeft = 3;
        comMove(); //after player turn, make computer turn
    }

    if (movesLeft == 0)
    {
        movesLeft = 3;
        comMove();  //after player turn, make computer turn
    }
}

void gameOver()
{      
    int num = rand() % 25 + 15;
    
    grid();
    cout << "Game Over!" << endl;
    cout << "Player " << num << endl;
    
    
    sqlite::sqlite db( "CharactersV2.db" );    // open database

    auto cur = db.get_statement();            // create query
    cur->set_sql( "SELECT * FROM MovesTaken;" );
    cur->prepare();                            // run query
    
    cur->step();
    
    
}

void playGame()
{

    playerPosition[1] = 0;
    playerPosition[2] = 5;
    comPosition[1] = 3;
    comPosition[2] = 4;

    while(playing)
    {
    movePlayer();
    playing = checkAttack();
    }

    gameOver();
}

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
            //return true;
            playGame();
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

int main()
{
    mainMenu();
    return 0;
}

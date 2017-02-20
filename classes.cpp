#include <iostream>
using namespace std;

class Ranged {   
   private:
        int health = 80
        int movement = 5 
}

class Meele {
    private:
        int health = 100
        int movement = 5
}

class Knight: Meele {
    private:
        int Attack = 10
        int Defence = 8
}

class Berserker: Meele {
    private:
        int Attack = 12
        int Defence = 5
}

class Templar: Meele {
    private:
        int Attack = 8
        int Defence = 12
}

class Mage: Ranged {
    private:
        int Attack = 10
        int Defence = 0
}

class Archer: Ranged {
    private:
        int Attack = 3
        int Defence = 10
}

class CrossbowMan: Ranged {
    private:
        int Attack = 6
        int Defence = 7
}

int main()

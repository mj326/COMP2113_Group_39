#include <iostream>
#include <string>
#include <cctype>
#include "game.h"
#include "card.h"
#include "player.h"
using namespace std;

int main()
{
    Blackjack BJ;
    string menu;

    cout << "-----------------------------Welcome To BlackJack-----------------------------" << endl;
    cout << endl;

    while(1)
    {
        BJ.intro();

            cin >> menu;
            cin.ignore();

            if (menu == "R" || menu == "r") //if the input for menu is "R" or "r", BJ.addPlayer executed
            {
                BJ.addPlayer();
            }
            else if (menu == "G" || menu == "g") //if the input for menu is "G" or "g", BJ.startGame executed
            {
                BJ.startGame();
            }
            else if (menu == "I" || menu == "i") //if the input for menu is "I" or "i", BJ.PrintLicense executed
            {
                BJ.printLicense();
            }
            else if (menu == "E" || menu == "e") //if the input for menu is "E" or "e", BJ.exit executed and the loop is broken
            {
                BJ.exit();
                break;
            }
            else
            {
                cout << endl;
                cout << "Please enter again." << endl; //else "Please enter again." is printed
                cout << endl;
                cin.clear();
            }
        }
    return 0;
}

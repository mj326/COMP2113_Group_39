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

            if (menu == "R" || menu == "r")
            {
                BJ.addPlayer();
            }
            else if (menu == "G" || menu == "g")
            {
                BJ.startGame();
            }
            else if (menu == "I" || menu == "i")
            {
                BJ.printLicense();
            }
            else if (menu == "E" || menu == "e")
            {
                BJ.exit();
                break;
            }
            else
            {
                cout << endl;
                cout << "Please enter again." << endl;
                cout << endl;
                cin.clear();
            }
        }
    return 0;
}

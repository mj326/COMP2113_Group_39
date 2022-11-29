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

    cout << "----------------------------------Welcome To BlackJack----------------------------------" << endl;
    cout << endl;

    while(1)
    {
        BJ.showIntro();

        try
        {
            cin >> menu;
            cin.ignore();

            if ((menu.size() > 1) || (isalpha(menu[0] == 0)))
            {
                throw menu;
            }

            if ((menu.compare("R")==0) || (menu.compare("r") == 0))
            {
                BJ.addPlayer();
            }            
            else if ((menu.compare("G")==0) || (menu.compare("g") == 0))
            {
                BJ.startGame();
            }
            else if ((menu.compare("I")==0) || (menu.compare("i") == 0))
            {
                BJ.printLicense();
            }
            else if ((menu.compare("E")==0) || (menu.compare("e") == 0))
            {
                BJ.exit();
                break;
            }
            else 
            {
                continue;
            }
            break;
        }
        catch(string warning)
        {   
            cout << endl;
            cout << "Please try again." << endl;
            cout << endl;
            cin.clear();
        }
    }
return 0;
}

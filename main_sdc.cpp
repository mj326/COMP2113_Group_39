#include <iostream>
#include <string>
#include <cctype>
#include "game.h"
#include "card.h"
#include "player.h"
using namespace std;

int main()
{
    BlackJack BJ;
    string menu;

    cout << "----------------------------------Welcome To BlackJack----------------------------------" << endl;
    cout << endl;

    while(1)
    {
        BJ.showintro();

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
                BJ.addNewPlayer();
            }            
            else if ((menu.compare("G")==0) || (menu.compare("g") == 0))
            {
                BJ.startGame();
            }
            else if ((menu.compare("I")==0) || (menu.compare("i") == 0))
            {
                BJ.showlicense();
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
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

//    while(1)
//    {
//        // 메뉴 첫화면 출력
//        BJ.intro();
//
//        try{
//            // 메뉴 선택
//            cin>>menu;
//            cin.ignore();
//
//            if(menu.size() > 1 || !isalpha(menu[0]))
//                throw menu;
//
//            char cstr[2];
//            strcpy(cstr,menu.c_str());
//
//            switch (cstr[0]) {
//                case 'R': // 새로운 플레이어 등록
//                case 'r': // 새로운 플레이어 등록
//                    BJ.addPlayer();
//                    continue;
//                case 'G': // 기존 플레이어 시작
//                case 'g': // 기존 플레이어 시작
//                    BJ.startGame();
//                    continue;
//                case 'I':
//                case 'i':
//                    BJ.printLicense();
//                    continue;
//                case 'E': // 게임 종료하기
//                case 'e': // 게임 종료하기
//                    BJ.exit();
//                    break;
//                default:
//                    continue;
//            }
//            break;
//        }
//        catch(string exception)
//        {
//            cout<<"Please Try Again."<<endl;
//            cin.clear();
//        }
//    }
//    return 0;

    while(1)
    {
        BJ.intro();

            cin >> menu;
            cin.ignore();

            if (menu == "R" || menu == "r")
            {
                BJ.addPlayer();
            }
            if (menu == "G" || menu == "g")
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

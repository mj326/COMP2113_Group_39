#include <iostream>
using namespace std;

int main()
{
	//BlackJack BJ;
	string menu;
	
	cout<<"--------------- Welcome to BlackJACK ---------------"<<endl;
	cout<<endl;
	while(1)
	{
		//BJ.showIntro();

		try{
			// 메뉴 선택
			cin>>menu;
			cin.ignore();
			
			if(menu.size() > 1 || !isalpha(menu[0]))
				throw menu;
			
			char cstr[2];
			strcpy(cstr,menu.c_str());
			
			switch (cstr[0]) {
				case 'G': // 기존 플레이어 시작
				case 'g': // 기존 플레이어 시작
					//BJ.startGame();
					continue;
				case 'C': // 기존 플레이어 돈 충전하기
				case 'c': // 기존 플레이어 돈 충전하기
					//BJ.fillUp();
					continue;
				case 'I':
				case 'i':
					//BJ.showLicence();
					continue;
				case 'E': // 게임 종료하기
				case 'e': // 게임 종료하기
					//BJ.exit();
					break;
				default:
					continue;
			}
			break;
		}
		catch(string exception)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
	return 0;
}
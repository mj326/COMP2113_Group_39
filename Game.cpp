#include "Game.h"

using namespace std;

void printLine()
{
	cout<<"-----------------------------------------------------------------"<<endl;
}


Game::Game()
{
	loadPlayers();// 게임 시작 시 players.txt에서 플레이어 목록 로딩
}

Game::~Game()
{
	storePlayers();// 게임 종료 시 players.txt에 플레이어 목록 저장
}

// 완성
void Game::storePlayers()
{
	ofstream fout;
	fout.open("players.txt");
	
	sort(Players.begin(), Players.end(), cmpNum);
	fout << Players.size() << endl;
	
	
	for(int i = 0; i < Players.size(); i++ )
	{
		fout<<Players[i].getNum()<<" "<<Players[i].getName()<<" "<<Players[i].getBalance()<<endl;
	}
	fout.close();
}

// 완성)게임 첫 화면 출력
void Game::showIntro()
{
	/*
	 먼저 loadPlayers() 통해서 players.txt로부터 Players 로딩
	 1. 게임 시작
	    a. 딜러 카드 2개 , 플레이어 카드 2개 할당
	    b. 딜러 카드 하나 오픈, 플레이어 카드 2개 오픈
	 2. 기본 베팅 ( player.cpp에서 )
	 4. 플레이어 옵션 선택
	    a. Stand : 딜러랑 비교해서 승자 선택
        b. Hit : 카드 한 장 더 받고 , 합이 21이상이면 Burst
	 3. 라이센스 출력 혹은 게임방법 출력
	 4. 게임 종료
	 */

	printLine();

    //일단 보류
	cout<<"1. Game start"<<endl
	cout<<"2. Charge your money.(C or c)"<<endl;
	cout<<"4. Information : Who made this game.(I or i)"<<endl;
	cout<<"5. End game.(E or e)"<<endl;
	
	printLine();

    //
	cout<<"Which menu are you going to choose? : ";
}



// #2. 기존 플레이어로 게임 시작
void Game::startGame()
{
	/*
	 이 부분은 Blackjack 클래스의 멤버함수로 함
	 */
}


// 완성)#4. 기존 플레이어 게임머니 충전하기
void Game::fillUp(string playerName)
{
	/*
	 1. 메뉴 첫 화면에서 들어온 경우 : ->playerName == "" 이다.
	 이름을 입력 받아서 Players에서 검색후 이름이 있으면 충전할 금액 입력받아서 업데이트 하기
	 이름이 없으면 오류 문구 출력하고 메뉴 첫화면으로 return
	 2. 새로운 플레이어 등록, 혹은 게임 중에서 들어온 경우 : playerName != "" 이다.
	 충전할 금액 입력 받아서 Players의 end()의 잔고를 업데이트 한 후 메뉴 첫화면으로 return
	 */
	string money;
	double money_value;
	int idx;
	
	if(playerName == "")
	{
		while(true)
		{
			try {
				cout<<"Enter your name. : ";
				cin>>playerName;
				cin.ignore();
				
				for(int i = 0; i < playerName.size(); i++)
				{
					if(isalnum(playerName[i]))
						continue;
					else
						throw playerName;
				}
				
				idx = getRegisteredPlayerIdx(playerName);
				if( idx == -1 )
				{
					cout<<endl<<"Your Name ["<<playerName<<"] does not exist. "<<endl;
					throw playerName;
				}
				break;
			}
			catch (...)
			{
				
				cout<<"Please Try Again."<<endl;
				cin.clear();
			}
		}
	}
	
	idx = getRegisteredPlayerIdx(playerName);
	while(true)
	{
		try{
			
			
			cout<<"Enter the amount as you want to charge. : ";
			cin>>money;
			cin.ignore();
			int cnt = 0;
			for(int i = 0; i < money.size(); i++)
			{
				if(money[i] =='.' && cnt == 0)
				{
					cnt++;
					continue;
				}
				else if(isnumber(money[i]))
					continue;
				else
					throw money;
			}
			
			money_value = stod(money);
			if(money_value <= 0)
				throw money_value;
			
			break;
			
		}
		catch(...)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
	
	Players[idx].setBalance(money_value);
	Players[idx].showPlayerInfo(); // 업데이트 된 정보 출력
}

// 완성)#5. 라이센스 출력
void Game::printLicence()
{
	/*
	 2. 라이센스 출력
	 */
	cout<<"---------------------------------------------------"<<endl;
	cout<<"|            Contributors to this Game            |"<<endl;
	cout<<"|                                                 |"<<endl;
	cout<<"|               Kyoungmin Park                    |"<<endl;
	cout<<"|               Minjun Kim                        |"<<endl;
	cout<<"|               Dongchan Shin                     |"<<endl;
	cout<<"|               Siwoo Kim                         |"<<endl;
	cout<<"|               Yujin Kim                         |"<<endl;
	cout<<"|                                                 |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

// 완성)#6. 게임 종료
void Game::exit()
{
	/*
	 1. savePlayer() 통해서 Players를 players.txt 파일에 다시 저장하고
	 2. "Thank you for playing" 출력후
	 3. return
	 */
	savePlayers();
	cout<<"Thank you for playing BLACKJACK"<<endl;
}


Blackjack::Blackjack() : Game()
{
	player_draw = 0;
}
Blackjack::~Blackjack()
{}


// 테스트)현재 게임하는 사람 로딩 : 성공하면 true, 실패하면 false 반환
bool Blackjack::loadPlayer()
{
	string playerName;
	
	int idx;
	while(true)
	{
		try {
			cout<<"Enter your name. : ";
			cin>>playerName;
			cin.ignore();
			
			for(int i = 0; i < playerName.size(); i++)
			{
				if(isalnum(playerName[i]))
					continue;
				else
					throw playerName;
			}
			
			idx = getRegisteredPlayerIdx(playerName);
			if( idx == -1 )
			{
				cout<<endl<<"Your Name ["<<playerName<<"] does not exist. "<<endl;
				throw playerName;
			}
			break;
		}
		catch (...)
		{
			
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
	currentPlayer.setPlayer(Players[idx]);
	return true;
}

// 테스트)플레이어가 베팅하기 : 정상적으로 베팅되었으면 true 반환, 아니면 false 반환
bool Blackjack::doBetting()
{
	string input;
	double money;
	//-> Starting_Balance에 Balance를 백업하고 Balance에서 베팅금액을 뺀다.
	currentPlayer.setStartingBalance();
	
	while(true)
	{
		try{
			cout<<"How much do you want to bet? :";
			cin>>input;
			cin.ignore();
			
			for(int i = 0; i < input.size(); i++)
			{
				if(input[i] =='.' || isdigit(input[i]))
					continue;
				else
					throw input;
			}
			money = stod(input);
			if(currentPlayer.canBet(money))
			{
				currentPlayer.plusBet(money); // 베팅금액을 덮어씌우는게 아니라 더해야 함.
				currentPlayer.showPlayerInfo();
				return true;
			}
			else
			{
				cout<<"You don't have enough money."<<endl;
				cout<<"You go to main menu."<<endl;
				return false;
			}
		}
		catch(string exception)
		{
			cout<<"Please Try Again."<<endl;
			cout<<exception<<endl;
			cin.clear();
		}
	}
}


void Blackjack::showFirstCards() // 딜러는 오픈카드만, 플레이어는 두 장의 첫 카드를 보여준다.
//카드 오픈하는 function
{
	Computer.showOpenCard();
	currentPlayer.showFirstTwoCards();
}


// 게임 시작시 두 장의 카드 받기
int Blackjack::getTwoCards()
{
	currentPlayer.drawTwoCards(deck);
	Computer.drawTwoCards(deck);
	player_draw = 1;
	
	if(Computer.isOpenCardAce())
	{
		Computer.showOpenCard();
		//			cout<<"딜러의 오픈카드 에이스"<<endl;
		if(currentPlayer.isFirstCardsBJ())
		{
			currentPlayer.showFirstTwoCards();
			//				cout<<"플레이어가 블랙잭입니다."<<endl;
			return 1;
		}
		else
		{
			currentPlayer.showFirstTwoCards();
			//				cout<<"플레이어가 블랙잭이 아닙니다."<<endl;
			return 2;
		}
		
	}
	else
	{
		Computer.showOpenCard();
		//			cout<<"딜러의 오픈카드 에이스가 아닙니다."<<endl;
		if(currentPlayer.isFirstCardsBJ())
		{
			currentPlayer.showFirstTwoCards();
			//				cout<<"플레이어가 블랙잭입니다."<<endl;
			return 3;
		}
		else
		{
			currentPlayer.showFirstTwoCards();
			//				cout<<"플레이어가 블랙잭이 아닙니다."<<endl;
			return 4;
		}
	}
}

// 플레이어가 어떤 일할지 메뉴 출력하기
void Blackjack::showPlayerWhatToDo()
{
	/*
	 1. STAY 2. HIT
	 */
	cout<<"What do you want to do?"<<endl;
	printLine();
	
	cout<<"1. Stay.(S or s)"<<endl;
	cout<<"2. Hit.(H or h)"<<endl;

	printLine();
}

// 플레이어 턴에 할일 : 블랙잭이나 버스트가 아닐 경우
int Blackjack::doPlayerTurn()
{/*
  * 플레이어 할일 :(플레이어가 블랙잭인 경우는 이미 다뤄졌음)
  ** 메뉴를 출력한다. -> 메뉴를 선택한다.
  (1) STAY -> turn을 딜러로 넘긴다.
  (2) HIT -> 추가 카드를 받는다. -> 추가 카드를 출력한다.
  (a) 합이 22 이상이다 -> 베팅금액 잃고 게임 끝(5)
  (b) 합이 21 이하이다 -> 1)로 간다. ->SURRENDER 비활성화
  (3) DOUBLEDOWN -> 추가 카드를 받고 베팅금액이 2배가 된다.(Balance에서 베팅금액 한 번 더 빠짐) -> 추가 카드를 출력한다.
  (a) 합이 22 이상이다 -> 모든 베팅금액 잃고 게임 끝(5)
  (b) 합이 21 이하이다 -> turn을 딜러로 넘긴다.
  (4) SURRENDER -> 베팅금액의 1/2만 다시 Balance에 충전되고 게임 끝(6)
  */
	
	char response;
	int result = -1;
	while(true)
	{
		try{
			showPlayerWhatToDo();
			// 메뉴 선택
			cin>>response;
			cin.ignore();
			
			if(!isalpha(response))
				throw response;
			
			if(player_draw == 1)
			{
				switch (response) {
                    // STAY
                    case 'S':
                    case 's':
                        result = 1; // STAY
                        break;
                        // HIT
                    case 'H':
                    case 'h':
                        currentPlayer.drawACard(deck);
                        player_draw++;
                        currentPlayer.showHand();
                        if (currentPlayer.getCardSum() > 21) {
                            result = 5; // BURST
                            break;
                        } else {
                            continue;
                        }

                }
			else
			{
				switch (response) {
						// STAY
					case 'S':
					case 's':
						result = 1; // STAY
						break;
						// HIT
					case 'H':
					case 'h':
						currentPlayer.drawACard(deck);
						player_draw++;
						currentPlayer.showHand();
						if(currentPlayer.getCardSum() > 21)
						{
							result = 5; // BURST
							break;
						}
						else
						{
							continue;
						}
					default:
						continue;
				}
			}
			break;
		}
		catch(char exception)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
	return result;
}

// 딜러 턴에 할 일 : 플레이어가 할일 다 한 경우
int Blackjack::doDealerTurn()
{
	int result = -1;
	
	Computer.showHand();
	if(Computer.isFirstCardsBJ())
		return 7;
	bool cont = true;
	while(cont)
	{
		
		int sum = Computer.getCardSum();
		if(sum <= 16)
		{
			Computer.drawACard(deck);
			Computer.showHand();
			cont = true;
		}
		else if(sum >= 22)
		{
			cont = false;
			cout<<"Dealer burst!"<<endl;
			result = 2; // 딜러가 졌음
		}
		else
		{
			cont = false;
			if(currentPlayer == Computer)// 카드합 : 플레이어 == 딜러
				result = 3; // 플레이어와 딜러 비김
			else if(currentPlayer > Computer) // 카드합 : 플레이어 > 딜러
				result = 2; // 딜러가 졌음
			else // 카드합 : 플레이어 < 딜러
				result = 5; // 플레이어가 졌음
		}
	}
	return result;
}


// 어떤 케이스냐에 따라 처리하는 결과가 달라짐
void Blackjack::getResult(int result)
{
	/*
	 1 -> 플레이어가 BLACKJACK인 경우 : 베팅금액 + 베팅금액 * 1.5를 돌려받기
	 2 -> 플레이어가 win한 경우 : 베팅금액 + 베팅금액을 돌려받기
	 3 -> push 인 경우 : 베팅금액을 돌려받기
	 4 -> 인슈런스 성공인 경우 : 인슈런스 금액 + 인슈런스 금액 * 2를 돌려받기
	 5 -> 모든 실패의 경우 : 그냥 끝
	 6 -> 플레이어가 SURREND한 경우 : 베팅금액의 1/2를 돌려받기
	 
	 */
	int bet = currentPlayer.getBet();
	int insurance = currentPlayer.getInsurance();
	switch (result) {
		case 1:
			cout<<"BLACK JACK!"<<endl;
			currentPlayer.setBalance(bet + bet * 1.5);
			break;
			
		case 2:
			cout<<"You Win!"<<endl;
			currentPlayer.setBalance(bet + bet);
			break;
			
		case 3:
			cout<<"Push!"<<endl;
			currentPlayer.setBalance(bet);
			break;
			
		case 4:
			cout<<"Insuranse hit!"<<endl;
			currentPlayer.setBalance(insurance + insurance * 2);
			break;
			
		case 5:
			cout<<"You Fail!"<<endl;
			break;
			
		case 6:
			cout<<"You Surrender!"<<endl;
			currentPlayer.setBalance(bet * 0.5);
			break;
			
			
		default:
			break;
	}
}


bool Blackjack::wannaEvenMoney()
{
	cout<<"Do you want to Even money?(Y/N) :";
	char response;
	while(true)
	{
		try{
			// 메뉴 선택
			cin>>response;
			cin.ignore();
			
			if(!isalpha(response))
				throw response;
			
			switch (response) {
				case 'Y':
				case 'y':
					return true;
				case 'N':
				case 'n':
					return false;
				default:
					continue;
			}
			break;
		}
		catch(char exception)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
}

bool Blackjack::wannaInsurance()
{
	cout<<"Do you want to Insurance?(Y/N) :";
	char response;
	while(true)
	{
		try{
			// 메뉴 선택
			cin>>response;
			cin.ignore();
			
			if(!isalpha(response))
				throw response;
			
			switch (response) {
				case 'Y':
				case 'y':
					if(currentPlayer.canBet(currentPlayer.getBet() / 2)) // 추가적으로 베팅금의 반만큼 베팅 할 수 있나?
					{
						currentPlayer.setInsurance(currentPlayer.getBet() / 2);
						return true;
					}
					else
					{
						cout<<"You don't have enough money.";
						return false;
					}
				case 'N':
				case 'n':
					return false;
				default:
					continue;
			}
			break;
		}
		catch(char exception)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
}

bool Blackjack::wannaRestart()
{
	cout<<"Do you want to restart the Game?(Y/N) :";
	char response;
	while(true)
	{
		try{
			// 메뉴 선택
			cin>>response;
			cin.ignore();
			
			if(!isalpha(response))
				throw response;
			
			switch (response) {
				case 'Y':
				case 'y':
					return true;
				case 'N':
				case 'n':
					return false;
				default:
					continue;
			}
			break;
		}
		catch(char exception)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
}

bool Blackjack::wannaNextStage()
{
	cout<<"Continue?(Y) :";
	char response;
	while(true)
	{
		try{
			// 메뉴 선택
			cin>>response;
			cin.ignore();
			
			if(!isalpha(response))
				throw response;
			
			switch (response) {
				case 'Y':
				case 'y':
					return true;
				default:
					continue;
			}
			break;
		}
		catch(char exception)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
}

void Blackjack::startGame()
{
	/*
	 1. 카드를 섞는다.
	 2. 플레이어가 베팅을 한다. -> Starting_Balance에 Balance를 백업하고 Balance에서 베팅금액을 뺀다.
	 3. 플레이어가 카드 1장 받고 딜러가 히든카드 1장 받는다. 그리고 다시 플레이어, 딜러 각각 1장씩 받는다.
	 4. 각 패를 보여준다.
	 5. 만약, 딜러의 오픈 카드가 에이스다. :
	 1) 플레이어는 블랙잭이다. -> 이븐머니 여부를 묻는다.
	 (1) 이븐머니 한다 -> 딜러의 히든카드를 보여준다.
	 (a) 딜러가 블랙잭 여부 상관없이 -> 베팅금액 + 베팅금액(승리수당)을 받는다. -> 게임 끝(2)
	 (2) 이븐머니 하지 않는다. -> 딜러의 히든카드를 보여준다.
	 (a) 딜러가 블랙잭이다. -> push이므로(비겼으므로) 베팅금액만을 그대로 다시 돌려 받는다. -> 게임 끝(3)
	 (b) 딜러가 블랙잭이 아니다. -> 베팅금액 + 베팅금액*1.5를 받는다. -> 게임 끝(1)
	 2) 플레이어가 블랙잭이 아니다. ->인슈런스 여부를 묻는다.
	 (1) 인슈런스를 한다 -> (베팅액의 절반을 Balance에서 뺀다.) -> 플레이어 할일 한다. -> 딜러의 히든카드를 보여준다.
	 (a) 딜러가 블랙잭이다. -> 보험금 + 보험금*2 를 받는다. -> 게임 끝(4)
	 (b) 딜러가 블랙잭이 아니다. -> 보험금은 잃고 딜러가 할일 한다.-> 결과에 따라 계산한다. -> 게임 끝
	 (2) 인슈런스를 하지않는다. -> 플레이어 할일 한다. -> 딜러의 히든카드를 보여준다.
	 (a) 딜러가 블랙잭이다. -> 베팅금액을 잃는다. -> 게임 끝(5)
	 (b) 딜러가 블랙잭이 아니다. -> 딜러가 할일 한다. -> 결과에 따라 계산한다. -> 게임 끝
	 - 딜러의 오픈카드가 에이스가 아니다. :
	 1) 플레이어는 블랙잭이다.
	 (1) 딜러도 블랙잭이다.(21) -> push이므로(비겼으므로) 베팅금액만을 그대로 다시 돌려 받는다. -> 게임 끝(3)
	 (2) 딜러는 블랙잭이 아니다 -> 딜러가 할일한다. -> 결과에 따라 계산한다. -> 게임 끝
	 2) 플레이어가 블랙잭이 아니다.
	 (1) 플레이어가 할일 한후
	 (a) 결과가 1인 경우
	 > 딜러는 블랙잭이다.(21) -> 딜러가 이겼다. -> 게임 끝
	 > 딜러가 블랙잭이 아니다.
	 > 딜러가 할일 한후 ->  결과에 따라 처리 -> 게임 끝
	 (b) 결과가 5혹은 6인 경우 -> 게임 종료(5)
	 
	 6. 게임끝이면 다시 게임할건지 묻는다.
	 1) 다시 할거다. -> 1.로 간다.
	 2) 끝낸다. -> 지금까지의 게임 결과 출력하고 updatePlayer()로 currentPlayer를 Players에 업데이트한 후 return
	 
	 * 플레이어 할일 :(플레이어가 블랙잭인 경우는 이미 다뤄졌음)
	 ** 메뉴를 출력한다. -> 메뉴를 선택한다.
	 (1) STAY -> turn을 딜러로 넘긴다.
	 (2) HIT -> 추가 카드를 받는다. -> 추가 카드를 출력한다.
	 (a) 합이 22 이상이다 -> 베팅금액 잃고 게임 끝(5)
	 (b) 합이 21 이하이다 -> 1)로 간다. ->SURRENDER 비활성화
	 (3) DOUBLEDOWN -> 추가 카드를 받고 베팅금액이 2배가 된다.(Balance에서 베팅금액 한 번 더 빠짐) -> 추가 카드를 출력한다.
	 (a) 합이 22 이상이다 -> 모든 베팅금액 잃고 게임 끝(5)
	 (b) 합이 21 이하이다 -> turn을 딜러로 넘긴다.
	 (4) SURRENDER -> 베팅금액의 1/2만 다시 Balance에 충전되고 게임 끝(6)
	 
	 * 딜러가 할일 :(딜러의 오픈카드가 에이스인 경우, 딜러가 블랙잭인 경우는 이미 다뤄졌음)
	 ** 히든카드를 출력한다.
	 (1) 합이 16 이하다. -> 추가 카드를 획득한다. -> 추가 카드를 출력한다. -> 다시 분기로 이동
	 (2) 합이 22 이상이다. -> 딜러가 버스트했으므로 플레이어는 베팅금액 + 베팅금액을 받는다. -> 게임 끝(2)
	 (3) 합이 21 이하이다. -> 플레이어의 카드 합과 비교한다.
	 (a) 플레이어가 합이 더 크다. -> 플레이어가 이겼으므로 베팅금액 + 베팅금액을 받는다. -> 게임 끝(2)
	 (b) 딜러가 합이 더 크다. -> 플레이어는 베팅금액을 잃는다. -> 게임 끝(5)
	 (c) 합이 같다. -> push이므로 베팅금액만 그대로 돌려받는다. -> 게임 끝(3)
	 */
	
	bool cont;
	if(loadPlayer()) // 이름 입력 받아서 플레이어 정보를 로딩한다.
		cont = true;
	else
	{
		cont = false;
		return;
	}
	
	while(cont)
	{
		deck.init(); // 52장 카드로 초기화한다.
		deck.shuffleDeck(); // 덱의 카드들을 섞는다.
		
		currentPlayer.initGame(); // 카드와 베팅금액을 비운다.
		Computer.initGame(); // 카드를 비운다.
		player_draw = 0;
		if(!doBetting()) // player는 베팅을 한다.
			break;
		
		int first_result = getTwoCards();
		
		//			showFirstCards();
		int after_player, after_dealer;
		
		switch (first_result)
		{
			  //히트랑 스테이
				else // 인슈런스 하지 않겠다.
				{
					printf("You didn't choose to put insurance. \n");
					after_player = doPlayerTurn();
					if(after_player == 1) // 플레이어가 stay해서 비교해야함
					{
						if(Computer.isFirstCardsBJ()) // 딜러가 블랙잭이면
						{
							Computer.showHand(); // 딜러의 히든 카드를 보여줌
							getResult(5); // 5번 결과로 처리
						}
						else
						{
							after_dealer = doDealerTurn();
							getResult(after_dealer);
						}
					}
					else
					{
						Computer.showHand(); // 딜러의 히든 카드를 보여줌
						getResult(after_player);
					}
				}
				break;
			case 3:
				wannaNextStage();
				after_dealer = doDealerTurn();
				if(after_dealer == 7)
				{
					getResult(3);
				}
				else
				{
					getResult(1);
				}
				break;
			case 4:
				after_player = doPlayerTurn();
				if(after_player == 1)
				{
					after_dealer = doDealerTurn();
					if(after_dealer == 7)
					{
						getResult(5);
					}
					else
					{
						getResult(after_dealer);
					}
				}
				else
				{
					Computer.showHand(); // 딜러의 히든 카드를 보여줌
					getResult(after_player);
				}
				break;
			default:
				break;
		}
		
		
		if(wannaRestart())
		{
			cont = true;
			cout<<endl;
			cout<<"Let's do it again!"<<endl;
			cout<<endl;
		}
		else
			cont = false;
	}
	updatePlayer();
}

// Players에 이번 플레이어의 정보 업데이트
void Blackjack::updatePlayer()
{
	int idx = getRegisteredPlayerIdx(currentPlayer.getName());
	Players[idx].setPlayer(currentPlayer);
}
#include "game.h"

using namespace std;

void printLine()
{
	cout<<"---------------------------------------------------------------"<<endl;
}


Game::Game() {}

Game::~Game()
{
	savePlayer();// 게임 종료 시 players.txt에 플레이어 목록 저장
}

void Game::loadPlayer()
{
	ifstream fin;
	fin.open("players.txt");

	int numofplayers;
	fin >> numofplayers;
	
	int num;
	string playerName;
	double balance;
	
	for(int i = 0; i < numofplayers; i++ )
	{
		fin>>num>>playerName>>balance;
		Players.push_back(Player(num, playerName, balance));
	}
	fin.close();
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
	 1. 새로운 플레이어 등록
	 2. 기존 플레이어로 게임 시작
	 3. 잔고 기준 플레이어 랭킹 출력
	 4. 기존 플레이어 게임머니 충전하기
	 5. 라이센스 출력 혹은 게임방법 출력
	 6. 게임 종료
	 */

	printLine();
	
	cout<<"1. Register new Player.(R or r)"<<endl;
	cout<<"2. Game start if you have registered.(G or g)"<<endl;
	cout<<"3. Show players status.(S or s)"<<endl;
	cout<<"4. Charge your money.(C or c)"<<endl;
	cout<<"5. Information : Who made this game.(I or i)"<<endl;
	cout<<"6. End game.(E or e)"<<endl;
	
	printLine();
	
	cout<<"Which menu are you going to choose? : ";
}


// 완성)#1. 새로운 플레이어 등록
void Game::addNewPlayer()
{
	/*
	 1. 이름 입력
	 2. ->입력한 이름이 이미 있는 이름이면 메뉴 첫화면으로 return
	 3. ->입력한 이름이 없으면 이름 입력 받고 그 이름으로 fillUp() 호출해 게임머니 충전하고 메뉴 첫화면으로 return
	 */
	string playerName;
	
	while(true)
	{
		try{
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
				Player newPlayer((unsigned int)Players.size(), playerName, 0);
				Players.push_back(newPlayer);
				fillUp(playerName);
				return;
			
		}
		catch(...)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
}


// #2. 기존 플레이어로 게임 시작
void Game::startGame()
{
	/*
	 이 부분은 Blackjack 클래스의 멤버함수로 함
	 */
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
	cout<<"|               KyoungMin Park                    |"<<endl;
	cout<<"|               MinJun Kim                        |"<<endl;
	cout<<"|               DongChan Shin                     |"<<endl;
	cout<<"|               SiWoo Kim                         |"<<endl;
	cout<<"|               Yoojin Kang                        |"<<endl;
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
	savePlayer();
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
	string money_s;
	double money;
	// Update Starting balance.
	// Subtract betting amount from Balance.
	currentPlayer.setStartingBalance();
	
	while(true)
	{
		try {
			cout << "How much do you want to bet? :";
			cin >> money_s;
			cin.ignore();
			
			for(int i = 0; i < money_s.size(); i++)
			{
				if(money_s[i] == '.' || isdigit(money_s[i]))
					continue;
				else
					throw money_s;
			}
			money = stod(money_s);
			if (currentPlayer.canBet(money))
			{
				currentPlayer.plusBet(money); // 베팅금액을 덮어씌우는게 아니라 더해야 함.
				currentPlayer.showPlayerInfo();
				return true;
			}
			else
			{
				cout << "Not enough money!" << endl;
				cout << "You Lose" << endl;
				return false;
			}
		}
		catch(string wrong)
		{
			cout << "Please enter again" << endl;
			cout << wrong << endl;
			cin.clear();
		}
	}
}

void Blackjack::showFirstCards() // 딜러는 오픈카드만, 플레이어는 두 장의 첫 카드를 보여준다.
{
	Computer.showOpenCard();
	currentPlayer.showFirstTwoCards();
}


//다시 수정 -> 민준
// 게임 시작시 두 장의 카드 받기
int Blackjack::getTwoCards()
{
	currentPlayer.drawTwoCards(deck);
	Computer.drawTwoCards(deck);
	player_draw = 1;
	
	if(Computer.isOpenCardAce())
	{
		Computer.showOpenCard();
		if(currentPlayer.isFirstCardsBJ())
		{
			currentPlayer.showFirstTwoCards();
			cout << "Player is BlackJack" << endl;
			return 1;
		}
		else
		{
			currentPlayer.showFirstTwoCards();
			cout << "Player is not BlackJack" << endl;
			return 2;
		}
		
	}
	else
	{
		Computer.showOpenCard();
		if(currentPlayer.isFirstCardsBJ())
		{
			currentPlayer.showFirstTwoCards();
			cout << "Player is BlackJack" << endl;
			return 3;
		}
		else
		{
			currentPlayer.showFirstTwoCards();
			cout << "Player is not BlackJack" << endl;
			return 4;
		}
	}
}

// Print choices for player
void Blackjack::showPlayerChoices()
{
	/*
	 1. STAY 2. HIT 3. DOUBLEDOWN 4. SURRENDER(2번째부터는 비활성화)
	 */
	cout<<"What do you want to do?"<<endl;
	printLine();
	
	cout<<"1. Stay.(S or s)"<<endl;
	cout<<"2. Hit.(H or h)"<<endl;
//	if(player_draw == 1)
//	{
//		cout<<"3. Double down.(D or d)"<<endl;
//		cout<<"4. Surrender. (G or g)"<<endl;
//	}
//	printLine();
}

// 플레이어 턴에 할일 : 블랙잭이나 버스트가 아닐 경우
int Blackjack::playerTurn()
{/*
  * 플레이어 할일 :(플레이어가 블랙잭인 경우는 이미 다뤄졌음)
  ** Print choices -> choose
  (1) STAY -> Dealer's Turn.
  (2) HIT -> Draw another card. -> Print the drawn card.
  	(a) Sum > 22 -> Lose round
  	(b) Sum <= 21 -> go to 1)
  */
	
	char input;
	int result = -1;
	while(true)
	{
		try{
			showPlayerChoices();
			// Choose
			cin >> input;
			cin.ignore();
			
			if(!isalpha(input))
				throw input;
			
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
						if(currentPlayer.getCardSum() > 21)
						{
							result = 5; // BURST
							break;
						}
						else
						{
							continue;
						}
						

			}
			else
			{
				switch (response) {
						// STAY
					case 'S':
					case 's':
						result = 1; // Stay
						break;
					// Hit
					case 'H':
					case 'h':
						currentPlayer.drawACard(deck);
						player_draw++;
						currentPlayer.showHand();
						if(currentPlayer.getCardSum() > 21)
						{
							result = 5; // Lose round
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
			cout << "Please Enter Again" << endl;
			cin.clear();
		}
	}
	return result;
}

// 딜러 턴에 할 일 : 플레이어가 할일 다 한 경우
int Blackjack::dealerTurn()
{
	int result = -1;
	
	Computer.showHand();
	if(Computer.isFirstCardsBJ())
		return 7;
	bool dealer = true;
	while(dealer)
	{
		
		int dealerSum = Computer.getCardSum();
		if(dealerSum <= 16)
		{
			Computer.drawACard(deck);
			Computer.showHand();
			dealer = true;
		}
		else if(dealerSum >= 22)
		{
			dealer = false;
			cout << "Dealer burst!" << endl;
			result = 2; // Dealer lose
		}
		else
		{
			dealer = false;
			if(currentPlayer == Computer)// Sum = Player == Dealer
				result = 3; // Draw
			else if(currentPlayer > Computer) // Sum = Player > Dealer
				result = 2; // Dealer lose
			else // Sum = Player < Dealer
				result = 5; // Player wins
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
	switch (result) {
		case 1:
			cout << "BLACKJACK!" << endl;
			currentPlayer.setBalance(bet + bet * 1.5);
			break;
			
		case 2:
			cout<<"You Win!"<<endl;
			currentPlayer.setBalance(bet + bet);
			break;
			
		case 3:
			cout << "Push!" << endl;
			currentPlayer.setBalance(bet);
			break;

		case 4:
			cout << "You Fail!" << endl;
			break;
			
		case 5:
			cout << "You Surrender!" << endl;
			currentPlayer.setBalance(bet * 0.5);
			break;
			
			
		default:
			break;
	}
}

bool Blackjack::nextRound()
{
	cout<<"Continue? (Y) :";
	char response;
	while(true)
	{
		try{
			// 메뉴 선택
			cin >> response;
			cin.ignore();
			
			if(!isalpha(response))
				throw response;
			
			switch (response)
			{
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
			cout << "Please Enter Again" << endl;
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
	 5. 딜러의 오픈카드가 에이스가 아니다. :
	 1) 플레이어는 블랙잭이다.
		(a) 딜러도 블랙잭이다. -> push이므로(비겼으므로) 베팅금액만을 그대로 다시 돌려 받는다. -> 게임 끝(3)
		(b) 딜러는 블랙잭이 아니다 -> 딜러가 할일한다. -> 결과에 따라 계산한다. -> 게임 끝
	 2) 플레이어가 블랙잭이 아니다.
		(a) 플레이어가 할일 한후
			(i) 결과가 1인 경우
	 			> 딜러는 블랙잭이다.(21) -> 딜러가 이겼다. -> 게임 끝
	 			> 딜러가 블랙잭이 아니다.
	 			> 딜러가 할일 한후 ->  결과에 따라 처리 -> 게임 끝
	 		(ii) 결과가 5혹은 6인 경우 -> 게임 종료(5)
	 
	 6. 게임끝이면 다시 게임할건지 묻는다.
	 1) 다시 할거다. -> 1.로 간다.
	 2) 끝낸다. -> 지금까지의 게임 결과 출력하고 updatePlayer()로 currentPlayer를 Players에 업데이트한 후 return
	 
	 * 플레이어 할일 :(플레이어가 블랙잭인 경우는 이미 다뤄졌음)
	 ** 메뉴를 출력한다. -> 메뉴를 선택한다.
	 (1) Stay -> turn을 딜러로 넘긴다.
	 (2) Hit -> 추가 카드를 받는다. -> 추가 카드를 출력한다.
	 (a) 합이 22 이상이다 -> 베팅금액 잃고 게임 끝(5)
	 (b) 합이 21 이하이다 -> 1)로 간다. ->SURRENDER 비활성화
	 
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
		// add new player
		return;
	}
	
	while(cont)
	{
		deck.init(); // 52장 카드로 초기화한다.
		deck.shuffleDeck(); // shuffle the deck
		
		currentPlayer.initGame(); // 카드와 베팅금액을 비운다.
		Computer.initGame(); // 카드를 비운다.
		player_draw = 0;
		if(!doBetting()) // player는 베팅을 한다.
			break;
		
		int first_result = getTwoCards();
		
		showInitialCards();
		int after_player, after_dealer;
		
		switch (first_result)
		{
			case 1:
				nextRound();
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
			case 2:
				after_player = playerTurn();
				if(after_player == 1)
				{
					after_dealer = dealerTurn();
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
					Computer.showHand(); // Show dealer's hidden card
					getResult(after_player);
				}
				break;
			default:
				break;
		}
		
		if(restart())
		{
			cont = true;
			cout << endl;
			cout << "Let's play again!" << endl;
			cout << endl;
		}
		else
			cont = false;
	}
}

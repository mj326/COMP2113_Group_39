#include "game.h"

using namespace std;

void printLine()
{
	cout<<"---------------------------------------------------"<<endl;
}


Game::Game() {}

Game::~Game()
{
	storePlayers(); // 게임 종료 시 players.txt에 플레이어 목록 저장
}

//
void Game::storePlayers()
{
	ofstream fout;
	fout.open("players.txt");

	for(int i = 0; i < Players.size(); i++ )
	{
		fout << " " << Players[i].getName() << " " << Players[i].getBalance() << endl;
	}
	fout.close();
}

// Show Intro
void Game::intro()
{
	/*
	 1. The user has to register his name before he begins playing the game
	 2. 기존 플레이어로 게임 시작
	 3. 잔고 기준 플레이어 랭킹 출력
	 4. 기존 플레이어 게임머니 충전하기
	 5. 라이센스 출력 혹은 게임방법 출력
	 6. 게임 종료
	 */

	printLine();
	
	cout<<"1. Register your name.(R or r)"<<endl;
	cout<<"2. Game start if you have registered your name.(G or g)"<<endl;
	cout<<"3. Information : Who made this game?(I or i)"<<endl;
	cout<<"4. End game.(E or e)"<<endl;
	
	printLine();
	
	cout<<"Which menu are you going to choose? : ";
}


// Add new player
void Game::addPlayer()
{
	/*
	 1. Enter name
	 2. ->입력한 이름이 이미 있는 이름이면 메뉴 첫화면으로 return
	 3. ->입력한 이름이 없으면 이름 입력 받고 그 이름으로 fillUp() 호출해 게임머니 충전하고 메뉴 첫화면으로 return
	 */
	string playerName;
	
	while(true)
	{
		try {
			cout << "Enter your name: ";
			cin >> playerName;
			cin.ignore();
			
			for(int i = 0; i < playerName.size(); i++)
			{
				if(isalnum(playerName[i]))
					continue;
				else
					throw playerName;
			}
				PlayerInfo currentPlayer(playerName, 50);
				Players.push_back(currentPlayer);
				return;
			
		}
		catch(...)
		{
			cout<<"Please Try Again"<<endl;
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
void Game::printLicense()
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
	cout<<"|               Yoojin Kang                       |"<<endl;
	cout<<"|                                                 |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

// 완성)#6. 게임 종료
void Game::exit()
{
	/*
	 1. save the player's information in players.txt including the name and the balance
	 2. print out  "Thank you for playing"
	 3. return
	 */
	storePlayers();
	cout << "Thank you for playing BLACKJACK" << endl;
}


Blackjack::Blackjack() : Game()
{
	player_draw = 0;
}
Blackjack::~Blackjack()
{}

// Player betting : Return true if betting succeeds, else return false
bool Blackjack::doBetting()
{
	string money_s;
	double amount;

	// Update Starting balance.
	// Subtract betting amount from Balance.
	currentPlayer.setStartBal();
	
	while(true)
	{
		try {
            currentPlayer.show_info();
			cout << "Choose how much you want to bet : " << endl;
            cout << " 1) $10   2) $20   3) $30 " << endl;
			cin >> money_s;
			cin.ignore();

    		amount = stod(money_s);

			if (amount == 10 || amount == 20 || amount == 30) {
                return true;
            }
			else{

				throw money_s;
            }
			if(currentPlayer.betMoneyAvail(amount))
			{
				currentPlayer.betMoney(amount);
				return true;
			}
			else
			{
				cout<<"You don't have enough money."<<endl;
                currentPlayer.show_info();
                cout<<endl;
				cout<<"Go to main menu."<<endl;
				return false;
			}
        }
        // tell the player that he entered wrong betting amount
		catch(string wrong)
		{
			cout << endl << "Wrong input. Please enter 10, 20 or 30." << endl;
			cout << "You entered : " << wrong << endl;
            printLine();
			cin.clear();
            // return false;
		}
	}
}

// 1= BJ, 2 = not BJ
int Blackjack::getTwoCards()
{
	currentPlayer.drawTwoCards(deck);
	Computer.drawTwoCards(deck);
	player_draw = 1;

    Computer.showOpenCard();

    if(currentPlayer.isFirstCardsBJ())
    {
        cout << "[ Player is BlackJack! ]" << endl;
        return 1;
    }
    else
    {
        cout << "[ Player is not BlackJack ]" << endl;
        return 2;
    }

}


bool Blackjack::restart() //새로 시작
{
    cout<<"Do you want another round? (Y/N) : ";
    char answer;
    while(true)
    {
        try{
			// 메뉴 선택
			cin>>answer;
			cin.ignore();
			
			if(!isalpha(answer))
				throw answer;
			
			switch (answer) {
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
		catch(char wrong)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
    }
}


// Print choices for player
void Blackjack::showPlayerChoices()
{
	
	// 1. STAY 2. HIT
	cout<<"What do you want to do?"<<endl;
	printLine();
	
	cout<<"1. Stay. (S or s)"<<endl;
	cout<<"2. Hit. (H or h)"<<endl;
//	printLine();
}

// 1=Stay, 5=burst, 6=Player BJ
int Blackjack::playerTurn()
{
    /*
    * 플레이어 할일 :(플레이어가 블랙잭인 경우는 이미 다뤄졌음)
    ** Print choices -> choose
    (1) STAY -> Dealer's Turn.
    (2) HIT -> Draw another card. -> Print the drawn card.
        (a) Sum > 22 -> Lose round
        (b) Sum <= 21 -> go to 1)
    */
    currentPlayer.showHand();
    if (currentPlayer.isFirstCardsBJ())
        return 6;

    char input;
    int result = 0;
    while(true)
    {
        try{
            showPlayerChoices();   // 메뉴 선택
            cin>>input;
            cin.ignore();

            if(!isalpha(input))
                throw input;

            if(player_draw == 1)
            {
                switch (input)
                {
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
                            result = 4; // BURST
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
            else
            {
                switch (input) {
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
                            result = 4; // BURST
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


// 7=BJ 2=Dealer lose 3=Draw 5=Player wins
int Blackjack::dealerTurn() {
    int result = 0;

    Computer.showHand();
    if (Computer.isFirstCardsBJ())
        return 7;

    bool dealer = true;
    while (dealer) {

        int dealerSum = Computer.getCardSum();
        if (dealerSum <= 16) {
            Computer.drawACard(deck);
            Computer.showHand();
            dealer = true;
        }
        else if (dealerSum > 21) {
            dealer = false;
            cout << "Dealer burst!" << endl;
            result = 2; // Player Wins
        }
        else
        //dealer's card sum is less than 21 and greater than 16
        {
            dealer = false;
            if (currentPlayer == Computer)// Sum = Player == Dealer
                result = 3; // Draw
            else if (currentPlayer > Computer) // Sum = Player > Dealer
                result = 2; // Dealer wins
            else // Sum = Player < Dealer
                result = 4; // Player lose
        }
    }
    return result;
}


// 1.BJ 2.Player Win 3.Draw 4.Lose
void Blackjack::getResult(int result) {
    /*
     1 -> 플레이어가 BLACKJACK인 경우 : 베팅금액 3배를 돌려받기
     2 -> 플레이어가 win한 경우 : 베팅금액 2배 돌려받기
     3 -> draw 인 경우 : 베팅금액을 돌려받기
     4 -> lose 모든 실패의 경우 : 그냥 끝
     */

    int bet = currentPlayer.getBet();
    switch (result) {
        case 1:
            cout << "BLACKJACK!" << endl;
            currentPlayer.setBalance(bet + bet * 2);
            break;

        case 2:
            cout << "You Win!" << endl;
            currentPlayer.setBalance(bet + bet);
            break;

        case 3:
            cout << "Draw!" << endl;
            currentPlayer.setBalance(bet);
            break;

        case 4:
            cout << "You Lose!" << endl;
            break;

        default:
            break;
    }
}

bool Blackjack::nextRound() {
    cout << "Continue? (Y) :";
    char answer;
    while (true) {
        try {
            // 메뉴 선택
            cin >> answer;
            cin.ignore();

            if (!isalpha(answer))
                throw answer;

            switch (answer) {
                case 'Y':
                case 'y':
                    return true;
                default:
                    continue;
            }
            break;
        }
        catch (char exception) {
            cout << "Please Enter Again" << endl;
            cin.clear();
        }
    }
}


void Blackjack::startGame() {
    /*
     1. Shuffle Cards
     2. Player choose the amount of money to bet
        -> Starting_Balance = 50 (정해진건가?)
        에 Balance를 백업하고 Balance에서 베팅금액을 뺀다.
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

    int continue_game = 1;

    while (continue_game == 1) {

        deck.init(); // initialise  52 cards
        deck.mixDeck(); // shuffle the deck

        currentPlayer.initGame(); // 카드와 베팅금액을 비운다.
        Computer.initGame(); // 카드를 비운다.
        player_draw = 0;
        if (!doBetting()) // doBetting() returns true if betting succeeds, else return false
            break;

        int first_result = getTwoCards();
        int after_player, after_dealer;

        switch (first_result) {
            case 1: // Player is BJ
                nextRound();
                after_dealer = dealerTurn();
                if (after_dealer == 7) {
                    getResult(3);
                } else {
                    getResult(1);
                }
                break;
            case 2:
                after_player = playerTurn();
                if (after_player == 1) {
                    after_dealer = dealerTurn();
                    if (after_dealer == 7) {
                        getResult(4);
                    } else {
                        getResult(after_dealer);
                    }
                    break;
                }
                else if (after_player == 6) {
                    after_dealer = dealerTurn();
                    if (after_dealer == 7) {
                        getResult(3);
                    } else {
                        getResult(2);
                    }
                    break;
                }
                else {
                    Computer.showHand(); // Show dealer's hidden card
                    getResult(after_player);
                }
                break;
            default:
                break;
        }

        if (restart()) {
            continue_game = 1;
            cout << endl;
            cout << "Let's play again!" << endl;
            cout << endl;
        } else
            continue_game = 0;
    }
}

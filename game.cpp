#include "game.h"

using namespace std;

void printLine()
{
	cout<<"---------------------------------------------------"<<endl;
}


Game::Game() {}

Game::~Game()
{
    // when game is over, save the player's name and final balance in "players.txt"
	storePlayers();
}


// check whether the player is registered already
void Game::loadPlayers()
{
    ifstream fin;
    fin.open("players.txt");


    int num = 1;
    string playerName;
    double balance;

    for(int i = 0; i < 1; i++ )
    {
        fin>>playerName>>balance;
        Players.push_back(PlayerInfo(num,playerName, balance));
    }
    fin.close();

}

//to store player's name and ending balance
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

// Show Introduction of the game
void Game::intro()
{
	/*
	 1. The user has to register his name before he begins playing the game
	 2. Start game is the player registered already
	 3. To check the Information of the game
	 4. The user chooses to end the game
	 */

	printLine();
	
	cout<<"1. Register your name.(R or r)"<<endl;
	cout<<"2. Game start if you have registered your name.(G or g)"<<endl;
	cout<<"3. Information : Who made this game?(I or i)"<<endl;
	cout<<"4. End game.(E or e)"<<endl;
	
	printLine();
	
	cout<<"Which menu are you going to choose? : ";
}


// Add player's name by user's input
void Game::addPlayer()
{
	/*
	 1. Enter name
	 2. ->if name exists, return to the menu
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

            PlayerInfo newPlayer(1, playerName, 100);
            Players.push_back(newPlayer);
            return;

		}
		catch(...)
		{
			cout<<"Please Try Again"<<endl;
			cin.clear();
		}
	}
}

//to update player's information after every round
void Blackjack::updatePlayer()
{
    int i = getPlayerIndex(currentPlayer.getName());
	Players[i].setPlayer(currentPlayer);
}

//startGame
void Game::startGame()
{
	/*
	 using member function from Blackjack class
	 */
}

// print our license (names of the contributors)
void Game::printLicense()
{

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


// give the player his index number to check whetehr his name is registered already
int Game::getPlayerIndex(string playerName)
{
	int i = 0;
	int result = -1;

    while(i < Players.size())
    {
        if(Players[i].getName() == playerName)
        {
            result = i;
            break;
        }
        i++;
    }

	return result;
}


// To end the game
void Game::exit()
{
	/*
	 1. save the player's information in players.txt including the name and the ending balance
	 2. print out  "Thank you for playing BLACKJACK"
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

bool Blackjack::loadPlayer()
{
	string playerName;
    int j,k=-1;
	while(true)
	{
		try {
			cout<<"Enter your name : ";
			cin>>playerName;
			cin.ignore();
			
			for(int i = 0; i < playerName.size(); i++)
			{
				if(isalnum(playerName[i]))
					continue;
				else
					throw playerName;
			}

            //if the name is not registered
            j = getPlayerIndex(playerName);
			if( j == -1 )
			{
				cout<<endl<<"Your name does not exist."<<endl;
				throw playerName;

			}
            k++;
			break;

		}
		catch (...)
		{
			cout << "Please Enter Again." << endl;
			cin.clear();
		}
	}
	currentPlayer.setPlayer(Players[j]);
	return true;

}

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
            cout << " 1) 10   2) 20   3) 30 " << endl;
			cin >> money_s;
			cin.ignore();

    		amount = stod(money_s);

            //user is given with  options
			if (amount == 10 || amount == 20 || amount == 30) {
                if(currentPlayer.possibleBet(amount))
                {
                    currentPlayer.addBet(amount);
                    currentPlayer.show_info();
                    return true;
                }
                else
                {
                    cout<<"You don't have enough money."<<endl;
                    cout<<"You go to main menu."<<endl;
                    return false;
                }
            }
			else{

				throw money_s;
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

//another around of the game
bool Blackjack::restart()
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
            showPlayerChoices();   // choose choice
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
     1 -> Player is BLACKJACK : return triple of bet_money
     2 -> Player WIN : return double of bet_money
     3 -> DRAW : return bet_money
     4 -> Player LOSE :  game over
     */

    int bet = currentPlayer.getBet();
    switch (result) {
        case 1:
            cout << "BLACKJACK!" << endl;
            currentPlayer.setBalance(bet +  bet * 3);
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

void Blackjack::startGame() {
    /*
     1. Check the name is registered
     2. Shuffle Cards
     2. Player choose the amount of money to bet
        -> Starting_Balance = 100
        Update curernt Balance then substract the money of bet
     3. Player and dealer each draws two cards.
     4. Show each cards except dealer's hidden card. (Total 3 cards shown)
     5. BLACKJACK == sum of cards is 21.
        a. Player is BLACKJACK, player automatically WINS -> Round over
        b. Dealer is BLACKJACK, player automatically LOSES -> Round over
        c. If no BLACKJACK, move on.

      6. Player's turn. Print two choices and select one:
      1. STAY
         - Player's turn is over and dealer shows hidden card.
            1. If player's card sum < dealer's card sum, player LOSES -> Round over
            2. If player's card sum > dealer's card sum OR dealer's card sum > 21, player WINS -> Round over
      2. HIT
         - Player draws another card. (If the player's card sum < 21, player goes back to step 5.)
            1. If player card sum > 21 OR player card sum < dealer card sum, player LOSES -> Round over
            2. If player card sum > dealer card sum, player WINS -> Round over



     */

    bool continue_game;
    if(loadPlayer())
    {
        continue_game = true;
    }
    else
    {
        continue_game = false;
    }

    while (continue_game) {

        deck.init(); // initialise  52 cards
        deck.mixDeck(); // shuffle the deck

        currentPlayer.initGame(); // empty card and bet_money
        Computer.initGame(); // empty cards
        player_draw = 0;
        if (!doBetting()) // doBetting() returns true if betting succeeds, else return false
            break;

        int first_result = getTwoCards();
        int after_player, after_dealer;

        switch (first_result) {
            case 1: // Player is BJ
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
            continue_game = true;
            cout << endl;
            cout << "Let's play again!" << endl;
            cout << endl;
        }

        else
            continue_game = false;
    }
    updatePlayer();
}

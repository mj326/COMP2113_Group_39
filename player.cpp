#include "player.h"
using namespace std;

PlayerInfo::PlayerInfo(int player_num, string player_name, int player_balance) :player_num(player_num), player_name(player_name), player_balance(player_balance)
{}			//class initilization where input is player number, name of player, amount of balance for player

PlayerInfo::PlayerInfo() {} 	//class initilization with no specific input
PlayerInfo::~PlayerInfo() {}	//class destructor


//sets the player's basic information of number, name, and amount of balance. Given input is PlayerInfo variable
//and output is storing the player's information onto class variables.
void PlayerInfo::setPlayer(PlayerInfo playerX)		
{
    this->player_num = playerX.player_num;
	this->player_name = playerX.player_name;
	this->player_balance = playerX.player_balance;
}

//displays the player's name and balance. 
void GamePlayer::show_info()
{
	cout<<"Player Name : "<<this->player_name<<endl;
    cout<<"Current Balance : $"<< this->player_balance<<endl;
}

//returns the information of player's number
int PlayerInfo::getNum() const
{
	return player_num;
}

//returns the name of the player
string PlayerInfo::getName() const
{
    return  player_name;
}

//sets the player's balance and stores it by getting the input of amount of balance that needs to be stored
void PlayerInfo::setBalance(int balance)
{
    // cin >> player_balance;
    player_balance += balance;
}

//returns the amount of balance player currently has
double PlayerInfo::getBalance() const
{
    return player_balance;
}

//class initilization for Game player with inheritance of playerInfo. Given input is player number, player name, and the player balance. 
GamePlayer::GamePlayer(int player_num, string player_name, int player_balance)
{
    PlayerInfo(player_num, player_name, player_balance);		//As GamePlayer under goes initilization, the inheritance class of PlayerInfo is 
									//also initilized.
}

//GamePlayer class initilization. As GamePlayer is initilized, PlayerInfo class is also initilized for the case of no input. 
GamePlayer::GamePlayer() : PlayerInfo()					
{}

//class GamePlayer destructor
GamePlayer::~GamePlayer()
{}

//function that returns a bool value whether the amount of money player is willing to bet could be bet with the player's current balance.
//Takes the amount of money as input and returns bool value of true or false as output.
bool GamePlayer::possibleBet(int money)
{
    if(this->player_balance >= money){
        return true;
    }
    else{
        return false;
    }
}

//function of actual betting by adding the bet money. Takes the amount of money the player wants to bet as input and saves it in class variables.
void GamePlayer::addBet(int money)
{
    this->player_balance -= money;
    this->bet_money += money;
}

//returns the sum of the player's card in hand (deck) for game playing.
int GamePlayer::printCardSum() {
	this->sum = printSum<int>(Hand);
	return this->sum;
}

//sets the player's starting balance to 100 as default. Playerbalance is also continuously updated as money is betted. 
void GamePlayer::setStartBal()
{
        this->start_balance = this->player_balance; // starting balance = $100
        this->player_balance -= this->bet_money;
}

//returns the amount of player's money that is on bet
double GamePlayer::getBet()
{
    return this->bet_money;
}

//initilizes the game by setting the money on bet to 0 and clearing the player's deck
void GamePlayer::initGame(){
    this->bet_money = 0;
    (this->Hand).clear();
}

//bool function that returns a bool value whether the player's first cards are in black. If the player's hand sum is equal to 21, returns a true value.
bool GamePlayer::isFirstCardsBJ()
{
    this->sum = printSum<int>(Hand);
    if(sum == 21)
    {
        return true;
    }else
    {
        return false;
    }
}

//shows the player's cards in hand and deck and also shows the sum of the card sum in player's current hand
void GamePlayer::showHand(){
    cout<<"Player's Cards : "<<endl;
    vector<Card>::iterator i;
    for(i=Hand.begin(); i != Hand.end(); i++){
        (*i).printSuit();
    }
    cout<<"Your card sum is : "<<printSum<int>(Hand)<<endl;
	cout<<"---------------------------------------------------"<<endl;
}


//shows the first two cards in the player's hand and the current sum of the two cards
void GamePlayer::showFirstTwoCards()
{
	cout << "Player's Cards : " << endl;
	Hand[0].printSuit();
	Hand[1].printSuit();
	cout << "Your card sum is : " << printSum<int>(Hand) << endl;
}

//player draws two cards from the deck on to the hand
void GamePlayer::drawTwoCards(Deck &deck){
	(this->Hand).push_back(deck.drawACard());
	(this->Hand).push_back(deck.drawACard());
}

//player draws one card from the deck on to the hand
void GamePlayer::drawACard(Deck &deck)
{
	(this->Hand).push_back(deck.drawACard());
}

//bool operator function for comparing the dealer's card sum and the player's card sum and returns a bool value
bool operator>(GamePlayer& p1, GamePlayer& p2)
{
    int sum1 = p1.printCardSum();
    int sum2 = p2.printCardSum();

    if(sum1 < sum2)
        return false;
    else if(sum1 > sum2)
        return true;
    else
        return false;
}

//bool operator function for comparing the dealer's card sum and the player's card sum
bool operator==(GamePlayer& p1, GamePlayer& p2)
{
    int sum1 = p1.printCardSum();
    int sum2 = p2.printCardSum();

    if(sum1 < sum2)
        return false;
    else if(sum1 > sum2)
        return false;
    else
        return true;
}

//shows the dealer's card by opening it and showing the sum of the opened dealer's card
void Dealer::showOpenCard(){
    cout<<endl<<"Dealer's Open Card :";
    Hand[1].printSuit();
    cout<<"Dealer's open card sum is : "<<Hand[1].printValue()<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

//shows the cards in dealer's hand and also prints the sum of the dealer's card
void Dealer::showHand(){
    cout<<"Dealer's cards are : ";
    vector<Card>::iterator i;
    for(i=Hand.begin(); i != Hand.end(); i++){
        (*i).printSuit();
    }
    cout<<"Dealer's card sum is :  "<<printSum<int>(Hand)<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

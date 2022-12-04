#include "player.h"
using namespace std;

PlayerInfo::PlayerInfo(int player_num, string player_name, int player_balance) :player_num(player_num), player_name(player_name), player_balance(player_balance)
{}

PlayerInfo::PlayerInfo() {}
PlayerInfo::~PlayerInfo() {}

/* void PlayerInfo::setName(PlayerInfo playerX) // who -> playerX
{
    // cin >> player_name;
    this->player_name = playerX.player_name;
    this->player_balance = playerX.player_balance;
} */

void PlayerInfo::setPlayer(PlayerInfo playerX) // who -> playerX
{
    this->player_num = playerX.player_num;
	this->player_name = playerX.player_name;
	this->player_balance = playerX.player_balance;
}
void GamePlayer::show_info()
{
	cout<<"Player Name : "<<this->player_name<<endl;
    cout<<"Current Balance : $"<< this->player_balance<<endl;
}

int PlayerInfo::getNum() const
{
	return player_num;
}

string PlayerInfo::getName() const
{
    return  player_name;
}

void PlayerInfo::setBalance(int balance)
{
    // cin >> player_balance;
    player_balance += balance;
}

double PlayerInfo::getBalance() const
{
    return player_balance;
}

GamePlayer::GamePlayer(int player_num, string player_name, int player_balance)
{
    PlayerInfo(player_num, player_name, player_balance);
}

GamePlayer::GamePlayer() : PlayerInfo()
{}

GamePlayer::~GamePlayer()
{}

int GamePlayer::printCardSum() {
	this->sum = printSum<int>(Hand);
	return this->sum;
}

void GamePlayer::setStartBal()
{
        this->start_balance = this->player_balance;           // starting balance = $50
        this->player_balance -= this->bet_money;
}

bool GamePlayer::betMoneyAvail(double amount)
{
    try             // Handling Exceptions
    {
        if (amount != 10 || amount != 20 || amount != 30)
            throw amount;
    }
    catch(double exception)
    {
        cout << "Entered $" << exception << " to bet." << endl;
        cout << "Please re-enter the correct amount to bet." << endl;
    }

    if (this->player_balance >= amount && this->player_balance - amount >= 0)
        return true;
    else
        return false;
}

void GamePlayer::betMoney(double amount)
{
    try             // Handling Exceptions
    {
        if (amount != 10 || amount != 20 || amount != 30)
            throw amount;
    }
    catch(double exception)
    {
        cout << "Entered $" << exception << " to bet." << endl;
        cout << "Please re-enter the correct amount to bet." << endl;
    }

    this->start_balance -= amount;
    this->player_balance = this->start_balance;
    this->bet_money += amount;
    /*
    if ( player wins )
        this->player_balance += amount * 2;
    else
        this->player_balance += 0;
    */
}

double GamePlayer::getCardSum()
{
    this->sum = printSum<int>(Hand);
    return this->sum;
}

double GamePlayer::getBet()
{
    return this->bet_money;
}

void GamePlayer::initGame(){
    this->bet_money = 0;
    (this->Hand).clear();
}


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


void GamePlayer::showHand(){
    cout<<"Player's Cards : "<<endl;
    vector<Card>::iterator i;
    for(i=Hand.begin(); i != Hand.end(); i++){
        (*i).printSuit();
    }
    cout<<"Your card sum is : "<<printSum<int>(Hand)<<endl;
	cout<<"---------------------------------------------------"<<endl;
}



void GamePlayer::showFirstTwoCards()
{
	cout << "Player's Cards : " << endl;
	Hand[0].printSuit();
	Hand[1].printSuit();
	cout << "Your card sum is : " << printSum<int>(Hand) << endl;
}

void GamePlayer::drawTwoCards(Deck &deck){
	(this->Hand).push_back(deck.drawACard());
	(this->Hand).push_back(deck.drawACard());
}

void GamePlayer::drawACard(Deck &deck)
{
	(this->Hand).push_back(deck.drawACard());
}

// 딜러 카드의 합과 플레이어 카드의 합 비교
bool operator>(GamePlayer& p1, GamePlayer& p2)
{
    int sum1 = p1.getCardSum();
    int sum2 = p2.getCardSum();

    if(sum1 < sum2)
        return false;
    else if(sum1 > sum2)
        return true;
    else
        return false;
}

bool operator==(GamePlayer& p1, GamePlayer& p2)
{
    int sum1 = p1.getCardSum();
    int sum2 = p2.getCardSum();

    if(sum1 < sum2)
        return false;
    else if(sum1 > sum2)
        return false;
    else
        return true;
}


void Dealer::showOpenCard(){
    cout<<endl<<"Dealer's Open Card :";
    Hand[1].printSuit();
    cout<<"Dealer's open card sum is : "<<Hand[1].printValue()<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

void Dealer::showHand(){
    cout<<"Dealer's cards are : ";
    vector<Card>::iterator i;
    for(i=Hand.begin(); i != Hand.end(); i++){
        (*i).printSuit();
    }
    cout<<"Dealer's card sum is :  "<<printSum<int>(Hand)<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

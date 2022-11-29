#include "player.h"
using namespace std;

PlayerInfo::PlayerInfo()
{
    this->player_name = "";
    this->player_balance = 0;

}
PlayerInfo::PlayerInfo(string player_name, int player_balance)
{
    this->player_name = player_name;
    this->player_balance = player_balance;
}
PlayerInfo::~PlayerInfo() {};
void PlayerInfo::setName(PlayerInfo who)
{
    cin.getline(player_name);
    this->player_name = player_name;
}

void PlayerInfo::setBalance(int player_balance)
{
    cin >> player_balance;
    this->player_balance = player_balance;
}

GamePlayer::GamePlayer()
{
    this->Deck = vector<Card> Deck;
    this->bet_money = 0;
    this->sum = 0;
    this -> start_balance = 0;
}

GamePlayer::GamePlayer(string player_name, int player_balance)
{
    PlayerInfo(player_name, player_balance);
}

GamePlayer::~GamePlayer()
{}

void GamePlayer::setStartBal()
{
    if (this->player_balance != 0)          //If player balance is successfully initialized
    {
        this->start_balance = this->player_balance;
    }
    else
    {
        this->start_balance = 50;           //starting balance = 50
    }
}

bool GamePlayer::betMoneyAvail(int amount)
{
    try             //Handling Exceptions
    {
        if (amount != 0 || amount != 10 || amount != 20)
            throw amount;
    }
    catch(int exception)
    {
        cout << "Entered " << exception << "to bet." << endl;
        cout << "Please re-enter the correct amount to bet." << endl;
    }

    switch(amount)
    {
        case 1:         //betting 0
            return true;
            break;
        case 2:         //betting 10
        {
            if (this->player_balance >= amount && this->player_balance - amount >= 0)
                return true;
            else
                return false;
            break;
        }
        case 3:        //betting 20
        {
            if (this->player_balance >= amount && this->player_balance - amount >= 0)
                return true;
            else
                return false;
            break;
        }
    }
}

void GamePlayer::show_info()
{
    cout << "Name : " << this->player_name << endl;
    cout << "Starting Balance : " << this->start_balance << endl;
    cout << "Current Balance : " << this->player_balance << endl;
    cout << "Current accumulated Bet Money" << this->bet_money << endl;
}

void GamePlayer::betMoney(int amount)
{
    try             //Handling Exceptions
    {
        if (amount != 0 || amount != 10 || amount != 20)
            throw amount;
    }
    catch(int exception)
    {
        cout << "Entered " << exception << "to bet." << endl;
        cout << "Please re-enter the correct amount to bet." << endl;
    }

    this->start_balance -= amount;
    this->player_balance = this->start_balance;
    this->bet_money += amount;

    if (//win)
        this->player_balance += amount * 2;
    else
        this->player_balance += 0;
}

void GamePlayer::showFirstTwoCards()
{
	cout << "[ Player ]" << endl;
	Deck[0].getShape();
	Deck[1].getShape();
	cout << "[ " << getSum<int>(Deck)<< " ]" << endl;
	cout << "---------------------------------" << endl;
}

void GamePlayer::drawTwoCards(Deck &deck){
	(this->Hand).push_back(deck.getACard());
	(this->Hand).push_back(deck.getACard());
}
#include <player.h>

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
void PlayerInfo::setName(string player_name)
{
    cin.getline(player_name);
    this->player_name = player_name;
}

void PlayerInfo::setBalance(string player_balance)
{
    cin >> player_balance;
    this->player_balance = player_balance;
}

Game::Game()
{
    this->Deck = vector<Card> Deck;
    this->bet_money = 0;
    this->sum = 0;
    this -> start_balance = 0;
}

Game::Game(string player_name, int player_balance)
{
    PlayerInfo(player_name, player_balance);
}

Game::~Game()
{}

void Game::setStartBal()
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

bool Game::betMoneyAvail(int amount)
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

void Game:show_info()
{
    cout << "Name : " << this->name << endl;
    cout << "Starting Balance : " << this->start_balance << endl;
    cout << "Current Balance : " << this->player_balance << end;
    cout << "Current accumulated Bet Money" << this->bet_money << endl;
}

void Game::betMoney(int amount)
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

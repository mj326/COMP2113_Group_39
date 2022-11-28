#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PlayerInfo
{
public:     //Initializing Player
    PlayerInfo();
    PlayerInfo(string player_name, int player_balance);
    ~PlayerInfo();

public: //Setting Information
    void setName(string player_name);
    void setBalance(int player_balance);

public: //Getting Information
    inline string getName() const {return player_name;}
    inline int getBalance() const {return player_balance;}

protected:
    string player_name;
    int player_balance;
private:
};


class Game : public PlayerInfo          //Inheritance of Player class to Game class
{
public:                                 //Initilization
    Game();
    Game(string player_name, int balance);
    ~Game();

public:         //Getting Player in-game Information
    inline int getSum() const {return sum;}
    inline int getStartBal() const {return start_balance;}
    inline int getBetMoney() const {return bet_money;}

public:         //Setting Player in-game Information
    void setStartBal();
    bool betMoneyAvail(int amount);
    void betMoney(int amount);
    void show_info();

protected:
private:
    vector<Card> Deck;
    int bet_money;
    int sum;
    int start_balance;
};
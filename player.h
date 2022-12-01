#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
using namespace std;

class PlayerInfo
{
public:     //Initializing Player
    PlayerInfo();
    PlayerInfo(string player_name, int player_balance);
    ~PlayerInfo();

public: // Setting Information
    void setName(PlayerInfo who);
    void setBalance(int player_balance);

public: // Getting Information
    inline string getName() const {return player_name;}
    inline int getBalance() const {return player_balance;}

protected:
    string player_name;
    int player_balance;
private:
};

bool compNum(const PlayerInfo &a, const PlayerInfo &b);
bool compBalance(const PlayerInfo &a, const PlayerInfo &b);

class GamePlayer : public PlayerInfo          // Inheritance of Player class to Game class
{
public:
    // Initilization
    GamePlayer();
    GamePlayer(string player_name, int balance);
    ~GamePlayer();

public:         //Getting Player in-game Information
    inline int printSum() const {return sum;}
    inline int getStartBal() const {return start_balance;}
    inline int getBetMoney() const {return bet_money;}

public:         //Setting Player in-game Information
    void setStartBal();
    bool betMoneyAvail(int amount);
    void betMoney(int amount);
    void show_info();
    void showFirstTwoCards();
    void drawTwoCards(Deck &deck);
    bool isFirstCardsBJ();
    void drawACard(Deck &deck);
    void showHand();
    double getCardSum();
    double getBet();
    void initGame();

protected:
    vector<Card> Hand;
    int bet_money;
    int sum;
    int start_balance;
};

bool operator>(GamePlayer& p1, GamePlayer& p2);

bool operator==(GamePlayer& p1, GamePlayer& p2);

class Dealer : public GamePlayer
{
public:
	
	void showOpenCard();
	bool isOpenCardAce();
	void showHand();
};
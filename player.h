#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
using namespace std;

class PlayerInfo
{

protected:
    int player_num = 1;
    string player_name;
    int player_balance;


public:     // Initializing Player
    PlayerInfo(int player_num, string player_name, int player_balance);
    PlayerInfo();
    ~PlayerInfo();

public:
    // Setting Information
    void setName(PlayerInfo someone);
    void setPlayer (PlayerInfo someone);
    void setBalance(int player_balance);
    //void setBalance(double money);
    int getNum() const;
    string getName() const;
    double getBalance() const;
//    inline string getName() const {return player_name;}
//    inline int getBalance() const {return player_balance;}
};

class GamePlayer : public PlayerInfo
        // Inheritance of Player class to Game class
{
protected:
    vector<Card> Hand;
    int bet_money;
    int sum;
    int start_balance;

public:
    // Initilization
    GamePlayer(int player_num, string player_name, int balance);
    GamePlayer();
    ~GamePlayer();

public:
    //Getting Player in-game Information
    inline int getStartBal() const {return start_balance;}
    inline int getBetMoney() const {return bet_money;}
    int printCardSum();

    //Setting Player in-game Information
    void setStartBal();
    bool possibleBet(int money);
    void addBet(int money);
    void show_info();
    void showFirstTwoCards();
    void drawTwoCards(Deck &deck);
    bool isFirstCardsBJ();
    void drawACard(Deck &deck);
    void showHand();
    double getCardSum();
    double getBet();
    void initGame();

};

// compare the sum of Cards of the Player's and the Dealer's
bool operator>(GamePlayer& p1, GamePlayer& p2);
bool operator==(GamePlayer& p1, GamePlayer& p2);

class Dealer : public GamePlayer
{
public:
	
	void showOpenCard();
	void showHand();
};
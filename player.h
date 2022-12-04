#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
using namespace std;

class PlayerInfo
{

protected:
    string player_name;
    int player_balance;


public:     // Initializing Player
    PlayerInfo(string player_name, int player_balance);
    PlayerInfo();
    ~PlayerInfo();

public:
    // Setting Information
    void setName(PlayerInfo who);
    void setPlayer (PlayerInfo who);
    void setBalance(int player_balance);
    //void setBalance(double money);
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
    GamePlayer(string player_name, int balance);
    GamePlayer();
    ~GamePlayer();

public:
    //Getting Player in-game Information
    inline int getStartBal() const {return start_balance;}
    inline int getBetMoney() const {return bet_money;}
    int printCardSum();

    //Setting Player in-game Information
    void setStartBal();
    bool betMoneyAvail(double amount);
    void betMoney(double amount);
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

// 딜러 카드의 합과 플레이어 카드의 합 비교
bool operator>(GamePlayer& p1, GamePlayer& p2);
bool operator==(GamePlayer& p1, GamePlayer& p2);

class Dealer : public GamePlayer
{
public:
	
	void showOpenCard();
	void showHand();
};
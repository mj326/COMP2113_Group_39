#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
using namespace std;

class PlayerInfo 	//class for PlayerInfo
{

protected:
    int player_num = 1;		//player_number initilized to 1
    string player_name;		//variable for name of the player
    int player_balance;		//variable for the player's balance


public:     // Initializing Player
	
//class PlayerInfo initilization with player number, player name, and player balance as input
    PlayerInfo(int player_num, string player_name, int player_balance);	
//class PlayerInfo initilization
    PlayerInfo();
//class PlayerInfo destructor
    ~PlayerInfo();

public:
    // Setting Information
    void setName(PlayerInfo someone);		//Sets the name of the player
    void setPlayer (PlayerInfo someone);	//Sets the number of player
    void setBalance(int player_balance);	//Sets the balance of player
    //void setBalance(double money);
    int getNum() const;				//Getting the player's number
    string getName() const;			//Getting the name of the player
    double getBalance() const;			//Getting the player's balance
//    inline string getName() const {return player_name;}
//    inline int getBalance() const {return player_balance;}
};

// Inheritance of PlayerInfo class to GamePlayer Class
class GamePlayer : public PlayerInfo		
        
{
protected:
    vector<Card> Hand;			//Using the vector STL made in card 
    int bet_money;			//variable to keep track of money that is being bet
    int sum;				//sum variable for tracking player's money sum
    int start_balance;			//variable for player's start balance

public:
    // Initilization
    //class GamePlayer initilization with player number, player name, and player balance as input 
    GamePlayer(int player_num, string player_name, int balance);		
    //class GamePlayer initilization
    GamePlayer();
    //class GamePlayer destructor
    ~GamePlayer();

public:
    //Getting Player in-game Information
    inline int getStartBal() const {return start_balance;}	//returns the starting balance
    inline int getBetMoney() const {return bet_money;}		//returns the money that is bet 
    int printCardSum();						//prints the sum of the card
		
    //Setting Player in-game Information
    void setStartBal();						//sets the player's starting balance
    bool possibleBet(int money);				//returns a bool value for availability on the money amount being bet
    void addBet(int money);					//actual betting with the amount of money that the player wants to bet as input
    void show_info();						//shows the player's information
    void showFirstTwoCards();					//shows the first two cards
    void drawTwoCards(Deck &deck);				//drawing two cards from the deck
    bool isFirstCardsBJ();					//bool function to see if the player is black jack from the first cards received
    void drawACard(Deck &deck);					//drawing a card from the deck
    void showHand();						//shows the cards that the player has 
    double getCardSum();					//getting the sum of the card the player has
    double getBet();						//getting the amount of money bet the player has made
    void initGame();						//initilizing the game

};

// compare the sum of Cards of the Player's and the Dealer's
bool operator>(GamePlayer& p1, GamePlayer& p2);
bool operator==(GamePlayer& p1, GamePlayer& p2);

class Dealer : public GamePlayer				//Dealer class with inheritance of GamePlayer class
{
public:
	
	void showOpenCard();					//showing the cards that are opened from the dealer
	void showHand();					//showing the dealer's cards
};

#pragma once
#include "card.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void printLine();

class Game
{
protected:
	vector<PlayerInfo> Players; // registered player

public:
	Game();
	~Game();
	
	// Print intro on terminal
	void intro();

	// load player's index from players.txt
	int getPlayerIndex(string playerName);

	// Save player record on players.txt
	void storePlayers();

	// Load existing player
	void loadPlayers();

    // Input user's name
    void addPlayer();
	
	// Start playing game
	virtual void startGame();

	// Print license of game
	void printLicense();

	// Exit game
	void exit();
	
};

class Blackjack : public Game
{
protected:

	GamePlayer currentPlayer; // current player (User)
	Dealer Computer; // dealer (Computer)
	Deck deck; // 52 cards in total
	int player_draw; // How many cards the player drew

public:
	Blackjack();
	~Blackjack();

	// Load the current player info : return true if no error, else return false
	bool loadPlayer();
	// Player bets : Return true if betting has no error, else return false
	bool doBetting();
	
	void showInitialCards();

	// Receive 2 cards in the beginning
	int getTwoCards();
	
	// Print choices for the player after card open
	void showPlayerChoices();
	
	// what the player needs to do if it's not BLACKJACK
	int playerTurn();
	
	// what the dealer need to do once player is done
	int dealerTurn();
	
	// decide on the result
	void getResult(int result);
	
	bool restart();

	virtual void startGame();
	
	// Update the player's information
	void updatePlayer();
};

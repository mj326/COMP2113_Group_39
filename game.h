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
	vector<PlayerInfo> Players; // 등록된 플레이어들

public:
	Game();
	~Game();
	
	// Print intro on terminal
	void intro();
	
	// Load current player from players.txt
	void loadPlayer();

	// Save player record on players.txt
	void storePlayers();

    // 기존 플레이어로 게임시작
    void addPlayer();
	
	// #2. 기존 플레이어로 게임 시작
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
	
	// 플레이어 턴에 할일 : 블랙잭이나 버스트가 아닐 경우
	int playerTurn();
	
	// 딜러 턴에 할 일 : 플레이어가 할일 다 한 경우
	int dealerTurn();
	
	// 어떤 케이스냐에 따라 처리하는 결과가 달라짐
	void getResult(int result);
	
	bool restart();
	
	bool nextRound();
	virtual void startGame();
	
	// Players에 이번 플레이어의 정보 업데이트
	void updatePlayer();
};

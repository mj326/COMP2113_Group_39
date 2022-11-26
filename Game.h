#pragma once
#include "Card.h"
#include "Player.h"
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
	vector<Player> Players; // 등록된 플레이어들

public:
	Game();
	~Game();
	
	// Print intro on terminal
	void showIntro();
	
	// Save player record on players.txt
	void savePlayers();

    // 기존 플레이어로 게임시작
    void addNewPlayer();
	
	// #2. 기존 플레이어로 게임 시작
	virtual void startGame();

	// Print license of game
	void printLicence();

	// Exit game
	void exit();
	
};

class Blackjack : public Game
{
protected:

	GamePlayer currentPlayer; // current player (User)
	Dealer Computer; // dealer (Computer)
	Deck deck; // 52 cards total
	int player_draw; // How many cards the player drew

	GamePlayer currentPlayer; // 현재 게임하는 사람
	Dealer Computer; // 딜러
	Deck deck; // 총 52장의 카드
	int player_draw; // 플레이어가 몇 번 카드를 드로우 했는지.

public:
	Blackjack();
	~Blackjack();

	// Player bets : Return true if betting has no error, else return false
	bool doBetting();
	
	void showFirstCards();

	
	// Receive 2 cards in the beginning
	int getTwoCards();
	
	// Print user manual
	void showPlayerWhatToDo();
	
	// 플레이어 턴에 할일 : 블랙잭이나 버스트가 아닐 경우
	int doPlayerTurn();
	
	// 딜러 턴에 할 일 : 플레이어가 할일 다 한 경우
	int doDealerTurn();
	
	// 어떤 케이스냐에 따라 처리하는 결과가 달라짐
	void getResult(int result);
	
	bool wannaRestart();
	
	bool wannaNextStage();
	virtual void startGame();
	
	// Players에 이번 플레이어의 정보 업데이트
	void updatePlayer();
};
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
	
	// 완성
	void loadPlayers();
	// 완성
	void storePlayers();
	
	// Print intro on terminal
	void showIntro();
	
	// 플레이어의 인덱스를 반환하고 없으면 -1반환
	// int getRegisteredPlayerIdx(string playerName);
	
	
	// 완성)#1. 새로운 플레이어 등록
	// void addNewPlayer();
	
	
	// #2. 기존 플레이어로 게임 시작
	virtual void startGame();

	// 완성)#3. 잔고 기준 플레이어 랭킹 출력
	// void showPlayers();
	// 완성)#4. 기존 플레이어 게임머니 충전하기
	// void fillUp(string playerName = "");
	
	// Print license of game
	void showLicence();
	
	// Exit game
	void exit();
	
};

class BlackJack : public Game
{
protected:
	GamePlayer currentPlayer; // current player (User)
	Dealer Computer; // dealer (Computer)
	Deck deck; // 52 cards total
	int player_draw; // How many cards the player drew

public:
	BlackJack();
	~BlackJack();
	
	// 테스트)현재 게임하는 사람 로딩 : 성공하면 true, 실패하면 false 반환
	bool loadPlayer();

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
	
    // bool wannaEvenMoney();
	// bool wannaInsurance();

	bool wannaRestart();
	
	bool wannaNextStage();
	virtual void startGame();
	
	// Update current player's info to players
	void updatePlayer();
};
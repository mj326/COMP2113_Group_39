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
	
	// 완성)게임 첫 화면 출력
	void showIntro();
	
	// 플레이어의 인덱스를 반환하고 없으면 -1반환
	int getRegisteredPlayerIdx(string playerName);
	
	
	
	// 완성)#1. 새로운 플레이어 등록
	void addNewPlayer();
	
	
	// #2. 기존 플레이어로 게임 시작
	virtual void startGame();
	// 완성)#3. 잔고 기준 플레이어 랭킹 출력
	void showPlayers();
	// 완성)#4. 기존 플레이어 게임머니 충전하기
	void fillUp(string playerName = "");
	
	// 완성)#5. 라이센스 출력
	void showLicence();
	
	// 완성)#6. 게임 종료
	void exit();
	
};

class BlackJack : public Game
{
protected:
	GamePlayer currentPlayer; // 현재 게임하는 사람
	Dealer Computer; // 딜러
	Deck deck; // 총 52장의 카드
	int player_draw; // 플레이어가 몇 번 카드를 드로우 했는지.

public:
	BlackJack();
	~BlackJack();
	
	// 테스트)현재 게임하는 사람 로딩 : 성공하면 true, 실패하면 false 반환
	bool loadPlayer();

	// 테스트)플레이어가 베팅하기 : 정상적으로 베팅되었으면 true 반환, 아니면 false 반환
	bool doBetting();
	
	void showFirstCards() ;

	
	// 게임 시작시 두 장의 카드 받기
	int getTwoCards();
	
	// 플레이어가 어떤 일할지 메뉴 출력하기
	void showPlayerWhatToDo();
	
	// 플레이어 턴에 할일 : 블랙잭이나 버스트가 아닐 경우
	int doPlayerTurn();
	
	// 딜러 턴에 할 일 : 플레이어가 할일 다 한 경우
	int doDealerTurn();
	
	
	// 어떤 케이스냐에 따라 처리하는 결과가 달라짐
	void getResult(int result);
	
	
	bool wannaEvenMoney();
	
	bool wannaInsurance();
	bool wannaRestart();
	
	bool wannaNextStage();
	virtual void startGame();
	
	// Players에 이번 플레이어의 정보 업데이트
	void updatePlayer();
};
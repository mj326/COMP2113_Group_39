#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <random>
#include <algorithm>
#include <iterator>
using namespace std;

// Create namespace for the Deck
namespace Card_namespace {

	const int NumofCards = 52;
	// Calculate Ace as 1 or 10
	const int DIAMOND_A = 1; 
	const int SPADE_A = 2;
	const int HEART_A = 3;
	const int CLUBS_A = 4;
	
	// Card numbers 2 to 9
	const int DIAMOND_2 = 12;
	const int DIAMOND_3 = 13;
	const int DIAMOND_4 = 14;
	const int DIAMOND_5 = 15;
	const int DIAMOND_6 = 16;
	const int DIAMOND_7 = 17;
	const int DIAMOND_8 = 18;
	const int DIAMOND_9 = 19;
	
	const int SPADE_2 = 22;
	const int SPADE_3 = 23;
	const int SPADE_4 = 24;
	const int SPADE_5 = 25;
	const int SPADE_6 = 26;
	const int SPADE_7 = 27;
	const int SPADE_8 = 28;
	const int SPADE_9 = 29;
	
	const int HEART_2 = 32;
	const int HEART_3 = 33;
	const int HEART_4 = 34;
	const int HEART_5 = 35;
	const int HEART_6 = 36;
	const int HEART_7 = 37;
	const int HEART_8 = 38;
	const int HEART_9 = 39;
	
	const int CLUBS_2 = 42;
	const int CLUBS_3 = 43;
	const int CLUBS_4 = 44;
	const int CLUBS_5 = 45;
	const int CLUBS_6 = 46;
	const int CLUBS_7 = 47;
	const int CLUBS_8 = 48;
	const int CLUBS_9 = 49;
	
	// 10, K, J, Q are calculated as 10
	const int DIAMOND_10 = 100;
	const int DIAMOND_K = 110;
	const int DIMOND_J = 120;
	const int DIAMOND_Q = 130;
	
	const int SPADE_10 = 200;
	const int SPADE_K = 210;
	const int SPADE_J = 220;
	const int SPADE_Q = 230;
	
	const int HEART_10 = 300;
	const int HEART_K = 310;
	const int HEART_J = 320;
	const int HEART_Q = 330;
	
	const int CLUBS_10 = 400;
	const int CLUBS_K = 410;
	const int CLUBS_J = 420;
	const int CLUBS_Q = 430;
}

class Card // into Card_class 
{
protected:
	int value; // Actual value used
	
private:
	int cards;
	
public:
	int sut, number, cardName;
	Card();
	~Card();
	Card(const Card & ca);
	void setupCard(int cardName) ;
	
	void setupSuit(int cardName);
	void setupValue(int cardName);
	
	void setupNumber(int cardName);
	
	char printSuit() ;
	int printNum() ;
	int printValue() ;
};

class Deck
{
	vector<Card> cards;
public:
	Deck();
	~Deck();
	void mixDeck();
	int printRemainCardsNum();
	Card drawACard() ;
	void init();
};

template <typename T>
T printSum(vector <Card> &Hand) {
	T num, sum = 0;
	if (Hand.empty())
		return 0;
	
	num = (int)Hand.size();
	for (int i = 0; i < num; i++) {
		sum += Hand[i].printValue();
	}
	return sum;
}
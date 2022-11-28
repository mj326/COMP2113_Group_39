#include "Card.h"
using namespace std;

Card::Card() { cards = 52; }
Card::~Card() {};
Card::Card(const Card & Ca){ // ca => Ca
	value = Ca.value;
	cards = Ca.cards; 
	sut = Ca.sut; //shp => sut
	number = Ca.number; 
	cardName = Ca.cardName;
}

void Card::setupCard(int cardName) { //setCard=> setupCard
	setupSuit(cardName); // setShape => setupSuit
	setupValue(cardName); // setValue => setupValue
	setupNumber(cardName); // setNumber => setupNumber
}

void Card::setupSuit(int cardName) { //setShape => setupSuit
	if (cardName < 10)
		sut = cardName;
	else if (10 < cardName && cardName < 50)
		sut = cardName / 10;
	else if (50 < cardName) {
		sut = cardName / 100;
	}
}

void Card::setupValue(int cardName) { // setValue => setupValue
	if (cardName < 10)
		value = 11;                     // A를 무조건 11로 처리
	else if (10 < cardName && cardName < 50)
		value = cardName % 10;
	else if (50 < cardName)
		value = 10;
}

void Card::setupNumber(int cardName) { // setNumber => setupNumber
	if (cardName < 10)
		number = 'A';  //65
	else if (10 < cardName && cardName < 50)
		number = cardName % 10;
	else if (50 < cardName) {
		if (cardName % 100 == 0)
			number = 10;
		else if (cardName % 100 == 10)
			number = 'K'; //75
		else if (cardName % 100 == 20)
			number = 'J'; //74
		else if (cardName % 100 == 30)
			number = 'Q'; //81
	}
}

char Card::printSuit() { //getShape => printSuit
	char suit; //shape => suit
	if (number > 10){
		if (sut == 1){ //shp => sut
			suit = 'D'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ◆        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<(char)number<<"     |"<<endl;      
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
		else if (sut == 2){ //shp => sut
			suit = 'S'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ♠        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<(char)number<<"     |"<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
		else if (sut == 3){ //shp => sut
			suit = 'H'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ♥        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<(char)number<<"     |"<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
		else if (sut == 4){ //shp => sut
			suit = 'C'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ♣        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<(char)number<<"     |"<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
	} else {
		if (sut == 1){ //shp => sut
			suit = 'D'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ◆        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<number<<"     |"<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
		else if (sut == 2){ //shp => sut
			suit = 'S'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ♠        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<number<<"     |"<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
		else if (sut == 3){ //shp => sut
			suit = 'H'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ♥        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<number<<"     |"<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
		else if (sut == 4){ //shp => sut
			suit = 'C'; //shape => suit
			cout<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
			cout<<"| ♣        |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|          |"<<endl;
			cout<<"|    "<<number<<"     |"<<endl;
			cout<<" ㅡㅡㅡㅡㅡ"<<endl;
		}
	}
	return suit; //shape => suit
}

int Card::printNum() { //getNumber => printNum
	return number;
}

int Card::printValue() { //getValue => printValue
	return value;
}


Deck::Deck() {
	cards.reserve(52);
	init();
}
Deck::~Deck() {};

void Deck::mixDeck() //shuffleDeck => mixDeck
{
//	unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
//	random_mix(cards.begin(), cards.end(), std::default_random_engine(seed));
	std::random_device rd;
	std::mt19937 g(rd());
	
	std::shuffle(cards.begin(), cards.end(), g); //shuffle(...) => mix(...)
}

int Deck::printRemainCardsNum() { // getRemainCardsNum() => printRemainCardsNum()
	return (int)cards.size();
}


Card Deck::collectACard() { //getACard() => collectACard()
	Card card;
	if (cards.size() >= 1) {
		card = cards[cards.size() - 1];
		cards.pop_back();
		card.Card::setupCard(card.cardName);
	}
	else {
		cout << "All the cards are drawn from the deck." << endl;
		exit(-1);
	}
	return card;
}

void Deck::init() {
	Card NewCard; //new_card = NewCard
	int card_array[52] = { 1, 2, 3, 4, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 27, 28, 29, 32, 33, 34, 35, 36, 37, 38, 39, 42, 43, 44, 45, 46, 47, 48, 49, 100, 110, 120, 130, 200, 210, 220, 230, 300, 310, 320, 330, 400, 410, 420, 430 };
	cards.clear();
	for (int i = 0; i < 52; i++) {
		NewCard.cardName = card_array[i]; //from arry[..]
		cards.push_back(NewCard);
	}
}

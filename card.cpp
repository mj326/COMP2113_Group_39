#include "card.h"
using namespace std;

//Card class initilization with setting the cards to 52 cards (deck)
Card::Card() { cards = 52; }

//Class destructor
Card::~Card() {}

//Card class initilization with taking input of Card variable and setting the class variables with input variables
Card::Card(const Card & Ca){ // ca => Ca
	value = Ca.value;
	cards = Ca.cards; 
	sut = Ca.sut; //shp => sut
	number = Ca.number; 
	cardName = Ca.cardName;
}

//setting up the Card
void Card::setupCard(int cardName) {
	setupSuit(cardName);
	setupValue(cardName);
	setupNumber(cardName);
}

//Setting up the card suit with taking the cardName int variable as input
void Card::setupSuit(int cardName) {
	if (cardName < 10)
		sut = cardName;
	else if (10 < cardName && cardName < 50)
		sut = cardName / 10;
	else if (50 < cardName) {
		sut = cardName / 100;
	}
}

//Setting up the card value with taking cardName int variable as input
void Card::setupValue(int cardName) {
	if (cardName < 10)
        // A is always 11
		value = 11;
	else if (10 < cardName && cardName < 50)
		value = cardName % 10;
	else if (50 < cardName)
		value = 10;
}

//Setting up the card number with taking cardName int variable as input
void Card::setupNumber(int cardName) {
	if (cardName < 10)
		number = 'A';  // 65
	else if (10 < cardName && cardName < 50)
		number = cardName % 10;
	else if (50 < cardName) {
		if (cardName % 100 == 0)
			number = 10;
		else if (cardName % 100 == 10)
			number = 'K'; // 75
		else if (cardName % 100 == 20)
			number = 'J'; // 74
		else if (cardName % 100 == 30)
			number = 'Q'; // 81
	}
}

// to visualise cards (prints the card design)
char Card::printSuit() {
	char suit;
    if(number > 10){
        if (sut == 1){
            suit = 'D';
            cout<<endl;
            cout<<" *_____* "<<endl;
            cout<<"| ◆     |"<<endl;
            cout<<"|   "<<(char)number<<"   |"<<endl;
            cout<<"|     ◆ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }

        else if (sut == 2){
            suit = 'S';
            cout<<endl;
            cout<<" *_____* "<<endl;
            cout<<"| ♠     |"<<endl;
            cout<<"|   "<<(char)number<<"   |"<<endl;
            cout<<"|     ♠ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }
        else if (sut == 3){
            suit = 'H';
            cout<<endl;
            cout<<" *_____* "<<endl;
            cout<<"| ♥     |"<<endl;
            cout<<"|   "<<(char)number<<"   |"<<endl;
            cout<<"|     ♥ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }
        else if (sut == 4){
            suit = 'C';
            cout<<endl;
            cout<<" *_____* "<<endl;
            cout<<"| ♣     |"<<endl;
            cout<<"|   "<<(char)number<<"   |"<<endl;
            cout<<"|     ♣ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }
    } else {
        if (sut == 1){
            suit = 'D';
            cout<<endl;
            cout<<" *_____* "<<endl;
            cout<<"| ◆     |"<<endl;
            cout<<"|   "<<number<<"   |"<<endl;
            cout<<"|     ◆ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }
        else if (sut == 2){
            suit = 'S';
            cout<<endl;
            cout<<" *_____* "<<endl;
            cout<<"| ♠     |"<<endl;
            cout<<"|   "<<number<<"   |"<<endl;
            cout<<"|     ♠ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }
        else if (sut == 3){
            suit = 'H';
            cout<<endl;
            cout<<" *_____*"<<endl;
            cout<<"| ♥     |"<<endl;
            cout<<"|   "<<number<<"   |"<<endl;
            cout<<"|     ♥ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }
        else if (sut == 4){
            suit = 'C';
            cout<<endl;
            cout<<" *_____* "<<endl;
            cout<<"| ♣     |"<<endl;
            cout<<"|   "<<number<<"   |"<<endl;
            cout<<"|     ♣ |"<<endl;
            cout<<" *_____* "<<endl;
            cout<<endl;
        }
    }
    return suit;
}


//returns the card number
int Card::printNum() {
	return number;
}

//returns the card value
int Card::printValue() {
	return value;
}

//general function of the card deck (class initilization)
Deck::Deck() {
	cards.reserve(52);
	init();
}
//class destructor
Deck::~Deck() {}

//mixing the deck (shuffling) randomly
void Deck::mixDeck()
{

	std::random_device rd;
	std::mt19937 g(rd());
	
	std::shuffle(cards.begin(), cards.end(), g);
}

//shows the remaining number of cards in deck
int Deck::printRemainCardsNum() {
	return (int)cards.size();
}

//function for drawing a card from the deck and setting the size and the deck again after card being drawed. Returns the altered card deck.
Card Deck::drawACard() {
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

//Initilization of deck (52 cards)
void Deck::init() {
	Card NewCard;
	int card_array[52] = {1, 2, 3, 4, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 27, 28, 29, 32, 33, 34, 35, 36, 37, 38, 39, 42, 43, 44, 45, 46, 47, 48, 49, 100, 110, 120, 130, 200, 210, 220, 230, 300, 310, 320, 330, 400, 410, 420, 430};
	cards.clear();
	for (int i = 0; i < 52; i++) {
		NewCard.cardName = card_array[i];
		cards.push_back(NewCard);
	}
}

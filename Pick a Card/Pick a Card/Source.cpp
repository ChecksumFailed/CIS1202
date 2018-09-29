#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string>
#include <cstdlib> //needed for rand and srand
#include <istream>
#include <ctime> // needed to get system time


using namespace std;


enum suits { CLUBS, DIAMONDS, HEARTS, SPADES };
enum cardValues { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

//definition of playing card
struct cards {
	suits suit;
	cardValues card;
};


//funcitons
void createDeck(cards[]);  //creates 52 card deck
void printDeck(cards[]); //prints out deck
void printCard(cards); //Prints single card
void deal(cards[],cards&);
void winner(cards,	cards);
string getDisplayValue(cardValues);
string getDisplayValue(suits);


int main() {
	const int deckSize = 52;
	cards deck[deckSize];
	cards card1, card2;
	
	//Seed random number generator
	unsigned seed = time(0); //use system time as seed
	srand(seed); //seed random number generator


	createDeck(deck); // create a adeck of 52 cards
	printDeck(deck); // print out deck

	deal(deck, card1); //deal random card and assign to card1
	deal(deck, card2); //deal random card and assign to card2

	cout << "\nCard 1 = ";
	printCard(card1) ;
	cout << "Card 2 = ";
	printCard(card2) ;

	winner(card1, card2); //Determine winning card and print results


	//pauses program
	cout << "\nPress enter key to exit program\n";
	cin.clear();
	cin.get();
	return 0;
}


void createDeck(cards deck[]) {
	int cardNum = 0;
	for (int i = 0; i < 4; i++) { //suits
		for (int j = 0; j < 13; j++) {//cards
			deck[cardNum].suit = static_cast<suits>(i);
			deck[cardNum].card = static_cast<cardValues>(j);
			cardNum++;
		}
	}
}

void printDeck(cards deck[]) {
	cout << "\nThe card deck: \n\n";
	for (int i = 0; i < 52; i++) {
		printCard(deck[i]);
	}
	cout << endl;
}

void printCard(cards card) {
	cout << getDisplayValue(card.card) << " of " << getDisplayValue(card.suit) << endl;
}

string getDisplayValue(suits suit)
{
	switch (suit)
	{
	case HEARTS:
		return "Hearts";
		break;
	case DIAMONDS:
		return "Diamonds";
		break;
	case CLUBS:
		return "Clubs";
		break;
	case SPADES:
		return "Spades";
		break;
	 default:
		 return "Invalid Suit";
	}
}

string getDisplayValue(cardValues cardVal)
{
	switch (cardVal)
	{
	case ACE:
		return "Ace";
		break;
	case TWO:
		return "Two";
		break;
	case THREE:
		return "Three";
		break;
	case FOUR:
		return "Four";
		break;
	case FIVE:
		return "Five";
		break;
	case SIX:
		return "Six";
		break;
	case SEVEN:
		return "Seven";
		break;
	case EIGHT:
		return "Eight";
		break;
	case NINE:
		return "Nine";
		break;
	case TEN:
		return "Ten";
		break;
	case JACK:
		return "Jack";
		break;
	case QUEEN:
		return "Queen";
		break;
	case KING:
		return "King";
		break;
	default:
		return "Invalid Card Value";
	}
}

void deal(cards deck[], cards& theCard) {

	theCard = deck[rand() % 52]; //return random number between 0 - 51

}

void winner(cards card1, cards card2) {
	if (card1.card > card2.card) {
		cout << "\n\nCard 1 wins, ";
		printCard(card1);
	}
	else if(card2.card > card1.card) {
		cout << "\n\nCard 2 wins, ";
		printCard(card2);
	}
	else {
		cout << "Its a tie!" << endl;
	}
}

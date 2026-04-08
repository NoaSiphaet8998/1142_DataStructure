#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdexcept>  // for throwing errors
using namespace std;

// represents a single playing card
class Card {
public:
    string colors; // suit (Hearts, Spades, etc.)
    string rank;   // value (A, 2~10, J, Q, K)

    // constructor: runs when a Card is created
    Card(string s, string r) : colors(s), rank(r) {}

    // prints the card
    void display() const {
        cout << rank << " of " << colors << endl;
    }
};

// stack implementation (LIFO: last in, first out)
class Stack {
private:
    vector<Card> stack;

public:
    // add a card to the top
    void push(const Card& card) {
        stack.push_back(card);
    }

    // remove and return the top card
    Card pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty!"); // throw error
        }

        Card topCard = stack.back(); // get the last card
        stack.pop_back();            // remove it
        return topCard;              // return the removed card
    }

    // check if stack is empty
    bool isEmpty() const {
        return stack.empty();
    }
};

// represents a full deck of cards
class Deck {
private:
    vector<Card> cards;
    Stack shuffledDeck;

public:
    // constructor: creates 52 cards
    Deck() {
        string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" }; // suits
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9",
                           "10", "J", "Q", "K", "A" }; // values

        // generate all 52 combinations
        for (int i = 0; i < 4; i++) {        // loop suits
            for (int j = 0; j < 13; j++) {   // loop ranks
                cards.push_back(Card(colors[i], ranks[j])); // create card
            }
        }
    }

    // shuffle the deck and move into stack
    void shuffleDeck() {
        random_device rd;     // random seed
        mt19937 g(rd());      // random number generator

        shuffle(cards.begin(), cards.end(), g); // shuffle the vector

        // push shuffled cards into stack
        for (int i = 0; i < cards.size(); i++) {
            shuffledDeck.push(cards[i]);
        }
    }

    // draw (print) all cards from stack
    void drawAllCards() {
        // keep drawing until stack is empty
        while (!shuffledDeck.isEmpty()) {
            Card c = shuffledDeck.pop(); // take top card
            c.display();                 // show the top card
        }
    }
};

int main() {
    Deck deck;            // create the base deck (52 cards auto-generated)
    deck.shuffleDeck();   // shuffle and load into a stack

    cout << "Shuffled deck:" << endl;
    deck.drawAllCards();  // draw all cards one by one

    return 0;
}

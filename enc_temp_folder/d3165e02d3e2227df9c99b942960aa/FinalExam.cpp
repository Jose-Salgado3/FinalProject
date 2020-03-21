#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

const int DECK_SIZE = 52;
const array<string, DECK_SIZE> cards{
		 "AH", "AC", "AD", "AS",
		 "2H", "2C", "2D", "2S",
		 "3H", "3C", "3D", "3S",
		 "4H", "4C", "4D", "4S",
		 "5H", "5C", "5D", "5S",
		 "6H", "6C", "6D", "6S",
		 "7H", "7C", "7D", "7S",
		 "8H", "8C", "8D", "8S",
		 "9H", "9C", "9D", "9S",
		 "10H", "10C", "10D", "10S",
		 "JH", "JC", "JD", "JS",
		 "QH", "QC", "QD", "QS",
		 "KH", "KC", "KD", "KS", };

void initializeDeck(array<const string*, DECK_SIZE>* deck);
void displayDeck(array<const string*, DECK_SIZE> deck);
void shuffleDeck(array<const string*, DECK_SIZE>* deck);
void printMenu();

int main() {

	//Create own deck [array of pointers] pointing to const strings.(array above)

	//52 pointer array.
	array<const string*, DECK_SIZE> deck;
	
	//Sends array of pointers as a reference (&deck) 
	initializeDeck(&deck);

	int userChoice = -1;
	while (userChoice != 0) {
		printMenu();
		cin >> userChoice;
		if (userChoice == 1) {
			shuffleDeck(&deck);
		}
		else if (userChoice == 2) {
			displayDeck(deck);
		}
	}

	system("pause");
	return 0;
}

// Takes in the address of deck as a pointer
// De-Reference pointers

// Will store the exact same deck as before when this initializes.
// BUT WITH POINTERS?

void initializeDeck(array<const string*, DECK_SIZE>* deck) {

	for (size_t i = 0; i < DECK_SIZE; ++i) {
		//deref pointer at address [i] and store 
		// store inside memoryaddress and store inside of it memory of cards{i}
		//value       address
		(*deck)[i] = &cards[i];
	}
}

void printMenu() {
	cout << "0 - Quit" << endl;
	cout << "1 - Shuffle deck" << endl;
	cout << "2 - Display deck" << endl;
}

void displayDeck(array<const string*, DECK_SIZE> deck) {
	
	cout << "Display the deck here" << endl;
	
	for (size_t i = 0; i < DECK_SIZE; i += 4)
	{
		// This if statement will keep from an out of bounds exception.
		if (i < DECK_SIZE - 2)
		{
			cout << (*deck[i]) << " " << (*deck[i + 1]) << " " << (*deck[i + 2]) << " " << (*deck[i + 3]) << "\n";
		}
	}
}

void shuffleDeck(array<const string*, DECK_SIZE> * deck) {
	// TO DO: REPLACE THE BODY OF THIS FUNCTION
	cout << "Shuffle the deck here" << endl;
	
	static default_random_engine engine(static_cast<unsigned int>(time(0)));

	//Non static version of call from random generator.
	int count = 1;

	// lOOP TO PERFORM THE SWAP
	for (int i = DECK_SIZE - 1; i >= 0; i--)
	{	
		uniform_int_distribution<unsigned int> randomInt(0, i);

		int j = randomInt(engine);
		string temp = (*(*deck)[i]);

		if (i != j)
		{
			//cout << (*deck)[j] << "\n";
			//cout << (*(*deck)[i]) << "\n" << "\n";

			swap((*deck)[i], (*deck)[j]);
		}
		count++;
	}

	cout << count;
}	

	










// Program is crashing when randIndex == size.


//=======================================================================================================================================
//		WORKING VERSION TAMPLATE. BUT = WONT MOVE ACE OF HEARTS.
//
//=================================================================================================================================================
//void shuffleDeck(array<const string*, DECK_SIZE>* deck) {
//	// TO DO: REPLACE THE BODY OF THIS FUNCTION
//	cout << "Shuffle the deck here" << endl;
//
//
//	static default_random_engine engine(static_cast<unsigned int>(time(0)));
//
//	//Non static version of call from random generator.
//	uniform_int_distribution<unsigned int> randomInt(1, DECK_SIZE - 1);
//	int count = 1;
//
//
//	void* p1;
//	for (int i = DECK_SIZE - 1; i > 0; i--)
//	{
//		int randIndex = randomInt(engine);
//		string temp = (*(*deck)[i]);
//
//		// Testing to run the loop in reverse using dereferencing shows memory and string stored in memory/
//		//cout << (*(*deck)[i]) << " memory is" << &(*deck)[i] << endl;
//
//		// Have to use double ** to deref a pointer to a pointer
//		//<< (*deck)[i - 2] << " " << (*deck)[i - 3] << " " << (*deck)[i - 4] << endl;
//
//		if (i != randIndex && i > 0)
//		{
//
//			//Swap the memory allocations of each index.
//			//cout << (*deck)[randIndex] << "\n";// = const_cast<string*>(&temp);
//			//cout << (*deck)[i] << "\n" << "\n";
//
//
//
//			cout << (*deck)[randIndex] << "\n";// = const_cast<string*>(&temp);
//			cout << (*(*deck)[i]) << "\n" << "\n";
//
//			swap((*deck)[i], (*deck)[randIndex]);
//
//
//		}
//	}
//}

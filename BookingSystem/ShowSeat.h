#pragma once

#include <iostream>
#include <string>

using namespace std;

class ShowSeat {
	public:
		ShowSeat();
		~ShowSeat();
		void initaliseFloorPlan();
		int getNumberOfSeats();
		int chooseSeat();
	private:
		void displayFloorPlan(char floorPlan[5][5]);
		void calculatePrice(double &price);
		bool checkDecisionInput(int &numSeats);
		void allocateSeat(int row, int column);
	protected:
		char floorPlan[5][5];
		int numSeats;
		int rowNumber;
		double price;
};


ShowSeat::ShowSeat() {
	
}

ShowSeat::~ShowSeat() {

}

void ShowSeat::initaliseFloorPlan() {
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 6; column++) {
			floorPlan[row][column] = 'A';
		}
	}
	displayFloorPlan(floorPlan);
}

int ShowSeat::getNumberOfSeats() {
	cout << "\n======================== Select Seats ========================\n" << endl;

	do {
		cin.clear();
		cin.ignore(100, '\n');

		cout << "How many tickets would you like to purchase (Max. 8)?: ";

		cin >> numSeats;
		cout << endl;
	} while (checkDecisionInput(numSeats));

	return numSeats;
}

int ShowSeat::chooseSeat() {
	int row, column = 0;
	numSeats = getNumberOfSeats();

	for (int i = 0; i < numSeats; i++) {
		cout << "Number of wanted tickets: " << numSeats << endl;
		cout << "Selection for ticket number " << i + 1 << endl;
		do {
			cout << "Please enter desired row number (1 - 5): ";
			cin >> row;
		} while (row < 1 || row > 5);

		do {
			cout << "Please enter desired column number (1 - 5): ";
			cin >> column;
		} while (column < 1 || column > 5);

		allocateSeat(row, column);
	}
	return numSeats;
}

bool ShowSeat::checkDecisionInput(int &numSeats) {
	int validation = numSeats != 1 && numSeats != 2 && numSeats != 3 && numSeats != 4 && numSeats != 5 && numSeats != 6 && numSeats != 7 && numSeats != 8;
	return validation;
}

void ShowSeat::allocateSeat(int row, int column) {
	if (floorPlan[row - 1][column - 1] = 'A') {
		floorPlan[row - 1][column - 1] = 'B'; //Booked annotation
	} else {
		cout << "Please choose another seat." << endl;
	}
	displayFloorPlan(floorPlan);
}

void ShowSeat::displayFloorPlan(char floorPlan[5][5]) {
	//Render top of table
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "| S | 1 | 2 | 3 | 4 | 5 | " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	for (int row = 0; row < 5; row++) {
		cout << "| " << row + 1 << " | ";
		for (int column = 0; column < 5; column++) {
			cout << floorPlan[row][column] << " | ";

		}
		if (row != 6) cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	cout << "A = Available, B = Booked" << endl;
}



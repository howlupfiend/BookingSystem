#pragma once

#include <iostream>
#include <string>
#include "User.h"
#include "Show.h"

using namespace std;

class Ticket {
	public:
		Ticket();
		~Ticket();
		void getTicketPrice(int seatQuantity);
		void displayTicket(User user, Show show, int seatQuantity);
	private:
		void calculatePrice(int ticketInput);
	protected:
		double price;
		double discountPrice;
};

Ticket::Ticket() {
	price = 0;
	discountPrice = 0;
}

Ticket::~Ticket() {

}


void Ticket::getTicketPrice(int chosenSeatQuantity) {

	for (int i = 0; i < chosenSeatQuantity; i++) {
		int input;
		do {
			cout << "===== Ticket Discounts =====" << endl;
			cout << "Ticket no. :  " << i + 1 << endl;
			cout << "1 - Senior Citizen - " << (char)156 << "10" << endl;
			cout << "2 - Adult - " << (char)156 << "20" << endl;
			cout << "3 - Child - " << (char)156 << "5" << endl;
			cout << "4 - Student - " << (char)156 << "15" << endl;
			cout << "Please choose a ticket for your no." << i + 1 << ". ticket: ";
			cin >> input;
			
		} while (input < 1 || input > 4);
		calculatePrice(input);
		
	}
	cout << "The calculated total of your tickets is " << (char)156 << discountPrice << endl;
}

void Ticket::calculatePrice(int ticketInput) {
	switch (ticketInput) {
	case 1:
		price += 10;
		break;
	case 2:
		price += 20;
		break;
	case 3:
		price += 5;
		break;
	case 4:
		price += 15;
		break;
	}
	this->discountPrice = price;
}

void Ticket::displayTicket(User user,Show show, int seatQuantity) {
	cout << "----- Ticket Summary -----" << endl;
	cout << "--- Your information ---" << endl;
	cout << "Name: " << user.firstName << "  Surname: " << user.lastName << endl;
	cout << "Address: " << user.address << endl;
	cout << "----- Show Information -----" << endl;
	cout << "Show: " << show.showName << endl;
	cout << "Date: " << show.showDate << endl;
	cout << "Time: " << show.showTime << endl;
	cout << "----- Tickets -----" << endl;
	cout << "Number of seats brough: " << seatQuantity << endl;
	cout << "Total price: " << (char)156 << price << endl;
	cout << "-------------------" << endl;

}
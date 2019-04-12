#include "pch.h"
#include "Show.h"
#include "ShowSeat.h"
#include "Ticket.h"
#include <iostream>

int main()
{
	Show show, selectedShow;
	ShowSeat showSeat;
	Ticket ticket;
	User user, selectedUser;
	string showName, showTime, showDate;
	int selectedNoSeats;

	user.login();
	selectedUser = user.getCustomerProfile();
	selectedShow = show.selectShow(showName, showDate, showTime);
	showSeat.initaliseFloorPlan();
	selectedNoSeats = showSeat.chooseSeat();
	ticket.getTicketPrice(selectedNoSeats);
	ticket.displayTicket(selectedUser, selectedShow, selectedNoSeats);

}
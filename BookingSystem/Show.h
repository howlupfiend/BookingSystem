#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <vector>


using namespace std;

class Show
{
public:
	Show();
	~Show();
	Show selectShow(string &showName, string &showDate, string &showTime);;
	void getShows(const vector<Show> &listOfShows);
	vector<Show> defineShows();
	string showName, showDate, showTime;	
};

Show::Show()
{
	showName = "";
	showDate = "";
	showTime = "";
};

Show::~Show()
{

}

Show Show::selectShow(string &showName, string &showDate, string &showTime)
{
	int showInput;
	const vector<Show> listOfShows = defineShows();
	//TODO validation of input.
	do {
		cout << "Here are a list of shows to watch \n";
		getShows(listOfShows);
		cout << "=========================================== \n";
		cout << "Input what film you want to see: ";
		cin >> showInput;

		switch (showInput)
		{
		case 1: showName = listOfShows[showInput - 1].showName, showDate = listOfShows[showInput - 1].showDate, showTime = listOfShows[showInput - 1].showTime;
			break;
		case 2: showName = listOfShows[showInput - 1].showName, showDate = listOfShows[showInput - 1].showDate, showTime = listOfShows[showInput - 1].showTime;
			break;
		case 3: showName = listOfShows[showInput - 1].showName, showDate = listOfShows[showInput - 1].showDate, showTime = listOfShows[showInput - 1 ].showTime;
			break;
		}

		this->showName = showName;
		this->showDate = showDate;
		this->showTime = showTime;
		cout << "---- You have chosen ---- \n" << showName << " | " << showDate << " | " << showTime << endl;
		
		return listOfShows[showInput - 1];
	} while (showInput < 0 || showInput > 4);

}

void Show::getShows(const vector<Show> &listOfShows) {

	for (const Show &showInList : listOfShows) {
		cout << showInList.showName << " on " + showInList.showDate << " at " + showInList.showTime << endl;
	}
}

vector<Show> Show::defineShows() {
	Show Show1;
	Show Show2;
	Show Show3;
	Show Show4;

	vector<Show> listOfShows;

	//Define Show 1;
	Show1.showName = "1 - Les Miserables";
	Show1.showDate = "08/04/2019";
	Show1.showTime = "6pm";
	listOfShows.push_back(Show1);

	//Define Show 2;
	Show2.showName = "2 - Lion King";
	Show2.showDate = "09/04/2019";
	Show2.showTime = "2pm";
	listOfShows.push_back(Show2);

	//Define Show 3;
	Show3.showName = "3 - Shrek The Musical";
	Show3.showDate = "10/04/2019";
	Show3.showTime = "3pm";
	listOfShows.push_back(Show3);

	//Define Show 4;
	Show4.showName = "4 - Woman in Black";
	Show4.showDate = "11/04/2019";
	Show4.showTime = "5pm";
	listOfShows.push_back(Show4);

	return listOfShows;
}

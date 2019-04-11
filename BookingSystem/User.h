#pragma once

using namespace std;

class User {
public:
	User();
	~User();
	void login();
	User getCustomerProfile();
	string firstName, lastName, address;
};

User::User() {
	firstName = "john";
	lastName = "appleseed";
	address = "10 test street";
}

User::~User() {

}

void User::login() {
	string username, password;

	cout << "Welcome to The Bucks Center for The Performing Arts" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Please login." << endl;
	cout << "Enter Username: ";
	getline(cin, username);
	cout << "Enter Password (minimum 5 characters): ";
	getline(cin, password); 
}

User User::getCustomerProfile() {
	User addedUser;
	cout << "Please enter your profile information:" << endl;
	cout << "First name: ";
	getline(cin, firstName);
	cout << "Last name: ";
	getline(cin, lastName);
	cout << "Address name: ";
	getline(cin, address);
	cout << "Thank you for entering your profile information" << endl;

	addedUser.firstName = firstName;
	addedUser.lastName = lastName;
	addedUser.address = address;

	return addedUser;
}
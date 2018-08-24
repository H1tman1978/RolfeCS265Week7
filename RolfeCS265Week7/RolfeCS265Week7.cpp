/*
Author: Anthony Rolfe
Class: CS265
Institution: Grantham University

This program allows the user to manage the bookings of seats on an aircraft with 13 rows of seats with 6 seats per row. Seats 'A' and 'F' are considered Window Seats with seats 'C' and 'D' considered Aisle Seats. Additionally, rows 1 and 2 are considered First Class seats, rows 3 - 7 are Business Class seats and 8 - 13 are Economy Class seats. This program displays the use of multi-dimensional arrays and is for demonstration purposes.
*/

#include <iostream>
#include <iomanip>
#include <tuple>

//Constants
const int ROWS = 13;
const int SEATS = 6;
const int FC_MIN = 0;
const int FC_MAX = 2;
const int BUS_MIN = 2;
const int BUS_MAX = 7;
const int ECO_MIN = 7;
const int ECO_MAX = 13;
const int SEAT_MIN = 0;
const int SEAT_MAX = 6;

//seatMatrix datatype
//typedef char seatMatrix[ROWS][SEATS];

int displayMenu() {  //This function displays the main menu
	int selection;
	system("CLS");
	std::cout << "**********MAIN MENU**********" << std::endl;
	std::cout << "1 - Display Seats" << std::endl;
	std::cout << "2 - Book a Seat" << std::endl;
	std::cout << "9 - Quit program" << std::endl;
	std::cout << "*****************************" << std::endl;
	std::cout << "What is your selection? ";
	std::cin >> selection;
	return selection;
}

void displaySeats(char seats[ROWS][SEATS]) {  //This function displays the current booking status of all the seats
	system("CLS");
	
	std::cout << std::setw(11) << "A" << std::setw(5) << "B" << std::setw(5) << "C" << std::setw(5) << "D" << std::setw(5) << "E" << std::setw(5) << "F" << std::endl;
	for (int i = 0; i < ROWS; i++) {
		std::cout << "Row " << std::setw(2) << (i + 1);
		for (int j = 0; j < SEATS; j++) {
			std::cout << std::setw(5) << seats[i][j];
		}
		std::cout << std::endl;
	}
	system("PAUSE");
}

std::tuple<int, int> bookSeat(char seats[ROWS][SEATS]) { //This function will allow the user to "book" a seat based on seat class (First Class, etc) and seat location (window, aisle or either)
	//Variable Declaration
	char seatClass, seatLocation;  // Input variables to determine where to find the seat to book
	bool validInput = false, foundSeat = false; //Control variables

	while (!validInput) //Loop runs until we have valid input for both seatClass and seatLocation
	{
		system("CLS");
		std::cout << "Welcome to the Seat Booking Menu!" << std::endl;
		std::cout << "In which class of seat do you wish to book?" << std::endl;
		std::cout << "Please enter 'F' for First Class, 'B' for Business Class or 'E' for Economy Class: ";
		std::cin >> seatClass;
		if (toupper(seatClass) == 'F' || toupper(seatClass) == 'B' || toupper(seatClass) == 'E')
		{
			validInput = true;
		}
		else
		{
			std::cout << "Invalid input...let's try again";
			continue;
		}
		std::cout << "Which seat location would you like to book?" << std::endl;
		std::cout << "Please enter 'W' for Window, 'A' for Aisle or 'D' for doesn't matter: ";
		std::cin >> seatLocation;
		if (toupper(seatLocation) == 'W' || toupper(seatLocation) == 'A' || toupper(seatLocation) == 'D')
		{
			validInput = true;
		}
		else
		{
			std::cout << "Invalid input...let's try again";
			continue;
		}
	}

	while (!foundSeat)
	{  //This loops finds a seat to book from the array of seats.
		switch (seatClass)
		{
		case 'F': //First Class search
			switch (seatLocation)
			{
			case 'W': //Window Seat search
				for (int i = FC_MIN; i < FC_MAX; i++) 
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						std::cout << seats[i][j] << " ";
						if (seats[i][j] != 'X' && foundSeat != true && j == 0 || j == 5) //Seats 0 and 5 represent the window seats
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			case 'A':
				for (int i = FC_MIN; i < FC_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (seats[i][j] != 'X' && foundSeat != true && j == 2 || j == 3) //Seats 2 and 3 represent the Aisle seats
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;							
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
			break;
			case 'D':			
				for (int i = FC_MIN; i < FC_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (seats[i][j] != 'X' && foundSeat != true)
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			default:
				break;
			}
		case 'B':
			switch (seatLocation)
			{
			case 'W':
				for (int i = BUS_MIN; i < BUS_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (seats[i][j] != 'X' && foundSeat != true && j == 0 || j == 5) //Seats 0 and 5 represent the window seats
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			case 'A':
				for(int i = BUS_MIN; i < BUS_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (seats[i][j] != 'X' && foundSeat != true && j == 2 || j == 3) //Seats 2 and 3 represent the Aisle seats
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			case 'D':
				for (int i = BUS_MIN; i < BUS_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (seats[i][j] != 'X' && foundSeat != true)
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			default:
				break;
			}
		case 'E':
			switch (seatLocation)
			{
			case 'W':
				for (int i = ECO_MIN; i < ECO_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (j == 0 || j == 5 && seats[i][j] != 'X' && foundSeat != true) //Seats 0 and 5 represent the window seats
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			case 'A':
				for (int i = ECO_MIN; i < ECO_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (seats[i][j] != 'X' && foundSeat != true && j == 2 || j == 3) //Seats 2 and 3 represent the Aisle seats
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			case 'D':
				for (int i = ECO_MIN; i < ECO_MAX; i++)
				{ //Iterate through the rows
					for (int j = SEAT_MIN; j < SEAT_MAX; j++)
					{ //Iterate through the seats
						if (seats[i][j] != 'X' && foundSeat != true)
						{
							std::cout << "A seat has been booked in Row " << i + 1 << ", Seat " << char(j + 65) << "." << std::endl;
							foundSeat = true;
							system("PAUSE");
							return std::make_tuple(i, j);
						}
					}
				}
				break;
			default:
				break;
			}
		default:
			break;
		}
	}	
	system("PAUSE");
	return std::make_tuple(-1, -1);  //If the program reaches this line of code something went wrong.
}

int main() {
	//Variable Declaration
	int menuSelection;
	bool running = true;
	std::tuple<int, int> seatIndex;

	//Declaration/Initialize Array
	char seats[ROWS][SEATS] = 
	{   //A    B    C    D    E    F
		{'*', '*', 'X', '*', 'X', 'X'},  //row 1  
	    {'*', 'X', '*', 'X', '*', 'X'},  //row 2
	    {'*', '*', 'X', 'X', '*', 'X'},  //row 3
	    {'X', '*', 'X', '*', 'X', 'X'},  //row 4
	    {'*', 'X', '*', 'X', '*', '*'},  //row 5
	    {'*', 'X', '*', '*', '*', 'X'},  //row 6
	    {'X', '*', '*', '*', 'X', 'X'},  //row 7
	    {'*', 'X', '*', 'X', 'X', '*'},  //row 8
	    {'X', '*', 'X', 'X', '*', 'X'},  //row 9
	    {'*', 'X', '*', 'X', 'X', 'X'},  //row 10
	    {'*', '*', 'X', '*', 'X', '*'},  //row 11
	    {'*', '*', 'X', 'X', '*', 'X'},  //row 12
	    {'*', '*', '*', '*', 'X', '*'},  //row 13
	};

	//Program loop
	while (running) {
		menuSelection = displayMenu();
		switch (menuSelection)
		{
		case 1:
			displaySeats(seats);
			break;
		case 2:
			seatIndex = bookSeat(seats);
			seats[std::get<0>(seatIndex)][std::get<1>(seatIndex)] = 'X';
			break;
		case 9:
			running = false;
			break;
		default:
			break;
		}
	}
	std::cout << "Have a nice day...Goodbye!!" << std::endl;
	system("PAUSE");
	return 0;
}

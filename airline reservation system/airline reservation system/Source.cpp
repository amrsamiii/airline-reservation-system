#include <iostream>
#include <stdio.h>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
using namespace std;
void signup();
void distination();
void personal_information();
void show_ticket();
void Modify();







int main()
{
	signup();
	distination();
	personal_information();
	show_ticket();
	system("cls");
	cout << "\t\t**************\t\t" << endl;
	cout << "\t\t\tAirLine Reservation System\t " << endl;
	cout << "\t\t**************\t\t";
	cout << endl;
	int more_option;
	while (true) {


		cout << "\t(1) Add new flight" << endl;
		cout << "\t(2) Modify your flight" << endl;
		cout << "\t(3) Cancel your flight" << endl;
		cout << "\t(4) show your reservation" << endl;
		cout << "\t(5) logout from the system" << endl;
		cout << endl;
		cout << "\t\t**************\t\t";
		cout << endl;

		cin >> more_option;
		system("cls");
		if (more_option == 1) {
			distination();
			personal_information();
			system("cls");
			break;
		}
		else if (more_option == 2) {
			Modify();
			system("cls");
			break;
		}
		else if (more_option == 3) {
			system("cls");
			break;
		}
		else if (more_option == 4) {
			show_ticket();
			system("pause");
			system("cls");
			break;
		}
		else if (more_option == 5) {
			exit(0);
			system("cls");
			break;
		}
		cout << "\t\t Please Enter A valid number : ";
		cout << " \tSelect Valid Choose(1 or 2 or 3 or 4 or 5).\n";
	}




}
void Modify() {
	system("cls");
	cout << "\t\t**************\t\t\n";
	cout << "\t\t\tAirLine Reservation System\t " << endl;
	cout << "\t\t**************\t\t";
	cout << "\t\n\n" << endl;
	string line;
	int one_or_two;
	while (true) {
		cout << "Do You Booked (1)One Way Or (2)Two Way Flight?" << endl;
		cin >> one_or_two;
		if (one_or_two == 1 || one_or_two == 2) {
			break;
		}
		else cout << "Enter Valid Choose\n";
	}
	if (one_or_two == 1) {
		fstream out_file;
		out_file.open("date information.txt");
		cout << "\n\n***************************\n";
		for (int i = 0; i < 2; i++) {
			getline(out_file, line);
			cout << "Your Old " << line << endl;
		}
		cout << "\n***************************\n\n";
	}
	else if (one_or_two == 2) {
		fstream out_file;
		out_file.open("date information.txt");
		cout << "\n***************************\n\n";

		for (int i = 0; i < 4; i++) {
			getline(out_file, line);
			cout << "Your " << line << endl;
		}cout << "\n***************************\n\n";
	}
	int reservation;
	while (true) {
		cout << "Do You Want To Change It To\n";
		cout << "\t1.OneWay\n";
		cout << "\t2.Round Trip\n";
		cout << "Choose Number: ";

		cin >> reservation;
		if (reservation == 1 || reservation == 2) {

			break;
		}
		else cout << " \tSelect Valid Choose(1 or 2).\n";
	}


	if (reservation == 1) {

		fstream out_file;
		out_file.open("date information.txt");
		long long dayoneway, monthoneway;
		cout << "\t Enter New Date of Flight: " << endl;
		while (true) {
			cout << "\t\tDay" << ':';
			cin >> dayoneway;

			cout << "\t\tMonth" << ':';
			cin >> monthoneway;

			if ((monthoneway == 1) || (monthoneway == 3) || (monthoneway == 5) || (monthoneway == 7) || (monthoneway == 8) || (monthoneway == 10) || (monthoneway == 12) && (dayoneway > 0) && (dayoneway <= 31)) {
				cout << "valid date.\n";
				break;
			}
			else if ((monthoneway == 4) || (monthoneway == 6) || (monthoneway == 11) || (monthoneway == 9) && (dayoneway > 0) && (dayoneway <= 30)) {
				cout << "valid date.\n";
				break;
			}
			else if ((monthoneway == 2) && (dayoneway > 0) && (dayoneway <= 29)) {
				cout << "valid date.\n";
				break;
			}
			cout << "\tplease enter valid date.\n";
		}
		out_file << "Day Of One Way Flight Is " << dayoneway << endl;
		out_file << "Month Of One way Flight Is " << monthoneway << endl;
		out_file.close();



	}
	else if (reservation == 2) {


		fstream out_file;
		out_file.open("date information.txt");
		long long day_departure_twoway, month_departure_twoeway;
		cout << "\t Enter New Depature Date " << endl;
		while (true) {

			cout << "\t\tDay" << ':';
			cin >> day_departure_twoway;
			cout << "\t\tMonth" << ':';
			cin >> month_departure_twoeway;
			if ((month_departure_twoeway == 1) || (month_departure_twoeway == 3) || (month_departure_twoeway == 5) || (month_departure_twoeway == 7) || (month_departure_twoeway == 8) || (month_departure_twoeway == 10) || (month_departure_twoeway == 12) && (day_departure_twoway > 0) && (day_departure_twoway <= 31)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_departure_twoeway == 4) || (month_departure_twoeway == 6) || (month_departure_twoeway == 11) || (month_departure_twoeway == 9) && (day_departure_twoway > 0) && (day_departure_twoway <= 30)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_departure_twoeway == 2) && (day_departure_twoway > 0) && (day_departure_twoway <= 29)) {
				cout << "valid date.\n";
				break;
			}
			cout << "\tplease enter valid date.\n";
		}
		long long day_return_twoway, month_return_twoway;
		cout << "\t Enter New Return Date " << endl;
		while (true) {
			cout << "\t\tDay" << ':';
			cin >> day_return_twoway;
			cout << "\t\tMonth" << ':';
			cin >> month_return_twoway;
			if (day_departure_twoway == day_return_twoway) {
				if (month_departure_twoeway < month_return_twoway) {
					cout << "valid date.\n";
					break;
				}
			}
			else if (day_departure_twoway < day_return_twoway) {
				cout << "valid date.\n";
				break;
			}
			else if (month_departure_twoeway == month_return_twoway) {
				if (day_departure_twoway < day_return_twoway) {
					cout << "valid date.\n";
					break;
				}
			}
			else if (month_return_twoway > month_departure_twoeway) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_return_twoway == 1) || (month_return_twoway == 3) || (month_return_twoway == 5) || (month_return_twoway == 7) || (month_return_twoway == 8) || (month_return_twoway == 10) || (month_return_twoway == 12) && (day_return_twoway > 0) && (day_return_twoway <= 31)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_return_twoway == 4) || (month_return_twoway == 6) || (month_return_twoway == 11) || (month_return_twoway == 9) && (day_return_twoway > 0) && (day_return_twoway <= 30)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_return_twoway == 2) && (day_return_twoway > 0) && (day_return_twoway <= 29)) {
				cout << "valid date.\n";
				break;
			}
			cout << "\tplease enter valid date.\n";
		}
		out_file << "Departure Day Of Two Way Flight Is " << day_departure_twoway << endl;
		out_file << "Departure Month Of Two Way Flight Is " << month_departure_twoeway << endl;
		out_file << "Return Day Of Two Way Flight Is " << day_return_twoway << endl;
		out_file << "Return Month Of Two Way Flight Is " << month_return_twoway << endl;
		out_file.close();


	}
	fstream out_file;
	out_file.open("date information.txt");
	if (reservation == 1) {
		for (int i = 0; i < 2; i++) {
			getline(out_file, line);
			cout << "Your New " << line << endl;
		}
	}
	else if (reservation == 2) {

		for (int i = 0; i < 4; i++) {
			getline(out_file, line);
			cout << "Your New " << line << endl;
		}

	}
	system("pause");
}

void signup()
{
	char login_password[20];
	char stored_pasword[20];
	char login_username[20];
	char stored_username[20];


	int choose_signup_or_login;

	cout << "Choose Number (1 or 2)\n";

	cout << "\t1.signup\n";
	cout << "\t2.login\n";


	while (true) {
		cin >> choose_signup_or_login;
		system("cls");



		if (choose_signup_or_login == 1) {
			cout << "\tSignup\t" << endl;



			ofstream pull("users.txt", ios::app);
			cout << "username:";
			cin >> login_username;
			cout << "password:";
			cin >> login_password;
			pull << login_username << "\t";
			pull << login_password << "\t" << endl;
			cout << "\tSignup Successful.\t " << endl;
			system("pause");
			system("cls");
			break;
		}






		if (choose_signup_or_login == 2) {
			cout << "\tLogin\t" << endl;


			fstream pull("users.txt", ios::in);
			if (!pull) {

				cout << "\tfile not loaded!" << endl;

			}
			cout << "username:";

			cin >> login_username;
			while (strcmp(login_username, stored_username)) {

				pull >> stored_username;
				if (pull.eof()) {
					cout << "username doesn't exist." << endl;
					exit(0);

				}


			}
			pull >> stored_pasword;

			cout << "password:";
			cin >> login_password;
			while (strcmp(stored_pasword, login_password)) {
				cout << "wrong password" << endl;
				cout << "try again: ";
				cin >> login_password;


			}
			cout << "\tLogin Successful." << endl;
			system("pause");
			system("cls");
			break;
		}
		cout << "\tEnter Valid Number";
	}
}




void distination()
{
	int Reseravation;
	int  Number_of_Airplane;
	cout << "\t\t****************************************\t\t\n";
	cout << "\t\t\tAirLine Reservation System\t " << endl;
	cout << "\t\t****************************************\t\t";
	cout << "\t" << endl;

	int destination;

	cout << endl;
	cout << "1. Cairo : Abu dhabi(1) " << endl << "2. Cairo : New york(2)" << endl << "3. Cairo : Istanbol(3)" << endl << "4. Cairo : Dubai(4)" << endl << "5. Cairo : Sharm El Sheikh(5)" << endl << "6. Cairo : luxor(6)" << endl << "7. Cairo : Aswan(7)" << endl << "8. Cairo : Hurghada(8)" << endl << endl;
	// enter destination error 
	while (true) {
		cout << "\tEnter Destination Number: ";
		cin >> destination;
		cout << "\n\t***************************\n";
		if (destination == 1) {
			cout << "From : cairo (Eygpt)" << "   " << "To : Abu Dhabi (Emirates)";
			break;
		}
		if (destination == 2) {
			cout << "From : Cairo (Eygpt) " << "  " << "To : New york (U.S.A)";
			break;
		}
		if (destination == 3) {
			cout << "From : cairo (Eygpt)" << "   " << "To : Istanboul (Turkey)";
			break;

		}
		if (destination == 4) {
			cout << "From : cairo (Eygpt)" << "   " << "To : Dubai (Emirates)";
			break;

		}if (destination == 5) {
			cout << "From : cairo (Eygpt)" << "   " << "To : Sharm El Sheikh (Egypt)";
			break;

		}if (destination == 6) {
			cout << "From : cairo (Eygpt)" << "   " << "To : Luxor (Egypt)";
			break;

		}if (destination == 7) {
			cout << "From : cairo (Eygpt)" << "   " << "To : Asswan (Egypt)";
			break;

		}if (destination == 8) {
			cout << "From : cairo (Eygpt)" << "   " << "To : Hurghada (Egypt) ";
			break;

		}
		cout << " \tPlease enter a valid destination: \n";
	}

	//enter one way or two way choose error 
	cout << endl;
	while (true) {
		cout << "\t1.OneWay\n";
		cout << "\t2.Round Trip\n";
		cout << "Choose Number: ";
		cin >> Reseravation;
		if (Reseravation == 1 || Reseravation == 2) {

			break;
		}
		else cout << " \tSelect Valid Choose(1 or 2).\n";
	}



	if (Reseravation == 1) {
		long long dayoneway, monthoneway;
		cout << "\t Enter Date of Flight: " << endl;
		while (true) {
			cout << "\t\tDay" << ':';
			cin >> dayoneway;
			cout << "\t\tMonth" << ':';
			cin >> monthoneway;
			if ((monthoneway == 1) || (monthoneway == 3) || (monthoneway == 5) || (monthoneway == 7) || (monthoneway == 8) || (monthoneway == 10) || (monthoneway == 12) && (dayoneway > 0) && (dayoneway <= 31)) {
				cout << "valid date.\n";
				break;
			}
			else if ((monthoneway == 4) || (monthoneway == 6) || (monthoneway == 11) || (monthoneway == 9) && (dayoneway > 0) && (dayoneway <= 30)) {
				cout << "valid date.\n";
				break;
			}
			else if ((monthoneway == 2) && (dayoneway > 0) && (dayoneway <= 29)) {
				cout << "valid date.\n";
				break;
			}
			cout << "\tplease enter valid date.\n";
		}


		system("cls");
		cout << "\t\t****************************************\t\t" << endl;
		cout << "\t\t\tAirLine Reservation System\t " << endl;
		cout << "\t\t****************************************\t\t";
		cout << "\t" << endl;

		bool flag = false;
		string filename, line;
		ifstream infile;
		infile.open("xxx.txt");
		for (int i = 0; i < 71; i++) {
			getline(infile, line);
			if (destination == 1 && i < 10) {         //abu dhapi
				cout << line << endl;

				continue;

			}
			else if (destination == 2 && i > 9 && i < 20) {
				cout << line << endl;                               //newyork
				continue;
			}
			else if (destination == 3 && i > 19 && i < 28) {
				cout << line << endl;                        //istanbul
				continue;
			}
			else if (destination == 4 && i > 27 && i < 38) {
				cout << line << endl;                       //dubai                      
				continue;
			}
			else if (destination == 5 && i > 37 && i < 46) {
				cout << line << endl;                      //sharm
				continue;
			}
			else if (destination == 6 && i > 45 && i < 55) {
				cout << line << endl;                      //aswan
				continue;
			}
			else if (destination == 7 && i > 54 && i < 64) {
				cout << line << endl;                      //axour
				continue;
			}
			else if (destination == 8 && i > 63 && i < 71) {
				cout << line << endl;                              //hurghadaa
				continue;
			}
		}
		if (destination == 1 || destination == 2 || destination == 3 || destination == 4 || destination == 5 || destination == 6 || destination == 7 || destination == 8) {
			flag = true;
		}
		if (flag) {
			cout << " " << endl;
		}

		else cout << "in valid" << endl;




		while (true) {

			cout << "Select Flight Number Please :" << endl;
			cin >> Number_of_Airplane;
			if (destination == 1 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 2 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 3 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3)) {
				break;
			}
			else if (destination == 4 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 5 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4)) {
				break;
			}
			else if (destination == 6 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 7 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 8 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3)) {
				break;
			}
			cout << "\tEnter valid choose.\n";
		}



		infile.close();


		infile.open("xxx.txt");
		ofstream outfile;
		outfile.open("flight information.txt");//one way

		for (int i = 0; i < 71; i++) {
			getline(infile, line);
			if (destination == 1) {
				if (Number_of_Airplane == 1 && i > 2 && i < 4) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 3 && i < 5) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 4 && i < 6) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 5 && i < 7) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 6 && i < 8) {

					cout << line << endl;
					continue;
				}
				else {
					cout << " ";
				}

			}

			if (destination == 2) {
				if (Number_of_Airplane == 1 && i > 12 && i < 14) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 13 && i < 15) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 14 && i < 16) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 15 && i < 17) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 16 && i < 18) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}
			}

			if (destination == 3) {
				if (Number_of_Airplane == 1 && i > 22 && i < 24) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 23 && i < 25) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 24 && i < 26) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else {
					cout << " ";
				}
			}

			if (destination == 4) {
				if (Number_of_Airplane == 1 && i > 30 && i < 32) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 31 && i < 33) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 32 && i < 34) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 33 && i < 35) {

					cout << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 34 && i < 36) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}

			}

			if (destination == 5) {
				if (Number_of_Airplane == 1 && i > 40 && i < 42) {
					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 41 && i < 43) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 42 && i < 44) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 43 && i < 45) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else {
					cout << " ";
				}

			}
			if (destination == 6) {
				if (Number_of_Airplane == 1 && i > 48 && i < 50) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 49 && i < 51) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 50 && i < 52) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 51 && i < 53) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 52 && i < 54) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}

			}
			if (destination == 7) {
				if (Number_of_Airplane == 1 && i > 57 && i < 59) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 58 && i < 60) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 59 && i < 61) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 60 && i < 62) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 61 && i < 63) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}

			}
			if (destination == 8) {
				if (Number_of_Airplane == 1 && i > 66 && i < 68) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 67 && i < 69) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 68 && i < 70) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else {
					cout << " ";
				}

			}

		}
		outfile.close();
		infile.close();
		system("pause");
	}

	else if (Reseravation == 2) {
		long long day_departure_twoway, month_departure_twoeway;
		cout << "\t Enter Depature Date " << endl;
		while (true) {
			cout << "\t\tDay" << ':';
			cin >> day_departure_twoway;
			cout << "\t\tMonth" << ':';
			cin >> month_departure_twoeway;
			if ((month_departure_twoeway == 1) || (month_departure_twoeway == 3) || (month_departure_twoeway == 5) || (month_departure_twoeway == 7) || (month_departure_twoeway == 8) || (month_departure_twoeway == 10) || (month_departure_twoeway == 12) && (day_departure_twoway > 0) && (day_departure_twoway <= 31)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_departure_twoeway == 4) || (month_departure_twoeway == 6) || (month_departure_twoeway == 11) || (month_departure_twoeway == 9) && (day_departure_twoway > 0) && (day_departure_twoway <= 30)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_departure_twoeway == 2) && (day_departure_twoway > 0) && (day_departure_twoway <= 29)) {
				cout << "valid date.\n";
				break;
			}
			cout << "\tplease enter valid date.\n";
		}
		long long day_return_twoway, month_return_twoway;
		cout << "\t enter Return Date " << endl;
		while (true) {
			cout << "\t\tDay" << ':';
			cin >> day_return_twoway;
			cout << "\t\tMonth" << ':';
			cin >> month_return_twoway;
			if (day_departure_twoway == day_return_twoway) {
				if (month_departure_twoeway < month_return_twoway) {
					cout << "valid date.\n";
					break;
				}
			}
			else if ((day_departure_twoway < day_return_twoway) && (month_departure_twoeway < month_return_twoway)) {
				cout << "valid date.\n";
				break;
			}
			if ((day_departure_twoway == day_return_twoway) && (month_return_twoway < month_departure_twoeway)) {
				cout << "\tplease enter valid date.\n";
				continue;
			}
			else if (month_departure_twoeway == month_return_twoway) {
				if (day_departure_twoway < day_return_twoway) {
					cout << "valid date.\n";
					break;
				}
			}
			if ((day_departure_twoway > day_return_twoway) && (month_departure_twoeway > month_return_twoway)) {
				//continue;
			}
			else if (month_return_twoway > month_departure_twoeway) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_return_twoway == 1) || (month_return_twoway == 3) || (month_return_twoway == 5) || (month_return_twoway == 7) || (month_return_twoway == 8) || (month_return_twoway == 10) || (month_return_twoway == 12) && (day_return_twoway > 0) && (day_return_twoway <= 31)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_return_twoway == 4) || (month_return_twoway == 6) || (month_return_twoway == 11) || (month_return_twoway == 9) && (day_return_twoway > 0) && (day_return_twoway <= 30)) {
				cout << "valid date.\n";
				break;
			}
			else if ((month_return_twoway == 2) && (day_return_twoway > 0) && (day_return_twoway <= 29)) {
				cout << "valid date.\n";
				break;
			}
			cout << "\tplease enter valid date.\n";
		}

		system("cls");
		cout << "\t\t****************************************\t\t" << endl;
		cout << "\t\t\tAirLine Reservation System\t " << endl;
		cout << "\t\t****************************************\t\t";
		cout << "\t" << endl;

		bool flag = false;
		string filename, line;
		ifstream infile;
		infile.open("zzz.txt");
		for (int i = 0; i < 138; i++) {
			getline(infile, line);
			if (destination == 1 && i < 17) {         //abu dhapi
				cout << line << endl;

				continue;

			}
			else if (destination == 2 && i > 18 && i < 38) {
				cout << line << endl;                               //newyork
				continue;
			}
			else if (destination == 3 && i > 40 && i < 53) {
				cout << line << endl;                        //istanbul
				continue;
			}
			else if (destination == 4 && i > 53 && i < 73) {
				cout << line << endl;                       //dubai                      
				continue;
			}
			else if (destination == 5 && i > 73 && i < 89) {
				cout << line << endl;                      //sharm
				continue;
			}
			else if (destination == 6 && i > 88 && i < 107) {
				cout << line << endl;                      //aswan
				continue;
			}
			else if (destination == 7 && i > 106 && i < 125) {
				cout << line << endl;                      //axour
				continue;
			}
			else if (destination == 8 && i > 125 && i < 138) {
				cout << line << endl;                              //hurghadaa
				continue;
			}
		}
		if (destination == 1 || destination == 2 || destination == 3 || destination == 4 || destination == 5 || destination == 6 || destination == 7 || destination == 8) {
			flag = true;
		}
		if (flag) {
			cout << " " << endl;
		}

		else cout << "in valid" << endl;


		while (true) {

			cout << "Select Flight Number Please :" << endl;
			cin >> Number_of_Airplane;
			if (destination == 1 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 2 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 3 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3)) {
				break;
			}
			else if (destination == 4 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 5 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4)) {
				break;
			}
			else if (destination == 6 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 7 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3 || Number_of_Airplane == 4 || Number_of_Airplane == 5)) {
				break;
			}
			else if (destination == 8 && (Number_of_Airplane == 1 || Number_of_Airplane == 2 || Number_of_Airplane == 3)) {
				break;
			}
			cout << "\tEnter valid choose(1 to 5).\n";
		}
		infile.close();


		infile.open("zzz.txt");
		ofstream outfile;
		outfile.open("flight information.txt");
		for (int i = 1; i <= 138; i++) {
			getline(infile, line);
			if (destination == 1) {
				if (Number_of_Airplane == 1 && i > 3 && i < 6) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 5 && i < 8) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 8 && i < 11) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 11 && i < 14) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 14 && i < 17) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}

			}

			if (destination == 2) {
				if (Number_of_Airplane == 1 && i > 21 && i < 24) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 24 && i < 27) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 27 && i < 30) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 30 && i < 33) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 33 && i < 36) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}
			}

			if (destination == 3) {
				if (Number_of_Airplane == 1 && i > 43 && i < 46) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 46 && i < 49) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 49 && i < 52) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else {
					cout << " ";
				}
			}

			if (destination == 4) {
				if (Number_of_Airplane == 1 && i > 56 && i < 59) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 59 && i < 62) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 62 && i < 65) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 65 && i < 68) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 68 && i < 71) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}

			}

			if (destination == 5) {
				if (Number_of_Airplane == 1 && i > 76 && i < 79) {
					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 79 && i < 82) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 82 && i < 85) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 85 && i < 88) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else {
					cout << " ";
				}

			}
			if (destination == 6) {
				if (Number_of_Airplane == 1 && i > 91 && i < 94) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 94 && i < 97) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 97 && i < 100) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 100 && i < 103) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 103 && i < 106) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else {
					cout << " ";
				}

			}
			if (destination == 7) {
				if (Number_of_Airplane == 1 && i > 109 && i < 112) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 112 && i < 115) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 115 && i < 118) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 4 && i > 118 && i < 121) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 5 && i > 121 && i < 124) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

			}
			if (destination == 8) {
				if (Number_of_Airplane == 1 && i > 128 && i < 131) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}
				else if (Number_of_Airplane == 2 && i > 131 && i < 134) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else if (Number_of_Airplane == 3 && i > 134 && i < 137) {

					cout << line << endl;
					outfile << line << endl;
					continue;
				}

				else {
					cout << " ";
				}

			}

		}
		outfile.close();
		infile.close();
		system("pause");




	}

	else {
		cout << " ";
	}
}


struct info
{
	char name[50];
	char address[100];
	int day, month, year;
	string Phonenumber;
	char CountryOfResidence[20];
	string IDnumber;
	string Gender;
}y;



void personal_information()
{




	system("cls");
	cout << "\t\t*************************************\t\t" << endl;
	cout << "\t\t\tAirLine Reservation System\t " << endl;
	cout << "\t\t*************************************\t\t";
	cout << endl;

	ofstream out_file;
	out_file.open("Passenger Informations.txt");
	int number_of_tickets;
	cout << "\n\tPlease Enter The Number Of Tickets : " << " ";
	while (true) {
		cin >> number_of_tickets;
		if (number_of_tickets >= 1 && number_of_tickets <= 10) {
			cout << "\tThere Is Enough Tickets" << endl;
			break;
		}
		else
			cout << "\tPlease Enter Less Number Of Tickets : ";


	}
	for (int i = 1; i <= number_of_tickets; i++)
	{
		cout << "\n\nPersonal Information:\n";
		cout << "********************************\n\n";
		cout << "\tEnter Your Name : ";
		cin.ignore();
		cin.get(y.name, 50);
		cout << "\tEnter Your Address: ";
		cin.ignore();
		cin.get(y.address, 100);
		cout << "\tEnter Your Phone Number: ";
		cin >> y.Phonenumber;
		cout << "\tEnter The Date Of Birth:\n ";
		while (true) {
			cout << "\t\tDay :";
			cin >> y.day;
			cout << "\t\tMonth :";
			cin >> y.month;
			cout << "\t\tYear :";
			cin >> y.year;
			if (((y.month == 1) || (y.month == 3) || (y.month == 5) || (y.month == 7) || (y.month == 8) || (y.month == 10) || (y.month == 12)) && (y.day > 0) && (y.day <= 31) && (y.year >= 1800) && (y.year <= 2015)) {
				cout << "\tvalid date" << endl;
				break;
			}
			else if (((y.month == 4) || (y.month == 6) || (y.month == 11) || (y.month == 9)) && (y.day > 0) && (y.day <= 30) && (y.year >= 1800) && (y.year <= 2015)) {
				cout << "\tvalid date" << endl;
				break;
			}
			else if ((y.month == 2) && (y.day > 0) && (y.day < 29) && (y.year >= 1800) && (y.year <= 2015)) {
				cout << "\tvalid date" << endl;
				break;
			}
			else {
				cout << "\tPlease Enter Valid Date.\n";
			}


		}


		cout << "\tEnter Your ID Number: ";
		cin >> y.IDnumber;
		cout << "\tEnter Your Country Of Residence: ";
		cin.ignore();
		cin.get(y.CountryOfResidence, 20);
		cout << "\tGender :";
		cin >> y.Gender;
		out_file << "Name: " << y.name << endl << "Adress: " << y.address << endl << "Phone number: " << y.Phonenumber << endl << "Date of birth: " <<
			y.day << y.month << y.year << endl << "ID number: " << y.IDnumber << endl << "Country of residence: " << y.CountryOfResidence << endl;
		out_file.close();
		system("cls");
	}


}


void show_ticket()
{




	cout << "\tTicket\n";

	cout << "\t**************\n\n\n";

	srand(time(NULL));
	int PNR[4];
	cout << "\tPNR:";

	for (int x = 0; x != 4; x++) {
		PNR[x] = 1 + (rand() % 4);

		printf("%d", PNR[x]);

	}
	cout << "\n\n";




	cout << "Personal information\n";

	cout << "***********************\n\n";

	ofstream ot_file;
	ot_file.open("Passenger Informations.txt");

	cout << "\t" << "Name:" << y.name << endl;
	cout << "\t" << "Address:" << y.address << endl;
	cout << "\t" << "Phonenumber:" << y.Phonenumber << endl;
	cout << "\t" << "Enter The Date Of Birth :" << y.day << "/";
	cout << y.month << "/";
	cout << y.year << endl;
	cout << "\t" << "ID Number:" << y.IDnumber << endl;
	cout << "\t" << "Gender:" << y.Gender << endl;
	cout << "\t" << "CountryofResidence:" << y.CountryOfResidence << endl;


	ot_file.close();


	cout << "\n";
	cout << "Flight information\n";

	cout << "**********************\n\n";

	ifstream outfile;
	outfile.open("flight information.txt");

	string line;
	for (int i = 1; i <= 138; i++) {
		getline(outfile, line);

		cout << line;


	}
	outfile.close();




}





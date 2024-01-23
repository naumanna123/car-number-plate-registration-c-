#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>  /* for time() */

using namespace std;

class Registration {

	private:
		int arithemtic;
		int number;
		int reserve;
		int random_integer;
		string entry;
		string brand[50];
		int index;
		int choice;
		int count;

	public:
		char ch;
		Registration();
		void Car();
		int randomNumber();
		void Register();
		void Brand();
		void View();
		void ViewGolden();
		void Manual();
		void Menu();

};
Registration::Registration(){
	count = 1;
	index = 0;
	number = 0;
	reserve = -1;
	arithemtic = 0;
	random_integer = 0;
	entry = "NA";

}

void Registration::Menu(){
    cout << "Registeration System     \n";
	cout << "\n";
	cout<< "\n1. Car Brand"
		<< "\n2. Register"
		<< "\n3. View"
		<< "\n4. Golden PlateNumber"
		<< "\n5. View Golden"
		<< "\n6. Exit"
		<< "\n>>>:   ";
	cin >> choice;
	switch (choice){
		case 1:{
			Car();
			break;
		}

		case 2:
			Register();
			break;

		case 3:
			View();
			break;

		case 4:
			cin.ignore();
			Manual();
			break;

		case 5:
			ViewGolden();
			break;

		case 6:
		default:
			ch = 'n';
			break;
	}
}

void Registration::Manual(){
	if ( entry == "NA" and reserve == -1){
		cout << "You have to register first!\n";
		return;
	}
	else{
		fstream file;
		string tp1;
		int tp2;
		cout << "Enter First Part( ABC - ): ";
		cin >> tp1;
		cout << "Enter Second Part( - 123): ";
		cin >> tp2;
		file.open("Golden.txt", ios::app);
		file << count << ". " << tp1 << " - " << tp2 << "\n";
		reserve = 0;
		count++;
		cout << "Entered!\n";
		file.close();
	}
}

void Registration::ViewGolden(){
	if ( entry == "NA" and reserve == -1){
		cout << "You have to register first!\n";
		return;
	}
	else{
		fstream file;
		cout << "Registered Plate Numbers:\n";
		file.open("Golden.txt", ios::in);
		if (file.is_open()){
			string tp;
			while(getline(file, tp)){
				cout << tp << "\n";
			}
			file.close();
		}
		file.close();
	}
}

void Registration::View(){


	if ( entry == "NA"){
		cout << "You have to register first!\n";
		return;
	}
	else{
		fstream file;
		cout << "Registered Plate Numbers:\n";
		file.open(entry, ios::in);
		if (file.is_open()){
			string tp;
			while(getline(file, tp)){
				cout << tp << "\n";
			}
			file.close();
		}
		file.close();
	}
}

void Registration::Car(){

	string car[6] = {"Honda", "Toyota", "Suzuki", "Audi", "Mercedes", "BMW"};
	index = 0;
	for(int i = 0; i < 6; i++){
		brand[i] = car[i];
		index++;
	}
	cout << "Available Brands: \n";
			for(int i = 0; i < index; i++)
				cout << i+1 << ". " << brand[i] << endl;
	cout << endl;
}

void Registration::Register(){

	srand(time(NULL));
	arithemtic = rand() % 10;  /* generate a number from 0 - 9 */
	if (arithemtic == 0)
		arithemtic += 1;

	cout << "Enter how many plate numbers are needed" << endl;
	cin >> entry;
	istringstream buffer(entry);

	buffer >>  number;
	entry = "Registration" + entry + ".txt";
	 cout << entry<< endl;
	cout << "Arithemtic: " << arithemtic << endl;

	ofstream myfile;
	myfile.open ( entry.c_str() );
	random_integer = randomNumber();

	for (int j=1; j <= number; j++) {
		reserve = number;
		cout <<j<< ". ";
		myfile<<j<< ". ";

		for (int i = 0; i<3; i++){
			int random_integer = rand();
			// For the letters
			random_integer %= 26;
			// ASCII A starts at 65
			random_integer += 65;
			// cout << random_integer << " is equal to " <<char(random_integer)<< endl;
			cout <<char(random_integer);
			myfile<<char(random_integer);
			}

		myfile<<" - ";
		cout << " - ";


		random_integer = random_integer + arithemtic;

		cout <<random_integer;
		myfile<<random_integer;


		cout << endl;
		myfile<<"\n";
	}
	myfile.close();
}

int Registration::randomNumber(){

	int temp = 0, num = 0;
	for (int i = 0; i<3; i++){
		int temp = rand();
		// For the digitd
		temp %= 10;
		// cout << random_integer << "uu";
		num = num * 10 + temp;
		// ASCII 0 starts at 48
		temp += 48;
	}
	return num;
}


int main()
{
  // Create an instance of the Registration class
  Registration plateNumber;

  // Set the value of the ch member variable to 'y'
  plateNumber.ch = 'y';

  // Run the do-while loop until the value of ch is not 'y' or 'Y'
  do {
    // Call the Menu() function to display the menu
    plateNumber.Menu();

    // If the value of ch is 'y', ask the user if they want to see the menu again
    if (plateNumber.ch == 'y') {
      cout << "Do you wanna see the menu again: (y/n)";
      cin >> plateNumber.ch;
    }
  } while (plateNumber.ch == 'y' or plateNumber.ch == 'Y');

  // Open the "Golden.txt" file in write mode
  ofstream file("Golden.txt");

  // Return 0 to indicate that the program has terminated successfully
  return 0;
}

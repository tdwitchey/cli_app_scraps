#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string character(int x);
string toString(int x);
string generatePassword(int x);
string generateUser();
int randNum();
int type();
int passLength();
void userList(int x);

//Application that uses one-dimensional, two-dimensional, and three-dimensional arrays to generate random usernames,
//passwords, and a list of both depending on user input
int main()
{
	srand(time(NULL));
	bool loop = true;
	char menu;
	int list;

	while(loop == true){
		cout << "[ MENU ] | (U) Generate Username |(P) Generate Password | (L) Generate List | (Q) Quit" << endl;
		cin >> menu;
		switch(menu){
			case 'P':
			case 'p':
				cout << generatePassword(passLength()) << endl;
				cout << endl;
				break;
			case 'U':
			case 'u':
				cout << generateUser() << endl;
				cout << endl;
				break;
			case 'L':
			case 'l':
				cout << "How many users?: " << endl;
				cin >> list;
				cout << endl;
				userList(list);
				break;
			case 'Q':
			case 'q':
				loop = false;
				break;
			default:
				break;
		}
	}

	return 0;
}

//Simple function that returns a random number between 0 and 9
int randNum()
{
	int random = rand() % 10;
	return random;
}

//Simple function that returns either 1 or 2
int type()
{
	int random = rand() % 2 + 1;
	return random;
}

//Function that takes an integer input (from the 'type' function) and uses that input to determine
//if the character returned will be lowercase or uppercase
string character(int x)
{
	string charReturn;
	int random = rand() % 26;
	string charactersLower[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	string charactersUpper[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	
	if(x == 1)
	{
		charReturn = charactersLower[random];
	}
	else if (x == 2)
	{
		charReturn = charactersUpper[random];
	}
	else
	{
		charReturn = "x";
	}

	return charReturn;
}

//Simple function that returns a number between 10 and 20
int passLength()
{
	int length = rand() % (21 - 10) + 10;
	return length;
}

//Could not figure out how to convert an int to a string without getting errors
//so I made my own solution since a one digit number can only be 0-9
string toString(int x)
{
	string number;
	switch(x)
	{
		case 0: 
			number = "0";
			break;
		case 1: 
			number = "1";
			break;
		case 2: 
			number = "2";
			break;
		case 3: 
			number = "3";
			break;
		case 4:
			number = "4";
			break;
		case 5: 
			number = "5";
			break;
		case 6: 
			number = "6";
			break;
		case 7: 
			number = "7";
			break;
		case 8: 
			number = "8";
			break;
		case 9: 
			number = "9";
			break;
		default: 
			number = "x";
			break;
	}
	return number;
}

//Function that takes an integer input from the 'passLength' function and uses it to determine
//the size of an array, which will then go through a for loop which takes input from the 'type' function
//and uses it to determine if the next value of the array will be a number or letter and saves each
//value into the variable 'value' to form a string of numbers and letters and returns it
string generatePassword(int x)
{
	string structure[x];
	string value = "";
	for(int i = 0; i < x; i++)
	{
		int placeholder = type();
				switch (placeholder){
					case 1:
						structure[i] = toString(randNum());
						break;
					case 2:
						structure[i] = character(type());
						break;
					default: break;
				}
			value += structure[i];
	}
	return value;
}

//Function that generates a username by using the 'type' function to pull random values from the 
//'structure array', randomly add underscores between the values, and adds 1 or 2 numbers to the
//end of the string which it saves into, and returns, the 'user variable' 
string generateUser()
{
	int space;
	string user;
	string structure[3][2][2] =
	{
		{
			{"The", "My"},
			{"Our", "Your"}
		},
		{
			{"Blue", "Red"},
			{"Green", "Yellow"}
		},
		{
			{"Dog", "Cat"},
			{"Fish", "Bird"}
		}
	};

	for(int i = 0; i < 3; i++)
	{
		user += structure[i][type()-1][type()-1];
		space = type();
		switch(space){
			case 1:
				user += "_";
				break;
			case 2:
				break;
			default:
				break;
		}
	}

	for(int k = 0; k < type(); k++)
	{
		user += toString(randNum());
	}
	return user;
}

//Function that takes input from the user to determine the number of users for which to create a username and
//password. Uses input from the 'generateUser', 'generatePassword', and 'passLength' functions
void userList(int x)
{
	string name[x];
	string pass[x];
	string structure[x][2];

	for(int i = 0; i < x; i++)
	{
		structure[i][0] = generateUser();
		name[i] = structure[i][0];

		structure[i][1] = generatePassword(passLength());
		pass[i] = structure[i][1];

		cout << "Username[" << i+1 << "]: "<< name[i] << "\nPassword[" << i+1 << "]: " << pass[i] << "\n" << endl;
	}

}

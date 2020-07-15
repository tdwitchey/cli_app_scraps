#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void clearConsole();
void viewStudentList_all();
void studentClasses(int x);
void studentGrades(int x);
void viewClassList_all();
void classStudents(int x);
void classGrades(int x);
bool advLogin();
bool advDataComparison(string a, string b);
bool checkMatch(string x, string y);
int advNum();
int viewStudent();
int viewClass();
char displayMainMenu();
char displayStudentMenu();
char StudentMenu(char x);
char displayClassMenu();
char ClassMenu(char x);

int main()
{
	//A college that needs to allow their advisors to track student, class, and grade information
	bool loop = true;
	
	clearConsole();
	cout << "Welcome to the Small University Advisor Database" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Please login: \n" << endl;
	bool logInSuccess = advLogin();
		while(logInSuccess == false){
			clearConsole();
			cout << "Incorrect Username or Password. Please try again." << endl;
			cout << "For testing purposes User: admin0 Passcode: 0000 are accepted." << endl;
			cout << endl;
			logInSuccess = advLogin();
		}

	clearConsole();
	char menuChoice = displayMainMenu();
	while(loop == true){
		switch (menuChoice){
			case 's':
			case 'S':
				viewStudentList_all();
				menuChoice = StudentMenu(displayStudentMenu());
				break;
			case 'c':
			case 'C':
				viewClassList_all();
				menuChoice = ClassMenu(displayClassMenu());
				break;
			case 'q':
			case 'Q':
				loop = false;
				break;
			default:
				menuChoice = displayMainMenu();
				break;
		}
	}
	return 0;
}

void clearConsole()
{
	//This string of characters "clears" the console.
	cout << "\033[2J\033[1;1H";
}

//login function
bool advLogin()
{
	bool approval = false;

	string check_user, check_passCode;
	cout << "Advisor Checkpoint" << endl;
	cout << "-------------------------" << endl;
	cout << "Enter Username: ";
	cin >> check_user;
	cout << endl;
	cout << "Enter 4-Digit Passcode: ";
	cin >> check_passCode;
	cout << endl;
	approval = checkMatch(check_user, check_passCode);

	return approval;
}

bool checkMatch(string x, string y)
{
	string advList[5][2] = {{"admin0", "0000"}, 
						    {"admin1", "1144"},
						    {"admin2", "7382"}, 
			        	    {"admin3", "9281"},
						    {"admin4", "8590"}};
	bool isMatch;
	bool userMatch;

	for(int a = 0; a < 5; a++)
	{
		if(x == advList[a][0])
		{
			userMatch = true;
		}
		else
		{
			userMatch = false;
		}

		if(y == advList[a][1] && userMatch == true)
		{
			isMatch = true;
			a = 6;
		}
		else
		{
			isMatch = false;
		}

	}
	return isMatch;
}

char displayMainMenu()
{
	clearConsole();
	char choice;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--[ Main Menu ]--------(S)tudent List--(C)lass List--(Q)uit-------|" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--Input: ";
	cin >> choice;
	return choice;
}

void viewStudentList_all()
{
	clearConsole();
	string id, first, last;

	cout << "|---------------------------Student List---------------------------|" << endl;

	string Students_all[4][3] =
	{
		{"01", "John", "Doe"},
		{"02", "Jane", "Smith"},
		{"03", "Jack", "Baker"},
		{"04", "Mortdecai", "Amadeaus"}
	};

	for(int i = 0; i < 4; i++)
	{
		for(int k = 0; k < 3; k++)
		{
			id = Students_all[i][k];
			k++;
			first = Students_all[i][k];
			k++;
			last = Students_all[i][k];
		}
		cout << "|---Student ID: " << id << endl;
		cout << "|" << endl;
		cout << "|---First Name: " << first << endl;
		cout << "|"<< endl;
		cout << "|---Last Name: " << last << endl;
		cout << "|------------------------------------------------------------------|" << endl;
	}
}

char displayStudentMenu()
{
	char sChoice;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--[ Student Menu ]---------(C)lasses--(G)rades--(B)ack------------|" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--Input: ";
	cin >> sChoice;
	return sChoice;
}

char StudentMenu(char x)
{
	switch(x){
		case 'b':
		case 'B':
			return displayMainMenu();
			break;
		case 'c':
		case 'C':
			studentClasses(viewStudent());
			x = StudentMenu(displayStudentMenu());
			break;
		case 'g':
		case 'G':
			studentGrades(viewStudent());
			x = StudentMenu(displayStudentMenu());
			break;
		default:
			return displayMainMenu();
			break;
	}
	
}

int viewStudent()
{
	string id_input;
	clearConsole();
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--Please enter the Student's ID-----------------------------------|" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--Input: ";
	cin >> id_input;
	cout << endl;

	int input;
	istringstream iss (id_input);
	iss >> input;

	switch(input){
		case 01:
			return 1;
			break;
		case 02:
			return 2;
			break;
		case 03:
			return 3;
			break;
		case 04:
			return 4;
			break;
		default:
			return 0;
			break;
	}

}

void studentClasses(int x)
{
	string sClass[4][6] =
	{
		{"01", "John", "Doe", "Chemistry 111", "Math 115", "Accounting 101"},
		{"02", "Jane", "Smith", "Biology 101", "Speech 101", "Economics 202"},
		{"03", "Jack", "Baker", "English 211", "Math 115", "Finance 101"},
		{"04", "Mortdecai", "Amadeaus", "Physics 201", "Theatre 131", "Robotics 101"}
	};

	if(x == 0)
	{
		clearConsole();
		cout << "|---Student not found." << endl;
	}
	else
	{
		clearConsole();
		cout << "|------------------------------------------------------------------|" << endl;
		cout << "|---Student " << sClass[x-1][0] << endl;
		cout << "|---" << sClass[x-1][1] << " " << sClass[x-1][2] << ": "<< endl;
		cout << "|------------------------------------------------------------------|" << endl;
		for(int i = 0; i < 3; i++)
		{
			cout << "|---" << sClass[x-1][i+3]<< endl;
			cout << "|" << endl;
		}
	}
}

void studentGrades(int x)
{
	string sGrade[4][3][3] =
	{
		{
			{"01", "John", "Doe"},
			{"Chemistry 111", "Math 115", "Accounting 101"},
			{"98.4%", "99.55%", "83.41%"}
		},
		{
			{"02", "Jane", "Smith"},
			{"Chemistry 111", "Speech 101", "Math 115"},
			{"87.28%", "91.33%", "89.82%"}
		},
		{
			{"03", "Jack", "Baker"},
			{"English 211", "Math 115", "Accounting 101"},
			{"81.32%", "96.46%", "97.28%"}
		},
		{
			{"04", "Mortdecai", "Amadeaus"},
			{"English 211", "Math 115", "Speech 101"},
			{"99.51%", "83.77%", "90.39%"}
		}
	};

	if(x == 0)
	{
		clearConsole();
		cout << "|---Student not found." << endl;
	}
	else
	{
		clearConsole();
		cout << "|------------------------------------------------------------------|" << endl;
		cout << "|---Student " << sGrade[x-1][0][0] << endl;
		cout << "|---" << sGrade[x-1][0][1] << " " << sGrade[x-1][0][2] << ": "<< endl;
		cout << "|------------------------------------------------------------------|" << endl;

		string structure[2][3];
		string grade[3];

		for(int i = 0; i < 2; i++)
		{
			for(int k = 0; k < 3; k++)
			{
				structure[i][k] = sGrade[x-1][i+1][k];
				if(i == 1){
					grade[k] += ": ";
					grade[k] += structure[i][k];
					cout << "|---" << grade[k] << endl;
					cout << "|" << endl;
				}
				else{
					grade[k] = structure[i][k];
				}
			}
		}
	}
}

void viewClassList_all()
{
	clearConsole();

	cout << "|----------------------------Class List----------------------------|" << endl;

	string classes_all[5] = {"Chemistry 111", "Math 115", "Accounting 101", "Speech 101", "English 211"};

	for(int i = 0; i < 5; i++)
	{
		cout << "|---[" << i+1 << "] " << classes_all[i] << endl;
		cout << "|" << endl;
		cout << "|------------------------------------------------------------------|" << endl;
	}
}

char displayClassMenu()
{
	char sChoice;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--[ Class Menu ]----------(S)tudents--(G)rades--(B)ack------------|" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--Input: ";
	cin >> sChoice;
	return sChoice;
}

char ClassMenu(char x)
{
	switch(x){
		case 'b':
		case 'B':
			return displayMainMenu();
			break;
		case 's':
		case 'S':
			classStudents(viewClass());
			x = ClassMenu(displayClassMenu());
			break;
		case 'g':
		case 'G':
			classGrades(viewClass());
			x = ClassMenu(displayClassMenu());
			break;
		default:
			return displayMainMenu();
			break;
	}
	
}

int viewClass()
{
	int c_input;
	clearConsole();
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--Please enter the Class [#]--------------------------------------|" << endl;
	cout << "|------------------------------------------------------------------|" << endl;
	cout << "|--Input: ";
	cin >> c_input;
	cout << endl;

	switch(c_input){
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		default:
			return 0;
			break;
	}

}

void classStudents(int x)
{
	string cStudents[5][2][4] =
	{
		{
			{"Chemistry 111"},
			{"John Doe", "Jane Smith"}
		},
		{
			{"Math 115"},
			{"John Doe", "Jane Smith", "Jack Baker", "Mortdecai Amadeaus"}
		},
		{
			{"Accounting 101"},
			{"John Doe", "Jack Baker"}
		},
		{
			{"Speech 101"},
			{"Jane Smith", "Mortdecai Amadeaus"}
		},
		{
			{"English 211"},
			{"Jack Baker", "Mortdecai Amadeaus"}
		}
	};

	if(x == 0)
	{
		clearConsole();
		cout << "|---Class not on record." << endl;
	}
	else
	{
		clearConsole();
		cout << "|------------------------------------------------------------------|" << endl;
		cout << "|---" << cStudents[x-1][0][0] << endl;
		cout << "|------------------------------------------------------------------|" << endl;
		for(int i = 0; i < 4; i++)
		{
			if(cStudents[x-1][1][i] != ""){
				cout << "|---" << cStudents[x-1][1][i] << endl;
				cout << "|" << endl;
			}
			
		}
	}
}

void classGrades(int x)
{
	string cGrade[5][3][4] =
	{
		{
			{"Chemistry 111"},
			{"John Doe", "Jane Smith"},
			{"98.4", "87.28"}
		},
		{
			{"Math 115"},
			{"John Doe", "Jane Smith", "Jack Baker", "Mortdecai Amadeaus"},
			{"99.55", "89.82", "96.46", "83.77"}
		},
		{
			{"Accounting 101"},
			{"John Doe", "Jack Baker"},
			{"83.41", "97.28"}
		},
		{
			{"Speech 101"},
			{"Jane Smith", "Mortdecai Amadeaus"},
			{"91.33", "90.39"}
		},
		{
			{"English 211"},
			{"Jack Baker", "Mortdecai Amadeaus"},
			{"81.32", "99.51"}
		}
	};

	if(x == 0)
	{
		clearConsole();
		cout << "|---Class not on record." << endl;
	}
	else
	{
		clearConsole();
		cout << "|------------------------------------------------------------------|" << endl;
		cout << "|---" << cGrade[x-1][0][0] << endl;
		cout << "|------------------------------------------------------------------|" << endl;

		string structure[2][4];
		string grade[4];
		string avgString;
		double avgCount = 0.0;
		double input = 0.0, avgHold = 0.0, avg = 0.0;
		stringstream ss;
		

		for(int i = 0; i < 2; i++)
		{
			for(int k = 0; k < 4; k++)
			{
				if(cGrade[x-1][i+1][k] != "")
				{
					structure[i][k] = cGrade[x-1][i+1][k];
					if(i == 1){
						grade[k] += ": ";
						grade[k] += structure[i][k];
						cout << "|---" << grade[k] << "%" << endl;
						cout << "|" << endl;
						avgString = structure[i][k];
						ss << avgString;
						ss >> avgHold;
						avg += avgHold;
						avgCount++;
						ss.clear();
					}
					else{
						grade[k] = structure[i][k];
					}
				}
				
			}
		}
		cout << "|------------------------------------------------------------------|" << endl;
		cout << "|---" << cGrade[x-1][0][0] << " Average Grade: " << (avg / avgCount) << "%" << endl;
		cout << "|------------------------------------------------------------------|" << endl;
	}
}

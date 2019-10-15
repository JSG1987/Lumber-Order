
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
ifstream infile;
ofstream outfile;
string readCustomer();
string convertWood(char woodType);
void readBoardData(char& woodType, int& pieces, int& width, int& height, int& length);
double calculateBoardFeet(double pieces, double width, double height, double length);
double calculateCost(double boardFeet, char woodType); 
void processCustomer(string customer);
int main()
{
	outfile.open("Order.dat");
	infile.open("LumberOrder.txt");
	if (!infile)
	{
		cout << "File did not open" << endl;
	}
	string cust = readCustomer();
	while (cust.length())
	{
		processCustomer(cust);
		cust = readCustomer();
	}

	outfile.close();
	infile.close();
	system("Pause");
	return 0;
	
}

string readCustomer()
{
	string customer;
	string customerNumber;
	string PC;
	infile >> customer >> PC >> customerNumber;
	outfile << " " << customer << PC << "\t" << customerNumber << endl;
	return customerNumber;
}

void readBoardData(char& woodType, int& pieces, int& width, int& height, int& length)
{
	infile >> woodType;
	if (woodType != 'T')
		infile >> pieces >> width >> height >> length;
}

double calculateBoardFeet(double pieces, double width, double height, double length)
{
	return (pieces * width * height * length * 12 / 144);
}

double calculateCost(double boardFeet, char woodType)
{
	cout << setprecision(2) << fixed;
	if (woodType == 'P')
	{
		return boardFeet * .89;
	}
	else if (woodType == 'F')
	{
		return boardFeet * 1.09;
	}
	else if (woodType == 'C')
	{
		return boardFeet * 2.26;
	}
	else if (woodType == 'M')
	{
		return boardFeet * 4.50;
	}
	else if (woodType == 'O')
	{
		return boardFeet * 3.10;
	}
}

void processCustomer(string customer)
{
	cout << "Customer #: " << customer << endl;
	cout << "Pieces \tSize \tWood \tCost" << endl;
	outfile << "Pieces \tSize \tWood \tCost" << endl;
	char woodType;
	int pieces, width, height, length;
	double sum = 0;
	double boardFeet;
	readBoardData(woodType, pieces, width, height, length);
	boardFeet = calculateBoardFeet(pieces, width, height, length);
	while (woodType != 'T')
	{
	
		string wood = convertWood(woodType);
		sum += calculateCost(boardFeet, woodType);
		cout << pieces << "\t" << width << "x" << height << "x" << length << "\t" << wood
			<< "\t$" << calculateCost(boardFeet, woodType) << endl;
		outfile << pieces << "\t" << width << "x" << height << "x" << length << "\t" << wood
			<< "\t$" << calculateCost(boardFeet, woodType) << endl;
		readBoardData(woodType, pieces, width, height, length);
	}
	cout << "\t\tTotal: $" << sum << endl;
	outfile << "\t\tTotal: $" << sum << endl;
}

string convertWood(char woodType)
{
	switch (woodType)
	{
	case 'P':
		return "Pine";
	case 'F':
		return "Fir";
	case 'C':
		return "Cedar";
	case 'M':
		return "Maple";
	case 'O':
		return "Oak";
	default:
		return "un-type";
	}
}



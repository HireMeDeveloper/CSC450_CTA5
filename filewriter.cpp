#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>

using namespace std;

void reverseFile(string fileName){
	// Store file data to string
	ifstream inputFile(fileName);
	string fileData;

	if (inputFile.is_open()){
		while (inputFile){
			string line;
			getline(inputFile, line);
			fileData.append(line);
			fileData.append("\n");
		}
	} else {
		cout << "Access to input file failed." << endl;
	}

	inputFile >> fileData;

	// Reverse the data and output to file
	ofstream outputFile("CSC450_CT5_reverse.txt");

	if (outputFile.is_open()){

		 for(int i = fileData.length() - 1; i >= 0; i--)
		 {
		      	outputFile << fileData[i];
		 }

		cout << "Reverse file has been updated." << endl;
	} else {
		cout << "Access to output file failed." << endl;
	}

	inputFile.close();
	outputFile.close();
}

int main(){
	string fileName = "CSC450_CT5_mod5.txt";

	ofstream file(fileName, ios::app);

	if (file.is_open()) {
		cout << "File Accessed!" << endl;;
		cout << "Please provide input to be appended to file:" << endl;

		string input;
		getline(cin, input);

		file << input << "\n";

		file.close();

		cout << "Input has been appended to file." << endl;
	} else {
		cout << "Access Denied!";
	}

	cout << "Reversing file contents." << endl;
	reverseFile(fileName);

	return 0;
}

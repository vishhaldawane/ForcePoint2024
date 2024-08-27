//============================================================================
// Name        : FileHandlingProject.cpp
// Author      : Vishhal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;
/*
 * 						volatile
 * 	reading/input	in the memory		writing / output
 * 	|					|				 |
 * 	keyboard	-->	int num=190;  --> monitor
 * 	|									|
 * 	cin>>num						  cout<<num
 * 	std									std
 *
 *
 * 			File				File
 * 			|					|
 * 			inputstream			outputstream
 * 			|					|
 * 			reading				writing
 * 				|				|
 * 				+--<--abc.txt-<-+
 * 					non-volatile
 *
 * 		keyboard								    monitor
 * 		|												|
 * 		data ---writingstream-->file-->readingstream--data
 *
 *
 *
 * 		ifstream -> read the data from a file
 * 		ofstream -> write the data to a file
 * 		fstream -> read/write data from/to a file
 *
 * 					ios
 * 					 |
 * 				-------------
 * 				|			|
 * 		  istream		     ostream
 * 		  |	|	|			|   |  |
 * 		cin |   |           |   |  cout
 * 	    	|	-------------   |
 * 		ifstream	   |		ofstream
 * 					ostream
 * 					   |
 * 					fstream
 *
 */


void writeToAFile()
{
	ofstream fout;
	cout<<"\nOpening the file...";
	fout.open("/Users/apple/bank.txt",ios::app);
	cout<<"\nFile is ready...";

	string line; // a blank line

	while(fout) {
		getline(cin,line); //read from the keyboard

		if(line=="-1")
			break;

		fout<<line<<endl; //store this line into the file referred by fout
	}
	cout<<"\nclosing the file...";
	fout.close();
	cout<<"\nFile is closed..";

}

int main() {
	cout << "!!! File Handling !!!"<< endl; // prints !!!Hello World!!!
	writeToAFile();
	return 0;
}

/*
*File           : mini4.ccp
*Project        : mini assignment 4
*Programmer     : Colby Taylor
*First version  : 2021-03-23
*Description    : Take words and put them into a vector, then search the container 
*				: for the entered words
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;
#pragma warning(disable:4996)
#define kLoopForever 1

int main(void)
{
	vector<string> v;

	string newWord;
	string searchWord;
	string token;
	string space(" ");
	string exitCriteria(".");
	
	size_t spaceFinder = 0;
	size_t lastSpaceFinder = 0;
	size_t length = 0;

	int exit = 0;
	int found = 0;

	cout << "Enter words ('.') to stop" << endl;
	while (kLoopForever)
	{
		getline(cin, newWord, '\n'); //get line of words or one word 
		exit = exitCriteria.compare(newWord);
		if (exit == 0)
		{
			break;
		}

		spaceFinder = newWord.find(space); //find word separation by space
		length = newWord.length();//whats the length of the string

		if (spaceFinder > length) //if the first space is less than total length
		{
			v.push_back(newWord);
			continue;
		}

		while (spaceFinder < length) //mutliple word string
		{
			token = newWord.substr(0, spaceFinder);
			newWord.erase(0, spaceFinder+1);
			v.push_back(token);

			exit = exitCriteria.compare(newWord);
			if (exit == 0)
			{
				break;
			}
			spaceFinder = newWord.find(space); 
			length = newWord.length();

			if (spaceFinder > length) //getting the last word in the string of words
			{
				v.push_back(newWord);
			}
		}

		if (exit == 0)//the limitations of break statements 
		{
			break;
		}
	}

	while (kLoopForever)
	{
		cout << "Please enter a word to search for: ";
		getline(cin, searchWord, '\n');
		exit = exitCriteria.compare(searchWord);
		if (exit == 0)
		{
			break;
		}
		for (vector<string>::iterator i=v.begin(); i != v.end(); ++i)
		{
			found = searchWord.compare(*i);
			if (found == 0)
			{
				cout << "Success!" << endl;
				break;
			}
			if (i == ((v.end())-1))
			{
				cout << "Not there!" << endl;
			}
		}
	}
	return 0;
}

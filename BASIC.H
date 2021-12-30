/*								Basic.h
		This file contain basic things for the library program
	it define two structure Book and Borrow and define constants and 
	global variables

		further more it contain functions for handling input errors 
	and make this program more robust.
*/
#ifndef basic
#define basic

#include <iostream>		//Kyeboard monitor i/o handling
#include <fstream>		//File i/o
#include <iomanip>		//Formating output
#include <string>		//std string 
#include <time.h>		//to handl date 
#include <ctype.h>		//formating of charsctors

using namespace std;

const int SIZE=300;		//all C_string hase this size 
int NO_BOOKS=0;			//number of books
int NO_THESIS=0;		//number of thesis
int NO_BORROWERS=0;		//number of book's borrowers
int NO_BORROWERSTH=0;	//number of thesis borrowers
char PASSWORD[SIZE];	//System pasword

const char BOOK_HOLDER_FILE[]="BOOK.txt";
const char BORROWER_FILE[]="BORROWER.txt";
const char BORROWER_FILETH[]="BORROWERTH.txt";
const char THESIS_FILE[]="thesis.txt";
const char INFORMATION[]="information.inf";

struct Book
{
	int ACC;
	string ISBN;
	string title;
	string author;
	string subject;
	string contry;
	short edition;
	short part;
	short year;
	short price;
	short borrowable;
};
struct Borrow
{
	int ACC;
	string name;
	string ID;
	string collage;
	string degree;
	time_t date;
};
void regulate(string &word)
{
	int point;
	for (int i=0;i<word.length();i++)
		if(word[i]==' ' ||word[i]=='\t')
		{
			point=i;
			for(int j=0;(word[i]==' ' ||word[i]=='\t') 
				&& i<word.length();i++,j++);
			word.replace(point,j,"*");
			i=point; 
		}
	if (word[word.length()-1]=='*')
		word.erase(word.length()-1,1);
	if (word[0]=='*')
		word.erase(0,1);
	for(i=0;i<word.length();i++)
		word[i]=tolower(word[i]);
}

void remove_star(string &word)
{
	for (int i=0;i<word.length();i++)
		if (word[i]=='*')
			word[i]=' ';
}

bool isword(char s[])
{
	if(strlen(s)==0)
	{
		cout<<"Incorrect word(s)! Try again\n\a"; 
		return false;
	}
	for (int i=0;i<strlen(s);i++)
		if(!isalpha(s[i]) && !isspace(s[i]) && s[i]!='.' && s[i]!='_' && s[i]!='+' && s[i]!='/'&&!isdigit(s[i]))
		{
			cout<<"Incorrect word(s)! Try again\n\a";
			return false;
		}
	return true;
}

bool isnumber(char s[])
{
	if(strlen(s)==0 || strlen(s)>9)
	{
		cout<<"Incorrect number! Try again\n\a"; 
		return false;
	}
	for (int i=0;i<strlen(s);i++)
		if(!isdigit(s[i]))
		{
			cout<<"Incorrect number! Try again\n\a";
			return false;
		}
	return true;
}

string word_cin(char text[])
{
	char temp[SIZE];
	do
	{
		cout<<text;
		cin.getline(temp,SIZE);
	}while(!isword(temp));
	string str(temp);
	regulate(str);
	return str;
}

int num_cin(char text[])
{
	char temp[SIZE];
	do
	{
		cout<<text;
		cin.getline(temp,SIZE);
	}while(!isnumber(temp));
	return atoi(temp);
}
bool choice(char text[])
{
	char temp[SIZE];
	do
	{
		cout <<text;
		cin.getline(temp,SIZE);
	}while(strcmpi(temp,"y") && strcmpi(temp,"n"));
	if(!strcmpi(temp,"y"))
		return true;
	return false;
}

#endif

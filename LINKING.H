/*							Linking file
		this file contain functions which they are works between
		user interfaces and internal functions like add, remove 
		books or borrowers
*/
#ifndef Linking
#define Linking
#include "Books.h"
#include "Borrowers.h"
//This function combines add and remove books function by 
//executing one of them after catching user choice 
void add_remove_book(Book b[],const char file[],int &Loop,int interf)
//1- Book b[] it may be hold information of books or thesis
//2- file C_string holds file name with corresponding books type
//3- Loop number of books to indecate array size
//4- interf it tels the function where it is called to displys conveniant interface
{
	int choose,i=0;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(interf);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2") &&strcmp(temp,"3") 
			&&strcmp(temp,"4")&&strcmp(temp,"5"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			//This case lets the librarian to add books or thesis as its choiuce 
			//second parameter works as a flag if it is 1 then it adds borrowable books
			//and if it is 0 then the function adds nonborrowable books 
			Add_book(b,1,file,Loop);
			break;
		case 2:
			//for non borrowe able books or thesis
			Add_book(b,0,file,Loop);
			break;
		case 3:
			//this case exicuts a function that deletes books in the library
			remove_book(b,file,Loop);
			break;
		case 4:
			//Just sentenses for help
			cout<<"\n\n            Help of Add Remove books/thesis menu\n\n";
			cout<<"   1- in this choice you can add books/thesis of type\n";
			cout<<"        borrow able, you must enter new ACC for every book\n";
			cout<<"        if your book has no part then enter 0 to explain\n";
			cout<<"        there is no part of this book\n\n"; 
			cout<<"   2- in this choice you can add books or thesis of type\n";
			cout<<"        none borrow able you must enter new ACC for every\n";
			cout<<"        book if your book has no part then enter 0 to explain\n";
			cout<<"        there is no part of this book.\n\n";
			cout<<"   3- In this choice you must know book's title and ACC to remove\n";
			cout<<"         any book/thesis. After removing it you can not return its\n";
			cout<<"         information\n\n"; 
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 5:
			//return to the book control menu or thesis control menu (where it calls)
			return ;
			break;
		}//end of switch
	}//end of while
}//end of function

//this function adds or removes borrowers of that they borrowed books or thesis 
void add_remove_borrower(Book b[],Borrow br[],const char file[],int &Loopb,int &Loopbr)
//1- b[] this array contain book's or thesis data 
//2- br[] it has borrowers information of books or borrowers of thesis
//3 file contian borrrower file name
//Loopb book array size
//Loopbr borrower array size
{
	int choose,i=0;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(214);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2")
			&&strcmp(temp,"3") &&strcmp(temp,"4"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			add_borrower(b,br,file,Loopbr,Loopb);
			break;
		case 2:
			remove_borrower(br,file,Loopbr);
			break;
		case 3:
			cout<<"   1- When you choose this option  you can add borrowers\n";
			cout<<"         of every type of books thesis or normal books but\n";
			cout<<"         non borrow able books can not be added\n\n";
			cout<<"   2- When the borrower returns any book choose this option\n";
			cout<<"         and type borrowed books ACC and borrower name\n\n"; 
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 4:
			return ;
			break;
		}//end of switch
	}//end of while
}//end of function

//this function combines all tasks that can be carried out on the books
//and seslct correct task that corresponds with the user choice 
void book_control_menu(Book b[],Borrow br[])
//b[] electrical coppy of the books table in the RAM
//br[] electrical coppy of the borrowers books table in the RAM
{
	int choose,i=0;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(21);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2") &&strcmp(temp,"3") 
				&&strcmp(temp,"4") &&strcmp(temp,"5")&&strcmp(temp,"6"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			//first option is searching for books this function
			//has three parameter first is book array second is flag
			//that calls correct interface and last one is global 
			search_for_books(b,211,NO_BOOKS);
			break;
		case 2:
			//NO_BORROWERS is global 
			search_for_borrowers(b,br,NO_BOOKS,NO_BORROWERS,212);
			break;
		case 3:
			add_remove_book(b,BOOK_HOLDER_FILE,NO_BOOKS,213);
			break;
		case 4:
			add_remove_borrower(b,br,BORROWER_FILE,NO_BOOKS,NO_BORROWERS);
			break;
		case 5:
			cout<<"\n\n                      Help of the books control menu\n\n";
			cout<<"   1- Search for books: after choosing this option you can search for books\n";
			cout<<"         by its title, author, subject or keyword in the subject.\n\n"; 
			cout<<"   2- Search for borrowers: after choosing this option you can search for \n";
			cout<<"         borrowers by thier name or college. Further more it can outputs \n";
			cout<<"         every delayed borrowers and all borrowers\n\n";
			cout<<"   3- Add new books: after you choose this option please be sure of all\n";
			cout<<"         information you add, about any book because this system deals\n";
			cout<<"         with added information either it is true or false\n\n";
			cout<<"   4- Remove books: be sure before removing any thesis because you can not \n";
			cout<<"         return it after you deleting it in this case you shoud add it again\n\n";
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 6:
			return ;
			break;
		}
	}
}
void thesis_control_menu(Book b[],Borrow br[])
{
	int choose,i=0;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(22);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2") &&strcmp(temp,"3") 
				&&strcmp(temp,"4") &&strcmp(temp,"5")&&strcmp(temp,"6"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			search_for_books(b,221,NO_THESIS);
			break;
		case 2:
			search_for_borrowers(b,br,NO_THESIS,NO_BORROWERSTH,222);
			break;
		case 3:
			add_remove_book(b,THESIS_FILE,NO_THESIS,223);
			break;
		case 4:
			add_remove_borrower(b,br,BORROWER_FILETH,NO_THESIS,NO_BORROWERSTH);
			break;
		case 5:
			cout<<"\n\n                      Help of the thesis control menu\n\n";
			cout<<"   1- Search for thesis: after choosing this option you can search for \n";
			cout<<"         thesis by its title, author, subject or keyword in the subject.\n\n"; 
			cout<<"   2- Search for borrowers: after choosing this option you can search for \n";
			cout<<"         borrowers by thier name or college. Further more it can outputs \n";
			cout<<"         every delayed borrowers and all borrowers\n\n";
			cout<<"   3- Add new thesis: after you choose this option please be sure of all\n";
			cout<<"         information you add, about any thesis because this system deals\n";
			cout<<"         with added information either it is true or false\n\n";
			cout<<"   4- Remove thesis: be sure before removing any thesis because you can not \n";
			cout<<"         return it after you deleting it in this case you shoud add it again\n\n";
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 6:
			return ;
			break;
		}
	}
}

void librarian_menu(Book b[],Book th[],Borrow br[],Borrow brth[])
{
	int choose,i=0;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(2);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2") &&strcmp(temp,"3") 
				&&strcmp(temp,"4") &&strcmp(temp,"5")&&strcmp(temp,"6"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			book_control_menu(b,br);
			break;
		case 2:
			thesis_control_menu(th,brth);
			break;
		case 3:
			change_password();
			break;
		case 4:
			cout<<"\n\n                      Help of librarian menu\n\n";
			cout<<"   1- Book control menu: after choosing this option you can\n";
			cout<<"        do all operations on the normal book, the operations are \n";
			cout<<"        add, remove and searchfor the books.\n\n";
			cout<<"   2- Thesis control menu: after choosing this option you can\n";
			cout<<"        do all operations on the thesis, the operations are add,\n";
			cout<<"        remove and search.\n\n";
			cout<<"   3- Change password: by this option you can change system password.\n";
			cout<<"        We advice you to use hard password which contain spaces,\n";
			cout<<"        tabs and symbols and recorded this password in safe place,\n";
			cout<<"        to avoid forget it. If you forget your password call us,\n";
			cout<<"        in the (Software Department-Engineering College).\n";
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 5:
			return ;
			break;
		case 6:
			exit(0);
			break;
		}//end os switch
	}
}

////////////////////////////////////////////////////////////////////
void user_menu(Book b[],Book th[])
{
	int choose,i=0;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(1);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2") 
			&&strcmp(temp,"3") &&strcmp(temp,"4"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			search_for_books(b,11,NO_BOOKS);
			break;
		case 2:
			search_for_books(th,12,NO_THESIS);
			break;
		case 3:
			cout<<"\n\n\n                      Help of user menu\n\n";
			cout<<"   1-Search for books: you can search for normal books by its\n";
			cout<<"        title, author subject and the keywords in the title\n\n";
			cout<<"   2-Search for thesis: you can search for normal books by its\n";
			cout<<"        title, author subject and the keywords in the title\n\n";
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 4:
			return ;
			break;
		}//end of switch
	}
}
#endif



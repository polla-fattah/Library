/*                         Main file 
	This file contain main function it loads all nessessary
	data from hard to the RAM and controls first interface
	of swiching between user menu and Librarian menu
*/

#include "linking.h"	
void flash();
main()
{	
	int choose;		//this variable to catch user choice after filtering it
	char temp[SIZE];//to get all user enteries befor filtering it

	startup();		//This function gets all information.inf information to the  
					//global variables which they decleared in the basic.h file
	flash();
	//creat electrical table to the books and thesis and thier borrowers
	Borrow *br=new Borrow[NO_BORROWERS];		
	Borrow *brth=new Borrow[NO_BORROWERSTH];
	Book *b=new Book[NO_BOOKS];
	Book *th=new Book[NO_THESIS];

	//thes steps fills created tables with data wich they 
	//are stored magnatically in the files 
	load(b,BOOK_HOLDER_FILE,NO_BOOKS);
	load(th,THESIS_FILE,NO_THESIS);
	load(br,BORROWER_FILE,NO_BORROWERS);
	load(brth,BORROWER_FILETH,NO_BORROWERSTH);
	
	while(true)//repets while user chooses termination option
	{
		do	//Until user chooses 1, 2, 3 or 4
		{
			system("cls");	//clears dos screen
			Interface(0);			//this function outputs conveniant 
									//interface that describes choices
			cin.getline(temp,SIZE);	//chatches user inputs
		}while(strcmp(temp,"1") &&strcmp(temp,"2")
			&&strcmp(temp,"3")&&strcmp(temp,"4"));

		choose=atoi(temp);	//change C_string to the int because 
							//switch dose not accept C_string

		system("cls");	//Clearing screen again

		switch(choose)			//this control statement to select user input
		{
		case 1:
			//option 1 directs to the user menu to serching for books and thesis only
			user_menu(b,th);	//this function controls on the user menu and needs
								//all books data to search
			break;
		case 2:
			//option 2 asks for the system password befor 
			//entring to the librarian control function
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t    Please, enter passward : ";
			cin.getline(temp,SIZE);
			if(!strcmp(temp,PASSWORD))
				librarian_menu(b,th,br,brth);
			else
			{
				cout<<"\t\t\t\tIncorrect password!\n";
				cout<<"\a\a\a\a\a";
				for(int a=0;a<10000000;a++);
			}
			break;
		case 3:
			//this choice displayes the following sentenses as a help
			cout<<"\n\n                 Welcome to the library program\n\n";
			cout<<"   1- User menu: if you choose this option you will see a menu.\n";
			cout<<"        Through this menu you can search for books or thesis.\n\n";
			cout<<"   2. Librarian menu: when you choose this option you will prompt\n";
			cout<<"        to type password with correct password you get access to\n";
			cout<<"        control works in the library otherwise you cannot enter system\n";
			cout<<"        With correct password librarian menu opened. \n";
			cout<<"        Through this menu you permit to add, removing ,updating \n";
			cout<<"        books, thesis, borrowers and changing password.\n\n";
			cout<<"   3. Help:  through this option you will get information to use program.\n";
			cout<<"        And the specific option corresponds with help number. All submenu  \n";
			cout<<"        contain individual help that advice you how to use the menu.\n\n";
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 4:
			//stors all global variables and terminates the program
			stor();
			return 0;
			break;
		}//end of switch
	}//end of while

	return 0;	//terminate program

}//end of main

void flash()
{
	cout<<"\n\n";
	cout<<"             * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	cout<<"             *                                                     *\n";
	cout<<"             *                                                     *\n";
	cout<<"             *                                                     *\n";
	cout<<"             *               Library Management system             *\n";
	cout<<"             *                                                     *\n";
	cout<<"             *                                                     *\n";
	cout<<"             *                                                     *\n";
	cout<<"             *                        Writen by                    *\n";
	cout<<"             *       Polla A. Fatah                                *\n";
	cout<<"             *       Awat A. Hamad                                 *\n";
	cout<<"             *       Dashti M. Ibrahim                             *\n";
	cout<<"             *       Fatima M. Muhammed-amin                       *\n";
	cout<<"             *       Jamal O. Qadr                                 *\n";
	cout<<"             *       Sanar F. Abdul-jabar                          *\n";
	cout<<"             *       Zahir M. ziad                                 *\n";
	cout<<"             *                                                     *\n";
	cout<<"             *                         Copy right Software Eng.    *\n";
	cout<<"             * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	for (int i=0;i<900000000;i++);
}

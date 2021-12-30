#ifndef search_h
#define search_h
#include "basic.h"
#include "interface_h.h"
int ACCsearch(Book b[],int acc,int Loop)
{
	for (int i=0;i<Loop ;i++)
		if(b[i].ACC==acc)
			return i;
	return -1;
}

int ACCsearch(Borrow br[],int acc,int Loop)
{
	for (int i=0;i<Loop ;i++)
		if(br[i].ACC==acc)
			return i;
	return -1;
}

void search_for_books(Book b[],int intref,int &Loop)
{
	int choose,i=0;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(intref);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2") &&strcmp(temp,"3")
			&&strcmp(temp,"4") &&strcmp(temp,"5")&&strcmp(temp,"6"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			do
			{
				stemp=word_cin("Enter Book's title : ");
				cout<<"Search result....\n";
				for (i=0;i<Loop;i++)
					if(b[i].title==stemp)
						show(b[i]);
			}while(choice("Do you want another search (Y/N) : "));
			break;
		case 2:
			do
			{
				stemp=word_cin("Enter Book's author : ");
				cout<<"Search result....\n";
				for (i=0;i<Loop;i++)
					if(b[i].author==stemp)
						show(b[i]);
			}while(choice("Do you want another search (Y/N) : "));
			break;
		case 3:
			do
			{
				stemp=word_cin("Enter Book's subject : ");
				cout<<"Search result....\n";
				for (i=0;i<Loop;i++)
					if(b[i].subject==stemp)
						show(b[i]);
			}while(choice("Do you want another search (Y/N) : "));
			break;
		case 4:
			do
			{
				stemp=word_cin("Enter kyeword in the book's title : ");
				cout<<"Search result....\n";
				for (i=0;i<Loop;i++)
					if(b[i].title.find(stemp)<=b[i].title.length())
						show(b[i]);
			}while(choice("Do you want another search (Y/N) : "));
			break;
		case 5:
			cout<<"\n\n                 Help of Serch for books menu\n\n";
			cout<<"   1- Search by title: when you want any book and you know\n";
			cout<<"         its title then choose me to find out your book\n\n";
			cout<<"   2- search by author: if you want to know what is all written\n";
			cout<<"         books of an author choose me please.\n\n";
			cout<<"   3. search by subject: when you want information for any subject\n";
			cout<<"         but you don't know what book is good for you don't wary\n";
			cout<<"         just choose me and enter your subject I find all books which\n";
			cout<<"         they mention your subject immediately.\n\n";
			cout<<"   4. choose by keyword in the title: I think you forget full title\n";
			cout<<"         of your lovely book try with me I never disappoint you, Just\n";
			cout<<"         write any part you mention of your book\n\n";
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 6:
			return ;
			break;
		}//end os switch
	}
}
void search_for_borrowers(Book b[],Borrow br[],int &Loopb,int &Loopbr,int interf)
{
	const int one_day=60*60*24;
	time_t today=time(NULL);
	int choose,i=0,index;
	char temp[SIZE];
	string stemp;
	while(true)
	{
		do
		{
			system("cls");
			Interface(interf);
			cin.getline(temp,SIZE);
		}while(strcmp(temp,"1") &&strcmp(temp,"2") 
			&&strcmp(temp,"3")&&strcmp(temp,"4") 
			&&strcmp(temp,"5")&&strcmp(temp,"6")&&strcmp(temp,"7"));
		choose=atoi(temp);
		system("cls");
		switch(choose)
		{
		case 1:
			do
			{
				stemp=word_cin("Enter Borrower's name : ");
				cout<<"Search result....\n";
				for (i=0;i<Loopbr;i++)
					if(br[i].name==stemp)
					{
						index=ACCsearch(b,br[i].ACC,Loopb);
						show(b[index],br[i],int(difftime(today,br[i].date)/ one_day));
					}
			}while(choice("Do you want another search (Y/N) : "));
			break;
		case 2:
			do
			{
				stemp=word_cin("Enter Borrower's collage : ");
				for (i=0;i<Loopbr;i++)
					if(br[i].collage==stemp)
					{
						index=ACCsearch(b,br[i].ACC, Loopb);
						show(b[index],br[i],int(difftime(today,br[i].date)/ one_day));
					}
			}while(choice("Do you want another search (Y/N) : "));
			break;
		case 3:
				for (i=0;i<Loopbr;i++)
					if(int(difftime(today,br[i].date)/one_day)>30  &&  br[i].degree=="staff"
						|| int(difftime(today,br[i].date)/one_day)>10 &&br[i].degree=="student")
					{
						index=ACCsearch(b,br[i].ACC,Loopb);
						show(b[index],br[i],int(difftime(today,br[i].date)/ one_day));
					}
			while(!choice("Do you want to return back (Y/N) : "));
			break;
		case 4:
				for (i=0;i<Loopbr;i++)
				{
					index=ACCsearch(b,br[i].ACC,Loopb);
					show(b[index],br[i],int(difftime(today,br[i].date)/ one_day) );
				}
			while(!choice("Do you want to return back (Y/N) : "));
			break;
		case 5:
			cout<<"\n\n             Help of Search for borrowers menu\n\n";
			cout<<"   1- Search by borrower's name: I'm profusion to find every\n";
			cout<<"         borrower just choose me and enter names.\n\n";
			cout<<"   2- Search by borrower's collage: every collage may want\n";
			cout<<"         to know how are they borrowed from library.I can\n";
			cout<<"         help them to find all borrowers of their college.\n\n";
			cout<<"   3- Search for delayed borrowers : I am just a calculator. But\n";
			cout<<"         I can find all borrowers who delay to return books\n\n";
			cout<<"   4- View all borrowers: Hi Do you want to know all borrowers\n";
			cout<<"         in this library.\n\n";
			while(!choice("Do you want to exit help (Y/N) : "));
			break;
		case 6:
			return ;
			break;
		}
	}
}
#endif
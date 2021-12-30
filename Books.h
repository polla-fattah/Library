#ifndef Books
#define Books
#include "basic.h"
#include "search.h"
#include "opening.h"
void Add_book(Book b[],int borrowed,const char file[],int &Loop)
{
	Book btemp;
	int index=0,bin[SIZE],i=0;
	ofstream out(file,ios::app);
	bool terminate=true;
	do
	{
		while(true)
		{
			terminate=true;
			btemp.ACC = num_cin("Enter book's ACC      : ");
			bin[index]=btemp.ACC;
			for (i=0;i<index;i++)
				if (bin[i]==btemp.ACC)
				{
					cout<<"You can not use same ACC tiwce!\n";
					terminate=false;
				}
			if(ACCsearch(b,btemp.ACC,Loop)!=-1)
			{
				cout<<"You can not use same ACC tiwce!\n";
				terminate=false;
			}
			if(terminate)
				break;
		}
		btemp.ISBN   =word_cin("Enter book's ISBN     : ");
		btemp.title  =word_cin("Enter book's title    : ");
		btemp.author =word_cin("Enter book's author   : ");
		btemp.subject =word_cin("Enter book's subject : ");
		btemp.contry =word_cin("Enter publisher contry: ");
		btemp.edition=num_cin ("Enter book's edition  : ");
		btemp.part   =num_cin ("Enter book's part     : ");
		btemp.year   =num_cin ("Enter publishing year : ");
		btemp.price  =num_cin ("Enter book's price    : ");
		btemp.borrowable=borrowed;
		if(choice("Are you sure to add this book (Y/N): "))
		{
			index++;
			Loop++;
			out <<btemp.ACC<<'\t'<<btemp.ISBN<<'\t'<<btemp.title<<'\t';
			out	<<btemp.author<<'\t'<<btemp.subject<<'\t'<<btemp.contry<<'\t'<<btemp.edition<<'\t';
			out	<<btemp.part<<'\t'<<btemp.year<<'\t'<<btemp.price<<'\t'<<btemp.borrowable<<'\n';
		}

	}while(choice("Do you want to add another book (Y/N): "));	
	out.close();
	stor();
	system("refresh");
	exit(0);
}

void remove_book(Book b[],const char file[], int &Loop)
{
	int index,no_of_books=Loop;
	while(true) 
	{
		index=ACCsearch(b,num_cin("Enter book's ACC : "),Loop);
		if(index==-1)
		{
			cout<<"There is no book whith this ACC! \n";
			if(choice("Do you want to continue (Y/N) : "))
				continue;
			else
				break;
		}
		if (b[index].title == word_cin("Enter book's title : "))
		{
			if(choice("Are you sure you want to remove tihs book (Y/N) : "))
			{
				Loop--;
				b[index].ACC=0;
			}
		}
		else
		{
			cout<<"This title has no prevous ACC! \n";
			if(choice("Do you want to continue (Y/N) : "))
				continue;
			break;
		}
		if(!choice("Do you want to remove another book (Y/N) : "))
			break;
	}
	ofstream out(file,ios::trunc);

	for (int i=0;i<no_of_books;i++)
	{
		if(b[i].ACC)
		{
			out <<b[i].ACC<<'\t'<<b[i].ISBN<<'\t'<<b[i].title<<'\t';
			out	<<b[i].author<<'\t'<<b[i].subject<<'\t'<<b[i].contry<<'\t'<<b[i].edition<<'\t';
			out	<<b[i].part<<'\t'<<b[i].year<<'\t'<<b[i].price<<'\t'<<b[i].borrowable<<'\n';
		}
	}
	out.close();
	stor();
	system("refresh");
	exit(0);
}

#endif

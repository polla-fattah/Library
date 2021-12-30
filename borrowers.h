#ifndef Borrowers_h
#define Borrowers_h

#include "basic.h"
#include "search.h"
bool cannot(Borrow br[],Borrow bin[],int index,int Loop)
{
	int count=0;
	for(int i=0;i<Loop;i++)
		if(bin[index].name==br[i].name &&bin[i].ID==br[i].ID)
			count++;
	for(i=0;i<=index;i++)
		if(bin[index].name==bin[i].name && bin[i].ID==bin[i].ID)
			count++;
	if(bin[index].degree=="staff" && count>7)
		return true;
	if(bin[index].degree=="student" && count>3)
		return true;
	return false;

}
bool not_valied(Borrow bin[],Borrow br[],Book b[],int index,int &Loopb,int &Loopbr)
{
	int Bindex;
	while(true)
	{
		bin[index].ACC=num_cin("Enter book's ACC      : ");
		if(ACCsearch(br,bin[index].ACC,Loopbr)!=-1 ||ACCsearch(bin,bin[index].ACC,index)!=-1)
		{
			cout<<"This book is in borrow!\n";
			if(choice("Do you want to continue (Y/N) : "))
			continue;
			else
				return false;
		}
		Bindex=ACCsearch(b,bin[index].ACC,Loopb);
		if(Bindex==-1)
		{
			cout<<"There is no book by this ACC!\n";
			if(choice("Do you want to continue (Y/N) : "))
				continue;
			else
				return false;
		}
		if(b[Bindex].title!=word_cin("Enter book's title : "))
		{
			cout<<"There is no book by this title\n";
			if(choice("Do you want to continue (Y/N) : "))
				continue;
			else
				return false;
		}
		if(b[Bindex].borrowable==0)
		{
			cout<<"Sorry you can not borrow this book!\a\n";
			if(choice("Do you want to continue (Y/N) : "))
				continue;
			else
				return false;
		}
		break;
	}
	return true;
}

void add_borrower(Book b[],Borrow br[],const char file[],int &Loopbr,int &Loopb)
{
	int aza=Loopbr;
	ofstream out(file,ios::app);
	time_t to_day=time(NULL);
	int index=0,i=0;
	Borrow bin[SIZE];
	while(true)
	{
		if(!not_valied(bin,br,b,index,Loopb,Loopbr))
			break;
		bin[index].name=word_cin("Enter borrower name : ");
		bin[index].ID=word_cin("Enter borrower ID : ");
		bin[index].collage=word_cin("Enter borrower collage : ");
		do
			bin[index].degree= word_cin("Enter borrower degree (staff/student) : ");
		while(bin[index].degree!="staff" && bin[index].degree != "student");
		bin[index].date=to_day;

		if(cannot(br,bin,index,Loopbr))
		{
			cout<<"This borrower passed legal borrowing number of books!\n\a";
			if(!choice("Do you want to continue any way (Y/N) : "))
				continue;
		}
		if(choice("Are you sure to add this borrower (Y/N) : "))
		{
			out <<bin[index].ACC<<'\t'<<bin[index].name<<'\t'<<bin[index].ID<<'\t'
				<<bin[index].collage<<'\t'<<bin[index].degree<<'\t'<<bin[index].date<<'\n';
			index++;
			aza++;
		}
		if(!choice("Do you want add another borrower (Y/N) : "))
			break;

	}
	Loopbr=aza;
	out.close();
	stor();
	system("refresh");
	exit(0);
}

void remove_borrower(Borrow br[],const char file[],int &Loop)
{
	int index,borrower_number=Loop;
	while(true)
	{
		index=ACCsearch(br,num_cin("Enter book's ACC : "),Loop);
		if(index==-1)
		{
			cout<<"There is no book in borrow by this name!\a\n";
			if(choice("Do you want to continue (Y/N) : "))
				continue;
			else
				break;
		}
		if(br[index].name != word_cin("Enter borrower name : "))
		{
			cout<<"This book does not borrowed by entered name!\a\n";
			if(choice("Do you want to continue (Y/N) : "))
				continue;
			else
				break;
		}
		if(choice("Are you sure to remove this borrower (Y/N) : "))
		{
			Loop--;
			br[index].ACC=0;
		}
		if(!choice("Do you want to remove another borrower (Y/N) : "))
			break;
	}
	ofstream out(file,ios::trunc);
	for(int i=0;i<borrower_number;i++)
	{
		if(br[i].ACC)
		{
			out <<br[i].ACC<<'\t'<<br[i].name<<'\t'<<br[i].ID<<'\t'
				<<br[i].collage<<'\t'<<br[i].degree<<'\t'<<br[i].date<<'\n';
		}
	}
	out.close();
	stor();
	system("refresh");
	exit(0);
}
#endif

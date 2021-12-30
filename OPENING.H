#ifndef opening
#define opening
#include "basic.h"
void load(Book b[],const char file[],int Loop)
{
	ifstream in(file);
	for (int i=0;i<Loop;i++)
	{
		in >> b[i].ACC    >> b[i].ISBN   >> b[i].title  ;
		in >> b[i].author >>b[i].subject>> b[i].contry >> b[i].edition;
		in >> b[i].part   >> b[i].year   >> b[i].price>>b[i].borrowable;
	}
	in.close();
}
void load(Borrow br[],const char file[],int Loop)
{
	ifstream in(file);
	for (int i=0; i<Loop ;i++)
	{
		in >> br[i].ACC >> br[i].name >> br[i].ID;
		in >> br[i].collage >>br[i].degree >>br[i].date;
	}
	in.close();
}	
void startup()
{
	ifstream in(INFORMATION);
	in>>NO_BOOKS;
	in>>NO_BORROWERS;
	in>>NO_THESIS;
	in>>NO_BORROWERSTH;
	in.ignore();
	in.getline(PASSWORD,SIZE);
	in.close();
}
void stor()
{
	ofstream out(INFORMATION);
	out<<NO_BOOKS<<'\n'<<NO_BORROWERS<<'\n';
	out<<NO_THESIS<<'\n'<<NO_BORROWERSTH<<'\n';
	out<<PASSWORD<<'\n';
	out.close();
}
void change_password()
{
	char temp[SIZE];

	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tEnter old password : ";
	cin.getline(temp,SIZE);
	if(strcmp(temp,PASSWORD)!=0)
	{
		cout<<"\n\t\t\t\tIncorrect password!";
		for (int a=0;a<10000000;a++);
		cout<<"\a\a\a\a\a";
		return;
	}
	while(true)
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tEnter new password : ";
		cin.getline(temp,SIZE);
		cout<<"\t\t\t\tCheck new password : ";
		cin.getline(PASSWORD,SIZE);
		if(strcmp(temp,PASSWORD)==0)
		{
			cout<<"\n\t\t\t\tYour password is changed!\a\a";
			for(int i=0;i<150000000;i++);
			break;
		}
	}
	stor();
}

#endif
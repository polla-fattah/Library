#ifndef interface_h
#define interface_h
#include "basic.h"
void show(Book b)
{
	remove_star(b.author);
	remove_star(b.contry);
	remove_star(b.ISBN);
	remove_star(b.title);
	remove_star(b.subject);

	cout <<"-----------------------------------------------------------\n";
	cout <<"  Book's ACC      : "<<b.ACC<<endl;
	cout <<"  Book's ISBN     : "<<b.ISBN<<endl;
	cout <<"  Book's title    : "<<b.title<<endl;
	cout <<"  Book's author   : "<<b.author<<endl;
	cout <<"  Book's Subject  : "<<b.subject<<endl;
	cout <<"  Book's edition  : "<<b.edition<<endl;
	cout <<"  Book's part     : "<<b.part<<endl;
	cout <<"  Publishing place: "<<b.contry<<endl;
	cout <<"  Publishing year : "<<b.year <<endl;
	cout <<"  Book's price    : " <<b.price<<endl;
	if(b.borrowable==0)
		cout <<"                    Can NOT be borrowed\n";
	cout <<"-----------------------------------------------------------\n";
}

void show(Book b,Borrow br,int late)
{
	remove_star(br.collage);
	remove_star(br.ID);
	remove_star(br.name);
	remove_star(b.ISBN);
	remove_star(b.title);

	cout <<"-----------------------------------------------------------\n";
	cout <<"  Book's ACC         : "<<b.ACC<<endl;
	cout <<"  Book's ISBN        : "<<b.ISBN<<endl;
	cout <<"  Book's title       : "<<b.title<<endl;
	cout <<"  Borrower name      : "<<br.name<<endl;
	cout <<"  Borrower collage   : "<<br.collage<<endl;
	cout <<"  Borrower ID        : "<<br.ID<<endl;
	cout <<"  Borrower degree    : "<<br.degree<<endl;
	cout <<"  Total borowing days: "<<late<<endl;
	cout <<"-----------------------------------------------------------\n";
}
void Interface(int flag)
{
	cout<<"\n\n\n\n\n\n\n                    "<<char(201);
	for(int i=0 ;i<40;i++)
		cout<<char(205);
	cout<<char(187)<<endl;
	switch(flag)
	{
	case 0:
		cout<<"                    "<<char(186)<<"               Main menu                "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-User menu                            "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Librarian menu                       "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Exit                                 "<<char(186)<<endl;
		break;
	case 1:
		cout<<"                    "<<char(186)<<"               Usre Menu                "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Search for book                      "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Search for thesis                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Return back                          "<<char(186)<<endl;
		break;
	case 2:
		cout<<"                    "<<char(186)<<"            Librarian menu              "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Book controll menu                   "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Thesis controll menu                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Change password                      "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Return back                          "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 6-Exit                                 "<<char(186)<<endl;
		break;
	case 21: 
		cout<<"                    "<<char(186)<<"          Book controll menu            "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Search for books                     "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Search for borrowers                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Add Remove books                     "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Add Remove borrowers                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 6-Return back                          "<<char(186)<<endl;
		break;
	case 22: 
		cout<<"                    "<<char(186)<<"         Thesis controll menu           "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Search for thesis                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Search for borrowers                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Add Remove thesis                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Add Remove borrowers                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 6-Return back                          "<<char(186)<<endl;
		break;
	case 11: case 211:
		cout<<"                    "<<char(186)<<"         Search for books menu          "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Search by title                      "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Search by author                     "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Search by subject                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Search by kyeword                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 6-Return back                          "<<char(186)<<endl;
		break;
	case 12: case 221:
		cout<<"                    "<<char(186)<<"         Search for thesis menu         "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Search by title                      "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Search by author                     "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Search by subject                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Search by kyeword                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 6-Return back                          "<<char(186)<<endl;
		break;
	case 222:case 212:
		cout<<"                    "<<char(186)<<"       Search for borrowers menu        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Search by borrower's name            "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Search by collage                    "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Search for delayed borrowers         "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Viue all borrowers                   "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 6-Return back                          "<<char(186)<<endl;
		break;
	case 213:
		cout<<"                    "<<char(186)<<"            Add Remov books             "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Add new books                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Add non borowable books              "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Remove kooks                         "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Return back                          "<<char(186)<<endl;
		break;
	case 223:
		cout<<"                    "<<char(186)<<"            Add Remov thesis            "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Add new thesis                       "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Add non borowable thesis             "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Remove thesis                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 5-Return back                          "<<char(186)<<endl;
		break;
	case 214:case 224:
		cout<<"                    "<<char(186)<<"         Add Remov borrowers            "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<"                                        "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 1-Add borrowrs                         "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 2-Remove borrowers                     "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 3-Help                                 "<<char(186)<<endl;
		cout<<"                    "<<char(186)<<" 4-Return back                          "<<char(186)<<endl;
		break;
	}
	cout<<"                    "<<char(200);
	for(i=0 ;i<40;i++)
		cout<<char(205);
	cout<<char(188)<<endl;
	cout<<"                       "<<"Please, enter your choice : ";
}

#endif
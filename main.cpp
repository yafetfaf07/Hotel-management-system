/*
HOTEL MANAGMENT SYSTEM
The features that this code includes are:
      1.Hotel reservation
      2.View  reserved rooms
      3.Edit reserved rooms
      4.Delete reserved rooms

		DONE BY: YAFET YOSEF
*/


#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct customer
{
    int roomnum;
    string fname;
    string sname;
    string address;
    string phone ;

};
void menu(struct customer cust);
void display(struct customer cust);
void reservation(struct customer cust);
void edit(struct customer cust);
void deletefile(struct customer cust);
int main()
{
    string password,secret,username,validate;
 customer cust;
     system("color 02");
        validate="user1";
        secret="pass";
       cout<<endl<<endl<<endl;
       cout<<"\t\t\t\tHOTEL MANAGMENT SYSTEM\n";

         for(int i=5;i>=0;i--){
          cout<<"\t\t\t\t ENTER username:";
          getline(cin,username);
            if(username==validate){
                cout<<endl;
                break;
               }
             else{
             cout<<"\t\t\t\t access denied "<<i<<" attempts left\n";
             }
               if(i==0){
               cout<<endl;
                cout<< "\t\tFailed Identification";
                return 0;
             }
         }
          for(int i=5;i>=0;i--){
              cout<<"\t\t\t\t ENTER PASSWORD :";
              cin>>password;
            if(secret==password){
                cout<<endl;
                break;
               }
             else{
             cout<<"\t\t\t\t access denied "<<i<<" attempts left\n";
             }
             if(i==0){
                cout<<endl;
                cout<< "\t\t Wrong password entered";
                return 0;
             }

             }
     system("cls");
     menu(cust);
    cout<< "\n\n\t\t Thank you for using our program";

    return 0;
}
void reservation(struct customer cust)
{
    system("cls");
    char choice;
    ifstream check;
    ofstream opfile;
    string numstr;
       cout<<"\t\t\t\t Total no. of Rooms - 70"<<endl;
       cout<<"\t\t\t\t Two bed Rooms from 1 - 25"<<endl;
       cout<<"\t\t\t\t single bed Rooms from  26 - 50"<<endl;
       cout<<"\t\t\t\t Family Rooms from 51 - 60"<<endl;
       cout<<"\t\t\t\t suite Rooms from 61 - 70"<<endl;

    cout<<"enter roomnum: ";
    cin>>cust.roomnum;

                while(cin.fail()) {
                cin.clear();
                cin.ignore(10,'\n');
                cout<<"\"\t\t\t\tplease enter a valid input\"";
                cin>>cust.roomnum;
           };
           while(cust.roomnum>70||cust.roomnum<1)
           {
                cout<<"\t\t\t\t enter a number between 1 and 70 ";
                cin>>cust.roomnum;

           };

    numstr=to_string(cust.roomnum);
    numstr=numstr+".txt";
    check.open(numstr);
     while(check){
        cout<<"\t\t\t\tThe room is booked\n";
        check.close();
        cout<<"\t\t\t\tEnter another roomnum";
        cin>>cust.roomnum;
        numstr=to_string(cust.roomnum);
        numstr=numstr+".txt";
        check.open(numstr);
     };
     check.close();
    opfile.open(numstr,ios::out);
    if(opfile.is_open()){
    opfile<<cust.roomnum<<".\n";
    cout<<"\t\t\t\tEnter First name: ";
    cin>>cust.fname;
    opfile<<"First Name: "<<cust.fname<<endl;
    cout<<"\t\t\t\t Enter Second name: ";
    cin>>cust.sname;
    opfile<<"Second Name: "<<cust.sname<<endl;
    cout<<"\t\t\t\tEnter address: ";
    cin>>cust.address;
    opfile<<"Address: "<<cust.address<<endl;
    cout<<"\t\t\t\tEnter phone number: ";
    cin>>cust.phone;
    opfile<<"phone number: "<<cust.phone<<endl;
      }
    opfile.close();
    cout<<"\t\t\t\t1.menu "<<endl;
    cout<<"\t\t\t\t2.exit"<<endl;
    cin>>choice;
    switch(choice)
    {
    case '1':
        menu(cust);
        break;
    case '2':
        break;
    default:
    cout<<"\n\t\t\t INALID INPUT";
    system("pause");
    menu(cust);
    break;

    }
};
void display(struct customer cust)
{
 system("cls");
 char choice;
 string numstr,view;
 ifstream ipfile;
 cout<<endl<<endl;
 cout<<"\t\t\t\t\t Total no. of Rooms - 70"<<endl;
       cout<<"\t\t\t\t Two bed Rooms from 1 - 25"<<endl;
       cout<<"\t\t\t\t single bed Rooms from  26 - 50"<<endl;
       cout<<"\t\t\t\t Family Rooms from 51 - 60"<<endl;
       cout<<"\t\t\t\t suite Rooms from 61 - 70"<<endl;

       cout<<"\t\t\t\t enter which room you want to view";
       cin>>cust.roomnum;

                while(cin.fail()) {
                cin.clear();
                cin.ignore(10,'\n');
                cout<<"\"\t\t\t\t please enter a valid input\"";
                cin>>cust.roomnum;
                };
           while(cust.roomnum>70||cust.roomnum<1)
             {
                cout<<"\t\t\t\t enter a number betweem 1 and 70 ";
                cin>>cust.roomnum;

           };
 numstr=to_string(cust.roomnum);
 numstr=numstr+".txt";
 ipfile.open(numstr,ios::in);
 if(ipfile.is_open()){
 while(!ipfile.eof())
 {
     getline(ipfile,view);
     cout<<view<<endl;
 }
 }
 else
    cout<<"\t\t\t\t Cannot be displayed\n";
 ipfile.close();
    cout<<"\t\t\t\t 1.menu "<<endl;
    cout<<"\t\t\t\t 2.exit"<<endl;
    cin>>choice;
    switch(choice)
    {
    case '1':
        menu(cust);
        break;
    case '2':
        break;
    default:
    cout<<"\n\t\t\t INALID INPUT";
    system("pause");
    menu(cust);
    break;

    }
};

void edit(struct customer cust)
{
   system("cls");

  char choice;
  ofstream edfile;
  ifstream check;
  string numstr;
  cout<<"\t\t\t\t enter which room you want to edit";
  cin>>cust.roomnum;
   while(cin.fail()) {
                cin.clear();
                cin.ignore(10,'\n');
                cout<<"\"\t\t\t\t please enter a valid input\"";
                cin>>cust.roomnum;
                continue;
           };

  numstr=to_string(cust.roomnum);
  numstr=numstr+".txt";
  check.open(numstr);
   if(check){
       check.close();
       edfile.open(numstr,ios::out);
  if(edfile.is_open()){
    edfile<<cust.roomnum<<".\n";
    cout<<endl;
    cout<<"\t\t\t\t Enter First name: ";
    cin>>cust.fname;
    edfile<<"First Name: "<<cust.fname<<endl;
    cout<<"\t\t\t\t Enter Second name: ";
    cin>>cust.sname;
    edfile<<"Second Name: "<<cust.sname<<endl;
    cout<<"\t\t\t\t Enter address: ";
    cin>>cust.address;
    edfile<<"Address: "<<cust.address<<endl;
    cout<<"\t\t\t\t Enter phone number: ";
    cin>>cust.phone;
    edfile<<"phone number: "<<cust.phone<<endl;
    }
   }
    else
        cout<<"\t\t\t\t Error has occurred\n";
   cout<<"\t\t\t\t 1.menu "<<endl;
    cout<<"\t\t\t\t 2.exit"<<endl;
    cin>>choice;
    switch(choice)
    {
    case '1':
        menu(cust);
        break;
    case '2':
        break;
    default:
    cout<<"\n\t\t\t INALID INPUT ";
    system("pause");
    menu(cust);
    break;

    }


};
void deletefile (struct customer cust){
   system("cls");
  char choice;
  int check,len;
  string numstr;
    cout<<"\t\t\t\t enter which room you want to delete";
  cin>>cust.roomnum;
              while(cin.fail()) {
                cin.clear();
                cin.ignore(10,'\n');
                cout<<"\"\t\t\t\t please enter a valid input\"";
                cin>>cust.roomnum;
                continue;
                };
           while(cust.roomnum>70||cust.roomnum<1)
             {
                cout<<"\t\t\t\t enter a number between 1 and 70 ";
                cin>>cust.roomnum;

           };
  numstr=to_string(cust.roomnum);
  numstr=numstr+".txt";
  len=numstr.length();
  char delroom[len+1];
  strcpy(delroom, numstr.c_str());
   check=remove(delroom);
  if (check==0)
    cout<<"\t\t\t\t File has been successfully deleted\n";
   else
   cout<<"\t\t\t\t Operation unsuccessful\n";
   cout<<"\t\t\t\t 1.menu "<<endl;
    cout<<"\t\t\t\t 2.exit"<<endl;
    cin>>choice;
    switch(choice)
    {
    case '1':
        menu(cust);
        break;
    case '2':
         break;
    default:
    cout<<"\n\t\t\t INALID INPUT\n";
    system("pause");
    menu(cust);
    break;

    }

 }
void menu(struct customer cust)
{
    system("cls");
 char choice;
    cout<< "\t\t\t\t ===========================" << endl;
    cout<< "\t\t\t\t Hotel Management System" << endl;
    cout<< "\t\t\t\t ===========================" << endl;
    cout<< "\t\t\t\t 1. Customer Reservation\n";
    cout<< "\t\t\t\t 2. Display\n";
    cout<< "\t\t\t\t 3. Edit\n";
    cout<< "\t\t\t\t 4. Delete\n";
    cout<< "\t\t\t\t 5. Exit\n";
    cin >> choice;

 switch (choice)
 {
 case '1':
    reservation(cust);
    break;
 case '2':
    display(cust);
    break;
 case '3':
    edit(cust);
    break;
 case '4':
    deletefile(cust);
    break;
 case '5':
 break;
 default:
    cout<<"\n\t\t\t INALID INPUT try again\n";
    system("pause");
    menu(cust);
    break;

 };

}

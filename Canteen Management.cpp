#include<time.h>
#include<math.h>
#include<iostream>
#include<fstream>
#include<istream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctime>
#include<windows.h>
#ifdef _WIN32
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include<dos.h>
using namespace std;
class item;
class admin;
class employee;
string empnamee;
string custnamee;
string custphnoo;
string custemaill;
int custagee;
string custitems[100];
int custqty[100];
int custtotals[100];
int count_cust=0;
void recipt();
void gotoxy(int ,int );
void gotoxy(int x,int y) //function to print anything at desired position...
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void loading(){
        cout<<"\n\n\n\n\t\t\t\tLoading...";
        char x = 219;
        for(int i=0;i<25;i++){
            cout<<x;
            if(i<10)
                Sleep(150);
            if(i>=10 && i<20)
                Sleep(75);
            if(i>=10)
                Sleep(25);

        }
        system("cls");

    }

void loading(int N) //function for loading screen 7 zeros,
{
int i,j;
char c;//42 is ASCII code for Character which is to be printed
c=42;
gotoxy(24,10);
for(i=1;i<=37;i++)
{
cout << c;
}
gotoxy(24,11);
cout << "*                                   *";
gotoxy(24,12);
for(i=1;i<=37;i++)
{
cout << c;
}
c= 219;//219 is ASCII code for Character which is to be printed
gotoxy(25,11);
cout << "Loading : ";

gotoxy(35,11);

for(i=1;i<=25;i++)
{
for(j=0; j<=N;j++);
{
} //determine speed of loading screen
cout << c;

}
}

class item
{

	public:
		string name;
		string username;
		string password;
		int code   ;
		int price  ;
		int qty    ;
		void setdata(string a , int b , int c , int d);
		string getname();
		int getcode();
		int getprice();
		int getqty();
	    virtual void add_item()=0;
	    virtual void edit_item()=0;
	    virtual void del_item()=0;
	    
};

class admin:public item
{

    protected:
    string empname;
    string emppass;
    string empusername;
    public:
    void welcome();
    void add_item();
	void edit_item();
	void del_item();
	void wholesell();
    void addemployee();
    void deleteemployee();
    void setadmin();
    	admin(string n="Empty",string u="Empty",string p="Empty"){
    name=n;
    username=u;
    password=p;
    string tname;
    string tusername;
    string tpassword;
    int token=0;
    fstream adminn("adminsdata.bin",ios::in);
    if(name!="Empty"&&username!="Empty"&&password!="Empty"){
        if(!adminn){
            adminn.open("adminsdata.bin",ios::app|ios::out);
            adminn<<" "<<name<<" "<<username<<" "<<password<<"\n";

        }
        else{
            adminn>>tname>>tusername>>tpassword;
            while(!adminn.eof()){
                if(username==tusername){
                    token++;
                }
                adminn>>tname>>tusername>>tpassword;
            }
            adminn.close();

            if(token==0){
                cout<<"\n\n\n"<<token<<"\n\n";
            adminn.open("adminsdata.bin",ios::app|ios::out);
            adminn.seekp(0 , ios::end);
            adminn<<" "<<name<<" "<<username<<" "<<password<<"\n";
            }

        }
    }
    adminn.close();
    }
        string tempname;
       // void administration();
        void adminslogin();
        void List();
        void menu();
        ~admin(){}
    
};
class employee:public admin{
public:
   void menu();
   void employeelogin();
   void sellitem();
   void buyitem();
};
void employee::menu(){
        int choice;
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t1-sell Item\n\t\t\t\t3-exit\n\n\n";
        cout<<"\t\t\t\tPlease Enter Your Choice\t";
        cin>>choice;
        switch(choice){
   
    case 1:
    {
        fstream check("database.txt" , ios::in);
        if(!check){
            cout<<"\n\n\n\t\tSorry we dont have any Item available yet,Please contact us Later ";
            loading();
            check.close();
            break;
        }

        else{
        check.close();
        system("cls");
        List();
        buyitem();
        break;
        }
    }
    case 3:
        break;
        }

}
void employee::buyitem(){
    char choice;
    fstream data,data1;
    string med;
    int choice1;
    int code;
    int qty;
    int tcode;
    string tname;
    int tprice;
    int total=0;
    int checkcode;
    int checkqty;
    int tqty;
    string tpain;
    int i=0;
    int token=0;
    int no;
m:
cout<<"\n\n\nDo you want to buy Item"<<endl;
cout<<" \nY-yes\nN-No";
cout<<"\nEnter You Choice \t:";
cin>>choice;
if(choice=='n' || choice=='N'){
        system("cls");
        menu();
}
else if(choice=='y' || choice=='Y')
{
string cname;
string cphno;
string cemail;
int cage;
int temp=0;
fflush(stdin);
cout<<"\n\n\t\t\tEnter Customer`s Details"<<endl;
cout<<"\nName Of The Customer \t:";
getline(cin,cname);
custnamee=cname;
fflush(stdin);
cout<<"\nphone no Of The Customer \t:";
cin>>cphno;
custphnoo=cphno;
fflush(stdin);
cout<<"\nEmail Of The Customer \t:";
cin>>cemail;
custemaill=cemail;
fflush(stdin);
cout<<"\nAge Of The Customer \t:";
cin>>cage;
fflush(stdin);
custagee=cage;
string a;
string b;
string c;
int d;
int token=0;
fflush(stdin);
cout<<"\n\nHow many Items you want to buy\t:";
cin>>no;
fflush(stdin);
fstream cust;
cust.open("customerrecord.txt" , ios::in);
if(!cust){
    cust.open("customerrecord.txt" , ios::app|ios::out);
    cust<<" "<<cname<<" "<<cphno<<" "<<cemail<<" "<<cage<<"\n";
    cust.close();
}
else{
    cust>>a>>b>>c>>d;
    while(!cust.eof()){
        if(b==cphno || c==cemail){
            token++;
        }
        cust>>a>>b>>c>>d;

}
cust.close();
    if(token==0){
        cust.open("customerrecord.txt" , ios::app|ios::out);
        cust.seekg(0, ios_base::end);
        cust<<" "<<cname<<" "<<cphno<<" "<<cemail<<" "<<cage<<"\n";

        cust.close();
    }
}

for(int i=0;i<no;i++){
    token=0;
cout<<"\n\nSelect You Buying Criteria";
cout<<"\n\n1-Name of the Item\n2- Item  Code"<<endl;
cout<<"\nEnter your choice\t:";
cin>>choice1;
fflush(stdin);
switch(choice1){
    case 1:
cout<<"\n\nEnter the name of the Item \t:";
cin>>med;
cout<<"\n\nEnter the Quantity of the Item \t:";
cin>>qty;
break;
    case 2:
        cout<<"\n\nEnter the Item code of the Items \t:";
        cin>>code;
        cout<<"\n\nEnter the Quantity of the Items \t:";
        cin>>qty;
        break;
}
fstream buy("database.txt",ios::in);
if(!buy){
        cout<<"File error"<<endl;
        break;
}
else{
    buy>>tcode>>tname>>tprice>>tqty;
    setdata(tname,tcode ,tprice,tqty);
    checkqty=getqty();
    while(!buy.eof()){
        if((med==getname()&&qty<=getqty())||(code==getcode()&&qty<=getqty())){
            fstream cdata;
            fstream stock;
            cdata.open(cphno.c_str() , ios::app | ios::out);
            stock.open("overallsell.txt" , ios::app|ios::out);
            stock.seekp(0,ios::end);
            cdata.seekp(0, ios::end);
            cdata<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<qty<<" "<<(qty*getprice())<<"\n";
            stock<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<qty<<" "<<(qty*getprice())<<"\n";
            checkqty=getqty();
            custtotals[i]=qty*getprice();
            total+=custtotals[i];
            custitems[i]=getname();
            custqty[i]=qty;
            count_cust++;
            checkcode=getcode();
            stock.close();
            cdata.close();
            int tcode;
    string tname;
    int tprice;
    int tqty;
    string tpain;
    int mkey;
    buy.close();
    data.open("database.txt" , ios::in);
    data.seekg(0, ios::beg);
    if(data ){

        data1.open("database1.txt" , ios::app|ios::out);
        data1.seekp(0, ios::beg);

        data>>tcode>>tname>>tprice>>tqty;
        setdata(tname,tcode,tprice,tqty);
        while(!data.eof()){

            if(code==tcode || med==tname){
                temp=tqty-qty;
                 data1<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<temp<<"\n";
                 temp=0;
                  }
        else{
            data1<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<getqty()<<"\n";
        }
        data>>tcode>>tname>>tprice>>tqty;
        setdata(tname,tcode,tprice,tqty);

    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt" , "database.txt");


    }

             token++;
             break;
        }
        buy>>tcode>>tname>>tprice>>tqty;
        setdata(tname,tcode,tprice,tqty);

    }
    buy.close();

        }

    if(token==0){
    cout<<"\n\nSorry This Item is not available ";
    }
    else if(qty>checkqty){
    cout<<"\n\nSorry we have not enough quantity available ";
    }
}
    if(total>0){
    cout<<"\n\nPlease Wait While Your Bill is creating "<<endl;
    loading();
    recipt();
    }
    else
        Sleep(10000);
    }
    else
    {
    cout<<"\n\nSelect right choice";
    goto m;
    }

    }
void recipt(){
    system("cls");
    int total=0;
    cout<<"\n\n\t----------------------------------------------------------\n\n";
    cout<<"\t\t\tFAST NUCES CAFETERIA\n\n";
    cout<<"\t----------------------------------------------------------\n\n";
    cout<<"\tCustomer Name     :\t\t"<<custnamee<<endl;
    cout<<"\tCustomer Phone No :\t"<<custphnoo<<endl;
    cout<<"\tCustomer Email    : \t"<<custemaill<<endl;
    cout<<"\tCustomer Age      : \t\t"<<custagee<<endl;
    cout<<"\n\n\n";
    cout<<"\tMed Name\t\t\tqty\tTotal\n\n";
    for(int i =0 ; i<count_cust ; i++){
            if(custqty[i]!=0){

        cout<<"\t"<<custitems[i]<<"\t\t\t\t"<<custqty[i]<<"\t"<<custtotals[i]<<"\n";
        total=total+custtotals[i];
            }
    }
    cout<<"\t----------------------------------------------------------\n\n";
    cout<<"\tTotal Bill       : \t\t\t\t"<<total<<endl<<endl;
    cout<<"\tBill Generate By : \t\t\t"<<empnamee<<endl<<endl;
    time_t tt;
    struct tm*ti;
    time(&tt);
    ti=localtime(&tt);
    cout<<endl<<endl<<"\t\t\t\t\t"<<asctime(ti)<<endl;
    cout<<"\t----------------------------------------------------------\n\n";
    Sleep(15000);

}
void employee::employeelogin(){
    string tname;
string tpass;
cout<<"\t\t\t\t-----------------------------------------"<<endl;
cout<<"\t\t\t\t\tEnter Employee`s Login Info"<<endl;
cout<<"\t\t\t\t-----------------------------------------\n\n\n\n"<<endl;
cout<<"Enter your Username\t:";
cin>>tname;
int i=1;
n:
cout<<"Enter your password\t:";
cin>>tpass;
fstream in;
in.open(tname.c_str(),ios::in);
if(!in){
    cout<<"\n\n\n\t\t\t\tSorry No username found "<<endl;
    loading();
    in.close();
}
else{
    in>>empname>>empusername>>emppass;
    if(tpass==emppass){
            empnamee=empname;
            loading();
        cout<<"\t\t\t\t-----------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\tHEY "<<empname<<" WELCOME "<<endl;
        cout<<"\t\t\t\t-----------------------------------------------"<<endl;
        int choice;
        menu();
    }
    else{
        i++;
        if(i<=3){
            cout<<"\n\nWrong password,Enter your password again"<<endl;
            goto n;
        }
    }

}
        in.close();
}
void admin::List(){
    int tcode;
    string tname;
    int tprice;
    int tqty;
    string tpain;
    int size;
fstream data;
data.open("database.txt",ios::in);
system("cls");
cout<<"\t\t\t\t------------------------------------------\n";
cout<<"\t\t\t\t\t\tLIST\n"<<endl;
cout<<"\t\t\t\t------------------------------------------\n\n\n\n\n";
cout<<"\t1.Item_code\t2.Item name\t\t3.Item price\t4.Item qty\n"<<endl;
data>>tcode>>tname>>tprice>>tqty;
    setdata(tname,tcode,tprice,tqty);
while(!data.eof()){
    size=tname.size();
    if(size<=7){
    cout<<"\t"<<getcode()<<"\t\t"<<getname()<<"\t\t\t"<<getprice()<<"\t\t"<<getqty()<<endl;
    }
    else
    cout<<"\t"<<getcode()<<"\t\t"<<getname()<<"\t\t"<<getprice()<<"\t\t"<<getqty()<<endl;

    data>>tcode>>tname>>tprice>>tqty;
    setdata(tname,tcode,tprice,tqty);
}
data.close();

}
void admin::wholesell(){
     int tcode;
    string tname;
    int tprice;
    int tqty;
    int totall;
    string n;
    int size;
    int grandtotal=0;
fstream data;
data.open("overallsell.txt",ios::in);
system("cls");
cout<<"\t\t\t\t------------------------------------------\n";
cout<<"\t\t\t\t\t\tOVERALL SELL\n"<<endl;
cout<<"\t\t\t\t------------------------------------------\n\n\n\n\n";
cout<<"\t1.Item_code\t2.Item name\t\t3.Item price\t4.med qty\t5.Total\n"<<endl;
data>>tcode>>tname>>tprice>>tqty>>totall;
while(!data.eof()){
    grandtotal+=totall;
    size=tname.size();
    if(size<=7){
    cout<<"\t"<<tcode<<"\t\t"<<tname<<"\t\t\t"<<tprice<<"\t\t"<<tqty<<"\t\t"<<totall<<endl;
    }
    else
    cout<<"\t"<<tcode<<"\t\t"<<tname<<"\t\t"<<tprice<<"\t\t"<<tqty<<"\t\t"<<totall<<endl;

    data>>tcode>>tname>>tprice>>tqty>>totall;
}
cout<<"\n\n\t----------------------------------------------------------------------\n\n";
cout<<"\tGrand Total \t:\t\t\t\t\t\t\t"<<grandtotal;
cout<<"\n\n\nPress Any Key To Cntinue \t:";
cin>>n;
system("cls");
data.close();

}
void admin::del_item()
{

	int tcode;
    string tname;
    int tprice;
    int tqty;
    fstream data,data1;
    int mkey;
    int token=0;
    cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\t\t\t\t\t\tDelete Item"<<endl;
     cout<<"\t\t\t\t-----------------------------------------"<<endl;
    cout<<"\n\n\nItem code\t:";
    cin>>mkey;
    data.open("database.txt" , ios::in);
    if(!data){
        cout<<"\nFile does not exixst";
        data.close();
    }
    else{
        data1.open("database1.txt" , ios::app|ios::out);
        data>>tcode>>tname>>tprice>>tqty;
        setdata(tname,tcode,tprice,tqty);

        while(!data.eof()){
            if(getcode()==mkey){
                cout<<"\n\n\t\t\t\tItem Deleted Succesfully";
                loading();
                token++;
                  }
        else{
            data1<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<getqty()<<"\n";
        }

        data>>tcode>>tname>>tprice>>tqty;
        setdata(tname,tcode,tprice,tqty);
    }
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt" , "database.txt");

    if(token==0){
        cout<<"\n\n\n\t\t\t\tItem Not Found Try again";
        loading();
        
    }
}
void item :: setdata(string a , int b , int c , int d)
{
	name  = a;
	code  = b;
	price = c;
	qty   = d;
}

string item::getname()
{
	return name;
}
int item::getprice()
{
	return price;
}
int item::getqty()
{
	return  qty;
}
int item::getcode()
{
	return code;
}
void admin::edit_item()
{
	fstream data,data1;
    int mkey;
    int token=0;
    int c;
    int p;
    string n;
    int qt;
    int tcode;
    string tname;
    int tprice;
    int tqty;
     cout<<"\n\n\n\n"<<endl;
    cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\t\t\t\t\t\tModify Item"<<endl;
     cout<<"\t\t\t\t-----------------------------------------\n\n\n\n"<<endl;
    cout<<"Enter Item code To modify  :";
    cin>>mkey;

    data.open("database.txt",ios::in);
    if(!data){
    cout<<"file doesn`t Exist"<<endl;
    }
    else{
        data>>tcode>>tname>>tprice>>tqty;
    setdata(tname,tcode,tprice,tqty);
    data1.open("database1.txt",ios::app|ios::out);

    while(!data.eof()){
        if(mkey==getcode()){
        cout<<"enter new code\t:";
        cin>>c;
        cout<<"product name\t:";
        cin>>n;
        cout<<"product price\t:";
        cin>>p;
        cout<<"Enter Quantity\t:";
        cin>>qt;
            
        data1<<" "<<c<<" "<<n<<" "<<p<<" "<<qt<<"\n";
        cout<<"\n\n\t\t\t\t\trecord  Has been edited "<<endl;
            loading();
        token++;
        system("cls");
           }
           else{
        data1<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<getqty()<<"\n";
               }
        data>>tcode>>tname>>tprice>>tqty;
        setdata(tname,tcode,tprice,tqty);
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0){
        cout<<"\n\n\nRecord not found sorry"<<endl;
        loading();
        getch();
        system("cls");
    }
    }

}

void admin::adminslogin(){
    string tpass;
    string tusername;
    int token;
cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\t\t\t\tEnter here your logins details please "<<endl;
     cout<<"\t\t\t\t-----------------------------------------\n\n\n\n"<<endl;
cout<<"Enter your username\t:";
cin>>tusername;
cout<<"Enter your password\t:";
cin>>tpass;
fstream adminss("adminsdata.bin",ios::in|ios::binary);
if(!adminss){
    cout<<"No opening failed"<<endl;
}
else{
    adminss>>name>>username>>password;
    while(!adminss.eof()){
        if((username==tusername)&&(password==tpass)){
                loading();
                cout<<"\n\n\t\t\t\t\tHEY "<<name <<" WELCOME TO YOUR CAFETERIA \n"<<endl;
            menu();
            token=0;
            break;
        }
        else{
            token++;
        }
        adminss>>name>>username>>password;
    }
    adminss.close();

}
if(token!=0){
    cout<<"You have entered wrong details\nTry Againnn.... " <<endl;
    Sleep(1000);
    getch();
}
}

void admin::add_item() 
{
	
  m:
   fstream data;
   int c;
   int token=0;
   int p;
   string n;
   int qt;
   string pain;
   int tcode;
    string tname;
    int tqty;
    int tprice;
   cout<<"\n\n\n\n"<<endl;
   cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\t\t\t\t\t\tAdd new Item"<<endl;
   cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\nproduct code\t:";
   cin>>tcode;
   cout<<"\nproduct name\t:";
   cin>>tname;
   cout<<"\nproduct price\t:";
   cin>>tprice;
   cout<<"\nEnter stock of Item\t:";
   cin>>tqty;
   cout<<"\n\n";
    setdata(tname,tcode,tprice,tqty);

    data.open("database.txt",ios::in);
    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<getqty()<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>qt;
        while(!data.eof())
        {

            if(c==getcode()){
                token++;
            }
            data>>c>>n>>p>>qt;

        }
        data.close();

    if(token==1){
        cout<<"This product was already add"<<endl;
        getch();
        system("cls");
        goto m;
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<getcode()<<" "<<getname()<<" "<<getprice()<<" "<<getqty()<<"\n";
        data.close();
    }
    }
    cout<<"Record Inserted"<<endl;
     loading();
}
void admin::addemployee(){
cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\t\t\t\t\t\tADD NEW EMPLOYEE DETAILS "<<endl;
     cout<<"\t\t\t\t-----------------------------------------\n\n\n\n"<<endl;
     a:
fflush(stdin);
cout<<"\nEnter the Name of the Employee\t:";
getline(cin,empname);
fflush(stdin);
cout<<"\nEnter the username of the Employee\t";
cin>>empusername;
fflush(stdin);
cout<<"\nEnter the password of the employee\t";
cin>>emppass;
fflush(stdin);
fstream employee(empusername.c_str(),ios::in);
if(!employee){
    fstream employee(empusername.c_str(),ios::app|ios::out);
    employee<<" "<<empname<<" "<<empusername<<" "<<emppass<<"\n";
    employee.close();
    cout<<"\n\n\n\t\t\t\tEmployee has been edited successfully!!"<<endl;
    loading();
}
else{
    cout<<"\n\n\nSorry This username has already taken"<<endl;
    cout<<"\nEnter Details again"<<endl;
    goto a;
}
}
void admin::deleteemployee(){
string tname;
cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\t\t\t\t\t\tDeleting Employee"<<endl;
     cout<<"\t\t\t\t-----------------------------------------\n\n\n\n"<<endl;
cout<<"Enter the username of the employee you want to delete\t:"<<endl;
cin>>tname;
if(remove(tname.c_str())!=0){
     cout<<"\nfile  not deleted";
}
else{
        cout<<"\n\n\n\t\t\t\tEmployee Deleted Successuly!!";
        loading();

}


}
void admin::setadmin(){
    cout<<"\t\t\t\t-----------------------------------------"<<endl;
   cout<<"\t\t\t\t\t\tEnter New Admin`s Info"<<endl;
     cout<<"\t\t\t\t-----------------------------------------\n\n\n\n"<<endl;
        cout<<"Enter admin`s name\t:"<<endl;
        cin>>name;
        cout<<"Enter admin`s username\t:"<<endl;
        cin>>username;
        cout<<"Enter admin`s password\t:"<<endl;
        cin>>password;
        fstream adminn("adminsdata.bin",ios::out|ios::app|ios::binary);
        if(!adminn){
            cout<<"file not created"<<endl;
        }
        else{
            adminn<<" "<<name<<" "<<username<<" "<<password<<" "<<endl;
            cout<<"\n\n\n\t\t\t\t\tNew admin created";
            loading();
        }
}
void admin :: menu()
{

int choice ;
    m:

    cout<<"\n\n1-Add medicine \n\n2-Modify \n\n3-Delete\n\n4-Add Employee\n\n5-Delete Employee\n\n6-Add admin\n\n7-Overall sale\n\n8-Back in the main menu\n\n";
    cout<<"ENTER YOUR CHOICE:\t";
    cin>>choice;
    system("cls");
    switch(choice){
case 1:
    add_item();
    break;
case 2:
    edit_item();
    break;
case 3:
    del_item();
    goto m;
case 4:
    addemployee();
    goto m;
case 5:
    deleteemployee();
    goto m;
case 6:
    setadmin();
    goto m;
case 7:
    wholesell();
    goto m;
case 8:
    break;
default:
    cout<<"invalid choice"<<endl;
    goto m;
}
}
void admin :: welcome()
{
	
	system("cls");
	int option;
	char c=219;
	time_t t;
	time(&t);
	cout << "\n\t\t\t\t\t\t " << ctime(&t);
	int i;
	gotoxy(24,5);
	for(i=1;i<=42;i++)
	{
		cout << c;
	}
	gotoxy(24,6);
	cout << c << c << "      WELCOME TO FAST CAFETERIA    "   <<"\t"<<c<<c;
	gotoxy(24,7);
	for(i=1;i<=42;i++)
	{
		cout << c;
	}
	loading(10000000);
	cout << endl;
	gotoxy(24,18);
	cout<<"Press Enter to Continue";
	getch();
	system("cls");
}
//int main()
//{
//	admin a;
//	a.add_item();
//	a.del_item();
//	a.edit_item();
////item i ;
//i.add_item();
//i.edit_item();
//i.del_item();
//}
int main(){
system("color 74");
admin x;
admin p;
x.welcome();
admin missfarah("missfarah" , "missfarah@cafe" , "missfarah");
admin seher("seher","seher@cafe","seher");
admin huzaifa("huzaifa","huzaifa@cafe","huzaifa");
employee e;
int choice;
m:
system("cls");
cout<<"\n\t\t\t\t-----------------------------------------------\n\n";
cout<<"\t\t\t\t\tWELCOME TO FAST NUCES CAFETERIA\n\n";
cout<<"\n\t\t\t\t-----------------------------------------------\n\n";
cout<<"\n\n"<<"\t\t\t\t1-ADMIN\n\t\t\t\t2-EMPLOYEE\n\t\t\t\t3-EXIT  ";
cout<<"\n\t\t\t\tENTER YOUR CHOICE  :";
cin>>choice;

switch(choice){
case 1:
    system("cls");
    missfarah.adminslogin();
 goto m;
 break;
case 2:
    system("cls");
    e.employeelogin();
    goto m;
case 3:
    exit(0);
default:
    goto m;
}
}

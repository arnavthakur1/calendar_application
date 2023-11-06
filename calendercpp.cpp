#include <iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
bool isleapyr(int &y) //to find the entered year is a leap year or not.
{
    bool flag;
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)
            {
              flag=true;
            }
            else
            {
                flag=false;
            }
        }
        else
        {
            flag=true;
        }
    }
    else
    {
        flag=false;
    }
    return flag;
}

int yrs(int l) //to get extra day because of leap year.
{
    l-=1; 
int leapyrs=l/4-l/100+l/400;
int extra = (l-leapyrs)+leapyrs*2;
return (extra%7);
}

int months(int &m,int &l) 
{
int extra;
if(isleapyr(l))
{
    int temp[]={-1,0,3,4,0,2,5,0,3,6,1,4,6,2};
    extra=temp[m];
}
else
{
    int temp[]={-1,0,3,3,6,1,4,6,2,5,0,3,5,1};
    extra=temp[m];
}
return extra;
}

int days(int &n) 
{
int extra=(n%7);
return extra;
}

int extra(int p, int &q , int &r)
{
    int extra=yrs(r)+months(q,r)+days(p);
    extra=extra%7;
    return extra;
}

int output(int &p, int &q , int &r) //to get the day that falls on the entered  date.
{
    cout<<endl;
    switch(extra(p,q,r))
    {
        case 0:cout<<"'Sunday'"<<endl;
        break;
        case 1:cout<<"'Monday'"<<endl;
        break;
        case 2:cout<<"'Tuesday'"<<endl;
        break;
        case 3:cout<<"'Wednesday'"<<endl;
        break;
        case 4:cout<<"'Thursday'"<<endl;
        break;
        case 5:cout<<"'Friday'"<<endl;
        break;
        case 6:cout<<"'Saturday'"<<endl;
        break;
        default:cout<<"'NULL'"<<endl;
        break;
    }
    cout<<endl;
    system("pause");
}

void calendar( int &a , int &c) //function to print calendar of the enterd month ny the user.
{
    int q;
    cout<<endl;
    cout<<"\t";
    switch(a)
    {
        case 1:cout<<"January, "<<c<<endl;
            break;
        case 2:cout<<"Feburary, "<<c<<endl;
            break;
        case 3:cout<<"March, "<<c<<endl;
            break;
        case 4:cout<<"April, "<<c<<endl;
            break;
        case 5:cout<<"May, "<<c<<endl;
            break;
        case 6:cout<<"June, "<<c<<endl;
            break;
        case 7:cout<<"July, "<<c<<endl;
            break;
        case 8:cout<<"August, "<<c<<endl;
            break;
        case 9:cout<<"September, "<<c<<endl;
            break;
        case 10:cout<<"October, "<<c<<endl;
            break;
        case 11:cout<<"November, "<<c<<endl;
            break;
        case 12:cout<<"December, "<<c<<endl;
            break;
        default:cout<<"'NULL'"<<c<<endl;
            break;
    }
    cout<<" Sun Mon Tue Wed Thu Fri Sat"<<endl;
    int temp;
    switch(extra(1,a,c))
    {
        case 0:cout<<"  1";temp=6;
            break;
        case 1:cout<<"      1";temp=5;
            break;
        case 2:cout<<"          1";temp=4;
            break;
        case 3:cout<<"              1";temp=3;
            break;
        case 4:cout<<"                  1";temp=2;
            break;
        case 5:cout<<"                      1";temp=1;
            break;
        case 6:cout<<"                          1";temp=0;
            break;
        default:cout<<"NULL";
            break;
    }
    if(a==2 && isleapyr(c)==true)
    {
        q=29;
    }
    else if(a==2 && isleapyr(c)==false)
    {
        q=28;
    }
    else
    {
        if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
            q=31;
        else
            q=30;
    }
    for(int i=2;i<=q;i++,temp--)
    {
        if(temp==0)
        {
            if(i<10)
                cout<<endl<<"  "<<i;
            else
                cout<<endl<<" "<<i;
            temp=7;
        }
        else
        {
            if(i<10)
                cout<<"   "<<i;
            else
                cout<<"  "<<i;
        }
    }
    cout<<endl<<endl;
    system("pause");

}
void events(int &a,int &b,int &c){ //function to add event on the enterd date.
    char event[50];
    cout<<"Enter Event(without spaces)"<<endl;
    cin>>event;
    for(int i=0;i<strlen(event)+11;i++){
        cout<<"-";
    }
    cout<<"\n"<<endl;
    cout<<a<<"-"<<b<<"-"<<c<<"->"<<event<<endl;
    for(int i=0;i<strlen(event)+11;i++){
        cout<<"-";
    }
    cout<<"\n"<<endl;
}

int main() 
{
    int x;
    do {
        system("cls");
        cout <<endl<<"1. Find the day of Month of any Year"<< endl;
        cout <<"2. Print the calender of a Month of any Year"<< endl;
        cout <<"3. Enter Events"<<endl;
        cout <<"4. Exit the program"<<endl;
        cout<<"Enter Your Option - ";
        cin>>x;
        if(x==1)
        {
            int a, b, c;
            do {
                char day[3], month[3], year[5];
                cout << "Now Enter the date in the Format 'Date/Month/Year'" << endl;
                cin.get(day, 4, '/');//ignores the / sign enterd by the user.
                cin.ignore(100, '/');
                cin.get(month, 4, '/');
                cin.ignore(100, '/');
                cin.get(year, 5);
                a = atoi(day);//to convert into int data type.
                b = atoi(month);
                c = atoi(year);
            }while(a>31 || a<1 || b>12 || b<1 && cout<<endl<<"Enter a valid date");
            output(a,b,c);
        }
        else if(x==2)
        {
            int b, c;
            do {
                char day[3], month[3], year[5];
                cout << "Now Enter the date in the Format 'Month/Year'" << endl;
                cin.get(month, 4, '/');
                cin.ignore(100, '/');
                cin.get(year, 5);
                b = atoi(month);
                c = atoi(year);
            } while(b>12 || b<1 && cout<<endl<<"Try Again with Better Values");
            calendar(b,c);
        }
        else if(x==3){
            int n;
            cout<<"How many events you want to enter"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                int a, b, c;
            do {
                char day[3], month[3], year[5];
                cout << "Now Enter the date in the Following Format 'Date/Month/Year'" << endl;
                cin.get(day, 4, '/');
                cin.ignore(100, '/');
                cin.get(month, 4, '/');
                cin.ignore(100, '/');
                cin.get(year, 5);
                a = atoi(day);
                b = atoi(month);
                c = atoi(year);
            }while(a>31 || a<1 || b>12 || b<1 && cout<<endl<<"Please enter a valid date");
            events(a,b,c);
            }
        }
        else if(x==4)
        {
            exit(0);
        }
        else
        {
            cout<<"Enter a valid input"<<endl;
        }
    }while(x!=3);
    system("pause");
    return 0;
//NOTE->Not all the header files have been used in the program.
}
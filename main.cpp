#include <iostream>
#include <windows.h>
#include<conio.h>
#include<stdio.h>
#define extended -32
#define upArrow 72
#define downArrow 80
#define homeKey 71
#define endKey 79
#define tap 9
#define enter 13
using namespace std;
void Display();
void Display2();
void gotoxy(int,int);
int main()
{
    char myarray[3][10]={{"NEW"},{"DISPLAY"},{"EXIT"}};     //array of strings to define Menu items
    int X=28;                                           // center console screen set cursor
    int Y=4;
    int flag=0;
    int flag2=0;                                        // flag check which string of menu will be colored
    int checkcurrent=0;
    int z=checkcurrent;                    // save current postioned colored
    char key;
    Display();
    //draw menu and for first time color first item of menu
    for(int i=0;i<3;i++){
        gotoxy(X,Y++);
        if(flag++==checkcurrent)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x41);
        cout<<myarray[i]<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
        }
    key=getch();
    cout<<(int)key;
    if(key==extended){
        key=getch();
    }
    do{
        X=28;
        Y=4;
        switch((int)key){
            case tap:
            case downArrow:
                checkcurrent++;
                if(checkcurrent>2)
                    checkcurrent=0;
                system("CLS");
                Display();
                flag=0;
                for(int i=0;i<3;i++){
                        gotoxy(X,Y++);
                        if(flag++==checkcurrent)
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x41);
                        cout<<myarray[i]<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
                     }
                break;
            case upArrow:
             checkcurrent--;
             if(checkcurrent<0)
                checkcurrent=2;
              system("CLS");
              Display();
              flag=0;
              for(int i=0;i<3;i++){
                gotoxy(X,Y++);
                if(flag++==checkcurrent)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x41);
                cout<<myarray[i]<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
                     }
        break;
        case homeKey:
            checkcurrent=0;
            flag=0;
            system("CLS");
            Display();
            for(int i=0;i<3;i++){
            gotoxy(X,Y++);
            if(flag++==checkcurrent)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x41);
            cout<<myarray[i]<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
             break;
         case endKey:
            checkcurrent=2;
            flag=0;
            system("CLS");
            Display();
            for(int i=0;i<3;i++){
                gotoxy(X,Y++);
                if(flag++==checkcurrent)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x41);
                cout<<myarray[i]<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
            break;
         case enter:
            system("CLS");
            Display2();
            gotoxy(X,Y);
            switch(checkcurrent){
                case 0:
                    cout<<"U Entered TO New section \n press Menu Keys to Back to Menu"<<endl;
                    break;
                case 1:
                    cout<<"U Entered TO Display section \n press any Key to Back to Menu"<<endl;
                    break;
                case 2:
                    cout<<"Thank YOU :)"<<endl;
                    flag2=1;
                    key=27;
                    break;
                default :
            cout<<"press menu key only"<<endl<<"press menu Key to go back to menu"<<endl;
                }
            break;
       default :
        cout <<"CHoose from a valid key"<<endl;
    }
    if(flag2==0){
    key=getch();
    if(key==extended)
        key=getch();
    }
      }
        while(key !=27 );
        return 0;
    }
void Display(){
cout<<"use UP arrow , Down arrow , HOME key ,END key , tab key to navigate\n use ENTER key to select  "<<endl;
}
void Display2(){
cout<<"use UP arrow , Down arrow , HOME key ,END key , tab key to Return\n "<<endl;
}
    //gotoxy Implementation function that set cursor in certain postion
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



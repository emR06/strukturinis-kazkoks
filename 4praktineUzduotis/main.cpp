#include <fstream>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;
struct menuItemType{
    string menuItem="";
    double menuPrice;
};

struct selectedMenuItem{
    string menuItem;
    double price;
    int amnt;
};

void getData(menuItemType menuList[],int& n);
void showMenu(menuItemType menuList[],int n);
void ordering(menuItemType menuList[],selectedMenuItem orderList[],int n,int& x);
void printCheck(selectedMenuItem orderList[],int x);
void copyCheck(selectedMenuItem orderList[],int& x);
void cleanOrder(selectedMenuItem orderList[],int& x,int m);

int main ()
{
    const int items=50;
    int n,x;
    menuItemType menuList[items];
    selectedMenuItem orderList[items];

    getData(menuList,n);
    showMenu(menuList,n);
    ordering(menuList,orderList,n,x);
    copyCheck(orderList,x);
    printCheck(orderList,x);
return 0;
}

void getData(menuItemType menuList[],int& n)
{
    char c[256];
    int o;
    ifstream fd("menu.txt");
    n=0;
    while(!fd.eof())
    {
        fd.getline(c,256);
        o=fd.gcount();
        for(int i=0; i<o; i++)
        {
            if(!isdigit(c[i]))
            {
                menuList[n].menuItem+=c[i];
                c[i]=' ';
            }
            else
            {
                menuList[n].menuPrice=atof(c);
                break;
            }
        }
        n++;
    }
    fd.close();
}

void showMenu(menuItemType menuList[],int n)
{
    cout<<"Sveiki atvyke i restorana ''restoranas''"<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". "<<left<<setw(40)<<menuList[i].menuItem<<menuList[i].menuPrice<<endl;
    }
    cout<<"---------------------------------------"<<endl;
}

void ordering(menuItemType menuList[],selectedMenuItem orderList[],int n,int& x)
{
    int order;
    x=0;
    cout<<"Norint uzsisakyti, prasome irasyti saraso numeri. Baigus uzsisakyti, irasykite 0."<<endl;
    cin>>order;
    while(order!=0){
        if(order>n)
        {
            while(order>n)
            {
                cout<<"Patiekalas nerastas. Prasome bandyti dar karta. ";
                cin>>order;
            }
        }
        orderList[x].menuItem=menuList[order-1].menuItem;

        cout<<"Prasome irasyti kieki. ";
        cin>>orderList[x].amnt;
        if(orderList[x].amnt==0)
        {
            cout<<"Kiekis negali buti 0. Prasome irasyti kita kieki. ";
            cin>>orderList[x].amnt;
        }
        orderList[x].price=menuList[order-1].menuPrice;
        x++;
        cout<<"Uzsakymas apdorotas."<<endl<<endl<<"Prasome irasyti saraso numeri. Baigus uzsisakyti, irasykite 0. ";
        cin>>order;
    }
    cout<<endl<<"Aciu. Jusu uzsakymas apdorotas. Rasite isspausdinta saskaita kataloge.";
}

void copyCheck(selectedMenuItem orderList[],int& x)
{
    for(int i=0; i<x-1; i++)
    {
        for(int j=i+1; j<x; j++)
        {
            if(orderList[i].menuItem==orderList[j].menuItem)
            {
                orderList[i].amnt+=orderList[j].amnt;
                cleanOrder(orderList,x,j);
                j--;
            }
        }
    }
}

void cleanOrder(selectedMenuItem orderList[],int& x,int m)
{
    for(int i=m; i<x-1; i++)
    {
        orderList[i].menuItem=orderList[i+1].menuItem;
        orderList[i].amnt=orderList[i+1].amnt;
        orderList[i].price=orderList[i+1].price;
    }
    orderList[x].menuItem="";
    orderList[x].amnt=0;
    orderList[x].price=0;
    x--;
}

void printCheck(selectedMenuItem orderList[],int x)
{
    double galSum=0,mok;
    ofstream fr("receipt.txt");
    fr<<"Sveiki atvykę į restoraną ''restoranas''"<<endl<<endl;
    for(int i=0; i<x; i++)
    {
        fr<<left<<setw(4)<<orderList[i].amnt<<setw(40)<<orderList[i].menuItem<<orderList[i].price<<endl;
        galSum+=orderList[i].amnt*orderList[i].price;
    }
    mok=galSum*0.21;
    fr<<endl<<setw(45)<<"Mokesčiai (21%)"<<fixed<<setprecision(2)<<mok<<endl;
    fr<<setw(45)<<"Galutinė suma"<<fixed<<setprecision(2)<<mok+galSum;
}

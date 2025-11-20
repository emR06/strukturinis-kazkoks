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

int main ()
{
    const int items=50;
    int n,x;
    menuItemType menuList[items];
    selectedMenuItem orderList[items];

    getData(menuList,n);
    showMenu(menuList,n);
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
        orderList[x].menuItem=menuList[order-1].menuItem;
        cout<<"Prasome irasyti kieki."
        cin>>orderList[x].amnt; //gotta find a way to check if theres duplicate orders and combine them after...
        orderList[x].price=menuList[order-1].menuPrice*orderList[x].amnt;
        x++;
        cin>>order;
    }
    cout<<endl<<"Aciu. Jusu uzsakymas apdorotas. Rasite isspausdina saskaita kataloge.";
}

void printCheck()
{

}

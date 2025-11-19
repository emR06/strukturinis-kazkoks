#include <fstream>
#include <iomanip>
#include <iostream>
#include <cctype>
using namespace std;
struct menuItemType
{
    string menuItem="";
    double menuPrice;
};

void getData(menuItemType menuList[],int& n);
void showMenu(menuItemType menuList[],int n);

int main ()
{
    const int items=50;
    int n;
    menuItemType menuList[items];
    getData(menuList,n);
    showMenu(menuList,n);
return 0;
}

void getData(menuItemType menuList[],int& n)
{
    int c;
    ifstream fd("menu.txt");
    n=0;
    while(!fd.eof())
    {

    }
    fd.close();
}

void showMenu(menuItemType menuList[],int n)
{
    cout<<"Sveiki atvyke i restorana ''restoranas''"<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<menuList[i].menuItem<<" "<<menuList[i].menuPrice<<endl;
    }
}

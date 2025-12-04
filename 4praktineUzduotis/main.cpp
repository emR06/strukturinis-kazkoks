#include <fstream>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;
struct menuItemType{     //
    string menuItem="";  // struktura, skirta meniu issaugoti
    double menuPrice;    //
};

struct selectedMenuItem{ //
    string menuItem;     // struktura, skirta uzsakymui issaugoti
    double price;        //
    int amnt;            //
};

void getData(menuItemType menuList[],int& n);                                        //
void showMenu(menuItemType menuList[],int n);                                        //
void ordering(menuItemType menuList[],selectedMenuItem orderList[],int n,int& x);    // funkciju prototipai
void printCheck(selectedMenuItem orderList[],int x);                                 //
void copyCheck(selectedMenuItem orderList[],int& x);                                 //
void cleanOrder(selectedMenuItem orderList[],int& x,int m);                          //

int main ()
{
    const int items=50; //kiek max galima tureti sarase patiekalu
    int n,x; // n - kiek sarase yra patiekalu, x - kiek patiekalu uzsakyme
    menuItemType menuList[items];       //
    selectedMenuItem orderList[items];  //masyvu apreiskimas. menuList - meniu, orderList - uzsakymas

    getData(menuList,n);                //
    showMenu(menuList,n);               //
    ordering(menuList,orderList,n,x);   // funkciju iskvietimai
    copyCheck(orderList,x);             //
    printCheck(orderList,x);            //
return 0;
}

void getData(menuItemType menuList[],int& n) //si funkcija gauna duomenis is menu failo
{
    char c[256];
    int o;
    ifstream fd("menu.txt"); //atidaromas failas
    n=0;
    while(!fd.eof())
    {
        fd.getline(c,256); //gauname eilute
        o=fd.gcount(); //gauname eilutes ilgi
        for(int i=0; i<o; i++)                      //
        {                                           //
            if(!isdigit(c[i]))                      // tikriname kiekviena eilutes simboli,
            {                                       // ar jis ne skaicius.
                menuList[n].menuItem+=c[i];         // jei true: raide pridedame prie menuItem string'o,
                c[i]=' ';                           // jei false: konvertuojame likusius simbolius i skaiciu,
            }                                       // ir idedame i menuPrice. ciklas uzbaigiamas su break
            else                                    //
            {                                       //
                menuList[n].menuPrice=atof(c);      //
                break;                              //
            }                                       //
        }
        n++; //suskaiciuojame, kiek patiekalu yra
    }
    fd.close(); //uzdaromas failas
}

void showMenu(menuItemType menuList[],int n) //funkcija skirta menu parodymui
{
    cout<<"Sveiki atvyke i restorana ''restoranas''"<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". "<<left<<setw(40)<<menuList[i].menuItem<<menuList[i].menuPrice<<endl; //savaime suprantama, isspausdiname sunumeruota sarasa
    }
    cout<<"---------------------------------------"<<endl;
}

void ordering(menuItemType menuList[],selectedMenuItem orderList[],int n,int& x) //uzsakymo funkcija
{
    int order; //vartotojo pasirinktas saraso numeris
    x=0; //kiek uzsisake vartotojas
    cout<<"Norint uzsisakyti, prasome irasyti saraso numeri. Baigus uzsisakyti, irasykite 0."<<endl;
    cin>>order;
    while(order!=0){ //nuskaite numeri, ciklas kartosis kol vartotojas neirasys 0
        if(order>n || order<0)  //tikrina, ar irasytas numeris priklauso sarasui; jei ne, jis prades while cikla
        {
            while(order>n || order<0) //kartosis, kol irasytas numeris nepriklauso sarasui
            {
                cout<<"Patiekalas nerastas. Prasome bandyti dar karta. ";
                cin>>order;
            }
        }
        orderList[x].menuItem=menuList[order-1].menuItem; //gavus saraso numeri, mes irasome patiekalo varda i orderList masyva

        cout<<"Prasome irasyti kieki. ";
        cin>>orderList[x].amnt; //gauname patiekalo porcijos kieki
        if(orderList[x].amnt<=0) //kaip ir pries tai, tikriname, ar irasytas kiekis nera maziau arba lygu 0.
        {
            while(orderList[x].amnt<=0){ //jei taip, sis ciklas kartosis, kol vartotojas irasys skaiciu didesni nei 0
                cout<<"Kiekis negali maziau arba lygu 0. Prasome irasyti kita kieki. ";
                cin>>orderList[x].amnt;
            }
        }
        orderList[x].price=menuList[order-1].menuPrice; //irasome patiekalo kaina i orderList masyva
        x++; //suskaiciuojame, kiek vartotojas uzsisake patiekalu
        cout<<"Uzsakymas apdorotas."<<endl<<endl<<"Prasome irasyti saraso numeri. Baigus uzsisakyti, irasykite 0. ";
        cin>>order; //ir vel kartojame cikla..!!
    }
    cout<<endl<<"Aciu. Jusu uzsakymas apdorotas. Rasite isspausdinta saskaita kataloge.";
}

void copyCheck(selectedMenuItem orderList[],int& x) //si funkcija skirta tam, kad "sutrauktu" duplikatus
{
    for(int i=0; i<x-1; i++)     //
    {                            // ciklas cikle tam, kad mes galetume visus elementus palyginti su visais kitais elementais
        for(int j=i+1; j<x; j++) //
        {
            if(orderList[i].menuItem==orderList[j].menuItem) //tikriname, ar patiekalo vardas tas pats
            {                                                //
                orderList[i].amnt+=orderList[j].amnt;        // jei taip, sudedame kiekius,
                cleanOrder(orderList,x,j);                   // ir iskvieciame cleanOrder funkcija.
                j--;                                         // sumaziname j, kad kartotusi antras ciklas dar karta
            }
        }
    }
}

void cleanOrder(selectedMenuItem orderList[],int& x,int m) //funkcija, skirta copyCheck funkcijai; ji "istrina" masyvo eilute ir patraukia kitus
{
    for(int i=m; i<x-1; i++) //pradedame nuo tos eilutes pozicijos, kuria reikia istrinti
    {
        orderList[i].menuItem=orderList[i+1].menuItem; //
        orderList[i].amnt=orderList[i+1].amnt;         // patraukiame eilutes i ankstesnes pozicijas
        orderList[i].price=orderList[i+1].price;       //
    }
    orderList[x].menuItem=""; //
    orderList[x].amnt=0;      // "nunuliname" paskutini elementa
    orderList[x].price=0;     //
    x--; //galiausiai, sumaziname vartotojo uzsakytu patiekalu skaiciu
}

void printCheck(selectedMenuItem orderList[],int x) //funkcija skirta spausdinimui
{
    double galSum=0,mok; //galSum - galutine suma visu patiekalu, mok - apskaiciuota PVM dalis
    ofstream fr("receipt.txt"); //atidarome faila
    fr<<"Sveiki atvykę į restoraną ''restoranas''"<<endl<<endl;
    for(int i=0; i<x; i++)
    {
        fr<<left<<setw(4)<<orderList[i].amnt<<setw(40)<<orderList[i].menuItem<<orderList[i].price<<endl; //spausdiname kieki,
        galSum+=orderList[i].amnt*orderList[i].price;                                                    //patiekala, vieneto kaina ir apskaiciuojame
    }                                                                                                    //suma
    mok=galSum*0.21; //apskaiciuojame mokescio dali
    fr<<endl<<setw(45)<<"Mokesčiai (21%)"<<fixed<<setprecision(2)<<mok<<endl; //isspausdiname PVM,
    fr<<setw(45)<<"Galutinė suma"<<fixed<<setprecision(2)<<mok+galSum;        //ir galutine suma
    fr.close(); //uzdarome faila
}

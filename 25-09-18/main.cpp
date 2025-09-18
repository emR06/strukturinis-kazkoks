#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<"pirma uzduotis"<<endl;
    string vardas,pavarde,grupe,studijuPrograma;
    int kursas,amzius;

    vardas="Vardas";
    pavarde="Pavardenis";
    grupe="PI25";
    studijuPrograma="Programu sistemos";
    kursas=1;
    amzius=19;

    cout<<"STUDENTO INFORMACIJA"<<endl<<"////////////////////////////"<<endl;
    cout<<"VARDAS: "<<vardas<<" "<<pavarde<<endl;
    cout<<"AMZIUS: "<<amzius<<endl;
    cout<<"GRUPE: "<<grupe<<endl;
    cout<<"KURSAS: "<<kursas<<endl;
    cout<<"STUDIJOS PROGRAMOS PAVADINIMAS: "<<studijuPrograma<<endl;

    cout<<endl<<"antra uzduotis"<<endl;
    string pavadinimas,savininkas,arena;
    int metai,vSk;

    pavadinimas="Londono „Arsenal“";
    savininkas="Stan Kroenke";
    arena="„Emirates“ stadionas";
    metai=1886;
    vSk=60432;

    cout<<"FUTBOLO KLUBAS "<<pavadinimas<<endl<<"////////"<<endl;
    cout<<"IKURIMO METAI: "<<metai<<endl;
    cout<<"SAVININKAS: "<<savininkas<<endl;
    cout<<"ARENA: "<<arena<<endl;
    cout<<"TALPA: "<<vSk<<endl;

    cout<<endl<<"trecia uzduotis"<<endl;
    string marke,modelis,spalva;
    int metai2;
    float litrazas;

    marke="OPEL";
    modelis="ZAFIRA";
    metai2=2010;
    litrazas=2;
    spalva="sidabrines";

    cout<<"Automobilis "<<marke<<" "<<modelis<<" yra pagamintas "<<metai2<<" metais. Jo motoras "<<fixed<<setprecision(1)<<litrazas<<" litrazo. Automobilis yra "<<spalva<<" spalvos."<<endl;

    cout<<endl<<"ketvirta uzduotis"<<endl;
    int a=13, b=5;
    float c=17.5;

    cout<<a+b-c<<endl;
    cout<<15/2+c<<endl;
    cout<<a/static_cast<double>(b)+2*c<<endl;
    cout<<14%3+6.3+b/a<<endl;
    cout<<static_cast<int>(c)%5+a-b<<endl;
    cout<<13.5/2+4.0*3.5+18<<endl;

    cout<<endl<<"penkta uzduotis"<<endl;
    int x,y,z,q,w;
    float vid;
    cin>>x>>y>>z>>q>>w;
    vid=x+y+z+q+w;
    vid=vid/float(5);
    cout<<vid<<endl;

    cout<<endl<<"sesta uzduotis"<<endl;
    int dviz,n,m;
    cin>>dviz;
    n=dviz/10;
    m=dviz%10;
    cout<<n+m<<endl;

    return 0;
}
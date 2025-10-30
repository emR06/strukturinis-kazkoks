#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
void bil_suma(const int m);
void atlyg_padid(const int m);

int main ()
{
    int p;
    const int m=100;

    while(p!=3){
        cout<<"Pasirinkite operacija:"<<endl;
        cout<<"1) Bilietu pardavimu sumos skaiciavimas"<<endl;
        cout<<"2) Darbuotoju atlyginimu atnaujinimas"<<endl;
        cout<<"3) Uzbaigti"<<endl;
        cout<<endl;
        cin>>p;
        switch (p){
            case 1:{
                cout<<"Pasirinkote sumos skaiciavima."<<endl;
                cout<<"---------------------------------------"<<endl;
                bil_suma(m);
               break;
            }
            case 2:{
                cout<<"Pasirinkote atlyginimu atnaujinima."<<endl;
                cout<<"---------------------------------------"<<endl;
                atlyg_padid(m);
                break;
            }
            case 3:{
                cout<<"Viso gero.";
                break;
            }
            default:{
                cout<<"error, pabandykite dar karta"<<endl;
                break;
            }
        }
    }
return 0;
}

void bil_suma(const int m)
{
    int Bil[m][2];
    int n=0;
    int kiek=0;
    float sum=0;

    ifstream fd("prices.txt");
    while(!fd.eof()){
        fd>>Bil[n][0];
        fd>>Bil[n][1];
        n++;
    }
    fd.close();

    cout<<"Visa lentele:"<<endl;
    for(int i=0; i<n; i++){
        cout<<Bil[i][0]<<" "<<Bil[i][1]<<endl;
    }
    cout<<"~~~~~~~~~~~~~~"<<endl;

    for(int i=0; i<n; i++){
        kiek+=Bil[i][1];
        sum+=Bil[i][0]*Bil[i][1];
    }
    cout<<"Bilietu kiekis: "<<kiek<<endl;
    cout<<"Bendra pardavimu suma: "<<fixed<<setprecision(2)<<sum<<endl;

    ofstream fr("sumRez.txt");
    fr<<"Bilietu kiekis: "<<kiek<<endl;
    fr<<"Bendra pardavimu suma: "<<fixed<<setprecision(2)<<sum;
    fr.close();

    cout<<endl<<"Rezultatai isspausdinti i faila."<<endl;
    cout<<"Operacija baigta."<<endl;
    cout<<"---------------------------------------"<<endl<<endl;
}

void atlyg_padid(const int m)
{
    string fullN[m][2];
    float duom[m][2], naujAtl;
    int n=0;

    ifstream fd("salary.txt");
    while(!fd.eof())
    {
        fd>>fullN[n][0];
        fd>>fullN[n][1];
        fd>>duom[n][0];
        fd>>duom[n][1];
        n++;
    }
    fd.close();

    cout<<"Visa lentele:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<fullN[i][0]<<" "<<fullN[i][1]<<" "<<duom[i][0]<<" "<<duom[i][1]<<endl;
    }
    cout<<endl;
    cout<<"Su atnaujintais atlyginimais: "<<endl;
    for(int i=0; i<n; i++)
    {
        naujAtl=duom[i][0]+(duom[i][0]*(duom[i][1]/100));
        cout<<fullN[i][0]<<" "<<fullN[i][1]<<" "<<fixed<<setprecision(2)<<naujAtl<<endl;
    }

    ofstream fr("newSalary.txt");
    for(int i=0; i<n; i++)
    {
        naujAtl=duom[i][0]+(duom[i][0]*(duom[i][1]/100));
        fr<<fullN[i][0]<<" "<<fullN[i][1]<<" "<<fixed<<setprecision(2)<<naujAtl<<endl;
    }
    fr.close();

    cout<<endl<<"Rezultatai isspausdinti i faila."<<endl;
    cout<<"Operacija baigta."<<endl;
    cout<<"---------------------------------------"<<endl<<endl;
}

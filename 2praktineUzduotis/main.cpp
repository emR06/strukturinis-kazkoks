#include <iostream>
#include <string>
using namespace std;

void ivedimas(int pazLim, int mokLim, int MokPaz[][10], string Vardai[], int &mk, int &maxPz);
void perziura(int MokPaz[][10], string Vardai[], bool konkret, int &mk,int &maxPz);
void atnaujint(int MokPaz[][10], string Vardai[], int &mk, int &maxPz);
void pasalinti(int MokPaz[][10], string Vardai[], int &mk, int &maxPz);

int main() {
    const int mokLim=100;
    const int pazLim=10;

    string Vardai[mokLim];
    int MokPaz[mokLim][pazLim]={0}, pas;
    int mk=0, maxPz=0;
    bool konkret;
    char p;

    while (pas!=5) {
        cout<<"Prasome pasirinkti operacija."<<endl;
        cout<<"1) Mokiniu ir ju pazymiu ivedimas,"<<endl;
        cout<<"2) Mokiniu ir ju pazymiu perziura,"<<endl;
        cout<<"3) Pazymiu atnaujinimas,"<<endl;
        cout<<"4) Mokiniu pasalinimas is sistemos."<<endl;
        cout<<"5) Uzbaigti."<<endl;
        cout<<endl;
        cin>>pas;

        cout<<"Jus pasirinkote: ";
        switch(pas) {
            case 1: cout<<"mokiniu ir ju pazymiu ivedima."<<endl<<"==========================="<<endl<<endl; ivedimas(pazLim,mokLim,MokPaz,Vardai,mk,maxPz); break;
            case 2: {
                    cout<<"mokiniu ir ju pazymiu perziura."<<endl;
                    cout<<"Ar norite perziureti visa sarasa? y/n"<<endl;
                    cin>>p;
                    if(p=='y'){konkret=false;}
                    else if(p=='n'){konkret=true;}
                    else{cout<<"Prasome ivesti y/n."<<endl; break;}
                    cout<<"==========================="<<endl<<endl;
                    perziura(MokPaz,Vardai,konkret,mk,maxPz);
                    break;
                    }
            case 3: cout<<"pazymiu atnaujinima."<<endl<<"==========================="<<endl<<endl; atnaujint(MokPaz,Vardai,mk,maxPz); break;
            case 4: cout<<"mokiniu pasalinima."<<endl<<"==========================="<<endl<<endl; pasalinti(MokPaz,Vardai,mk,maxPz); break;
            case 5: cout<<"uzbaigima. Viso gero."<<endl<<"==========================="<<endl<<endl; break;
            default: cout<<"Tokios operacijos nera. Prasome bandyti dar karta."<<endl<<endl; break;
        }
    }
    return 0;
}

void ivedimas(int pazLim, int mokLim, int MokPaz[][10], string Vardai[], int &mk, int &maxPz) {
    int n,m;
    cout<<"Prasome ivesti mokiniu kieki: ";
    cin>>n;
    while(mk+n>mokLim) {
        cout<<"Per didelis skaicius. Prasome ivesti skaiciu ne didesni uz "<<mokLim-mk<<"."<<endl;
        cin>>n;
    }

    if(n==0){
        cout<<"Operacija atsaukta."<<endl;
    }
    else{
        for(int i=mk; i<mk+n; i++) {
            cout<<"Irasykite mokinio varda: ";
            cin>>Vardai[i];
            cout<<"Kiek mokinys pazymiu turi? ";
            cin>>m;
            while(m>pazLim) {
                cout<<"Per didelis skaicius. Prasome ivesti skaiciu ne didesni uz "<<pazLim<<"."<<endl;
                cout<<"Kiek mokinys pazymiu turi? ";
                cin>>m;
            }
            if(m>maxPz){maxPz=m;}
            cout<<"Prasome irasyti pazymius."<<endl;
            for(int j=0; j<m; j++) {
                cout<<j+1<<"-as pazymys: ";
                cin>>MokPaz[i][j];
                while(MokPaz[i][j]>10){
                    cout<<"Per didelis skaicius. Prasome ivesti skaiciu ne didesni uz 10."<<endl;
                    cout<<j+1<<"-as pazymys: ";
                    cin>>MokPaz[i][j];
                }
            }
            cout<<"---------------------------"<<endl;
        }
        mk+=n;
    }
    cout<<"Operacija baigta."<<endl<<endl;
    cout<<"==========================="<<endl;
}

void perziura(int MokPaz[][10], string Vardai[], bool konkret, int &mk,int &maxPz) {
    int n;
    string vardas;
    if(konkret==true){
            cout<<"Prasome irasyti mokinio varda. ";
            cin>>vardas;
            for(int i=0; i<n; i++) {
                if(vardas==Vardai[i]){n=i;}
            }
            cout<<"Mokinio pazymiai. "<<endl;
            cout<<vardas<<":";
            for(int i=0; i<maxPz; i++) {
                cout<<" "<<MokPaz[n][i];
            }
            cout<<endl<<"---------------------------"<<endl;

        }
    else{
            cout<<"Spausdinimas visas sarasas mokiniu ir ju pazymiai."<<endl;
            for(int i=0; i<mk; i++) {
                cout<<Vardai[i]<<":";
                for(int j=0; j<maxPz; j++) {
                    cout<<" "<<MokPaz[i][j];
                }
                cout<<endl;
            }
            cout<<"---------------------------"<<endl;
    }
    cout<<"Operacija baigta."<<endl<<endl;
    cout<<"==========================="<<endl;
}

void atnaujint(int MokPaz[][10], string Vardai[], int &mk, int &maxPz) {
    string vardas;
    int n,x;
    cout<<"Mokiniu sarasas: "<<endl;
    for(int i=0; i<mk; i++) {
        cout<<" o "<<Vardai[i]<<endl;
    }
    cout<<endl<<"Prasome irasyti mokinio varda, kurio pazymius norite koreguoti. ";
    cin>>vardas;

    for(int i=0; i<mk; i++) {
        if(vardas==Vardai[i]){n=i;}
    }

    cout<<"Mokinio "<<vardas<<" pazymiai."<<endl;
    cout<<vardas<<": ";
    for(int i=0; i<maxPz; i++) {
        cout<<MokPaz[n][i]<<" ";
    }
    cout<<endl<<"Kelinta pazymi norite redaguoti? ";
    cin>>x;
    cout<<"Irasykite nauja pazymi. ";
    cin>>MokPaz[n][x-1];
    cout<<endl;

    cout<<"Nauji mokinio "<<vardas<<" pazymiai."<<endl;
    cout<<vardas<<": ";
    for(int i=0; i<maxPz; i++) {
        cout<<MokPaz[n][i]<<" ";
    }
    cout<<endl<<"---------------------------"<<endl;
    cout<<"Operacija baigta."<<endl<<endl;
    cout<<"==========================="<<endl;
}

void pasalinti(int MokPaz[][10], string Vardai[], int &mk, int &maxPz) {
    string vardas;
    int n;
    cout<<"Mokiniu sarasas: "<<endl;
    for(int i=0; i<mk; i++) {
        cout<<" o "<<Vardai[i]<<endl;
    }
    cout<<endl<<"Prasome irasyti mokinio varda, kuri norite pasalinti is saraso. ";
    cin>>vardas;

    for(int i=0; i<mk; i++) {
        if(vardas==Vardai[i]) {
            n=i;
        }
    }

    Vardai[n]="";
    for(int i=0; i<maxPz; i++) {
        MokPaz[n][i]=0;
    }

    for(int i=n; i<mk; i++) {
        Vardai[i]=Vardai[i+1];
        for(int j=0; j<maxPz; j++) {
            MokPaz[i][j]=MokPaz[i+1][j];
        }
    }
    Vardai[mk]="";
    for(int i=0; i<maxPz; i++) {
        MokPaz[mk][i]=0;
    }
    mk--;

    cout<<"Atnaujintas sarasas: "<<endl;
    for(int i=0; i<mk; i++) {
        cout<<" o "<<Vardai[i]<<endl;
    }
    cout<<"---------------------------"<<endl;
    cout<<"Operacija baigta."<<endl<<endl;
    cout<<"==========================="<<endl;
}

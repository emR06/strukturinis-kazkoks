#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Student{ //studentu struktura
    string id;
    char answer[20];
    int grade;
    int score=0;
    float percent;
};

struct Question{ //klausimu struktura (statistikai)
    int right=0;
    int wrong=0;
    int und=0;
    float percent;
};

void sk(vector<Student> &students, char* Ats);
void apdoroti(vector<Student> &students, char* Ats);
void sp(vector<Student> students);
void stats(vector<Student> students);
int maximum(vector<Student> students);
int minimum(vector<Student> students);
float vidurkSc(vector<Student> students);
float vidurkPr(vector<Student> students);
int counting(vector<Student> students,int num);
void statsKl(vector<Student> students,char* Ats);
void sunkKl(Question qStats[],int n,int pos[],int &x);
void paieska(vector<Student> students);



int main ()
{
    vector<Student> students;
    char Ats[20];
    sk(students,Ats);
    apdoroti(students,Ats);

    //menu
    cout<<"Duomenys apdoroti."<<endl;
    int p=0;
    while(p!=5){
        cout<<"Pasirinkite funkcija:"<<endl;
        cout<<"1) Rezultatu isvedimas i faila."<<endl;
        cout<<"2) Klases statistika."<<endl;
        cout<<"3) Klausimu statistika."<<endl;
        cout<<"4) Studento paieska pagal ID."<<endl;
        cout<<"5) Iseiti."<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<">";
        cin>>p;
        switch (p)
        {
        case 1:
            {
                cout<<"Spausdinima...";
                sp(students);
                cout<<endl<<"Baigta."<<endl<<endl;
                break;
            }
        case 2:
            {
                cout<<"Klases statistika."<<endl;
                stats(students);
                cout<<"Baigta."<<endl<<endl;
                break;
            }
        case 3:
            {
                cout<<"Klausimu statistika."<<endl;
                statsKl(students,Ats);
                cout<<"Baigta."<<endl<<endl;
                break;
            }
        case 4:
            {
                cout<<"Paieska."<<endl;
                paieska(students);
                cout<<endl<<"Baigta."<<endl<<endl;
                break;
            }
        case 5:
            {

                cout<<endl<<"Viso gero.";
            }
        }
    }

return 0;
}

void sk(vector<Student> &students, char* Ats) //skaitymo funkcija
{
    ifstream fd("testData.txt"); //duomenu failas
    //atsakymu skaitymas
    for(int i=0; i<20; i++)
    {
        fd>>Ats[i];
    }

    //studentu info apdorojimas
    int n=0;
    while(!fd.eof())
    {
        students.push_back(Student());
        fd>>students[n].id;
        for(int i=0; i<20; i++)
        {
            fd>>students[n].answer[i];
        }
        n++;
    }
    students.pop_back();
    fd.close();
}

void apdoroti(vector<Student> &students, char* Ats)
{
    //pereinam per visus studentus
    for(int i=0; i<students.size(); i++)
    {
        for(int j=0; j<20; j++)
        {
            //palyginame studento atsakyma; jei sutampa, +2 balai, jei nesutampa, -1 balas
            if(students[i].answer[j] == Ats[j]){students[i].score+=2;}
            else if(students[i].answer[j] != Ats[j] && students[i].answer[j] != '-'){students[i].score--;}
        }
        //suskaiciuojamas studento procentas
        students[i].percent = (students[i].score/40.0)*100;
        //priskyriame pazymi (visai negrazus sprendimas, bet tebunie)
        if(students[i].percent>94){students[i].grade = 10;}
        else if(students[i].percent>84){students[i].grade=9;}
        else if(students[i].percent>74){students[i].grade=8;}
        else if(students[i].percent>64){students[i].grade=7;}
        else if(students[i].percent>54){students[i].grade=6;}
        else if(students[i].percent>49){students[i].grade=5;}
        else if(students[i].percent>34){students[i].grade=4;}
        else if(students[i].percent>24){students[i].grade=3;}
        else if(students[i].percent>14){students[i].grade=2;}
        else{students[i].grade=1;}
    }
}

//prasideda kitos funkcijos

void sp(vector<Student> students) //spausdinimo funkcija
{
    ofstream fr("results.txt"); //rezultatu failas

    for(int i=0; i<students.size(); i++)
    {
        fr<<students[i].id<<" "<<students[i].score<<" "<<students[i].percent<<"% "<<students[i].grade<<endl;
    } //spausdinam viska, id, balus, procentus, pazymius

    fr.close();
}

void stats(vector<Student> students) //statistikos isspausdinimas
{
    cout<<"Studentu skaicius: "<<students.size()<<endl;
    cout<<"Didziausias balas: "<<maximum(students)<<endl;
    cout<<"Maziausias balas: "<<minimum(students)<<endl;
    cout<<"Vidutinis balas: "<<vidurkSc(students)<<endl;
    cout<<"Vidutinis procentas: "<<vidurkPr(students)<<endl;
    cout<<"Pasiskirstymas..."<<endl;
    for(int i=1; i<=10; i++)
    {
        cout<<i<<"..."<<counting(students,i)<<endl;
    }
    cout<<endl;
}

int maximum(vector<Student> students) //didziausio balo ieskojimas
{
    int m=-41;
    for(int i=0; i<students.size(); i++)
    {
        if(students[i].score>m)
        {
            m=students[i].score;
        }
    }
    return m;
}

int minimum(vector<Student> students) //maziausio balo ieskojimas
{
    int m=41;
    for(int i=0; i<students.size(); i++)
    {
        if(students[i].score<m)
        {
            m=students[i].score;
        }
    }
    return m;
}

float vidurkSc(vector<Student> students) //vidurkio skaiciavimas (balu)
{
    float sum=0;
    for(int i=0; i<students.size(); i++)
    {
        sum+=students[i].score;
    }
    return sum/students.size();
}

float vidurkPr(vector<Student> students) //vidurkio skaiciavimas #2 (procentu)
{
    float sum=0;
    for(int i=0; i<students.size(); i++)
    {
        sum+=students[i].percent;
    }
    return sum/students.size();
}

int counting(vector<Student> students,int num) //pazymiu pasiskirstymo skaiciavimas
{
    int sum=0;
    for(int i=0; i<students.size(); i++)
    {
        if(students[i].grade == num)
        {
            sum++;
        }
    }
    return sum;
}

void statsKl(vector<Student> students,char* Ats) //klausimu statistika
{
    Question qStats[20]; //klausimu statistikos struktura
    for(int i=0; i<students.size(); i++)
    {
        for(int j=0; j<20; j++)
        {
            if(students[i].answer[j] == Ats[j]){qStats[j].right++;}      // lyginame studentu atsakymus,
            else if(students[i].answer[j] == '-'){qStats[j].und++;}      // skaiciuojam, kiek teisingu, kiek neteisingu,
            else if(students[i].answer[j] != Ats[j]){qStats[j].wrong++;} // ir kiek neatsakytu atsakymu yra
        }
    }

    for(int i=1; i<=20; i++)
    {
        cout<<i<<"-o klausimo atsakymai:"<<endl;
        cout<<"Teisingi: "<<qStats[i-1].right<<" | Neteisingi: "<<qStats[i-1].wrong<<" | Neatsakyti: "<<qStats[i-1].und<<endl;
        cout<<"."<<endl; //isspausdiname viska
    }

    int pos[20]; //sunkiausiu klausimu sarasas
    int x=0; //kiek yra sunkiausiu klausimu

    cout<<"Sunkiausi klausimai: "<<endl;
    sunkKl(qStats,students.size(),pos,x); //ieskome sunkiausio klausimo...!
    for(int i=0; i<x; i++)
    {
        cout<<"  o "<<pos[i]-1<<"-tas klausimas. Procentai: "<<qStats[pos[i]].percent<<endl; //isspausdinam viska
    }
}

void sunkKl(Question qStats[],int n,int pos[],int &x)
{
    float sunk=120;
    for(int i=0; i<20; i++)
    {
        qStats[i].percent = (qStats[i].right/(n*1.0))*100; //apskaiciuojame teisingu atsakymu procenta
        if(qStats[i].percent<sunk) //tuo pat surandame, koks sunkiausio klausimo procentas
        {
            sunk=qStats[i].percent;
        }
    }

    for(int i=0; i<20; i++)
    {
        if(qStats[i].percent == sunk) //tada lyginame sunkiausio klausimo procenta su kitais procentais;
        {                             //jei sutampa, idedame to klausimo pozicija i masyva, padidiname x
            pos[x] = i;
            x++;
        }
    }
}

void paieska(vector<Student> students) //paieskos funkcija
{
    string sid;
    bool searched;
    cout<<"Studentu ID sarasas:"<<endl;
    for(int i=0; i<students.size(); i++)
    {
        cout<<"  o "<<students[i].id<<endl; //isspausdiname visus ID
    }
    cout<<"===================================="<<endl;
    while(sid!="0"){ //while ciklas vyks, kol sid nera 0
    searched=false; //searched skirtas tam, kad zinotume, ar buvo sekmingai surastas ID ar ne
    cout<<"Norint iseiti, prasome irasyti 0."<<endl;
    cout<<"Irasykite studento ID: ";
    cin>>sid;
    if(sid=="0"){break;} //jei ivestas nulis, ciklas nutrauktas
    for(int i=0; i<students.size(); i++)
    { //ieskome ID!
        if(students[i].id == sid) //jei yra toks ID: isspausdinam ji, ir isspausdiname studento rezultatus
        {
            cout<<"~~~~~"<<endl;
            cout<<students[i].id<<": "<<endl;
            cout<<"Balai: "<<students[i].score<<" | Procentai: "<<students[i].percent<<" | Pazymys: "<<students[i].grade<<endl;
            cout<<"Teigiamas pazymys? ";
            if(students[i].grade>=5){cout<<"Taip."<<endl;}
            else{cout<<"Ne."<<endl;}
            cout<<"~~~~~"<<endl;
            searched=true;
        }
    }
    if(searched==false)
    {
        cout<<"Tokio ID nera. Prasome bandyti dar karta."<<endl<<endl; //jei id nesurastas, isspausdiname si pranesima
    }
    }
}

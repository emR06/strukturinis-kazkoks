#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Student{
    string id;
    char answer[20];
    int grade;
    int score=0;
    float percent;
};

void sk(vector<Student>* students, int* Ats);
void apdoroti(vector<Student>* students, int* Ats);
void sp(vector<Student>* students);

int main ()
{
    vector<Student> students;
    int *Ats;
    Ats = new int[20];
    sk(students,Ats);
    apdoroti(students,Ats);

    //menu
    cout<<"Duomenys apdoroti."<<endl
    int p=0;
    while(p!=5){
        cout<<"Pasirinkite funkcija:"<<endl;
        cout<<endl;
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
                cout<<endl<<"Spausdinima..."
                sp(students);
                cout<<endl<<"Baigta."<<endl;
                break;
            }
        case 2:
            {
                break;
            }
        case 3:
            {
                break;
            }
        case 4:
            {
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

void sk(vector<Student>* students, int* Ats)
{
    ifstream fd("testData.txt");
    //atsakymu skaitymas
    for(int i=0; i<20; i++)
    {
        fd>>Ats[i];
    }

    //studentu info apdorojimas
    students.push_back(Student()); //sukuriame nauja vektoriaus elementa
    int n=0;
    while(!fd.eof())
    {

        fd>>students[n].id;
        for(int i=0; i<20; i++)
        {
            fd>>students[n].answer[i];
        }
        students.push_back(Student());
        n++;
    }
    fd.close();
}

void apdoroti(vector<Student>* students, int* Ats)
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
        if(students[i].percent>94){students[i].grade == 10;}
        if else(students[i].percent>84){students[i].grade==9;}
        if else(students[i].percent>74){students[i].grade==8;}
        if else(students[i].percent>64){students[i].grade==7;}
        if else(students[i].percent>54){students[i].grade==6;}
        if else(students[i].percent>49){students[i].grade==5;}
        if else(students[i].percent>34){students[i].grade==4;}
        if else(students[i].percent>24){students[i].grade==3;}
        if else(students[i].percent>14){students[i].grade==2;}
        else{students[i].grade==1;}
    }
}

//prasideda kitos funkcijos

void sp(vector<Student>* students)
{
    ofstream fr("results.txt");

    for(int i=0; i<students.size(); i++)
    {
        fr<<students[i].id<<" "<<students[i].score<<" "<<students[i].procent<<" "<<students[i].grade<<endl;
    }

    fr.close();
}



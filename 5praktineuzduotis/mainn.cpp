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

struct Question{
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

void sk(vector<Student> &students, char* Ats)
{
    ifstream fd("testData.txt");
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

void sp(vector<Student> students)
{
    ofstream fr("results.txt");

    for(int i=0; i<students.size(); i++)
    {
        fr<<students[i].id<<" "<<students[i].score<<" "<<students[i].percent<<"% "<<students[i].grade<<endl;
    }

    fr.close();
}

void stats(vector<Student> students)
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

int maximum(vector<Student> students)
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

int minimum(vector<Student> students)
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

float vidurkSc(vector<Student> students)
{
    float sum=0;
    for(int i=0; i<students.size(); i++)
    {
        sum+=students[i].score;
    }
    return sum/students.size();
}

float vidurkPr(vector<Student> students)
{
    float sum=0;
    for(int i=0; i<students.size(); i++)
    {
        sum+=students[i].percent;
    }
    return sum/students.size();
}

int counting(vector<Student> students,int num)
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

void statsKl(vector<Student> students,char* Ats)
{
    Question qStats[20];
    for(int i=0; i<students.size(); i++)
    {
        for(int j=0; j<20; j++)
        {
            if(students[i].answer[j] == Ats[j]){qStats[j].right++;}
            else if(students[i].answer[j] == '-'){qStats[j].und++;}
            else if(students[i].answer[j] != Ats[j]){qStats[j].wrong++;}
        }
    }

    for(int i=1; i<=20; i++)
    {
        cout<<i<<"-o klausimo atsakymai:"<<endl;
        cout<<"Teisingi: "<<qStats[i-1].right<<" | Neteisingi: "<<qStats[i-1].wrong<<" | Neatsakyti: "<<qStats[i-1].und<<endl;
        cout<<"."<<endl;
    }
}


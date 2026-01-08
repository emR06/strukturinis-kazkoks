#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

struct Student
{
    string studentID;
    char answers[20];
    int points=0;
};

int main ()
{
    //
    //       ___==__=
    //__----       o \
    //          o      ]
    //               /
    //              |
    // =    __---   /
    //   \_|     |_|
    //what the hell a polar bear doing in texas
return 0;
}

void sk()
{
    ifstream fd("testData.txt");

    int a=20;
    char *tA = new char[a];
    for(int i=0; i<a; i++) //assign that 20 to a vriable plz
    {                       //testo atsakymai btw
        fd>>tA[i];
    }

    int n=50;
    int x=0;
    Student* studentsTemp=new Student[n]; //i guess weonly use this for the fact that we dont know how many eilutes we have?
    for(int i=0; i<n; i++) //studentu atsakymai btw
    {                       //gotta find a way to save all the info without knowing the size i guess???
        fd>>studentsTemp[i].studentID;
        x++;
        for(int j=0; j<a; j++)
        {
            fd>>studentsTemp[i].answers[j];
            if(studentsTemp[i].answers[j]==tA[j]){studentsTemp[i].points+=2;}
            if(studentsTemp[i].answers[j]!=tA[j] && (studentsTemp[i].answers[j]!='-' || studentsTemp[i].answers[j]!=' ')){studentsTemp[i].points--;}
        }
    }

    Student students[x];
    for(int i=0; i<x; i++)
    {
        students[i].studentID = studentsTemp[i].studentID;
        students[i].points = studentsTemp[i].points;
        students[i].answers = studentsTemp.answers;
    }

    delete[] studentsTemp;
    delete[] tA;
    fd.close();
}


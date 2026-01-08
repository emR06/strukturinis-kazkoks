#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void sk(vector<Student>* students, int* Ats);

struct Student{
    string id;
    char answer[20];
};

int main ()
{
    vector<Student> students;
    int *Ats;
    Ats = new int[20];
    sk(students,Ats);


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

    //studentu apdorojimas
    students.push_back(Student());
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
}



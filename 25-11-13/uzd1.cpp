#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

struct Student{
    string vardas;
    int amzius;
    double pazymys;
};

void sk(int& n,Student A[]);
float vid(int n,Student A[]);

int main ()
{
    const int k=100;
    Student A[k];
    int n;

    sk(n,A);

    cout<<vid(n,A);
return 0;
}

void sk(int& n,Student A[])
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Studento vardas. ";
        cin>>A[i].vardas;
        cout<<"Studento amzius. ";
        cin>>A[i].amzius;
        cout<<"Studento pazymys. ";
        cin>>A[i].pazymys;
        cout<<"------------------"<<endl;
    }
}

float vid(int n,Student A[])
{
    float sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=A[i].pazymys;
    }

    return sum/(n*1.0);
}

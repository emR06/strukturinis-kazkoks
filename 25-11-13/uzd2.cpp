#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

struct Preke
{
    string pavadinimas;
    double kaina;
    int kiekis;
};

void sk(int& n, Preke A[]);
string mx(int n, Preke A[]);

int main ()
{
    const int k=100;
    Preke A[k];
    int n;

    sk(n,A);

    cout<<"Brangiausia preke: "<<mx(n,A);
return 0;
}

void sk(int& n, Preke A[])
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Prekes pavadinimas. ";
        cin>>A[i].pavadinimas;
        cout<<"Prekes kaina. ";
        cin>>A[i].kaina;
        cout<<"Prekes kiekis. ";
        cin>>A[i].kiekis;
        cout<<"-----------------"<<endl;
    }
}

string mx(int n, Preke A[])
{
    double mKaina=A[0].kaina;
    int poz;

    for(int i=1; i<n; i++)
    {
        if(A[i].kaina>mKaina)
        {
            poz=i;
            mKaina=A[i].kaina;
        }
    }

    return A[poz].pavadinimas;
}

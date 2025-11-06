#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//insert erlking standing in rain
int main ()
{
    string St[10];
    int Pz[10], n=0;
    const int cutoff=8;

    ifstream fd("studentai.txt");
    while(!fd.eof())
    {
        fd>>St[n];
        fd>>Pz[n];
        n++;
    }
    fd.close();

    ofstream fr("studentaiRez.txt");
    for(int i=0; i<n; i++)
    {
        if(Pz[i]>cutoff)
        {
            fr<<St[i]<<" "<<Pz[i]<<endl;
        }
    }
    fr.close();

return 0;
}

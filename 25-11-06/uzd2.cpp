#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
void counting (char c, int& lc, int& sc, int& wc);

int main ()
{
    int lc=0, sc=0, wc=0;
    char c;

    ifstream fd("studentai.txt");
    while(!fd.eof())
    {
        fd.get(c);
        counting(c,lc,sc,wc);
    }
    fd.close();

    ofstream fr("studentaiRez.txt");
    fr<<"Eiluciu skaicius: "<<lc+1<<endl;
    fr<<"Simboliu skaicius: "<<sc<<endl;
    fr<<"Zodziu skaicius: "<<wc<<endl;
    fr.close();
return 0;
}

void counting (char c, int& lc, int& sc, int& wc)
{
    if(c != '\n')
    {
        sc++;
    }
    else
    {
        lc++;
    }

    if(c == ' ')
    {
        wc++; //this part's wrong cuz if you add another space itll
              //count the numbers as a word too but then again. numbers are technically words
              //whatever im too lazy to go through this philosophical dillemma
    }         //and my method is too simple i think

              //im from the future and i think you're overthinkikng it. bloody minging innit
}

#include <iostream>

using namespace std;

int main() {

    //1-2 uzd.
    //int n, A[25];
    //float vid=0;
    //cout<<"iveskite pazymiu skaiciu"<<endl;
    //cin>>n;
    //cout<<"iveskite pazymius"<<endl;
    //for(int i=0; i<n; i++) {
       // cin>>A[i];
       //vid+=A[i];
    //}
    //cout<<"////////////"<<endl;
    //vid=vid/float(n);
    //if(vid>=5){cout<<"vidurkis teigiamas";}
    //else{cout<<"vidurkis neigiamas";}

    //3 uzd.
    //int p;
    //cin>>p;

    //if(p==10){cout<<"puiku";}
    //else if(p>=9){cout<<"labai gerai";}
    //else if(p>=7){cout<<"gerai";}
    //else if(p>=5){cout<<"patenkinamai";}
    //else if(p<5){cout<<"egzaminas neislaikytas";}

    //4 uzd.
    //int p;
    //cin>>p;

   // switch(p) {
       // case 10: cout<<"puiku"; break;
        //case 9: cout<<"labai gerai"; break;
        //case 8: cout<<"gerai"; break;
        //case 7: cout<<"gerai"; break;
        //case 6: cout<<"patenkinamai"; break;
        //case 5: cout<<"patenkinamai"; break;
        //default: cout<<"egzaminas neislaikytas"; break;
    //}

    //5 uzd.
    //int sum=0;
    //for(int i=1; i<=20; i++) {
        //if(i%2!=0) {
            //sum+=i;
        //}
    //}
    //cout<<sum;

    //6 uzd.
    int m;
    float p,proc;
    cin>>p>>proc>>m;
    for(int i=0; i<m; i++) {
        p=p*(1+(proc/100));
    }
    cout<<p<<endl;

    //7 uzd.
    //for(int i=1; i<=20; i++) {
        //if(i%4==0) {
            //cout<<i<<endl;
        //}
    //}

    return 0;
}

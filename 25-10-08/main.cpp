#include <iostream>

using namespace std;

int main() {
    //vienmaciai masyvai
    //uzd 1.
    //int A[5],max,min,sum=0;
    //for(int i=0; i<5; i++) {
        //cin>>A[i];
        //sum+=A[i];
        //if(i==0) {
            //max=A[0];
            //min=A[0];
        //}
        //if(i>0 && A[i]>max) {
            //max=A[i];
        //}
        //if(i>0 && A[i]<min) {
            //min=A[i];
        //}
    //}
    //cout<<"Visu elementu suma: "<<sum<<endl;
    //cout<<"Didziausias elementas: "<<max<<endl;
    //cout<<"Maziausias elementas: "<<min<<endl;

    //2 uzd.
    //int B[10]={0},x;
    //for(int i=0; i<40; i++) {
        //cin>>x;
        //B[x-1]++;
    //}

    //for(int i=0; i<10; i++) {
        //cout<<i+1<<": "<<B[i]<<endl;
    //}

    //dvimaciai masyvai
    //uzd 1
    //int n, m;
    //cin>>n>>m;
    //int B[n][m];
    //float studVid=0,dalVid=0,bendrVid;

    //for(int i=0; i<n; i++) {
        //for(int j=0; j<m; j++) {
            //cout<<i+1<<" studento "<<j+1<<" dalyko pazymys: ";
            //cin>>B[i][j];
        //}
    //}

    //for(int i=0; i<n; i++) {
        //for(int j=0; j<m; j++) {
            //studVid+=B[i][j];
            //dalVid+=B[j][i];
        //}
        //studVid=studVid/float(m);
        //dalVid=dalVid/float(n);
        //cout<<i+1<<" studento vidurkis: "<<studVid<<endl;
        //cout<<i+1<<" dalyko vidurkis: "<<dalVid<<endl;
        //bendrVid+=studVid+dalVid;
        //studVid=0;
        //dalVid=0;
    //}
    //bendrVid=bendrVid/float(n*m);
    //cout<<"bendras grupes vidurkis: "<<bendrVid;

    //uzd 2.
    const int m=3,d=7,p=4;
    int A[m][d][p];

    for(int i=0; i<m; i++) {
        for(int j=0; j<d; j++) {
            for(int k=0; k<p; k++) {
                cout<<i+1<<" miesto "<<j+1<<" dienos "<<k+1<<" paros laiko temperatura:";
                cin>>A[i][j][k];
            }
        }
    }

    float tempParos=0,vidDienos=0,vidSav=0;
    float silDiena,pozDiena;
    for(int i=0; i<m; i++) {
        for(int j=0; j<d; j++) {
            for(int k=0; k<p; k++) {
                tempParos+=A[i][j][k];
            }
            vidDienos=tempParos/float(p);
            vidSav+=vidDienos;
            vidDienos=0;
        }
        vidSav=vidSav/d;
        cout<<i+1<<" miesto savaites vid. temp.: "<<vidSav<<endl;
        vidSav=0;
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<d; j++) {
            for(int k=0; k<p; k++) {
                tempParos+=A[i][j][k];
            }
            vidDienos=tempParos/float(p);
            if(j==0){silDiena=vidDienos;}
            if(j>0 && vidDienos>silDiena) {
                silDiena=vidDienos;
                pozDiena=j;
            }
        }
        cout<<i+1<<" miesto silciausia diena buvo "<<pozDiena<<" diena."<<endl;
    }

    return 0;
}

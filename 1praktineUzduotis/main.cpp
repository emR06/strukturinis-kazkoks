#include <iostream>

void pirkti(int pasirink);
void parduoti(int pasirink);

using namespace std;

int main() {
    int pasirink;

    cout<<"Prasome pasirinkti operacija:"<<endl;
    cout<<"1: Valiutos kurso palyginimas su kita valiuta."<<endl;
    cout<<"2: Galimybe isigyti valiutos."<<endl;
    cout<<"3: Galimybe parduoti valiuta."<<endl;
    cout<<"Jusu pasirinkimas: ";
    cin>>pasirink;
    cout<<endl<<"Jus pasirinkote: ";

    switch(pasirink) {
        case 1: cout<<"valiutos kurso palyginimas su kita valiuta."; break;
        case 2: cout<<"galimybe isigyti valiutos."; pirkti(pasirink); break;
        case 3: cout<<"galimybe parduoti valiuta."; parduoti(pasirink); break;
    }
    return 0;
}

void pirkti(int pasirink){
    int n;
    float GBP_Pirkti=0.8600;
    float USD_Pirkti=1.1460;
    float INR_Pirkti=101.3862;

    cout<<endl<<"///////////////"<<endl;
    cout<<"Prasome pasirinkti valiuta:"<<endl;
    cout<<"1: GBP"<<endl;
    cout<<"2: USD"<<endl;
    cout<<"3: INR"<<endl;
    cout<<"Jusu pasirinkimas:";
    cin>>pasirink;
    cout<<endl<<"Jus pasirinkote: ";

    switch(pasirink) {
        case 1: cout<<"GBP"<<endl; break;
        case 2: cout<<"USD"<<endl; break;
        case 3: cout<<"INR"<<endl; break;
    }

    cout<<endl<<"Uz 1 EUR galima nupirkti ";
    switch(pasirink) {
        case 1: cout<<GBP_Pirkti<<" GBP."; break;
        case 2: cout<<USD_Pirkti<<" USD."; break;
        case 3: cout<<INR_Pirkti<<" INR."; break;
    }

    cout<<endl<<"Prasome irasyti uz kiek EUR pirksite."<<endl;
    cin>>n;
    cout<<endl<<"Uz "<<n<<" EUR gausite ";
    switch(pasirink) {
        case 1: cout<<GBP_Pirkti*n<<" GBP."; break;
        case 2: cout<<USD_Pirkti*n<<" USD."; break;
        case 3: cout<<INR_Pirkti*n<<" INR."; break;
    }

}

void parduoti(int pasirink) {
    int n;
    float GBP_Parduoti=0.9220;
    float USD_Parduoti=1.2340;
    float INR_Parduoti=107.8546;

    cout<<endl<<"///////////////"<<endl;
    cout<<"Prasome pasirinkti valiuta:"<<endl;
    cout<<"1: GBP"<<endl;
    cout<<"2: USD"<<endl;
    cout<<"3: INR"<<endl;
    cout<<"Jusu pasirinkimas:";
    cin>>pasirink;
    cout<<endl<<"Jus pasirinkote: ";

    switch(pasirink) {
        case 1: cout<<"GBP"<<endl; break;
        case 2: cout<<"USD"<<endl; break;
        case 3: cout<<"INR"<<endl; break;
    }

    cout<<endl<<"Pardavus 1 ";
    switch(pasirink) {
        case 1: cout<<"GBP gausite "<<GBP_Parduoti<<" EUR."; break;
        case 2: cout<<"USD gausite "<<USD_Parduoti<<" EUR."; break;
        case 3: cout<<"INR gausite "<<INR_Parduoti<<" EUR."; break;
    }

    cout<<endl<<"Prasome irasyti kiek parduosite."<<endl;
    cin>>n;
    cout<<endl<<"Uz "<<n;
    switch(pasirink) {
        case 1: cout<<" GBP gausite "<<GBP_Parduoti*n<<" EUR."; break;
        case 2: cout<<" USD gausite "<<USD_Parduoti*n<<" EUR."; break;
        case 3: cout<<" INR gausite "<<INR_Parduoti*n<<" EUR."; break;
    }
}

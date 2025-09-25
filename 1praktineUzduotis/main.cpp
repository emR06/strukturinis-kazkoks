#include <iostream>
#include <iomanip>

void pirkti(int pasirink);
void parduoti(int pasirink);
void palygint(int pasirink);

using namespace std;

int main() {
    int pasirink;

    cout<<"Prasome pasirinkti operacija:"<<endl;
    cout<<"1: Valiutos kurso palyginimas su kita valiuta."<<endl;
    cout<<"2: Galimybe isigyti valiutos."<<endl;
    cout<<"3: Galimybe parduoti valiuta."<<endl;
    cout<<"Jusu pasirinkimas: ";
    cin>>pasirink;
    cout<<"Jus pasirinkote: ";

    switch(pasirink) {
        case 1: cout<<"valiutos kurso palyginimas su kita valiuta."; palygint(pasirink); break;
        case 2: cout<<"galimybe isigyti valiutos."; pirkti(pasirink); break;
        case 3: cout<<"galimybe parduoti valiuta."; parduoti(pasirink); break;
        default: cout<<"error"<<endl<<"Prasome bandyti dar karta."; break;
    }
    return 0;
}

void palygint(int pasirink) {
    float n;
    float GBP_Bendras=0.8729;
    float USD_Bendras=1.1793;
    float INR_Bendras=104.6918;
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
        default: cout<<"error"; break;
    }

    cout<<endl<<"1 EUR = ";
    switch(pasirink) {
        case 1: cout<<fixed<<setprecision(2)<<GBP_Bendras<<" GBP."; break;
        case 2: cout<<fixed<<setprecision(2)<<USD_Bendras<<" USD."; break;
        case 3: cout<<fixed<<setprecision(2)<<INR_Bendras<<" INR."; break;
        default: cout<<"error"; break;
    }

    cout<<endl<<"Prasome irasyti EUR kieki."<<endl;
    cin>>n;
    cout<<endl<<n<<" EUR = ";
    switch(pasirink) {
        case 1: cout<<fixed<<setprecision(2)<<GBP_Bendras*n<<" GBP."; break;
        case 2: cout<<fixed<<setprecision(2)<<USD_Bendras*n<<" USD."; break;
        case 3: cout<<fixed<<setprecision(2)<<INR_Bendras*n<<" INR."; break;
        default: cout<<"error"<<endl<<"Prasome bandyti dar karta."; break;
    }
}

void pirkti(int pasirink){
    float n;
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
        default: cout<<"error"; break;
    }

    cout<<endl<<"Uz 1 EUR galima nupirkti ";
    switch(pasirink) {
        case 1: cout<<fixed<<setprecision(2)<<GBP_Pirkti<<" GBP."; break;
        case 2: cout<<fixed<<setprecision(2)<<USD_Pirkti<<" USD."; break;
        case 3: cout<<fixed<<setprecision(2)<<INR_Pirkti<<" INR."; break;
        default: cout<<"error"; break;
    }

    cout<<endl<<"Prasome irasyti uz kiek EUR pirksite."<<endl;
    cin>>n;
    cout<<endl<<"Uz "<<n<<" EUR gausite ";
    switch(pasirink) {
        case 1: cout<<fixed<<setprecision(2)<<GBP_Pirkti*n<<" GBP."; break;
        case 2: cout<<fixed<<setprecision(2)<<USD_Pirkti*n<<" USD."; break;
        case 3: cout<<fixed<<setprecision(2)<<INR_Pirkti*n<<" INR."; break;
        default: cout<<"error"<<endl<<"Prasome bandyti dar karta."; break;
    }

}

void parduoti(int pasirink) {
    float n;
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
        default: cout<<"error"; break;
    }

    cout<<endl<<"Pardavus 1 ";
    switch(pasirink) {
        case 1: cout<<fixed<<setprecision(2)<<"GBP gausite "<<1/GBP_Parduoti<<" EUR."; break;
        case 2: cout<<fixed<<setprecision(2)<<"USD gausite "<<1/USD_Parduoti<<" EUR."; break;
        case 3: cout<<fixed<<setprecision(2)<<"INR gausite "<<1/INR_Parduoti<<" EUR."; break;
        default: cout<<"error"; break;
    }

    cout<<endl<<"Prasome irasyti kiek parduosite."<<endl;
    cin>>n;
    cout<<endl<<"Uz "<<n;
    switch(pasirink) {
        case 1: cout<<" GBP gausite "<<fixed<<setprecision(2)<<(1/GBP_Parduoti)*n<<" EUR."; break;
        case 2: cout<<" USD gausite "<<fixed<<setprecision(2)<<(1/USD_Parduoti)*n<<" EUR."; break;
        case 3: cout<<" INR gausite "<<fixed<<setprecision(2)<<(1/INR_Parduoti)*n<<" EUR."; break;
        default: cout<<"error"<<endl<<"Prasome bandyti dar karta."; break;
    }
}

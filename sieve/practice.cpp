#include<bits/stdc++.h>
using namespace std;
#define outn(uu)           cout<<uu <<endl;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
    int x,y,z,PA,PB,QA,QB;
    cin>>PA>>PB>>QA>>QB;
    if(PA==QA||PA==QB||PB==QB || PB==QA) cout<<"TIE"<<endl;
    else if(PB<QB) cout<<"P"<<endl;
    else if(PB>QB) cout<<"Q"<<endl;

    }
}

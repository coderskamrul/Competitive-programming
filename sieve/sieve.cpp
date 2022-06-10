#include <bits/stdc++.h>
#define ll long long
using namespace std;
///onst ll OO = 1e18;
int main() {
 ll T=1;    cin>>T;
  while(T--){
         ll n , k;   cin>>n>>k;
         if( k == 1){
             cout<<( n%2 == 0 ? "EVEN" : "ODD" )<<endl;
         }
         else{
             cout<<( k%2 == 0 ? "ODD" : "EVEN")<<endl;
         }
  }
}

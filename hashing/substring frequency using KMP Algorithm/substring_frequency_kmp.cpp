//________________________________________________________________________________________
//
//_______________________________IUBAT___________________________________________________________________
//
//				...BISMILLAHIR RAHMANIR RAHIM...
//				    ...MD Kamrul Hasan...
//________________________________________________________________________________________
//
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef bool                      bol;
typedef int                       li;
typedef long long int             ll;
typedef unsigned long long int    l1;
typedef double                    db;
typedef string                    ST;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef vector < li >                   vli;
typedef vector < ll >                   vll;
typedef set < li >                      sli;
typedef set < ll >                      sll;
typedef pair < li, li >                pli;
typedef pair < ll, ll >                pll;
typedef map < li,li >                  mli;
typedef map < ll,ll >                  mll;
typedef unordered_map<ll,ll>           uml;
typedef vector < pair < li, li > >     vpi;
typedef vector < pair < ll, ll > >     vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tcase                     int t;cin>>t;while(t--)
#define inp_i(a,n)                for(i=0; i<n ;i++) cin>>a[i]
#define out_i(a, b, c)            for(i=b; i<c; i++) cout<<a[i] spc; cout nl;
#define lp(i,a,b)                 for(i=a;i<b;i++)
#define len(z)                    z.begin(),z.end()
#define faster                    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define input_txt                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define nl                        <<"\n"
#define newline                   cout<<"\n"
#define spc                       <<" "
#define sp                        <<" "<<
#define outn(x)                   cout<<x nl;
#define out(x)                    cout<<x
#define siz(a)                    a.size()
#define yes                       cout<<"YES" nl
#define no                        cout<<"NO" nl
#define pb                        push_back
#define F                         first
#define S                         second
#define Maxx                      max_element
#define Minn                      min_element
#define pi                        2*acos(0.0)
#define clr(z)                    z.clear()
#define len_s(u)                  ((int)u.size())
#define rn                        return
#define mem(b,z)                  memset(b,z,sizeof(b))
#define fixed(x)                  fixed<<setprecision(x)
#define srt(h)                    (h).begin(), (h).end()
#define ins                        insert
#define rev                        reverse

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
char text[1100000];
char pattern[1100000];
int b[1100000];
void kmpPreprocess(char *pattern)
{
    const int m = strlen(pattern);
    int i = 0, j = -1;

    b[i] = -1;
    while(i < m)
    {
        while(j >= 0 && pattern[i] != pattern[j])
            j = b[j];

		i++;
        j++;
        b[i] = j;
    }
}

int kmp(char *text, char *pattern)
{
    int i=0, j=0, count = 0;
    const int n = strlen(text);
    const int m = strlen(pattern);
	kmpPreprocess(pattern);
    while (i<n)
    {
        while (j>=0 && text[i]!=pattern[j])
            j=b[j];

        i++;
        j++;

        if (j==m)
        {
            count++;
            j=b[j];
        }
    }
    return count;
}


void solves()
{
    ll n,sum=0;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
    cin>>text>>pattern;
    ll ans = kmp(text,pattern);
    outn("Case "<<i+1<<": " <<ans);
    }
}
void init_code()
{
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
}

int main()
{
    faster
    //tcase(solves());
    solves();
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define neg cout << -1 << endl
#define pb push_back
#define ss second
#define ff first

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int INF = 1e18;
int md = 998244353;

void solve()
{
     int a, b, c;
     cin>>a>>b>>c;
     string s;
     cin>>s;
     if(s=="Red"){
        cout<<(min(b, c))<<endl;
     }
     if(s=="Green"){
        cout<<(min(a, c))<<endl;
     }
     if(s=="Blue"){
        cout<<(min(a, b))<<endl;
     }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test=1;
    //cin >> test;
    for (int tc = 0; tc < test; tc++)
    {
        solve();
    }

    return 0;
}


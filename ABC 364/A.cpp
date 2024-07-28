#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define neg cout << -1 << endl
#define pb push_back
#define ss second
#define ff first

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e18;
int md = 998244353;

void solve()
{
    int n;
    cin>>n;
    string last;
    string s;
    int f=0;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        if(i>0 and i<n-1)
        {
            if(s==last and s=="sweet")
            {
                f=1;
            }
        }
        last=s;

    }
    if(f)
    {
        no;
        return;
    }
    yes;
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


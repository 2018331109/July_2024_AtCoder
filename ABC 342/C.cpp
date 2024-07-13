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
    int n;
    cin>>n;
    vector<pair<int, int>>v;
    int negative=0, positive=0;
    vector<int>visited(n, 0), ans(n, 0);
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        v.pb(make_pair(a, b));
        if(a>0)
        {
            positive+=a;
            ans[i]=a;
        }
        if(b<0)
        {
            negative+=abs(b);
            ans[i]=b;
        }
    }
    if(positive!=negative)
    {
        int rm=abs(positive-negative);
        for(int i=0; i<n; i++)
        {
            if(positive>negative)
            {
                if(v[i].ss<=0)
                {
                    int take=min(rm, abs(v[i].ff)-abs(v[i].ss));
                    rm-=take;
                    ans[i]+=(-take);
                    negative+=take;
                }
                else if(v[i].ff<0)
                {
                    int take=min(rm, abs(v[i].ff));
                    rm-=take;
                    ans[i]+=(-take);
                    negative+=take;
                }
            }
            if(positive<negative)
            {
                if(v[i].ff>0)
                {
                    int take=min(rm,  v[i].ss- v[i].ff);
                    rm-=take;
                    ans[i]+=take;
                    positive+=take;
                }
                else if(v[i].ss>0)
                {
                    int take=min(rm,  v[i].ss);
                    rm-=take;
                    ans[i]+=take;
                    positive+=take;
                }
            }
        }
    }
    if(positive==negative)
    {
        yes;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    no;

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


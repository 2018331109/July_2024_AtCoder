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
const int N = 2e5 + 5;
const int INF = 1e18;
int md = 998244353;

bool call(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    // Get the min and max for the first cuboid in each dimension
    int x1_min = min(a, d), x1_max = max(a, d);
    int y1_min = min(b, e), y1_max = max(b, e);
    int z1_min = min(c, f), z1_max = max(c, f);

    // Get the min and max for the second cuboid in each dimension
    int x2_min = min(g, j), x2_max = max(g, j);
    int y2_min = min(h, k), y2_max = max(h, k);
    int z2_min = min(i, l), z2_max = max(i, l);

    // Check for overlap in all dimensions
    bool overlap_x = !(x1_max <= x2_min || x2_max <= x1_min);
    bool overlap_y = !(y1_max <= y2_min || y2_max <= y1_min);
    bool overlap_z = !(z1_max <= z2_min || z2_max <= z1_min);

    // Intersection has positive volume if all dimensions overlap
    return overlap_x && overlap_y && overlap_z;
}

void solve()
{
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;

    // Reading input
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    // Checking for intersection
    if (call(a, b, c, d, e, f, g, h, i, j, k, l)) yes;
    else no;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test=1;
    //cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }

    return 0;
}


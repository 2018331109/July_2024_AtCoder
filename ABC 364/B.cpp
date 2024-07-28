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
    int H, W;
    cin >> H >> W;
    int Si, Sj;
    cin >> Si >> Sj;

    // Adjust to zero-indexed
    Si--;
    Sj--;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];
    }

    string X;
    cin >> X;

    // Directions map
    int dx[4] = {0, 0, -1, 1}; // L, R, U, D
    int dy[4] = {-1, 1, 0, 0}; // L, R, U, D
    char dir[4] = {'L', 'R', 'U', 'D'};

    for (char move : X)
    {
        int new_x = Si, new_y = Sj;
        for (int d = 0; d < 4; ++d)
        {
            if (move == dir[d])
            {
                new_x = Si + dx[d];
                new_y = Sj + dy[d];
                break;
            }
        }
        if (new_x >= 0 && new_x < H && new_y >= 0 && new_y < W && grid[new_x][new_y] == '.')
        {
            Si = new_x;
            Sj = new_y;
        }
    }

    // Adjust back to one-indexed
    cout << Si + 1 << " " << Sj + 1 << endl;
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


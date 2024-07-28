class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Sort both the horizontal and vertical cuts in descending order
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int horizontalPieces = 1, verticalPieces = 1;
        int totalCost = 0;
        int i = 0, j = 0;

        // Use a greedy approach to process the largest cuts first
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] > verticalCut[j]) {
                totalCost += horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                totalCost += verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        // Add remaining horizontal cuts
        while (i < horizontalCut.size()) {
            totalCost += horizontalCut[i] * verticalPieces;
            horizontalPieces++;
            i++;
        }

        // Add remaining vertical cuts
        while (j < verticalCut.size()) {
            totalCost += verticalCut[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }

        return totalCost;
    }
};#include <bits/stdc++.h>
using namespace std;
#define int long long
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

    int N;
    int X, Y;
    cin >> N >> X >> Y;

    vector<pair<int, int>> dishes(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> dishes[i].first;  // Sweetness
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> dishes[i].second;  // Saltiness
    }

    // Sort by sweetness in descending order
    sort(dishes.begin(), dishes.end(), [](pair<int, int>& a, pair<int, int>& b)
    {
        return a.first > b.first;
    });

    // Calculate minimum dishes needed by sweetness constraint
    int totalSweetness = 0;
    int ans1 = 0;
    for (int i = 0; i < N; ++i)
    {
        totalSweetness += dishes[i].first;
        ans1++;
        if (totalSweetness > X)
        {
            break;
        }
    }

    // Sort by saltiness in descending order
    sort(dishes.begin(), dishes.end(), [](pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    });

    // Calculate minimum dishes needed by saltiness constraint
    int totalSaltiness = 0;
    int ans2 = 0;
    for (int i = 0; i < N; ++i)
    {
        totalSaltiness += dishes[i].second;
        ans2++;
        if (totalSaltiness > Y)
        {
            break;
        }
    }

    // Print the minimum number of dishes needed
    cout << min(ans1, ans2) << endl;
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


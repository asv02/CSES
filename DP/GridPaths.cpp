
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define vvll vector<vector<ll>>
const ll MOD = 1000000007;
#define fta_fat_lelo()                    \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define loop(i, st, end) for (int i = st; i < end; i++)
#define revloop(i, st, end) for (int i = st; i >= end; i--)
#define all(arr) arr.begin(), arr.end()
#define pb emplace_back
#define en "\n"
#define input(arr, n) \
    loop(i, 0, n) { cin >> arr[i]; }
#define output(arr, n) \
    loop(i, 0, n) { cout << arr[i] << " "; }

int n;
string arr[1001];
ll dp[1001][1001];
ll path[1001][1001];


int iter()
{
    if (arr[0][0] == '*')
    {
        return 0;
    }

    path[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                continue;
            }
            if (arr[i][j] == '*')
            {
                path[i][j] = 0;
            }
            else if (i == 0 and j >= 1)
            {
                path[i][j] = path[i][j - 1]%MOD;
            }
            else if (j == 0 and i >= 1)
            {
                path[i][j] = path[i - 1][j]%MOD;
            }
            else if (i >= 1 and j >= 1)
            {
                path[i][j] = (path[i - 1][j] + path[i][j - 1])%MOD;
            }
        }
    }
    return (path[n - 1][n - 1])%MOD;
}
void solve()
{
    cin >> n;
    loop(i, 0, n)
    {
        cin >> arr[i];
    }
    cout << iter()%MOD << en;

}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}
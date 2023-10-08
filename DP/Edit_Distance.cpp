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

int n, x;
int arr[1001];
// int dp[100001][100001];
string s1, s2;

// gives TLE
int rec() { return 1; }

void solve()
{
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n2; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s1[i - 1] != s2[j - 1])
            {                     //added          //replaced        //removed(this condition gives minimum when extra letter present )
                dp[i][j] = 1 + min({dp[i][j - 1],  dp[i - 1][j - 1],dp[i-1][j]});
            }
        }
    }
    cout<<dp[n1][n2]<<en;
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
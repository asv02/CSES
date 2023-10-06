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
int dp[103][1000003];

int iter()
{
    for (int i = 0; i < x + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            int not_taken = (1LL * dp[i - 1][j]) % MOD;
            int taken = 0;
            if (arr[i - 1] <= j)
            {
                taken = (1LL * dp[i][j - arr[i - 1]]) % MOD;
            }
            dp[i][j] = (1LL * taken + 1LL * not_taken) % MOD;
        }
    }
    return dp[n][x];
}

// gives TLE
int rec(int level, int sum_left)
{

    if (sum_left == 0)
    {
        return 1;
    }

    if (sum_left < 0 || level >= n)
    {
        return 0;
    }

    if (dp[level][sum_left] != -1)
    {
        return (1LL * dp[level][sum_left]) % MOD;
    }

    int not_taken = (1LL * rec(level + 1, sum_left)) % MOD;
    int taken = 0;

    if (arr[level] <= sum_left)
    {
        taken = (1LL * rec(level, sum_left - arr[level])) % MOD;
    }

    return dp[level][sum_left] = (1LL * taken + 1LL * not_taken) % MOD;
}

void solve()
{
    cin >> n >> x;
    input(arr, n);

    // for (int i = 0; i < n + 1; i++)
    // {
    //     loop(j, 0, x + 1)
    //     {
    //         dp[i][j] = -1;
    //     }
    // }
    // cout << rec(0, x) << en;
    cout << iter() << en;
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

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
    for (int j = 0; j < x+1; j++)
    {
        dp[0][j] = -1;
    }

    for (int i = 0; i < n+1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            int not_taken = dp[i - 1][j];
            int taken = -1;
            if (arr[i - 1] <= j)
            {
                taken = dp[i][j - arr[i - 1]];
                if (taken != -1)
                {
                    taken = 1 + taken;
                }
            }
            if (not_taken == -1 and taken == -1)
            {
                 dp[i][j] = -1;
            }
            else if (not_taken == -1)
            {
                 dp[i][j] = taken;
            }
            else if (taken == -1)
            {
                 dp[i][j] = not_taken;
            }
            else if (not_taken != -1 and taken != -1)
            {
                 dp[i][j] = min(not_taken, taken);
            }
        }
    }
    return dp[n][x];
}

//gives TLE
int rec(int level, int sum_left)
{

    if (sum_left < 0 || level >= n)
    {
        return -1;
    }
    if (sum_left == 0)
    {
        return 0;
    }

    if (dp[level][sum_left] != -2)
    {
        return dp[level][sum_left];
    }
    int not_taken = rec(level + 1, sum_left);
    int taken = -1;
    if (arr[level] <= sum_left)
    {
        taken = rec(level, sum_left - arr[level]);
        if (taken != -1)
        {
            taken = 1 + taken;
        }
    }

    if (not_taken == -1 and taken == -1)
    {
        return dp[level][sum_left] = -1;
    }
    else if (not_taken == -1)
    {
        return dp[level][sum_left] = taken;
    }
    else if (taken == -1)
    {
        return dp[level][sum_left] = not_taken;
    }
    else if (not_taken != -1 and taken != -1)
    {
        return dp[level][sum_left] = min(not_taken, taken);
    }
}

void solve()
{
    cin >> n >> x;
    input(arr, n);

    // for (int i = 0; i < n + 1; i++)
    // {
    //     loop(j, 0, x + 1)
    //     {
    //         dp[i][j] = -2;
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
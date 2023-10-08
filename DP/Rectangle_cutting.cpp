
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
ll dp[1000003];

int rec(int sum_left)
{

    if (sum_left == 0)
    {
        return 1;
    }

    if (sum_left < 0)
    {
        return 0;
    }

    if (dp[sum_left] != -1)
    {
        return (dp[sum_left] % MOD);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sum_left)
        {
            ans += rec(sum_left - arr[i]);
        }
    }
    return dp[sum_left] = (ans % MOD);
}

void solve()
{
    cin >> n >> x;
    input(arr, n);

    for(int i=0;i<=x;i++)
    {
        dp[i]=-1;
    }
    cout << (rec(x)%MOD) << en;
    // cout << iter() << en;
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
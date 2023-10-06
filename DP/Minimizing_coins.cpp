//***************************** JAI SHREE RAM**********************************//
 
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
#define loop(i, st, end) for (ll i = st; i < end; i++)
#define revloop(i, st, end) for (ll i = st; i >= end; i--)
#define all(arr) arr.begin(), arr.end()
#define pb emplace_back
#define en "\n"
#define input(arr, n) \
    loop(i, 0, n) { cin >> arr[i]; }
#define output(arr, n) \
    loop(i, 0, n) { cout << arr[i] << " "; }
 
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}
ll setbits(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans++;
        x = x & (x - 1);
    }
    return ans;
}
 
ll ncr(ll n, ll r)
{
 
    ll sum = 1;
    for (ll i = 0; i < r; i++)
    {
        sum *= (n - i);
        sum *= (1 / (i + 1));
    }
    return sum;
}
 
ll dp[1000000+1];
 
ll rec(ll &n,ll level)
{   

}
 
void solve()
{
ll n;
cin>>n;

}
 
int main()
{
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}
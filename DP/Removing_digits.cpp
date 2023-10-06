
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
int arr[1001];
ll dp[1000003];

int rec(int n)
{
  if(n==0){return 0;}
  string s=to_string(n);
  int ans=1e9+7;

  if(dp[n] !=-1){return dp[n];}

  for(int i=0;i<s.length();i++)
  {
    if(s[i] !='0')
    {ans=min(ans,1+rec(n-(s[i]-'0')));}
  }
  return dp[n]=ans;
}

void solve()
{
    cin >> n ;  
    for(int i=0;i<=n;i++){dp[i]=-1;}
    cout << (rec(n)) << en;

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
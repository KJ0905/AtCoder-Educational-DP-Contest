#include<bits/stdc++.h>
//#include <math>
//#include <string>
using namespace std;
#define ll long long
#define ld long double
#define forn(j,m) for(int i=j;i<m;i++)
int mini=INT_MAX;
int maxi=INT_MIN;
ll lmini=INT64_MAX;
ll lmaxi=INT64_MIN;
#define mod 1000000007
#define inf 1e9
//freopen("guess.in","r",stdin);   freopen("billboard.out","w",stdout);
#define all(x) (x).begin(), (x).end()  //sort(all(vec)) instead of sort(vec.begin(), vec.end()).
#define al(x,n) x,x+n
#define KUNAL ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){
    int n; cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    vector<vector<int>> dp(1,vector<int>(3));
    dp[0][0]=v[0][0],dp[0][1]=v[0][1],dp[0][2]=v[0][2];
    for(int i=1;i<n;i++){
        int prev1=dp[0][0],prev2=dp[0][1],prev3=dp[0][2];
        dp[0][0]=max(prev2,prev3)+v[i][0];
        dp[0][1]=max(prev1,prev3)+v[i][1];
        dp[0][2]=max(prev1,prev2)+v[i][2];
    }
    cout<<max({dp[0][0],dp[0][1],dp[0][2]})<<endl;
}
int main(){
    KUNAL
        solve();
}

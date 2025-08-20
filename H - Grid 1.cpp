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
    int r,c; cin>>r>>c;
    vector<vector<ll>>dp(r+1,vector<ll>(c+1));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            char c; cin>>c;
            if(c=='.'){dp[i][j]=-1;}
        }
    }
    dp[1][1]=1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(dp[i][j]==-1){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[r][c]<<endl;
}
int main(){
    KUNAL
        solve();
}

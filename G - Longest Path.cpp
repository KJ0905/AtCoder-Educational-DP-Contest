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

vector<int>dp;
vector<bool>vis;

void dfs(int node,vector<vector<int>>&adj){
    vis[node]=true;
    for(auto val:adj[node]){
        if(vis[val]){
            dp[node]=max(dp[node],1+dp[val]);
        }
        else{
            dfs(val,adj);
            dp[node]=max(dp[node],1+dp[val]);
        }
    }
    return;
}
void solve(){
    int n,m; cin>>n>>m;
    dp=vector<int>(n+1);
    vis=vector<bool>(n+1);
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}
int main(){
    KUNAL
        solve();
}

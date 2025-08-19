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
    int n,k; cin>>n>>k;
    int arr[n];
    forn(0,n){cin>>arr[i];}
    vector<int>dp(n);
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        dp[i]=inf;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int a=dp[i-j]+abs(arr[i]-arr[i-j]);
                dp[i]=min(a,dp[i]);
            }
        }
    }
    cout<<dp[n-1]<<endl;
}
int main(){
    KUNAL
        solve();
}

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
	vector<double>c(n);
	forn(0,n){
		cin>>c[i];
	}
	vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j==0){
				dp[i][j]=dp[i-1][j]*(1-c[i-1]);
			}
			else{
				dp[i][j]=dp[i-1][j]*(1-c[i-1])+dp[i-1][j-1]*(c[i-1]);
			}
		}
	}
	double ans=0.0;
	for(int j=0;j<=n;j++){
		if(j>=((n/2)+1)){ans+=dp[n][j];}
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}
int main(){
	KUNAL;
	solve();
}

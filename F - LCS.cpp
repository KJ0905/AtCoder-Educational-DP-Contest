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
    string s1,s2; cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[j-1]==s2[i-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string t; int i=m,j=n;
    while(i!=0 && j!=0){
        if(i-1<0 || j-1<0){break;}
        if(s1[j-1]==s2[i-1] && i-1>=0 && j-1>=0){
            t.push_back(s1[j-1]);
            i--,j--;
        }
        else{
            if(i-1<0 || j-1<0){
                break;
            }
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    for(int i=0;i<(int)t.size();i++){
        cout<<t[t.size()-i-1];
    }cout<<endl;

}
int main(){
    KUNAL
        solve();
}

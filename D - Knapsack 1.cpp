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
    ll n,weigh; cin>>n>>weigh;
    vector<pair<ll,ll>>val(n);
    for(ll i=0;i<n;i++){
        cin>>val[i].first>>val[i].second;
    }
    vector<ll>dpprev(weigh+1),dpcurr(weigh+1);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=weigh;j++){
                dpcurr[j]=dpprev[j];
            if(j-val[i].first>=0){
                dpcurr[j]=max(dpcurr[j],dpprev[j-val[i].first]+val[i].second);
            }
        }
        dpprev=dpcurr;
    }
    ll ans=0;
    for(ll i=0;i<=weigh;i++){
        ans=max(ans,dpcurr[i]);
    }
    cout<<ans<<endl;
}
int main(){
    KUNAL
        solve();
}

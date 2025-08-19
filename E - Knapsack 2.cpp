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
    vector<ll>mwprev(1e5+1,INT_MAX),mwcurr(1e5+1,INT_MAX);
    vector<bool>dpprev(1e5+1),dpcurr(1e5+1);
    mwprev[0]=0;
    dpprev[0]=true;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<1e5+1;j++){
            if(dpprev[j]){
                dpcurr[j]=true;
                mwcurr[j]=min(mwprev[j],mwcurr[j]);
            }
            if(j-val[i].second>=0 && dpprev[j-val[i].second] && mwprev[j-val[i].second]+val[i].first<=weigh){
                dpcurr[j]=true;
                mwcurr[j]=min(mwcurr[j],mwprev[j-val[i].second]+val[i].first);
            }
        }
        dpprev=dpcurr;
        mwprev=mwcurr;
    }
    int ans=0;
    for(int i=0;i<1e5+1;i++){
        if(dpcurr[i]){
            ans=i;
        }
    }
   cout<<ans<<endl;
}
int main(){
    KUNAL
        solve();
}

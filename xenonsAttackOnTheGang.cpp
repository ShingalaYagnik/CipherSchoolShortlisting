#include<bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.begin(),v.end()
#define sz(x) (int)sz.size()
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define what(x) cout<<#x<<" is "<<x<<endl;
using namespace std;
#define int long long
#ifdef LOCAL//ONLINE_JUDGE
#include "D:\c_c++\template.h"
#else
#define debug(...) 42
#endif

ll powmod(ll a,ll b,ll mod) {
    ll res=1;a%=mod;
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;
			a=a*a%mod;
    }
    return res;
}
const int mxn = 3003;
int n,root;
vector<int> g[mxn];
int h[mxn];
int sub[mxn][mxn],par[mxn][mxn],dp[mxn][mxn];

void dfs(int u,int p=-1){
	sub[root][u]=1;
	for(int it:g[u]){
		if(it==p)continue;
		par[root][it]=u;
		dfs(it,u);
		sub[root][u]+=sub[root][it];
	}
}


int DP(int u,int v){
	if(v==u)return 0;
	int &res=dp[u][v];
	if(~res)return res;
	return dp[u][v]=sub[u][v]*sub[v][u]+max(DP(par[v][u],v),DP(par[u][v],u));
}

void solve(){
	cin>>n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=0;i<n;i++)root=i,dfs(i);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=-1;
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
				ans=max(ans,DP(i,j));
		}
	cout<<ans<<'\n';
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    #ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int tc=1;
    // cin>>tc;
    while(tc--)solve();
}

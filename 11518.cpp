#include <bits/stdc++.h>

using namespace std;

int vis[10001];
int cont;

void dfs(int v, vector<vector<int>>&adj){
	
	vis[v]=true;
	
	for(int h : adj[v]){
		if(!vis[h]){
			dfs(h, adj);
			cont++;
		}
	}
}

int main(){
	
	int o, ve, e, l, i, k, a, b;
	cin >> o;
	while(o--){
		
		cin >> ve >> e >> l;
		vector<vector<int>>adj(10001);	
		memset(vis, false, sizeof vis);
		cont=0;
		for(i=0; i<e; i++){
			cin >> a >> b;
			a--; b--;
			adj[a].push_back(b);
		}
		for(i=0; i<l; i++){
			cin >> k;
			k--;
			if(!vis[k]){
				cont++;
				dfs(k, adj);
			}
		}
		cout << cont << endl;
	}
}

#include <bits/stdc++.h>
		
using namespace std;
		
vector<vector<int>>adj(100100);
stack<int>pilha;

bool vis[100100];
		
void dfs(int v){
	
	vis[v]=true;
	for(int a : adj[v]){
		if(!vis[a]){
			dfs(a);
		}
	}
	pilha.push(v);
}

void dfs1(int v){
	
	vis[v]=true;
	for(int a : adj[v]){
		if(!vis[a]){
			dfs1(a);
		}
	}
}
		
int main(){
	
	//freopen("in.txt", "w", stdout);
	int o, n, e, a, b, cont;
	
	cin >> o;
	while(o--){
		
		cont=0;
		cin >> n >> e;
		adj = vector<vector<int>>(n+1);
		while(e--){
			cin >> a >> b;
			adj[a].push_back(b);
		}
		memset(vis, false, sizeof vis);
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				dfs(i);
			}
		}
		memset(vis, false, sizeof vis);
		while(!pilha.empty()){
			
			int u = pilha.top();
			pilha.pop();
			
			if(!vis[u]){
				dfs1(u);
				cont++;
			}
		}
		cout << cont << endl;
	}
}

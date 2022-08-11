#include <bits/stdc++.h>
		
using namespace std;
		
vector<vector<int>>adj(10010);
vector<vector<int>>adj1(10010);
stack<int>pilha;

bool vis[10010];
		
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
	
	//freopen("asd.txt", "w", stdout);
	int o, n, e, a, b, cont, round=1;
	string lix;
	cin >> o;
	while(o--){
		
		cont=0;
		cin >> n >> e;
		adj = vector<vector<int>>(n+1);
		adj1 = vector<vector<int>>(n+1);
		while(e--){
			cin >> a >> b;
			adj[a].push_back(b);
			adj1[b].push_back(a);
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
		cout << "Case " << round << ": " << cont << endl;
		round++;
	}
}	

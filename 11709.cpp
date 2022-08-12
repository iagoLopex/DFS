#include <bits/stdc++.h>

using namespace std;

stack<int>pilha;
vector<vector<int>>adj(1010);
vector<vector<int>>adj1(1010);

bool vis[1010];
int cont;

void dfs(int v){
	
	vis[v]=true;
	for(auto i: adj[v]){
		if(!vis[i]){
			dfs(i);
		}
	}
	pilha.push(v);
}

void dfs1(int v){
	
	vis[v]=true;
	for(auto i: adj1[v]){
		if(!vis[i]){
			dfs1(i);
		}
	}
}

int main(){
	
	
	int n, e;
	cin >> n >> e;
	while(n || e){
		
		string a, b;
		cont=0;
		
		adj = vector<vector<int>>(n+1);
		adj1 = vector<vector<int>>(n+1);
		
		map<string, int>mapa;
		map<string, int>::iterator it;
		cin.ignore();
		for(int i=0; i<n; i++){
			getline(cin, a);
			mapa[a] = i;
		}
		//cin.ignore();
		//e = (e<<1);
		for(int i=0; i<e; i++){
			getline(cin, a);
			getline(cin, b);

			adj[mapa[a]].push_back(mapa[b]);
			adj1[mapa[b]].push_back(mapa[a]);
		}
		
		memset(vis, false, sizeof vis);
		for(int i=0; i<n; i++){
			if(!vis[i]){
				dfs(i);
			}
		}
		memset(vis, false, sizeof vis);
		while(!pilha.empty()){
			
			int u = pilha.top(); pilha.pop();
			
			if(!vis[u]){
				dfs1(u);
				cont++;
			}
		}
		cout << cont << endl;

		cin >> n >> e;
	}
	
}

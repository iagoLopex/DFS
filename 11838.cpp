#include <bits/stdc++.h>
            
using namespace std;

bool vis[10000];
stack<int>pilha;

void dfs1(int v, vector<vector<int>>&adj1){
	
	vis[v] = true;
	for(int j: adj1[v]){
		if(!vis[j]){
			dfs1(j, adj1);
		}
	}
	pilha.push(v);
}

void dfs2(int v, vector<vector<int>>&adj2){
	
	vis[v] = true;
	for(int j: adj2[v]){
		if(!vis[j]){
			dfs2(j, adj2);
		}
	}
}

int main(){
	
	int v, e, i, a, b, cont, type;
	
	cin >> v >> e;
	while(v || e){
		
		vector<vector<int>>adj1(v);
		vector<vector<int>>adj2(v);
			
		for(i=0; i<e; i++){
			
			cin >> a >> b >> type;
			a--; b--;
			adj1[a].push_back(b);
			adj2[b].push_back(a);
			
			//caminho de volta
			if(type == 2){
				adj1[b].push_back(a);
				adj2[a].push_back(b);
			}
		}
		
		memset(vis, false, sizeof vis);
		for(i=0; i<adj1.size(); i++){
			if(!vis[i]){
				dfs1(i, adj1);
			}
		}
		memset(vis, false, sizeof vis);
		cont=0;
		while(!pilha.empty()){
			int u = pilha.top(); pilha.pop();
			//cout << "topo : " << u << endl;
			if(!vis[u]){
				dfs2(u, adj2);
				cont++;
			}
		}
		cout << ((cont==1) ? 1 : 0) << endl;
		cin >> v >> e;
	}
}       

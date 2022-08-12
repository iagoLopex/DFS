#include <bits/stdc++.h>

using namespace std;

vector<pair<string, string>>vec;
vector<string> ans;
stack<int>pilha;
vector<vector<int>>adj(30);
vector<vector<int>>adj1(30);

map<int, string>rmapa;

bool vis[30];

void dfs(int v){
	
	vis[v]=true;
	for(auto w: adj[v]){
		if(!vis[w]){
			dfs(w);
		}
	}
	pilha.push(v);
}

void dfs1(int v){
		
	vis[v]=true;
	ans.push_back(rmapa[v]);
	for(auto w: adj1[v]){
		if(!vis[w]){
			dfs1(w);
		}
	}
}

int main (){
	
	map<string, int>::iterator it;
	int cont, n, e, ok=0;
	bool p=false;
	string a, b;
	
	cin >> n >> e;
	while(n || e){
		
		if(p) cout << endl;
		
		p=true;
		map<string, int>mapa;
		
		adj = vector<vector<int>>(n);
		adj1 = vector<vector<int>>(n);
		rmapa.clear();
		vec.clear();
		
		cont = 0;
		for(int i=0; i<e; i++){
			
			cin >> a >> b;
			vec.push_back({a,b});
			
			it = mapa.find(a);
			if(it == mapa.end()){
				mapa[a] = cont;
				rmapa[cont] = a;
				cont++;
			}
			
			it = mapa.find(b);
			if(it == mapa.end()){
				mapa[b] = cont;
				rmapa[cont] = b;
				cont++;
			}
			
		}
		for(int i=0; i<vec.size(); i++){
			adj[mapa[vec[i].first]].push_back(mapa[vec[i].second]);
			adj1[mapa[vec[i].second]].push_back(mapa[vec[i].first]);
		}
		memset(vis, false, sizeof vis);
		for(int i=0; i<n; i++){
			if(!vis[i]){
				dfs(i);
			}
		}
		memset(vis, false, sizeof vis);
		ok++;
		cout << "Calling circles for data set " << ok << ":\n";
		while(!pilha.empty()){
			
			int u = pilha.top(); pilha.pop();
			ans.clear();
			if(!vis[u]){
				dfs1(u);
				cout << ans[0];
				for(int i = 1; i < ans.size(); i++) {
					cout << ", " << ans[i];
				}
				cout << "\n";
			}
		}
		
		cin >> n >> e;
	}
}

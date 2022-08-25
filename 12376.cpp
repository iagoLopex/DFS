#include <bits/stdc++.h>
using namespace std;

int valor[110];
int vis[110];
int soma;
vector<vector<int>>adj(110);
int ind;
int ultimo;

void dfs(int v){
	
	vis[v]=true;
	int maior=-1;
	
	for(int i: adj[v]){

		if(maior < valor[i]){
			maior = valor[i];
			ind = i;
		}
	}

	//valido o melhor caminho
	if(!vis[ind]){
		
		soma+=maior;
		ultimo=ind;
		dfs(ind);
	}
}

int main(){
	
	int o, n, e, a, b, round=0;
	string lix;
	cin>>o;
	while(o--){
		
		getline(cin, lix);
		memset(vis, false, sizeof vis);
		cin >> n >> e;
		adj = vector<vector<int>>(n);
		for(int i=0; i<n; i++){
			cin >> valor[i];
		}
		for(int i=0; i<e; i++){
			cin >> a >> b;
			adj[a].push_back(b);
		}
		round++;
		soma=0;
		dfs(0);
		cout<<"Case " << round << ": " <<soma<<" "<<ultimo<<endl;
	}
}

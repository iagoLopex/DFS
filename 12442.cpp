#include <bits/stdc++.h>

using namespace std;

bool vis[50100];
bool Ppai[50100];
vector<vector<int>>adj;
int cont;

void dfs(int v){
	vis[v]=true;
	for(int i: adj[v]){
		if(!vis[i]){
			cont++;
			dfs(i);
		}
	}
	vis[v]=false;
	Ppai[v]=true;
}

int main(){
	
	int o,n, a, b, count=0;
	cin >>o;
	memset(vis, false, sizeof vis);
	while(o--){
		count++;
		cin >> n;
		adj = vector<vector<int>>(n+1);
		memset(Ppai, false, sizeof Ppai);
		for(int i=0; i<n; i++){
			cin >> a >> b;
			adj[a].push_back(b);
		}
		int maior=-1, index;
		for(int i=1; i<=n; i++){
			if(!Ppai[i]){
				cont=1;
				dfs(i);
				if(maior<cont){
					maior = cont;
					index = i;
				}
			}
		}
		cout <<"Case " << count << ": " << index << endl;
	}
}

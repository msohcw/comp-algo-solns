#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;

long long n,x,y;

int edges[200010];
vector< vector<int> > adj;
int used[200010];
long breaks = 0;

int dfs(int v){
	if(used[v]) return 0;
	used[v] = true;
	int count = 0;
	for(int i = 0; i < adj[v].size(); i++) count += dfs(adj[v][i]);
	if(count <= 1) return 1;
	breaks += count - 2;
	if(v != 0) breaks++;
	return 0;
}

int main(){
	cin >> n;
	cin >> x;
	cin >> y;
	vector<int> empty;
	for(int i = 0; i < n; i++) adj.push_back(empty);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d%d", &a,&b);
		a--;
		b--;
		edges[a]++;
		edges[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	long long min_cost;

	if(x == y){
		min_cost = x * (n-1);
	}else if(x > y){
		//avoid st
		bool star = false;
		for(int i = 0; i < n; i++){
			if(edges[i] == n-1){
				star = true;
				break;
			}
		}
		min_cost = (star)? y * (n-2) + x : y * (n-1);
	}else{ //x < y use the mst
		breaks = 0;
		dfs(0);
		min_cost = y * breaks + x * (n - 1 - breaks); 
	}
	cout << min_cost << endl;
}
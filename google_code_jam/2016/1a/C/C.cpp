#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>

#define INF 2000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

int N;
int adj[1010];
// int inv_adj[1010];
bool visited[1010];
int maxlen;
int t_bff[1010];
int t_cycles;

ii dfs(int p){
	if(visited[p]){
		return make_pair(1,p);
	}else{
		visited[p] = true;
		ii ret = dfs(adj[p]);
		if(ret.second == p){
			maxlen = max(ret.first, maxlen);
			if(ret.first == 2){ //2cycle
				t_bff[p] = adj[p];
				t_bff[adj[p]] = p;
				t_cycles++;
			}
			return make_pair(0,0);
		}else{
			ret.first++;
			return ret;
		}
	}
}

int dfs_from(int p, int d, int b){
	if(p == b) return 0;
	if(visited[p]){
		return d;
	}else{
		visited[p] = true;
		int max_d = d;
		for(int i = 1; i <= N; i++){
			if(adj[i] == p){
				max_d = max(max_d, dfs_from(i, d+1, b));
			}
		}
		return max_d;
	}
}

int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);
		scanf("%d", &N);
		memset(adj, 0, sizeof(adj));
		for(int i = 1; i <= N; i++){
			scanf("%d", &adj[i]);
		}

		maxlen = 0;
		
		memset(t_bff, 0, sizeof(t_bff));
		memset(visited, 0, sizeof(visited));
		
		for(int i = 1; i <= N ;i++){
			if(visited[i]) continue;
			dfs(i);
		}

		if(t_cycles > 0){			
			memset(visited, 0, sizeof(visited));
			int combine = 0;

			for(int i = 1; i <= N; i++)  if(t_bff[i] > 0) combine+= dfs_from(i, 1, t_bff[i]);
			maxlen = max(combine, maxlen);
		}
		printf("%d\n", maxlen);
	}
}
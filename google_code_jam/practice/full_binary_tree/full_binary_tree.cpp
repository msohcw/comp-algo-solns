#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 2000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

int N;
int adj[1010][1010];
int memo[1010][1010];
bool memo_md[1010][1010];
int md[1010][1010];

int weight(int p, int n){
	// printf("w %d %d \n", p, n);
	if(memo[p][n] > 0) return memo[p][n];
	
	int total = 1;
	for(int i = 1; i <= N; i++){
		if(i == p) continue;
		if(adj[n][i]) total+= weight(n, i);
	}
	return total;
}

int min_del(int p, int n){
	// printf("md %d %d \n", p, n);
	if(p > 0 && memo_md[p][n]) return md[p][n];
	
	vii children;
	
	for(int i = 1; i <= N; i++){
		if(i == p) continue;
		if(adj[n][i]) children.push_back(make_pair(min_del(n,i), i));		
	}

	sort(children.begin(), children.end());
	reverse(children.begin(), children.end());
	
	int ret;

	if(children.size() == 0){
		ret = 0;
	}else if(children.size() == 1){
		ret = weight(n, children[0].second);
	}else{
		ret = min_del(n, children[0].second) + min_del(n, children[1].second);
		for(int i = 2; i < children.size(); i++) ret+= children[i].first;
	}
	
	memo_md[p][n] = true;
	md[p][n] = ret;
	
	return ret;
}

int max_keep(int p, int n){
	vii children;
	
	for(int i = 1; i <= N; i++){
		if(i == p) continue;
		if(adj[n][i]) children.push_back(make_pair(max_keep(n,i), i));		
	}

	sort(children.begin(), children.end());
	reverse(children.begin(), children.end());
	
	int ret;

	if(children.size() == 0 || children.size() == 1){
		ret = 1;
	}else{
		ret = children[0].first + children[1].first + 1;
	}
	return ret;
}


int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);

		scanf("%d", &N);
		
		memset(adj, 0, sizeof(adj));
		memset(memo, 0, sizeof(memo));
		memset(memo_md, 0, sizeof(memo_md));
		memset(md, 0, sizeof(md));
		
		for(int i = 0; i < N-1; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a][b] = adj[b][a] = 1;
		}

		int _min = N;
		
		for(int i = 1; i <= N; i++) _min = min(N - max_keep(-1,i), _min);

		printf("%d\n", _min);
	}
}
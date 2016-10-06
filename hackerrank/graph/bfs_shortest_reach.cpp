#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define I18F 1000000000000000000 // 10^18
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int Q, N, M;

int main(){
  scanf("%d", &Q);
  for(int kt = 0; kt < Q; ++kt){
    scanf("%d%d", &N, &M);
    vi adj[1010];
    int visited[1010];
    memset(visited, MEMSET_INF, sizeof(visited));
    
    for(int i = 0; i < M; ++i){
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    int s;
    scanf("%d", &s);
    s--;
    queue<ii> Q;
    Q.push(make_pair(s, 0));

    while(!Q.empty()){
      ii top = Q.front();
      int at = top.first;
      int d = top.second;
      Q.pop();
      if(visited[at] < N) continue;
      visited[at] = d;
      for(int i = 0; i < adj[at].size(); ++i){
        Q.push(make_pair(adj[at][i], d + 1));
      }
    }
    
    for(int i = 0; i < N; ++i){
      if(i == s) continue;
      visited[i] = (visited[i] > N) ? -1 : visited[i] * 6;
      printf("%d ", visited[i]);
    }
    printf("\n");
  }
}

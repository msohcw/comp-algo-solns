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
#define MEMSET_INF 127 // about 2B
#define INF 2139062143 // value of MEMSET_INF
#define MEMSET_HALF_INF 63 // about 1B

int Q, N, M;

int main(){
  scanf("%d", &Q);
  for(int kt = 0; kt < Q; ++kt){
    scanf("%d%d", &N, &M);
    vector<iii> adj;
    int visited[3010];
    memset(visited, MEMSET_INF, sizeof(visited));

    for(int i = 0; i < M; ++i){
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w);
      a--;
      b--;
      adj.push_back(make_pair(make_pair(a, b), w));
      adj.push_back(make_pair(make_pair(b, a), w));
    }
    
    sort(adj.begin(), adj.end());

    int s;
    scanf("%d", &s);
    s--;
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    Q.push(make_pair(0, s));

    while(!Q.empty()){
      ii top = Q.top();
      int at = top.second;
      int d = top.first;
      Q.pop();

      if(visited[at] != INF) continue;
      visited[at] = d;
      
      int adj_start = lower_bound(adj.begin(), adj.end(), make_pair(make_pair(at,0),0)) - adj.begin();

      for(int i = adj_start; i < adj.size(); ++i){
        if(adj[i].first.first != at) break;
        Q.push(make_pair(d + adj[i].second, adj[i].first.second));
      }
    }
    
    for(int i = 0; i < N; ++i){
      if(i == s) continue;
      visited[i] = (visited[i] == INF) ? -1 : visited[i];
      printf("%d ", visited[i]);
    }
    printf("\n");
  }
}

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
typedef pair<int, pair<int, int> > i_ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int P, T;
priority_queue<ii, vii, greater<ii> > Q;
ii p[10010];
int visited[10010];
vector<ii> trail[10010];
int ct[10000][10000];
int used[10000][10000];

int dist;

void augment(int at){
  //printf("augmenting %d, %d, %d\n", at, p[at].second, p[at].first);
  if(at == 0) return;
  used[p[at].first][at] = true;
  augment(p[at].first);
}

void dfs(int at, int rem){
  if(rem < 0) return;
  if(at == P-1 && rem == 0){
    augment(P-1);
  }else{
    visited[at] = true;
    for(int i = 0; i < trail[at].size(); ++i){
      int next = trail[at][i].first;
      if(next >= P) continue;
      if(visited[next]) continue;
      p[next] = make_pair(at, i);
      dfs(next, rem - trail[at][i].second);
    }
  }
}

int main(){
  memset(p, 0, sizeof(p));
  memset(visited, 0, sizeof(visited));
  memset(ct, 0, sizeof(ct));
  memset(used, 0, sizeof(used));
  scanf("%d%d", &P, &T);

  for(int i = 0; i < T; ++i){
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    trail[a].push_back(make_pair(b, w));
    trail[b].push_back(make_pair(a, w));
  }
  
  for(int i = 0; i < P; ++i){
    for(int j = 1; j < trail[i].size(); ++j){
      if(trail[i][j].second == trail[i][j-1].second) ct[i][j] += ct[i][j-1] + 1;
      trail[i][j-1].first = P;
      trail[i][j].second = trail[i][j-1].second;
    }
  }
  

  Q.push(make_pair(0, 0));
  while(!Q.empty()){
    ii top = Q.top();
    Q.pop();
    if(top.second == P-1){
      dist = top.first;
      break;
    }else{
      for(int i = 0; i < trail[top.second].size(); ++i){
        ii t = trail[top.second][i];
        if(t.first >= P) continue;
        Q.push(make_pair(t.second + top.first, t.first));
      }
    }
  }

  printf("%d\n", dist); 
  dfs(0, dist);
  int cost = 0;
  for(int i = 0; i < P; ++i){
    for(int j = 0; j < trail[i].size(); ++j){
      if(used[i][j]) cost += 2 * trail[i][j].second * (ct[i][j]+1);
    }
  }
  printf("%d\n", cost);
}

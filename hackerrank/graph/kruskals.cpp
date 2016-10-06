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
typedef pair<int, pair<int, int> > i_ii;
typedef pair<pair<int, int>, int> ii_i;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define I18F 1000000000000000000 // 10^18
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, M;
priority_queue<i_ii, vector<i_ii>, greater<i_ii> > Q;
int weight = 0;
int parent[5000];

int find(int a){
  if(a == parent[a]) return a;
  parent[a] = find(parent[a]);
  return parent[a];
}

void join(int a, int b){
  parent[find(a)] = parent[find(b)];
}

int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i) parent[i] = i;
  for(int i = 0; i < M; ++i){
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    a--;
    b--;
    Q.push(make_pair(w,make_pair(a,b)));
  }
 
  int s;
  scanf("%d", &s);
  s--;
  
  int edges = 0;

  while(!Q.empty() && edges < N-1){
    i_ii top = Q.top();
    Q.pop();

    int a, b, w;
    w = top.first;
    a = top.second.first;
    b = top.second.second;
    
    if(find(a) == find(b)) continue;
    weight += w;
    join(a,b);
    edges++;  
  }
  printf("%d\n", weight);
}

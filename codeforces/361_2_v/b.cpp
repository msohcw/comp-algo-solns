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

#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N;
int G[200010];
int d[200010];
bool visited[200010];
queue<int> Q;

int main(){
    scanf("%d", &N);
      for(int i = 0; i < N; ++i){
          d[i] = i;
          scanf("%d", &G[i]);
          G[i]-=1;
      }
      d[0] = 0;
      memset(visited, 0, sizeof(visited));
      Q.push(0);
      while(!Q.empty()){
        int at = Q.front();
        Q.pop();
        if(visited[at]) continue;
        visited[at] = true;
        if(at > 0){
          d[at-1] = min(d[at]+1,d[at-1]);
          Q.push(at-1);
        }
        if(at < N-1){
          d[at+1] = min(d[at]+1,d[at+1]);
          Q.push(at+1);
        }
        d[G[at]] = min(d[at]+1,d[G[at]]);
        Q.push(G[at]);
      }
      for(int i = 0; i < N; ++i) printf("%d ", d[i]);
      printf("\n");
}

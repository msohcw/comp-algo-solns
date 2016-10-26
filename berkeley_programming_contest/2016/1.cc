#include "contest.h"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <stdarg.h>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define I18F 1000000000000000000 // 10^18
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, r1, c1, r2, c2;

int moves[8][2] = { {1,-2}, {2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1}, {-1, -2}};

bool check(int a, int b){
  if(a < 0 || b < 0) return false;
  if(a >= N || b >= N) return false;
  return true;
}

int main(){
  while(scanf("%d", &N) != EOF){
    queue<iii> Q;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    Q.push(make_pair(make_pair(r1, c1), 0));
    int visited[1010][1010];
    memset(visited, 0, sizeof(visited));
    int dist = -1;
    while(!Q.empty()){
      iii top = Q.front();
      Q.pop();
      int r = top.first.first;
      int c = top.first.second;
      if(visited[r][c] != 0) continue;
      visited[r][c] = 1;
      if(r == r2 && c == c2){
        dist = top.second;
        break;
      }
      for(int i = 0; i < 8; ++i){
        if(check(r + moves[i][0], c + moves[i][1])) Q.push(make_pair(make_pair(r+moves[i][0], c+moves[i][1]),top.second+1));
      }
      printf("dist is %d\n", dist);
    }
    printf("%d\n", dist);
  }
}

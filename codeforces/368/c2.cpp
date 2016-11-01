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
#define INF18 1000000000000000000

int N;
queue<pair<pair<ll, ll>, ll> > Q;
ll total = 0;
int dir[3][3][3] = {{{1,-2,2},{2,-1,2},{2,-2,3}},{{1,2,2},{2,1,2},{2,2,3}},{{-1,2,2},{-2,1,2},{-2,2,3}}};
int main(){
  scanf("%d", &N);
  Q.push(make_pair(make_pair(3, 4), 5));
                    
  while(!Q.empty()){
    pair<pair<ll,ll>,ll> top = Q.front();
    Q.pop();
    ll A,B,H;
    A  = top.first.first;
    B = top.first.second;
    H = top.second;
    for(int i = 0; i < 3; ++i){
      ll a,b, h;
      a = A * dir[i][0][0] + B * dir[i][0][1] + H * dir[i][0][2];
      b = A * dir[i][1][0] + B * dir[i][1][1] + H * dir[i][1][2];
      h = A * dir[i][2][0] + B * dir[i][2][1] + H * dir[i][2][2];
      if(a > INF18 || b > INF18 || h  > INF18) continue;
      Q.push(make_pair(make_pair(a,b),h));
      total++;
      printf("%lld : %lld %lld %lld\n", total, a, b, h);
    }
  }
  printf("%lld\n", total);
}

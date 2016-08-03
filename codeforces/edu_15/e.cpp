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

ll N,K;

struct f {
  ll min, len, to;
};

f b0[100010];
f b1[100010];
f ret[100010];

int main(){
  scanf("%lld %lld", &N, &K);
  int a;
  memset(b0, 0, sizeof(b0));
  memset(b1, 0, sizeof(b1));
  memset(ret, 0, sizeof(ret));
  for(int i = 0; i < N; ++i){
    scanf("%d", &a);
    b1[i].to = b0[i].to = a;
    ret[i].to = i;
  }
  for(int i = 0; i < N; ++i){
    scanf("%d", &a);
    b1[i].len = b1[i].min = b0[i].len = b0[i].min = a;
    ret[i].min = INF;
  }
  int ct = 0;
  while(K >> ct > 0){
    for(int i = 0; i < N; ++i){
      if(ct == 0) break; //alr in b0, b1
      b1[i].len += b0[b0[i].to].len;
      b1[i].min = min(b0[i].min, b0[b0[i].to].min);
      b1[i].to = b0[b0[i].to].to;
    }
    for(int i = 0; i < N; ++i) b0[i] = b1[i];
    for(int i = 0; i < N; ++i){
      if((K >> ct) & 1){
        ret[i].len += b0[ret[i].to].len;
        ret[i].min = min(ret[i].min, b0[ret[i].to].min);
        ret[i].to = b0[ret[i].to].to;
      }
    }
    ct++;
  }
  for(int i = 0; i < N; ++i) printf("%lld %lld\n", ret[i].len, ret[i].min);
}

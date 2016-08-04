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
#define LONG_INF 2000000000000000000
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

ll M, N;
ll s, e;
int main(){
  scanf("%lld", &M);
  s = 1;
  e = LONG_INF;
  N = LONG_INF;
  bool found = false;
  while(s < e){
    ll mid = (s+e)/2;
    ll ways = 0;
    for(ll i = 2; i < INF; i++){
      if((i*i*i) > mid) break;
      ways += mid/(i*i*i);
    }
    if(ways == M){
      N = min(mid, N);
      found = true;
    }
    if(ways >= M){
      e = mid;
    }else{
      s = mid+1;
    }
  }
  if(found){
    printf("%lld\n", N);
  }else{
    printf("-1\n");
  }
}

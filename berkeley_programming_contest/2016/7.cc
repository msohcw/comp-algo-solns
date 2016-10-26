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
typedef pair<int, pair<int, int> > iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define I18F 1000000000000000000 // 10^18
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, K;
vi row;
vi col;

int main(){
  scanf("%d%d", &N, &K);
  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    row.push_back(a);
  }
  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    col.push_back(a);
  }
  K = N*N - K;
  sort(row.begin(), row.end());
  sort(col.begin(), col.end());
  for(int i = 0; i < row.size(); ++i) printf("%d ", row[i]);
  printf("\n");
  for(int i = 0; i < col.size(); ++i) printf("%d ", col[i]);
  printf("\n");
  ll low, high, mid;
  low = row[0] * col[0];
  high = row[N-1] * col[N-1] + 1;
  ll ans = INF;
  while(low < high){
    mid = (low + high)/2;
    printf("%lld-%lld-%lld\n", low, mid, high); 
    ll ct = 0;
    for(int i = 0; i < row.size(); ++i){
      if(row[i] == 0){
        ct += col.size();
        continue;
      }
      ll stop = upper_bound(col.begin(), col.end(), (int)(mid/((ll) row[i]))) - col.begin();
      ct+= stop;
      //printf("taking %lld for %d\n", stop, row[i]);
    }
    printf("sum is %lld\n", ct);

    if(ct == K){     
      for(int i = 0; i < row.size(); ++i){
        int stop = upper_bound(col.begin(), col.end(), (int)(mid/((ll) row[i]))) - col.begin();
        printf("%d for %d\n", stop, row[i]);
        if(stop == col.size()) continue;
        ans = min(ans, (ll) row[i] * (ll) col[stop]);
      }
      break;
    }else{
      if(ct > K){
        high = mid;
      }else{
        low = mid+1;
      }
    }
  }
    if(ans == INF) ans = mid;
    printf("%lld\n", ans);
}

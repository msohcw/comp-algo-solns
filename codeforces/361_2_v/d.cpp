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
int maxi[200010];
int mini[200010];

int a_sparse[20][200010];
int b_sparse[20][200010];

int rmq(int l, int r){
  int diff = r-l+1;
  int msb = 0;
  while(diff >> msb > 0) msb++;
  //printf("msb: %d, l: %d, r:%d\n", msb, l, r-(1<<(msb-1))+1);
  return max(a_sparse[msb-1][l], a_sparse[msb-1][r-(1<<(msb-1))+1]) - min(b_sparse[msb-1][l],b_sparse[msb-1][r-(1<<(msb-1))+1]);
}

int main(){

  memset(a_sparse,0,sizeof(a_sparse));
  memset(b_sparse,127,sizeof(b_sparse));

  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", &maxi[i]);
    a_sparse[0][i] = maxi[i];
  }
  for(int i = 0; i < N; ++i){
    scanf("%d", &mini[i]);
    b_sparse[0][i] = mini[i];
  }
  int ct = 1;
  while (N >> ct > 0){
    int size = 1 << ct;
    for(int i = 0; i < (N-size+1); ++i){
      a_sparse[ct][i] = max(a_sparse[ct-1][i],a_sparse[ct-1][i+(1<<(ct-1))]);
      b_sparse[ct][i] = min(b_sparse[ct-1][i],b_sparse[ct-1][i+(1<<(ct-1))]);
      // printf("%d ", b_sparse[ct][i]);
    }
    // printf("\n");
    ct++;
  }

  int s, e;
  ll matches = 0;
  for(int i = 0; i < N;i++){
    s = i;
    e = N;
    int lower, upper;
    //lower
    while(s < e){
      int mid = (s+e)/2;
      if(rmq(i, mid) >= 0){
        e = mid;
      }else{
        s = mid+1;
      }
    }
    lower = s;
    //upper
    s = i;
    e = N;

    while(s < e){
      int mid = (s+e)/2;
      if(rmq(i, mid) <= 0){
        s = mid+1;
      }else{
        e = mid;
      }
    }
    upper = s;
    if(rmq(i, lower) == 0){
      //printf("match at %d - %d = %d\n", upper, lower, upper-lower);
      matches += upper - lower;
    }
    //printf("at l = %d, upper = %d, lower = %d\n", i, upper, lower);
  }
  printf("%lld\n", matches);
}

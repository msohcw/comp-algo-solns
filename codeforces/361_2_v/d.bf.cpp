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
ll matches = 0;
int a[1010];
int b[1010];

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &a[i]);
  for(int i = 0; i < N; i++) scanf("%d", &b[i]);
  for(int i = 0; i < N; i++){
    for(int j = i; j < N; j++){
      int mini = INF;
      int maxi = -INF;
      for(int k = i; k <= j; k++){
        mini = min(mini, b[k]);
        maxi = max(maxi, a[k]);
      }
      if(mini == maxi){
        printf("match at %d - %d\n", i, j);
        matches++;
      }
    }
  }
  printf("%lld\n", matches);
}

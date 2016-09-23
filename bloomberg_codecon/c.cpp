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

#define I18F 1000000000000000000 // 10^18
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N;
vi cakes;
int dp[110];

int main(){
  scanf("%d", &N);
  
  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    cakes.push_back(a);
    dp[i] = a;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 0; j < i; ++j){
      if(cakes[j] <= cakes[i]) dp[i] = max(dp[i], cakes[i] + dp[j]);
    }
  }

  int maxv = 0;
  for(int i = 0; i < N; ++i) maxv = max(dp[i], maxv);
  printf("%d\n", maxv);
}

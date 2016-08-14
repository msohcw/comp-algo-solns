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
int num[200];
int dp[200];
int init = 0;
int maxF = -1;

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", &num[i]);
    init += num[i];
    num[i] = (num[i] == 0) ? 1 : -1;
  }
  dp[0] = max(0,num[0]);
  for(int i = 1; i < N; ++i) dp[i] = max(0, num[i]+dp[i-1]);
  for(int i = 0; i < N; ++i) maxF = max(maxF, dp[i]);
  if(init == N) maxF = -1;
  printf("%d\n", maxF + init);
}

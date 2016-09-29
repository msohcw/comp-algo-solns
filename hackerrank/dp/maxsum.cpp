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

int T, N;
int main(){
  scanf("%d", &T);
  for(int tc = 0; tc < T; ++tc){
    scanf("%d", &N);
    int sum, maxsum, ctr;
    int maxval = -INF;
    sum = maxsum = ctr = 0;
    for(int i = 0; i < N; ++i){
      int a;
      scanf("%d", &a);
      maxval = max(maxval, a);
      if(a > 0) sum += a;
      ctr = max(0, ctr + a);
      maxsum = max(maxsum, ctr);
    }
    if(maxval < 0) sum = maxsum = maxval;
    printf("%d %d\n", maxsum, sum);
  }
}

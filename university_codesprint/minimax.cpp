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
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

ll mini = INF;
ll maxi = 0;
ll sum = 0;
int main(){
  for(int i = 0 ; i < 5; ++i){
    int a;
    scanf("%d", &a);
    maxi = max((ll) a, maxi);
    mini = min((ll) a, mini);
    sum += a;
  }
  printf("%lld %lld\n", sum - maxi, sum - mini);
}

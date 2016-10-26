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
typedef pair<pair<int, int>, int> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define I18F 1000000000000000000 // 10^18
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
#define EPS 0.0000000001

vi num;

int main(){
  int a;
  ll sum = 0;
  while(scanf("%d", &a) != EOF){
    num.push_back(a);
    sum += a;
  }
  double mean = double(sum) / double(num.size());
  double diff = INF;
  bool both = false;
  ii best;
  for(int i = 0; i < num.size(); ++i){
    double dist = abs(double(num[i] - mean));
    if(abs(dist - diff) < EPS){
      both = true;
      best.second = num[i];
    }else if(dist < diff){
      both = false;
      best.first = num[i];
      diff = dist;
    }
  }
  if(both){
    if(best.first > best.second){
      int a = best.first;
      best.first = best.second;
      best.second = a;
    }
    printf("%d %d\n", best.first, best.second);
  }else{
    printf("%d\n", best.first);
  }
}

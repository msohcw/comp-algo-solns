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

vi rows;
vi cols;
vector<ll> prod;
int N = 500;
int M = 1000;
int main(){
  srand(time(NULL));
  for(int i = 0; i < N; ++i){
    int a = rand() % M;
    int b = rand() % M;
    rows.push_back(a);
    cols.push_back(b);
  }
  for(int i = 0; i < rows.size(); ++i){
    for(int j = 0; j < cols.size(); ++j){
      ll p = rows[i];
      p *= (ll) cols[j];
      prod.push_back(p);
    }
  }
  sort(prod.begin(), prod.end());
  reverse(prod.begin(), prod.end());
  int K = rand() % prod.size();
  printf("%lld\n", prod[K]);
  printf("%d %d\n", N, K+1);
  for(int i = 0; i < rows.size(); ++i) printf("%d ", rows[i]);
  printf("\n");
  for(int j = 0; j < cols.size(); ++j) printf("%d ", cols[j]);
  printf("\n");
}

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

int N;
int ops = 0;
vi num;

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    num.push_back(a);
  }
  int min = 1;
  for(int i = 0; i < N; ++i){
    if(num[i] > min) ops++;
    if(num[i] == min) min++;
  }
  printf("%d\n", ops);
}

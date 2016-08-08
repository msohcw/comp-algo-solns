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

int main(){
  srand(time(NULL));
  // C
  printf("10000 100\n");
  int nots = 0;
  for(int i = 0; i < 10000; ++i){
    int type = rand() % 3 + 1;
    int ret;
    if(type == 1) nots++;
    if(type == 1 || type == 2) ret = rand() % 100 + 1;
    if(type == 3) ret = rand() % nots + 1;
    printf("%d %d\n", type, ret);
  }
}

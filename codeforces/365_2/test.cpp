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
  // B
  printf("1000 50\n");
  for(int i = 0; i < 1000; i++) printf("%d ", rand()%10000);
  printf("\n");
  for(int i = 1; i <= 50; ++i){
    printf("%d ", i*2-rand()%2);
  }
}

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
  printf("100000 100000 1000\n");
  for(int i = 0; i < 100000; ++i){
    int a = rand() % 100000 + 1;
    int b = rand() % 100000 + 1;
    if(a == b) b = a + 1;
    printf("%d %d %d\n", a, b, rand()%10000000);
  }
  for(int i = 0; i < 1000; ++i) printf("%d ", rand()%100000+1);
  printf("\n");
}

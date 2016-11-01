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

ll a, b, c;
int main(){
  cin >> a >> b >> c;
  ll low = min(min(a,b), c);
  
  if(low != 0){
    a -= low;
    b -= low;
    c -= low;
  }
  int at = 0;
  if(b > a){
    if(c > b){
      at = 2;
    }else{
      at = 1;
    }
  }else{
    if(c > a) at = 2;
  }

  ll missed = 0;
  ll lvls[3] = {a,b,c};
  lvls[at] -= 1;
  ll left = lvls[at];
  at = (at+1)%3;
  if(left > lvls[at]) missed += left - lvls[at];
  at = (at+1)%3;
  if(left > lvls[at]) missed += left - lvls[at];
  at = (at+1)%3;
  cout << missed << endl;

}

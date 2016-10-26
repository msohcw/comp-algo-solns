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

int main(){
  string line;
  int s = 0;
  while(getline(cin, line)) {
    vector<pair<double,double> > points;
    stringstream ss;
    ss << line;
    while(ss.rdbuf()->in_avail() > 0){
      double a, b;
      ss >> a;
      ss >> b;
      points.push_back(make_pair(a,b));
    }

    // I hope I don't need convex hull
    double maxd = 0;
    for(int i = 0; i < points.size(); ++i){
      for(int j = 0; j < points.size(); ++j){
        maxd = max((points[i].first - points[j].first)*(points[i].first - points[j].first) +  (points[i].second - points[j].second) * (points[i].second - points[j].second), maxd); 
      }
    }
    s += 1;
    printf("Set #%d: Diameter is %.2lf\n", s, sqrt(maxd));
  }
}

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
#define EPS 0.0000001
#define PI 3.141592653589793

struct point{
  double x;
  double y;
  point(double _x, double _y){
    x = _x;
    y = _y;
  }
};

double angle(point a, point b, point c){
  double ux = b.x - a.x;
  double uy = b.y - a.y;
  double vx = c.x - a.x;
  double vy = c.y - a.y;
  return acos((ux*vx + uy * vy)/sqrt((ux*ux + uy*uy)*(vx*vx + vy*vy)));
}

vector<point> P;

double cross(point p, point q, point r){ return (r.x - q.x) * (p.y - q.y) - (r.y -q.y) * (p.x - q.x); }

bool inPolygon(point p){
  double sum = 0;
  for(int i = 0; i < (int)P.size() -1; ++i){
    double ang = angle(p, P[i], P[i+1]);
    if(cross(p, P[i],P[i+1]) < 0){
      sum -= ang;
    }else{
      sum += ang;
    }
    if(fabs(ang-PI) < EPS) return false;
  }
  return (fabs(sum-2*PI) < EPS || fabs(sum + 2*PI) < EPS);
}

int N, M;

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    P.push_back(point(a,b));
  }
  P.push_back(P[0]);
  scanf("%d", &M);
  int s = 0;
  for(int i = 0; i < M; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    if(inPolygon(point(a,b))) s++;
  }
  printf("%d\n", s);
}

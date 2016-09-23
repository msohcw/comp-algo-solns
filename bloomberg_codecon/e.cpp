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
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

ll N;
vi num;
vi palindrome;

int main(){
  cin >> N;

  while(N > 0){
    num.push_back(N%10);
    N = N/10;
  }

  sort(num.begin(), num.end());
  reverse(num.begin(), num.end());
  
  for(int i = 0; i < num.size(); ++i){
    if(i == num.size()-1) continue;
    if(num[i] == num[i+1]){
      palindrome.push_back(num[i]);
      num[i] = num[i+1] = -1;
      i+=1;
    }
  }
  
  bool odd = false;
  for(int i = 0; i < num.size(); ++i){
    if(num[i] == -1) continue;
    palindrome.push_back(num[i]);
    odd = true;
    break;
  }
  for(int i = 0; i < palindrome.size(); ++i) printf("%d", palindrome[i]);
  for(int i = 0; i < palindrome.size(); ++i){
    if(odd){
      odd = false;
    }else{
      printf("%d", palindrome[palindrome.size() - 1 - i]);
    }
  }
  printf("\n");
}
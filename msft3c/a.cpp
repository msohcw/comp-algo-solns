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
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

map<char, char> mc;

int main(){
  /*
  bool init = false;
  char s[10];
  while(init == false || strlen(s) == 3){
    init = true;
    cin >> s;
    mc.insert(make_pair(s[0], s[2]));
  }
  */
  char s[100000];
  cin.getline(s,100000);
  for(int i = 0; i < strlen(s); i+=4){
    if(mc.find(s[i]) != mc.end()) continue;
    mc.insert(make_pair(s[i], s[i+2]));
  }
  char message[100000];
  cin.getline(message,100000);
  //cout << message;
  //printf("%d\n", strlen(message));
  for(int i = 0; i < strlen(message); ++i){
    int num = (int) message[i];
    if(num < 65 || (num > 90 && num < 97) || num > 122) continue;
    bool lowercase = (num >= 97);
    char key = (lowercase)? (char) (((int) message[i]) - 32) : message[i];
    //printf("mapping %c-%c", key, mc[key]);
    message[i] = (lowercase)? (char)(((int)(mc[key])) + 32) : mc[key];
  }
  cout << message;
}

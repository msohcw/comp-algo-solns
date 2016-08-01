#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

msi M;
int N;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N;i++){
        char nation[75];
        scanf("%s", &nation);
        M[nation]++;
        gets(nation);
    }
    for(msi::iterator it = M.begin(); it != M.end(); ++it){
        printf("%s %d\n", (*it).first.c_str(), (*it).second); 
    }
}

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

// typedef long long ll;
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

int N;
map<ll,ll> tolls;

int pop_ct(ll i){
    int ct = 0;
    while(i >> ct > 0) ct++;
    return ct;
}

ll common_ancestor(ll a, ll b){
    ll big = max(a,b);
    ll small = min(a,b);
    int diff = pop_ct(big) - pop_ct(small);
    big = big >> diff;
    ll ca = (big ^ small);
    int shift = 0;
    while(ca >> shift > 0) shift++;
    ca = big >> shift;
    return ca;
}

ll cost(ll a, ll b){
    ll total = 0;
    ll ca = common_ancestor(a,b);
    int steps = 0;
    while(a != b){
        if(a == ca){
            a = b;
            b = ca;
        }
        if(tolls.count(a) == 1) total += tolls[a];
        a = a >> 1;
        steps++;
    }
    return total;
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			ll a,b,w;
            cin >> a >> b >> w;

            ll ptr = max(a,b);
            ll end = min(a,b);
            ll ca = common_ancestor(a,b);
            while(ptr != end){
                if(ptr == ca){
                    ptr = end;
                    end = ca;
                }
                tolls[ptr] +=w;
                ptr = ptr >> 1;
                        
            }
		}else if (t == 2){
			ll a,b;
			cin >> a >> b;
            ll low, high;
            low = max(a,b);
            high = min(a,b);
		    cout << cost(low,high) << endl; 
		}
	}
}

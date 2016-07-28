#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 999999999999999999

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

char C[20];
char J[20];
int c[20], j[20];
int L;

vector<pair<long, long>> poss;

ll pow10(int a){
	return (long long) pow(10,a);
}

ll test(ll co, ll ja, int index){
	if(index == L){
		ll diff = (co > ja)? co - ja: ja - co;
		return diff;
	}

	int _min = min(c[index], j[index]);
	if(_min == -1) _min = 0;

	vector<pair<long long, long long> > bases;

	if(c[index] != -1 && j[index] != -1){
		bases.push_back(make_pair(co + pow10(L - index - 1) * c[index], ja + pow10(L - index - 1) * j[index]));
	}else if(c[index] == -1 && j[index] == -1){
		bases.push_back(make_pair(co, ja));
		bases.push_back(make_pair(co + pow10(L - index - 1), ja));
		bases.push_back(make_pair(co + pow10(L - index - 1) * 9, ja));
		bases.push_back(make_pair(co, ja + pow10(L - index - 1))) ;
		bases.push_back(make_pair(co, ja + pow10(L - index - 1) * 9)) ;
	}else if(c[index] == -1) {
		bases.push_back(make_pair(co + pow10(L - index - 1) * j[index], ja + pow10(L - index - 1) * j[index]));
		bases.push_back(make_pair(co + pow10(L - index - 1) * (j[index] - 1)%10+10, ja + pow10(L - index - 1) * j[index]));
		bases.push_back(make_pair(co + pow10(L - index - 1) * (j[index] + 1)%10, ja + pow10(L - index - 1) * j[index]));
	}else if(j[index] == -1) {
		bases.push_back(make_pair(co + pow10(L - index - 1) * c[index], ja + pow10(L - index - 1) * c[index]));
		bases.push_back(make_pair(co + pow10(L - index - 1) * c[index], ja + pow10(L - index - 1) * (c[index] - 1)%10+10));
		bases.push_back(make_pair(co + pow10(L - index - 1) * c[index], ja + pow10(L - index - 1) * (c[index] + 1)%10));
	}
	pair<long, long> ret;
	ll _min_diff = INF;

	for(int i = 0; i < bases.size(); i++){
		printf("testing %lld, %lld\n", bases[i].first, bases[i].second);
		ll testing = test(bases[i].first, bases[i].second, index+1);

		if(testing < _min_diff){
			ret = bases[i];
			_min_diff = testing;
		}
	}

	RET = ret;
	return _min_diff;
}

int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);
		
		memset(C, 0, sizeof(C));
		memset(J, 0, sizeof(J));
		memset(c, 0, sizeof(c));
		memset(j, 0, sizeof(j));

		scanf("%s %s", &C, &J);
		L = strlen(C);

		for(int i =0 ; i < strlen(C); i++){
			if(C[i] == '?'){
				c[i] = -1;
			}else{
				c[i] = int(C[i]) - 48;
			}
		}
		for(int i =0 ; i < strlen(C); i++){
			if(J[i] == '?'){
				j[i] = -1;
			}else{
				j[i] = int(J[i]) - 48;
			}
		}

		for(int i = 0; i < strlen(C); i++) printf("%d", c[i]);
		printf("\n");

		ll _diff = test(0,0,0);

		printf("%lld, %lld\n");
		printf("%lld", _diff);

	}

}


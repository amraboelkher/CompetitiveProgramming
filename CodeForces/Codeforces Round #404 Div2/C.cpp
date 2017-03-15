#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 3;
int main(){
	ll N , mx;
	cin >> N >> mx;
	if(mx > N){
		cout << N << endl;
		return 0;
	}
	ll days = mx;
	ll l = 1 , r = 1e10 , res = 0;
	N -= mx;
	while(l <= r && N > 0){
		ll md = (l + r) >> 1;
		ll cnt = md * (md + 1) / 2;
		if(N - cnt <= 0)
			res = md , r = md - 1;
		else l = md + 1;
	}
	days += res;
	cout << days << endl;
	

}

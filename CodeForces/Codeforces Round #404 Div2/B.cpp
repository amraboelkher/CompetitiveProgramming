#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 3;
int main(){

	set< pair< ll , ll > > S1 , S2;
	vector< ll >  A , B;
	int n , m;
	scanf("%d" , &n);
	while(n --){
		int l , r ;
		scanf("%d%d" , &l , &r);
		S1.insert({l , r});
		A.push_back(l);
	}
	scanf("%d" , &m);
	while(m --){
		int l , r ;
		scanf("%d%d" , &l , &r);
		S2.insert({l , r});
		B.push_back(l);
	}
	sort(A.begin() , A.end());
	sort(B.begin() , B.end());
	A.resize(unique(A.begin() , A.end()) - A.begin() );
	
	B.resize(unique(B.begin() , B.end()) - B.begin() );
	
	ll mx = 0;
	for(auto no : S1){
		ll l = no.first , r = no.second;
		ll kk = B.back();
		if(kk != -1)
			mx = max(mx , (ll)kk - r);
			
	}
	for(auto no : S2){
		ll l = no.first , r = no.second;
		ll kk = A.back();
		if(kk != -1)
			mx = max(mx , (ll) kk - r);
		
	}
	printf("%lld\n" , mx);

}

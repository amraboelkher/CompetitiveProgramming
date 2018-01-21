#include<bits/stdc++.h>
using namespace std;
const long long MOD [] = {2000000011 , 1000000009} , base = 10;
map< pair< int , int > , int > mp;
string calHash(string &s, int v , bool f = 0){
	int ret[] = {1 , 1};
	pair< int , int > rr(0 , s.size() - 1);
	set<pair< int , int > > nice;
	int sz = s.size();
	for(int l = 0 ;l < s.size() ;l ++){
		ret[0] = ret[1]= 1;
		for(int i = l ; i < s.size() ;i ++){
			for(int ii = 0 ;ii < 2; ii ++)
				ret[ii] = ( ret[ii] *1LL* base + int(s[i] - '0') ) % MOD[ii];
			if(!nice.count({ret[0] , ret[1]})){
				nice.insert({ret[0] , ret[1]}) ;
				mp[{ret[0] , ret[1]}] += v;
			}

			if(f == 1 && i - l + 1 < sz && mp[{ret[0] , ret[1]}] == 0){
				sz = i - l + 1;
				rr = {l , i};
			}
		}
	}

	return s.substr(rr.first , sz);
}
int main(){
	freopen("in.in" , "r" , stdin);
	int n ;
	cin >> n;
	vector< string > S(n);
	for(int i = 0 ;i < n; i ++){
		cin >> S[i];

		calHash(S[i] , 1 , 0);
	}
	for(int i = 0 ;i < n ;i ++){
		string ss = calHash(S[i] , -1 , 0);
		ss = calHash(S[i] , 0 , 1);
		calHash(S[i] , 1 , 0);
		cout << ss << "\n";
	}
	
}
 

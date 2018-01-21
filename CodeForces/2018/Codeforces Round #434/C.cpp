#include<bits/stdc++.h>
using namespace std;
string r = "aeiou";
bool check(char s){
	for(auto i : r)if(i == s)
		return 0;
	return 1;
}
int main(){
	freopen("in.in" , "r" , stdin);
	string S , ret = "";
	cin >> S;
	int N = S.size();
	vector< pair< int , int > > A;
	vector< int > put(N);
	int l = -1;
	int idx = 0;
	while(idx < N){
		while(idx < N && check(S[idx]) == 0)idx ++;
		if(idx == N)break;
		int L = idx;
		set< char > ss;
		while(idx < N && check(S[idx]) == 1) ss.insert(S[idx]) , idx ++;
		int sz = idx - L;
		if(ss.size() > 1 && sz >= 3)
			A.push_back({L , idx - 1});
	}
	int cnt = 0;
	set< char > ss;
	for(int i = 0 ;i < A.size() ;i ++){
		int ll = A[i].first , rr = A[i].second;
		cnt = 0;
		ss.clear();
		for(int ii = ll ; ii <= rr ;ii ++){
			ss.insert(S[ii]);
			cnt ++;
			if(cnt >= 3 && ss.size() > 1){
				put[ii] = -1;
				cnt = 1;
				ss.clear();
				ss.insert(S[ii]);
			}
		
		}
	}

	for(int i = 0 ;i < N ;i ++){
		if(put[i] == -1)
			ret += " ";
		ret += S[i];
	}
	cout << ret << endl;
	
	
}

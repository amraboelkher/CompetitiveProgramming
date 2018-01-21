#include<bits/stdc++.h>
using namespace std;
string rr = "^>v<";
int main(){
	freopen("in.in" , "r" , stdin);
	string s;
	int no , MOD = 4;
	getline(cin , s);
	cin >> no;
	no %= MOD;
	for(int i = -1; i < 2; i += 2){
		int n = no ;
		string fn(1 , s[0]);
		int idx = rr.find(fn);
		while(n --)
			idx = (idx + i + MOD) % MOD;
		if(rr[idx] == s.back()){
			if(i == -1)cout << "c";
			cout << "cw";
			return 0;
		}
	}
	cout << "undefined" << endl;
	
}


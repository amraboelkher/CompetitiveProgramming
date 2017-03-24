#include<bits/stdc++.h>
using namespace std;
int main(){
	int n ;

	string s ;
	cin >> n >> s;
	string res = s , tmp = s;
	int r = n / 2 , l = (n - 1) / 2;
	if(n & 1){
		res[n / 2] = s[0];
		l = n / 2 - 1;
		r = n / 2 + 1;
	}
	bool first = 1;
	for(int i = n & 1 ; i < s.size() ;i ++){
		if(first)res[l --] = s[i];
		else res[r ++] = s[i];
		first = !first;
	}
	cout << res << endl;
}

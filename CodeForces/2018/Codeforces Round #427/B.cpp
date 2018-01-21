#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" , stdin);
	int k ;
	string s;
	cin >> k >> s;
	long long sum = 0;
	for(int i = 0 ;i < s.size() ;i ++)
		sum += (s[i] - '0');
	sort(s.begin() , s.end() );
	int cnt = 0;
	int idx = 0;
	while(sum < k && idx < s.size() ){
		sum = sum + 9 - (s[idx] - '0');
		idx ++;
		cnt ++;
	}
	cout << cnt << endl;
}

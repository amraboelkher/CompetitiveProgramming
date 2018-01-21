#include<bits/stdc++.h>
using namespace std;
int main(){

	long long pw = 1 , n , k;
	cin >> n >> k;
	while(k --)
		pw *= 0x0a;
	cout << n * pw / __gcd(n , pw) << endl;
	
	
}

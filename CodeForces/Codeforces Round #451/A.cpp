#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" ,  stdin);
	long long n ;
	cin >> n;
	int k = n % 10;
	n /= 10;
	if(k >= 5)
		n ++ , n = n * 10;
	else n = n * 10;
	cout << n << endl;
}

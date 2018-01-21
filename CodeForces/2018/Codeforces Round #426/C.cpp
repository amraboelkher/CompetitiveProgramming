#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" , stdin);
	int n;
	scanf("%d", &n);
	while(n --){
		int a , b;
		scanf("%d%d" , &a , &b);
		long long pw3 = a * 1LL * b;
		pw3 = cbrt(pw3) + 1e-7;
		int winkA = a / pw3 , winkB = b / pw3  , loskA = winkB , loskB = winkA;
		int expA = winkA * winkA * loskA , expB = winkB * winkB * loskB;
		if(expA == a && expB == b)	puts("Yes");
		else puts("No");
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" , stdin);
	long long n , a , b;
	cin >> n >> a >> b;
	for(int i = 0 ;i <= n ;i ++){
		long long rem = n - i * a;
		if(rem >= 0 && rem % b == 0){
			printf("YES\n%lld %lld", 1LL*i , rem / b);
			return 0; 
		}
		long long rr = n - i * b;
		if(rr >= 0 && rr % a == 0){
			printf("YES\n%lld %lld", rr / a , 1LL*i);
			return 0; 
		}
	}
	puts("NO");
	
}


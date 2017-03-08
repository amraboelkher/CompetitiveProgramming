#include<bits/stdc++.h>
using namespace std;
int main(){

	map<int , int > mp;
	long long res = 0;
	int n , x ;
	scanf("%d%d" , &n , &x);
	for(int i = 0 ;i < n ;i ++){
		int tmp ;
		scanf("%d" , &tmp);
		res += mp[tmp ^ x];
		mp[tmp] ++;
	}
	printf("%lld\n" , res);

}

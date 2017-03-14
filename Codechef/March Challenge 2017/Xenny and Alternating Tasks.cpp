#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int t;
	scanf("%d" , &t);
	while(t --){
		int N , x;
		scanf("%d" , &N);
		int res1 = 0 , res2 = 0 , res3 = 0 , res4 = 0;
		for(int i = 0 ;i < N ;i ++){
			scanf("%d" , &x);
			if(i & 1) res1 += x;
			else res2 += x;
		}
		for(int i = 0; i < N ;i ++){
			scanf("%d" , &x);
			if(i & 1) res3 += x;
			else res4 += x;
		}
		printf("%d\n" , (int)min(res1 + res4 , res2 + res3) );
	}
			
}

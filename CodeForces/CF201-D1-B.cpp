#include<bits/stdc++.h>
using namespace std;
int B[2001][2001] , retY , retX , ret;
long long CX[2003] , CY[2003] , CCX[2003] , CCY[2003];
int n , m;
int main(){
	scanf("%d%d" , &n , &m);
	for(int i = 0 ;i < n ;i ++){
		for(int l = 0; l < m ;l ++){
			scanf("%d" , &B[i][l]);
			CX[i] += B[i][l];
			CY[l] += B[i][l];
		}
	}
	for(int i = 0 ;i <= n ;i ++){
		for(int l = 0 ;l < n; l ++){
			CCX[i] += CX[l] * (2 * i - 2 * l - 1) * ( 2 * i - 2 * l - 1) ;
		}
	}
	for(int i = 0 ;i <= m ;i ++){
		for(int l = 0; l < m ;l ++){
			CCY[i] += CY[l] * (2 * i - 2 * l - 1) * (2 * i - 2 * l - 1) ;
		}
	}
	for(int i = 0 ;i <= n ;i ++){
		if(CCX[retX] > CCX[i])
			retX = i;
	}
	for(int i = 0 ;i <= m; i ++){
		if(CCY[retY] > CCY[i])
			retY = i;
	}
	ret = 4 * (CCX[retX] + CCY[retY] );
	
	
	printf("%I64d\n%d %d\n" , ret , retX , retY); 


}

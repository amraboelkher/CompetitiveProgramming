#include<bits/stdc++.h>
using namespace std;

int  main(){

	int s , x1 , x2;
	int foot , train;
	int posT , dir ;
	scanf("%d%d%d%d%d%d%d" , &s , &x1 , &x2 , &train , &foot , &posT , &dir);
	int res1 = abs(x1 - x2) * foot;
	int res2 = ( abs(x1 - x2) + abs(x1 - posT) ) * train;
	if(dir == 1 && x1 < posT)
		res2 += (s - posT) * 2 * train , dir = -1;
	else if(dir == -1 && x1 > posT)
		res2 += 2 * posT * train , dir = 1;
	if(dir == 1 && x2 < x1)
		res2 += (s - x1) * 2 * train;
	else if(dir == -1 && x2 > x1)
		res2 += x1 * 2 * train ;
	printf("%d\n" , min(res1 , res2) );
	

}

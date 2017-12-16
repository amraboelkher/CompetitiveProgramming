#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1002;
double dp[MAXN][MAXN];
// dp[i][j] means we're currently having i bugs types and they've been found in one or more in these j subsystems  
// we have four options at position dp[i][j] 
// option1 : we will have another bug which is the same as one of the Is bugs found and belong to one of the existing subsystems 
// we will denote that as (old bug + same subsystems) 
// option2 : we will have another bug which is the same as one of the Is bugs found and belong to a new subsystem 
// we will denote that as (old bug + new subsystem)
// option3 : we will have a new bug and it belongs to one of the existing subsystems
// we will denote that as (new bug + same subsystems)
// option4 : we will have a new bug and it belongs to a new subsystem 
// we will denote that as (new bug + new subsystem)
// each move will consume 1 unit of time (as the problem is asking to get expectation time required 
// equation will be -> 
// dp[i][j] = option1 * dp[i][j] + option2 * dp[i][j + 1] + option3 * dp[i + 1][j] + option4 * dp[i + 1][j + 1] + 1
// option1 = (i * j) / (n * s) 
// option2 = (i * (s - j) ) / (n * s) 
// option3 = ((n - i) * j) / (n * s) 
// option4 = ((n - i) * (s - j)) / (n * s) 
// after getting all terms of dp[i][j] to the left hand side 
// dp[i][j] - option1 * dp[i][j] = option2 * dp[i][j + 1] + option3 * dp[i + 1][j] + option4 * dp[i + 1][j + 1] + 1
// dp[i][j] * (1 - option1) = option2 * dp[i][j + 1] + option3 * dp[i + 1][j] + option4 * dp[i + 1][j + 1] + 1
// dp[i][j] = (option2 * dp[i][j + 1] + option3 * dp[i + 1][j] + option4 * dp[i + 1][j + 1] + 1) / (1 - option1) 
// to avoid dividing by zero !
// 1 - option1 = ( n * s - i * j ) / (n * s) 
// dp[i][j] = (option2 * dp[i][j + 1] + option3 * dp[i + 1][j] + option4 * dp[i + 1][j + 1] + 1) / ( ( n * s - i * j ) / (n * s) ) 
// multiply by n * s 
// dp[i][j] = (n * s) * (option2 * dp[i][j + 1] + option3 * dp[i + 1][j] + option4 * dp[i + 1][j + 1] + 1) /  ( n * s - i * j )
// if you want you can simplify it more as each term of optionX [2:4] have a denominator also !
// dp[i][j] = ( (i * (s - j) ) * dp[i][j + 1] + ((n - i) * j) * dp[i + 1][j] + 
//									((n - i) * (s - j)) * dp[i + 1][j + 1] + (n * s) ) /  ( n * s - i * j )
 
int main(){
	double n , s;
	scanf("%lf%lf" , &n , &s);
	for(int i = n; i >= 0 ; i -- ){
		for(int j = s; j >= 0 ; j --)if(i != n || j != s){
			double option1 = (i * j) / (n * s) ;
			double option2 = (i * (s - j) ) / (n * s) ;
			double option3 = ((n - i) * j) / (n * s) ;
			double option4 = ((n - i) * (s - j)) / (n * s) ;
			dp[i][j] = ( (n * s) * (option2 * dp[i][j + 1] + option3 * dp[i + 1][j] + option4 * dp[i + 1][j + 1] + 1) ) /  ( n * s - i * j );
//			dp[i][j] = ( (i * (s - j) ) * dp[i][j + 1] + ((n - i) * j) * dp[i + 1][j] + 
//									((n - i) * (s - j)) * dp[i + 1][j + 1] + (n * s) ) /  ( n * s - i * j )
		}
	}
	printf("%.4lf\n" , dp[0][0]); 
}

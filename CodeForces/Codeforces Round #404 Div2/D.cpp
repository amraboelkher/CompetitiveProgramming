#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 3 , MOD = 1e9 + 7;
ll F[MAXN];
char S[MAXN];
ll G(ll x , ll y){
	if(y == 0) return 1;
	if(y == 1) return x;
	ll t = G(x , y / 2);t = t * t % MOD;
	if(y % 2) t = x * t % MOD;
	return t;
}
int main(){
	scanf("%s" , S);
	int n = strlen(S) , ans = 0;
	int open = 0 , close = 0;
	for(int i = 0; i < n ;i ++)if(S[i] == ')')
		close ++;
	F[0] = 1;
	for(int i = 1; i < MAXN; i ++)
		F[i] = (i * F[i - 1]) % MOD;
	for(int i = 0 ;i < n ;i ++){
		if(S[i] == '('){
			ans = (ans + ( (F[open + close] * G(F[close - 1] , MOD - 2) % MOD) * G(F[open + 1] , MOD - 2) % MOD ) ) % MOD;
			open ++;
		}else 
			close --;
	}
	printf("%d\n" , ans);

	

}

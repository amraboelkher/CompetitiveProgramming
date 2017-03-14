#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 3;
int Te[4 * MAXN + 2] , dp[(1 << 16) + 2];
char S[5];
void up(int idx , int v , int l1 , int r1 , int l , int r){
	if(l > r1 || r < l1)
		return ;
	if(l >= l1 && r <= r1){
		Te[idx] = v;
		return ;
	}
	int md = (l + r) >> 1;
	up(idx * 2 , v , l1 , r1 , l , md);
	up(idx * 2 + 1 , v , l1 , r1 , md + 1 , r);
	Te[idx] = Te[idx * 2] ^ Te[idx * 2 + 1];
}
int get(int idx , int l1 , int r1 , int l , int r){
	if(l > r1 || r < l1)
		return 0;
	if(l >= l1 && r <= r1)
		return Te[idx];
	int md = (l + r) >> 1;
	return get(idx * 2 , l1 , r1 , l , md) ^ get(idx * 2 + 1 , l1 , r1 , md + 1 ,r);
}
int rec(int msk){
	if(!msk) return msk;
	if(dp[msk] != -1)	return dp[msk];
	int &ret = dp[msk];
	ret = 0;
	set< int > G;
	for(int i = 0; i < 4; i ++){
		for(int l = 0 ;l < 4; l ++){
			for(int ii = i ; ii < 4;  ii ++){
				for(int ll = l ; ll < 4; ll ++){
					bool in = 1;
					int nmsk = msk;
					for(int iii = i ; iii < ii + 1  ; iii ++){
						for(int lll = l ; lll < ll + 1 ; lll ++){ 
							if( ( (1 << ( 4 * iii + lll ) ) & msk ) == 0){
								in = 0;
								break;
							}
							nmsk ^= (1 << (4 * iii + lll) );
						}
					}
					if(in)
						G.insert(rec(nmsk));
				}
			}
		}
	}
	while(G.count(ret))
		ret ++;
	return ret;
}
int extract(){
	int msk = 0;
	for(int i = 0 ;i < 4; i ++){
		scanf("%s" , S);
		for(int l = 0; l < 4; l ++){
			if(S[l] == '1')
				msk |= (1 << (4 * i + l) );
		}
	}
	return msk;
}
	
int main(){
	int t;
	memset(dp , -1 , sizeof dp);
	scanf("%d" , &t);
	while(t --){
		int N , Q;
		scanf("%d%d" , &N , &Q);
		for(int ii = 0; ii < N ; ii ++){
			int msk = extract();
			msk = rec(msk);
			up(1 ,  msk , ii , ii , 0 , N - 1);
		}
		while(Q --){
			int tmp , tmp1;
			scanf("%d%d" , &tmp , &tmp1);
			if(tmp == 1){
				int tmp2;
				scanf("%d" , &tmp2) , tmp1 -- , tmp2 --;
				if(get(1 , tmp1 , tmp2 , 0 , N - 1) )
					puts("Pishty");
				else puts("Lotsy");
			}
			else {
				int msk = extract();
				msk = rec(msk);
				up(1 , msk , tmp1 - 1 , tmp1 - 1 , 0 , N - 1);
			}
		}
	
	}
}

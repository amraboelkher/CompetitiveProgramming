#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 502;
bool check(int K , int cnt , int N){
	for(int i = 0; i < N ;i ++){
		int L = i - K , R = i + K + 1;
		if(R >= 0)
			R = N - R;
		R = max(0 , R) , L = max(L , 0) ;
		if(L + R > cnt)
			return 0;
		cnt -= (L + R);
	}
	return 1;

}
int main(){
	int t;
	scanf("%d" , &t);
	while(t --){
		int N , cnt = 0 , tmp;
		scanf("%d" , &N);
		for(int i = 0 ;i < N ;i ++){
			for(int l = 0; l < N ;l ++){
				scanf("%d" , &tmp);
				if(!tmp)	cnt ++;
			}
		}
		int l = 0 , r = N , res = -1;
		while(l <= r){
			int md = (l + r) >> 1;
			if(check(md , cnt , N))
				res = md , r = md - 1;
			else l = md + 1;
		}
		printf("%d\n" , res);	
	}
}


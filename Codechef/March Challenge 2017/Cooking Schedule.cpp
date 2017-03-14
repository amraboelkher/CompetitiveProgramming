#include<bits/stdc++.h>
using namespace std;
char S[1000100];
vector< int > A;
bool check(int K , int M){
	for(int i = 0 ;i < A.size() ;i ++){
		M -= (A[i] / (K + 1) );
		if(M < 0)
			return 0;
	}
	return 1;
}
int main(){
	int t;
	scanf("%d" , &t);
	while(t --){
		int N , M , res = -1;
		scanf("%d%d%s" ,&N , &M , S);
		A.clear();
		char last = 'a' ;
		for(int i = 0 ; i < N ;i ++){
			if(S[i] == last)
				A.back() ++;
			else {
				A.push_back(1);
				last = S[i];
			}
		}
		int tmp1 = 0 , tmp2 = 0;
		for(int i = 0 ;i < N ;i += 2){
			if(S[i] != '1')
				tmp1 ++;
			else tmp2 ++;
		}
		for(int i = 1; i < N ; i += 2){
			if(S[i] != '0')
				tmp1 ++;
			else tmp2 ++;
		}
		int l = 2 , r = N;
		while(l <= r){
			int md = (l + r) >> 1;
			if(check(md ,M))
				res = md , r = md - 1;
			else l = md + 1;
		}
		if(tmp1 <= M || tmp2 <= M)
			res = 1;
		printf("%d\n" , res);
		 
	}


}

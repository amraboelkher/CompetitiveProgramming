#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , m , T = 0;
	while(scanf("%d%d" , &n , &m) && (n || m) ){
	
		
		deque< int > F , S ;
		for(int i = 1; i <= min(2000 , n) ; i ++){
				F.push_back(i);
		}
		
		int nxt = 2;
		printf("Case %d:\n" , ++T);
		for(int i = 0 ;i < m ; i ++){
			char s[10];
			scanf("%s" , s);
			string ss = s;
			while(F.size() && F.front() < 0)
				F.pop_front();
			while(S.size() && S.front() < 0)
				S.pop_front();
			if(F.size() == 0)
				F.push_back(S.front()) , S.pop_front();
			if(ss == "N"){
				int x = F.front();
				printf("%d\n" , x);
				F.pop_front();
				S.push_back(x);
			}
			else {
				int no ;
				scanf("%d" , &no);
				bool in = 0;
				for(int ii = 0 ; ii < F.size() ; ii ++) if(F[ii] == no){
					F[ii] = -1e6;
					break;
				}
				for(int ii = 0 ; ii < S.size() ; ii ++) if(S[ii] == no){
					S[ii] = -1e6;
					break;
				}
				F.push_front(no);
			}

		
		}
		
	
	}
}

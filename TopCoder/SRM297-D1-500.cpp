#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string.h>

using namespace std;


class CageTheMonster {
public:
	vector< vector< int > > G , vis;
	// 0 empty 
	// 1 dragon
	// 2 wall 
	int dr[4] = {1 , -1 , 0 , 0};
	int dc[4] = {0 , 0 , 1,  -1};
	int N , M;
	bool valid(int r , int c){
		return r >= 0 && r < N && c >= 0 && c < M;
	}
	bool yes , no;
	void dfs(int r , int c ){
		vis[r][c] = 1;
		if(yes)return ;
		for(int i = 0 ;i < 4 ;i ++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(!valid(nr , nc) ) {  yes = 1;}
			if(valid(nr , nc) && G[nr][nc] != 2 && !vis[nr][nc])
				dfs(nr , nc);
		}
	}

	int capture(vector <string> A) {
		G.clear();
		G.resize(A.size());
		vis.clear();
		vis.resize(A.size());
		bool in = 0;

		N = A.size() , M = A[0].size();
		for(int i = 0 ;i < A.size() ;i ++){
			G[i].resize(A[i].size());
			vis[i].resize(A[i].size());
			for(int ii = 0; ii < A[i].size() ; ii ++){
				if(A[i][ii] == '.')
					G[i][ii] = 0;
				else if(A[i][ii] == '^'){
					G[i][ii] = 1;
					if(i != 0 && i != A.size() - 1 && ii != 0 && ii != A[i].size() - 1)
						in = 1; 	
				}
				else G[i][ii] = 2;
			}
		}
		if(!in)return -1;
		int res = 10;
		for(int i = 1 ;i + 1 < N ;i ++){
			for(int l = 1 ;l + 1 < M ;l ++){
				if(G[i][l] == 1){
					vector< int > tmpU(M) , tmpD(M) , tmpL(N) , tmpR(N);
					tmpU = G[i - 1];
					tmpD = G[i + 1];
					for(int ii = 0 ; ii < N ; ii ++)
						tmpL[ii] = G[ii][l - 1] , tmpR[ii] = G[ii][l + 1];
					// choose which one i'll construct 
					// 0 up , 1 down , 2 right , 3 left
					vector< int > T(M , 2);
					for(int ii = 0 ; ii < (1 << 4) ; ii ++){
						int tmp = 0;
						if( ii & (1 << 0) )	G[i - 1] = T , tmp ++;
						if( ii & (1 << 1) )	G[i + 1] = T , tmp ++;
						if( ii & (1 << 2) ){
							for(int ll = 0 ;ll < N ;ll ++)
								G[ll][l + 1] = 2; 
							tmp ++;
						}
						if( ii & (1 << 3) ){
							for(int ll = 0 ;ll < N ;ll ++)
								G[ll][l - 1] = 2;
							tmp ++;
						}
						yes = 0;
						for(int k = 0 ; k < vis.size() ;k ++)
							for(int kk = 0 ; kk < vis[k].size() ; kk ++)
								vis[k][kk] = 0;
						if(ii == 0) no = 1;
						else no = 0;
						yes = false;
						dfs(i , l);
						if(!yes) res = min(res , tmp);
						G[i - 1] = tmpU;
						G[i + 1] = tmpD;
						for(int ll = 0 ; ll < N ;ll ++)
							G[ll][l + 1] = tmpR[ll] , 
							G[ll][l - 1] = tmpL[ll] ;
					}
					
					
				}
			}
		}
		return res;
		
		
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

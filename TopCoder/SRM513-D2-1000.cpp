

#include<bits/stdc++.h>
using namespace std;


class CutTheNumbers {
public:
	int dp[5][5][5][5] , r , c;
	string S[5];
	int rec(int I , int J , int H  , int W){
		if(H == 1){
			int no = 0;
			for(int i = J; i < J + W ; i ++)
				no = no * 10 + (S[I][i] - '0');
			return no;
		}
		if(W == 1){
			int no = 0;
			for(int i = I; i < I + H; i ++)
				no = no * 10 + (S[i][J] - '0');
			return no;
		}
		int &ret = dp[I][J][H][W];
		if(ret != -1)return ret;
		ret = 0;
		for(int i = 1;i < W; i ++)
			ret = max(ret , rec(I , J , H , i) + rec(I , J + i , H , W - i) );
		for(int i = 1;i < H; i ++)
			ret = max(ret , rec(I , J , i , W) + rec(I + i , J , H - i , W ) );
		return ret;
	}
	int maximumSum(vector <string> kk) {
		memset(dp , -1 , sizeof dp);
		for(int i = 0 ;i < kk.size() ;i  ++)
			S[i] = kk[i];
		r = kk.size();
		c = kk[0].size();
		return rec(0 , 0 , r , c);
	}
};

int main(){

}

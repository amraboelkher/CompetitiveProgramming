#include<bits/stdc++.h>
using namespace std;
const  int MAXN = 200; 
int match[MAXN];
int main(){

	string S , T;
	int N , M;
	long long ret = 0;
	cin >> N >> M >> S >> T;
	for(int i = 0 ;i < T.size() ;i ++){
		for(int ii = 0; ii < S.size() ;ii ++){
			int idx = (match[i] + i) % T.size();
			if(T[idx] == S[ii])
				match[i] ++;
		}
	}
	for(int i = 0; i < N ;i ++)
		ret += match[(ret % (int)T.size())];
	 
	cout << ret / (M *1LL* T.size()) << endl;
}

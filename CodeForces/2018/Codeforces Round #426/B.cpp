#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" , stdin);
	string S ;
	int K , n;
	cin >>n >> K >>  S ;
	vector< int > A(S.size() ) , B(S.size() );
	for(char i = 'A' ; i <= 'Z' ;i ++){
		for(int ii = 0 ;ii < S.size() ;ii ++){
			if(S[ii] == i){
				A[ii] ++;
				break;
			}	
		}
		for(int ii = S.size() - 1; ii >= 0 ;ii --){
			if(S[ii] == i){
				B[ii] --;
				break;
			}
		}
	}
	int no = 0;
	bool yes =1;
	for(int i = 0 ;i < S.size() ;i ++){
		no += A[i];
		yes &= no <= K;	
		no += B[i];
	}
	cout << (yes ? "YES" : "NO" ) << endl;
}

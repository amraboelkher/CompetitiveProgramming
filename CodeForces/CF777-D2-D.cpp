#include<bits/stdc++.h>
using namespace std;
char S[601009];
int main(){

	int n ;
	scanf("%d" , &n);
	vector< string > A(n);
	for(int  i = 0 ; i < n ;i ++)
		scanf("%s" , S) , A[i] = S;
	for(int i = n - 1; i > 0 ;i --){
		string s1 = A[i - 1] , s2 = A[i];
		int x1 = 1 , x2 = 1;
		while(x1 < s1.size() && x2 < s2.size() && s1[x1] == s2[x2])
			x1 ++ , x2 ++;
		
		if(x1 != s1.size() && x2 != s2.size()){
			if(s1[x1] > s2[x2])
				A[i - 1] = s1.substr(0 , x1 );
		}
		else if(x2 == s2.size())
			A[i - 1] = s1.substr(0 , s2.size() );
	}
	for(int i = 0 ;i < n ;i ++)
		printf("%s\n" , A[i].c_str() );
	return 0;

}

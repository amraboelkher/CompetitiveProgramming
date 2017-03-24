#include<bits/stdc++.h>
using namespace std;
int N , K;
char tmp[30];
string ans[52];
bool marked[52];
int main(){
	scanf("%d%d" , &N , &K);
	string cur = "Aa" , ttmp;
	for(int i = 0; i + K - 1 < N ; i ++){
		scanf("%s" , tmp) , ttmp = tmp;
		for(int ii = i ; ii - K < i ; ii ++){
			if(!marked[ii]){
				marked[ii] = 1;
				if(cur[1] == 'z')
					cur[0] ++ , cur[1] = 'a';
				else cur[1] ++;
				ans[ii] = cur;
			}
		}
		if(ttmp == "NO")
			ans[i + K - 1] = ans[i];
	}
	for(int i = 0 ;i < N ;i ++){
		for(int ii = 0 ;ii < ans[i].size() ; ii ++)
			printf("%c" , ans[i][ii]);
		printf(" ");
	}
		
}


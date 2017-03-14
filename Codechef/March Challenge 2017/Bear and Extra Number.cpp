#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int t;
	scanf("%d" , &t);
	while(t --){
		int N , res;
		scanf("%d" ,&N);
		map< int , int > mp;
		for(int i = 0 , x ;i < N ;i ++)
			scanf("%d", &x) , mp[x] ++;
		for(auto no : mp){
			if(no.second == 1 && (mp.count(no.first + 1) || mp.count(no.first - 1)))
				continue;
			res = no.first;
		}
		printf("%d\n" , res);
	}
}

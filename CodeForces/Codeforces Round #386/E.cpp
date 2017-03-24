#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

	int N , M;
	scanf("%d%d" , &N , &M);
	set< int > S , _odd , _even ;
	int change = 0;
	int takenOdd = 0, takenEven = 0;
	int odd = 0 , even = 0 , extraOdd = 0 , extraEven = 0 , resChange = 0;
	vector< int > res( N ) , CC;
	map< int , int > mp;
	for(int i = 0 ;i < N ;i ++){
		int tmp;
		scanf("%d" , &tmp);
		if(S.count(tmp))
			change ++  , CC.push_back(i);
		else S.insert(tmp) , mp[tmp] = i;
	}
	for(auto it = S.rbegin() ; it != S.rend() ; it ++){
		int no = *it;
		if(no % 2 == 0){
			if(takenEven + 1 <= N / 2)
				res[mp[no]] = no , takenEven ++;
			else change ++ , CC.push_back(mp[no]);
		}
		else{
			if(takenOdd + 1 <= N / 2)
				res[mp[no]] = no , takenOdd ++;
			else change ++ , CC.push_back(mp[no]);
		}
	}
	resChange = change ;
	
	for(int i = 1; i <= M && (takenEven != N / 2 || takenOdd != N / 2) ;i ++){
		if(!S.count(i)){
			if(i % 2 == 0)
				extraEven ++ , _even.insert(i);
			else extraOdd ++ , _odd.insert(i);
		}
		while(change > 0){
			if(takenOdd < N / 2 && extraOdd > 0)
				extraOdd -- , takenOdd ++ , res[CC.back()] = (*_odd.begin()) , _odd.erase(_odd.begin()) , change -- , CC.pop_back();
			else if(takenEven < N / 2 && extraEven > 0)
				extraEven -- , takenEven ++ , res[CC.back()] = (*_even.begin()) , _even.erase(_even.begin()) , change  -- , CC.pop_back();
			else break;
		}
	}
	if(takenEven != takenOdd || takenOdd != N / 2)
		puts("-1");
	else {
		printf("%d\n" , resChange);
		for(int i = 0 ;i < N ;i ++)
			printf("%d " , res[i] );
		puts("");
		
	
	}
	
}


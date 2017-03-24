#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 3;
set< pair< int , int > > part , full;
int gain[MAXN] , cost[MAXN] , atMost , reachWork , N;
long long totalCost , totalGain , mx ;
void add(int idx){
	part.insert(make_pair(cost[idx] , idx));
	totalCost += cost[idx] / 2 + cost[idx] % 2;
	totalGain += gain[idx];
	while(part.size() > atMost){
		idx = part.begin()->second;
		full.insert(make_pair(cost[idx] , idx));
		part.erase(part.begin());
		totalCost -= (cost[idx] / 2 + cost[idx] % 2);
		totalCost += cost[idx];
	}
}
void del(int idx){
	if(part.count(make_pair(cost[idx] , idx))){
		totalCost -= (cost[idx] / 2 + cost[idx] % 2);
		part.erase(make_pair(cost[idx] , idx));
	}
	else {
		totalCost -= cost[idx];
		full.erase(make_pair(cost[idx] , idx));
	}
	totalGain -= gain[idx];
	while(full.size() > 0 && part.size() < atMost){
		idx = full.rbegin()->second;
		totalCost -= cost[idx];
		totalCost += (cost[idx] / 2 + cost[idx] % 2);
		part.insert(make_pair(cost[idx] , idx));
		full.erase(make_pair(cost[idx] , idx));
	}
}

 
int main(){	
	scanf("%d%d%d" , &N , &atMost , &reachWork);
	for(int i = 0 ;i < N ;i ++)
		scanf("%d" , &gain[i]);
	for(int i = 0 ;i < N ;i ++)
		scanf("%d" , &cost[i]);
	int l = 0 , r = 0;
	while(l < N){
		r = max(r , l);
		while(r < N){
			add(r);
			if(totalCost > reachWork){
				del(r);
				break;
			}
			mx = max(mx , totalGain);
			r ++;
		}
		del(l);
		l ++;
	}
	printf("%I64d\n" , mx);

}

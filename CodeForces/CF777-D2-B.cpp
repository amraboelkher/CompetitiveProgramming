#include<bits/stdc++.h>
using namespace std;
int main(){


	int n;
	string s1 , s2;
	cin >> n >> s1 >> s2;
	vector< int > cnt(10);
	for(int i = 0 ;i < n ;i ++)
		cnt[s2[i] - '0'] ++;
	int resN = 0 , resM = 0;
	vector< int > cnt2 = cnt;
	for(int i = 0 ;i < n ;i ++){
		int no = s1[i] - '0';
		bool found = 0;
		for(int l = no ; l < 10 ;l ++){
			if(cnt2[l])
				cnt2[l] -- , found = 1;
			if(found)break;	
		}
		if(!found){
			resN ++;
			for(int l = 0 ; l < no ;l ++){
				if(cnt2[l]){
					cnt2[l] --;
					break;
				}
			}
		}
		found = 0;
		for(int l = no + 1 ;l < 10 ;l ++){
			if(cnt[l])
				cnt[l] -- , found = 1;
			if(found)break;
		}
		if(found)
			resM ++;
		else {
			for(int l = 0 ;l < 10 ;l ++){
				if(cnt[l]){
					cnt[l] --;
					break;
				}
			}
		}
		
	}
	cout << resN << endl << resM << endl;	
	
			

}

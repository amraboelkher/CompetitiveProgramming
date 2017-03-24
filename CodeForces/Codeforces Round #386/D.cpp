#include<bits/stdc++.h>
using namespace std;
string res = "";
void add(int x , vector<int> &whichType , vector<int > &howMany){
	if(whichType.size() == 0 || whichType.back() != x)
		whichType.push_back(x) , howMany.push_back(1);
	else howMany.back() ++;
}
bool check(int n , int k , int a , int b , bool x = 0){
	vector< int > whichType , howMany ;
	int last = 0 , tot = 0;
	string ch = "";
	int A[2];
	A[0] = a , A[1] = b , ch = "GB";
	if(x)
		swap(A[0] , A[1]) , swap(ch[0] , ch[1]) ;	
	res = "";
	while(A[0] > 0 && A[1] > 0){
		if(tot == 0){
			if(A[last] > 0)
				A[last] -- , tot = 1 , add(last , whichType , howMany);
			else last ^= 1 , A[last] -- , tot = 1  , add(last , whichType , howMany);
		}
		else {
			if(tot + 1 <= k && A[last] > 0){
				A[last] --;
				tot ++;
				add(last , whichType , howMany);
			}
			else {
				tot = 0;
				A[last ^ 1] --;
				add(last ^ 1 , whichType , howMany);
			}
		}
	}

	if(A[0] > 0 && (whichType.size() == 0  || whichType.back() != 0 ) ){
		int mn = min(A[0] , k);
		whichType.push_back(0);
		howMany.push_back(mn);
		A[0] -= mn;
	}
	if(A[1] > 0 && (whichType.size() == 0 || whichType.back() != 1 ) ) {
		int mn = min(A[1] , k);
		whichType.push_back(1);
		howMany.push_back(mn);
		A[1] -= mn;
	}

	for(int i = 0 ;i < whichType.size() ;i ++){
		if(A[0] == 0 && whichType[i] != 0){
			while(howMany[i] < k && A[1] > 0)
				howMany[i] ++ , A[1] -- ;
		}
		else if(A[1] == 0 && whichType[i] != 1){
			while(howMany[i] < k && A[0] > 0)
				howMany[i] ++ , A[0] -- ; 
		}
	}
	
	for(int i = 0; i < whichType.size() ;i ++){

		for(int l = 0; l < howMany[i]; l ++)
			res += ch[whichType[i]];
	}
	
	return A[0] == 0 && A[1] == 0;
	
	

}
int main(){
	int  k , n , a , b ;
	cin >> n >> k >> a >> b;
	if(check(n , k , a , b , 0))
		cout << res << endl;
	else if(check(n , k ,a , b , 1))
		cout << res  << endl;
	else cout << "NO" << endl;
			

}

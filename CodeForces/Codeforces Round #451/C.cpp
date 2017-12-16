#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.in" , "r" ,  stdin);
	int n ;
	cin >> n;
	map<string , set< string > > mp;
	map<string , vector< string > > ret;
	for(int i = 0 ;i < n ;i ++){
		int no;
		string per;
		
		cin >> per >> no;
		while(no --){
			string ss;
			cin >> ss;
			mp[per].insert(ss);
		}
	}
	for(auto &mm : mp){
		vector< string > vec(mm.second.begin() , mm.second.end());
		vector< bool > yes(vec.size() );
		for(int i = 0 ; i < vec.size() ;i ++){
			for(int ii = 0 ; ii < vec.size() ;ii ++) if(i != ii && vec[ii].size() >= vec[i].size()){
				string nn = vec[ii].substr(vec[ii].size() - vec[i].size() );
				if(nn == vec[i]){
					yes[i] = 1;
					break;
				} 
			}
		}
		for(int i = 0 ;i < vec.size() ;i ++){
			if(!yes[i]){
				ret[mm.first].push_back(vec[i]);
			}
		}
	}
	cout << ret.size() << "\n";
	for(auto &mm : ret){
		cout << mm.first << " " << mm.second.size() ;
		for(int i = 0 ;i < mm.second.size() ;i ++)
			cout << " " << mm.second[i] ;
		cout << "\n";
	}
}

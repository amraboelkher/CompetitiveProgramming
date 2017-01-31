
#include<bits/stdc++.h>
using namespace std;


class HanoiTower
{
	public:
typedef pair< long long , pair< long long , pair<long long , long long >  > > pii;
long long get(string S){
    long long no = 0;
    for(int i = 0 ;i < S.size() ;i ++){
        int k = 0;
        if(S[i] == 'A')k = 1;
        if(S[i] == 'B')k = 2;
        if(S[i] == 'C')k = 3;
        no = no * 10 + k;
    }
    return no;
}
bool ck(long long  A , long long v){
    if(A == 0)return 1;
    while(A){
        if((A % 10) != v)return 0;
        A /= 10;
    }
    return 1;
}
bool check(long long A ,long long B , long long C){
    return ck(A , 1) && ck(B , 2) && ck(C , 3);
}

int solve(string A , string B , string C){
    queue < pii > Q;
    map< pair< long long , pair< long long  , long long > > , int  > S;
    Q.push({get(A) , {get(B) , {get(C) , 0} } } );
    int res = 0;
    while(!Q.empty()){
        pii cur = Q.front();Q.pop();
        long long a = cur.first , b = cur.second.first , c = cur.second.second.first ;
        int cc = cur.second.second.second;
        if(check(a , b , c))
            return cur.second.second.second;
        if(a > 0){
            int d = a % 10;
            if(!S.count({ a / 10 ,  {b * 10 + d , c} }) || S[{ a / 10 ,  {b * 10 + d , c} }] > cc + 1){
                S[{ a / 10 ,  {b * 10 + d ,c }}] = cc + 1;
                Q.push({ a / 10 ,  {b * 10 + d , {c ,  cc + 1} }});
            }
            if(!S.count({ a / 10 , {b , c * 10 + d} }) || S[{ a / 10 , {b , c * 10 + d} }] > cc + 1){
                S[{ a / 10 , {b , c * 10 +  d} }] = cc + 1;
                Q.push({ a / 10 , {b , {c * 10 + d , cc + 1} }  } );
            }
        }
        if(b > 0){
            int d = b % 10;
            if(!S.count({ a * 10 + d , {b / 10 , c} }) || S[{ a * 10 + d , {b / 10 , c} }] > cc + 1){
                S[{ a * 10 + d , {b / 10 , c}   }] = cc + 1;
                Q.push({ a * 10 + d , {b / 10 , {c , cc + 1} } } );
            }
            if(!S.count({a , {b / 10 , c * 10 + d}}) || S[{a , {b / 10 , c * 10 + d}}] > cc + 1){
                S[{a , {b / 10 , c * 10 + d } }] = cc + 1;
                Q.push({a , {b / 10 , {c * 10 + d , cc + 1} } } );
            }
        }
        if(c > 0){
            int d = c % 10;
            if(!S.count({a * 10 + d , {b , c / 10}}) || S[{a * 10 + d , {b , c / 10}}] > cc + 1){
                S[{a * 10 + d , {b , c / 10} }] = cc + 1;
                Q.push({a * 10 + d , {b , {c / 10 , cc + 1} } } );
            }
            if(!S.count({a , {b * 10 + d , c / 10}}) || S[{a , {b * 10 + d , c / 10}}] > cc + 1){
                S[{a , {b * 10 + d , c / 10} }] = cc + 1 ;
                Q.push({a , {b * 10 + d  , {c / 10 , cc + 1} } } );
            }
        }
    }

}
	 int moves(string pegA, string pegB, string pegC)
	{
		return solve(pegA , pegB , pegC );
	}


};

int main(){

}

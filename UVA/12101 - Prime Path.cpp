
#include<bits/stdc++.h>

using namespace std;
int P[100002] , vis[100002];
string get(int no){
    string s = "";
    while(no)
        s += char('0' + (no % 10)) , no /= 10;
    reverse(s.begin() , s.end());
    return s;
}
int main()
{
    for(int i = 2;i < 100000 ;i ++){
        if(!P[i])
            for(int l = i + i ;l < 100000; l += i)
                P[l] = 1;
    }
    int t;
    scanf("%d" , &t);
    while(t --){
        int from  , to;
        scanf("%d%d" , &from , &to);
        for(int i = 1000; i < 10000; i ++)
            vis[i] = 0;
        priority_queue<pair<int , int > , vector< pair<int , int > >  , greater<pair<int , int > > > Q;
        Q.push({0 , from});
        int ans = -1;
        while(Q.size()){
            pair<int , int > cur = Q.top();Q.pop();
            int c = cur.second;
            string s = get(c);
            if(vis[c])continue;
            if(c == to){
                ans = cur.first;
                break;
            }
            vis[c] = 1;
            for(int i = 0 ;i < s.size() ;i ++){
                for(int l = (i == 0); l < 10 ;l ++){
                    int k = 0;
                    for(int ii = 0 ; ii < s.size() ; ii ++){
                        if(ii == i)
                            k = k * 10 + l;
                        else k = k * 10 + (s[ii] - '0');
                    }
                    if(!vis[k] && !P[k])
                        Q.push({cur.first + 1 , k});
                }
            }
        }
        if(ans == -1)
            printf("Impossible\n");
        else printf("%d\n" , ans);

    }

}

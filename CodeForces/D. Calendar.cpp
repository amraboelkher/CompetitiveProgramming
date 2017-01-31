#include<bits/stdc++.h>
using namespace std;
char s[12];
deque< string > A[12];
int main()
{
    int  n;
    string sep;
    scanf("%d" , &n);
    int mn = 12 , mx = -1;
    for(int i = 0 ;i < n ;i ++){
        scanf("%s" , s);
        string _s = s;
        A[_s.size()].push_back(_s);
        mn = min(mn , (int)_s.size());
        mx = max(mx , (int)_s.size());
    }
    scanf("%s" , s);
    sep = s;
    for(int i = 0 ; i < 12 ; i ++)
        sort(A[i].begin() , A[i].end());
    vector< string > res;
    while(n > 0){
        n -= 2;
        string Fmn = A[mn][0] ;
        A[mn].pop_front();
        while(A[mx].size() == 0) mx --;
        string Fmx = A[mx][0];
        A[mx].pop_front();
        string s1 = Fmn + sep + Fmx , s2 = Fmx + sep + Fmn;
        if(s1 < s2) res.push_back(s1);
        else        res.push_back(s2);
        while(A[mn].size() == 0)    mn ++;
        while(A[mx].size() == 0)    mx --;
    }
    sort(res.begin() , res.end());
    for(int i = 0 ;i < res.size() ;i ++)
        printf("%s\n" , res[i].c_str());


}

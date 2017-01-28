#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 3;


class Seg{
    vector< int > T , mn , mx  ;
    vector< int > Set , Add ;
    public:
    Seg(int n){
        n = 2 * n;
        T.resize(4 * n , 0);
        mn.resize(4 * n , 1e9);
        mx.resize(4 * n , -1e9);
        Set.resize(4 * n , 0);
        Add.resize(4 * n , 0);
    }
    void up1(int idx , int l , int r , int S , int A){
        if(S >= 0){
            T[idx] = S * (r - l + 1);
            mn[idx] = mx[idx] = S;
            Set[idx] = S;
            Add[idx] = 0;
        }
        if(A != 0){
            T[idx] += A * (r - l + 1);
            mn[idx] += A;
            mx[idx] += A;
            Add[idx] += A;
        }
    }
    void change(int idx){
        T[idx] = T[idx * 2] + T[idx * 2 + 1];
        mn[idx] = min(mn[idx * 2] , mn[idx * 2 + 1]);
        mx[idx] = max(mx[idx * 2] , mx[idx * 2 + 1]);
    }
    void relax(int idx , int l , int r){
        int md = (l + r) >> 1;
        up1(idx * 2 , l , md , Set[idx] , Add[idx]);
        up1(idx * 2 + 1 , md + 1 , r ,  Set[idx] , Add[idx]);
        change(idx);
        Add[idx] = 0;
        Set[idx] = -1;
    }
    void up(int l , int r , int v , int L , int R , int idx , int k = 0 ){
        if(L > r || R < l)
            return ;
        if(L >= l && R <= r){
            if(k == 1) Add[idx] += v;
            if(k == 2) Set[idx] = v , Add[idx] = 0;
            relax(idx , L , R);
            return ;
        }
        check(idx);
        relax(idx , L , R);
        int md = (L + R) >> 1;
        up(l , r , v , L , md , idx * 2 , k);
        up(l , r , v , md + 1 , R , idx * 2 + 1 , k);
        change(idx);
    }

    int get(int l  , int r , int L , int R , int idx , int type ){
        if(L > r || R < l ){
            if(type == 1)return 0;
            if(type == 2)return 1e9;
            return -1e9;
        }
        check(idx);
        relax(idx , L , R);
        if(L >= l && R <= r){
            if(type == 1)return T[idx];
            if(type == 2)return mn[idx];
            return mx[idx];
        }
        int md = (L + R) >> 1;
        int _L = get(l , r , L , md , idx * 2 , type) ;
        int _R = get(l , r , md + 1 , R , idx * 2 + 1 , type);
        if(type == 1)return _L + _R;
        if(type == 2)return min(_L , _R);
        return max(_L , _R);
    }
};



int main()
{
    int N , M , O;
    while(scanf("%d%d%d" , &N , &M , &O) != EOF){
            vector < Seg > T;
            for(int i = 0 ; i < N ;i ++){
                T.push_back(Seg(M));
            }
            int type , x1 ,y1 , x2 , y2 , v;
            while(O --){
                scanf("%d" , &type);
                if(type < 3){
                    scanf("%d%d%d%d%d" , &x1 , &y1 , &x2 , &y2 , &v);
                    for(int i = x1 - 1; i < x2; i ++)
                        T[i].up(y1 -  1 , y2 - 1 , v , 0 , M - 1 , 1 , type);
                }
                else {
                    scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2);
                    int res = 0 , mn = 1e9 + 10 , mx = -1e9 - 10;
                    for(int i = x1 - 1;  i < x2 ; i ++){
                        assert(i < T.size());
                        res += T[i].get(y1 - 1 , y2 - 1 , 0 , M - 1 , 1 , 1) ;
                        mn = min(mn , T[i].get(y1 - 1 , y2 - 1 , 0 , M - 1 , 1 , 2) ) ;
                        mx = max(mx , T[i].get(y1 - 1,  y2 - 1 , 0 , M - 1 , 1 , 3) ) ;
                    }
                    printf("%d %d %d\n" , res , mn , mx);
                }
            }
    }
}

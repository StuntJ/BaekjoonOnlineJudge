#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ll fpow(ll n, ll p){
    if(p==0) return 1;
    ll temp = fpow(n,p/2);
    ll ret = temp*temp;
    if(p&1) return ret*n;
    return ret;
}

int solution(int dist_limit, int split_limit) {
    int answer = 0;
    
    for(ll x = 0; fpow(3,x)<=split_limit; x++){
        ll t = fpow(3,x);
        ll y = 0;
        while(t * fpow(2,y)<=split_limit) y++;
        y--;
        
        int cnt = 1;
        int curx = x;
        int cury = y;
        int lim = dist_limit;
        int leaf = 1;
        bool flag = false;
        while(cury--){
            if(lim>leaf){
                lim -= leaf;
                leaf *=2;
                cnt = leaf;
                    
            }
            else{
                cnt = leaf - lim + lim*2;
                leaf = lim*2;
                lim = 0;
                flag = true;
            }
            if(flag) break;
        }
        
        
        if(!flag){
            while(curx--){
                if(lim>leaf){
                    lim -= leaf;
                    leaf *= 3;
                    cnt = leaf;                     
                }
                else{
                    cnt = leaf - lim + lim*3;
                    leaf = lim*3;
                    lim = 0;
                    flag = true;
                }
                if(flag) break;
            }
        }
        
        answer = max(answer,cnt);
        
        cnt = 1;
        curx = x;
        cury = y;
        lim = dist_limit;
        leaf = 1;
        flag = false;
        
        
        while(curx--){
            if(lim>leaf){
                lim -= leaf;
                leaf *= 3;
                cnt = leaf;                     
            }
            else{
                cnt = leaf - lim + lim*3;
                leaf = lim*3;
                lim = 0;
                flag = true;
            }
            if(flag) break;
        }
        
        if(!flag){
            while(cury--){
                if(lim>leaf){
                    lim -= leaf;
                    leaf *=2;
                    cnt = leaf;
                    
                }
                else{
                    cnt = leaf - lim + lim*2;
                    leaf = lim*2;
                    lim = 0;
                    flag = true;
                }
                if(flag) break;
            }
        }
        answer = max(answer,cnt);
    }
        
    return answer;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

struct token{
    bool open = false;
    ll top;
    ll bottom;
    token(ll _top, ll _bottom) : top(_top), bottom(_bottom) {
        ll g = gcd(top,bottom);
        top/=g; bottom/=g;
    };

    token(){
        open = true;
    }

    token operator / (const token &rhs) const{
        return token(top*rhs.bottom, bottom*rhs.top);
    }

    token operator + (const token &rhs) const{  
        ll g = gcd(bottom,rhs.bottom);
        ll lcm = bottom*rhs.bottom/g;
        ll newTop = top*lcm/bottom;
        ll newRhsTop = rhs.top*lcm/rhs.bottom;
        ll totTop = newTop + newRhsTop;
        return token(totTop,lcm);
    }
};

void wrong(){
    cout<<-1;
    exit(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<token> st;

    int N;
    cin>>N;
    string expression;
    cin.ignore();
    getline(cin,expression);

    for(int i=0;i<expression.size();i++){
        if(expression[i]==' ') continue;
        else if(expression[i]=='(') st.push(token());
        else if('0'<=expression[i]&&expression[i]<='9')
            st.push(token(expression[i]-'0',1));
        else if(expression[i]==')'){
            if(st.empty()) wrong();
            token a = st.top(); st.pop();
            if(st.empty()) wrong();
            token b = st.top(); st.pop();
            if(st.empty()) wrong();
            token c = st.top(); st.pop();
            if(st.empty()) wrong();
            if(!st.top().open) wrong();
            st.pop();
            if(a.open||b.open||c.open) wrong();
            st.push(c+b/a); 
        }
        else wrong();
    }
    if(st.size()!=1) wrong();
    token ans = st.top();
    if(ans.open) wrong();
    cout<<ans.top<<' '<<ans.bottom;
}
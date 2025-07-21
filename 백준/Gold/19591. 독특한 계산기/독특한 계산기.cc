#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;

    string digBuf;
    deque<ll> dq;
    bool firstm = false;
    for(int i=0;i<str.size();i++){
        if(i==0 &&str[i]=='-'){
            firstm = true;
            continue;
        }
        if(str[i]=='*'||str[i]=='/'||str[i]=='-'||str[i]=='+'){
            dq.push_back(stoll(digBuf));
            digBuf.clear();
            dq.push_back(str[i]);
        }
        else digBuf.push_back(str[i]);
    }
    dq.push_back(stoll(digBuf));
    digBuf.clear();

    if(firstm){
        ll x = -dq.front();
        dq.pop_front();
        dq.push_front(x);
    }

    auto cal = [&](ll a, ll b, char op){
        switch(op){
            case '+':
            return a+b;
            case '-':
            return a-b;
            case '/':
            return a/b;
            case '*':
            return a*b;
        }
    };

    while(dq.size()!=1){
        ll fa,fb,fop,sa,sb,sop;
        bool f = true, b = true;
        fa = dq.front();
        dq.pop_front();
        fop = dq.front();
        dq.pop_front();
        fb = dq.front();
        dq.pop_front();
        
        bool co = false;
        if(dq.size()>=3){
            sb = dq.back();
            dq.pop_back();
            sop = dq.back();
            dq.pop_back();
            sa = dq.back();
            dq.pop_back();
        }
        else if(dq.size()==2){
            sb = dq.back();
            dq.pop_back();
            sop = dq.back();
            dq.pop_back();
            sa = fb;
            co = true;
        }
        else{
            dq.push_front(cal(fa,fb,fop));
            continue;
        }

        if(b){
            if((fop=='*'||fop=='/') && (sop=='+'||sop=='-')){
                b = false;
            }
            if((fop=='+'||fop=='-') && (sop=='*'||sop=='/')){
                f = false;
            }
        }
        if(!f){
            dq.push_back(cal(sa,sb,sop));
            if(!co)
                dq.push_front(fb);
            dq.push_front(fop);
            dq.push_front(fa);
            continue;
        }
        if(!b){
            dq.push_front(cal(fa,fb,fop));
            if(!co)
                dq.push_back(sa);
            dq.push_back(sop);
            dq.push_back(sb);
            continue;
        }

        ll fcal = cal(fa,fb,fop);
        ll scal = cal(sa,sb,sop);
        if(fcal>=scal){
            dq.push_front(cal(fa,fb,fop));
            if(!co)
                dq.push_back(sa);
            dq.push_back(sop);
            dq.push_back(sb);
            continue;
        }
        else{
            dq.push_back(cal(sa,sb,sop));
            if(!co)
                dq.push_front(fb);
            dq.push_front(fop);
            dq.push_front(fa);
            continue;
        }
    }
    cout<<dq.front();
}
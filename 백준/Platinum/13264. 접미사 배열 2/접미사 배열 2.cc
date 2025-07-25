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

//정렬을 시행하는 기준
struct Comparator{
    const vector<int> &group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group),t(_t){}

    bool operator () (int a, int b){
        if(group[a]!=group[b]) return group[a]<group[b];
        return group[a+t]<group[b+t];
    }    
};

//접미사 배열을 구하는 함수이다. s인수로 주고 위의 구조체와 복붙하여 사용하면 된다.
vector<int> getSuffixArray(const string &s){
    int n = s.size();

    int t = 1;
    vector<int> group(n+1);
    for(int i=0;i<n;i++) group[i] = s[i];
    group[n] = -1;
    vector<int> perm(n);
    for(int i=0;i<n;i++) perm[i] = i;
    while(t<n){
        Comparator compareUsing2T(group,t);
        //perm에 순위 매기기 (a,b는 perm에 들어있는 값)
        //group[a]==group[b] 이면 return group[a+t]<group[b+t]
        //이외에는 return group[a]<group[b]
        sort(perm.begin(),perm.end(),compareUsing2T);
        //t갱신
        t*=2;
        if(t>=n) break;

        //group[a]==group[b] 이고 group[a+t]==group[b+t] 이면 다음 group의 값이 같아야한다.
        //하지만 현재 perm에서는 위 조건을 만족해도 숫자가 다르다.
        //perm[i-1] 과 perm[i]가 위의 두 조건을 만족할 경우 숫자를 같게 만든다. 
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for(int i=1;i<n;i++){
            if(compareUsing2T(perm[i-1],perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group = newGroup;
    }
    return perm;
}

//lcp 배열은 (Longest Common Prefix) 즉, SuffixArray배열의 이웃하는 접미사의 최장 공통 접두사를 말한다.
//여기서 이웃한다는 것은 SuffixArray배열에서 index가 이웃한다는 것이다. 즉 순위가 1차이나는 것들이다.
//lcp[i]는 sfx[i]와 sfx[i-1]의 최장 공통 문자열이다.
//lcp 배열을 구하는 함수 첫번째 인자는 getSuffixArray의 결과이고, 두번째 인자는 문자열이다.
vector<int> getLCP(vector<int> &sfx, const string &s){
    //s[i-1 ..] 과 이웃하는 앞 접미사와의 LCP값을 I라고 하고, 이 값이 1보다 크다면, S[i..]과 이웃하는 앞 접미사와의 LCP값은 I-1 이상임을 이용한다.
    //now를 i값이라고 생각하면 된다. algorithm 노트에 이를 증명해놓았다.
    ll n = sfx.size();
    vector<int> rev(n);
    vector<int> ret(n);
    for(int i=0;i<n;i++) rev[sfx[i]] = i;
    int now = 0;
    for(int i=0;i<n;i++){
        if(rev[i]>0){
            while(s[i+now]==s[sfx[rev[i]-1]+now]) now++;
            ret[rev[i]] = now;
        }
        if(now) now--;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;
    vector<int> v = getSuffixArray(str);
    for(auto &i : v) cout<<i<<'\n';
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

vector<int> getLCP(vector<int> &sfx, const string &s){
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;
    vector<int> sfarr = getSuffixArray(str);
    for(auto i : sfarr) cout<<i+1<<' ';
    cout<<'\n';
    vector<int> lcp = getLCP(sfarr,str);
    cout<<'x'<<' ';
    for(int i=1;i<str.size();i++) cout<<lcp[i]<<' ';
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    unordered_set<int> st;
    int M;
    cin>>M;
    while(M--){
        int x;
        cin>>x;
        st.insert(x);
    }

    int s1 = abs(N-100);

    auto able = [&](int x)->bool{
        if(x==0){
            if(st.find(x)!=st.end()) return false;
            return true;
        }
        while(x>0){
            int md = x%10;
            if(st.find(md)!=st.end()) return false;
            x/=10;
        }
        return true;
    };

    const int INF = 1e9;
    int s2 = INF;
    for(int i=N;i<N+500000;i++){
        if(able(i)){
            s2 = abs(N-i) + to_string(i).size();
            break;
        }
    }
    int s3 = INF;
    for(int i=N;i>=0;i--){
        if(able(i)){
            s3 = abs(N-i) + to_string(i).size();
            break;
        }
    }

    cout<<min(s1,min(s2,s3));
}
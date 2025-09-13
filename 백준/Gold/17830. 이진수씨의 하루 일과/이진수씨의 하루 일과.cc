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

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        vector<int> vm(3*N), vM(3*N);

        string B;
        cin>>B;

        string Bm = B, BM = B;
        for(auto &i : Bm) if(i=='?') i = '0';
        for(auto &i : BM) if(i=='?') i = '1';

        reverse(Bm.begin(),Bm.end());
        reverse(BM.begin(),BM.end());

        for(int i=0;i<N;i++){
            if(Bm[i]=='1'){
                vm[i]++;
                vm[i+N]--;
            }
            if(BM[i]=='1'){
                vM[i]++;
                vM[i+N]--;
            }
        }
        
        for(int i=1;i<N*3;i++){
            vm[i] += vm[i-1];
            vM[i] += vM[i-1];
        }

        int dgM = 1, dgm = 1;
        for(int i=0;i<N*3-1;i++){
            if(vm[i]>1){
                vm[i+1] += vm[i]/2;
                vm[i] = vm[i]%2;
            }
            if(vM[i]>1){
                vM[i+1] += vM[i]/2;
                vM[i] = vM[i]%2;
            }
        }
        for(int i=0;i<N*3;i++){
            if(vm[i]>0) dgm = max(1,i+1);
            if(vM[i]>0) dgM = max(1,i+1);
        }
        cout<<dgM<<' '<<dgm<<'\n';
    }
}
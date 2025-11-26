#include <bits/stdc++.h>

using namespace std;

int total[367];
int tab[367];
int space[367];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    int ans5 = 0;
    for(int i=0;i<N;i++){
        char c;
        int s,e;
        cin>>c;
        cin>>s>>e;
        ans5 = max(ans5,(e-s+1));

        for(int i=s;i<=e;i++){
            total[i]++;
            if(c=='T') tab[i]++;
            else space[i]++;
        } 
    }

    int ans1 = 0;
    for(int i=1;i<367;i++) if(total[i]) ans1++;
    int ans2 = *max_element(total+1,total+367);

    int ans3 = 0;
    int ans4 = 0;
    for(int i=1;i<367;i++){
        if(total[i]){
            if(tab[i]==space[i]){
                ans3++;
                ans4 = max(total[i],ans4);
            }
        }
    }
    cout<<ans1<<'\n';
    cout<<ans2<<'\n';
    cout<<ans3<<'\n';
    cout<<ans4<<'\n';
    cout<<ans5<<'\n';
}
#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    int orT = T;

    while(T--)
    {
        int N,M;
        cin>>N;
        vector<string> engine(N);


        cin.ignore();
        for(int i=0;i<N;i++) getline(cin,engine[i]);

        cin>>M;
        vector<string> query(M);

        cin.ignore();
        for(int i=0;i<M;i++) getline(cin,query[i]);

        set<string> st;
        int count = 0;
        for(int i=0;i<M;i++)
        {
            if(st.find(query[i])==st.end())
            {
                if(st.size()==N-1)
                {
                    st.clear();
                    count++;
                }
                st.insert(query[i]);
            }
        }

        cout<<"Case #"<<orT-T<<": "<<count<<'\n';
    }
}

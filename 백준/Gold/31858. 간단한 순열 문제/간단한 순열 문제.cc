#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    stack<int> st;

    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;

        if(st.empty())
        {
            st.push(x);
            continue;
        }

        while(!st.empty()&&st.top()<x)
        {
            st.pop();
            cnt++;
        }

        if(!st.empty()) cnt++;
        st.push(x);
    }

    cout<<cnt;
}

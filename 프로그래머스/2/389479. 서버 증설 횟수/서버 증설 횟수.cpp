#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(24);
    for(int i=0;i<players.size();i++){
        int t = players[i]/m;
        if(t>server[i]){
            int inc = t-server[i];
            for(int j=i;j<min(24,i+k);j++){
                server[j]+=inc;
            }
            answer += inc;
        }
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

const int defaultHP = 20;
const int defaultAT = 2;
const int defaultDEF = 2;
const int defaultLV = 1;
const int defaultexpFull = 5;
class CharacterStat;
class Monster;
class Character;
class itemEffect;
class itemInfo;


int N,M;
vector<vector<char>> grid;
map<pair<int,int>,Monster> mon;
map<pair<int,int>,itemInfo> items;
string endMessage;

class itemInfo{
    friend class Character;
public:
    itemInfo(char st, string itemtype){
        type = st;
        pr = itemtype;
    }
    itemInfo(char st, int x){
        type = st;
        n = x;
    }
    //itemInfo() {}
    void print(){
        cout<<type<<' '<<pr<<' '<<n<<'\n';
    }

private:
    char type;
    string pr;
    int n;
};

class itemEffect{
    friend class Character;
public: 
    itemEffect() : number(0), adAttack(0), adDefense(0), HR(false), RE(false), CO(false), EX(false), DX(false), HU(false), CU(false) {}
        
    void changeadAttack(int x){ //공격력이 x인 공템으로 바꾸기 
        adAttack = x;
    }

    void changeadDefense(int x){ //공격력이 x인 방템으로 바꾸기
        adDefense = x;
    }

private: 
    int number; //bool 형식이 켜진 숫자만큼. 4개이상 불가.
    int adAttack; //추가 공격력 1개만 착용가능
    int adDefense; //추가 방어력 1개만 착용가능
    bool HR; //전투 승리시 +3회복
    bool RE; //최대체력 부활 & 시작위치로 돌려보내기. 전투중인 몬스터 있으면 그녀석 체력도 full 주인공 사망시 소멸 regain가능
    bool CO; //첫 공격 2배 데미지. DX와 함께라면 3배
    bool EX; //얻는 경험치 1.2배
    bool DX; //가시함정 데미지 1. CO 성능 좋아짐.
    bool HU; //전투 돌입시 순간체력 최대치. '보스'첫공격 무시
    bool CU; //효과 없음
};


class HP{
    friend class CharacterStat;
    friend class Character;
public:
    HP(int ful) : now(ful), full(ful) {};
    //HP() {}
    void hpUP(int x){ //hp 총량 x만큼 올려주는 함수
        full += x;
    }

    void hpRecover(int x){ //x만큼 체력회복
        now = max(0,min(now+x,full));
    }

    void hpFull(){ //hp를 꽉 채워주는 함수
        now = full;
    }
private:
    int now;
    int full;
};

class CharacterStat{
    friend class Character;
public:
    CharacterStat() : hp(defaultHP), attack(defaultAT), defense(defaultDEF), LV(1), expFull(defaultexpFull), expNow(0){}

    void hpFull(){
        hp.hpFull();
    }

    void hpRecover(int x){
        hp.hpRecover(x);
    }

    int showHp(){
        return hp.now;
    }

    void levelUp(){
        LV++;
        attack += 2;
        defense += 2;
        hp.hpUP(5);
        hp.hpFull();
    }

    void getExp(int exp, bool isEX){
        if(isEX) exp = exp*6/5;
        expNow += exp;
        if(expNow>=expFull){ //level up
            levelUp();
            expNow = 0;
            expFull = LV*5;
        }
    }
        
private:
    HP hp;
    int attack;
    int defense;
    int LV;
    int expFull;
    int expNow;
};

class Monster{
    friend class Character;
public: 
    Monster(const string &s, int _hp, int _defense, int _attack, int _exp, bool _isBoss) : name(s), hp(_hp), defense(_defense), attack(_attack), exp(_exp), isBoss(_isBoss) {}

    //Monster() {}

    int getexp(){
        return exp;
    }

    void hpFull(){
        hp.hpFull();
    }

    string getName(){
        return name;
    }

    bool isBossMonster(){
        return isBoss;
    }
private:
    bool isBoss;
    string name;
    HP hp;
    int defense;
    int attack;
    int exp;
};

class Character{
public:
    Character(int _x, int _y) : stat(), effect(), x(_x), y(_y), T(0) {
        stx = _x;
        sty = _y;
        isOnspike = false;
    }

    void defineItem(){ //armor 0, item 1
        itemInfo &item = items.find({x,y})->second;
        if(item.type =='O') getItem(item.pr);
        else getItem(item.type,item.n);
    } 

    void getItem(char &c, int N){ //무기 or 방어구
        if(c=='W'){ //무기인 경우
            effect.changeadAttack(N);
        } 
        else{ //방어구인 경우
            effect.changeadDefense(N);
        }
    }
    void getItem(string &s){
        if(effect.number==4) return;
        if(s=="HR" && !effect.HR){
            effect.HR = true;
            effect.number++;
        } 
        else if(s=="RE" && !effect.RE){
            effect.RE = true;
            effect.number++;
        } 
        else if(s=="CO" && !effect.CO){
            effect.CO = true;
            effect.number++;
        } 
        else if(s=="EX" && !effect.EX){
            effect.EX = true;
            effect.number++;
        } 
        else if(s=="DX" && !effect.DX){
            effect.DX = true;
            effect.number++;
        } 
        else if(s=="HU" && !effect.HU){
            effect.HU = true;
            effect.number++;
        } 
        else if(s=="CU" && !effect.CU){
            effect.CU = true;
            effect.number++;
        } 
    }   

    int spikeEffect(){ //0 죽음 1 생존
        int damage = 5;
        if(effect.DX) damage = 1;
        stat.hpRecover(-damage);
        if(stat.showHp()<=0){
            if(effect.RE){
                isOnspike = false;
                grid[x][y] = '^';
                x = stx;
                y = sty;
                grid[x][y] = '@';
                effect.RE = false;
                effect.number--;
                stat.hpFull();
                return 1;
            }
            else{
                grid[x][y] = '^';
                endMessage = "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
                return 0;
            }
        }
        return 1;
    }

    bool fightMonster(Monster &mon){ // 몬스터를 만나서 싸우다.
        if(effect.HU && mon.isBoss) stat.hpFull();
        int playerAttack = stat.attack + effect.adAttack;
        int monsterAttack = mon.attack;
        bool playerFirstAttack = true, monsterFirstAttack = true;

        while(stat.hp.now>0 && mon.hp.now>0){
            int nowPlayerAttack = playerAttack;
            if(playerFirstAttack){
                if(effect.CO){
                    if(effect.DX) nowPlayerAttack *= 3;
                    else nowPlayerAttack *= 2;
                }
            }
            int totalPlayerAttack = max(1,nowPlayerAttack-mon.defense);
            mon.hp.hpRecover(-totalPlayerAttack);
            if(mon.hp.now==0) return true;

            int nowMonsterAttack = monsterAttack;
            int totalMonsterAttack = max(1,nowMonsterAttack-stat.defense-effect.adDefense);
            if(monsterFirstAttack && effect.HU && mon.isBoss) totalMonsterAttack = 0;
            stat.hpRecover(-totalMonsterAttack);
            if(stat.hp.now==0) return false;

            playerFirstAttack = false;
            monsterFirstAttack = false;
        }
    }

    int moveto(char &order){ //지정된 곳으로 이동. 2이김 1 정상이동 0 die 
        int nx = x, ny = y;
        if(order=='U') nx--;
        if(order=='D') nx++;
        if(order=='R') ny++;
        if(order=='L') ny--;
        if(!(1<=nx && nx<=N && 1<=ny && ny<=M)){
            if(isOnspike){
                return spikeEffect();
            }
            return 1;
        } 
        if(grid[nx][ny]=='#'){
            if(isOnspike){
                return spikeEffect();
            }
            return 1;
        }
        if(grid[nx][ny]=='.'){
            if(isOnspike){
                grid[x][y] = '^';
                isOnspike = false;
            } 
            else grid[x][y] = '.';
            grid[nx][ny] = '@';

            x = nx;
            y = ny;
            return 1;
        }
        if(grid[nx][ny]=='&'||grid[nx][ny]=='M'){
            Monster &opponent = mon.find({nx,ny})->second;
            if(!fightMonster(opponent)){
                if(effect.RE){ //졌는데 RE item 있음
                    if(isOnspike) isOnspike = false;
                    //RE소멸
                    effect.RE = false;
                    effect.number--;
                    //몬스터 hpFull로
                    opponent.hpFull();
                    //좌표 초기화
                    if(isOnspike) grid[x][y] = '^'; //가시위에서 tp
                    else grid[x][y] = '.';
                    grid[stx][sty] = '@';
                    x = stx;
                    y = sty;
                    //플레이어 hpFull로
                    stat.hpFull();
                    return 1;
                }
                else{
                    endMessage = "YOU HAVE BEEN KILLED BY " + opponent.getName() + "..";
                    if(isOnspike) grid[x][y] = '^'; //가시위에서 죽은 경우
                    else grid[x][y] = '.'; //플레이어 죽었으니 grid 빈칸으로
                    return 0;
                } 
            }
            else{ //이김
                if(effect.HR) stat.hpRecover(3); //hr 있으면 3회복
                stat.getExp(opponent.getexp(),effect.EX);
                if(isOnspike){
                    isOnspike = false;
                    grid[x][y] = '^';
                } 
                else grid[x][y] = '.';
                grid[nx][ny] = '@';
                x = nx;
                y = ny;
                //보스 몬스터인지 확인
                if(opponent.isBossMonster()){
                    endMessage = "YOU WIN!";
                    return 2;
                } 
                else return 1;
            }
        }
        if(grid[nx][ny]=='^'){
            if(isOnspike) grid[x][y] = '^';
            else grid[x][y] = '.';
            grid[nx][ny] = '@';
            isOnspike = true;
            x = nx;
            y = ny;
            return spikeEffect();
        }
        if(grid[nx][ny]=='B'){
            if(isOnspike){
                grid[x][y] = '^';
                isOnspike = false;
            } 
            else grid[x][y] = '.';
            grid[nx][ny] = '@';

            x = nx;
            y = ny;
            defineItem();
            return 1;
        }
        return 1;
    }

    void print(){
        cout<<"LV : "<<stat.LV<<'\n';
        cout<<"HP : "<<stat.hp.now<<"/"<<stat.hp.full<<'\n';
        cout<<"ATT : "<<stat.attack<<"+"<<effect.adAttack<<'\n';
        cout<<"DEF : "<<stat.defense<<"+"<<effect.adDefense<<'\n';
        cout<<"EXP : "<<stat.expNow<<"/"<<stat.expFull<<'\n';
    }

private:
    CharacterStat stat;
    itemEffect effect;
    bool isOnspike;
    int x;
    int stx;
    int y;
    int sty;
    int T;
};

int main(){
    cin>>N>>M;
    grid = vector<vector<char>>(N+1,vector<char>(M+1));
    int monSize = 0, itemSize = 0;
    int bossx, bossy;
    int chx,chy;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='&'||grid[i][j]=='M') monSize++;
            if(grid[i][j]=='B') itemSize++;
            if(grid[i][j]=='M'){
                bossx = i; bossy = j;
            }
            if(grid[i][j]=='@'){
                chx = i; chy = j;
            }
        } 
    } 

    Character player(chx,chy);
    
    string instruction;
    cin>>instruction;

    for(int i=0;i<monSize;i++){
        int x,y;
        string name;
        int attack, defense, hpMax, exp;
        cin>>x>>y>>name>>attack>>defense>>hpMax>>exp;
        mon.insert({{x,y},Monster(name,hpMax,defense,attack,exp,(x==bossx&&y==bossy))});
    }

    for(int i=0;i<itemSize;i++){
        int x,y;
        char type;
        cin>>x>>y>>type;
        if(type=='O'){
            string st;
            cin>>st;
            items.insert({{x,y},itemInfo(type,st)});
        }
        else{
            int t;
            cin>>t;
            items.insert({{x,y},itemInfo(type,t)});
        }
    }

    int idx = 0;
    for(int i=0;i<instruction.size();i++){
        idx++;
        char order = instruction[i];
        int moveRes = player.moveto(order);
        if(moveRes!=1) break;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<grid[i][j];
        }
        cout<<'\n';
    }

    cout<<"Passed Turns : "<<idx<<'\n';
    player.print();
    cout<<(endMessage!="" ? endMessage : "Press any key to continue.")<<'\n';
    //items.find({6,6})->second.print();
}

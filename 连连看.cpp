//本题因为刷题太少也是修改了很久  也借鉴了一些   总算是改对了 
//本题要求路线转折次数小于两次  等同于寻找最短路的问题（路线越短转折越少） 
// 寻找最短路问题自然就用广搜  本题加了一个标记走到每一步的最小步数 

#include<iostream>
#include<queue>
#include<cstring>
#define MAXN 1000+10
using namespace std;
struct node{
	int x, y, dir, turn;
};
queue<node> que;
int inf[MAXN][MAXN];//储存界面 
int Min[MAXN][MAXN];//标记走到当前点用的最小步数 
int n, m;
int question,x1,y1,x2,y2;
int dir_x[4]={-1,1,0,0},dir_y[4]={0,0,-1,1};

bool judge(node &inf){
    if(inf.x >= 1 && inf.x <= n && inf.y >= 1 && inf.y <= m) 
	return true;
    return false;
} //判断下一步是否可走 

void input(){
	int i, j;
	for(i = 1; i <= n; i++)
	    for(j = 1; j <= m; j++)
	        cin >> inf[i][j];
}

bool bfs(){
	node cur,next;
    while(que.size()){
        cur = que.front();
        que.pop();
        if(cur.x == x2 && cur.y == y2 && cur.turn <= 2) return true;
        for(int i = 0; i < 4; i++){
            if(cur.dir != i){
                next.dir = i;
                next.turn = cur.turn+1;
            }
            else{
                next.dir = cur.dir;
                next.turn = cur.turn;
            }
            if(next.turn > 2) continue;
            next.x = cur.x + dir_x[i], next.y = cur.y + dir_y[i];
            if((!inf[next.x][next.y] || (next.x == x2 && next.y == y2)) && judge(next) && Min[next.x][next.y] >= next.turn){
                que.push(next);
                Min[next.x][next.y] = next.turn;
            }
        }
    }
    return false;
} //深搜 

void solve(){
	cin >> question;
    while(question--){
        cin >> x1 >> y1 >> x2 >>y2;
        if((inf[x1][y1] != inf[x2][y2]) || !inf[x1][y1] || !inf[x2][y2] || (x1 == x2 && y1 == y2)){
            cout << "NO" <<endl;
            continue;
    }
    while(!que.empty()) que.pop();
    memset(Min, 1, sizeof(Min));
    node start;
    start.x = x1, start.y = y1, start.turn = 0;
    for(int i = 0; i<4; i++){
        start.dir = i;
        que.push(start);
    }
    Min[x1][y1] = 0;
    if(bfs()) {
    	cout << "YES" <<endl;
	}else cout << "NO" <<endl;
}
}

int main(){
	while(1){
	cin >> n >> m;
	if(n == 0 || m == 0) break;
	input();
	solve();
	}
}

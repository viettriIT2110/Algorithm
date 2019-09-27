#include<bits/stdc++.h>
using namespace std;

int a[1000][1000],N,M;
int cnt = 0;
int X[] = {0,0,-1,1};
int Y[] = {1,-1,0,0};

bool visit[1000][1000];
int level[1000][1000];

bool dk(int x,int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}

void nhap(){
    for(int i=0; i < N;i++){
        for(int j=0;j < M;j++)
            cin >> a[i][j];
    }
}

void DFS(int x,int y){
    cnt++;
    visit[x][y] = true;
    cout << x << ' ' << y << endl ;
    for(int i = 0;i < 4;i++){
        int fx = x + X[i];
        int fy = y + Y[i];
        if (dk(fx,fy) && !visit[fx][fy] && a[fx][fy] == 0){
            DFS(fx,fy);
        }
    }
}

void BFS(int startX,int startY){
    queue< pair<int,int> > Q;
    pair <int,int> top;
    Q.push({startX,startY});
    while(!Q.empty()){
        top = Q.front();
        Q.pop();
        cnt++;
        visit[top.first][top.second] = true;
        cout << top.first << ' ' << top.second << '\n';
        for(int i = 0;i < 4;i++){
            int fx = top.first + X[i];
            int fy = top.second + Y[i];
            if (dk(fx,fy) && !visit[fx][fy] && a[fx][fy] == 0){
                Q.push({fx,fy});
                level[fx][fy]= level[top.first][top.second]+1;
                visit[fx][fy]=1;
            }
        }
    }
}
void reset(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            visit[i][j] = false;
        }
    }
}
int main(){
    cin >> N >> M;
    DFS(0,0);
    cout << "DFS mang 2 chieu: " << cnt << '\n';
    reset();
    BFS(0,0);
    cout << "BFS mang 2 chieu: " << cnt << '\n';
}

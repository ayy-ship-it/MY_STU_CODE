#include<iostream> 
using namespace std;
const int N = 30;
int w,h;
char st[N][N];//存储地图 
bool st1[N][N];//存储是否访问过 
int ret = 0; //存储结果 
//方向向量 
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x,int y){
	//当某一个点的四周都没有未访问过的点就返回上一层 
	for(int i = 0;i < 4;i++){
		int a = x + dx[i];
		int b = y + dy[i];
		if(a < 0 || a >= h || b < 0 || b >= w) continue;
		if(st[a][b] == '#') continue;
		if(!st1[a][b]){
			st1[a][b] = true;
			ret++;
			dfs(a,b);//这句结束后不要return,要搜索四个方向 
		} 
	}
}

int main(){
	cin >> w >> h;
	for(int i = 0;i < h;i++){
		scanf("%s",st[i]);
	}
	
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(st[i][j] == '@'){
				st1[i][j] = true;
				dfs(i,j);
				break; //找到起点就可以终止循环了 
			}
		}
	}
	
	cout << ret+1;
	
	return 0;
}




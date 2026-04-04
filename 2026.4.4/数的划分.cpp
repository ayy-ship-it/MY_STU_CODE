#include<iostream>

using namespace std;
const int N = 10;
int n,k;
int a[N];
int ret = 0;

void dfs(int pos,int start,int nowSum){
	
	
	if(nowSum > n) return ;
	
	if(pos > k){
		if(nowSum == n){
			ret++;
		}
		return ;
	}
	
	
	
	for(int i = start;i <= n - nowSum;i++){
		a[pos] =  i;
		dfs(pos+1,i,nowSum+i);
	}
	
	
}


int main(){
	cin >> n >> k;
	dfs(1,1,0);
	
	cout << ret << endl;
	
	
	
	return 0;
}

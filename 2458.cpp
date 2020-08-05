#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> r;
vector<int> check;
int n,m;
void printArr(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<r[i].size();j++){
			printf("%d ",r[i][j]);
		}
		printf("\n");
	}
}
int taller(int x){
	int cnt=1;
	for(int i=0;i<v[x].size();i++){
		int temp=v[x][i];
		if(check[temp]==0){
			check[temp]=1;
			cnt+=taller(temp);
		}
	}
	return cnt;
}
int smaller(int x){
	int cnt=1;
	for(int i=0;i<r[x].size();i++){
		int temp=r[x][i];
		if(check[temp]==0){
			check[temp]=1;
			cnt+=smaller(temp);
		}
	}
	return cnt;
}
int main(){
//	freopen("2458.txt","r",stdin);
	scanf("%d %d",&n,&m);
	v.resize(n+1);
	r.resize(n+1);
	check.resize(n+1);
//	printf("%d %d",n,m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		r[y].push_back(x);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int tall=0;
		for(int j=1;j<=n;j++) check[j]=0;
		tall=taller(i)-1;
		
		int small=0;
		for(int j=1;j<=n;j++) check[j]=0;
		small=smaller(i)-1;
	//	printf("%d %d\n",tall,small);
		if((tall+small)==n-1)
			cnt++;
	}
	printf("%d",cnt);
}

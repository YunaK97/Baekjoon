#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];
void printArr(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int go(int n,int m){
	if(n<1||m<1)
		return 0;
	if(d[n][m]>=0)
		return d[n][m];
		
	d[n][m]=max(go(n-1,m),go(n,m-1))+a[n][m];
	return d[n][m];
}
int main(){
//	freopen("11048.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	//printf("%d %d",n,m);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	memset(d,-1,sizeof(d));
//	printArr(n,m);
	printf("%d",go(n,m));
}

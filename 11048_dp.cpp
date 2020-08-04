#include<iostream>
#include<algorithm>
int a[1001][1001];
int d[1001][1001];
using namespace std;

void printArr(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
}
int max3(int x,int y,int z){
	return max(x,max(y,z));
}
int main(){
	freopen("11048.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	//printf("%d %d",n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
			
//	printArr(n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=max3(d[i-1][j],d[i][j-1],d[i-1][j-1])+a[i][j];	
		}
	}
	printArr(n,m);
	printf("%d",d[n][m]);
}

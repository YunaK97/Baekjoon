#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
int n,m;
int main(){
	freopen("1940.txt","r",stdin);
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
		 //계산의 순서를 작은값부터 탐색하기위해 정렬시킴
	sort(v.begin(),v.end());
	int start=0,end=n-1;
	 //이분탐색 응용
	int count=0;
	while(start<end){
		if(v[start]+v[end]<m){
			start++;
		}
		else if(v[start]+v[end]>m){
			end--;
		}
		else{//start+end가 m이면
      //다음 탐색할 값은 start++,end--번쨰다.
			count++;
			start++;
			end--;
		}
	}
	cout<<count;
}

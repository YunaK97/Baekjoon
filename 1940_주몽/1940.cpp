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
		 //����� ������ ���������� Ž���ϱ����� ���Ľ�Ŵ
	sort(v.begin(),v.end());
	int start=0,end=n-1;
	 //�̺�Ž�� ����
	int count=0;
	while(start<end){
		if(v[start]+v[end]<m){
			start++;
		}
		else if(v[start]+v[end]>m){
			end--;
		}
		else{//start+end�� m�̸�
      //���� Ž���� ���� start++,end--������.
			count++;
			start++;
			end--;
		}
	}
	cout<<count;
}

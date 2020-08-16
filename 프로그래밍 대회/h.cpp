#include<iostream>
#include<string>
#include<vector>
int c,n,x;
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("h.txt","r",stdin);
	cin>>c>>n;
	vector<vector<string>> v(26);
	for(int i=0;i<c;i++){
		string tmp;
		cin>>tmp;
		v[tmp[0]-'a'].push_back(tmp);	
	}
	vector<vector<string>> name(26);
	for(int i=0;i<n;i++){
		string tmp;
		cin>>tmp;
		name[tmp[0]-'a'].push_back(tmp);
	}
	cin>>x;
	bool sw=false;
	for(int i=0;i<x;i++){
		sw=false;
		string s;
		cin>>s;
		for(int j=0;j<v[s[0]-'a'].size();j++){
			int t=s.find(v[s[0]-'a'][j]);
			int len=v[s[0]-'a'][j].length();
			if(t<=2000&&t>=0){
				string str2=s.substr(len);
				for(int k=0;k<name[str2[0]-'a'].size();k++){
					int p=str2.find(name[str2[0]-'a'][k]);
					int leng=name[str2[0]-'a'][k].length();
					if(p<=2000-len&&p>=0){
						string str3=str2.substr(leng);
						if(str3=="") {printf("Yes\n");sw=true;}
					}
				}
			}	
		}
		if(sw==false) printf("No\n");
	}
	return 0;
}


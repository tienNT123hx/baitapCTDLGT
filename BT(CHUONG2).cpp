#include<iostream>
#include<string>
using namespace std;

string* SortColor(string* p, int n){
	
	for(int i=0;i<n-2;i++){
		for(int j=n-1;j>i;j--){
			if(p[j]<p[j-1])
			swap(p[j],p[j-1]);
		}
	}
	return p;
}
int main(){
	int n;
	cin>>n;
	string *p=new string[n];
	for(int i=0;i<n;i++){
	cin>>p[i];
	cin.ignore();
	}
	p=SortColor(p,n);
	for(int j=0;j<n;j++){
	cout<<p[j]<<" ";
	}
	delete [] p;
}

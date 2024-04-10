#include<iostream>
#include<string>
using namespace std;
void Partition(string a[], int t, int p){
	if(t>=p) return ;
	string c=a[t];
	int i=t+1,j=p;
	while(i<=j){
		while(a[i]<=c && i<=j) i++;
		while(a[j]>c && i<=j) j--;
		if(i<j) swap(a[i],a[j]);
	}
	swap(a[t],a[j]);
	Partition(a,t,j-1);
	Partition(a,j+1,p);
}
void QuickSort(string a[],int n){
	Partition(a,0,n-1);
}
void MergeArray(string A[],int n, string B[], int m, string C[]){
	int i=0,j=0,count=0;
while(i<n && j<m){
	if(A[i]<=B[j]){	
	 C[count++]=A[i];
	++i;}
	else {
		C[count++]=B[j]; ++j;
	}
}
while(i<n){ C[count++]=A[i]; ++i;}
while(j<m){ C[count++]=B[i]; ++j; }
 
}
int main(){
	int n;
	cout<<"nhap so phan tu mang a:"<<endl;
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++){
	cin>>a[i];}
	QuickSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		
	}
	
	int m;
	cout<<"nhap so phan tu mang B:"<<endl;
	cin>>m;
	string B[m];
	for(int i=0;i<m;i++) cin>>B[i];
	 string C[n+m];
	MergeArray(a,n,B,m,C);
	cout<<"mang C sau khi tron mang A voi B la:"<<endl; 
	for(int i=0;i<m+n;i++) cout<<C[i]<<" ";
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int PrimeCheck(int n) 

{

int count = 0;

for (int i = 2; i <= n; i++)

if (n % i == 0) count++;

if (count == 1) return 1;

else return 0;

}
int BlumCheck(int n) 

{

int count = 1;

for (int i = 2; i < sqrt(n); i++)

{

if (PrimeCheck(i) && PrimeCheck(n / i) && (i * (n / i) == n))

{

count++;
if(i==sqrt(n)-1) return count;
}

}

if (count == 1) 

return count;

}
int main(){
	int n;cin>>n;

	 int *p=new int[n];
     int *q=new int[n];
      int d=0;
     for(int i=0;i<n;i++){
	  p[i]=i+1;
     	if( BlumCheck(p[i])!=1 ) {
		 q[d]=p[i];	++d;}
     	else continue;
	    if(q[d]>=n) break ;
        }
        
        cout<<"mang so blum la:"<<endl;
        for(int i=0;i<d;i++) cout<<q[i]<<" ";
        cout<<endl;
        
           int *k=new int[n];
           int d1=0;
         for(int i=0;i<d;i++){
         	for(int j=d-1;j>i;j--){
         		if(i==j) continue;
         		if( BlumCheck(q[i]+q[j])!=1 && (q[i]+q[j])<n ){ k[d1]=q[i]+q[j] ;++d1;}
        
			 }
		 } 
		 
		
		 
		 
		  if(d1==0) cout<<"mang blum moi ko co phan tu nao:"<<endl;
		  else {
		  
		 cout<<"mang blum moi la:"<<endl;
		
		 for(int i=0;i<d1;i++) cout<<k[i]<<" ";
             	}
             	cout<<endl;
             	
          int M;int c=0;
		  cout<<"nhap so Blum M:"<<endl; cin>>M;
		  for(int i=0;i<d;i++){
		  	if(M!=q[i]) ++c;
		  	else cout<<"M thuoc mang so blum:"<<endl;
		  }   if(c==d) cout<<"M khong thuoc mang so blum:";	
	
        delete []p;
        delete []q;
	
}

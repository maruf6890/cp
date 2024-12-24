#include <bits/stdc++.h>
using namespace std;
// using sieve
#define  M 10000
vector<int> mpf(M+1,1);



void sieve(){
  mpf[0]=0;
  
  for(int i=2;  i<=M; i++){
      if(mpf[i]==1){
          for(int j=i;  j<=M;  j+=i){
              if(mpf[j]==1) mpf[j]=i;
          }
      }
  }
}

vector<int> fact(int x){
    vector<int> primeFactor;
    while(x!=1){
        primeFactor.push_back(mpf[x]);
        x/=mpf[x];
        
    }
    return primeFactor;
}
int main() {
    sieve();
	 int x;
	 cin>>x;
	 
	 vector<int>primefact =  fact(x);
	 
	 
	 for(int i=0; i<primefact.size();  i++){
	     cout<<primefact[i]<<" ";
	 }
	 cout<<endl;
	 
	    

}

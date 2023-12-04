#include <bits/stdc++.h> 
using namespace std; 
 
int main(){ 
  int t; cin >> t; 
  while(t--){ 
    long long n,k,a,b; cin >> n >> k >> a >> b; 
    long long ra,sa,rb,sb; 
    long long sola = 2e18, solb = 2e18; 
    pair<long long,long long> pairs[n]; 
     
    for(int i=1;i<=n;i++){ 
      long long x,y; cin>>x>>y; 
      pairs[i-1]=make_pair(x,y); 
      if(i==a){ 
        ra=x; 
        sa=y; 
      } 
      if(i==b){ 
        rb=x; 
        sb=y; 
      } 
    } 
     
    for(int i=0;i<k;i++){ 
      sola=min(sola,abs(pairs[i].first-ra)+abs(pairs[i].second-sa)); 
      solb=min(solb,abs(pairs[i].first-rb)+abs(pairs[i].second-sb)); 
    } 
    cout<<min(sola+solb,abs(ra-rb)+abs(sa-sb)); 
    cout<<endl; 
  } 
   
  return 0; 
}
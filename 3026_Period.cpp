#include<bits/stdc++.h>
using namespace std;
 
//KMP::O(|s|)
vector<int> cal_pi(string& s){
  int n = s.size();
  vector<int> pi(n);
  for (int k = 0, i = 1; i < n; ++i){
    if(s[i]==s[k])  pi[i] = ++k;
    else if(k==0) pi[i]=0;
    else  k = pi[k-1], --i;
  }
  return pi;
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int tc = 0;
  while(1){
    int n;  cin >> n;
    if(n==0)  break;
    cout << "Test case #" << ++tc << "\n";
    string s; cin >> s;
    vector<int> pi = cal_pi(s);
    for (int i = 1; i < n; ++i){
      if((i+1)%(i+1-pi[i])==0){
        int k = (i+1)/(i+1-pi[i]);
        if(k>1) cout << i+1 << " " << k << "\n";
      }
    }
    cout << "\n";
  }
  
  return 0;
} 

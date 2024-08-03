// SDE internship question NSUT COLLEGE
// You have given an integer n. you have to convert the binary representation of n top a palindrom
// using below two operations
// 1.increase n by 1
// 2.decrease n by 1
// find the minimum no. of operations to do that?
#include <bits/stdc++.h>
using namespace std;
#define int long long int
int b2d(string binaryString) {
  int decimal = 0;
  int power = 0;

  for (int i = binaryString.length() - 1; i >= 0; i--) {
    int digit = binaryString[i] - '0';
    decimal += digit * pow(2, power);
    power++;
  }
  return decimal;
}
void solve() {
    // Your solution code goes here
    int n;cin>>n;
    if (n == 0){
        cout<<0<<endl;return;
    } 
    string binary = bitset<32>(n).to_string();
     binary = binary.substr(binary.find('1'));
      string reversed = binary;
    reverse(reversed.begin(), reversed.end());
    if (binary == reversed) {
        cout<<0<<endl;return;
    }
    int i=0,j=binary.size()-1;  
    long long cnt=0;
    while(i<j){
        if(binary[i] != binary[j]){
            string a=binary;
            string b=binary;
            
            a[i] = ('1'-a[i]) + '0';

            b[j]=('1' - b[j]) + '0';

            int cnta=abs(b2d(a) - b2d(binary));

            int cntb=abs(b2d(binary) - b2d(b));

            // cout<<binary<<endl;
            // cout<<cnta<<" "<<cntb<<endl;
            // cout<<a<<" "<<b<<endl;
          
            if(cnta < cntb){
                binary=a;
                cnt+=(cnta);
            }else{
                binary=b;
                cnt+=(cntb);
            }
        }
        i++,j--;
        
    }
    cout<<binary<<endl;
    cout<<cnt<<endl;
}
   int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int t ;cin >> t;while(t--){solve();}
//   solve();
    return 0;
}
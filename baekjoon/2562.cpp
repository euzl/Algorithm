// 2562::최대값
#include <iostream>
using namespace std;

int main(){
  int a[9];
  int max = -1;
  int idx = -1;
  for(int i=0; i<9;i++){
    cin>>a[i];
    if(a[i]>=max){
      max = a[i];
      idx = i+1;
    }
  }

  cout<<max<<'\n'<<idx;

  return 0;
}

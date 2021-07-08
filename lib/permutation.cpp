#include<iostream>
#include<algorithm>//next_permutation
using namespace std;

int main(){
  int array[]={1,2,3,4};
  do{
    for(int i=0; i<4; i++){
      cout<<array[i];
      if(i!=3)cout<<" ";
    }
    cout<<endl;
  }while(next_permutation(array,array+4));
  return 0;
}
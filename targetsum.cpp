#include<iostream>
using namespace std;



int sumways(int *arr,int n,int i,int target,int currentsum)
{
  if(currentsum==target)
  {
    return 1;
  }

  if (i == n || currentsum > target) {
        return 0;
    }

    int include=sumways(arr,n,i+1,target,currentsum+arr[i]);

    int exclude=sumways(arr,n,i+1,target,currentsum);

    return include+exclude;

}
int main()
{
  int *arr=new int[5];

int initialarray[5]={0,6,4,0,0};
for(int i=0;i<5;i++)
{
  arr[i]=initialarray[i];
}
int c=sumways(arr,5,0,10,0);
cout<<"Number of ways target can be formed:"<<c<<endl;
return 0;
}

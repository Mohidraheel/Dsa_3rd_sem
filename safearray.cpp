// #include<iostream>
// using namespace std;

// class safearray
// {
//   int* ptr;
//   int size;
//   public:
//   safearray(int s)
//   {
//     size=s;
//     ptr=new int[size];
//     for(int i=0;i<size;i++)
//     {
//       ptr[i]=0;
//     }
//   }

//   void print()
//   {
//     for(int i=0;i<size;i++)
//     {
//       cout<<ptr[i]<<" ";
//     }
//     cout<<endl;
//   }

//   void input()
//   {
//     cout<<"Enter elements: ";
//     for(int i=0;i<size;i++)
//     {
//       cin>>ptr[i];
//     }
//   }

//   void resize(int s)
//   {
//     if(this->size==s)
//     {
//       cout<<"Size is already "<<size<<endl;
      
//     }
//     else
//     {
//       if(this->size>s)
//       {
//         int *temp=new int[s];
//         for(int i=0;i<s;i++)
//         {
//           temp[i]=ptr[i];
//         }
//         delete[] ptr;
//         ptr=temp;
//         size=s;

//       }
//       else
//       {
//         int *temp=new int[s];
//         for(int i=0;i<size;i++)
//         {
//           temp[i]=ptr[i];
//         }
//          cout<<"Enter "<<endl;
//         for(int i=size;i<s;i++)
//         {
         
//           cin >> temp[i];
//         }
//         delete[] ptr;
//         ptr=temp;
//         size=s;

//       }
//     }
//   }

// };
// int main()
// {
//   safearray sa(5);
//   sa.input();
//   sa.print();
//   sa.resize(10);
//   sa.print();
//   sa.resize(5);
//   sa.print();

// return 0;
// }

#include<iostream>
using namespace std;

class safearray
{
  int arr[100];
  int size;
  public:
  safearray()
  {
    size=0;

  }
  int & access(int index)
  {
    if(index<0 || index>=100)
    {
      cout<< "Index out of bounds";
      exit(1);
    }
    return arr[index];
  }
};
int main()
{
  safearray sa;
  for(int i=0;i<20;i++)
  {
    sa.access(i)=i*3;
  }

  for(int i=0;i<20;i++)
  {
    int temp;
    temp=sa.access(i);
    cout<<"element"<<" "<<i<<" "<<temp<<endl;


  }
return 0;
}

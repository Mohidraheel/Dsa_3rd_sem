#include <iostream>
#include <vector>
using namespace std;
//using arrays
// void bubblesort(int arr[],int n)
// {
//     bool swapped;
//     for(int i=0;i<n;i++)
//     {
//         swapped=false;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i] > arr[j])
//             {
//                 swap(arr[i],arr[j]);
//                 swapped=true;
//             }
//         }
//         if (swapped == false)
//         {
//             break;
//         }

//     }
    

// }

// void print(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int n;
//     cout << "Enter the number of elements: ";
//     cin >> n;
//     int *arr=new int[n];
//     cout << "Enter the elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     bubblesort(arr, n);
//     cout << "Sorted array: ";
//     print(arr, n);
//     delete[] arr;


//     return 0;
// }


//using vectors

// void bubblesort(vector<int>&arr,int n)
// {
//     bool swapped;
//     for(int i = 0; i < n; i++)
//     {
//         swapped=false;
//         for(int j = i+1; j < n; j++)
//         {
//             if(arr[i] > arr[j])
//             {
//                 swap(arr[i],arr[j]);
//                 swapped=true;
//             }
//         }
//         if (swapped == false)
//         {
//             break;
//         }

//     }
// }

// void print(vector<int>&arr)
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int n;
//     cout << "Enter the number of elements: ";
//     cin >> n;
//     vector<int>arr(n);
//     cout << "Enter the elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     bubblesort(arr, n);
//     cout << "Sorted array: ";
//     print(arr);


//     return 0;
// }

//using recursion

// #include<iostream>
// using namespace std;

// int bubblesort(int *arr,int n)
// {
//     if(n==1)
//     {
//         return 0;
//     }

//     for(int i = 0; i < n-1; i++)
//     {
//     if(arr[i]>arr[i+1])
//     {
//         swap(arr[i],arr[i+1]);
       
//     }
//     }
//     bubblesort(arr, n-1);
// }
// int main()
// {
//     int arr[5]={1,6,3,2,5};
//     int n=5;
//     bubblesort(arr,n);
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }


//optimized code

// #include<iostream>
// using namespace std;
//  class node
//  {
//      int data;
//      node *previous;
//      node *next;
//      public:
//      node()
//      {
//          data=0;
//          previous=NULL;
//          next=NULL;
//      }
//      node(int data)
//      {
//          this->data=data;
//          previous=NULL;
//          next=NULL;
//      }
//      friend class doublelinkedlist;

//  };

//  class doublelinkedlist
//  {
//     node *head;
//     public:
//     doublelinkedlist()
//     {
//         head=NULL;
//     }
//     void insertathead(int data)
//     {
//         node *n=new node(data);
//         n->next=head;
//         if(head!=NULL)
//         {
//           head->previous=n;
//         }
       
//         n->previous=NULL;
//         head=n;

        
//     }
//     void insertatend(int data)
//     {
//       if(head==NULL)
//       {
//         insertathead(data);
//         return;
//       }
//       node *n=new node(data);
//       node *temp=head;
//       while(temp->next!=NULL)
//       {
//         temp=temp->next;
//       }
//       temp->next=n;
//       n->previous=temp;
//       n->next=NULL;
//     }
//     void insertbeforekey(int data,int key)
//     {
//       node *prev=NULL;
//       node *current=head;
//       int found=0;
//       while(current!=NULL)
//       {
//         if(current->data==key)
//         {
//           found=1;
//           break;
//         }
//         prev=current;
//         current=current->next;
//       }
//       if(found==1)
//       {
//         node *n=new node(data);
//         if(current->previous==NULL)
//         {
//           insertathead(data);
//           return;
//         }
//         n->next=current;
//         current->previous=n;
//         prev->next=n;
//         n->previous=prev;
        
//       }
//       else
//       {
//         cout<<"No Such Value"<<endl;
//       }

//     }

//     void insertafterkey(int data,int key)
//     {
//       node *temp=head;
//       node *nextptr;
//       int found=0;
//       while(temp!=NULL)
//       {
//         nextptr=temp->next;
//         if(temp->data==key)
//         {
//           found=1;
//           break;
//         }
//         temp=temp->next;

//       }

//       if(found==1)
//       {
//         node *n=new node(data);
//         if(temp->next==NULL)
//         {
//           insertatend(data);
//           return;
//         }

//         temp->next=n;
//         n->previous=temp;
//         n->next=nextptr; 
//         nextptr->previous=n;
        

//       }
//     }

//     void deletehead()
//     {
//       if(head==NULL)
//       {
//         cout<<"List is already empty"<<endl;
//         return;
//       }

//       node *todelete=head;
//       head=head->next;
//       delete todelete;
//     }
    
//     void deletefromend()
//     {
//       if(head==NULL)
//       {
//         return;
//       }
//       if(head->next==NULL)
//       {
//         deletehead();
//         return;
//       }
//       node *temp=head;

//       while(temp->next->next!=NULL)
//       {
//         temp=temp->next;
//       }
//       node *todelete=temp->next;
//       temp->next=NULL;
//       delete todelete;
//     }

//     void deleteatsomepoint(int key)
//     {
//       node *temp=head;
//       node *prev=NULL;
//       if(head==NULL)
//       {
//         return;
//       }
//       int found=0;

//       while(temp!=NULL)
//       {
//         if(temp->data==key)
//         {
//           found=1;
//           break;
//         }
//         prev=temp;
//         temp=temp->next;
//       }
//         // cout<<temp->data;
//         // cout<<prev->data;
//         // cout<<temp->next->data;
//       node *todelete=temp;
//       prev->next=temp->next;
//       temp->next->previous=prev;
//       delete todelete;

//     }
//     void sort()
//     {
//        node *temp;
//        node *temp1;
//        int temporary;
//        for(temp=head;temp!=NULL;temp=temp->next)
//        {
//         for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
//         {
//           if(temp->data>temp1->data)
//           {
//             // swap(temp->data,temp1->data);
//             temporary=temp->data;
//             temp->data=temp1->data;
//             temp1->data=temporary;
//           }
//         }

//        }
   
//     }

//     void optimizedbubblesort()
//     {
//         bool swapped=false;
//         node *temp=head;
//         node *temp1;
//         for(;temp!=NULL;temp=temp->next)
//         {
//             swapped=false;
//             for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
//             {
//                 if(temp->data > temp1->data)
//                 {
//                     swap(temp->data,temp1->data);
//                     swapped=true;
//                 }
//             }
//              if(!swapped)
//              {
//                break;
//              }
//         }
       
//     }

//     void removeduplicates()
//     {
//       optimizedbubblesort();
//       node *temp=head;
//       while(temp->next!=NULL)
//       {
//         if(temp->data==temp->next->data)
//         {
//           node *todelete=temp->next;
//           if(todelete->next!=NULL)
//           {
//               temp->next=todelete->next;
//               todelete->next->previous=temp;

//           }
//           else
//           {
//             temp->next=NULL;
//           }
        
//           delete todelete;

//         }
//         else
//         {
//            temp=temp->next;

//         }
       

//       }
      

//     }
   
//     void print()
//     {
//         node *temp=head;
//         cout<<"NULL";
//         while(temp!=NULL)
//         {
//             cout<<" <- "<<temp->data<<" -> ";
//             temp=temp->next;
//         }
//         cout<<"NULL";
//         cout<<endl;
//     }

//  };
//  int main()
//  {
//   doublelinkedlist ll;
//   ll.insertathead(2);
//   ll.insertatend(1);
//   ll.insertatend(4);
//   ll.insertatend(3);
//   ll.insertatend(8);
//   ll.insertathead(8);
//   ll.insertatend(4);
//   ll.insertatend(4);
//   ll.insertatend(9);
//   ll.insertatend(6);
//   ll.insertathead(9);
//   ll.print();
//   cout<<"After sorting:"<<endl;
//   ll.optimizedbubblesort();
//   ll.print();
//   cout<<"After removing Duplicates"<<endl;
//   ll.removeduplicates();
//   ll.print();
//  }






#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root; // Initialize largest as root (i)
   int r = 2 * root + 2; // right node is at (2*i +2).
   int l = 2 * root + 1; // left node is at (2*i + 1)
   
 
   //Left child is larger than the root
   if (l < n && (arr[l] > arr[largest]))
   {
      largest = l;
   }
 
   //Right child is larger than the current largest
   if (r < n && (arr[r] > arr[largest]))
   {
      largest = r;
   }
 
   //If largest is not root, swap
   if (largest != root) 
   {   
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;
 
      //Recursively heapifing the rest
      heapify(arr, n, largest);
   }   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = (n / 2) - 1; i >= 0; i--) 
   {
       heapify(arr, n, i);
   }
   
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--)
   {
      //swapping root and end
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      
      //heapify the rest
      heapify(arr, i, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int root=0; root<n; ++root)
   cout << arr[root] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int sz = 10;

   int heap_arr[sz];
   srand(time(NULL));
   for(int i=0;i<sz;i++)
      heap_arr[i]=rand()%100;  //Generate number between 0 to 99
  
   //int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

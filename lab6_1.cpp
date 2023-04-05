#include <iostream>
using namespace std;
#include <vector>
#include <chrono>
using namespace std::chrono;




vector<int> Push(vector<int> arr, int num, int capcity)
{
    if ((capcity - 1) > size(arr))
    {
        arr.push_back(num);
    }
    else
    {
        cout<<"Stack overflow"<< endl;
    } 
    return arr; 
}

vector<int> Pop(vector<int> arr)
{
    if (size(arr) < 0)
    {
        cout<<"Stack Underflow" << endl;
    }
    else
    {
        arr.pop_back();
    }
    return arr; 
}

void Display(vector<int> arr)
{   
    cout<<"Stack : ";
    
    for (int i = 0; i < size(arr); i++)
    {
        cout<<arr[i] << " ";
    }
    
    cout<<endl;
}


int main()
{
    int size;
    cout<<"Enter the stack size :";
    cin>>size;
    cout<< endl;
    vector <int> stack;

    auto start = chrono::high_resolution_clock::now();

    stack = Push(stack,8,size);
    stack = Push(stack,10,size);
    stack = Push(stack,5,size);
    stack = Push(stack,11,size);
    stack = Push(stack,15,size);
    stack = Push(stack,23,size);
    stack = Push(stack,6,size);
    stack = Push(stack,18,size);
    stack = Push(stack,20,size);
    stack = Push(stack,17,size);
    Display(stack);
    stack = Pop(stack);
    stack = Pop(stack);
    stack = Pop(stack);
    stack = Pop(stack);
    stack = Pop(stack);
    Display(stack);
    stack = Push(stack,4,size);
    stack = Push(stack,30,size);
    stack = Push(stack,3,size);
    stack = Push(stack,1,size);
    Display(stack);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function : "<< duration.count() << " microseconds\n";

    return 0;
    
}

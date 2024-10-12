#include <bits/stdc++.h>
#include<algorithm> //* sort()
using namespace std;


static bool comp(int &a, int &b){
    return a > b;
}

struct Point{
    int x,y;
};

 bool mycomp(Point p1, Point p2){
    return p1.x < p2.x;
}


void print(vector<int>&v){
    for(auto val:v){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){


//! sort() -> for sorting the container that allow random access
//* vector,list,deque

int arr[] = {10,20,5,7};
sort(arr,arr+4); //* by default, sorts in the ascending order
for(auto &val : arr){
    cout<<val<<" ";
}
cout<<endl;

//? sort(arr,arr+4,greater<int>)
sort(arr,arr+4,comp); // to sort in deceding order
for(auto &val : arr){
    cout<<val<<" ";
}
cout<<endl;


vector<int>v = {45,3,89,32,13};
sort(v.begin(),v.end());
print(v);


//?sort(v.begin(),v.end(),greater<int>);
sort(v.begin(),v.end(),comp);
print(v);


//* comparator
Point arr1[] = {{3,10},{6,3},{0,2}};
sort(arr1,arr1+3,mycomp);
for(auto i : arr1){
    cout<<i.x<<" "<<i.y<<endl;
}

/*
    Worst case and Average case-> O(n log(n))
    uses QuickSort or IntroSort(hybrid of QuickSort,HeapSort and Insertion Sort)
 */


//! merge() -> sorted contiainers
vector<int>arr2 = {10,20,40};
vector<int>arr3 = {40,50,60};
vector<int>arr4(6);//* need to give the size
merge(arr2.begin(),arr2.end(),arr3.begin(),arr3.end(),arr4.begin());
print(arr4);
/* SAME FOR THE ARRAY -> O(m+n)
 */



//! reverse() -> to reverse the element of the container
//* same for the array,string,list,deque -> O(n)
reverse(arr4.begin(),arr4.end()-1);
print(arr4);


//! next_permutation() -> to print the next lexicographical permutation
//* if the next permuatation is possible -> give the next permutation 
//* if the next permutation is not possible -> if it is last permuation -> return false
//* n! permutation possible
//* same of array,list,deque
/*
        1 2 3 4 5
        1 2 3 5 4
        1 2 4 3 5
        1 2 4 5 3
        1 2 5 3 4
        1 2 5 4 3


         1 2 5 4 3
         x = 2 , y = 3
         after swap : 1 3 5 4 2
         after reverse : 1 3 2 4 5

         O(n)
 */
vector<int>arr5 = {1,2,3,4,5};
next_permutation(arr5.begin(),arr5.end());
print(arr5);


//! prev_permutation()
//* same as above
//* it return boolean value to show -> prev_permuation is possible or not

/*
    5 4 1 2 3
    x = 4, y=3
    swap: 5 3 1 2 4
    reverse: 5 3 4 2 1    
    O(n)
 */
prev_permutation(arr5.begin(),arr5.end());
print(arr5);

    return 0;
}



//! make_heap() -> to convert a given range of elements in the max heap
/*
make_heap(first, last): Converts the range into a heap. 

v.push_back(val); then,
push_heap(first, last): Adds a new element to the heap.

pop_heap(first, last): Removes the top element of the heap.
pop_back();


sort_heap(first, last): Sorts the heap in ascending order.

std::make_heap(v.begin(), v.end(), std::greater<>());

v.front().



1. root value -> max
2. left(i) -> 2i + 1
3. right(i) -> 2i + 2
4. parent(i) -> (i-1)/2
 */
vector<int>arr6 = {15,6,7,12,30};

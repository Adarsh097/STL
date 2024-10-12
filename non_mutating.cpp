#include <bits/stdc++.h>
#include<algorithm>
#include<numeric> //-> accumulate
#include<cstdlib> //-> rand()
using namespace std;

int myfunc(int x,int y){
    return x*y;
}

int main(){
    //! find() -> O(n) 
    //* for list,vector,set,map...
    //? but for set,map we have container specific find() -> with less time complexity
    cout<<"find() -> \n";
   vector<int>v = {5,10,7,10,20,35};
   vector<int>:: iterator it = find(v.begin(),v.end(),35);
   if(it != v.end()){
    cout<<"10 is present at index: "<<(it - v.begin())<<endl;
   }

   int arr[] = {1,2,3,4,5,6};
   int *ptr = find(arr,arr+6,5);
   if(ptr == (arr + 6)){
    cout<<"Not found"<<endl;
   }else{
    cout<<"found at index: "<<(ptr - arr)<<endl;
   }


   //! lower_bound()  -> returns iterator to the element that is just greater than or equal to the given element
    //* if the element is not present -> return v.end();
    //? for array -> same as above
    //* does (binary search) in the sorted array
    cout<<"\nlower_bound()\n";
    vector<int>:: iterator it1 = lower_bound(v.begin(),v.end(),10);
    cout<<"at: "<<it1-v.begin()<<"   "<<(*it1)<<endl;

    /*
        1. TC-> O(log(n)) for Random Access Containers where n is number of elements in the container like
        2. vector,array // preferable
     */




    //! upper_bound() -> returns iterator to the first greater element in a sorted array
    auto it2 = upper_bound(v.begin(),v.end(),8);
    cout<<"\nupper_bound()\n";
    cout<<(*it2);
    //* upper_bound() - lower_bound(): gives the occurences of the element in the sorted array in O(log(n));
    
    /*
        same as lower_bound();
        it = advance(it,i); -> O(1) for the reandom access container / -> O(n) for the non-random access container 
     */



    //! binary_search() => to find the element in sorted array
    vector<int>a = {10,20,30,30,40,50,60};
    cout<<"\n\nbinary search\n";
    int x = 50;
    if(binary_search(a.begin(),a.end(),x)==true){
        cout<<"found"<<endl;
    }else{
        cout<<"not found\n";
    }
    //* same iteration as above for the array
    /* 
        same as the lower_bound()
     */


    //! max_element()  and  min_element() -> O(n)
    auto maxi = max_element(a.begin(),a.end());
    auto mini = min_element(a.begin(),a.end());
    cout<<"\nmax element: "<<(*maxi)<<endl;
    cout<<"min element: "<<(*mini)<<endl;
    cout<<"max element in the arr: "<<*(max_element(arr,arr+6))<<endl;
    cout<<"min element in the arr: "<<(*min_element(arr,arr+6))<<endl;


    //! count() -> to count the occurences of the element ->O(n)
    cout<<endl<<count(a.begin(),a.end(),30)<<endl;
    


    //! is_permutation() -> to check whether two given container are permuation of each other or not
    //* O(n^2)
    //* good for the multiple occurence case also
    vector<int>arr1 = {10,20,30,30,40};
    vector<int>arr2 = {40,30,20,10,30};

    if(is_permutation(arr1.begin(),arr1.end(),arr2.begin())){
        cout<<"\n\nyes, it is!"<<endl;
    }else{
        cout<<"\n\n not \n";
    }



    //! fill() -> to fill the container with a specific value in a given range
    cout<<"\n\nfill()"<<endl;
    fill(arr1.begin(),arr1.begin()+2,100);
    for(auto &val : arr1){
        cout<<val<<" ";
    }
    /* for array: same as above -> O(n)
     */


    //! rotate() -> to rotate the container about a given element <-- to left rotate 
    rotate(arr1.begin(),arr1.begin()+2,arr1.end());
    cout<<"\n\nfill()"<<endl;
    for(auto &val : arr1){
        cout<<val<<" ";
    }
    /* 
        1. same for the array
        2. O(n)
     */



    //! accumulate() -> to find the sum of the element in the given container
    //* O(n)
    int sum = accumulate(arr1.begin(),arr1.end(),0);
    cout<<"\n\nsum-> "<<sum<<endl;
    int init_res = 1;
    int ans = accumulate(arr1.begin(),arr1.end(),1,myfunc);
    cout<<"product of the array: "<<ans<<endl;



    //! rand() -> to generate the number
    //* 0 to RAND_MAX -> 0 TO 32767
    cout<<"\n\nrandom number: "<<rand()<<endl;
    
    return 0;
}
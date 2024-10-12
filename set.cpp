#include <iostream>
#include <set>
using namespace std;

//! user-defined set
struct Test{
    int x;
    bool operator<(const Test&t) const{
        return (this->x < t.x);
    }
};

void print(set<int,greater<int>>s1){
     for(auto it=s1.begin(); it!=s1.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    return;
}
void printSet(set<int>s1){
     for(auto it=s1.begin(); it!=s1.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    return;
}

int main(){
   //! set store the data in sorted order uniquely -> one element will be present for one time in the set
   //? Set can be used to remove the duplicate element in array
   //? By default, it is ascending order.
   set<int>s;
   s.insert(100);
   s.insert(34);
   s.insert(10);
   s.insert(10);

   //* prints the element in sorted order
//    for(const int &val : s){
//     cout<<val<<" ";
//    }
//    cout<<endl;

//! to store the element in descending order uniquely
    set<int,greater<int>>s1;
    s1.insert(23);
    s1.insert(4);
    s1.insert(70);
    s1.insert(70);
    s1.insert(89);
    //* set<int>:: iterator -> auto
    //* s.begin()-> points to the first value of the set -> storing the addresses
    //* s.end()-> points to the end  of the set -> ''  ''  ''
    for(set<int>:: iterator it=s1.begin(); it != s1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    //? to traverse the element in reverse order
    for(auto it=s1.rbegin(); it!=s1.rend(); it++){
        cout<<(*it)<<" ";// pring the set in ascending order -> coz traversing backside
    }
    cout<<endl;

//! s.find(val) -> to find the value in the set if present -> it returns the iterator to the value if present -> otherwise points to the end of the set
auto it = s1.find(89);
if(it == s1.end()){
    cout<<"value is not present\n";
}else{
    cout<<(*it)<<" is present in the set\n";
}

//! s.clear()  and  s.size();
// s1.clear();
cout<<"size of the set s1: "<<s1.size()<<endl;


//! s.count() -> usually counts the occurences of the elements -> but set contains unique element -> it return 1 if the element is present and 0 if the element is not present in the set
//? it return only (1 or 0)
if(s.count(100)){
    cout<<"100 is present in the set"<<endl;
}else{
    cout<<"100 is not present in the set"<<endl;
}

//! s.erase() -> to erase the paritcular element in the set
s1.erase(70);
cout<<s1.size()<<endl;

print(s1);
//? can also erase using the iterator`
set<int>:: iterator it1 = s1.find(23);
// s1.erase(it1);
print(s1);

//? removing a range of element
s1.erase(it1,s1.end());
print(s1);



//! s.lower_bound(val)-> returns iterator to the element that is just greater or equal to the element
//* if the element is not present -> return s.end()
s.insert(12);
s.insert(16);
s.insert(52);
printSet(s);
auto it2  = s.lower_bound(16);
cout<<"lower bound of 16: "<<(*it2)<<endl;
auto it3  = s.lower_bound(163);
(it3==s.end())?cout<<"yes":cout<<"no"; // point the end of the set
cout<<endl;


//! s.upper_bound(val)-> returns iterator to the element that is greater than the element
//* if the element is not present -> return s.end()
if(s.upper_bound(52) != s.end()){
    cout<<"upper bound: "<<(*s.upper_bound(52))<<endl;
}else{
    cout<<"upper bound is not present\n";
}



/* 
    1. set is built on self-balancing binary tree/Red-Black tree (heigh-> logn)
    2. begin(), end(), rbegin(), rend(), cbegin(), cend(), crbegin(), crend(), size(), empty()-> O(1).
    3. insert(), find(), count(), lower_bound(), upper_bound(), erase(val) -> O(log(n)). //!Red-Black tree
    4. erase(it) -> Amortized -> O(1) //! using the address to delete the element
 */


//! user defined set
set<Test>st;
st.insert({23});
st.insert({23});
st.insert({23});
st.insert({453});
for(Test t : st){
    cout<<t.x<<" ";
}

//! application
/* 
    1. to maintain the sorted order of data
    2. doubly ended priority queue -> s.begin()/s.end()-1
 */
    return 0;
}
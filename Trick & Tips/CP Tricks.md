## C++ Tricks

- Use the most efficient compiler

  ![compiler](C:\Users\princebilly\Desktop\My-Programing-Problem-Solves\_data\compiler comparison)

- Use `#include <bits/stdc++.h>`header file

- PI values

  ```c++
  const double pi=acos(-1.0);
  ```


### Global vs local variable: 

**global variables (outside any function) are automatically initialized to zero** where as local variables contains garbage values

```c++
//Experiments on Non-type templete
#include <iostream>
#include <vector>
using namespace std;

bool global_bool;
double global_float;
char global_char;
int global_int, global_int_array[20];
char global_char_string[10];
string global_string;
int main() {
    freopen("output.txt", "w", stdout);
    //global bool
    cout<<"global bool = "<<global_bool<<endl;
    //global float
    printf("global float = %lf\n", global_float);
    //global_char
    printf("global_char = %c\n", global_char);
    //globlal int
    printf("global_int = %d\n", global_int);
    //global array
    printf("global_int_array = ");
    for (int i : global_int_array) {
        printf("%d ", i);
    }
    //globar char string
    printf("\n");
    printf("global_char_string = %s\n", global_char_string);
    //global string
    cout<<"global_string = "<<global_string<<endl;

    return 0;
}
```

Output:

```
global bool = 0
global float = 0.000000
global_char = �
global_int = 0
global_int_array = 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
global_char_string = 
global_string = 
```



### Array Variable Initialization (both local and global variable):

When we initialize a array with less item with {} the leftover elements are automatically initialized to 0. 

**n.b> array can be assigned  with {} only at initialization time. (not even for char sequence can be intialized using "")**

```c++
//Experiment with array
#include <bits/stdc++.h>

using namespace std;

int main() {
    //when we don't init an array
    int a[20];
    for ( auto i : a) {
        printf("%d " , i);
    }
    printf("\n");
    int b[20] = {2, 4};
    //when we init an array
    for ( auto i : b) {
        printf("%d " , i);
    }
    printf("\n");
    return 0;
}
```

Output

```
-891803168 32549 -895498712 32549 -894826016 32549 -899353463 32549 -2130972336
 32764 1 0 -2130972336 32764 310410616 21890 1 0 308312580 21890 
2 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
```



### Comma techniques: 

- use comma to add multiple statement in same line.

  ```c++
  printf("Hello World\n"), printf("Hello Babes\n");
  ```

- multiple **expressions (not statement)** using comma in for loop

  ```c++
  for (int i = 0, j = 0, k = 3; i < n; i++, j+=2, k+=3) {
  	printf("%d %d %d\n",i ,j, k)
  }
  ```

### For loop range:

```c++
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
string name = "princebilly";
char b[] = "dhaka city college";
vector<int> c = {10, 20, 30, 40};
for (auto i : a ) { //int i
printf("%d ", i);
}
printf("\n");

for (auto i : name ) { //int i
printf("%c", i);
}
printf("\n");

for (auto i : b) { //char i
    printf("%c", i);
}
printf("\n");

for (auto i: c) { //int i
    printf("%d ", i);
}
printf("\n");

```

***I use auto to avoid the complexities in variable declaration in competitive programing.***

## Builting Function

- `__gcd(int,int)` returns the G.C.D. of two integers passed as parameters. 

## STL code writing
- Using **auto** with STL containers iterators.This will work for any type of STL containers.

    ```c++
    //version 1
    for(auto it =v.begin();it!=v.end();it++){....}

    //version 2 easiser
    vector<int> v;
    v = {1, 2, 5, 2};
    for (auto i: v)
        cout << i << ' ';
    cout << '\n';
    // prints "1 2 5 2"
    ```

- Use {} to take values in stl container

  ```c++
  //******************pair***************//
  pair<int, int> p;
  // ...
  p = {3, 4};
  //even a more complex pair
  pair<int, pair<char, long long> > p;
  // ...
  p = {3, {'a', 8ll}};
  
  //******************vector***************//
  vector<int> v;
  v = {1, 2, 5, 2};
  for (auto i: v)
      cout << i << ' ';
  cout << '\n';
  // prints "1 2 5 2"
  
  //.....This works with any kinds of container.....
  ```
  

- Use this uncommon builtin functions

  ```c++
  int x=*min_element(a,a+n);
  //Finds minimum in array a of size n
   
  int c=count(v.begin(),v.end(),3);
  //Counts number of 3 in vector v
   
  int g=__gcd(a,b);
  //Calculates gcd of two numbers a,b
   
  int c=__builtin_popcount(x);
  //Calculates number of one's in binary representation of x
  //Note - use __builtin_popcountll when x is long long
  ```


## Templates supports default  value for non-type arguments:

```c++
template<typename T, int  x = 20>
T func(T var) {
    return var+x;
}

int main() {
    //normal calls
    cout<<func<int, 2>(3)<<endl;
    cout<<func<double, 3>(4.34)<<endl;
    //call with out passing value
    cout<<func<int>(12)<<endl;
    cout<<func<double>(3.35)<<endl;
    return 0;
}
```

Output:

```
5
7.34
32
23.35
```

**N>B> templates cannot be overloaded. and non-type template parameters can not be string or float**



## Function pointer and function as argument

C++ support function to be used as function argument and pointer to hold function address. when we call a function we have to preceded it by * and enclosed it with first bracket

**declaration syntax:**

return_type (*pointer_name)(argument1_type,  argument2_type,...);

**Initialization: **

return_type (*pointer_name)(argument1_type,  argument2_type,...) = function_name;

**Call: **

(*pointer_name)(argument1, argument2,...);



```c++
struct user {
    string first_name;
    string last_name;
};

string  full_gen_name(const string &f_name, const string &l_name) {
    return f_name+" "+l_name;
}

void show_msg(user a, string (*name_gen)(const string&, const string&)) {
    cout<<"Welcome "<<(*name_gen)(a.first_name, a.last_name)<<endl;
}

int main() {
    user a;
    cout<<"Enter first name: "<<endl;
    getline(cin, a.first_name);
    cout<<"Enter last name:"<<endl;
    getline(cin, a.last_name);
    show_msg(a, full_gen_name);
    return 0;
}
```

output:

```
Enter first name: 
Prince Billy Graham
Enter last name:
Karmoker
Welcome Prince Billy Graham Karmoker
```

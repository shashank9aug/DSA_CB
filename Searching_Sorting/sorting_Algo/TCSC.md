## Merge Sort : 
```
    Space and Time Analysis : 

    Time : K = finding mid point 
        2T(n/2) = for sorting each parts about mid point
        kn = Merging the array 

        T(n)  = k + 2T(n/2) + kn

        T(n) = k'n + 2T(n/2)

        2T(n/2) = 2k'(n/2) + 4T(n/4);
        4T(n/4) = 4K'(n/4) + 4*2T(n/8);
        ......
        nT(1) = nk' + 0;
     ---------------------------------------------   
        T(n) = sum(k'n)i=0 to i=logn  = k'nlogn

        T(n) = n(logn) 

    Space  : 
    merge function : to store sorted elemets in temprorary array. = n space     

    merge sort uses recurssion : it will use call stack 
    N->N/2+N/2 -> N/4+N/4+N/4+N/4 -> ....
    so, LogN space 

    total space : O(logn + n) = O(n)  extra space.
```  

## Quick Sort : 

```
Time : 
    T(k) -> finding pivot element.
    T(kn) -> placing pivot element at its position
    T(p-1) -> placing right half to it's correct position.
    T(n-p) -> for rest of the element positioning  

    T(N) = k + kn + (p-1) + (n-p)
    ...
    ...
    T(n) = O(nlogn) => Average case.

    worst case : 
    array is already sorted 
```

## Bubble Sort : 
```
O(N^2) 
```



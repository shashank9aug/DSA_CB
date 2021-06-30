// return middle element between 3 numbers using using minimum comparison;

#include<iostream>
#include<cmath>
using namespace std;



int middle(int A, int B, int C)
{
    int X = A - B;
    int Y = B - C;
    int Z = C - A;

    if (X * Y > 0)
    {
        return B;
    }
    else if (X * Z > 0)
    {
        return A;
    }
    else
    {
        return C;
    }
}


int middle_m2(int A,int B,int C){
   if(A>B) swap(A,B);
   if(B>C) swap(B,C);
   if(A>B) swap(A,B);

   return B; 
}

int main(){
    int A,B,C;
    cin>>A>>B>>C;

    // int ans=middle(A,B,C);
    int ans=middle_m2(A,B,C);
    cout<<"Middle number : "<<ans<<endl;

    return 0;
}
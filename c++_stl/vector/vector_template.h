
template<typename T>
class Vector
{
    T *arr;
    int curr_size;
    int max_size;
    //By default everything inside class is private.
  public:  
    Vector()
    {
        curr_size = 0;
        max_size = 1;
        arr = new T[max_size];
    }

    void push_back(T num)
    {
        //vector is full now
        if (curr_size == max_size){
            T *oldarr=arr;
            arr=new T[2*max_size];
            max_size=2*max_size;
            for(int i=0;i<max_size;i++){
                arr[i]=oldarr[i];
            }
            //free the memory of old array
            delete []oldarr;
        }
        arr[curr_size]=num;
        curr_size++;
    }

    void pop_back(){
        curr_size--;
    }

    T font(){
        return arr[0];
    }

    T back(){
        return arr[curr_size-1];
    }

    int size(){
        return curr_size;
    }

    int capacity(){
        return max_size;
    }

    //operator overloading 
    T operator[](const int i){
        return arr[i];
    }

};
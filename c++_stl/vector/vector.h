class Vector
{
    int *arr;
    int curr_size;
    int max_size;
    //By default everything inside class is private.
  public:  
    Vector()
    {
        curr_size = 0;
        max_size = 1;
        arr = new int[max_size];
    }

    void push_back(int num)
    {
        //vector is full now
        if (curr_size == max_size){
            int *oldarr=arr;
            arr=new int[2*max_size];
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

    int font(){
        return arr[0];
    }

    int back(){
        return arr[curr_size-1];
    }

    int size(){
        return curr_size;
    }

    int capacity(){
        return max_size;
    }

    //operator overloading 
    int operator[](const int i){
        return arr[i];
    }

};
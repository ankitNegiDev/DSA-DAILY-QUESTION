// Array Data structure. using c++

#include <iostream>
#include <exception>
using namespace std;

// custom exceptions class..
class IndexBoundError :public exception{
    // throw is depricated we now use noexcept.
    public:
        const char *what() const noexcept {
            return "Array index out of bounds or invalid index!";
        }
};

class ArrayFull : public exception{
    public:
        const char *what() const noexcept{
            return "Array is full we can't insert more data!";
        }
};

class ArrayEmpty:public exception{
    public:
        const char *what() const noexcept{
            return "Array is empty we can't get data from array!";
        }
};

class Array{
    private:
        int capacity;
        int lastFilledIndex;
        int *ptr;
    
    public:
        // constructor
        Array();
        // copy constructor.
        Array (Array &obj);
        // copy assignment operator.
        Array& operator=(Array &obj);
        // destructor
        ~Array();
        void createArray(int incomingCapacity);
        void insertData(int data, int index);
        void appendData(int data);
        int getData(int index);
        int countArrayData();
        int getCapacity();
        bool isEmpty();
        bool isFull();
        void deleteData(int index);
        void editData(int newData, int index);
};
Array::Array(){
    ptr=NULL;
}

// copy constructor.. to avoid shallow copy..
Array::Array(Array &obj){
    // either we write this->capacity or (*this).cpacity or capacity both are same sinc this is pointing to caller and we can directly access the caller properites.
    capacity=obj.capacity;
    // lastFilledIndex=obj->lastFilledIndex; // obj is not a pointer we can -> apply arrow with pointer not with reference.
    lastFilledIndex=obj.lastFilledIndex;
    ptr=new int[capacity];
    for(int i=0; i<=lastFilledIndex; i++){
        ptr[i]=obj.ptr[i];
    }
}

// copy assignment operator.
Array& Array::operator=(Array &obj){
    capacity=obj.capacity;
    lastFilledIndex=obj.lastFilledIndex;
    if(ptr!=NULL){
        delete []ptr;
    }
    ptr=new int [capacity];
    for(int i=0; i<=lastFilledIndex; i++){
        ptr[i]=obj.ptr[i];
    }
    return (*this);
}

// destructor..
Array::~Array(){
    delete[]ptr;
}
void Array::createArray(int incomingCapacity){
    // we need to create the array.
    /**
     * but the current problem is if user of this class calls multiple time then we are just leaking the memory.
     */
    // capacity=incomingCapacity
    // ptr=new int [capacity];
    // lastFilledIndex=-1;
    if(ptr!=NULL){
        // if ptr is not null that means it have some valid address..
        // free(ptr); // c style.
        delete [] ptr;
    }
    capacity=incomingCapacity;
    ptr = new int[capacity];
    lastFilledIndex=-1;
}

bool Array::isFull(){
    // when array can't be full
    /**
     ** (1) when lastFilledIndex is not == capacity-1
     */
    // when array will be considred as full.
    /**
     ** (1) when lastFilledIndex==capacity-1
     */
    if(lastFilledIndex==capacity-1){
        return true;
    }else{
        return false;
    }
}
bool Array::isEmpty(){
    // when array can't be empty
    /**
     ** (1) when lastFilledIndex is == capacity-1
     */
    // when array will be considred as empty
    /**
     ** (1) when lastFilledIndex!=capacity-1
     */
    // if empty is considred as absolutely empty then this logic is fine..
    // cout<<"lastfilled indexi ns is empty is : "<<lastFilledIndex<<endl;
    if(lastFilledIndex==-1){
        return true;
    }else{
        // false; //! blunder u are not reutrning any thing...
        return false;
    }
    // But if empty means can we add the data in the array even if it have some data.(hasSpace etc)
    /*
    if(lastFilledIndex!=capacity-1){
        return true;
    }else{
        return false;
    }
    */
}

void Array::insertData(int data,int index){
    // when we can't insert data..
    /**
     ** (1) when index is out of range like index<0 and index>lastFilledIndex+1 because on lastFilledIndex+1 we can insert data..
     *? (2) when array is full. like lastFilledIndex==capacity
     */

    // when we can insert data.
    /**
     ** (1) when array is empty or inserting data on lastFilledIndex+1
     *? (2) when data is already on the given index.
     */
    try{
        if(index<0 || index>lastFilledIndex+1){
            throw IndexBoundError();
        }else if(lastFilledIndex==capacity-1){ // we can directly call isFull() member function.
            // array is full.
            throw ArrayFull();
        }
        // insert data.
        // logic 1
        /*
        if(index<=lastFilledIndex && lastFilledIndex != -1){
            // index is less then lastFilledIndex that means right shifting..
            // [10,20,30,...10(capacity)] -> lfi-2, index=1,
            // [10,20, ,30] -> [10, ,20,30];
            for(int i=lastFilledIndex; i>=index; i--){
                ptr[i+1]=ptr[i];
            }
            ptr[index]=data;
            lastFilledIndex++;
        }else if (lastFilledIndex==-1){ // we can directly call isEmpty() memeber function here
            lastFilledIndex++;
            ptr[lastFilledIndex]=data;
        }else if(index<=capacity-1 && index >lastFilledIndex){
            ptr[index]=data;
            lastFilledIndex++;
        }
        */
        // since we know this code will only runs when there is no error that means we have to do lastFilledIndex ++ so why not to do at first.
        // logic 2
        /*
        lastFilledIndex++;
        if(index<=lastFilledIndex && lastFilledIndex!=-1){
            for(int i=lastFilledIndex; i>index; i--){
                ptr[i]=ptr[i-1];
            }
            // ptr[index]=data;
        }
        ptr[index]=data;
        */
        // logic 3
        if(index<=lastFilledIndex){
            for (int i = lastFilledIndex; i >= index; i--){
                ptr[i + 1] = ptr[i];
            }
        }
        ptr[index]=data;
        lastFilledIndex++;
    }catch(exception &e){
        cout << "Caught in insertData : " << e.what() << endl;
    }
}

void Array::appendData(int data){
    // where we can't append the dataa
    /**
     ** (1) if array is full
     */
    // when we can append the data 
    /**
     ** (1) at that point when array is empty.
     */
    try{
        if(lastFilledIndex==capacity-1){ // we can directly call isFull()
            throw ArrayFull();
        }else{
            cout<<"last fileld ins"<<lastFilledIndex<<endl;
            lastFilledIndex++;
            ptr[lastFilledIndex]=data;
        }
    }catch(exception &error){
        cout<<"Caught in appendData : "<< error.what()<<endl;
    }
}

int Array::getData(int index){
    // when we can't get data.
    /**
     ** (1) when array is empty
     ** (2) when index is out of ranger or bound.
     */
    // when we can get data.
    /**
     ** (1) when array is not empty
     ** (2) when index is n valid range or bound.
     */
    try{
        // cout<<"result of isEmpty is : "<<isEmpty();
        if(isEmpty()){
            throw ArrayEmpty();
        }else if(index<0 || index >lastFilledIndex){
            // under this condition empty condition will come but just to show different error i choose to write them.. becasue if index 0 and lastFilled is -1 so index>lfi..like 
            throw IndexBoundError();
        }
        return ptr[index];
    }catch(exception &error){
        cout<<"Caught in getData : "<<error.what()<<endl;
        return -1;
    }
}

int Array::countArrayData(){
    // we need to return the length..
    return lastFilledIndex+1; 
}

int Array::getCapacity(){
    return capacity;
}

void Array::deleteData(int index){
    // when we can't do delete..
    /**
     ** (1) when array is empty.
     ** (2) when index is out of range..
     */

    // when we can do delte
    /**
     ** (1) when array is not empty have some value
     ** (2) when index is in valid range.
        * when we have to deelte at lastFilled index.. its easy no need of shifting
        * when we have to delete < lastFilled index we need to do left shifting.
     */
    try{
        if(isEmpty()){
            throw ArrayEmpty();
        }
        if(index<0 || index>lastFilledIndex){
            throw IndexBoundError();
        }
        if(index<lastFilledIndex){
            for(int i=index; i<lastFilledIndex; i++){
                ptr[i]=ptr[i+1];
            }
        }
        lastFilledIndex--;
    }catch(exception &error){
        cout<<"Caught in deleteData : "<<error.what()<<endl;
    }
}

void Array::editData(int newData, int index){
    // when we can't do edit..
    /**
     ** (1) when array is empty
     ** (2) when index are invalid
     */

    // when we can do edit
    /**
     ** (1) when arrray is not empty means it have some value.
     ** (2) when index are in valid range.
     */
    try{
        if(isEmpty()){
            throw ArrayEmpty();
        }
        if(index<0 || index>lastFilledIndex){
            // same here just to show different erro i choose to write two if. if index 0 and lfi is -1 this condition will be valid.
            throw IndexBoundError();
        }
        ptr[index]=newData;
    }catch(exception &error){
        cout<<"Caught in editData : "<<error.what()<<endl;
    }
}


// user of Array class.
int main (){
    Array obj1;
    // 10 size array created.
    obj1.createArray(10);
    obj1.insertData(10,0);
    obj1.insertData(20,1);
    obj1.appendData(30);
    for(int i=40; i<=100;){
        obj1.appendData(i);
        // cout<<"i is "<<i<<endl;
        i=i+10;
    }
    cout<<endl;
    cout<<"printing the array data"<<endl;
    int length=obj1.countArrayData();
    cout << endl;
    cout<<"length of array is : "<<length<<endl;
    cout<<endl;
    for(int i=0; i<length; i++){
        cout<<"item at index "<<i<<" is : "<<obj1.getData(i)<<endl;
    }

    cout<<"\n\n-----------------------\n\n";
    obj1.deleteData(0);
    length=obj1.countArrayData();
    obj1.editData(200,8);
    for (int i = 0; i < length; i++)
    {
        cout << endl<<"item at index " << i << " is : " << obj1.getData(i) << endl;
    }
    Array obj2=obj1;
    cout<<"--------------- obj2 data ----------------"<<endl<<endl;
    length=obj2.countArrayData();
    obj2.deleteData(6);
    length = obj2.countArrayData();

    for (int i = 0; i < length; i++)
    {
        // cout << endl << "item at index " << i << " is : " << obj1.getData(i) << endl;
        cout << obj2.getData(i) << " ";
    }
    cout<<endl<<endl;
    cout<<"----------- obj1 data------------- "<<endl<<endl;
    length = obj1.countArrayData();

    for (int i = 0; i < length; i++)
    {
        // cout << endl<< "item at index " << i << " is : " << obj1.getData(i) << endl;
        cout<<obj1.getData(i)<<" ";
    }
    return 0;
}
/*
--------------- obj2 data ----------------

20 30 40 50 60 70 90 200

----------- obj1 data-------------

20 30 40 50 60 70 80 90 200
in obj2 80 is missing where in obj1 80 is present that means we did sucessful deep copy....
*/
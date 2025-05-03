#include <iostream>
using namespace std;

class IndexBoundError : public exception
{
public:
    const char *what() const noexcept
    {
        return "Array index out of bounds or invalid index!";
    }
};
class ArrayEmpty : public exception
{
public:
    const char *what() const noexcept
    {
        return "Array is Empty sorry No operation performed!";
    }
};

class DynamicArray
{
private:
    int capacity;
    int lastFilledIndex;
    int *ptr;

protected:
    void doubleArray();
    void halfArray();

public:
    // constructor
    DynamicArray();
    // copy constructor
    DynamicArray(DynamicArray &dArr);
    // copy assignment operator
    DynamicArray &operator=(DynamicArray &dArr);
    // destructor.
    ~DynamicArray();
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

// protected member .... can be only accessed by user2 of this class means when we will do inheritance then protected member become private for private inheritance , protected become propted for protecte inheritance and protected become protected for public inheritance.

// doubleArray..
void DynamicArray::doubleArray()
{
    // we need to double the size...
    capacity = capacity * 2;
    int *temp = new int[capacity];
    for (int i = 0; i <= lastFilledIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
}

// half array..
void DynamicArray::halfArray()
{
    // we need to half the size.
    // int newCapacity=capacity/2;
    capacity = capacity / 2;
    // Ensure we don't lose valid data
    // if (lastFilledIndex >= newCapacity){
    //     lastFilledIndex = newCapacity - 1;
    // }
    int *temp = new int[capacity];
    for (int i = 0; i <= lastFilledIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    // capacity=newCapacity;
}

// defining constructor..
DynamicArray::DynamicArray()
{
    ptr = NULL;
}

// defining copy constructor..
DynamicArray::DynamicArray(DynamicArray &dArr)
{
    // we need to do deep copy..
    // copy constructor called when we assign the same class object at the time of new object creation.
    // we directly acess the caller properties or member variabes.
    // DynamicArray arr2 = arr1; so here arr2 is the caller and our copy constructor is called since we defined it manually and arr1 is apssed as a reference.
    capacity = dArr.capacity;
    lastFilledIndex = dArr.lastFilledIndex;
    ptr = new int[capacity];
    // now copying the data ..
    for (int i = 0; i <= lastFilledIndex; i++)
    {
        ptr[i] = dArr.ptr[i];
    }
}

// defining copy assignment operator..
DynamicArray &DynamicArray::operator=(DynamicArray &dArr)
{
    // we need to do deep copy..
    // copy constructor called when we assign the same class object at the time of new object creation.
    // we directly acess the caller properties or member variabes.
    // DynamicArray arr2 = arr1; so here arr2 is the caller and our copy constructor is called since we defined it manually and arr1 is apssed as a reference.
    capacity = dArr.capacity;
    lastFilledIndex = dArr.lastFilledIndex;
    if (ptr != NULL)
    {
        delete[] ptr;
    }
    ptr = new int[capacity];
    // now copying the data ..
    for (int i = 0; i <= lastFilledIndex; i++)
    {
        ptr[i] = dArr.ptr[i];
    }
    return (*this);
}

// defining destructor..
DynamicArray::~DynamicArray()
{
    // releasing the memory...
    delete[] ptr;
}

// createArray member function..
void DynamicArray::createArray(int incomingCapacity)
{
    // we need to create the array.
    capacity = incomingCapacity;
    lastFilledIndex = -1;
    if (ptr != NULL)
    {
        // that's means ptr point to a array alread.. we need free it because this is second time when user is calling..
        delete[] ptr;
    }
    ptr = new int[capacity];
}
bool DynamicArray::isFull()
{
    // when array is full call double array.. no we will no call the double array function here ...
    // because what if user wants to check is Array is full or not then ?? if we call the double array
    // then its just a memory wastage...
    if (lastFilledIndex == capacity - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DynamicArray::isEmpty()
{
    if (lastFilledIndex == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DynamicArray::insertData(int data, int index)
{
    // when we can't do insert...
    /**
     ** (1) when array index is invalid...
     ** (2) when array is full we need to call the fullArray function...
     */
    // when we can do insert.
    /**
     ** (1) when array is empty ..
     ** (2) when there is data already present on the given index... we need to do right shifting.
     */
    try
    {
        if (index < 0 || index > lastFilledIndex + 1)
        {
            throw IndexBoundError();
        }
        else if (lastFilledIndex == capacity - 1)
        {
            doubleArray();
        }
        if (index <= lastFilledIndex)
        {
            // we need to do shifting in right..
            for (int i = lastFilledIndex; i >= index; i--)
            {
                ptr[i + 1] = ptr[i];
            }
        }
        // when index is 0 and lastFilledIndex is -1 in that case no error will be thrown and index<=lastFilled will be false and below line will runs which is fine.. but when index 1 and lastFilledIndex is 0 then no error , 1<=0 then false so below code works which is fine..
        ptr[index] = data;
        lastFilledIndex++;
    }
    catch (exception &error)
    {
        cout << "Error caught in insertData : " << error.what() << endl;
    }
}

void DynamicArray::appendData(int data)
{
    // when we can't do the append...
    /**
     ** (1) ideally when array is full we will not be able to do append but since it is dynamic array so we will call doubleArray when array is full..
     */
    if (isFull())
    {
        doubleArray();
    }
    else
    {
        lastFilledIndex++;
        ptr[lastFilledIndex] = data;
    }
}

int DynamicArray::getData(int index)
{
    // whe we can't return the data..
    /**
     ** (1) when array is empty...
     ** (2) when index is out of bound..
     */
    // when we can return the data .
    /**
     ** (1) when array is not empty..
     */
    try
    {
        if (index < 0 || index > lastFilledIndex)
        {
            throw IndexBoundError();
        }
        else if (isEmpty())
        {
            throw ArrayEmpty();
        }
        else
        {
            return ptr[index];
        }
    }
    catch (exception &error)
    {
        cout << "Caught in getData : " << error.what() << endl;
        return -1;
    }
}

int DynamicArray::countArrayData()
{
    // this is basically length of the array ..

    // when we can't count ...
    /**
     ** (1) when array is empty ... else we can count.
     */
    try
    {
        if (isEmpty())
        {
            throw ArrayEmpty();
        }
        else
        {
            return lastFilledIndex + 1;
        }
    }
    catch (exception &error)
    {
        cout << "Caught in countArrayData : " << error.what() << endl;
        return -1;
    }
}

int DynamicArray::getCapacity()
{
    return capacity;
}

void DynamicArray::deleteData(int index)
{
    // when we can't delete the data ..
    /**
     ** (1) when the array is empty..
     ** (2) when index is out of range..
     */

    // when we can deelet the data ...
    /**
     ** (1) when array is not empty.
     ** (2) and when index are in valid range.. either index is less then lastFilledIndex or lastFilledIndex itself... and kepp in mind that when user deelte the half length of the array then call the halfArray function..
     */
    try
    {
        if (index < 0 || index > lastFilledIndex)
        {
            throw IndexBoundError();
        }
        else if (isEmpty())
        {
            throw ArrayEmpty();
        }
        else if (lastFilledIndex == (capacity - 1) / 2)
        {
            // call half array..
            cout << "halfArray is called " << endl;
            halfArray();
        }
        if (index <= lastFilledIndex)
        {
            // we need to do shifting in left..
            for (int i = index; i < lastFilledIndex; i++)
            {
                ptr[i] = ptr[i + 1];
            }
            lastFilledIndex--;
        }
    }
    catch (exception &error)
    {
        cout << "Caught in deleteData : " << error.what() << endl;
    }
}

void DynamicArray::editData(int newData, int index)
{
    // when we can't do edit..
    /**
     ** (1) when array is empty..
     ** (2) when index is out of range.
     */

    //  when we can do edit.
    /**
     ** (1) when array is not empty..
     */

    try
    {
        if (index < 0 || index > lastFilledIndex)
        {
            throw IndexBoundError();
        }
        else if (isEmpty())
        {
            throw ArrayEmpty();
        }

        if (index <= lastFilledIndex)
        {
            ptr[index] = newData;
        }
    }
    catch (exception &error)
    {
        cout << "Caugth : " << error.what() << endl;
    }
}

int main()
{
    // creating object of DynamicArray..
    DynamicArray arr1;
    arr1.createArray(5);
    arr1.insertData(10, 0);
    arr1.appendData(20);
    arr1.deleteData(1);
    cout << "the length of arr1 is : " << arr1.countArrayData() << endl;
    cout << "the capacity of arr1 is : " << arr1.getCapacity() << endl;
    arr1.appendData(20);
    arr1.appendData(30);
    arr1.appendData(40);
    arr1.appendData(50);
    cout << "the length of arr1 is : " << arr1.countArrayData() << endl;
    cout << "the capacity of arr1 is : " << arr1.getCapacity() << endl;

    arr1.appendData(60);
    arr1.appendData(70);
    arr1.appendData(80);
    cout << "the length of arr1 is : " << arr1.countArrayData() << endl;
    cout << "the capacity of arr1 is : " << arr1.getCapacity() << endl;

    arr1.deleteData(5);
    arr1.deleteData(4);
    arr1.deleteData(3);

    cout << "the length of arr1 is : " << arr1.countArrayData() << endl;
    cout << "the capacity of arr1 is : " << arr1.getCapacity() << endl;
    DynamicArray arr2 = arr1;
    cout << "\n\n-------------DATA of arr1--------------\n\n";
    int lenOfArr1 = arr1.countArrayData();
    for (int i = 0; i < lenOfArr1; i++)
    {
        cout << "valut at index " << i << " is : " << arr1.getData(i) << endl;
    }
    cout << "\n\n-------------DATA of arr2--------------\n\n";
    int lenOfArr2 = arr2.countArrayData();
    for (int i = 0; i < lenOfArr2; i++)
    {
        cout << "valut at index " << i << " is : " << arr2.getData(i) << endl;
    }

    cout << "now if we delete any one data from any one array then it is specific to it..\n\n";
    arr1.deleteData(0);
    cout << "arr1 length is : " << arr1.countArrayData() << endl;
    arr1.deleteData(0);
    cout << "arr1 length is : " << arr1.countArrayData() << endl;

    cout << "\n\n-------------DATA of arr1--------------\n\n";
    lenOfArr1 = arr1.countArrayData();
    for (int i = 0; i < lenOfArr1; i++)
    {
        cout << "valut at index " << i << " is : " << arr1.getData(i) << endl;
    }
    cout << "\n\n-------------DATA of arr2--------------\n\n";
    lenOfArr2 = arr2.countArrayData();
    for (int i = 0; i < lenOfArr2; i++)
    {
        cout << "valut at index " << i << " is : " << arr2.getData(i) << endl;
    }
    return 0;
}

/*
the length of arr1 is : 1
the capacity of arr1 is : 5
the length of arr1 is : 5
the capacity of arr1 is : 5
the length of arr1 is : 7
the capacity of arr1 is : 10
halfArray is called
the length of arr1 is : 4
the capacity of arr1 is : 5


-------------DATA of arr1--------------

valut at index 0 is : 10
valut at index 1 is : 20
valut at index 2 is : 30
valut at index 3 is : 80


-------------DATA of arr2--------------

valut at index 0 is : 10
valut at index 1 is : 20
valut at index 2 is : 30
valut at index 3 is : 80

now if we delete any one data from any one array then it is specific to it..

arr1 length is : 3
halfArray is called
arr1 length is : 2


-------------DATA of arr1--------------

valut at index 0 is : 30
valut at index 1 is : 80


-------------DATA of arr2--------------

valut at index 0 is : 10
valut at index 1 is : 20
valut at index 2 is : 30
valut at index 3 is : 80

now when we delete the data of arr1 then it has no effect on arr2 since we are doing the deep and it proved that shallow copy is not performed here ....
*/
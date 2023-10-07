#include "MyBoolVector.h"


using namespace std;

MyBoolVector::MyBoolVector()   //생성자
{
    data = new bool[5];
    allocated = 0;
    storage = 5;
}

bool & MyBoolVector::operator[](const int v)  //[] 연산자
{
    if(v>=allocated)
    {
        cout << "no data" << endl;
        exit(0);
    }

    else
        return data[v];

}

MyBoolVector::MyBoolVector(const MyBoolVector& v)  //copy constructor
{
    data = new bool[v.capacity()];
    for(int i =0; i<v.size() ; i++)
        data[i] = v.data[i];
    
    allocated = v.size();
    storage = v.capacity();


}


MyBoolVector::~MyBoolVector()         //소멸자
{
    delete[] data;

}


void MyBoolVector::operator=(const MyBoolVector &v)   //  = 연산자
{
    delete [] data;
    data = new bool[v.capacity()];
    for(int i = 0; i<v.size() ; i++)
        data[i] = v.data[i];

    allocated = v.size();
    storage = v.capacity();

}

MyBoolVector MyBoolVector::operator+=(const MyBoolVector &v) // += 연산자
{
    if(storage - allocated < v.size())
        reserve(v.size());

    for(int i =0; i<v.size() ; i++)
        data[allocated + i] = v.data[i];
    
    allocated = v.size();
    storage = v.capacity();

    return *this;

}




MyBoolVector MyBoolVector::operator+(const MyBoolVector &v)   //+연산자
{
    if(allocated != v.size())
        return *this;

    else 
        {
            for(int i = 0; i<allocated ; i++)
                data[i] += v.data[i];

            return *this;

        }
}

MyBoolVector MyBoolVector::operator-(const MyBoolVector &v)        //-연산자
{
    if(allocated != v.size())
        return *this;

    else 
        {
            for(int i = 0; i<allocated ; i++)
                data[i] -= v.data[i];

            return *this;

        }
}

bool MyBoolVector::operator==(const MyBoolVector &v)             // == 연산자
{
    if(allocated != v.size())
        return false;
    
    else
    {
        for(int i = 0; i<allocated ; i++)
        {
            if(data[i] != v.data[i])
                return false;
        }


        return true;

    }

}


bool MyBoolVector::operator!=(const MyBoolVector &v)           //!= 연산자
{
    if(allocated != v.size())
        return true;
    
    else
    {
        for(int i = 0; i<allocated ; i++)
        {
            if(data[i] != v.data[i])
                return true;
        }


        return false;

    }

}

void MyBoolVector::pop_back()              //맨 뒤 element 삭제
{
    if(allocated == 0)
        return;

    data[allocated-1] = NULL;
    allocated-=1;

    return;

}

void MyBoolVector::push_back(bool x)            //맨 뒤에 x 추가하기
{
    if(storage - allocated < 1)
        this->reserve(1);

    
    data[allocated] = x;
    allocated +=1;



}

size_t MyBoolVector::size() const                     //element의 개수 반환
{
    return allocated;
}

size_t MyBoolVector::capacity() const    //allocated 된 공간 크기 반환
{
    return storage;
}

void MyBoolVector::reserve(size_t n)               //n개의 element를 저장할 수 있는 공간 할당하기
{
    bool *temp = new bool[n+storage];
    for(int i =0; i<storage ; i++)
        temp[i] = data[i];

    storage+=n;
    delete [] data;
    data = temp;

    return;

}


bool MyBoolVector::is_empty() const            //vector container 가 비어있는지 확인
{
    if(allocated ==0)
        return true;

    else
        return false;
}


void MyBoolVector::clear()               //vector container 비우기
{
    for(int i =0; i<allocated ; i++)
    {
        data[i] = NULL;

    }

    allocated = 0;

}
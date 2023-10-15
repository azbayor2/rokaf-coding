#include <iostream>
#include <cstdlib>

using namespace std;


class MyBoolVector{

    public:

    MyBoolVector();   //생성자

    bool & operator[](const int v);  //[] 연산자

    MyBoolVector(const MyBoolVector& v);  //copy constructor
    ~MyBoolVector();         //소멸자

    void operator=(const MyBoolVector &v);   //  = 연산자
    MyBoolVector operator+=(const MyBoolVector &v); // += 연산자
    
    MyBoolVector operator+(const MyBoolVector &v);   //+연산자
    MyBoolVector operator-(const MyBoolVector &v);        //-연산자
    bool operator==(const MyBoolVector &v);             // == 연산자
    bool operator!=(const MyBoolVector &v);             //!= 연산자

    void pop_back();              //맨 뒤 element 삭제
    void push_back(bool x);            //맨 뒤에 x 추가하기
    size_t size() const;                     //element의 개수 반환
    size_t capacity() const;        //allocated 된 공간 크기 반환
    void reserve(size_t n);               //n개의 element를 저장할 수 있는 공간 할당하기
    bool is_empty() const;            //vector container 가 비어있는지 확인
    void clear();               //vector container 비우기


    private:
    bool *data;   //공간
    int allocated;    //사용된 공간
    int storage;       //전체공간



};


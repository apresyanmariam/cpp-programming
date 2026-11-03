#include <iostream>
#include <cstring>
#include <stdexcept>
#include <new>
#include <memory>

template <typename T>

class MyVector{
    private: 
        T* arr;
        int size_v;
        int capacity_v;
    
    public:

        MyVector(int n = 0){
            size_v = 0;
            capacity_v = n == 0 ? 1 : n * 2;
            arr = static_cast<T*>(::operator new(sizeof(T) * capacity_v));
        }

        MyVector(const MyVector& v) {
            size_v = v.size_v;
            capacity_v = v.capacity_v;
            arr = static_cast<T*>(::operator new(sizeof(T) * capacity_v));

            for(int i = 0; i < size_v; i++) {
                new(&arr[i]) T(v.arr[i]);
            }
        }

        void push_back_v(const T& num){
            
            if(size_v == capacity_v){
                capacity_v *= 2;
                T* newArr =  static_cast<T*>(::operator new(sizeof(T) * capacity_v));
                for(int i = 0; i < size_v; i++){
                    new (&newArr[i]) T(arr[i]);
                }
                for(int i = 0; i < size_v; i++){
                    std::destroy_at(&arr[i]);
                }
                ::operator delete(arr);
                arr = newArr;
            }

            new (&arr[size_v]) T(num);
            size_v++;
        }

        int getSize() const{
            return size_v;
        }

        T& at(int index){
            if (index < 0 || index >= size_v) {
                throw std::out_of_range("Index out of range");
            }
            return arr[index];
        }

        T& operator[] (int idx){
            return arr[idx];
        }

        const T& operator[] (int idx) const{
            return arr[idx];
        }


        MyVector& operator= (const MyVector& v){
            if(this != &v){
                for (int i = 0; i < size_v; i++) {
                    std::destroy_at(&arr[i]);
                }
                ::operator delete(arr);
                size_v = v.size_v;
                capacity_v = v.capacity_v;
                arr = static_cast<T*>(::operator new(sizeof(T) * capacity_v));

                for(int i = 0; i < size_v; i++){
                    new(&arr[i]) T(v[i]);
                }
            }
            return *this;
        }

        MyVector operator+ (const MyVector& v2) const{
            MyVector new_vector(size_v + v2.size_v);
            for(int i = 0; i < size_v; i++){
                new_vector.push_back_v(arr[i]);
            }
            for(int i = 0; i < v2.size_v; i++){
                new_vector.push_back_v(v2[i]);
            }

            return new_vector;
        }

        MyVector& operator+= (const MyVector& v2){
            for(int i = 0; i < v2.size_v; i++){
                this->push_back_v(v2.arr[i]);
            }
            return *this;
        }

        bool operator== (const MyVector& v2) const{
            if(size_v != v2.size_v) return false;
            for(int i = 0; i < size_v; i++){
                if(arr[i] != v2.arr[i]) return false;
            }
            return true;
        }
    

        ~MyVector(){
            for(int i = 0; i < size_v; i++){
                    std::destroy_at(&arr[i]);
                }
                ::operator delete(arr);
        }
};

int main(){

    MyVector<MyVector<int>> v;
    MyVector<int> row1;
    MyVector<int> row2;
    row1.push_back_v(15);
    row1.push_back_v(2);
    row1.push_back_v(7);
    row2.push_back_v(4);
    row2.push_back_v(1);
    row2.push_back_v(6);
    v.push_back_v(row1);
    v.push_back_v(row2);

    std::cout<<v[1][2];

    v[0].push_back_v(5);
    
    std::cout<<v[0][3];





    // MyVector<int> a;
    // a.push_back_v(10);
    // a.push_back_v(20);

    //copy constructor is called not operator=
    //same as MyVector<int> b(a)
    // MyVector<int> b = a; 




    // MyVector<string> v(3);
    // v.push_back_v("a");
    // v.push_back_v("b");
    // v.push_back_v("c");
    // v.push_back_v("d");
    // v.push_back_v("e");

    // MyVector<string> v2(2);
    // v2.push_back_v("f");
    // v2.push_back_v("g");

    // v = v2;
    // cout<<v[0];

    // MyVector v3;
    // v3 = v + v2;

    // cout<<v3[6];


    // v+=v2;
    // cout<<v[6];

    // bool eq = (v == v2);
    // cout<<eq;

    // cout<<v.at(4)<< " " << v.getSize();
    // cout<< v[2];
    // v[2] = 8;
    // cout<< v[2];


    return 0;
}
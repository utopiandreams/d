#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

template<typename T>
class my_array
{
    T* data;
    size_t n;

public :
    my_array(size_t n)
    {
        this->n = n;
        data = new T[n];
    }

    my_array(const my_array<T>& other){
        this->n = other.size();
        data = new T[n];

        for(int i=0;i<n;i++){
            data[i] = other[i];
        }
    }

    ~my_array()
    {
        delete[] data;
    }

    // 아래 두 함수는 서로 다른 역할을 합니다.
    
    // arr[3] = 10;
    // 과 같이 참조 대상의 값을 수정하는 경우 실행됩니다.
    T& operator[](size_t idx) {
        return data[idx];
    }

    // int value = arr[3];
    // 과 같이 참조 대상을 상수처럼 읽기 전용으로 읽어올 때 실행됩니다.
    const T& operator[](size_t idx) const
    {
        return data[idx];
    }

    const T& at(size_t idx) const 
    {
        return data[idx];
    }

    size_t size() const
    {
        return n;
    }

    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n; }

    friend my_array<T> operator+(const my_array<T>& arr1, const my_array<T>& arr2) {
        int a = arr1.size();
        int b = arr2.size();
        my_array<T> ret(a + b);
        for (int i = 0; i < a; i++) {
            ret[i] = arr1[i];
        }
        for (int i = 0; i < b; i++) {
            ret[i + a] = arr2[i];
        }
        return ret;
    }

    std::string to_string(const std::string& sep = ", ")
	{
		if (n == 0)
			return "";

		std::ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++)
			os << sep << data[i];

		return os.str();
	}

};

struct student
{
    string name;
    int age;
};

ostream& operator<<(ostream& os, const student& s){
    return (os << "[" << s.name << ", " << s.age << "]");
}


int main(){
    cout << "학생 수를 입력하세요 : " << endl;
    int studentN;
    cin >> studentN;
    my_array<student> class1(studentN);
    for(int i=0;i<studentN;i++){
        cout << i+1 << "번째 학생의 이름과 나이를 입력하세요";
        student a;
        cin >> a.name >> a.age;
        class1[i] = a;
    }
    cout << class1.to_string();
}

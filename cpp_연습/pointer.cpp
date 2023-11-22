#include<iostream>

typedef struct P
{
    int a;
    int b;
} P;

template<typename T>
void change_val1(T* sub, int pos, int num)
{
    sub[pos] = num;
}

void change_val2(int& sub, int num){
    sub = num;
}

void change_val3(P* sub, int pos, int num)
{
    sub[pos].a =  num;
}

void change_val4(P& sub, int num){
    sub.a = num;
}

void change_val5(P* (&sub)[10], int pos, int num){
    sub[pos] = new P;
    sub[pos]->a = num;
}

void change_val6(P* sub, int num){
    delete sub;
    sub = new P;
    sub->a = num;
}

int main(){
    // int 배열
    int list1[10];
    change_val1(list1, 3, 5);
    std::cout << list1[3] << std::endl;
    change_val2(list1[3], 3);
    std::cout << list1[3] << std::endl;


    // 구조체 배열
    P list2[10];
    change_val3(list2, 1, 43);
    std::cout << list2[1].a << std::endl;
    change_val4(list2[1], 72);
    std::cout << list2[1].a << std::endl;

    // 구조체 포인터 배열
    P* list3[10];
    change_val5(list3, 4, 7);
    std::cout << list3[4]->a << std::endl;
    change_val6(list3[4], 10);
    std::cout << list3[4]->a;
}
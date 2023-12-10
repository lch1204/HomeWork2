#include <iostream>
#include "list.h"

int main()
{
    
    setlocale(LC_ALL, "rus");
    List<double> list;
    list.push_back(5);
    list.push_back(12.5);
    list.push_back(22);
    list.push_back(45);
    list.push_back(531);
    list.print();
    list.erase(2);
    list.print();
    list.erase(0);
    list.print();
    list.erase(2);
    list.print();
    list.push_front(1.2);
    list.push_front(2);
    list.push_front(10);
    list.push_front(-10.0);
    list.push_back(-23);
    list.push_front(6.8);
    list.print();
    list.swapNode(1, 2);
    list.print();
    list.erase(20);
    list.print();
    list.sort(); 
    cout << "listInt" << endl;
    List<int> listInt;
    listInt.push_back(5);
    listInt.push_back(125);
    listInt.push_back(22);
    listInt.push_back(45);
    listInt.push_back(531);
    listInt.print();
    listInt.erase(2);
    listInt.print();
    listInt.erase(0);
    listInt.print();
    listInt.erase(2);
    listInt.print();
    listInt.push_front(12);
    listInt.push_front(2);
    listInt.push_front(10);
    listInt.push_front(-100);
    listInt.push_back(-23);
    listInt.push_front(68);
    listInt.print();
    listInt.swapNode(1, 2);
    listInt.print();
    listInt.erase(20);
    listInt.print();
    listInt.sort();
    listInt.swapNode(0, 7);
    listInt.print();
    listInt.swapNode(0, 8);
    listInt.print();
}

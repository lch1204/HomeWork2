#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
struct Node
{
    T data; //�� ������ ��� ������
    Node<T>* prev; //��������� �� ���������� �������
    Node<T>* next; //��������� �� ��������� �������

 //   Node() = default;
};

template <class T>
class List
{
public:

    void push_back(T data); // ���������� � ����� ������
    void push_front(T data); //���������� � ������ ������
    void erase(int index); //�������� ��������
    Node<T>* move(int index); //������� ��������� �� ������� 
    void print();//���������� ���� ������
    void clear(); //�������� ���� ������
    void swapNode(int index_one, int index_two); //������������ ���������
    bool correctIndex(int index); //�������� �� ��, ��� ������ ������ ����������
    Node<T>* head; //��������� �� ������ ������
    Node<T>* tail; //��������� �� ����� ������
    int count; //������� ���������

    //��� ���������� �������� (merge sort)
    void mergeSort(int low, int high);
    void merge(int low, int high, int mid);
    void sort();
    
    int countSort = 0;


    List();

    ~List();
 
};

#endif // LIST_H


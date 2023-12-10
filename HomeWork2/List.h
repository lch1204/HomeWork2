#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
struct Node
{
    T data; //те данные что храним
    Node<T>* prev; //указатель на предыдущий элемент
    Node<T>* next; //указатель на следующий элемент

 //   Node() = default;
};

template <class T>
class List
{
public:

    void push_back(T data); // добавление в конец списка
    void push_front(T data); //добавление в начало списка
    void erase(int index); //удаление элемента
    Node<T>* move(int index); //находим указатель на элемент 
    void print();//напечатать весь список
    void clear(); //очистить весь список
    void swapNode(int index_one, int index_two); //перестановка элементов
    bool correctIndex(int index); //проверка на то, что данный индекс существует
    Node<T>* head; //указатель на начало списка
    Node<T>* tail; //указатель на конец списка
    int count; //счетчик элементов

    //для сортировки слиянием (merge sort)
    void mergeSort(int low, int high);
    void merge(int low, int high, int mid);
    void sort();
    
    int countSort = 0;


    List();

    ~List();
 
};

#endif // LIST_H


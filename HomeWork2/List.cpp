#include "list.h"

template<class T>
List<T>::List()
{
    head = tail = nullptr; //��� �������� ������ ������� ���������� �� ���� (��� ������� ��� ��� ������� ������ ���)
    count = countSort = 0;
}

template<class T>
List<T>::~List()
{
    clear();
}

template<class T>
void List<T>::push_back(T _data)
{
    Node<T>* ptr = new Node<T>; //������� ����� �������, ���� ��� ��������� �� �����
    ptr->prev = tail;// ����������� ��������� ����� �������� ���������� ��������
    if (tail!=nullptr) //���� ������� ��������� ������� �����������
    {
        tail->next = ptr; //��������� ����� �������� �������� � ������ ��������
    }
    if (head == nullptr)
    {
        head = ptr; //��� ��� � ���� ������ ������ ������������
    }
    ptr->data = _data;
    tail = ptr; //��������� �� ����� ������ ������ ��������� �� ����� ��������� �������
    count++;
}


template<class T>
void List<T>::push_front(T _data)
{
    Node<T>* ptr = new Node<T>; //������� ����� �������, ���� ��� ��������� �� �����
    ptr->next = head;// ����������� ��������� ������ �������� ������� ��������
    if (head!=nullptr) //���� ������� ������ ������� �����������
    {
        head->prev = ptr; //��������� ����� �������� �������� � ������ ��������
    }
    if (tail == nullptr)
    {
        tail = ptr; //��� ��� � ���� ������ ������ ������������
    }
    ptr->data = _data;
    head = ptr; //��������� �� ������ ������ ������ ��������� �� ����� ��������� �������
    count++;
}




template<class T>
void List<T>::erase(int index)
{
    if (count == 0) return;
    if (!correctIndex(index)) return;
    Node<T>* ptr = move(index); //��������� ���������� �� ��������� �������
    Node<T>* ptrPrev = ptr->prev;
    Node<T>* ptrNext = ptr->next;
    if (index == 0)
        head = ptrNext; //���� ������� ������ �������
    else
        ptrPrev->next = ptrNext; //�������
    if (index == count-1)
        tail = ptrPrev; //���� ������� ���������
    else
        ptrNext->prev = ptrPrev;
    delete ptr;
    count--;
}

template<class T>
Node<T>* List<T>::move(int index)
{
    Node<T>* ptr = head; //������������� ��������� �� ������
    for (int i = 0; i < index; i++)
        ptr = ptr->next;
    return ptr;
}

template<class T>
void List<T>::print()
{
    Node<T>* ptr = head;
    for (int i = 0; i < count; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


template<class T>
void List<T>::clear()
{
    int n = count;
    for (int i = 0; i < n; i++)
        erase(0);//����� 0, �� �� ������� ������� ������� � 0, ������ ������ ����� ����������
}

template<class T>
void List<T>::swapNode(int index_one, int index_two)
{
    if (!correctIndex(index_one)) return;
    if (!correctIndex(index_two)) return;
    Node<T>* ptrOne = move(index_one);
    Node<T>* ptrTwo = move(index_two);
    T data = ptrOne->data;
    ptrOne->data = ptrTwo->data;
    ptrTwo->data = data;
}
template<class T>
inline bool List<T>::correctIndex(int index)
{
	if ((index >= 0) and (index < count))
		return true;
	else
	{
		cout << "��������� ������ �� �������� ����������, �� ������ ������ ����� ���������: "<< count << endl;
		return false;
	}

	
}

template<class T>
void List<T>::sort()
{
    mergeSort(0, count-1);
    cout << "���� ����������: ";
    print();
}



template<class T>
void List<T>::mergeSort(int low, int high)
{
    int mid;
    if (low < high)//���� ������ ���� ��� �����������
    {
        mid = (low + high) / 2;//������� ��������� ��������
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, high, mid);
    }
}

template<class T>
void List<T>::merge(int low, int high, int mid)
{
    int index = high - low + 1;
    int i, j, k;
    T* temp{ new T[index] };
    i = low;
    k = 0;
    j = mid + 1;
    while ((i <= mid) and (j <= high))
    {
        Node<T>* ptr = move(i); //��������� ���������� �� �������
        Node<T>* ptr2 = move(j); //��������� ���������� �� �������
        if (ptr->data < ptr2->data)
        {
            temp[k] = ptr->data;
            countSort++;
            k++;
            i++;
        }
        else
        {
            temp[k] = ptr2->data;
            countSort++;
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        Node<T>* ptr = move(i); //��������� ���������� �� �������
        temp[k] = ptr->data;
        countSort++;
        k++;
        i++;
    }
    while (j <= high)
    {
        Node<T>* ptr = move(j); //��������� ���������� �� �������
        temp[k] = ptr->data;
        countSort++;
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        Node<T>* ptr = move(i); //��������� ���������� �� �������
        ptr->data = temp[i-low];
    /*    cout << " ptr->data " << ptr->data  << endl;
        cout << "countSort" << countSort <<  endl;*/
    }
}

template class List<int>;
template struct Node<int>;

template class List<float>;
template struct Node<float>;

template class List<double>;
template struct Node<double>;



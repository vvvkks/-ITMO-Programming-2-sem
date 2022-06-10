#ifndef LAB_3_1_CURC_H
#define LAB_3_1_CURC_H
#include "buffer.h"

template<class T>

Circle<T>::Circle(int capacity)
{
    size = 0;
    this->capacity = capacity;
    Node *current = new Node;
    first = current;
    last = first;
    for (int i = 0; i < capacity - 1; i++)
    {
        current->next = new Node;
        (current->next)->prev = current;
        current = current->next;
    }
    current->next = first;
    first->prev = current;
}

template<class T>
int Circle<T>::Capacity()
{
    return capacity;
}

template<class T>
int Circle<T>::Size()
{
    return size;
}

template<class T>
bool Circle<T>::Is_Empty()
{
    return size == 0;
}

template<class T>
void Circle<T>::Resize(int capacity)
{
    int reverse = capacity - this->capacity;
    this->capacity = capacity;
    Node *current = new Node;
    Node *temp = last->next;
    last->next = current;
    current->prev = last;
    for (int i = 0; i < reverse - 1; i++)
    {
        current->next = new Node;
        (current->next)->prev = current;
        current = current->next;
    }
    current->next = temp;
    temp->prev = current;
}

template<class T>
void Circle<T>::Push_Back(T num)
{
    if (size == 0)
    {
        first->value = num;
        ++size;
        return;
    }
    if (size == capacity)
    {
        last = last->prev;
    } else
        ++size;
    first = first->prev;
    first->value = num;
}

template<class T>
bool Circle<T>::Pop_Back()
{
    if (size == 0)
    {
        return false;
    }
    if (size == 1)
    {
        first = last;
    }
    else
        last = last->prev;
    --size;
    return true;
}

template<class T>
void Circle<T>::Push_Front(T num)
{
    if (size == 0)
    {
        first->value = num;
        ++size;
        return;
    }
    if (last->next == first)
        first = first->next;
    else
        ++size;
    last = last->next;
    last->value = num;
}

template<class T>
bool Circle<T>::Pop_Front()
{
    if (size == 0)
    {
        return false;
    }
    if (size == 1)
    {
        first = last;
    }
    else
        first = first->next;
    --size;
    return true;
}

template<class T>
void Circle<T>::Push(Circle::Iterator it, T element)
{
    if (it == End())
    {
        Push_Front(element);
        return;
    }
    Node *current = it.num;
    Node *temp = current->next;
    current->next->value = element;
    current->next->next = temp;
    current->next->prev = current;
    if (size == capacity)
    {
        Pop_Front();
    }
    else
    {
        ++size;
        Node *erase = last->next;
        last->next = erase->next;
        erase->next->prev = last;
        delete (erase);
    }
}

template<class T>
bool Circle<T>::Delete(Circle::Iterator it)
{
    if (size == 0)
    {
        return false;
    }
    if (it == End())
    {
        Pop_Back();
    }
    else if (it == Begin())
    {
        Pop_Front();
    }
    else
    {
        --size;
        Node *erase = it.num;
        erase->next->prev = erase->prev;
        delete (erase);
        Node *temp = last->next;
        last->next = new Node;
        last->next->prev = last;
        last->next->next = temp;
        return true;
    }
}

template<class T>
T &Circle<T>::operator[](int index)
{
    Node *current = first;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->value;
}

template<class T>
Circle<T>::Iterator::Iterator(Circle::Node *i) : num(i) {}

template<class T>
typename Circle<T>::Node *Circle<T>::Iterator::operator+(int n)
{
    for (int i = 0; i < n; i++)
    {
        num = num->next;
    }
    return num;
}

template<class T>
typename Circle<T>::Node *Circle<T>::Iterator::operator-(int n)
{
    for (int i = 0; i < n; i++)
    {
        num = num->prev;
    }
    return num;
}

template<class T>
typename Circle<T>::Node *Circle<T>::Iterator::operator++(int n)
{
    return num = num->next;
}

template<class T>
typename Circle<T>::Node *Circle<T>::Iterator::operator--(int n)
{
    for (int i = 0; i < n; i++)
    {
        num = num->prev;
    }
    return num = num->prev;
}

template<class T>
bool Circle<T>::Iterator::operator==(Circle::Iterator temp)
{
    return this->num == temp.num;
}

template<class T>
bool Circle<T>::Iterator::operator!=(Circle::Iterator temp)
{
    return this->num != temp.num;
}

template<class T>
T &Circle<T>::Iterator::operator*()
{
    return num->value;
}

#endif

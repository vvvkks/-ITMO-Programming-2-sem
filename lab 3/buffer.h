#ifndef LAB_3_1_BUFFER_H
#define LAB_3_1_BUFFER_H
#pragma once

template<class T>

class Circle {

private:

    struct Node{
        T value;
        Node *prev;
        Node *next;
    };

    int capacity{};
    int size;
    Node *first;
    Node *last;

public:
    explicit Circle(int capacity);

    int Capacity();

    int Size();

    bool Is_Empty();

    void Resize(int capacity);

    void Push_Back(T num);

    bool Pop_Back();

    void Push_Front(T num);

    bool Pop_Front();

    class Iterator{

    public:

        Node *num;

        explicit Iterator(Node *i);

        Node *operator+(int n);

        Node *operator-(int n);

        Node *operator++(int n);

        Node *operator--(int n);

        bool operator==(Iterator temp);

        bool operator!=(Iterator temp);

        T &operator*();
    };

    Iterator Begin() {
        return *(new Iterator(first));
    }

    Iterator End() {
        return *(new Iterator(last));
    }

    void Push(Iterator it, T element);

    bool Delete(Iterator it);

    T &operator[](int index);
};

#endif
#ifndef LAB_3_ALGORITHMS_H
#define LAB_3_ALGORITHMS_H
#pragma once
#include <iostream>

using namespace std;

template <typename T, typename predicate>
bool all_of(const T& first, const T& last, predicate pred)
{
    for(T it = first; it != last; ++it){
        if (!pred(*it)) return false;
    }
    return true;
}

template <typename T, typename predicate>
bool any_of(const T& first, const T& last, predicate pred)
{
    for (T it = first; it != last; ++it) {
        if (pred(*it)) return true;
    }
    return false;
}

template <typename T, typename predicate>
bool none_of(const T& first, const T& last, predicate pred)
{
    for (T it = first; it != last; ++it) {
        if (pred(*it)) return false;
    }
    return true;
}

template <typename T, typename predicate>
bool one_of(const T& first, const T& last, predicate pred)
{
    for (T it = first; it != last; ++it) {
        if (pred(*it)) return true;
    }
    return false;
}
template <typename T, typename predicate>
bool is_sorted(const T& first, const T& last, predicate pred)
{
    for (T it = first; it != last; ++it) {
        if (pred(*it, *(it - 1)))
            return false;
    }
    return true;
}

template <typename T, typename predicate>
bool is_partitioned( T first, T last, predicate pred)
{
    bool newpred = pred(*first);
    bool f = 0;
    ++first;

    for (first; first != last; ++first) {
        if (pred(*first) != newpred) {
            if (f)
                return false;
            f = true;
            newpred = !newpred;
        }
    }
    return true;
}

template <typename T, typename Element>
Element find_not(const T& first, const T& last, Element elem) {
    for (T it = first; it != last; ++it) {
        if (*it != elem) {
            return *it;
        }
    }
    return elem;
}

template <typename T, typename Element>
Element find_backward(const T& first,const T& last, Element elem) {
    for (T it = last - 1; it != first; --it) {
        if (elem == *it) {
            return *it;
        }
    }
    return elem;
}

template <typename T, typename predicate>
bool is_palindrome(const T& first,const T& last, predicate pred)
{
    T start, finish;
    for (start = first, finish = last - 1; start != last && finish != first; start++, finish--) {
        if (*start != *finish) {
            return false;
        }
    }
    return true;
}

template <typename N>
bool bigger_then_two(N x) {
    return x > 2;
};

template <typename N>
bool compare(N x, N y) {
    if (y > x) {
        return true;
    }
    else {
        return false;
    }
}

#endif
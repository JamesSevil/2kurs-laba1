#include "../include/stack.h"

template <typename T>
Stack<T>::Stack(int size) : capacity(size), top(-1) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data; 
}

template <typename T>
void Stack<T>::push(T value) {
    if (top == capacity - 1) {
        throw overflow_error("Стек переполнен"); // Проверка на переполнение
    }
    data[++top] = value; // Увеличение индекса и добавление элемента
}

template <typename T>
T Stack<T>::pop() {
    if (top == -1) {
        throw underflow_error("Стек пуст"); // Проверка на пустоту
    }
    return data[top--]; // Возврат верхнего элемента и уменьшение индекса
}

template <typename T>
void Stack<T>::peek() {
    if (top == -1) {
        throw underflow_error("Стек пуст"); // Проверка на пустоту
    }
    cout << data[top] << endl; // вывод верхнего элемента без его удаления
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == -1;
}

template <typename T>
int Stack<T>::size() {
    return top + 1;
}
#include "../include/stack.h"

template <typename T>
Stack<T>::Stack(int size) : top(-1), capacity(size) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data; 
}

template <typename T>
void Stack<T>::push(T value) {
    if (top >= capacity - 1) {
        throw overflow_error("Стек переполнен"); // Проверка на переполнение
    }
    data[++top] = value; // Увеличение индекса и добавление элемента
}

template <typename T>
void Stack<T>::pop() {
    if (top < 0) {
        throw underflow_error("Стек пуст"); // Проверка на пустоту
    }
    data[--top]; // удаление верхнего элемента и уменьшение индекса
}

template <typename T>
T Stack<T>::peek() {
    if (top == -1) {
        throw underflow_error("Стек пуст"); // Проверка на пустоту
    }
    return data[top];
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top < 0;
}

template <typename T>
int Stack<T>::size() {
    return top + 1;
}
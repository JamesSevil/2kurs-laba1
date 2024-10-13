#include "../include/queue.h"

template<typename T>
Queue<T>::Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
    data = new T[capacity];
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template<typename T>
void Queue<T>::push(T value) {
    if (size == capacity) {
        throw overflow_error("Очередь переполнена"); // Проверка на переполнение
    }
    rear = (rear + 1) % capacity; // Циклическое увеличение индекса
    data[rear] = value; // Добавление элемента
    size++; // Увеличение размера очереди
}

template<typename T>
void Queue<T>::pop() {
    if (size == 0) {
        throw underflow_error("Очередь пуста"); // Проверка на пустоту
    }
    front = (front + 1) % capacity; // Циклическое увеличение индекса
    size--; // Уменьшение размера очереди
}

template<typename T>
T Queue<T>::peek() {
    if (size == 0) {
        throw underflow_error("Очередь пуста"); // Проверка на пустоту
    }
    return data[front];
}

template<typename T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

template<typename T>
int Queue<T>::Size() {
    return size;
}
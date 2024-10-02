#pragma once

#include "includes.h"

template <typename T>
struct Queue {
    T* data;        // Указатель на массив данных
    int front;      // Индекс первого элемента
    int rear;       // Индекс последнего элемента
    int capacity;   // Вместимость очереди
    int size;       // Текущий размер очереди

    Queue(int cap); // конструктор
    ~Queue(); // деструктор

    void push(T value); // ф-ия добавления элемента в конец очереди
    T pop(); // ф-ия удаления элемента с начала очереди и его возврат
    void peek(); // ф-ия вывода элемента в начале очереди
    bool isEmpty(); // ф-ия проверки очереди на пустоту
    int getSize(); // ф-ия получения размера очереди
};

#include "../src/queue.cpp" // Включаем реализацию шаблона
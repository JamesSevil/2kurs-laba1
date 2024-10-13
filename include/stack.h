#pragma once

#include "includes.h"

template <typename T>
struct Stack {
    T* data;        // Указатель на массив данных
    int top;        // Индекс верхнего элемента
    int capacity;   // Вместимость стека

    Stack(int size); // конструктор
    ~Stack(); // деструктор

    void push(T value); // добавление элемента
    void pop(); // удаление элемента
    T peek(); // вывод вершины стека
    bool isEmpty(); // проверка на пустоту
    int size(); // размер
};

#include "../src/stack.cpp" // Включаем реализацию шаблона
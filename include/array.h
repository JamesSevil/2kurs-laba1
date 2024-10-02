#pragma once

#include "includes.h"

template<typename T>
struct Array {
    T* data;       // Указатель на массив
    size_t capacity; // Вместимость массива
    size_t size;     // Текущий размер массива

    Array(); // Конструктор
    ~Array(); // Деструктор

    void resize(); // Увеличение вместимости
    void add(T value); // Добавление элемента в конец массива
    void addAt(size_t index, T value); // Добавление элемента по индексу
    T get(size_t index) const; // Получение элемента по индексу
    void remove(size_t index); // Удаление элемента по индексу
    void replace(size_t index, T value); // Замена элемента по индексу
    size_t length() const; // Вывод размера массива
    void print() const; // Вывод массива
};

#include "../src/array.cpp" // Включаем реализацию шаблона
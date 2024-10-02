#pragma once

#include "includes.h"

const int TABLE_SIZE = 10; // Размер таблицы

template<typename T>
struct KeyValuePair {
    string key;
    T value;
    KeyValuePair* next; // Указатель на следующий элемент (для цепочек)
};

template<typename T>
struct HashTable {
    KeyValuePair<T>* table[TABLE_SIZE]; // Массив указателей на элементы

    HashTable(); // Инициализация массива указателей
    ~HashTable(); // деструктор

    int hashFunction(const string& key); // Хеш-функция
    void insert(const string& key, T value); // ф-ия добавления элемента
    bool get(const string& key, T& value); // ф-ия получения элемента по ключу
    bool remove(const string& key); // ф-ия удаления элемента по ключу
};

#include "../src/hashtable.cpp" // Включаем реализацию шаблона
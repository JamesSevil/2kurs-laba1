#include "../include/hashtable.h"

template<typename T>
HashTable<T>::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

template<typename T>
HashTable<T>::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        KeyValuePair<T>* current = table[i];
        while (current) {
            KeyValuePair<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
}

template<typename T>
int HashTable<T>::hashFunction(const string& key) {
    hash<string> hashFn;
    return hashFn(key) % TABLE_SIZE;
}

template<typename T>
void HashTable<T>::insert(const string& key, T value) {
    int index = hashFunction(key);
    KeyValuePair<T>* newPair = new KeyValuePair<T>{key, value, nullptr};

    if (!table[index]) {
        table[index] = newPair; // Если ячейка пустая, добавляем новый элемент
    } else {
        KeyValuePair<T>* current = table[index];
        while (current->next) {
            if (current->key == key) {
                current->value = value; // Обновляем значение, если ключ существует
                delete newPair; // Удаляем временный элемент
                return;
            }
            current = current->next;
        }
        current->next = newPair; // Добавляем новый элемент в конец цепочки
    }
}

template<typename T>
bool HashTable<T>::get(const string& key, T& value) {
    int index = hashFunction(key);
    KeyValuePair<T>* current = table[index];
    while (current) {
        if (current->key == key) {
            value = current->value; // Возвращаем значение
            return true; // Успешное получение
        }
        current = current->next;
    }
    return false; // Ключ не найден
}

template<typename T>
bool HashTable<T>::remove(const string& key) {
    int index = hashFunction(key);
    KeyValuePair<T>* current = table[index];
    KeyValuePair<T>* previous = nullptr;

    while (current) {
        if (current->key == key) {
            if (previous) {
                previous->next = current->next; // Удаляем элемент из цепочки
            } else {
                table[index] = current->next; // Если это первый элемент в цепочке
            }
            delete current; // Освобождаем память
            return true; // Успешное удаление
        }
        previous = current;
        current = current->next;
    }
    return false; // Ключ не найден
}
//
// Created by ferathor on 04/10/18.
//

#include "List.h"

template <typename T>
List<T>::List() {
    this->size = 0;
    this->head = NULL;
}

template <typename T>
void List<T>::add(T nValue) {
    Node nNode;
    nNode.value = nValue;
    nNode.next = NULL;
    if (this->size > 0) {
        Node current = this->head;
        int count = this->size;
        while (count > 0) {
            current = current.next;
            count -= 1;
        }
        current.next = nNode;
        this->size += 1;
    } else {
        this->head = nNode;
        this->size += 1;
    }
}

template <typename T>
T List<T>::get(int index) {
    if (this->size > 0) {
        Node current;
        current = this->head;
        while (index > 0) {
            current = current.next;
            index -= 1;
        }
        return current.value;
    } else if (this->size == 0) {
        return this->head.value;
    }
}

template <typename T>
void List<T>::remove(int index) {
    if (index < this->size) {
        if (this->size > 1) {
            Node current = this->head;
            while (index > 1) {
                current = current.next;
                index -= 1;
            }
            current.next = current.next->next;
            this->size -= 1;
        } else if (this->size == 1) {
            this->head = NULL;
            this->size = 0;
        }
    }
}

template <typename T>
void List<T>::remove(T rValue) {
    if (this->head.value == rValue) {
        this->head = this->head.next;
    } else {
        Node current = this->head;
        while (current.next->value != rValue || current.next != NULL) {
            current = current.next;
        }
        if (current.next->value == rValue && current.next != NULL) {
            current.next = current.next->next;
            this->size -= 1;
        }
    }
}

template <typename T>
void List<T>::clear() {
    this->head = NULL;
    this->size = 0;
}
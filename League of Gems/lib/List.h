//
// Created by ferathor on 04/10/18.
//

#ifndef LEAGUEOFGEMS_LIST_H
#define LEAGUEOFGEMS_LIST_H
#define NULL 0;

template <typename T>
class List<T> {
    struct Node {
        T* value;
        Node* next;
    };
public:
    List();
    void add(T nValue);
    T get(int index);
    void remove(int index);          // To remove a value from a position into the list.
    void remove(T rValue);           // To remove a known value into the list.
    void clear();
private:
    Node head;
    int size;
};

#endif //LEAGUEOFGEMS_LIST_H

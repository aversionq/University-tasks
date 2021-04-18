/*
Input amount of numbers: 7
Input your numbers:
7
-51
-10
12
64
0
17
Initial list:
7 -51 -10 12 64 0 17
Sorted list:
-51 -10 0 7 12 17 64
*/


#include <iostream>


struct list
{
    int inf;
    list* next;
    list* prev;
};


void push(list*& h, list*& t, int x)
{
    list* r = new list;
    r->inf = x;
    r->next = 0;
    if (!h && !t) {
        r->prev = 0;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}


void print(list* h, list* t)
{
    list* p = h;
    while (p) {
        std::cout << p->inf << ' ';
        p = p->next;
    }
}


list* find(list* h, list* t, int x)
{
    list* p = h;
    while (p) {
        if (p->inf == x) {
            break;
        }
        p = p->next;
    }


    return p;
}


void insert_after(list*& h, list*& t, list* r, int y)
{
    list* p = new list;
    p->inf = y;
    if (r == t) {
        p->next = 0;
        p->prev = r;
        r->next = p;
        t = p;
    }
    else {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}


void del_node(list*& h, list*& t, list* r) {
    if (r == h && r == t) {
        h = t = 0;
    }
    else if (r == h) {
        h = h->next;
        h->prev = 0;
    }
    else if (r == t) {
        t = t->prev;
        t->next = 0;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}


void del_list(list*& h, list*& t)
{
    while (h) {
        list* p = h;
        h = h->next;
        h->prev = 0;
        delete p;
    }
}


void insertionSort(list*& h, list*& t, int n)
{
    int i;
    for (i = 1; i < n; ++i) {
        list* temp_val = h;
        for (int k = 0; k < (i - 1); ++k) {
            temp_val = temp_val->next;
        }
        while (temp_val && temp_val->next->inf < temp_val->inf) {
            int to_swap = temp_val->next->inf;
            temp_val->next->inf = temp_val->inf;
            temp_val->inf = to_swap;
            temp_val = temp_val->prev;
        }
    }
}


int main()
{
    int n, x;
    std::cout << "Input amount of numbers: ";
    std::cin >> n;
    list* head = 0;
    list* tail = 0;
    std::cout << "Input your numbers: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        push(head, tail, x);
    }
    std::cout << "Initial list: " << std::endl;
    print(head, tail);

    insertionSort(head, tail, n);
    std::cout << std::endl << "Sorted list: " << std::endl;
    print(head, tail);

    return 0;
}
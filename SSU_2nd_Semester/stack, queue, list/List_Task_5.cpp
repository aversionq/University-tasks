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


void insertAfter3Digit(list*& h, list*& t)
{
    int new_element;
    list* p = h;
    while (p) {
        if (abs(p->inf) >= 100 && abs(p->inf) <= 999) {
            std::cout << std::endl << "Three-digit value detected, input value of a new element: ";
            std::cin >> new_element;
            insert_after(h, t, p, new_element);
            p = p->next;
        }
        p = p->next;
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

    insertAfter3Digit(head, tail);
    std::cout << std::endl << "Changed list: " << std::endl;
    print(head, tail);

    return 0;
}
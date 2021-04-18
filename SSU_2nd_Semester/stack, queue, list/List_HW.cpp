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


void reversePrint(list* h, list* t)
{
    list* p = t;
    while (p) {
        std::cout << p->inf << ' ';
        p = p->prev;
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


std::pair<int, std::string> findLasteven(list*& h, list*& t)
{
    int lastEven = 1, x;
    list* p = h;
    while (p) {
        x = p->inf;
        if (x % 2 == 0) {
            lastEven = x;
        }
        p = p->next;
    }


    if (lastEven % 2 == 0) {
        return std::pair<int, std::string>(lastEven, "There is at least 1 even number, and the last one is");
    }
    else {
        return std::pair<int, std::string>(lastEven, "There are no even numbers.");
    }
}


list* findMinandDelete(list*& h, list*& t)
{
    int min_el, x, check_init = 0;
    list* p = h;
    list* min_ptr = p;
    while (p) {
        x = p->inf;
        if (check_init == 0) {
            min_el = x;
            check_init++;
        }
        if (x < min_el) {
            min_el = x;
            min_ptr = p;
        }
        p = p->next;
    }
    del_node(h, t, min_ptr);


    return t;
}


list* insertNULLafterLastmax(list*& h, list*& t)
{
    int max_el, x, check_init = 0;
    list* p = h;
    list* max_ptr = p;
    while (p) {
        x = p->inf;
        if (check_init == 0) {
            max_el = x;
            check_init++;
        }
        if (x > max_el) {
            max_el = x;
            max_ptr = p;
        }
        p = p->next;
    }
    insert_after(h, t, max_ptr, NULL);


    return t;
}


int main()
{
    int n, x, check_even;
    std::cout << "Input amount of numbers: ";
    std::cin >> n;
    list* head = 0;
    list* tail = 0;
    std::cout << "Input your numbers: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        push(head, tail, x);
    }


    std::cout << std::endl << "Input list: ";
    print(head, tail);


    std::cout << std::endl << std::endl << "Reversed list: ";
    reversePrint(head, tail);


    check_even = findLasteven(head, tail).first;
    if (check_even % 2 == 0) {
        std::cout << std::endl << std::endl << findLasteven(head, tail).second << " " << check_even << std::endl << std::endl;
    }
    else
    {
        std::cout << std::endl << std::endl << findLasteven(head, tail).second << std::endl << std::endl;
    }


    std::cout << "List with deleted first min element: ";
    list* new_tail = findMinandDelete(head, tail);
    print(head, new_tail);


    std::cout << std::endl << std::endl << "List with 0 after last max element: ";
    list* another_new_tail = insertNULLafterLastmax(head, new_tail);
    print(head, another_new_tail);
    std::cout << std::endl;


    return 0;
}
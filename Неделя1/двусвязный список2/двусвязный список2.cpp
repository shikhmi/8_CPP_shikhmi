#include <iostream>

//Этот код односвязного списка
//Этот список умеет совсем немного.
//Добавлять элементы в конец себя и печатать себя.


//Эта структура данных необходима для хранения одного элемента списка
struct list_item {
    int data;  //Это поле хранит данные
    list_item* next; // Это поле хранит указатель на следующий элемент
    list_item* previous; //Это поле - заготовка для превращения списка в двусвязный

    //Это конструктор,
    //Он нужен для инициализации элемента списка
    //Пока не важно как это рабоает, используйте по аналогии с вызовом в 46 строке
    list_item(int _data) : data(_data), next(nullptr), previous(nullptr) {};

};


//Эта структура данных необходима для работы со списком в целом
struct list {
    list_item* first;
    list_item* last;
    list() : first(nullptr), last(nullptr) {};
};


// Если элемент указатель, то вместо точки используется стрелка
// Тут все ясно
bool is_list_empty(list* my_list) {
    if (my_list->first == nullptr) {
        return true;
    }
    return false;
}

// Здесь реализовано добавление нового элемента
// Как только вы поймете как это работает - вы успешны
// Оператор -> означает разименование указателя и обращение к полю
// То есть cur_list->last - это то же самое, что (*cur_list).last
void pushback(list* cur_list, int data) {
    list_item* p_tmp = new list_item(data);

    if (is_list_empty(cur_list)) {
        cur_list->first = p_tmp;
        cur_list->last = p_tmp;
        return;
    }
    cur_list->last->next = p_tmp;
    p_tmp->previous = cur_list->last;
    cur_list->last = p_tmp;
}

void pushfront(list* cur_list, int data) {
    list_item* p_tmp = new list_item(data);

    if (is_list_empty(cur_list)) {
        cur_list->first = p_tmp;
        cur_list->last = p_tmp;
        return;
    }

    p_tmp->next = cur_list->first;
    cur_list->first->previous = p_tmp;
    cur_list->first = p_tmp;
}

// Эта штука проходится по списку и печатает элементы
void print_list(list* cur_list) {
    list_item* p_tmp = cur_list->first;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << " ";
        p_tmp = p_tmp->next;
    }
    std::cout << std::endl;
}

void print_reversed(list* cur_list)
{
    list_item* p_tmp = cur_list->last;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << " ";
        p_tmp = p_tmp->previous;
    }
    std::cout << std::endl;
}

void delete_back(list* cur_list)
{
    list_item* p_tmp = cur_list->last;
    cur_list->last = cur_list->last->previous;
    cur_list->last->next = nullptr;
    delete p_tmp;
}

void delete_front(list* cur_list)
{
    list_item* p_tmp = cur_list->first;
    cur_list->first = cur_list->first->next;
    cur_list->last->previous = nullptr;
    delete p_tmp;
}

int main()
{
    list l;
    std::cout << is_list_empty(&l) << std::endl;

    pushback(&l, 28);
    pushback(&l, 37);
    pushback(&l, 21);
    pushback(&l, 4);

    print_list(&l);
    print_reversed(&l);

    delete_back(&l);
    print_list(&l);
    delete_front(&l);
    print_list(&l);

    pushfront(&l, 377);
    print_list(&l);

    std::cout << is_list_empty(&l) << std::endl;
    std::cout << l.first;

    return 0;
}
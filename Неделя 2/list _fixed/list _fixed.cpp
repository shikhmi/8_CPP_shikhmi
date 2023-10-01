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
    list_item* current;

    list(list_item* First, list_item* Last) : first(First), last(Last), current(First) {};

    list() : list(nullptr, nullptr) {};

    ~list() 
    {
        current = first;
        while (current != last && current != nullptr) 
        {
            list_item* p_tmp = current;
            current = current->next;
            delete p_tmp;
        };
        delete last;
    };

    // Перемещение текущего элемента по списку
    void move_current_forward()
    {
        current = current->next;
    };

    // Добавление элемента после текущего
    void add_after_current(int data)
    {
        list_item* p_tmp = new list_item(data);

        p_tmp->previous = current;
        p_tmp->next = current->next;
        current->next->previous = p_tmp;
        current->next = p_tmp;

    }

    // Удаление текущего элемента
    void delete_current()
    {
        list_item* p_tmp = current;
        current = current->next;
        current->previous = current->previous->previous;
        current->previous->next = current;
        delete p_tmp;
    }



    // Если элемент указатель, то вместо точки используется стрелка
    // Тут все ясно
    bool is_list_empty() {
        if (first == nullptr) {
            return true;
        }
        return false;
    }

    // Здесь реализовано добавление нового элемента
    // Как только вы поймете как это работает - вы успешны
    // Оператор -> означает разименование указателя и обращение к полю
    // То есть last - это то же самое, что (*).last
    void pushback(int data) {
        list_item* p_tmp = new list_item(data);

        if (is_list_empty()) {
            first = p_tmp;
            last = p_tmp;
            return;
        }
        last->next = p_tmp;
        p_tmp->previous = last;
        last = p_tmp;
    }

    // Добавление элемента в начало списка
    void pushfront(int data) {
        list_item* p_tmp = new list_item(data);

        if (is_list_empty()) {
            first = p_tmp;
            last = p_tmp;
            return;
        }

        p_tmp->next = first;
        first->previous = p_tmp;
        first = p_tmp;
    }

    // Эта штука проходится по списку и печатает элементы
    void print_list() {
        list_item* p_tmp = first;
        while (p_tmp != nullptr) {
            std::cout << p_tmp->data << " ";
            p_tmp = p_tmp->next;
        }
        std::cout << std::endl;
    }

    // Печать элементов списка в обратном порядке
    void print_reversed()
    {
        list_item* p_tmp = last;
        while (p_tmp != nullptr) {
            std::cout << p_tmp->data << " ";
            p_tmp = p_tmp->previous;
        }
        std::cout << std::endl;
    }

    // Удаление элемента с конца списка
    void delete_back()
    {
        if (is_list_empty())
        {
            setlocale(LC_ALL, "Rus");
            std::cout << "список пуст";
            return;
        }
        if (first == last)
        {
            list_item* p_tmp = first;
            first = nullptr;
            last = nullptr;
        }
        else
        {
            list_item* p_tmp = last;
            last = last->previous;
            last->next = nullptr;
            delete p_tmp;
        }

    }

    // Удаление элемента из начала списка
    void delete_front()
    {
        if (is_list_empty())
        {
            setlocale(LC_ALL, "Rus");
            std::cout << "список пуст";
            return;
        }
        if (first == last)
        {
            list_item* p_tmp = last;
            first = nullptr;
            last = nullptr;
        }
        else
        {
            list_item* p_tmp = first;
            first = first->next;
            last->previous = nullptr;
            delete p_tmp;
        }

    }

};

//std::pair<list*, list*> split_list(list* cur_list)
list* split_list(list* cur_list) 
{
    list* list1 = new list(cur_list->first, cur_list->current);
    list* list2 = new list(cur_list->current->next, cur_list->last);
    /*
    list1->last->next = nullptr;
    list2->first->previous = nullptr;
    
    cur_list->first = nullptr;
    cur_list->last = nullptr;
    cur_list->current = nullptr;

    delete cur_list;
    return std::make_pair(list1, list2)
    */

    return list1;
};

/* Функциями удаления элементов из начала и из конца.
        Указателем на выбранный(текущий) элемент
        (Кроме указателя на первый и последний появляется еще один, по умолчанию пусть смотрит на первый)
        Возможностью 
        - вставить элемент после текущего
        - удалить текущий элемент
        - перемещать текущий(указатель на него) элемент по списку
        */

int main()
{
    list l;
    std::cout << l.is_list_empty() << std::endl;

    l.pushback(28);
    l.pushback(37);
    l.print_list();
    l.delete_back();
    l.print_list();
    l.delete_back();
    l.print_list();
    l.delete_back();


    // Проверка добавления с начала
    l.pushfront(377);
    l.print_list();

    std::cout << l.is_list_empty() << std::endl;
    std::cout << l.first;

    return 0;









    /*РЕфакторинг списка!
    Внесите функции для работы со списком внутрь структуры (должны стать функциями членами).
    Научите ваш список биться на 2 списка по текущему элементу.
    Приведите названия переменных и функций к единообразному виду.
    Кратко сформулируйте в комментариях в коде принципы, на основе которых вы именовали объекты.
    Приведите main(); к 'правильному' состоянию (демонстрируется корректная работа всех функций, программа объясняет пользователю что происходит)
    Дополните структуру list списка деструктором, не допускающим утечек памяти.
    */
};
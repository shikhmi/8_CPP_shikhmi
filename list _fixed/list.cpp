#pragma once
#include "list_item.cpp"
#include <iostream>
//��� ��������� ������ ���������� ��� ������ �� ������� � �����
struct list {

private:
    list_item* first;
    list_item* last;
    list_item* current;

public:

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

    int get_first() const
    {
        return first->data;
    };

    int get_current() const
    {
        return current->data;
    };

    int get_last() const
    {
        return last->data;
    };

    friend list* split_list(list*);
    // ����������� �������� �������� �� ������ �����
    void move_current_forward()
    {
        current = current->next;
    };

    // ����������� �������� �������� �� ������ �����
    void move_current_back()
    {
        current = current->previous;
    };

    // ���������� �������� ����� ��������
    void add_after_current(int data)
    {
        list_item* p_tmp = new list_item(data);

        p_tmp->previous = current;
        p_tmp->next = current->next;
        current->next->previous = p_tmp;
        current->next = p_tmp;

    }

    // �������� �������� ��������
    void delete_current()
    {
        list_item* p_tmp = current;
        current = current->next;
        current->previous = p_tmp->previous;
        current = p_tmp->previous;
        current->next = p_tmp->next;
        current = p_tmp->next;
        delete p_tmp;
    }



    // ���� ������� ���������, �� ������ ����� ������������ �������
    // ��� ��� ����
    bool is_list_empty() {
        if (first == nullptr) {
            return true;
        }
        return false;
    }

    // ����� ����������� ���������� ������ ��������
    // ��� ������ �� ������� ��� ��� �������� - �� �������
    // �������� -> �������� ������������� ��������� � ��������� � ����
    // �� ���� last - ��� �� �� �����, ��� (*).last
    void pushback(int data) {
        list_item* p_tmp = new list_item(data);

        if (is_list_empty()) {
            first = p_tmp;
            last = p_tmp;
            current = p_tmp;
            return;
        }
        last->next = p_tmp;
        p_tmp->previous = last;
        last = p_tmp;
    }

    // ���������� �������� � ������ ������
    void pushfront(int data) {
        list_item* p_tmp = new list_item(data);

        if (is_list_empty()) {
            first = p_tmp;
            last = p_tmp;
            current = p_tmp;
            return;
        }

        p_tmp->next = first;
        first->previous = p_tmp;
        first = p_tmp;
    }

    // ��� ����� ���������� �� ������ � �������� ��������
    void print_list() {
        list_item* p_tmp = first;
        while (p_tmp != nullptr) {
            std::cout << p_tmp->data << " ";
            p_tmp = p_tmp->next;
        }
        std::cout << std::endl;
    }

    // ������ ��������� ������ � �������� �������
    void print_reversed()
    {
        list_item* p_tmp = last;
        while (p_tmp != nullptr) {
            std::cout << p_tmp->data << " ";
            p_tmp = p_tmp->previous;
        }
        std::cout << std::endl;
    }

    // �������� �������� � ����� ������
    void delete_back()
    {
        if (is_list_empty())
        {
            setlocale(LC_ALL, "Rus");
            std::cout << "������ ����";
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

    // �������� �������� �� ������ ������
    void delete_front()
    {
        if (is_list_empty())
        {
            setlocale(LC_ALL, "Rus");
            std::cout << "������ ����";
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

    void set_current_to_first()
    {
        current = first;
    };

    bool current_is_last() const
    {
        return current == last;
    };

    list(list* const other)
    {

        first = new list_item(other->get_first());
        last = new list_item(other->get_last());
        current = first;
        first->next = last;
        last->previous = first;

        other->set_current_to_first();
        while (!other->current_is_last())
        {
            other->move_current_forward();
            add_after_current(other->get_current());
            move_current_forward();
        };

        /*
        for (current = first; current != nullptr; current = current->next)
        {
            add_after_current(other->get_current());
        }*/
    };

    /*
    Elem* temp = Head;
    // �������� �������� ������, ������� � ���������,
    // � ���� ����� ���������� ��������� � ������,
    // ����� ������� ��������� ������ Result ����� ���������
    // �������� � �������� �������
    while (temp != 0)
    {
        Result.AddHead(temp->data);
        temp = temp->next;
    }
    return Result;*/
};



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

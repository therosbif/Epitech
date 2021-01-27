/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall [WSL: Arch]
** File description:
** list
*/

#include "container.h"
#include "new.h"
#include "list.h"
#include <string.h>
#include <limits.h>

typedef struct {
    Iterator base;
    ListClass  *_list;
    node_t *_node;
}   ListIteratorClass;

static void List_push_back(ListClass *this, Object *elem)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *iterator = this->_nodes;

    if (!new_node)
        raise("Could not allocate enough memory for new node");
    new_node->value = elem;
    new_node->next = 0;
    if (!iterator) {
        this->_nodes = new_node;
        return;
    }
    while (iterator->next) iterator = iterator->next;
    iterator->next = new_node;
    return;
}

static void List_push_front(ListClass *this, Object *elem)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        raise("Could not allocate enough memory for new node");
    else {
        new_node->value = elem;
        new_node->next = this->_nodes;
        this->_nodes = new_node;
    }
}

static Object *List_pop_back(ListClass *this)
{
    node_t *iter = this->_nodes;
    Object *to_return;

    if (!this->_nodes) return 0;
    if (!this->_nodes->next) {
        to_return = this->_nodes->value;
        free(this->_nodes);
        this->_nodes = 0;
        return to_return;
    }
    while (iter->next->next) iter = iter->next;
    to_return = iter->next->value;
    free(iter->next);
    iter->next = 0;
    return to_return;
}

static Object *List_pop_front(ListClass *this)
{
    node_t *new_list;
    Object *to_return;

    if (this->_nodes == 0) return 0;
    new_list = this->_nodes->next;
    to_return = this->_nodes->value;
    free(this->_nodes);
    this->_nodes = new_list;
    return to_return;
}

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    int index;
    int i = 0;

    this->_list = va_arg(*args, ListClass *);
    this->_node = 0;
    index = va_arg(*args, int);
    for (node_t *iter = this->_list->_nodes; iter; iter = iter->next) {
        if (index == i) {
            this->_node = iter;
        }
        i++;
    }
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_node == other->_node);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    int index_this = INT_MAX;
    int index_other = INT_MAX;
    int i = 0;

    for (node_t *iter = this->_list->_nodes; iter; iter = iter->next) {
        if (iter == this->_node)
            index_this = i;
        if (iter == other->_node)
            index_other = i;
        i++;
    }
    return (index_this > index_other);
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    int index_this = INT_MAX;
    int index_other = INT_MAX;
    int i = 0;

    for (node_t *iter = this->_list->_nodes; iter; iter = iter->next) {
        if (iter == this->_node)
            index_this = i;
        if (iter == other->_node)
            index_other = i;
        i++;
    }
    return (index_this < index_other);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    if (!this->_node)
        raise("Out of range");
    this->_node = this->_node->next;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    if (!this->_node)
        return 0;
    return this->_node->value;
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list args;

    if (!this->_node) {
        List_push_back(this->_list, va_new(this->_list->_type, &args));
    } else {
        va_start(args, this);
        delete(this->_node->value);
        this->_node->value = va_new(this->_list->_type, &args);
        va_end(args);
    }
}

static const ListIteratorClass ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._node = NULL
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

static void List_ctor(ListClass *this, va_list *args)
{
    this->_type = va_arg(*args, Class *);
    this->_nodes = 0;
    va_end(*args);
}

static void List_dtor(ListClass *this)
{
    node_t *temp = 0;

    for (node_t *iter = this->_nodes; iter; iter = iter->next) {
        free(temp);
        temp = iter;
    }
    free(temp);
}

static size_t List_len(ListClass *this)
{
    int i = 0;

    for (node_t *iter = this->_nodes; iter; iter = iter->next)
        i++;
    return i;
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this, this->base.__len__((Container *) this)));
}

static Object *List_getitem(ListClass *this, ...)
{
    size_t requested_index;
    va_list args;
    size_t i = 0;

    va_start(args, this);
    requested_index = va_arg(args, size_t);
    for (node_t *iter = this->_nodes; iter; iter = iter->next) {
        if (i == requested_index) {
            va_end(args);
            return iter->value;
        }
        i++;
    }
    va_end(args);
    raise("The requested element is out of bounds\n");
}

static void List_setitem(ListClass *this, ...)
{
    size_t requested_index;
    va_list args;
    size_t i = 0;

    va_start(args, this);
    requested_index = va_arg(args, size_t);
    for (node_t *iter = this->_nodes; iter; iter = iter->next) {
        if (i == requested_index) {
            delete(iter->value);
            iter->value = va_new(this->_type, &args);
            va_end(args);
            return;
        }
        i++;
    }
    if (i == requested_index) {
        List_push_back(this, va_new(this->_type, &args));
        va_end(args);
        return;
    }
    va_end(args);
    raise("The requested element is out of bounds\n");
}

static ListClass *List_add(ListClass *this, ListClass *other)
{
    ListClass *new_list;

    if (this->_type != other->_type)
        raise("Both types must be equal.");
    new_list = new(List, this->_type);
    for (node_t *iter = this->_nodes; iter; iter = iter->next)
        new_list->push_back(new_list, iter->value);
    for (node_t *iter = other->_nodes; iter; iter = iter->next)
        new_list->push_back(new_list, iter->value);
    return new_list;
}

static char *List_str(ListClass *this)
{
    char *content = strdup("<List (");
    char *item;
    int i = 0;

    for (node_t *iter = this->_nodes; iter; iter = iter->next) {
        item = str(iter->value);
        content = realloc(content, strlen(content) + strlen(item) +
            (i != 0 ? 3 : 1));
        if (i != 0) strcat(content, ", ");
        strcat(content, item);
        free(item);
        i++;
    }
    content = realloc(content, strlen(content) + 3);
    strcat(content, ")>");
    return content;
}

static const ListClass _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = (to_string_t)&List_str,
            .__add__ = (binary_operator_t)&List_add,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._nodes = NULL,
    .push_front = &List_push_front,
    .push_back = &List_push_back,
    .pop_front = &List_pop_front,
    .pop_back = &List_pop_back
};

const Class *List = (const Class *)&_descr;

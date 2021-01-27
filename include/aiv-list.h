// //#pragma AIV_LIST_H
// #ifndef AIV_LIST_H
// #define AIV_LIST_H

// #include "global_variables.h"


// struct aiv_list_node {
//     void* data;
//     struct aiv_list_node* next;
// };
// typedef struct aiv_list_node alnode;

// struct aiv_list {
//     alnode* __head;
//     alnode* __tail;
// };
// typedef struct aiv_list alist;

// alist* aiv_list_new();
// void aiv_list_destroy(alist* list);
// void aiv_list_add(alist* list, void* elem);
// boolean aiv_list_is_empty(alist*); //ok
// uint    aiv_list_size(alist*);//ok
// void*   aiv_list_item_at(alist*, uint index);//ok
// boolean aiv_list_set(alist*, void *elem, uint index);//ok
// void    aiv_list_add(alist*, void *elem);//ok
// void    aiv_list_add_at(alist*, void *data, uint index);//ok
// void    aiv_list_destroy(alist*);//ok
// void    aiv_list_remove(alist*, void* data);//ok
// void    aiv_list_remote_at(alist*, uint index);//ok
// boolean aiv_list_contains(alist*, void *data);//ok
// int     aiv_list_index_of(alist*, void *data);//ok


// #endif /* AIV_LIST_H */
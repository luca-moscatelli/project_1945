// #include "aiv-list.h"
// #include "global_variables.h"
// #include <stdlib.h>

// alist *aiv_list_new()
// {
//     alist *list = (alist *)malloc(sizeof(alist));
//     list->__head = NULL;
//     list->__tail = NULL;
//     return list;
// }

// void aiv_list_destroy(alist *list)
// {
//     alnode *each = list->__head;
//     while (each != NULL)
//     {
//         alnode *next = each->next;
//         free(each);
//         each = next;
//     }
//     free(list);
// }

// void aiv_list_add(alist *list, void *elem)
// {
//     alnode *node = (alnode *)malloc(sizeof(alnode));
//     node->data = elem;
//     node->next = NULL;

//     if (list->__head == NULL)
//     {
//         list->__head = node;
//         list->__tail = node;
//     }
//     else
//     {
//         list->__tail->next = node;
//         list->__tail = node;
//     }
// }

// boolean aiv_list_is_empty(alist *list)
// {
//     if (list->__head == NULL)
//         return true;
//     return false;
// }

// uint aiv_list_size(alist *list)
// {
//     uint size = 1;

//     alnode *node = list->__head;

//     while (node != list->__tail)
//     {
//         size++;
//         node = node->next;
//     }

//     return size;
// }

// void *aiv_list_item_at(alist *list, uint index)
// {
//     alnode *node = list->__head;

//     for (size_t i = 0; i < index; i++)
//     {
//         if (node->next == NULL)
//             return NULL;

//         node = node->next;
//     }
//     return node->data;
// }

// boolean aiv_list_set(alist *list, void *data, uint index)
// {
//     alnode *node = list->__head;

//     for (size_t i = 0; i < index; i++)
//     {
//         if (node->next == NULL)
//             return false;
//         node = node->next;
//     }

//     node->data = data;

//     return true;
// }

// void aiv_list_add_at(alist *list, void *data, uint index)
// {
//     alnode *node = list->__head;

//     alnode *newNode = (alnode *)malloc(sizeof(alnode));

//     newNode->data = data;

//     for (size_t i = 0; i < index - 1; i++)
//     {
//         if (node->next == NULL)
//             return;
//         node = node->next;
//     }
//     alnode *tmp = node->next;

//     node->next = newNode;

//     newNode->next = tmp;
// }

// void aiv_list_remove(alist *list, void *data)
// {

//     alnode *currNode = list->__head;
//     alnode *prevNode = NULL;

//     while (currNode != NULL)
//     {
//         if (currNode->data == data)
//         {
//             if (prevNode != NULL)
//             {
//                 prevNode->next = currNode->next;
//             }

//             else
//             {
//                 list->__head = currNode->next;
//             }

//             free(currNode);
//             return;
//         }
//         prevNode = currNode;
//         currNode = currNode->next;
//     }
// }

// void aiv_list_remote_at(alist *list, uint index)
// {
//     alnode *node = list->__head;

//     for (size_t i = 0; i < index; i++)
//     {
//         node = node->next;
//     }

//     aiv_list_remove(list, node->data);
// }

// boolean aiv_list_contains(alist *list, void *data)
// {
//     alnode *node = list->__head;
//     while (node->data != data)
//     {
//         if (node == list->__tail)
//             return false;
//         node = node->next;
//     }

//     return true;
// }

// int aiv_list_index_of(alist *list, void *data)
// {
//     alnode *node = list->__head;

//     int index = 0;

//     while (node->data != data)
//     {
//         if (node == list->__tail)
//             return -1;
//         node = node->next;
//         index++;
//     }

//     return index;
// }

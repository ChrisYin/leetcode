//
// Created by zhenguo on 19-4-17.
//

#include "gslist.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Adds a new element on to the end of the list.
 *
 * The return value is the new start of the list, which may
 * have changed, so make sure you store the new value.
 */
GSlist *gslistAppend(GSlist *list, ElementType data) {
    GSlist *newList;
    GSlist *lastNode;

    newList = malloc(sizeof(GSlist));
    newList->data = data;
    newList->next = NULL;

    if (list) {
        lastNode = gslistLast(list);
        lastNode->next = newList;
        return list;
    } else {
        return newList;
    }
}

/*
 * Adds a new element on to the start of the list.
 *
 * The return value is the new start of the list, which
 * may have changed, so make sure you store the new value.
 */
GSlist *gslistPrepend(GSlist *list, ElementType data) {
    GSlist *newList;

    newList = malloc(sizeof(GSlist));
    newList->data = data;
    newList->next = list;
    return newList;
}

/*
 * If this is negative, or is larger than the number
 * of elements in the list, the new element is added on
 * to the end of the list.
 *
 * Inserts a new element into the list at the given position.
 *
 * Returns: the new start of the #GSList
 */
GSlist *gslistInsert(GSlist *list, ElementType data, int position) {

    if (position == 0)
        return gslistPrepend(list, data);

    if (position < 0)
        return gslistAppend(list, data);

    GSlist *newList;
    GSlist *tmpList;
    GSlist *prevList;

    newList = malloc(sizeof(GSlist));
    newList->data = data;
    newList->next = NULL;

    if (!list) {
        return newList;
    }

    prevList = NULL;
    tmpList = list;

    while ((position-- > 0) && tmpList) {
        prevList = tmpList;
        tmpList = tmpList->next;
    }

    //corectly insert
    newList->next = prevList->next;
    prevList->next = newList;

    return list;
}

/*
* Removes the node link_ from the list and frees it.
* Compare this to g_list_remove_link() which removes the node
* without freeing it.
*
* Returns: the (possibly changed) start of the #GList
*/
GSlist *gslistRemoveLink(GSlist *list, GSlist *link) {
    GSlist *tmp = NULL;
    GSlist **previous_ptr = &list;

    while (*previous_ptr) {
        tmp = *previous_ptr;
        if (tmp == link) {
            *previous_ptr = tmp->next;
            tmp->next = NULL;
            break;
        }

        previous_ptr = &tmp->next;
    }

    return list;
}

/*
*
* Removes an element from a #GList.
* If two elements contain the same data, only the first is removed.
* If none of the elements contain the data, the #GList is unchanged.
*
* Returns: the (possibly changed) start of the #GList
*/
GSlist *gslistRemove(GSlist *list, ElementType data) {
    GSlist *tmp = NULL;
    GSlist **previous_ptr = &list;

    while (*previous_ptr) {
        tmp = *previous_ptr;
        if (tmp->data == data) {
            *previous_ptr = tmp->next;
            free(tmp);
            break;
        } else {
            previous_ptr = &tmp->next;
        }
    }

    return list;
}

/*
 * Gets the last element in a #GSList.
*
* This function iterates over the whole list.
*
* Returns: the last element in the #GSList,
*     or %NULL if the #GSList has no elements
*/
GSlist *gslistLast(GSlist *list) {
    if (list) {
        while (list->next)
            list = list->next;
    }
    return list;
}

unsigned int gslistLength(GSlist *list) {
    uint length;

    length = 0;
    while (list) {
        length++;
        list = list->next;
    }

    return length;
}

int main(){
    GSlist *root = NULL;
    root = gslistAppend(root, 40);
    root = gslistAppend(root, 10);
    root = gslistPrepend(root, 60);
    while(root){
        printf("%d ", root->data);
        root = root->next;
    }
    return 0;
}
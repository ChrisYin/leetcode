//
// Created by zhenguo on 19-4-17.
//

#ifndef FOROFFER_SLIST_H
#define FOROFFER_SLIST_H


typedef int ElementType;
typedef struct GSlist{
    ElementType data;
    struct GSlist *next;
}GSlist;


GSlist *gslistAppend(GSlist *list, ElementType data);
GSlist *gslistPrepend(GSlist *list, ElementType data);
GSlist *gslistInsert(GSlist *list, ElementType data, int position);

GSlist *gslistRemoveLink(GSlist *list, GSlist *link);
GSlist *gslistRemove(GSlist *list, ElementType data);

GSlist *gslistLast(GSlist *list);

unsigned int gslistLength(GSlist *list);

#endif //FOROFFER_SLIST_H

/* adlist.c - A simple generic doubly linked list implementation
 * Copyright (C) 2006 Salvatore Sanfilippo <antirez@invece.org>
 * This software is released under the GPL license version 2.0 */

#ifndef __ADLIST_H__
#define __ADLIST_H__

/* Node, List, and Iterator are the only data structures used currently. */



//���쿪ʼע��redis
/*
 ���Ǵ���ע�ͼ����汾��redis
 
 
*/
typedef struct listNode {
    /*
     prepare node
	*/
    struct listNode *prev;
	/*
     next node
	*/
    struct listNode *next;
	/*
	 value domain
	*/
    void *value;
} listNode;

/*
 list�ṹʹ��
*/
typedef struct list {
	/*
	 �ṹͷ�ڵ�
	*/
    listNode *head;
	/*
	 �ṹ�β��?
	*/
    listNode *tail;
	/*
	 ���ƽ�ڵ?
	*/
    void *(*dup)(void *ptr);
	/*
	 release��ڵ?
	*/
    void (*free)(void *ptr);
	/*
	  matchƥ��
	*/
    int (*match)(void *ptr, void *key);
	/*
	 �ʵ�ʳ��?
	*/
    int len;
} list;

//list������
typedef struct listIter {
    listNode *next;
    listNode *prev;
    int direction;
} listIter;

/* Functions implemented as macros */
#define listLength(l) ((l)->len)
#define listFirst(l) ((l)->head)
#define listLast(l) ((l)->tail)
#define listPrevNode(n) ((n)->prev)
#define listNextNode(n) ((n)->next)
#define listNodeValue(n) ((n)->value)

/*
 ���÷���
*/
#define listSetDupMethod(l,m) ((l)->dup = (m))
#define listSetFreeMethod(l,m) ((l)->free = (m))
#define listSetMatchMethod(l,m) ((l)->match = (m))


/*
 ��ȡ����
*/
#define listGetDupMethod(l) ((l)->dup)
#define listGetFree(l) ((l)->free)
#define listGetMatchMethod(l) ((l)->match)

/* Prototypes */
/*@
   �����ͷŽڵ�
@*/
list *listCreate(void);
void listRelease(list *list);


/*@
  ��ӽڵ�ֵ
@*/
list *listAddNodeHead(list *list, void *value);
list *listAddNodeTail(list *list, void *value);
/*@
 ɾ���ڵ�ֵ
@*/
void listDelNode(list *list, listNode *node);
/*
 @��ȡ������
 @
*/
listIter *listGetIterator(list *list, int direction);
/*@
 ��ȡ��һ��Ԫ��
@*/
listNode *listNextElement(listIter *iter);
/*@
�ͷŵ�����ʹ�ý��
@*/
void listReleaseIterator(listIter *iter);
/*@
 listdup
@*/
list *listDup(list *orig);
/*
 @ 
 �ͷ� listsearchkey()
 @
*/
listNode *listSearchKey(list *list, void *key);
/*@
 listindex
@*/
listNode *listIndex(list *list, int index);

/* Directions for iterators */
#define AL_START_HEAD 0
#define AL_START_TAIL 1

#endif /* __ADLIST_H__ */

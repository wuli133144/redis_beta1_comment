/* adlist.c - A simple generic doubly linked list implementation
 * Copyright (C) 2006 Salvatore Sanfilippo <antirez@invece.org>
 * This software is released under the GPL license version 2.0 */

#ifndef __ADLIST_H__
#define __ADLIST_H__

/* Node, List, and Iterator are the only data structures used currently. */



//今天开始注释redis
/*
 我是打算注释几个版本的redis
 
 
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
 list结构使用
*/
typedef struct list {
	/*
	 结构头节点
	*/
    listNode *head;
	/*
	 结构挝步岬?
	*/
    listNode *tail;
	/*
	 复制浇诘?
	*/
    void *(*dup)(void *ptr);
	/*
	 release浇诘?
	*/
    void (*free)(void *ptr);
	/*
	  match匹配
	*/
    int (*match)(void *ptr, void *key);
	/*
	 适导食ざ?
	*/
    int len;
} list;

//list迭代器
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
 设置方法
*/
#define listSetDupMethod(l,m) ((l)->dup = (m))
#define listSetFreeMethod(l,m) ((l)->free = (m))
#define listSetMatchMethod(l,m) ((l)->match = (m))


/*
 获取方法
*/
#define listGetDupMethod(l) ((l)->dup)
#define listGetFree(l) ((l)->free)
#define listGetMatchMethod(l) ((l)->match)

/* Prototypes */
/*@
   创建释放节点
@*/
list *listCreate(void);
void listRelease(list *list);


/*@
  添加节点值
@*/
list *listAddNodeHead(list *list, void *value);
list *listAddNodeTail(list *list, void *value);
/*@
 删除节点值
@*/
void listDelNode(list *list, listNode *node);
/*
 @获取迭代器
 @
*/
listIter *listGetIterator(list *list, int direction);
/*@
 获取下一个元素
@*/
listNode *listNextElement(listIter *iter);
/*@
释放迭代器使用结果
@*/
void listReleaseIterator(listIter *iter);
/*@
 listdup
@*/
list *listDup(list *orig);
/*
 @ 
 释放 listsearchkey()
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

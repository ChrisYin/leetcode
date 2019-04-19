# Queue.h

queue.h 来自于FreeBSD系统中的头文件, 以宏定义的方式实现了四种数据结构:单链表,单链尾队列,双向链表,双向尾队列.

## A Singly-linked list

新元素添加在链表的开头或者某个元素之后, 从头部遍历整个链表.
用于实现LIFO队列

## A Singly-linked tail queue

新元素能够添加在队列的尾部或者头部, 从头部遍历整个链表.
用于实现FIFO队列

## A list

双向遍历, 双向链接

新元素可以从开头或者某个元素前后添加


## A tail queue

双向遍历, 双向链接
新元素可以添加在队列末端

+ 使用

TAILQ_ENTRY(type)

TAILQ_HEAD(name, type)

TAILQ_INSERT_HEAD(head, elm, field)

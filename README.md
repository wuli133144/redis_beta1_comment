
# about
 redis beta1注释

# feature

1.我会持续的注释redis的代码，先从低版本的注释开始
2.beta1版本比较容易理解，在事件驱动里只是使用了select()函数
3.关键的几个文件就是dict.h dict.c 文件



# layout

+--------
   |
   |---aelist.h aelist.c 是双端链表
   |
   |————ae.h ae.c是事件驱动程序
   |
   |____redis.c 是redis启动程序


# table

文件  | 文件说明
|:-------------------- |:---------------

|ae.h ae.c             | 表示事件驱动
|aelist.h aelist.c     |  表示list结构
|redis.c               |  启动程序

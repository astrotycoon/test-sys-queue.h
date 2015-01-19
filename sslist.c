/**
 *          File: slist.c
 *
 *        Create: 2015-1-19 10:05:05
 *
 *   Discription: sys/queue.h中的单向链表使用测试程序
 *
 *        Author: astrol 
 *         Email: astrotycoon@gmail.com
 *
 *===========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct _Data {
	int 				value;
	/* ... 任意其他数据 */
	SLIST_ENTRY(_Data)	slist_entry;	
};

int main(int argc, const char *argv[])
{
	/* 初始化单链表 */
#if 0
	SLIST_HEAD(slist_head, _Data) head = SLIST_HEAD_INITIALIZER(&head);	
#else
	SLIST_HEAD(slist_head, _Data) head;
	SLIST_INIT(&head);
#endif
	int i;

	/* 往单链表中添加10个数据元素 */
	struct _Data *prev = NULL;
	for (i = 0; i < 10; i++) {
		struct _Data *cur = (struct _Data *)calloc(1, sizeof(struct _Data));	
		cur->value = i;	
#ifdef _DEBUG
		printf("%p -- %d\n", cur, cur->value);
#endif
		if (SLIST_EMPTY(&head))	{
			SLIST_INSERT_HEAD(&head, cur, slist_entry);	
		} else {
			SLIST_INSERT_AFTER(prev, cur, slist_entry);		
			// 为什么没有SLIST_INSERT_BEFORE()?
		}
		prev = cur;
	}

	puts("");

#ifdef _DEBUG
	printf("old head %p %p\n", &head, SLIST_FIRST(&head));
#endif
	SLIST_REMOVE_HEAD(&head, slist_entry);
#ifdef _DEBUG
	printf("new head %p %p\n", &head, SLIST_FIRST(&head));
#endif

	puts("");

	struct _Data *pdata = NULL;
	/* 遍历整个单链表，并删除每个元素 */
#if 0
	for (pdata = SLIST_FIRST(&head); pdata; pdata = SLIST_NEXT(pdata, slist_entry)) {
		printf("%p -- %d\n", pdata, pdata->value);
		free(pdata);
		SLIST_REMOVE(&head, pdata, _Data, slist_entry);
	}
#else
	SLIST_FOREACH(pdata, &head, slist_entry) {
		printf("%p -- %d\n", pdata, pdata->value);
		free(pdata);
		SLIST_REMOVE(&head, pdata, _Data, slist_entry);
	}
#endif
	puts("");

	if (SLIST_EMPTY(&head)) {
		printf("slist is empty now.\n");	
	}

	exit(EXIT_SUCCESS);
}

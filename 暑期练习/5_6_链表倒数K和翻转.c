#include<stdio.h>
#include<stdlib.h>
#define Elem int

typedef struct LinkNode {
	Elem elem;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkList {
	LinkNode *head;
}LinkList;

void init(LinkList *plist) {
	plist->head = NULL;
}

void frontPush(LinkList *plist, Elem x) {
	LinkNode *cur = (LinkNode*)malloc(sizeof(LinkNode));
	cur->elem = x;
	cur->next = plist->head;
	plist->head = cur;
}

void frontPop(LinkList *plist) {
	LinkNode *tmp;
	if(plist->head) {
		tmp = plist->head;
		plist->head = tmp->next;
		free(tmp);
	}
}

void destroy(LinkList *plist) {
	LinkNode *tmp;
	while(plist->head) {
		tmp = plist->head;
		plist->head = tmp->next;
		free(tmp);
	}
}

void print(LinkList *plist) {
	LinkNode *cur;
	for(cur = plist->head; cur; cur = cur->next) {
		printf("%d ", cur->elem);
	}
}

//找到倒数第k个结点 
LinkNode* find_Kth_to_tail(LinkList *s, int k) {
	LinkNode* tmp = s->head;		//第一个指针 
	LinkNode* res = s->head;		//第二个指针 
	int i;
	for(i = 0; i < k - 1; ++i) {
		tmp = tmp->next;
	}
	while(tmp->next) {
		res = res->next;
		tmp = tmp->next; 
	}
	return res;
}

void reverse(LinkList *s) {
	LinkNode* oldh = s->head;
	LinkNode* tmp = s->head->next;
	while(tmp) {
		oldh->next = tmp->next;
		tmp->next = s->head;
		s->head = tmp;
		tmp = oldh->next;
	}
}

int main() {
	LinkList p;
	init(&p);
	frontPush(&p, 1);
	frontPush(&p, 2);
	frontPush(&p, 3);
	frontPush(&p, 4);
	frontPush(&p, 5);
	frontPush(&p, 6);
	frontPush(&p, 7);
	frontPush(&p, 8);
	frontPush(&p, 9);
	print(&p);
	putchar('\n');
	frontPop(&p);
	print(&p);
	putchar('\n');
	printf("%d ", find_Kth_to_tail(&p, 3)->elem);
	putchar('\n');
	reverse(&p);
	print(&p);
	destroy(&p);
}

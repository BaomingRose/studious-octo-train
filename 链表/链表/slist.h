#ifndef _SLIST_H_
#define _SLIST_H_
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// ��ͷ�����ѭ��������ɾ���ʵ�� 
typedef int SLTDataType; 
typedef struct SListNode {    
	SLTDataType _data;    
	struct SListNode* _next; 
}SListNode;

typedef struct SList { 
	SListNode* _head; 
}SList;

/*
�������
	for(cur = head; cur; cur = cur->next) {
		cur;
	}
	ǰ�����:
	for(cur = head; cur; pre = cur, cur = cur->next) {
		cur;
	}
	Ҳ��(���¸��ڵ������)
	for(cur = plist->_head; cur->_next; cur = cur->_next) {
		if(plist->_next->_data == x) {
			break;
		}
	}


	˫������
	for(cur = head->next; cur != head; cur = cur->next) {
		cur;
	}

*/


void SListInit(SList* plist); 
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x); 
void SListPushFront(SList* plist, SLTDataType x); 
void SListPopFront(SList* plist); 
SListNode* SListFind(SList* plist, SLTDataType x); 
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x); 
// ��pos��ǰ����в��� 
void SListInsertFront(SList* plist, SLTDataType x);
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist); 

#endif
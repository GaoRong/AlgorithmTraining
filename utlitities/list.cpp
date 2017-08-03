/********************************************************************************
** auth：  gaorong
** mail：  gaoronggood@163.com
** date：  2017-08-03 08:07:38
** desc：  about list
*********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int       m_nValue;
	ListNode* m_pNext;
	ListNode(int value=0, ListNode* next=NULL) : m_nValue(value), m_pNext(next) {}
};


ListNode* createListNode(int value)
{
	ListNode* pNode = new ListNode(value);
	return pNode;
}

void connectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == NULL)
	{
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	pCurrent->m_pNext = pNext;
}

void printListNode(ListNode* pNode)
{
	if (pNode == NULL)
	{
		printf("The node is NULL\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->m_nValue);
	}
}

void printList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}

	printf("\nPrintList ends.\n");
}

void destroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void addToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

void removeNode(ListNode** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;

		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != NULL)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

ListNode * reverseList(ListNode* pHead) {

	ListNode* pCur = pHead;
	ListNode* pPrev = NULL;
	ListNode* pReverHead = NULL;

	while (pCur != NULL) {
		ListNode* pNext = pCur->m_pNext;
		if (pNext == pReverHead) {
			pReverHead = pCur;
		}

		pCur->m_pNext = pPrev;
		pPrev = pCur;
		pCur = pNext;
	}
	return pReverHead;
}


ListNode* array2List(int* array, int length) {
	if (array == NULL || length == 0)
		return NULL;

	ListNode *pHead = createListNode(array[0]);
	ListNode *pTemp = pHead;

	for (int i = 1; i < length; i++) {
		pTemp->m_pNext = createListNode(array[i]);
		pTemp = pTemp->m_pNext;
	}
	return pHead;
}

/*
int main() {
	int a[] = { 1,2,3,4,5 };

	ListNode* head = array2List(a, 5);
	printList(head);

	head = reverseList(head);
	printList(head);
	
	//system("pause");
}
*/
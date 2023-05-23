#include "List.h"
#include <stdlib.h>
#include <stdio.h>

void InitList(list* l, int tmp)
{
	l->head = (element*)malloc(sizeof(element));
	l->head->next = NULL;
	l->head->data = tmp;
}

void PrintList(list* const l)
{
	if (IsEmptyList(l))
		return;

	for (element* i = l->head; i != NULL; i = i->next)
		printf_s("%d -> ", i->data);
	printf_s("\b\b\b   \n");
}

void PushList(list* l, int tmp, int index)
{
	if (IsEmptyList(l))
	{
		InitList(l, tmp);
		return;
	}

	element* e = (element*)malloc(sizeof(element));
	e->data = tmp;
	if (index == 0)
	{
		e->next = l->head;
		l->head = e;
		return;
	}

	int count = 0;
	for(element* i = l->head; ; i = i->next, count++)
		if (i->next == NULL)
		{
			i->next = e;
			e->next = NULL;
			return;
		}
		else if (count + 1 == index)
		{
			element* tmpElement = i->next;
			i->next = e;
			e->next = tmpElement;
			return;
		}
}

int PopList(list* l, int index)
{
	if (IsEmptyList(l))
		return INT_MAX;

	element* e;
	int tmpValue;
	if (index == 0 || l->head->next == NULL)
	{
		e = l->head->next;
		tmpValue = l->head->data;
		free(l->head);
		l->head = e;
		return tmpValue;
	}



	int count = 0;
	for (element* i = l->head; ; i = i->next, count++)
		if (i->next->next == NULL)
		{
			tmpValue = i->next->data;
			free(i->next);
			i->next = NULL;
			return tmpValue;
		}
		else if (count + 1 == index)
		{
			element* tmpElement = i->next->next;
			tmpValue = i->next->data;
			free(i->next);
			i->next = tmpElement;
			return tmpValue;
		}

}

int PeekList(list* const l, int index)
{
	if (IsEmptyList(l))
		return INT_MAX;
	
	int count = 0;
	for (element* i = l->head; ; i = i->next, count++)
		if (i->next == NULL)
			return i->data;
		else if (count  == index)
			return i->data;
		
}

bool SearchInList(list* const l, int tmp)
{
	if (IsEmptyList(l))
		return 0;

	for (element* i = l->head; i != NULL; i = i->next)
		if (i->data == tmp)
			return 1;

	return 0;
}

bool IsEmptyList(list* const l)
{
	return l->head == NULL;
}

void DestroyList(list* l)
{
	if (IsEmptyList(l))
		return;

	element* tmpList;
	while (l->head != NULL)
	{
		tmpList = l->head->next;
		free(l->head);
		l->head = tmpList;
	}
}

bool CheckOrederList(list* const l)
{
	if (IsEmptyList(l))
		return 0;

	for (element* i = l->head; i->next != NULL; i = i->next)
		if (i->data > i->next->data)
			return 0;

	return 1;
}

int CheckListNegativeNumber(list* const l)
{
	if (IsEmptyList(l))
		return -1;

	int index = 0;
	for (element* i = l->head; i != NULL; i = i->next, index++)
		if (i->data < 0)
			return index;

	return -1;
}

void DeleteListNegativeNumber(list* l)
{
	if (IsEmptyList(l))
		return;

	int tmp = 0;
	while ((tmp = CheckListNegativeNumber(l)) != -1)
	{
		PopList(l, tmp);
	}
}
#pragma once
#include <stdlib.h>

struct element
{
	int data = 0;
	element* next = NULL;
};

struct list
{
	element* head = NULL;
};

void InitList(list* l, int tmp);
void PrintList(list* const l);
void PushList(list* l, int tmp, int index);
int PopList(list* l, int index);
int PeekList(list* const l, int index);
bool SearchInList(list* const l, int tmp);
bool IsEmptyList(list* const l);
void DestroyList(list* l);

bool CheckOrederList(list* const l);
void DeleteListNegativeNumber(list* l);
int CheckListNegativeNumber(list* const l);
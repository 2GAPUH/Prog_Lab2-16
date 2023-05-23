#include <stdlib.h>
#include <stdio.h>
#include "List.h"


//Сформировать динамический список из элементов целого типа,
//проверить, является ли он упорядоченным набором чисел.
//Удалить из него отрицательные элементы.

void MainLoop()
{
	int userChoice = 0;
	int tmpValue = 0, tmpIndex = 0;
	bool loop = true;
	list array = {NULL};

	printf_s("1 - Add new element \n2 - Get with removing \n3 - Get without removing \n4 - Clear \n5 - Search in list \n6 - Task \n0 - Exit \n");

	while (loop)
	{
		printf_s("Your choice: ");
		scanf_s("%d", &userChoice);

		switch (userChoice)
		{
		case 1:
			printf_s("Enter your element: ");
			scanf_s("%d", &tmpValue);
			printf_s("Enter index: ");
			scanf_s("%d", &tmpIndex);
			PushList(&array, tmpValue, tmpIndex);
			break;

		case 2:
			printf_s("Enter index: ");
			scanf_s("%d", &tmpIndex);
			if ((tmpValue = PopList(&array, tmpIndex)) != INT_MAX)
				printf_s("Your element: %d\n", tmpValue);
			else
				printf_s("Your queue is empty.\n");
			break;

		case 3:
			printf_s("Enter index: ");
			scanf_s("%d", &tmpIndex);
			if ((tmpValue = PeekList(&array, tmpIndex)) != INT_MAX)
				printf_s("Your element: %d\n", tmpValue);
			else
				printf_s("Your stack is empty.\n");
			break;

		case 4:
			DestroyList(&array);
			break;

		case 5:
			printf_s("Enter your element: ");
			scanf_s("%d", &tmpValue);
			if (SearchInList(&array, tmpValue))
				printf_s("%d in list\n", tmpValue);
			else
				printf_s("%d mot in list", tmpValue);
			break;

		case 6:
			//Task
			break;

		case 0:
			loop = 0;
			break;

		default:

			break;
		}

		
	}

	
}


int main()
{
	MainLoop();

	return 0;
}
// use_q.c -- testing interface Queue
// Compile with queue.c

#include <stdio.h>
#include "queue.h"
int main(void)
{
	Queue line;
	Item temp;
	char ch;

	InitializeQueue(&line);
	puts("Testing Queue interface. Enter 'a' for add value,");
	puts("enter 'd' for delete value or enter 'q' for exit.");
	while ((ch = getchar()) != 'q')
	{
		if (ch != 'a' && ch != 'd')			// Ignore other input
			continue;
		if (ch == 'a')
		{
			printf("Integer for add: ");
			scanf("%d", &temp);
			if (!QueueIsFull(&line))
			{
				printf("Insert %d in queue\n", temp);
				EnQueue(temp, &line);
			}
			else
				puts("Queue is full!");
		}
		else
		{
			if (QueueIsEmpty(&line))
				puts("No elements for delete");
			else
			{
				DeQueue(&temp, &line);
				printf("Removing %d from queue\n", temp);
			}
		}
		printf("%d elements in queue\n", QueueItemCount(&line));
		puts("Enter 'a' for add, 'd' for delete or 'q' for exit");
	}
	EmptyTheQueue(&line);
	puts("Programm is executed");

	return 0;
}
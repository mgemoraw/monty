// #include "monty.h"
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/**
 * push - pushes value to the stack
 *
 * Return: returns nothing
 */
 
typedef struct Node
 {
	int value;
	struct Node *next;
 } Node;

typedef struct
 {
	Node *head;
	Node *tail;
	int size;
} Queue;


Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);


int main(void)
{
	Queue *queue = create_queue();

	// if (is_empty(queue)) printf("Queue is empty\n");

	enqueue(queue, 4);


	if (is_empty(queue))
		printf("Queue is  empty\n");
	else
		printf("Queue is not empty!\n");


	enqueue(queue, 5);
	enqueue(queue, 6);

	printf("Queue size: %d\n", size(queue));

	return (0);
}


/**
 * @brief Create a queue object
 * 
 * @return Queue* 
 */
Queue *create_queue()
{
	Queue *queue = malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;

	return queue;
}

int size(Queue *queue)
{
	return queue->size;
}

bool is_empty(Queue *queue)
{
	return (queue->size == 0);
}

int peek(Queue *queue, bool *status)
{
	if (is_empty(queue))
	{
		*status = false;
	}

	*status = true;
	return queue->head->value;
}

void enqueue(Queue *queue, int value)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;

	if (is_empty(queue))
	{
		queue->head = newNode;
		queue->tail = newNode;
		queue->size++;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
		queue->size++;
	}
}

int dequeue(Queue *queue, bool *status)
{
	if (is_empty(queue))
	{
		*status = false;
		return (0);
	}

	*status = true;
	
	int value = queue->head->value;
	
	Node *oldHead = queue->head; 

	if (queue->size == 1)
	{
		queue->head = NULL;
		queue->tail == NULL;
	}
	else
	{
		queue->head = queue->head->next;
	}
	
	free(oldHead);
	queue->size--;

	return (value);
}

void destroy_queue(Queue *queue)
{
	Node *currentNode = queue->head;

	while(currentNode != NULL)
	{
		Node *temp = currentNode;
		currentNode = currentNode->next;
		free(temp);
	}

	free(queue);
}

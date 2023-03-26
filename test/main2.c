
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
  int data;
  struct Node *next;
} node;
node *top = NULL;
void push (int x)
{
  node *newnode = malloc(sizeof(node));
  newnode->data = x;
  newnode->next = top;
  top = newnode;
}
void display()
{
  node *tmp;
  tmp = top;
  while(tmp != NULL)
    {
      printf("%d\n",tmp->data);
      tmp = tmp->next;
    }
}
void pop()
{
  node *tmp;
  tmp = top;
  top = top->next;
  free(tmp);
}
void swap()
{
  int tmp;
  tmp = top->data;
  top->data = top->next->data;
  top->next->data = tmp;
}
void add()
{
  node *tmp;
  top->next->data = top->data + top->next->data;
  tmp = top;
  top = top->next;
  free(tmp);
}
int main(int ac ,char *av[])
{
  char *cmd = NULL;
  char *args[1024];
  char *token;
  size_t len = 0;
  int i = 0;
  FILE *fp;
  fp = fopen(av[1],"r");
  while(getline(&cmd,&len,fp) != EOF)
    {
      token = strtok(cmd," \n");
      while(token != NULL)
        {
          args[i++] = token;
          token = strtok(NULL," \n");
        }
      if(strcmp(args[0],"push") == 0)
      {
         push(atoi(args[1]));
      }
      if(strcmp(args[0],"pall") == 0)
      {
        display();
      }
        if(strcmp(args[0],"pop") == 0)
      {
        pop();
      }
       if(strcmp(args[0],"swap") == 0)
      {
        swap();
      }
       if(strcmp(args[0],"add") == 0)
      {
        add();
      }
      args[i] = NULL;
      i = 0;
    }
  fclose(fp);
  free(cmd);
  return(0);
}

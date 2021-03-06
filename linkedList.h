#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINK_STRUCT {
  char *data; // Can take either a name or a number.
  struct NODE_STRUCT * next; //pointer to next node.
} link;


link *create_link(char *data, link *next);

link *add_link(link *beginning, char *data);

void print_data(link *beginning);

void cleanUpLinks(link *l);


#endif
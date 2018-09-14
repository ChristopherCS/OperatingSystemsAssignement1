#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

typedef struct LINK_STRUCT {
  char data[512]; // Can take either a name or a number. Made it much larger than necessary... space is cheap.
  struct NODE_STRUCT * next;
} link;


link *create_link(char *data, link *new_link);




#endif
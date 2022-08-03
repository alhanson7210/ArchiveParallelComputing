struct node {
	union Data;
	struct node * next;
	enum dataType type;
}

struct node *list = malloc(sizeof(struct node));

union Data *elem = list -> data;

elem -> f;

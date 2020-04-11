#ifndef ITEM_H_
#define ITEM_H_

typedef int item;

#define NULLITEM 0

int eq(item x, item y);
item new_item(int i);
void input_item(item *x);
void output_item(item x);

#endif /* ITEM_H_ */

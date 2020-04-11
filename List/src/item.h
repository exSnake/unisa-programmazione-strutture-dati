#include "punto.h"

#ifndef ITEM_H_
#define ITEM_H_

typedef punto item;

#define NULLITEM 0

int eq(item x, item y);
item new_item(float x, float y);
void input_item(item *x);
void output_item(item x);

#endif /* ITEM_H_ */

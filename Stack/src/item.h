#ifndef ITEM_H_
#define ITEM_H_

#include "int.h"
typedef myint item;

#define NULLITEM 0

int eq(item x, item y);
item input_item();
void output_item(item x);

#endif /* ITEM_H_ */

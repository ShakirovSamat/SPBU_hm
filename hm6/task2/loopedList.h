typedef int Error;

typedef struct LoopedList LoopedList;

LoopedList *create();

Error append(LoopedList *list, int value);

Error delete(LoopedList *list, int value);

int getLen(LoopedList *list);

Error printList(LoopedList *loopedList);
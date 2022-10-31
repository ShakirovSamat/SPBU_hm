typedef int Error;

typedef struct LoopedList LoopedList;

LoopedList *create();

Error append(LoopedList *list, int value);

int get(LoopedList *list, int index);

Error delete(LoopedList *list, int value);

int getLen(LoopedList *list);

Error printList(LoopedList *loopedList);
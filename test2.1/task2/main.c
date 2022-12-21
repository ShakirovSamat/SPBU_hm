#include <stddef.h>
#include "aggregate.h"

int main()
{
    Aggregate *aggregate1 = createAggregate();
    if (aggregate1 == NULL)
    {
        return -1;
    }
    Aggregate *aggregate2 = createAggregate();
    if (aggregate2 == NULL)
    {
        return -1;
    }

    insert(aggregate1, 6);
    insert(aggregate1, 1);
    insert(aggregate1, 76);
    insert(aggregate1, 4);
    insert(aggregate1, 45);

    insert(aggregate2, 7);
    insert(aggregate2, 21);
    insert(aggregate2, 23);
    insert(aggregate2, 6);

    print(aggregate1);
    print(aggregate2);

    merge(aggregate1, aggregate2);
    print(aggregate1);
    deleteAggregate(aggregate1);
    return 0;
}
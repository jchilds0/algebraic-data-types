#include <stdio.h>
#include <stdbool.h>
#include "types.h"

typedef struct {
    int x;
} Some;

typedef void None;

DEFINE_UNION(Option)
ADD_TYPE_UNION(Option, None)
ADD_TYPE_UNION(Option, Some)

int main(void) {
    Some some = {1};
    Option x = Option_Some(&some);
    Option y = Option_None(NULL);

    MATCHES(x, None) {
        printf("none x\n");
    }
    MATCHES_DATA(x, Some, some_x) {
        printf("some x %d\n", some_x->x);
    }

    MATCHES(y, None) {
        printf("none y\n");
    }
    MATCHES_DATA(y, Some, some_y) {
        printf("some y %d\n", some_y->x);
    }

    return 0;
}

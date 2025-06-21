#include <stdio.h>
#include <stdbool.h>
#include "types.h"

typedef struct {
    int x;
} Some;

typedef void None;

NEW_SUM_TYPE(Option)
SUM_ADD_TYPE(Option, None)
SUM_ADD_TYPE(Option, Some)

int main(void) {
    Some some = {1};
    Option x = Option_Some(&some);
    Option y = Option_None(NULL);

    MATCHES(x, None) {
        printf("none x\n");
    }
    MATCHES(x, Some, some_x) {
        printf("some x %d\n", some_x->x);
    }

    MATCHES(y, None) {
        printf("none y\n");
    }
    MATCHES(y, Some, some_y) {
        printf("some y %d\n", some_y->x);
    }

    return 0;
}


#ifndef TYPES_H
#define TYPES_H

#define NEW_SUM_TYPE(sum_type) \
    typedef struct { \
        int ident; \
        void *data; \
    } sum_type;

#define SUM_ADD_TYPE(sum_type, typed) \
    static const int typed ## _ID = __COUNTER__; \
    static int type_identifier_ ## typed (sum_type t) { return typed ## _ID; } \
    static sum_type sum_type ## _ ## typed (typed *t) { sum_type u_t = {typed ## _ID, t}; return u_t; }

#define GET_MACRO(_1, _2, _3, name, ...) name
#define MATCHES(...) GET_MACRO(__VA_ARGS__, MATCHES_DATA, MATCHES_EMPTY, NULL) (__VA_ARGS__)

#define MATCHES_EMPTY(obj, typed) \
    if ((obj).ident == type_identifier_ ## typed ((obj))) 

#define MATCHES_DATA(obj, typed, name) \
    typed *name = (typed *)(obj).data; \
    if ((obj).ident == type_identifier_ ## typed ((obj))) 

#endif  // TYPES_H

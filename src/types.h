
#ifndef TYPES_H
#define TYPES_H

#define DEFINE_UNION(union_type) typedef struct {int ident; void *data;} union_type;

#define ADD_TYPE_UNION(union_type, typed) \
    static const int typed ## _ID = __COUNTER__; \
    static int type_identifier_ ## typed (union_type t) { return typed ## _ID; } \
    static union_type union_type ## _ ## typed (typed *t) { union_type u_t = {typed ## _ID, t}; return u_t; }

#define MATCHES(obj, typed) if ((obj).ident == type_identifier_ ## typed ((obj))) 
#define MATCHES_DATA(obj, typed, name) typed *name = (typed *)(obj).data; if ((obj).ident == type_identifier_ ## typed ((obj))) 

#endif  // TYPES_H

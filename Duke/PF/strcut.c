#include <stdio.h>

/* 
    define a tag(rect_t) only, tag can only be used with the word struct as a prefix.
*/
struct rect_t {
    int left;
    int bottom;
    int right;
    int top;
}

/*
    define a tag(rect_tag) and then define its type alias(rect_t)
*/
struct rect_tag {
    int left;
    int bottom;
    int right;
    int top;
};
typedef struct rect_tag rect_t;

typedef struct rect_tag {
    int left;
    int bottom;
    int right;
    int top;
} rect_t;

/*
    struct can not refer to itself.
*/
typedef struct {
    int left;
    int bottom;
    int right;
    int top;
} rect_t;
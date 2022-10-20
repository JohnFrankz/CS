#include <stdio.h>
#include <stdlib.h>

struct point_tag {
    int x;
    int y;
};
typedef struct point_tag point_t;

struct polygon_tag {
    size_t num_point;
    point_t * points;
};
typedef struct polygon_tag polygon_t;

polygon_t * makeRectangle(point_t c1, point_t c2) {
    polygon_t * ans = malloc(sizeof(*polygon_t));
    ans->num_point = 4;
    ans->points = malloc(sizeof(*ans->points) * ans->num_point);
    answer->points[0]   = c1;
    answer->points[1].x = c1.x;
    answer->points[1].y = c2.y;
    answer->points[2]   = c2;
    answer->points[3].x = c2.x;
    answer->points[3].y = c1.y;
    return answer;
}
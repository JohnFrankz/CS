#include <stdio.h>

typedef struct rect_tag {
    float left;
    float bottom;
    float right;
    float top;
} rect_t;

float max(float num1, float num2) {
    if (num1 > num2) {
        return num1;
    }
    return num2;
}

float min(float num1, float num2) {
    if (num1 < num2) {
        return num1;
    }
    return num2;
}

rect_t interesection(rect_t r1, rect_t r2) {
    // Make a rectangle (called ans) with
    rect_t ans;
    // ans's left: maximum of r1's left and r2's left 
    ans.left = max(r1.left, r2.left);
    // ans's bottom: maximum of r1's bottom and r2's bottom
    ans.bottom = max(r1.bottom, r2.bottom);
    // ans's right: minimum of r1's right and r2's right
    ans.right = min(r1.right, r2.right)
    // ans's top: minimum of r1's top and r2's top
    ans.top = min(r1.top, r2.top);
    return ans;
}
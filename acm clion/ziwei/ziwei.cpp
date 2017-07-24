//
// Created by 孙启龙 on 2017/4/30.
//

#include<stdio.h>

typedef  char *byte_point;

void show_byte(byte_point start, int len)
{
    for(int i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_byte((byte_point)&x, sizeof(int));
}

void show_float(float x)
{
    show_byte((byte_point)&x, sizeof(float));
}

void show_void(void *x)
{
    show_byte((byte_point)x, sizeof(void *));
}

int main (void)
{
    show_int(12345);
    //show_float(1234567.0f);
    long long a = 12345;
    show_void(&a);
    return 0;
}
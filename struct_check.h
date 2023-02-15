#ifndef __STRUCT_SIZE_CHECK_H__
#define __STRUCT_SIZE_CHECK_H__

#include "stddef.h"

// 检测结构体的大小是否等于特定值
#define SIZE_OF_TYPE_EQUAL_TO(type, size) \
    extern int size_of_##type##_equal_to_##size[1 / (!!(sizeof(type) == (size)))]

// 检测结构体的大小是否不等于特定值
#define SIZE_OF_TYPE_UNEQUAL_TO(type, size) \
    extern int size_of_##type##_unequal_to_##size[1 / (!!(sizeof(type) != (size)))]

// 检测结构体的大小是否不大于特定值
#define SIZE_OF_TYPE_NOT_LARGER_THAN(type, size) \
    extern int size_of_##type##_not_larger_than_##size[1 / (!!(sizeof(type) <= (size)))]

// 检测结构体的大小是否不小于特定值
#define SIZE_OF_TYPE_NOT_SMALLER_THAN(type, size) \
    extern int size_of_##type##_not_smaller_than_##size[1 / (!!(sizeof(type) >= (size)))]

// 检测结构体的大小是否小于特定值
#define SIZE_OF_TYPE_SMALLER_THAN(type, size) \
    extern int size_of_##type##_smaller_than_##size[1 / (!!(sizeof(type) < (size)))]

// 检测结构体的大小是否大于特定值
#define SIZE_OF_TYPE_LARGER_THAN(type, size) \
    extern int size_of_##type##_larger_than_##size[1 / (!!(sizeof(type) > (size)))]

// 检测结构体的大小是否为特定值的整数倍
#define SIZE_OF_TYPE_IS_MULTIPLE_OF(type, size) \
    extern int size_of_##type##_is_multiple_of_##size[1 / (!(sizeof(type) % (size)))]

// 检测结构体成员偏移是否等于特定值
#define OFFSET_OF_MEMBER_IN_TYPE_EQUAL_TO(type, member, value) \
    extern int offset_of_##member##_in_##type##_is_error       \
        [1 / !!(offsetof(type, member) == (value))]

#endif /*__STRUCT_SIZE_CHECK_H__*/

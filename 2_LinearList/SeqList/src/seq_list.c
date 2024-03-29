﻿/*!
 * @file seq_list.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序表源文件
 * @version 1.0.0
 * @date 2022-07-10
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include <stdlib.h>
#include <stdio.h>
#include "seq_list.h"


/*!
 * @brief **顺序表初始化**
 * @param seq_list **顺序表**(指针)
 * @return **是否成功**
 * @note
 * 顺序表初始化
 * ----------
 * ----------
 * - 分配elements数组内存 \n
 * &emsp; **if** 内存分配失败 : \n
 * &emsp;&emsp; 返回NON_ALLOCATED \n
 */
status_t SeqListInit(seq_list_t* seq_list) {

    // 分配elements数组内存
    seq_list->elements = (ELEM_TYPE*)malloc(LIST_INIT_CAPACITY * sizeof(ELEM_TYPE));
    if (!seq_list->elements) {
        return NON_ALLOCATED;
    }

    // 设置length和capacity
    seq_list->length = 0;                       // 空表长度为0
    seq_list->capacity = LIST_INIT_CAPACITY;    // 初始存储容量

    return OK;
}


/*!
 * @brief **顺序表插入**
 * @param seq_list **顺序表**(指针)
 * @param pos **插入位置(插入到该位置结点的前一位置)**
 * @param elem **待插入元素**
 * @return **执行结果**
 * @note
 * 顺序表插入
 * ------------
 * ------------
 * **注**: 本顺序表实现, 索引从1开始, 区别于数组的从0开始\n
 * - 插入位置合法性判断 \n
 * &emsp; **if** 插入位置 < 1 或者 插入位置 > 长度 + 1 : \n
 * &emsp;&emsp; 返回OVERFLOW \n
 * - 满容量处理 \n
 * &emsp; **if** 线性表的容量已满(不扩容无法插入) : \n
 * &emsp;&emsp; 使用增量LIST_INCREMENT计算新的容量, 并分配新的elements数组内存 \n
 * &emsp;&emsp; **if** 内存分配失败 : \n
 * &emsp;&emsp;&emsp; 返回NON_ALLOCATED \n
 * &emsp;&emsp; 顺序表elements指针指向新数组 \n
 * &emsp;&emsp; 顺序表capacity增加容量数值 \n
 * - 插入位置(包含)后面的所有结点向后移动一位 \n
 * - 插入元素 \n
 * &emsp; 插入位置赋值 \n
 * &emsp; 表长+1 \n
 */
status_t SeqListInsert(seq_list_t* seq_list, int pos, ELEM_TYPE elem) {

    // 插入位置合法性判断
    if (pos < 1 || pos > seq_list->length + 1) {
        return OVERFLOW;
    }

    // 满容量处理
    if (seq_list->length >= seq_list->capacity) {
        // 使用增量LIST_INCREMENT计算新的容量, 并分配新的elements数组内存
        unsigned int new_capacity = (seq_list->capacity + LIST_INCREMENT) * sizeof(ELEM_TYPE);
        ELEM_TYPE* new_elements = (ELEM_TYPE*)realloc(seq_list->elements, new_capacity);
        if (!new_elements) {
            return NON_ALLOCATED;
        }

        seq_list->elements = new_elements;      // 顺序表elements指针指向新数组
        seq_list->capacity += LIST_INCREMENT;   // 顺序表capacity增加容量数值
    }

    // 插入位置(包含)后面的所有结点向后移动一位
    ELEM_TYPE* insert_pos_elem = seq_list->elements + pos - 1;
    for (ELEM_TYPE* cur = seq_list->elements + seq_list->length - 1; cur >= insert_pos_elem; cur--) {
        *(cur + 1) = *cur;
    }

    *insert_pos_elem = elem;  // 插入elem
    seq_list->length++;       // 表长增1

    return OK;
}


/*!
 * @brief **顺序表删除元素**
 * @param seq_list **顺序表**(指针)
 * @param pos **被删除结点所在位置**
 * @param elem **被删除结点的保存变量**
 * @return **执行结果**
 * @note
 * 顺序表删除元素
 * ------------
 * ------------
 * - 删除节点位置正确性检查 \n
 * &emsp;**if** pos < 1 或者 pos > 线性表长度 : \n
 * &emsp;&emsp; 返回OVERFLOW \n
 * - 被删除结点的值赋给保存变量 \n
 * - 被删除结点后面的所有结点向前移动补位 \n
 * &emsp; **for loop** 被删除节点后侧所有所有结点 : \n
 * &emsp;&emsp; 当前结点值赋给前一节点 \n
 * - 表长减1 \n
 */
status_t SeqListDelete(seq_list_t* seq_list, int pos, ELEM_TYPE* elem) {
    if (pos < 1 || pos > seq_list->length) {
        return OVERFLOW;
    }

    // 待删除节点值赋给保存变量
    ELEM_TYPE* delete_pos_elem = &(seq_list->elements[pos - 1]);
    *elem = *delete_pos_elem;

    ELEM_TYPE* last_elem = seq_list->elements + seq_list->length - 1;   // 表尾元素指针
    for (ELEM_TYPE* cur = delete_pos_elem + 1; cur <= last_elem; cur++) {
        // 当前结点值赋给前一结点
        *(cur - 1) = *cur;
    }

    // 表长减1
    seq_list->length--;

    return OK;
}


/*!
 * @brief **顺序表查找**
 * @param seq_list **顺序表**(指针)
 * @param elem **元素值**
 * @param compare **比较函数**
 * @return **元素位置**
 * @note
 * 顺序表查找
 * ------------
 * ------------
 * 如果没有该元素, 则返回0, 否则返回所在位置(首元素从1开始) \n
 * - 初始化pos和遍历指针cur \n
 * &emsp; pos初始化为1(首结点位置) \n
 * &emsp; cur指向elements数组首元素 \n
 * - 遍历线性表查找
 * &emsp; **while** 未遍历完线性表and未找到对应结点 : \n
 * &emsp;&emsp; pos加1 \n
 * &emsp;&emsp; cur指向后一元素 \n
 * - 返回位置 \n
 * &emsp; 如果找到位置, 返回位置 \n
 * &emsp; 如果没有找到位置, 返回0 \n
 */
int SeqListLocate(seq_list_t* seq_list, ELEM_TYPE elem, int (*compare)(ELEM_TYPE, ELEM_TYPE)) {

    // 初始化pos和遍历指针cur
    int pos = 1;                            // pos为第1个元素的位置
    ELEM_TYPE* cur = seq_list->elements;    // cur指向第1个元素的存储位置

    // 遍历线性表查找
    while (pos <= seq_list->length && (*compare)(*cur, elem) != 0) {
        pos++;
        cur++;
    }

    // 返回位置
    if (pos <= seq_list->length) {
        return pos;
    }

    return 0;
}


/*!
 * @brief **顺序表的合并**
 * @param list_a **顺序表a**
 * @param list_b **顺序表b**
 * @param merged_list **合并后的顺序表**
 * @return **执行结果**
 * @note
 *
 * 顺序表的合并
 * ----------
 * ----------
 * - 初始化两个顺序表的表头指针/表尾指针 \n
 * &emsp; list_a_cur指向表a的表头, list_b_cur指向表b的表头 \n
 * &emsp; list_a_last指向表a的表尾, list_b_last指向表b的表尾 \n
 * - 合并后的表设置属性分配内存 \n
 * &emsp; 设置长度/容量 \n
 * &emsp; 分配内存 \n
 * &emsp; **if** 内存分配失败 : \n
 * &emsp;&emsp; 返回NON_ALLOCATED \n
 * - 执行合并 \n
 * &emsp; **while** 任意一个表未合并完 : \n
 * &emsp;&emsp; **if** 表a当前元素 <= 表b当前元素 : \n
 * &emsp;&emsp;&emsp; 表a当前元素(*list_a_cur)插入合并表表尾 \n
 * &emsp;&emsp;&emsp; list_a_cur指向后面1位 \n
 * &emsp;&emsp; **else** (表a当前元素 > 表b当前元素) : \n
 * &emsp;&emsp;&emsp; 表b当前元素(*list_b_cur)插入合并表表尾 \n
 * &emsp;&emsp;&emsp; list_b_cur指向后面1位 \n
 * &emsp;&emsp; merged_list_cur指向后面1位(合并表当前元素向后移动) \n
 * - 未合并完的表补表尾 \n
 * &emsp; 表a剩余元素加到合并表尾部(如果表a有剩余) \n
 * &emsp; 表b剩余元素加到合并表尾部(如果表b有剩余) \n
 */
status_t SeqListMerge(seq_list_t* list_a, seq_list_t* list_b, seq_list_t* merged_list) {
    ELEM_TYPE* list_a_cur = list_a->elements;   // list_a_cur指针 -> 顺序表a的elements数组首地址
    ELEM_TYPE* list_b_cur = list_b->elements;   // list_b_cur指针 -> 顺序表b的elements数组首地址
    ELEM_TYPE* list_a_last = list_a->elements + list_a->length - 1; // last_a_last指针 -> 顺序表a的elements数组尾地址
    ELEM_TYPE* list_b_last = list_b->elements + list_b->length - 1; // last_b_last指针 -> 顺序表b的elements数组尾地址

    // 合并后的表设置属性分配内存
    merged_list->length = list_a->length + list_b->length;  // 长度
    merged_list->capacity = list_a->capacity + list_b->capacity;        // 容量
    merged_list->elements = (ELEM_TYPE*)malloc(merged_list->capacity * sizeof(ELEM_TYPE));  // elements数组分配内存
    if (!merged_list->elements) {
        return NON_ALLOCATED;   // 分配失败
    }

    // 执行合并
    ELEM_TYPE* merged_list_cur = merged_list->elements; // merged_list_cur指针 -> 合并后的顺序表的elements数组首地址

    while (list_a_cur <= list_a_last && list_b_cur <=list_b_last) {
        // list_a_cur和list_b_cur指向的两个元素, 选择较小的进入merged_list, 对应的cur指针向后移一位, merged_list_cur向后移一位
        if (*list_a_cur <= *list_b_cur) {
            *merged_list_cur = *list_a_cur;
            list_a_cur++;
        } else {
            *merged_list_cur = *list_b_cur;
            list_b_cur++;
        }
        merged_list_cur++;
    }

    // list_a剩余元素加到merged_list尾部(如果list_a有剩余)
    while (list_a_cur <= list_a_last) {
        *merged_list_cur = *list_a_cur;
        merged_list_cur++;
        list_a_cur++;
    }

    // list_b剩余元素加到merged_list尾部(如果list_b有剩余)
    while (list_b_cur <= list_b_last) {
        *merged_list_cur = *list_b_cur;
        merged_list_cur++;
        list_b_cur++;
    }

    return OK;
}


/*!
 * @brief **顺序表打印**
 * @param seq_list 顺序表(指针)
 * @note
 * 顺序表打印
 * ---------
 * ---------
 * 循环打印顺序表各元素
 */
void SeqListPrint(seq_list_t* seq_list) {
    for (int i = 0; i < seq_list->length; i++) {
        printf("%d ", seq_list->elements[i]);
    }
}

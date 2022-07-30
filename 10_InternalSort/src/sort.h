﻿/*!
 * @file sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 内部排序头文件
 * @version 1.0.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_SORT_H
#define CYBER_DASH_SORT_H


#define FALSE   0   //!< 逻辑非
#define TRUE    1   //!< 逻辑是

#define NUM_0_ASCII_CODE 48
#define NUM_1_ASCII_CODE 49

#define MAX_DIGIT_NUMBER 8                  // 关键字项数的最大值
#define RADIX_10 10                         // 10进制基数

#define MAX_SIZE 20     // 表的最大长度

typedef int BUCKETS[RADIX_10];
typedef char KEY_TYPE;


typedef int key_t;    //定义关键字类型为整数类型
typedef char info_t;  //其他数据类型


/*!
 * 顺序表结点
 */
typedef struct {
    key_t key;      //!< 关键字项
    info_t info;    //!< 其他数据项
} seq_list_node_t;


/*!
 * 顺序表
 */
typedef struct {
    seq_list_node_t elements[MAX_SIZE + 1]; //!< elements[0]闲置或用作哨兵单元
    int length;         //!< 顺序表长度
} seq_list_t;


/*
typedef struct
{
    seq_list_node_t rc;         //记录项
    int next;           //指针项
}SLNode;                //表结点类型

typedef struct
{
    SLNode elements[MAX_SIZE];     //0号单元为表头结点
    int length;         //链表当前长度
}SLinkListType;         //静态链表类型
 */



/*!
 * 静态链表结点结构体
 */
typedef struct {
    KEY_TYPE keys[MAX_DIGIT_NUMBER];    //关键字
    info_t info;                        //其他数据项
    int next;
} static_linked_list_node_t;


/*!
 * 基数排序的静态链表
 */
typedef struct {
    static_linked_list_node_t elements[MAX_SIZE];    //!< 元素的静态链表, elements[0]为头结点(不保存元素)
    int digit_number;                                //!< 基数关键字个数
    int length;                                      //!< 静态链表长度
} radix_static_linked_list_t;


void InsertSort(seq_list_t* seq_list);

void BinaryInsertSort(seq_list_t* seq_list);

// void TInsertSort(SLinkListType* L);

void ShellInsert(seq_list_t* seq_list, int gap);

void ShellSort(seq_list_t* seq_list, int gaps[], int gap_count);

void SelectSort(seq_list_t* L);

void BubbleSort(seq_list_t* seq_list);

void QuickSort(seq_list_t* seq_list);

void HeapSort(seq_list_t* heap);

void MergeSort(seq_list_t* L);

void RadixSort(radix_static_linked_list_t* static_linked_list);

#endif // CYBER_DASH_SORT_H

﻿/*!
 * @file seq_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序表
 * @version 1.0.0
 * @date 2022-07-10
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */
#ifndef CYBER_DASH_SEQ_LIST_H
#define CYBER_DASH_SEQ_LIST_H


#define LIST_INIT_SIZE  100
#define LIST_INCREMENT  10
#define ELEM_TYPE       int

typedef enum {
    OK,             //!< 成功/正确
    NON_ALLOCATED,  //!< 内存分配失败
    NON_EXISTENT,   //!< 不存在
    ERROR           //!< 错误
} Status;

typedef struct {
    ELEM_TYPE* elements;
    int length;
    int size;
} seq_list_t;


Status SeqListInit(seq_list_t* seq_list);

Status SeqListInsert(seq_list_t* seq_list, int pos, ELEM_TYPE elem);

Status SeqListDelete(seq_list_t* seq_list, int pos, ELEM_TYPE* elem);

int SeqListLocate(seq_list_t* seq_list, ELEM_TYPE elem, int (*compare)(ELEM_TYPE, ELEM_TYPE));

Status SeqListMerge(seq_list_t* list_a, seq_list_t* list_b, seq_list_t* merged_list);

void SeqListPrint(seq_list_t* seq_list);


#endif // CYBER_DASH_SEQ_LIST_H

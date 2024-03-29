﻿/*!
 * @file stack.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 栈头文件
 * @version 1.0.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "common.h"
#include "binary_tree_node.h"


#ifndef CYBER_DASH_TREE_STACK_H
#define CYBER_DASH_TREE_STACK_H

#define STACK_INIT_CAPACITY 100           //!< 存储空间初始分配量
#define STACK_INCREMENT  10               //!< 存储空间分配增量
#define STACK_ELEM binary_tree_node_t*    //!< 栈元素类型(二叉树结点指针)

/*!
 * @brief 顺序栈
 */
typedef struct {
    STACK_ELEM* elements;   //!< 栈元素数组
    STACK_ELEM* top;        //!< 栈顶指针
    int capacity;           //!< 容量
} seq_stack_t;


// 顺序栈初始化
status_t SeqStackInit(seq_stack_t* seq_stack);

// 顺序栈是否为空
int SeqStackIsEmpty(seq_stack_t seq_stack);

// 顺序栈获取栈顶元素
status_t SeqStackGetTop(seq_stack_t seq_stack, STACK_ELEM* elem);

// 顺序栈入栈
status_t SeqStackPush(seq_stack_t* seq_stack, binary_tree_node_t* elem);

// 顺序栈出栈
status_t SeqStackPop(seq_stack_t* seq_stack, STACK_ELEM* elem);


#endif // CYBER_DASH_TREE_STACK_H

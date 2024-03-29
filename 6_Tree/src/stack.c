﻿/*!
 * @file stack.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 栈源文件
 * @version 1.0.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "stack.h"
#include "stdlib.h"


/*!
 * @brief **顺序栈初始化**
 * @param seq_stack 顺序栈(指针)
 * @return 执行结果
 * @note
 * 顺序栈初始化
 * ----------
 * ----------
 * ###1 顺序栈数组分配内存###
 * &emsp; **if** 如果malloc失败 :\n
 * &emsp;&emsp; 返回NON_ALLOCATED\n
 * ###2 top和容量初始化###
 * &emsp; top指向elements首地址, capacity(容量)设置为STACK_INIT_CAPACITY\n
 */
status_t SeqStackInit(seq_stack_t* seq_stack) {

    // ----- 1 顺序栈数组分配内存 -----
    seq_stack->elements = (STACK_ELEM*)malloc(STACK_INIT_CAPACITY * sizeof(STACK_ELEM));
    if (!seq_stack->elements) { // if 如果malloc失败
        return NON_ALLOCATED;   // 返回NON_ALLOCATED
    }

    // ----- 2 top和容量初始化 -----
    // top指向elements首地址, capacity(容量)设置为STACK_INIT_CAPACITY
    seq_stack->top = seq_stack->elements;
    seq_stack->capacity = STACK_INIT_CAPACITY;

    return OK;
}


/*!
 * @brief **顺序栈获取栈顶元素**
 * @param seq_stack 顺序栈
 * @param elem 栈顶元素保存变量
 * @return 执行结果
 * @note
 * 顺序栈获取栈顶元素
 * ---------------
 * ---------------
 */
status_t SeqStackGetTop(seq_stack_t seq_stack, STACK_ELEM* elem) {

    // ----- 1 空栈判断 -----
    if (SeqStackIsEmpty(seq_stack)){    // if 空栈
        return NON_EXISTENT;    // 返回NON_EXISTENT
    }

    // ----- 2 赋值 -----
    *elem = *(seq_stack.top - 1);   // top指针前一位的值, 赋给*elem

    return OK;
}


/*!
 * @brief **顺序栈入栈**
 * @param seq_stack 顺序栈(指针)
 * @param elem 入栈元素
 * @return 执行结果
 * @note
 * 顺序栈入栈
 * --------
 * --------
 * ###1 判断是否栈满(以追加存储空间) ###
 * &emsp; **if** top - elements >= capacity :\n
 * - **I**&nbsp;&nbsp; 调用realloc重新分配elements数组内存\n
 *  + 新的elements数组内存长度为capacity + STACK_INCREMENT\n
 *  + 调用realloc\n
 * &emsp;&emsp;&emsp;&emsp; **if** 内存分配失败 : \n
 * &emsp;&emsp;&emsp;&emsp;&emsp; 返回NON_ALLOCATED\n
 * - **II**&nbsp; 调整top指向和容量\n
 * ###2 执行入栈 ###
 * - **I**&nbsp;&nbsp; elem赋值给top所指向地址\n
 * - **II**&nbsp; top向后移一位\n
 */
status_t SeqStackPush(seq_stack_t* seq_stack, binary_tree_node_t* elem) {
    // ----- 1 判断是否栈满(以追加存储空间) -----
    if (seq_stack->top - seq_stack->elements >= seq_stack->capacity) {  // if top - elements >= capacity :
        // I 调用realloc重新分配elements数组内存

        // 新的elements数组内存长度为capacity + STACK_INCREMENT, 调用realloc
        seq_stack->elements = (STACK_ELEM*)realloc(seq_stack->elements,
                                                   (seq_stack->capacity + STACK_INCREMENT) * sizeof(STACK_ELEM));

        if (!seq_stack->elements) { // if 内存分配失败
            return NON_ALLOCATED;   // 返回NON_ALLOCATED
        }

        // II 调整top指向和容量
        seq_stack->top = seq_stack->elements + seq_stack->capacity; // 调整top指向
        seq_stack->capacity += STACK_INCREMENT;  // 调整扩容数值
    }

    // ----- 2 执行入栈 -----
    *seq_stack->top = elem; // elem赋值给top所指向地址
    seq_stack->top++;       // top向后移一位

    return OK;
}


/*!
 * @brief **顺序栈出栈**
 * @param seq_stack 顺序栈(指针)
 * @param elem 出栈元素保存变量(指针)
 * @return 执行结果
 * @note
 * 顺序栈出栈
 * --------
 * --------
 * ###1 空栈判断###
 * &emsp; **if** top指向elements数组首地址 :\n
 * &emsp;&emsp; 返回NON_EXISTENT\n
 * ###2 执行出栈###
 * - **I**&nbsp;&nbsp; top指向前一位\n
 * - **II**&nbsp; top指向元素赋给*elem\n
 */
status_t SeqStackPop(seq_stack_t* seq_stack, STACK_ELEM* elem) {
    // ----- 1 空栈判断 -----
    if (seq_stack->top == seq_stack->elements) {    // if top指向elements数组首地址
        return NON_EXISTENT;    // 返回NON_EXISTENT
    }

    // ----- 2 执行出栈 -----
    seq_stack->top--;           // top指向前一位
    *elem = *seq_stack->top;    // top指向元素赋给*elem

    return OK;
}



/*!
 * @brief **顺序栈是否为空**
 * @param seq_stack 顺序栈
 * @return 是否为空
 * @note
 * 顺序栈是否为空
 * ------------
 * ------------
 * &emsp; 返回top == elements的结果\n
 */
int SeqStackIsEmpty(seq_stack_t seq_stack) {
    // 返回top == elements的结果
    if (seq_stack.top == seq_stack.elements) {
        return TRUE;
    }

    return FALSE;
}

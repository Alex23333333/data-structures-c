﻿//
// Created by cyberdash@163.com on 2021/12/30.
//

#include "stack.h"
#include "stdlib.h"
#include "stdio.h"


Status StackInit(seq_stack_t *S) {
    // 构造一个空栈S
    S->elements = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->elements) exit(OVERFLOW);   // 存储分配失败
    S->top = S->elements;
    S->size = STACK_INIT_SIZE;

    return OK;
}


Status StackGetTop(seq_stack_t S, SElemType *e) {
    // 若栈不空, 则用e返回S的栈顶元素, 并返回OK; 否则返回ERROR
    if (S.top == S.elements) return ERROR;
    *e = *(S.top - 1);
    return OK;
} // StackGetTop


Status StackPush(seq_stack_t* S, binary_tree_node_t *e) {
    // 插入元素e为新的栈顶元素
    if (S->top - S->elements >= S->size) { // 栈满, 追加存储空间
        S->elements = (SElemType*)realloc(S->elements, (S->size + STACKINCREMENT) * sizeof(SElemType));
        if (!S->elements) exit(OVERFLOW);   // 存储分配失败

        S->top = S->elements + S->size;
        S->size += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
} // StackPush


Status Pop(seq_stack_t *S, SElemType *e) {
    // 若栈不空, 则删除S的栈顶元素, 用e返回其值, 并返回OK; 否则返回ERROR
    if (S->top == S->elements) return ERROR;
    *e = *--S->top;
    return OK;
} // Pop


// 销毁栈S, S不再存在
Status DestroyStack(seq_stack_t *S) {
    free(S->elements);
    free(S);

    return OK;
}


// 把S置为空栈
Status ClearStack(seq_stack_t *S) {
    SElemType e;
    while (StackEmpty(*S) != OK) {
        Pop(S, &e);
    }

    return OK;
}


// 若栈S为空栈, 则返回TRUE, 否则返回FALSE
int StackEmpty(seq_stack_t S) {
    if (S.top == S.elements) {
        return TRUE;
    }

    return FALSE;
}


// 返回S的元素个数, 即栈的长度
int StackLength(seq_stack_t S) {
    return S.top - S.elements;
}

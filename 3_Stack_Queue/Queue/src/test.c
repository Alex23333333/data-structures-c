﻿/*!
 * @file test.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列测试源文件
 * @version 1.0.0
 * @date 2022-07-10
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include <stdio.h>
#include "test.h"


/*!
 * @brief **测试循环队列入队/出队**
 * @note
 * 测试循环队列入队/出队
 * ------------------
 * ------------------
 */
void TestCircularQueueEnQueueAndDeQueue() {
    printf("\n");
    printf("------------------------- CyberDash -------------------------\n");
    printf("                Test SeqQueue EnQueue/DeQueue                \n");
    printf("                      测试顺序队列入队/出队                     \n\n\n");

    circular_queue_t seq_queue;
    status_t status = CircularQueueInit(&seq_queue);

    QUEUE_ELEM elements[8] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    for (int i = 0; i < sizeof(elements) / sizeof(int); i++) {
        printf("入队: %d\n", elements[i]);
        CircularQueueEnQueue(&seq_queue, elements[i]);
    }

    CircularQueuePrint(&seq_queue);

    printf("\n出队5次后:\n\n");

    QUEUE_ELEM top_elem;
    for (int i = 0; i < 5; i++) {
        CircularQueueDeQueue(&seq_queue, &top_elem);
    }

    CircularQueuePrint(&seq_queue);

    printf("-------------------- 抖音: cyberdash_yuan --------------------\n");
}


/*!
 * @brief **测试链式队列入队/出队**
 * @note
 * 测试链式队列入队/出队
 * ------------------
 * ------------------
 */
void TestLinkQueueEnQueueAndDeQueue() {
    printf("\n");
    printf("------------------------- CyberDash -------------------------\n");
    printf("                Test linked_queue_t EnQueue/DeQueue               \n");
    printf("                      测试链式队列入队/出队                     \n\n\n");

    linked_queue_t link_queue;
    status_t status = LinkedQueueInit(&link_queue);

    QUEUE_ELEM elements[8] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    for (int i = 0; i < sizeof(elements) / sizeof(int); i++) {
        printf("入队: %d\n", elements[i]);
        LinkedQueueEnQueue(&link_queue, elements[i]);
    }

    LinkedQueuePrint(&link_queue);

    printf("\n出队5次后:\n\n");

    QUEUE_ELEM top_elem;
    for (int i = 0; i < 5; i++) {
        LinkedQueueDeQueue(&link_queue, &top_elem);
    }

    LinkedQueuePrint(&link_queue);

    printf("-------------------- 抖音: cyberdash_yuan --------------------\n");
}

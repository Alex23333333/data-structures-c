﻿/*!
 * @file circular_queue.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief  循环队列源文件
 * @version 1.0.0
 * @date 2022-07-10
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "circular_queue.h"
#include "stdlib.h"
#include "string.h"


/*!
 * @brief <h1>循环队列初始化</h1>
 * @param circular_queue **循环队列**(指针)
 * @return **执行结果**
 * @note
 */
status_t CircularQueueInit(circular_queue_t* circular_queue) {
    /// ###1 循环队列数组分配内存###
    /// &emsp; **if** 如果malloc失败 :\n
    /// &emsp;&emsp; 返回NON_ALLOCATED
    circular_queue->elements = (QUEUE_ELEM*)malloc(MAX_SIZE * sizeof(QUEUE_ELEM));
    if (!circular_queue->elements) {
        return NON_ALLOCATED;
    }

    memset(circular_queue->elements, 0, MAX_SIZE * sizeof(QUEUE_ELEM));

    /// ###2 队头队尾初始化###
    /// &emsp; front和rear都为0\n
    circular_queue->front = 0;
    circular_queue->rear = 0;

    return OK;
}


/*!
 * @brief <h1>循环队列长度</h1>
 * @param circular_queue **循环队列**
 * @return **长度**
 * @note
 */
int CircularQueueGetLength(circular_queue_t circular_queue) {
    /// &emsp; 长度等于(rear - front + MAX_SIZE) % MAX_SIZE\n
    return (circular_queue.rear - circular_queue.front + MAX_SIZE) % MAX_SIZE;
}


/*!
 * @brief <h1>循环队列入队</h1>
 * @param circular_queue **循环队列**(指针)
 * @param elem **入队元素**
 * @return **执行结果**
 * @note
 */
status_t CircularQueueEnQueue(circular_queue_t* circular_queue, QUEUE_ELEM elem) {

    /// ###1 判断队列是否满###
    /// &emsp; **if** 队列满 :\n
    /// &emsp;&emsp; 返回OVERFLOW\n
    if ((circular_queue->rear + 1) % MAX_SIZE == circular_queue->front) {
        return OVERFLOW;
    }

    /// ###2 元素elem插入到队尾###
    /// - **I**&nbsp;&nbsp; elements数组rear索引位置赋值
    /// - **II**&nbsp; rear调整数值
    circular_queue->elements[circular_queue->rear] = elem;
    circular_queue->rear = (circular_queue->rear + 1) % MAX_SIZE;

    return OK;
}


status_t CircularQueueDeQueue(circular_queue_t* circular_queue, QUEUE_ELEM* elem) {
    // 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK;
    // 否则返回ERROR
    if (circular_queue->front == circular_queue->rear) {
        return NON_EXISTENT;
    }

    *elem = circular_queue->elements[circular_queue->front];
    circular_queue->front = (circular_queue->front + 1) % MAX_SIZE;

    return OK;
}


/*!
 * <h1>顺序表转换成字符串</h1>
 * @param circular_queue **顺序表**(指针)
 * @param str **字符串**
 * @param str_len_limit **字符串长度限制**
 * @return 执行结果
 * @note
 */
status_t CircularQueueToString(circular_queue_t* circular_queue, char* str, int str_len_limit) {

    if (circular_queue->front == circular_queue->rear) {
        return OK;
    }

    int loop_stop_condition;
    if (circular_queue->front < circular_queue->rear) {
        loop_stop_condition = circular_queue->rear;
    } else {
        loop_stop_condition = circular_queue->rear + MAX_SIZE;
    }

    if (loop_stop_condition - circular_queue->front > str_len_limit) {
        return OVERFLOW;
    }

    int queue_str_idx = 0;
    for (int i = circular_queue->front; i < loop_stop_condition; i++) {
        str[queue_str_idx] = circular_queue->elements[i % MAX_SIZE];
        queue_str_idx++;
    }

    return OK;
}

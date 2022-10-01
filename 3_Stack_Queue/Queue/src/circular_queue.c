/*!
 * @file circular_queue.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 循环队列源文件
 * @version 1.0.0
 * @date 2022-07-10
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */


#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.h"


/*!
 * @brief **循环队列初始化**
 * @param circular_queue 循环队列(指针)
 * @return 执行结果
 * 循环队列初始化
 * ------------
 * ------------
 *
 * ------------
 * ###1 循环队列数组分配内存###
 * &emsp; **if** 如果malloc失败 :\n
 * &emsp;&emsp; 返回NON_ALLOCATED\n
 * ###2 队头队尾初始化###
 * &emsp; front初始化为0\n
 * &emsp; rear初始化为0\n
 */
status_t CircularQueueInit(circular_queue_t* circular_queue) {

    // ----- 1 循环队列数组分配内存 -----

    circular_queue->elements = (QUEUE_ELEM*)malloc(MAX_SIZE * sizeof(QUEUE_ELEM));
    if (!circular_queue->elements) {    // if 如果malloc失败
        return NON_ALLOCATED;   // 返回NON_ALLOCATED
    }

    // ----- 2 队头队尾初始化 -----
    circular_queue->front = 0;  // front初始化为0
    circular_queue->rear = 0;   // rear初始化为0

    return OK;
}


/*!
 * @brief **循环队列长度**
 * @param circular_queue 循环队列
 * @return 长度
 * @note
 * 循环队列长度
 * ----------
 * ----------
 *
 * ----------
 * 长度等于(rear - front + MAX_SIZE) % MAX_SIZE\n
 */
int CircularQueueLength(circular_queue_t circular_queue) {
    // 长度等于(rear - front + MAX_SIZE) % MAX_SIZE
    return (circular_queue.rear - circular_queue.front + MAX_SIZE) % MAX_SIZE;
}


/*!
 * @brief **循环队列入队**
 * @param circular_queue 循环队列(指针)
 * @param elem 入队元素
 * @return 执行结果
 * @note
 * 循环队列入队
 * ----------
 * ----------
 *
 * ----------
 * ### 1 判断队列是否满 ###
 * &emsp; **if** 队列满 :\n
 * &emsp;&emsp; 返回OVERFLOW\n
 * ###2 元素elem插入到队尾###
 * - **I**&nbsp;&nbsp; elements数组rear索引位置赋值\n
 * - **II**&nbsp; rear调整数值\n
 */
status_t CircularQueueEnQueue(circular_queue_t* circular_queue, QUEUE_ELEM elem) {

    // ----- 1 判断队列是否满 -----
    if ((circular_queue->rear + 1) % MAX_SIZE == circular_queue->front) {   // if 队列满
        return OVERFLOW;    // 返回OVERFLOW
    }

    // ----- 2 元素elem插入到队尾 -----
    circular_queue->elements[circular_queue->rear] = elem;          // elements数组rear索引位置赋值
    circular_queue->rear = (circular_queue->rear + 1) % MAX_SIZE;   // rear调整数值

    return OK;
}


/*!
 * @brief **循环队列出队**
 * @param circular_queue 循环队列(指针)
 * @param elem 出队元素保存变量(指针)
 * @return 执行结果
 * @note
 * 循环队列出队
 * ----------
 * ----------
 *
 * ----------
 * ###1 空队判断###
 * &emsp; **if** front等于rear : \n
 * &emsp;&emsp; 空队, 返回NON_EXISTENT\n
 * ###2 出队###
 * - **I**&nbsp;&nbsp; elements数组front索引位置元素赋给*elem
 * - **II**&nbsp; front调整数值
 */
status_t CircularQueueDeQueue(circular_queue_t* circular_queue, QUEUE_ELEM* elem) {
    // ----- 1 空队判断 -----
    if (circular_queue->front == circular_queue->rear) {    // if front等于rear
        return ERROR;   // 空队, 返回NON_EXISTENT
    }

    // ----- 2 出队 -----
    *elem = circular_queue->elements[circular_queue->front];    // elements数组front索引位置元素赋给*elem
    circular_queue->front = (circular_queue->front + 1) % MAX_SIZE; // front调整数值

    return OK;
}


/*!
 * @brief **打印循环队列**
 * @param circular_queue 循环队列(指针)
 * @note
 * 打印循环队列
 * ----------
 * ----------
 *
 * ----------
 * &emsp; 从队头front向队尾rear打印队列元素, 相邻元素以空格分隔
 */
void CircularQueuePrint(circular_queue_t* circular_queue) {
    printf("从队头向队尾打印元素(队头 ... 队尾):\n");

    int cur = circular_queue->front;
    while (cur < circular_queue->rear) {
        printf("%d ", circular_queue->elements[cur]);
        cur++;
    }

    printf("\n");
}

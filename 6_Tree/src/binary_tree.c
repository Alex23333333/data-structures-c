﻿/*!
 * @file binary_tree.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉树源文件
 * @version 1.0.0
 * @date 2022-07-10
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"


/*!
 * @brief **使用前序遍历字符串(NULL结点使用空格)创建二叉树(递归)**
 * @param node 二叉树结点(结点二级指针)
 * @param pre_order_str 前序遍历字符串(NULL结点使用空格)
 * @param traverse_index 遍历索引(用于遍历字符)
 * @param pre_order_str_len 前序遍历字符串长度(NULL结点使用空格)
 * @return 是否成功
 * @note
 * 使用前序遍历字符串(NULL结点使用空格)创建二叉树(递归)
 * ---------------------------------------------
 * ---------------------------------------------
 * ###1 检查是否终止递归###
 * &emsp; **if** 遍历索引 >= 字符串长度:\n
 * &emsp;&emsp; 越界(即之后的字符串不参与create), **终止递归**\n
 * ###2 遍历位置字符处理###
 * - **I**&nbsp;&nbsp; 遍历索引所指向的字符, 赋给chr\n
 * - **II**&nbsp; 遍历索引向后挪1位(**指向下一字符**)\n
 * - **III** NULL结点处理\n
 * &emsp; **if** chr为空格:\n
 * &emsp;&emsp; 则当前构造结点为NULL\n
 * &emsp;&emsp; 返回OK, **终止递归**
 * ###3 构造新结点###
 * - **I**&nbsp;&nbsp; 分配结点内存\n
 * &emsp; **if** 内存分配失败:\n
 * &emsp;&emsp; 返回错误码NON_ALLOCATED, **终止递归**\n
 * - **II**&nbsp; 节点数据项赋值
 * ###4 对孩子结点进行递归###
 * - **I**&nbsp;&nbsp; 对左孩子结点执行递归
 * - **II**&nbsp; 对右孩子结点执行递归
 */
status_t BinaryTreeCreateByPreOrderStringRecursive(binary_tree_node_t** node,
                                                   char* pre_order_str,
                                                   int* traverse_index,
                                                   size_t pre_order_str_len)
{
    // ----- 1 检查是否终止递归 -----
    if (*traverse_index >= (int)pre_order_str_len) {    // if 遍历索引 >= 字符串长度
        return OK;  // 越界(即之后的字符串不参与create), (终止递归)
    }

    // ----- 2 遍历位置字符处理 -----
    char chr = pre_order_str[*traverse_index];  // 遍历索引所指向的字符, 赋给chr
    *traverse_index = *traverse_index + 1;      // 遍历索引向后挪1位(**指向下一字符**)

    if (chr == ' ') {   // if chr为空格
        *node = NULL;       // 则当前构造结点为NULL
        return OK;          // 返回OK, (终止递归)
    }

    // ----- 3 构造新结点 -----
    if (!(*node = (binary_tree_node_t*)malloc(sizeof(binary_tree_node_t)))) {   // if 内存分配失败
        return NON_ALLOCATED;   // 返回错误码NON_ALLOCATED, (终止递归)
    }

    (*node)->data = chr;    // 节点数据项赋值

    // ----- 4 对孩子结点进行递归 -----
    // 对左孩子结点执行递归
    status_t status = BinaryTreeCreateByPreOrderStringRecursive(&(*node)->left_child,
                                                                pre_order_str,
                                                                traverse_index,
                                                                pre_order_str_len);
    if (status != OK) { // 如果错误, 返回错误码
        return status;
    }

    // 对右孩子结点执行递归
    status = BinaryTreeCreateByPreOrderStringRecursive(&(*node)->right_child,
                                                       pre_order_str,
                                                       traverse_index,
                                                       pre_order_str_len);

    return status;
}


/*!
 * @brief **二叉树前序遍历(递归)**
 * @param node 二叉树结点(指针)
 * @param Visit 结点元素访问函数
 * @return 执行结果
 * @note
 * 二叉树前序遍历(递归)
 * -----------------
 * -----------------
 * ###1 NULL结点处理 ###
 * &emsp; 返回OK, 正确情况下, **终止递归**
 * ###2 访问结点 ###
 * &emsp; **if** 如果访问失败 :\n
 * &emsp;&emsp; 返回错误码, 错误情况下, **终止递归**
 * ###3 递归###
 * - **I**&nbsp;&nbsp; 对node左孩子结点进行递归
 * - **II**&nbsp; 对node右孩子结点进行递归
 */
status_t BinaryTreePreOrderTraverseRecursive(binary_tree_node_t* node, status_t (*Visit)(BINARY_TREE_NODE_DATA)) {

    // ----- 1 NULL结点处理 ------
    if (node == NULL) {
        return OK;  // 返回OK, 正确情况下, (终止递归)
    }

    // ----- 2 访问结点 -----
    status_t status = Visit(node->data);
    if (status != OK) { // if 如果访问失败
        return status;  // 返回错误码, 错误情况下, (终止递归)
    }

    // ----- 3 递归 -----
    status = BinaryTreePreOrderTraverseRecursive(node->left_child, Visit);  // 对node左孩子结点进行递归
    if (status != OK) { // 如果遍历失败, 返回错误码
        return status;
    }

    status = BinaryTreePreOrderTraverseRecursive(node->right_child, Visit); // 对node右孩子结点进行递归

    return status;
}


/*!
 * @brief **二叉树中序遍历**
 * @param node 二叉树结点(指针)
 * @param Visit 结点元素访问函数
 * @return 执行结果
 * @note
 * 二叉树中序遍历
 * ------------
 * ------------
 */
status_t BinaryTreeInOrderTraverse(binary_tree_node_t* node, status_t (*Visit)(BINARY_TREE_NODE_DATA)) {

    seq_stack_t stack;
    SeqStackInit(&stack);

    binary_tree_node_t* cur = node;
    while (cur || !SeqStackIsEmpty(stack)) {
        if (cur) {
            SeqStackPush(&stack, cur);
            cur = cur->left_child;
        } else {
            SeqStackPop(&stack, &cur);
            if (Visit(cur->data) != OK) {
                return ERROR;
            }
            cur = cur->right_child;
        }
    }

    return OK;
}


/*!
 * @brief **二叉树中序遍历2**
 * @param node 二叉树结点(指针)
 * @param Visit 结点访问函数
 * @return 执行结果
 * @note
 * 二叉树中序遍历2
 * -------------
 * -------------
 * ###1 初始化栈###
 * &emsp; 根结点入栈\n
 * ###2 遍历过程###
 * &emsp; **while** 栈不为空 :\n
 * - **I**&nbsp;&nbsp; 遍历至最左子孙结点的过程\n
 *  + 栈顶出栈, 赋给遍历节点cur\n
 *  + 从cur的左孩子结点开始, 一直向子孙的左孩子结点遍历\n
 *  + 过程中的所有结点入栈\n
 * ```
 *                  *  <-- 开始遍历前的栈顶, cur结点
 *                 /
 *                *                 -
 *               /                  |
 *             ...             这些结点依次入栈
 *             /                    |
 * 遍历至 ->  *                     _
 *             \
 *              *
 * ```
 * - **II**&nbsp; 栈空条件处理\n
 * &emsp; **if** 如果栈空 :\n
 * &emsp;&emsp; 中序遍历结束
 * - **III** 栈顶出栈并访问\n
 *  + 栈顶出栈, 赋给节点cur\n
 *  + 访问节点cur\n
 * ```
 *                  *
 *                 /
 *                *
 *               /
 *             ...
 *             /
 *            *  --> cur
 *             \
 *              *
 * ```
 * - **III** 栈顶出栈并访问\n
 *  + 栈顶出栈, 赋给节点cur\n
 *  + 访问节点cur\n
 * ```
 *                  *
 *                 /
 *                *
 *               /
 *             ...
 *             /
 *            *  --> cur
 *             \
 *              *
 * ```
 */
status_t BinaryTreeInOrderTraverse2(binary_tree_node_t* node, status_t (*Visit)(BINARY_TREE_NODE_DATA)) {

    // ----- 1 初始化栈 -----
    seq_stack_t stack;
    SeqStackInit(&stack);

    SeqStackPush(&stack, node); // 根结点入栈

    // ----- 2 遍历过程 -----
    while (!SeqStackIsEmpty(stack)) {   // while 栈不为空

        binary_tree_node_t* cur;    // 遍历结点

        // - I 遍历至最左子孙结点的过程
        //  + 栈顶出栈, 赋给遍历节点cur
        //  + 从cur的左孩子结点开始, 一直向子孙的左孩子结点遍历
        //  + 过程中的所有结点入栈
        //                  *  <-- 开始遍历前的栈顶, cur结点
        //                 /
        //                *                 -
        //               /                  |
        //             ...             这些结点依次入栈
        //             /                    |
        // 遍历至 ->  *                     _
        //             \
        //              *
        while (SeqStackGetTop(stack, &cur) == OK && cur) {
            SeqStackPush(&stack, cur->left_child);
        }

        SeqStackPop(&stack, &cur); // 栈顶的NULL出栈, 使栈顶是树结点

        // - II 栈空条件处理
        if (SeqStackIsEmpty(stack)) {   // if 如果栈空
            break;  // 中序遍历结束
        }

        // - III 栈顶出栈并访问
        //                  *
        //                 /
        //                *
        //               /
        //             ...
        //             /
        //            *  --> cur
        //             \
        //              *
        SeqStackPop(&stack, &cur);  //  栈顶出栈, 赋给节点cur\n

        // 访问节点cur
        if (Visit(cur->data) != OK) {
            return ERROR;
        }

        // - IV 结点cur的右孩子结点入栈
        //                  *
        //                 /
        //                *
        //               /
        //             ...
        //             /
        //            *
        //             \
        //              *  <- 入栈
        SeqStackPush(&stack, cur->right_child);
    }

    return OK;
}


/*!
 * @brief **二叉树后序遍历(递归)**
 * @param node 二叉树结点(指针)
 * @param Visit 结点访问函数
 * @return 执行结果
 * @note
 * 二叉树后序遍历(递归)
 * -----------------
 * -----------------
 * ###1 NULL结点处理###
 * &emsp; **if** 遍历至NULL结点 :\n
 * &emsp;&emsp; 返回OK, **递归终止**\n
 * ###2 对左右孩子结点递归###
 * - **I**&nbsp;&nbsp; 左孩子结点进行递归\n
 * - **II**&nbsp; 右孩子结点进行递归\n
 *###3 访问结点###
 */
status_t BinaryTreePostOrderTraverseRecursive(binary_tree_node_t* node, status_t (*Visit)(BINARY_TREE_NODE_DATA)) {

    // ----- 1 NULL结点处理 -----
    if (node == NULL) { // if 遍历至NULL结点
        return OK;  // 返回OK, (递归终止)
    }

    // ----- 2 对左右孩子结点递归 -----
    status_t status = BinaryTreePostOrderTraverseRecursive(node->left_child, Visit);    // 左孩子结点进行递归
    if (status != OK) { // 如果遍历失败, 返回错误码
        return status;
    }

    status = BinaryTreePostOrderTraverseRecursive(node->right_child, Visit);    // 右孩子结点进行递归
    if (status != OK) { // 如果遍历失败, 返回错误码
        return status;
    }

    // ----- 3 访问结点 -----
    status = Visit(node->data);

    return status;
}


/*!
 * @brief **二叉树后序遍历**
 * @note
 * 二叉树后序遍历
 * ------------
 * ------------
 * 见 [CyberDash团队 数据结构(C++模板实现)](https://gitee.com/cyberdash/data-structure-cpp/blob/master/Tree/BinaryTree/src/binary_tree.h)
 */
status_t BinaryTreePostOrderTraverse(binary_tree_node_t* binary_tree, status_t (*Visit)(BINARY_TREE_NODE_DATA)) {
    // todo: 见note, 有兴趣者参照C++代码自行实现:-)
    return OK;
}


/*!
 * @brief **层序遍历**
 * @param binary_tree 二叉树(结点指针)
 * @param Visit 访问函数
 * @return 执行结果
 * @note
 * 层序遍历
 * -------
 * -------
 * ###1 初始化队列###
 * &emsp; 节点入队\n
 * ###2 使用队列进行遍历###
 * &emsp; **while** 队列不为空 :\n
 * - **I**&nbsp;&nbsp; 队头出队\n
 * - **II**&nbsp; 访问队头\n
 * - **III** 孩子结点入队\n
 *  + **if** 左孩子不为NULL: 左孩子结点入队\n
 *  + **if** 右孩子不为NULL: 右孩子结点入队\n
 */
status_t BinaryTreeLevelOrderTraverse(binary_tree_node_t* binary_tree, status_t (*Visit)(BINARY_TREE_NODE_DATA)) {

    // ----- 1 初始化队列 -----
    circular_queue_t queue;
    CircularQueueInit(&queue);

    // 节点入队
    CircularQueueEnQueue(&queue, binary_tree);

    // ----- 2 使用队列进行遍历 -----
    while (CircularQueueGetLength(queue)) { // while 队列不为空
        binary_tree_node_t* cur = NULL;
        CircularQueueDeQueue(&queue, &cur); // 队头出队

        Visit(cur->data);   // 访问队头

        if (cur->left_child) {  // if 左孩子不为NULL
            CircularQueueEnQueue(&queue, cur->left_child);  // 左孩子结点入队
        }

        if (cur->right_child) { // if 右孩子不为NULL
            CircularQueueEnQueue(&queue, cur->right_child); // 右孩子结点入队
        }
    }

    return OK;
}

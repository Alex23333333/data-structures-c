﻿/*!
 * @file main.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief main源文件
 * @version 1.0.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "test.h"


/*!
 * @brief **main函数**
 * @note
 * main函数
 * -------
 * -------
 * - 测试二叉树前序遍历\n
 * - 测试二叉树中序遍历\n
 * - 测试二叉树中序遍历2\n
 * - 测试二叉树后序遍历\n
 * - 测试二叉树层序遍历\n
 * - 测试哈夫曼(Huffman)编码\n
 */
int main() {

    // - 测试二叉树前序遍历
    TestBinaryTreePreOrderTraverse();

    // - 测试二叉树中序遍历
    TestBinaryTreeInOrderTraverse();

    // - 测试二叉树中序遍历2
    TestBinaryTreeInOrderTraverse2();

    // - 测试二叉树后序遍历
    TestBinaryTreePostOrderTraverse();

    // - 测试二叉树层序遍历
    TestBinaryTreeLevelOrderTraverse();

    // - 测试哈夫曼(Huffman)编码
    TestHuffmanCoding();

    return 0;
}

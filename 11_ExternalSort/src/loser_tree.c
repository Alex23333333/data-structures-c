/*!
 * @file loser_tree_t.c
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 外部排序败者树源文件
 * @version 1.0.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */
#include "loser_tree.h"
#include "limits.h"
#include "stdio.h"


void swap(int* item1, int* item2) {
    int tmp = *item1;
    *item1 = *item2;
    *item2 = tmp;
}


void Adjust(loser_tree_t loser_tree, leaves_t leaves, int index) {
    //沿从叶子结点b[s]到根结点ls[0]的路径调整败者树
    for (int parent = (index + SIZE) / 2; parent > 0; parent = parent / 2) {
		if(leaves[index].key > leaves[loser_tree[parent]].key) {		//s指示新的胜利者（小为胜，向上比较，大为败，留在双亲结点）
            swap(&index, &loser_tree[parent]);
		}
	}

    loser_tree[0] = index;							//顶部结点为最小值
}

/*!
 * 构造败者树
 * @param loser_tree
 * @param leaves
 * @note
 * 败者树数组构成非叶子结点, 其中loserTree[0]为根节点, 用来保存最小值
 */
void CreateLoserTree(loser_tree_t loser_tree, leaves_t leaves) {
    leaves[SIZE].key = INT_MIN;                // 设INT_MIN为关键字可能的最小值
    for (int i = 0; i < SIZE; ++i) {
        loser_tree[i] = SIZE;                    // 设置loserTree中"败者"的初值
    }
    for (int i = SIZE - 1; i >= 0; --i) {
        Adjust(loser_tree, leaves, i);  // 依次从leafArr[SIZE - 1], leaves[SIZE - 2] ... leaves[0]出发调整败者
    }
}


void K_Merge(loser_tree_t loser_tree, leaves_t leaves, int* array[], int limit_length) {
    // 利用败者树ls将编号从0到k - 1的k个输入归并段中的记录归并到输出归并段

    // 分别从k个输入归并段读入该段当前第一个记录的关键字到外结点
    for (int i = 0; i < SIZE; ++i) {
        leaves[i].key = array[i][0];
    }

    CreateLoserTree(loser_tree, leaves);
    int everyQueueWorkingIdx[SIZE] = { 1, 1, 1, 1, 1 };

    while (leaves[loser_tree[0]].key != INT_MAX) {
        int queue_idx = loser_tree[0];
        printf("%d  ", leaves[loser_tree[0]].key);

        if (everyQueueWorkingIdx[queue_idx] < limit_length) { // 如果queueIdx归并段, 还有元素, 赋值
            leaves[queue_idx].key = array[queue_idx][everyQueueWorkingIdx[queue_idx]];
            everyQueueWorkingIdx[queue_idx]++;
        } else { // 如果已经全部执行完
            leaves[queue_idx].key = INT_MAX;
        }
        Adjust(loser_tree, leaves, queue_idx);
    }

    printf("\n");
}
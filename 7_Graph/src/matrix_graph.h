﻿//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2022/3/24.
//

#include "graph.h"


Status CreateGraph(matrix_graph_t* graph);

// 使用弧信息数组构造图
Status CreateGraphByArcCellArr(matrix_graph_t* graph, edge_t* arcCellArr, int vertex_count, int arc_count);

// 构造有向图
Status CreateDG(matrix_graph_t *G);

// 构造有向网
Status CreateDN(matrix_graph_t *G);

// 构造无向图
Status CreateUDG(matrix_graph_t *G);

// 结点(索引)v在图G中的第一个(索引)邻接节点
int FirstAdjVertex(matrix_graph_t *graph, int vertex_idx);

// 结点(索引)v在图G中的, 结点(索引)w之外第一个(索引)邻接节点
int NextAdjVertex(matrix_graph_t *graph, int vertex_idx, int first_adj_vertex_idx);

// 构造无向网
Status CreateUDNByArcCellArr(matrix_graph_t *graph, edge_t *edge_arr, int edge_cnt, VERTEX_TYPE *vertex_arr, int vertex_cnt);

Status DestroyGraph(matrix_graph_t *G);

Status LocateVertex(matrix_graph_t graph, VERTEX_TYPE vertex, int *idx);

// 获取结点的第一条弧(边)
edge_t* GetFirstArc(matrix_graph_t *G, int vertexIdx);

// 获取结点的基于某条弧(边)的下一条弧(边)
edge_t* GetNextArc(matrix_graph_t *graph, int vertex_idx, edge_t* edge);

// 打印图的邻接矩阵
Status PrintGraphMatrix(matrix_graph_t* graph, WEIGHT_TYPE valueType);

// Status PutVex(matrix_graph_t *G, VERTEX_TYPE v, );
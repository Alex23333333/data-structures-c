<div align="center">
    <img src="https://i.imgtg.com/2022/06/24/7Vdot.webp">
</div>

# 👀这份代码是干什么的

实现计算机专业数据结构📒通用教材中的示例代码，使其从伪代码转变为可执行的程序，方便初学者运行和调试。

# 🤖 为什么要使用这份代码?

学习数据结构是比较痛苦的，因为这门课的内容都比较抽象，但是通过使用我们的代码，将抽象的内容实现出来，并可以运行出正确的结果，相信会对你理解数据结构和算法提供帮助。❤️

我们的代码是经过cyberdash团队严格审核的，每一行代码都仔细推敲。通过学习本项目，你可以获得📖

- 优雅的编程规范，参照谷歌的代码风格，让你养成优秀的编程习惯
- 标准的变量命名方式，每一个变量都经过深思熟虑，告别命名焦虑
- 完全开源，可直接使用的数据结构
- 简单的程序结构，小白也能看懂
- 清晰的目录结构，每一种数据结构都是单独项目
- 配套的课程更新中...


# 🚀从此刻开始

## 💾 下载本项目

如何使用git? 你可以参考这个: [git使用方法](/docs/git.md)

```bash
git clone https://gitee.com/cyberdash/data-structure-c.git
```

## cmake 编译

```bash
cmake -G "Makefiles"
```

# 🌵 项目结构

```sh
.
├── 2_LinearList //线性表
│   ├── LinkedList
│   │   ├── CMakeLists.txt
│   │   └── src
│   │       ├── linked_list.c
│   │       ├── linked_list.h
│   │       ├── main.c
│   │       ├── test.c
│   │       └── test.h
│   └── SeqList
│       ├── CMakeLists.txt
│       └── src
│           ├── main.c
│           ├── seq_list.c
│           ├── seq_list.h
│           ├── test.c
│           └── test.h
├── 3_Stack_Queue //栈和队列
│   ├── Queue
│   │   ├── CMakeLists.txt
│   │   └── src
│   │       ├── bank_simulation.c
│   │       ├── bank_simulation.h
│   │       ├── link_queue.c
│   │       ├── link_queue.h
│   │       ├── main.c
│   │       ├── sq_queue.c
│   │       ├── sq_queue.h
│   │       ├── test.c
│   │       ├── test.h
│   │       └── type.h
│   └── Stack
│       ├── CMakeLists.txt
│       └── src
│           ├── main.c
│           ├── seq_stack.c
│           ├── seq_stack.h
│           ├── test.c
│           └── test.h
├── 4_String //串
│   └── src
│       ├── cyberdash_string.c
│       ├── cyberdash_string.h
│       ├── main.c
│       ├── test.c
│       └── test.h
├── 5_ArrayAndGList //数组和广义表
│   ├── Array
│   │   ├── CMakeLists.txt
│   │   └── src
│   │       ├── array.c
│   │       ├── array.h
│   │       ├── common.h
│   │       ├── main.c
│   │       ├── sparseMatrix.c
│   │       ├── sparseMatrix.h
│   │       ├── test.c
│   │       └── test.h
│   └── GList
│       ├── CMakeLists.txt
│       └── src
│           ├── gList.c
│           ├── gList.h
│           ├── main.c
│           ├── sq_queue.c
│           ├── sq_queue.h
│           ├── test.c
│           ├── test.h
│           └── type.h
├── 6_Tree //二叉树
│   ├── CMakeLists.txt
│   └── src
│       ├── BinaryTree.c
│       ├── BinaryTree.h
│       ├── BinaryTreeNode.h
│       ├── HuffmanTree.c
│       ├── HuffmanTree.h                
│       ├── main.c
│       ├── stack.c
│       ├── stack.h
│       ├── test.c
│       ├── test.h
│       └── Tree.h
├── 7_Graph //图
│   ├── CMakeLists.txtcxx,cxx,x vxvvc,,l;;;;;;;cvcx
│   ├── cyber_dash_doxygen_config
│   └── src
│       ├── adjacency_list_graph.c
│       ├── adjacency_list_graph.h
│       ├── algorithm.c
│       ├── algorithm.h
│       ├── disjoint_set.c
│       ├── disjoinvc,,xzzxmmmmzmmmmet.h
│       ├── graph.h
│       ├── heap.c
│       ├── heap.h
│       ├── main.c
│       ├── matrix_graph.c
│       ├── matrix_graph.h
│       ├── queue.c
│       ├── queue.h
│       ├── test.c
│       └── test.h
├── 9_Search //查找
│   ├── CMakeLists.txt
│   └── src
│       ├── main.c
│       ├── search.h
│       ├── static_search_table.c
│       ├── static_search_table.h
│       ├── test.c
│       └── test.h
├── 10_InternalSort //内部排序
│   ├── CMakeLists.txt
│   └── src
│       ├── main.c
│       ├── sort.c
│       ├── sort.h
│       ├── test.c
│       └── test.h
├── 11_ExternalSort //外部排序
│   ├── CMakeLists.txt
│   └── src
│       ├── LoserTree.c
│       ├── LoserTree.h
│       ├── main.c
│       ├── test.c
│       └── test.h
├── LICENSE
└── README.md
```

# 👨‍👩‍👦‍👦 关于我们

我们是拥有十多年开发经验的开发工程师, 长期就职于各传统与互联网大厂.
目前在做计算机考研相关的内容, 如果想更多了解我们，欢迎关注抖音：cyberdash_yuan

🙋‍♀️ Y_Dash(元哥)

用过很多语言, 做过很多项目, 从底层到应用层, 安全/服务/社区/IoT/...
写代码能剪裁kernel, 吹拉谈唱能去欧洲做展会讲解, 从外太空到内XX, 五花八门什么都略懂一些

💪 G_Dash(磊哥)

10多年安全/系统工程师, 专注C/Linux/网络/安全, 某互联网基础架构部资深工程师, 元哥身后稳如磐石的男人

🤸 L_Dash

Geek, 资深摸鱼大师（bushi... 喜欢一切技术(但不精通

# 📣 感谢支持

如果你喜欢我们的项目，欢迎点击右上角的star，你的支持是我们持续更新的动力！

# 📒 参考
| |  |
| ------------- | - |
| 🧘‍♀️ **《数据结构c语言版》 严蔚敏** | 计算机专业最普遍的教材，数据结构考研参考书籍 |
| ⚛️ **Google Style Guides** | 谷歌的开源代码规范，本项目参考此规范编写 |
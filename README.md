# 通信网络节点评估算法

## 1 程序文件列表

```
 CommNet 
 ├── include
 |	 └── commNet.h
 ├── class
 |	 ├── node.h
 |	 └── node.cpp
 ├── src
 |	 ├── main.cpp
 |	 ├── netOperate.cpp
 |	 ├── dijkstra.cpp
 |	 └── aveLen.cpp
 ├── File
 |	 ├── chinese_ver_nodes
 |	 ├── chinese_ver_links
 |	 ├── english_ver_nodes
 |	 ├── english_ver_links
 |	 └── delete_nodes
 ├── cmake-build-debug	 #program file
 └── CmakeLists.txt		 #program file
```

## 2 注意事项 

- ```commNet.h```文件中，宏定义```netFilename```为节点名及节点权值文件，```linkFilename```为所有链路对应的节点名和链路权值，```delete_node_Filename```为需要评估的节点名文件；
- 节点文件和链路文件需按照实例格式填写；
- ```main.cpp```文件中，第7行的注释可以打印原通信网络各个节点间的路由路径；第13行的注释可以打印删除评估节点后的路由路径；
- 由于除了功能实现外，没有进行其他考虑，该程序的容错率极低。

# NickSpace

## 项目说明
NickSpace 是一个[多重维度动态空间模型]的项目。

最大值和最小值 描述空间的大小，默认为99，0
维度 Dimension 描述空间的复杂度
坐标类 Coordinate 描述某单元的绝对空间属性和相对空间属性
元素类 Element 模型中的基本元素，继承 Coordinate
空间类 Space 表示整个模型的所有空间信息
镜像类 Mirror 获取空间的某个二维影像
子空间类 Pandora 表示以某元素为核心的相对局部空间，用于实现 Linker
链接类 Linker 表示元素之间的响应，用于元素之间的交互
观察者 Observer 展示和输出空间的状态

 - 探索
  使用 Qt 建立图形化界面
  将 Pandora 由简单几何坐标边界升级为聚类


## 主要特性
 - 实现 N 维空间模型

## 安装方法

 - 下载Github仓库
git clone https://github.com/QQDDTT/NickSpace.git


## 注意
 - 仅支持 Linux 系统

 - 本地安装MinGW
   sudo apt install mingw-w64

 - 本地安装CMake
   sudo apt install cmake

 - 本地安装 Qt
   sudo apt install build-essential
   sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
   sudo apt install libxcb-xinerama0-dev
   echo "export DISPLAY=:0" >> ~/.bashrc
 - 注意 WSL 需安装 XServer
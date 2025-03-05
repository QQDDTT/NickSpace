# NickSpace

## 项目说明
NickSpace 是一个[多重维度动态空间模型]的项目。
 - 静态构架
 最大值和最小值 描述空间的大小，默认为99，0
 维度 Dimension 描述空间的复杂度
 坐标类 Coordinate 描述某单元的绝对空间属性和相对空间属性
 元素类 Element 模型中的基本元素，继承 Coordinate
 空间类 Space 表示整个模型的所有空间信息
 镜像类 Mirror 获取空间的某个二维影像
 子空间类 Pandora 表示以某元素为核心的相对局部空间，用于实现 Linker
 链接类 Linker 表示元素之间的响应，用于元素之间的交互
 观察者 Observer 展示和输出空间的状态
 脚本引擎 ScriptEngine 编译 JavaScript 脚本，为主方法设计策略



 - 动态机能
 元素类的 describe 属性，储存元素的信息
 坐标类和空间类的构造函数，灵活建立模型空间
 坐标类重载函数，建立坐标之间的运算法则
 坐标类哈希函数，快速访问空间内某坐标的元素
 链接类 actionable 函数，决定该链接是否成立
 链接类重载函数，用于实现元素之间的交互
 观察者重载函数，展示空间或局部空间

 - JavaScript
 接口类 EleModel 定义元素类 describe 的格式
 接口类 AIModel 定义策略的基本规则

 - 探索
 实现为 C++ 注入 JavaScript 脚本
 尝试 控制类 Element 的 describe 属性定义为 json 格式
      用 JS 脚本通过 Linker 类控制 describe 属性
      这将进一步扩展模型的功能

## 主要特性
 - 离散空间模型，所有位置皆为整数，所有元素之间的交互皆由 Linker 实现
 - XML 文件实时记录模型状态
 - 配置 QuickJS 引擎，支持嵌入 JavaScript 脚本

## 安装方法

 - 下载Github仓库
git clone https://github.com/QQDDTT/NickSpace.git


## 注意
 - 仅支持 Linux 系统

 - 本地安装MinGW
   sudo apt install mingw-w64

 - 本地安装CMake
   sudo apt install cmake

 - 安装 QuickJS
   sudo apt install quickjs

 - 安装 TinyXML2
   sudo apt install libtinyxml2-dev


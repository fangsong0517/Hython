## Hython语言设计与开发

### 项目描述:artificial_satellite:

设计一门自己的编程语言(类似Python解析器)

### 介绍:arrow_heading_down:

为了实战C++设计模式，因此编写一个类似Python的解析器。不言而喻，这是一个很有意义的事情，并且很容易成为了我做过的最酷的项目。通过使用了`Antlr`解析成抽象语法树，可以自定义语法，这很nice!

### 状态

更新中...

### 文件介绍

1. `1.antlr_test`是`Antlr`的基本使用方法的一个小例子(建议先研究)

2. `2.hython-v1`是`Hython`语言的设计开发源代码

   **bin**目录下存放的是生成可执行文件`hython`，`hython xx.py`类似`python xx.py`。

   **include**存放的头文件，其中`ExprTreeEvaluator.h`、`hythonLexer.h`、`hythonParser.h`是`Antlr`生成的，通常没必要理会。

   **lib**存放的你所安装`Antlr`后的`libantlr3c.a`(自行找一下)，和环境有关系，clone下的代码，你必须先把这个`.a`换成你自己的，否则环境不同跑不通。

   **src**存放所有的`.c`、`.cc`文件。

   **testdata**存放所有的测试数据文件。

   **thirdpart**中的`.jar`是编译的时候必备的，和`java`有关系，具体编译参考`makefile`文件，此处`.g`文件是存放文法文本的，自定义语法的地方，`.tokes`是`Antlr`生成的，里面给每种语法字符进行了编上数字，以便于在编写设计程序时的`switch()`方便。

   `makefile`编译文件。

### 测试

测试很简单makefile中把所有的运行自动化在此套件中

```shell
$make #make debug
$make run
```

### 建议学习使用流程

### 1. `Antlr` 的基础使用

安装:
http://blog.csdn.net/wfp458113181wfp/article/details/9148577

http://contrapunctus.net/blog/2012/antlr-c



`Antlr`将源码解析成抽象语法树.它为包括Java，C++，C#在内的语言提供了一个通过语法描述来自动构造自定义语言的识别器（recognizer），[编译器](https://baike.baidu.com/item/编译器/8853067)（parser）和[解释器](https://baike.baidu.com/item/解释器/10418965)（translator）的框架。

1. 增加除法表达式的支持(增加文本[源代码]中的关键字)
2. 增加取余表达式的支持(增加文本[源代码]中的关键字)
3. 修改解释器，对于每一行内容，都输出其表达式的值(修改解析器的功能)
4. 增加定义变量的语法结构
5. 增加作用域的功能`(完成文发文件解释器的程序部分)`

### 2. 简单的流程控制

1. 整理工程目录,`inclue/lib/bin/src/...`
2. 整理`main.cpp`内容,分成头文件和源文件,`main.cpp`尽量简单
3. `print`子句
4. 条件表达式(`==,<=,>=,&&,||`)
5. `if`结构的增加
6. `for`结构的增加
7. `while`结构的增加
8. `do...while`结构的增加

### 3.增加弱类型系统

1. 用责任链模式改写整体 `ExprTreeEvaluator `类的功能
2. 设计并实现弱类型系统





### 其他

#### **.g的作用**

```c
// The suffix '^' means make it a root.   ^作用：提升至抽象语法树的根节点。
// The suffix '!' means ignore it.   ！作用：忽略

expr ：表达式。冒号后面是表达式。

*号：代表:0 ～多次； +号：代表： 1 ～多次

atom ： 原子操作 ： INT， ID， （ ），等。INT代表整数， ID代表标识符。

stmt：代码段；  ->代表重映射。ASSIGN代表：= ；

^(ASSIGN ID expr)代表：=号为根节点， ID， expr 分别：左右子树。
```

#### 抽象语法树

![image-20200829110259868](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200829110259868.png)

#### 责任链模式

![image-20200830232450309](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200830232450309.png)


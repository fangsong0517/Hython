## Hython语言设计与开发

### 项目描述

设计一门自己的编程语言



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









### 其他

**.g的作用**

```c
// The suffix '^' means make it a root.   ^作用：提升至抽象语法树的根节点。
// The suffix '!' means ignore it.   ！作用：忽略

expr ：表达式。冒号后面是表达式。

*号：代表:0 ～多次； +号：代表： 1 ～多次

atom ： 原子操作 ： INT， ID， （ ），等。INT代表整数， ID代表标识符。

stmt：代码段；  ->代表重映射。ASSIGN代表：= ；

^(ASSIGN ID expr)代表：=号为根节点， ID， expr 分别：左右子树。
```

此处是获取了抽象语法树

![image-20200829110259868](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200829110259868.png)
## Hython语言设计与开发

### 项目描述

设计一门自己的编程语言



### 1. `Antlr` 的基础使用

`Antlr`将源码解析成抽象语法树.它为包括Java，C++，C#在内的语言提供了一个通过语法描述来自动构造自定义语言的识别器（recognizer），[编译器](https://baike.baidu.com/item/编译器/8853067)（parser）和[解释器](https://baike.baidu.com/item/解释器/10418965)（translator）的框架。

1. 增加除法表达式的支持(增加文本[源代码]中的关键字)
2. 增加取余表达式的支持(增加文本[源代码]中的关键字)
3. 修改解释器，对于每一行内容，都输出其表达式的值(修改解析器的功能)
4. 增加定义变量的语法结构
5. 增加作用域的功能`(基于船长的文法文件，完成解释器的程序部分)`

![image-20200824142743026](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200824142743026.png)

```cpp
{
    3 + 5;
    7 + 89;
    def a = 97 * 2;
    def c = 97 / 2;
    def d = 92 % 2;
    def b = 123 + a;
    def i1, i2, i3, i4;
    {
        a = 123;
    }
    f = a + b;
}

```


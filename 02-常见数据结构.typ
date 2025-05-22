#import "lib/lib.typ": *
#show: chapter-style.with(title: "算法概览", info: info-algo)

= STL
<STL>

C++ STL（标准模板库）是一套功能强大的 C++ 模板类，提供了通用的模板类和函数，这些模板类和函数可以实现多种流行和常用的算法和数据结构。

STL 大体分为六大组件，分别是：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

- 容器（container）：容器是用来管理某一类对象的集合
- 算法（algorithm）：作用于容器，提供了执行各种操作的方式
- 迭代器（iterator）：链接容器和算法- 仿函数：行为类似函数，可作为算法的某种策略
- 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
- 空间配置器：负责空间的配置与管理

== 访问 & 遍历

#let csv1 = csv("lib/stl-query.csv")
#figure(tableq(csv1, 8), caption: "访问 & 遍历", kind: table)

== 信息

#let csv1 = csv("lib/stl-info.csv")
#figure(tableq(csv1, 8), caption: "信息", kind: table)

== 元素操作

#let csv1 = csv("lib/stl-elem.csv")
#figure(tableq(csv1, 8, inset: 0.35em), caption: "元素操作", kind: table)

- `[]`：访问越界，直接挂掉
- `at()`：访问越界，抛出异常

== 容器操作

#let csv1 = csv("lib/stl-cont.csv")
#figure(tableq(csv1, 8), caption: "容器操作", kind: table)

== 迭代器

#let csv1 = csv("lib/stl-iter.csv")
#figure(tableq(csv1, 3, inset: 0.35em), caption: "迭代器", kind: table)

= 字符串
<字符串>

```cpp
char *message = "Hello World!";
```

== 字符串数组
字符串和字符数组的区别：最后一位是否是空字符

#let code1 = read("code/str_size.cpp")
#code(code1, lang: "c++")

== 基本操作

#let data = csv("lib/str.csv")
#figure(tableq(data, 2), caption: "字符串基本操作", kind: table)

#let code1 = read("code/str_op.cpp")
#code(code1, lang: "c++")

== 替换
使用 `memset(void *s, int c, unsigned long n)`：将指针变量 s 所指向的前$n$字节的内存单元用一个”整数”c 替换。

#let code1 = read("code/str_memset.cpp")
#code(code1, lang: "c++")

= C++ 发展史
<发展史>

== 语言沿革

+ FORTRAN：第一门高级语言
+ BCLP 语言
+ B 语言
+ C 语言,
+ C++（C + 面向对象 + 泛型）

== 大事纪要

- 1973 年 3 月，第三版 UNIX 上有了 C 语言的编译器
- 1973 年 11 月，第四版 UNIX 完全由 C 语言重写
- 1989 年，ANSI 发布第一个标准，"ANSI C"
- 1990 年，ISO 接受 "ANSI C"，命名为 "C89"
- 2014 年，所有现代编译器都支持了 "C99"

= 运算表达式
<运算表达式>

运算表达式有如下几种形式

- 完全括号表达式：不必记忆任何优先级规则，但繁琐
- 中缀表达式（infix）：操作符介于操作数（operand）之间，如 `B + C`
- 后缀表达式（postfix）：由前到后运算，适合计算机运算
- 前缀表达式（prefix）：由后到前运算

对中缀表达式的例子：`A + B * C`，虽然运算符`+`和`*`都在操作数之间，但存在一个运算优先级的问题。尽管四则运算的法则对人来说显而易见，计算机却需要明确地知道以何种顺序进行何种运算。杜绝歧义的写法有如下几种

#let data = csv("lib/op-expr.csv")
#figure(tableq(data, 3), caption: "运算表达式", kind: table)

== 中缀到后缀
对表达式 `A + ( B * C )`，需要两步

- 将 `*` 移到对应的 `)` 所在位置，去掉对应的 `(`，得到 `B C *`
- 将 `+` 移到对应的 `)` 所在位置，去掉对应的 `(`，得到 `A B C * +`

#figure(image("images/infix2postfix.png", width: 40%), caption: "中缀到后缀")

== 中缀到前缀

#figure(image("images/infix2prefix.png", width: 40%), caption: "中缀到前缀")

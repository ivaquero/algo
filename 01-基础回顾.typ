#import "lib/lib.typ": *
#show: chapter-style.with(
  title: "C++ 速通",
  info: info,
)

= 数据类型
<数据类型>

- 变量：存储数据的有上限的容器
- 常量（通常全大写）
  - `const` 修饰的变量
  - 字符串常量

== `auto`

- 声明变量时根据初始化表达式自动推断该变量的类型
- 声明函数时函数返回值的占位符

#let code1 = read("oop/type_auto.cpp")
#code(code1, lang: "c++")

== 输出与输入

- 格式化输出：`printf()`
- 格式化输入：`scanf()`

=== 整型

#let csv1 = csv("data/print-int.csv")
#figure(
  tableq(csv1, 3),
  caption: none,
  supplement: "表",
  kind: table,
)

#let code1 = read("oop/print_uint.cpp")
#code(code1, lang: "c++")

=== 浮点数

#let csv1 = csv("data/print-float.csv")
#figure(
  tableq(csv1, 4),
  caption: none,
  supplement: "表",
  kind: table,
)

=== 其他

- `size_t`：编码对象的大小
  - `%zd`：十进制
  - `%zx`：十六进制

= 指针

指针是一种局部变量，也是一个对象，其值为另一个变量的内存位置。指针实现了对其他对象的间接访问。

- 允许对指针赋值和拷贝，且在指针的生命周期内它可以先后指向几个不同的对象
- 无需在定义时赋初值
- 类型同变量的类型

#tip[
  简言之，指针变量就是记录地址的变量
]

- `&`
  - 取地址符，操作对象为变量
  - `*`
  #block(
    height: 6em,
    columns()[
      - 解引用符
        - 为右值（rvalue）
        - 获取指针指代的对象
        - 取地址符的逆运算
      - 指针声明符
        - 为左值（lvalue），即地址
        - 右值为已赋值变量
    ],
  )

#let code1 = read("oop/ptr_addr.cpp")
#code(code1, lang: "c++")

指针的一个作用是，同步变更变量的值。

#let code1 = read("oop/ptr_change.cpp")
#code(code1, lang: "c++")

== 指针的运算

假设数组 `int a[10]; int (*p)[10] = &a;`。其中，

- `a` 是数组名，是数组⾸元素地址，`+1` 表示地址值加上⼀个 `int`类型的⼤⼩，若`a`的值是 `0x00000001`，`+1` 操作后变为`0x00000005`，`(a + 1) = a[1]`。
- `&a` 是数组的指针，其类型为 `int(*)[10]`，其`+1`操作时，系统会认为是数组⾸地址加上整个数组的偏移，值为数组`a`尾元素后⼀个元素的地址。
- 若`(int *)p` ，此时输出`*p` 时，其值为`a[0]`的值，因为被转为`int *`类型，解引⽤时按照 `int`类型⼤⼩来读取。
使用运算赋值，可以避免索引赋值造成的缓冲溢出（buffer overflows）。

#let code1 = read("oop/ptr_arithm.cpp")
#code(code1, lang: "c++")

== this 指针

- `->` 的作用
  - 解引用
  - 指针所指的结构变量中的成员

当为一个方法编程时，有时需要访问当前对象，也就是正在执行该方法的对象。在方法定义中，可以使用 `this` 指针来访问当前对象。

通常情况下，这是不需要的，因为在访问成员时这是隐含的。但当需要消除歧义，例如，若声明的方法参数的名称与一个成员变量相冲突，`this` 指针就很必要。

#let code1 = read("oop/ptr_this.cpp")
#code(code1, lang: "c++")

方法参数总会掩盖成员，这意味着在此方法中输入 `year` 时，它指的是
`year` 参数，而非 `year` 成员。此时可用 `this` 来消除歧义。

= 引用

引用是一种变量，是指针的更安全、更方便的版本。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

- 改变引用变量会同时改变它引用的那个变量
- 不会分配内存
- 在声明前必须被初始化
- 引用指向的是对象的地址

== 与指针
指针和引用在很大程度上是可以互换的，但两者都有取舍。

- 若有时必须改变我们的引用类型，必须使用一个指针。许多数据结构要求我们能够改变一个指针的值
- 因为引用不能被重新定位，它们一般不应该被分配给`nullptr`，所以它们有时不适合

#let csv1 = csv("data/ptr-ref.csv")
#figure(
  tableq(csv1, 3),
  caption: "指针与引用",
  supplement: "表",
  kind: table,
)

引用通常用于函数参数列表和函数返回值。

- 作为参数：比一般的参数更安全
- 作为返回值：同返回其他数据类型

#let code1 = read("oop/ref_deref.cpp")
#code(code1, lang: "c++")

== const 限定

- 与指针
  - 指针两大操作空间
    - 重新指向
    - 变换当前值
  - `double const*`：指向不可动
  - `const double*`：指向的值不可修改
  - `const double const*`：不能动，也不能修改
- 与引用
  - `const double&` 相当于 `const double const*`

= 函数定义
<函数定义>

== main()

- `argc(argument count)`：保存运行时传递给 `main()` 的参数个数
- `argv[](argument vector)`：保存运行时传递`main()`的参数
  - 类型是一个字符指针数组，每个元素是一个字符指针，指向一个命令行参数
  - `argv[0]`：指向程序运行时的全路径名
  - `argv[1]`：指向程序在命令行中执行程序名后的第一个字符串
  - `argv[argc]`：指向 `nullptr`
- 形参在被调用时分配内存，在调用结束时释放内存
- 实参出现在主调函数

#let code1 = read("oop/func_argc.cpp")
#code(code1, lang: "c++")

== Lambda 函数

Lambda 函数又称匿名函数。具有输入输出，表达式的参数就是其输入，表达式结果为函数的输出。

- `=` 表示值传递方式捕捉所有父作用域的变量（包括 `this`）
- `&var` 表示引用传递捕捉变量 `var`
- `&` 表示引用传递捕捉所有父作用域的变量（包括 this）

#let code1 = read("oop/func_lam.cpp")
#code(code1, lang: "c++")

= 运算符
<运算符>

== 增量运算符

#let csv1 = csv("data/op-increment.csv")
#figure(
  tableq(csv1, 3, inset: 0.35em),
  caption: "增量运算符",
  supplement: "表",
  kind: table,
)

#let code1 = read("oop/op_increment.cpp")
#code(code1, lang: "c++")

= 其他
<其他>

== \#define

`#define` 的实质是字符替换

- 编译器处理⽅式
  - `#define` 在预处理阶段展开，不能对宏定义进⾏调试；
  - `const` 是在编译阶段使⽤；
- 类型和安全检查
  - `#define`
    没有类型，不做任何类型检查，仅仅是代码展开，可能产⽣边际效应等错误；
  - `const` 有具体类型，在编译阶段会执⾏类型检查；
- 存储⽅式
  - `#define`
    仅代码展开，在多个地⽅进⾏字符串替换，不分配内存，存储于程序的代码段中
  - `const` 会分配内存，但只维持⼀份拷⻉，存储于程序的数据段中；
- 定义域
  - `#define` 不受定义域限制；
  - `const` 只在定义域内有效；

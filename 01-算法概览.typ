#import "lib/lib.typ": *
#show: chapter-style.with(title: "算法概览", info: info-algo)

= 运算表达式
<运算表达式>

运算表达式有如下几种形式

- 完全括号表达式：不必记忆任何优先级规则，但繁琐
- 中缀表达式（infix）：操作符介于操作数（operand）之间，如 `B + C`
- 后缀表达式（postfix）：由前到后运算，适合计算机运算
- 前缀表达式（prefix）：由后到前运算

对中缀表达式的例子：`A + B * C`，虽然运算符`+`和`*`都在操作数之间，但存在一个运算优先级的问题。尽管四则运算的法则对人来说显而易见，计算机却需要明确地知道以何种顺序进行何种运算。杜绝歧义的写法有如下几种

#let data = csv("data/op-expr.csv")
#figure(tableq(data, 3), caption: "运算表达式", kind: table)

== 中缀到后缀

对表达式 `A + ( B * C )`，需要两步

- 将 `*` 移到对应的 `)` 所在位置，去掉对应的 `(`，得到 `B C *`
- 将 `+` 移到对应的 `)` 所在位置，去掉对应的 `(`，得到 `A B C * +`

#figure(image("images/infix2postfix.png", width: 40%), caption: "中缀到后缀")

== 中缀到前缀

#figure(image("images/infix2prefix.png", width: 40%), caption: "中缀到前缀")

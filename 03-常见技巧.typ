#import "lib/lib.typ": *
#show: qooklet.with(
  title: "常见技巧",
  author: "Yāng Xīnbīn",
  footer-cap: "Yāng Xīnbīn",
  header-cap: "数据结构与算法",
  lang: "zh",
)

= 数组
<数组>

== 遍历

#let code1 = read("code/array_iter.cpp")
#code(code1, lang: "c++")

== 模除

- 翻转数字

#let code1 = read("code/array_math_mod.cpp")
#code(code1, lang: "c++")

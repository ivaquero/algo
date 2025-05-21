#import "lib/lib.typ": *
#show: chapter-style.with(
  title: "常见技巧",
  info: info-algo,
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

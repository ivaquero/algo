#import "lib/lib.typ": *
#show: chapter-style.with(
  title: "Docker 入门",
  info: info-tool,
)

= container

== run

#let data = csv("data/docker-run.csv")
#figure(
  tableq(data, 5),
  caption: "命令行参数",
  supplement: "表",
  kind: table,
)

== 其他

= image

= compose

== 对应关系

```bash
docker run -d --name nginx_host -p 8080:80 -v /opt/nginx:/opt/nginx/html nginx:latest
```
上述命令可转写为 `docker-compose.yml` 文件：

#let compose = read("code/dockerc.yml")
#code(compose, lang: "yaml")

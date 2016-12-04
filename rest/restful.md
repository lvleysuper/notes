## RESTful介绍

### REST的由来

Web（万维网World Wide Web的简称）包罗万象，不同的人对于Web究竟是什么会有相同的观点。从技术架构层面上看，Web的技术架构包括了四个基石：

* URI
* HTTP
* HyperText（除了HTML外，也可以是带有超链接的XML或JSON）
* MIME

在这四个基石之上，Web开发技术的发展可以粗略划分成以下几个阶段：

* 静态内容阶段：这个阶段，Web由大量的静态HTML文档组成，其中大多是一些学术论文。Web服务器可以被看作是支持超文本的共享文件服务器。
* CGI程序阶段：在这个阶段，Web服务器增加了一些编程API。通过这些API编写的应用程序，可以向客户端提供一些动态变化的内容。Web服务器与应用程序之间的通信，通过CGI（Common Gateway Interface）协议完成，应用程序被称作CGI程序。
* 脚本语言阶段：在这个阶段，服务器端出现了ASP、PHP、JSP、ColdFusion等支持session的脚本语言技术，浏览器端出现了Java Applet、JavaScript等技术。使用这些技术，可以提供更加丰富的动态内容。
* 瘦客户端应用阶段：在这个阶段，在服务器端出现了独立于Web服务器的应用服务器。同时出现了Web MVC开发模式，各种Web MVC开发框架逐渐流行，并且占据了统治地位。基于这些框架开发的Web应用，通常都是瘦客户端应用，因为它们是在服务器端生成全部的动态内容。
* RIA应用阶段：在这个阶段，出现了多种RIA（Rich Internet Application）技术，大幅改善了Web应用的用户体验。应用最为广泛的RIA技术是DHTML+Ajax。Ajax技术支持在不刷新页面的情况下动态更新页面中的局部内容。
* 移动Web应用阶段：在这个阶段，出现了大量面向移动设备的Web应用开发技术。除了Android、iOS、Windows Phone等操作系统平台原生的开发技术之外，基于HTML5的开发技术也变得非常流行。

从上述Web开发技术的发展过程看，Web从最初其设计者所构思的主要支持静态文档的阶段，逐渐变得越来越动态化。Web应用的交互模式，变得越来越复杂：从静态文档发展到以内容为主的门户网站、电子商务网站、搜索引擎、社交网站，再到以娱乐为主的大型多人在线游戏、手机游戏。

Web发展到了1995年，在CGI、ASP等技术出现之后，沿用了多年、主要面向静态文档的HTTP/1.0协议已经无法满足Web应用的开发需求，因此需要设计新版本的HTTP协议。HTTP/1.0协议专家组核心开发者Roy Fielding（Apache软件基金会的合作创始人）主导HTTP/1.1协议的设计并取得成功。

Fielding在完成HTTP/1.1协议的设计工作之后，在他的博士学位论文Architectural Styles and the Design of Network-based Software Architectures中，Fielding更为系统、严谨地阐述了这套理论框架，并且使用这套理论框架推导出了一种新的架构风格，并且为这种架构风格取了一个令人轻松愉快的名字“REST”——Representational State Transfer（表述性状态转移）的缩写。

http://www.infoq.com/cn/articles/understanding-restful-style
http://www.ruanyifeng.com/blog/2011/09/restful.html
http://www.infoq.com/cn/articles/designing-restful-http-apps-roth
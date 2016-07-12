# Java入门基础
## Java简介

### Java是什么
Java不仅是一门编程语言，还是一个由一系列计算机软件和规范形成的技术体系。
Java是**Java语言**和**Java平台**的总称。

* **Java语言**：静态类型、面向对象的语言。
* **Java平台**：提供运行时环境的软件。Java虚拟机(JVM)负责把类文件形式(字节码)  的代码链接起来并执行。Java作为软件系统之所以成功，主要因为它是一种标准。

### Java发展史
* 1991年4月,James Gosling博士主导的Green Project启动，目的是开发能在消费性电子产品（机顶盒、冰箱等）上运行的程序架构。这个计划的产品就是Java的前身Oak，Oak在消费市场并不算成功；1995年随着互联网潮流的兴起，Oak迅速找到适合自己发展的市场定位蜕变为Java语言。
* 1995年5月23日，Oak语言更名为Java，在SunWorld发布Java1.0，并提出"Write Once,Run AnyWhere"的口号。
* 1996年1月23日，JDK1.0发布，代表技术：Java虚拟机、Applet、AWT等。
* 1996年4月，10个主流操作系统供应商申明在其产品嵌入Java技术；同年9月份，大约8.3w个网页应用了Java技术制作。
* 1997年2月19日，Sun发布JDK1.1，Java技术的最基础的支撑点都是在该版本发布，代表技术：JAR文件格式
，JDBC，JavaBeans，RMI等。
* 1998年12月4日，发布里程碑式版本JDK1.2，Sun在这个版本把Java技术体系分为三个方向：面向桌面应用
的J2SE，面向企业的J2EE和面向终端的J2NE。代表技术：EJB、Java Plug-in、Java IDL、Swing等。并在该
版本的Java虚拟机中第一次内置JIT。
* 2000年5月8日，JDK1.3发布，相对1.2版本改进主要表现在一些类库上。
* 2002年2月13日，JDK1.4版本发布，这是Java走向成熟的一个版本。该版本发布很多新技术特性：正则表达
式，异常链，NIO，日志类等。值得一提的是NIO，NIO的引入大大提高了服务端IO的效率，使得Java在服务端开发得到重用。
* 2004年9月30日，JDK1.5发布，在语法易用性上做出非常大的改进。
* 2006年12月11日，JDK1.6发布，技术J2SE、J2EE、J2ME的命名方式，启用JavaSE6、JavaME6、JavaEE6的命
名方式。该版本在语言动态支持和虚拟机内部做了大量改进。
* 2009年4月20日，Oracle收购Sun公司。
* 2011年7月28日，甲骨文发布java7.0的正式版。
* 2014年3月18日，发布Java8，引入函数式编程。

### Java vs C++
1. Java运行时JIT即时编译，运行速度比C++慢，但随着JIT的发展这一差距越来越小
2. Java中所有东西必须置入一个类。不存在全局函数或全局数据，可考虑使用类的
static方法和static成员实现等价功能
3. Java没有类声明在，只有类定义，没有作用域运算符
4. 基本数据类型长度固定，与机器无关
5. 字符使用unicode字符集
6. Java中不必提前声明，且没有预处理机制；使用类库，只需要使用import制定库名
7. Java使用包代替命名空间
8. Java没有C++那样的指针，用new创建对象会获得一个引用；所有变量均按引用传递
9. Java采用单根式分级结构，所有对象都是从根类Object统一继承
10. Java使用垃圾回收释放内存
11. Java不提供多重继承机制
12. Java提供丰富的标准库：多线程、JDBC、Socket、RMI等


### Java发展趋势
1. 模块化：对模块化提供语法层面的支持
2. 混合编程：Clojure、JRuby、JPython、Groovy等运行于JVM
3. 多核并行：OpenJDK的Sumatra项目
4. 丰富语法：Lambda表达式


## Java开发环境配置
### Windows环境安装
* 下载合适的[JDK版本](http://www.oracle.com/technetwork/java/javase/downloads/index-jsp-138363.html)，点击安装，下一步直到完成
* 添加JAVA_HOME环境变量
* 将$JAVA_HOME/bin添加到$PATH中

### Linux环境安装
	略

## Java基础语法
### 
### 基本类型
2. **Java是编译型语言还是解释型语言？**
	* Java源文件(.java)需要通过javac编译成.class字节码文件才能被JVM解释，在运行阶段即时(JIT)编译。
	* Java到字节码的过程不同于C/C++理解的编译，只是生成了中间语言(IL)形态，真正的编译器是JIT。

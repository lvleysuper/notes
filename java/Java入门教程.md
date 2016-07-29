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
### windows系统安装java
#### 下载、安装和环境变量配置
* 下载Java开发工具包JDK，[下载地址](http://www.oracle.com/technetwork/java/javase/downloads/index.html)
* 以64位系统为例，选择Windows x64版本
* 配置环境变量：[计算机]右键[属性]，选择[高级系统设置]，添加[环境变量]
```
变量名：JAVA_HOME
变量值：C:\Program Files (x86)\Java\jdk1.8.0_91        // 要根据自己的实际路径配置
变量名：CLASSPATH
变量值：.;%JAVA_HOME%\lib\dt.jar;%JAVA_HOME%\lib\tools.jar;         //记得前面有个"."
变量名：Path
变量值：%JAVA_HOME%\bin;%JAVA_HOME%\jre\bin;
```
#### 验证是否安装成功
* Win+R，输入cmd，在cmd中输入`java --version`，查看是否能输出版本信息



## Java基础语法
### 第一个Java程序
```java
/*
*	Author : lvley
* 	Date : 2016-07-01
*/

public class HelloWorld{
	public static void main(String[] args){
		System.out.println("Hello World"); //打印Hello World
	}
}
```
保存为HelloWorld.java，在cmd下执行
```cmd
C : > javac HelloWorld.java
C : > java HelloWorld 
Hello World
```

**用例说明：**
* Java支持两种风格的注释，和C++相同
* 文件名和类名相同，一个源文件只能有一个public类，可以有多个非public类
* 主方法入口：public static void main
* 首选数组表示方式：String [] args
* 使用`.`号操作对象方法，不存在指针操作
* public声明类或方法公有
* static声明方法为静态方法

### Java标识符
* 标识符以字母(A-Z,a-z),美元符($)或下划线(_)开始
* 首字母之后可以是任意字符组合
* 大小写敏感
* 关键字不能用作标识符
和C++类似，除了$开头的区别。

### Java数据类型
* Java坚持"所有都是对象"，但为了底层效率还是引入了基本数据类型
* Java决定基本类型的大小，不随机器结构变化，这也是Java强移植能力的原因之一
* Java无unsiged类型，所有基本类型都有封装器类

**基本类型列表**

|主类型|大小(位)|最小值|最大值|封装器类型|
|------|------|---|---|---|
|boolean|1|-|-|Boolean|
|char|16|Unicode 0|Unicode 2^16-1|Character|
|byte|8|-128|127|Byte|
|short|16|-2^15|2^15-1|Short|
|int|32|-2^31|2^31-1|Integer|
|long|64|-2^63|2^63-1|Long|
|float|32|-3.40E+38|3.40E+38|Float|
|double|64|-1.79E+308|1.79E+308|Double|

**封装器类用法示例：**
```java
char c = 'x';
Character ec = new Character('x');
String str = "1.5";
float val = Float.parseFloat(str);
```
**高精度类型**

不可直接使用运算符操作，必须使用方法调用

* **BigInteger**：支持任意精度的整数
* **BigDecimal**：支持任意精度的定点数字

**自定义类**

语法：
```java
class ATypeName
{
	// 方法 ：返回类型 方法名(参数列表) { 方法主体 }

	// 数据成员
	
}
```

## Java中类和对象
Java是面向对象语言，支持OOP的基本概念:**多态**，**继承**，**封装**，**抽象**，**重载**，**类**，**对象**。

Java中类和对象的概念与C++类似，类是一个模板，用于描述对象的行为和状态；对象是类的一个具体实例，有行为和状态。

通过一个简单的实例来理解Java中类和相关内容：
```java
package com.demo;
import java.util.Date;

class Test
{
	public static int UUID = 20160729;
	private long nativeFileId ;
	private name;


	public Test() {
		nativeFileId = openFile();
	}

	public Test(String name){
		this.name = name;
	}

	protect void finilize() {
		closeFile(nativeFileId);
	}

	public void displayTime(){
		System.out.println(new Date());
	}

	native public long openFile() { return 100; }
	native public void closeFile(long fileId) {}

}
```
### 构造与析构

Java中和C++一样也有构造函数，和类名相同，如上例中
```
public Test();
public Test(String name);
```

构造实例：
```
Test t = new Test();
```
Java中使用new构造类实例，返回对象引用，Java中不使用指针；Java中new的对象都是在堆上分配内存，当对象不再需要的时候会有垃圾收集器（GC）回收对象内存。

Java中一般不需要显式的释放内存，故没有析构函数。但是可以使用finilize()方法实现资源的释放。上例中native声明
了2个C++中的本地方法，openFile打开文件，并返回文件句柄；closeFile关闭文件。这种资源在DLL(或so)中申请，GC并不能直接控制，这中情况就需要自动释放文件句柄。


### Java包（package）
为更好的组织类，Java提供包机制，用于区别类名的命名空间，作用类似于C++的namespace。

**包的作用**
* 把功能相似或相关的类或接口组织在同一个包，方便类的查找和使用
* 和文件夹一样采用属性目录存储，同一个包中类名字是不同的，不同包中类名字可以相同；当同时调用两个不同包中相同类时，应加上包名加以区分，避免名字冲突
* 包限定了访问权限，拥有包访问权限的类才能访问包中的类

**创建包**
```
package pkg1[.pkg2[.pkg3...]];
```
如示例中package com.demo，建议使用域名倒置的方式。对应Test.java位于com/demo目录下。

**引用包**
```
import pkg1[.pkg2[.pkg3...]];
```
示例中`import java.util.Date`导入了Date类（日期操作类）。


### Java修饰符
Java修饰符分为两种：访问控制修饰符和非访问修饰符

#### 访问控制修饰符
* **default**: 默认的，包内可见，不使用任何修饰符
* **public**: 公有的，对所有类可见
* **protected**: 受保护的，对同一包内和所有子类可见
* **private**: 私有的，同一类内可见


#### 非访问修饰符
* **static**:类方法和类变量，Java中无全局变量，可使用static实现类似功能
* **final**:类、方法和变量，final修饰的类不能被继承，修饰的方法不能被继承类重新定义，修饰的变量是常量，不可修改的
* **abstract**:抽象类和抽象方法
* **synchronized**:代码块、方法，多线程编程
* **volatile**:作用同C++，多线程编程
* **transient**:序列化对象被transient修饰时，jvm跳过该变量


### Java中变量类型
Java是强类型语言，声明变量的格式如下：
```
type identifier [= value][, identifier [= vlaue] ...];
```
type为Java数据类型，identifier为变量名，多个变量使用逗号分隔。

Java有四种变量类型：
* **局部变量**
	* 局部变量声明在方法、构造方法或语句块中，执行完就自动销毁
	* 访问修饰符不能用于局部变量
	* 局部变量在栈上分配，旨在声明它的语句块中可见
	* 局部变量必须初始化才可以使用
* **成员变量**
	类的成员变量，和实例生命周期相同
* **实例变量**
	new创建，声明周期GC控制
* **类变量**（全局变量）
	* static声明静态变量，必须在构造方法和与语句块之外
	* 不论创建多少个对象，都只有一份拷贝
	* 程序开始创建，程序结束销毁
	* 可通过ClassName.VariableName的方式访问
	* public static final类型，变量名车必须使用大写字母



### 基本类型
2. **Java是编译型语言还是解释型语言？**
	* Java源文件(.java)需要通过javac编译成.class字节码文件才能被JVM解释，在运行阶段即时(JIT)编译。
	* Java到字节码的过程不同于C/C++理解的编译，只是生成了中间语言(IL)形态，真正的编译器是JIT。

## Scala Notes

### Scala简介及环境安装
* Scala 是一门多范式（multi-paradigm）的编程语言，设计初衷是要集成面向对象编程和函数式编程的各种特性。
* Scala 运行在Java虚拟机上，并兼容现有的Java程序。
* Scala 源代码被编译成Java字节码，可运行于JVM之上，可调用现有的Java类库
    * 编译代码： scalac HelloWorld.scala
    * 执行代码： scala HelloWorld.scala

**环境配置**
* 安装Java环境，配置JAVA_HOME和Path
* 下载Scala，并安装。配置SCALA_HOME，将`%SCALA_HOME%\bin;`添加到Path
* 验证Scala及版本:`scala -version`

### Scala语法
#### 基本语法
* 大小写敏感
* 类名第一个字母大写，命名单词的首字母大写
* 方法采用驼峰命名
* 文件名和类名要完全匹配
* def main(args: Array[String])定义函数入口

#### 标识符

Scala包含两种标识符：
* 字母数字：字母或下划线开头，$当做字母，$开头的标示符为scala编译器保留标识符，避免使用
* 符号：符号标识符包含一个或多个符号，如+，:，?
可以混合使用，scala可以在''之间的使用任何有效scala标识符，包括关键字

#### Scala关键字

不能以关键字做变量:

|col1|col2|col3|col4|col5|col6|
|:------|:------|:------|:------|:------|:------|
|abstract|case|catch|class|def|do|
|else|extends|false|final|finally| for|
|forSome|if|implicit|import|lazy|match|
|new|null|object|override|package|private|
|protected|return|  sealed | super|this |throw|  
| trait|   try|true|type|val |var|
|while|   with  |  yield   | |||
|-  | :  | =  | =>|<- | <:| 
| <% | >:|#   |@|||


#### 注释、空格/行、换行
* 注释：类似java，单行或多行注释
* 空格/行：一行只有空格，会被认为空行，标记可被空格或注释分割
* 换行符：使用分号或换行结束一行，分号可选；当一行多条语句时，必须使用分号

#### Scala包

**定义包**
两种定义形式：
* 和Java相同，当前文件打包到指定包中
* 类似C#, `package pkg_name { class Hello }`，可以在一个文件中定义多个包

** 引用包**
* Scala 使用 import 关键字引用包。
* import语句可以出现在任何地方，而不是只能在文件顶部。import的效果从开始延伸到语句块的结束。这可以大幅减少名称冲突的可能性
* 默认情况下，Scala 总会引入 java.lang._ 、 scala._ 和 Predef._，这里也能解释，为什么以scala开头的包，在使用时都是省去scala.的。


#### 变量声明
在 Scala 中，使用关键词 "var" 声明变量，使用关键词 "val" 声明常量。
var VariableName : DataType [=  Initial Value]

或

val VariableName : DataType [=  Initial Value]


在 Scala 中声明变量和常量不一定要指明数据类型，在没有指明数据类型的情况下，其数据类型是通过变量或常量的初始值推断出来的


Scala 多个变量声明
Scala 支持多个变量的声明：
val xmax, ymax = 100  // xmax, ymax都声明为100
如果方法返回值是元组，我们可以使用 val 来声明一个元组：
val (myVar1: Int, myVar2: String) = Pair(40, "Foo")
也可以不指定数据类型：
val (myVar1, myVar2) = Pair(40, "Foo")

函数声明
Scala 函数声明格式如下：
def functionName ([参数列表]) : [return type]
如果你不写等于号和方法主体，那么方法会被隐式声明为"抽象(abstract)"，包含它的类型于是也是一个抽象类型。

函数定义
方法定义由一个def 关键字开始，紧接着是可选的参数列表，一个冒号"：" 和方法的返回类型，一个等于号"="，最后是方法的主体。
Scala 函数定义格式如下：
def functionName ([参数列表]) : [return type] = {
   function body
   return [expr]
}

如果函数没有返回值，可以返回为 Unit，类似于 Java 的 void
## 下载 & 安装
1. http://maven.apache.org/download.cgi下载对应版本
2. 解压到自定义目录（<MAVEN_HOME>）
3. 设置环境变量M2_HOME为解压目录；在PATH中添加%M2_HOME%\bin
4. `mvn --version`检测安装是否成功

## 创建mvn project
```
mvn archetype:generate -DgroupId=com.mycompany.app -DartifactId=my-app 
-DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
```

### mvn工程结构
```
my-app
|-- pom.xml
`-- src
    |-- main
    |   `-- java
    |       `-- com
    |           `-- mycompany
    |               `-- app
    |                   `-- App.java
    `-- test
        `-- java
            `-- com
                `-- mycompany
                    `-- app
                        `-- AppTest.java
```

* src/main/java : 源码目录
* src/test/java : 测试代码目录
* pom.xml : project的工程对象模型（Project Object Model，POM）

### Maven标准目录布局

|目录|英文描述|中文描述|
|------|------|------|
|src/main/java|Application/Library sources|源代码目录|
|src/main/resources|Application/Library resources|资源目录|
|src/main/resources-filtered|Application/Library resources which are filtered. (Starting with Maven 3.4.0, not yet released.)|过滤后的资源，Maven 3.4.0以后版本才支持|
|src/main/filters|Resource filter files|资源过滤文件|
|src/main/webapp|Web application sources|web应用代码目录|
|src/test/java|Test sources|测试代码目录|
|src/test/resources|Test resources|测试资源目录|
|src/test/resources-filtered|Test resources which are filtered by default. (Starting with Maven 3.4.0, not yet released.)|过滤后的测试资源|
|src/test/filters|Test resource filter files|测试资源过滤文件|
|src/it|Integration Tests (primarily for plugins)|集成测试|
|src/assembly|Assembly descriptors|汇编描述|
|src/site|Site|站点目录|
|LICENSE.txt|Project's license|项目许可|
|NOTICE.txt|Notices and attributions required by libraries that the project depends on|项目依赖说明|
|README.txt|Project's readme|项目说明文件|
|pom.xml|descriptive of the project|项目描述文件|

* 项目布局只有2个子目录，src和target，target存储build产生的文件；此外只可能出现其他元数据信息比如CVS,.git或.svn
* src目录包含build需要的所有资源，main是产品生成的主要目录，test是测试代码和资源目录，site是站点目录；main下java标示java语言
* 如果有其他贡献代码，可能在其他子目录，比如src/main/antlr，该目录包含Antlr语法定义文件

## mvn工程配置文件
pom.xml是工程的核心配置文件。

实例配置（主体部分）：
```xml
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
  <modelVersion>4.0.0</modelVersion>
 
  <groupId>com.mycompany.app</groupId>
  <artifactId>my-app</artifactId>
  <version>1.0-SNAPSHOT</version>
  <packaging>jar</packaging>
 
  <name>Maven Quick Start Archetype</name>
  <url>http://maven.apache.org</url>
 
  <dependencies>
    <dependency>
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.8.2</version>
      <scope>test</scope>
    </dependency>
  </dependencies>
</project>
```
* project : pom.xml顶级元素
* modelVersion : Maven使用POM模型版本，强制声明，很少变化
* groupId : 生成当前工程的组织名称，名称要求完全限定
* artifactId : 生成的产品名称，典型的maven产品名称格式<artifactId>-<version>.<extension>(eg:my-app-1.0.jar)
* version : artifact的版本，SNAPSHOT标示为develop版本，详见[SNAPSHOT](http://maven.apache.org/guides/getting-started/index.html#What_is_a_SNAPSHOT_version)细节
* packaging : 生成package格式(如jar,war,ear)
* name : project显示的名称，通常用于Maven生成的文档
* url : 标示项目的url路径，通常用于Maven生成的文档
* description : 项目基本描述，通常用于Maven生成的文档




## mvn生命周期

默认声明周期列表：

* **validate**：检验阶段，工程是否正确，所有必要信息是否有效
* **compile**：编译阶段，编译源码
* **test**：测试阶段，使用合适的单元测试矿建测试编译后的源码，不要求代码打包或部署
* **package**：打包阶段，打包编译后的源码为指定格式，比如JAR
* **integration-test**：集成测试阶段，在集成测试环境上执行并部署package
* **verify**：验证阶段，确保package有效并达到质量标准
* **install**：安装阶段，将package安装到本地目录，以便本地使用
* **deploy**：部署阶段，在生产环境上执行，拷贝最终安装包到远程目录共享使用

例外列表：

* **clean** ： 清理先前编译的产物
* **site**：生成工程的在线帮助文档

## 编译工程

编译工程（至package阶段）：
```
mvn package
```

清理工程及依赖，并编译打包

```
mvn clean dependecy:copy-dependencies package
```

生成在线文档，在target/site目录
```
mvn site
```
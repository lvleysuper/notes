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

**mvn工程结构**
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
```bat
mvn site
```
## NETCONF协议简介

NETCONF协议定义了一种简单的机制，可以管理网络设备，并能够对网络配置信息进行CRUD操作。
NETCONF协议使用RPC规范，请求和应答数都被封装在XML数据中，可通过XML DTDs或XML Schema进行数据验证。
NETCONF几乎完全映射了设备的原始功能，减少了实现难度和访问设备特性的时间，使应用程序可以访问设备的原始用户接口。
NETCONF协议允许设备探测服务器具备的特性，并规范自己的行为。

### 术语

* candidate configuration datastore : 可选配置数据存储，不影响当前运行时配置，不是所有设备
都支持
* capability : 功能，补充NETCONF基本规范
* client : 客户端，通过协议操作服务器，也可以接受服务器的通知
* configuration data : 配置数据，一组可写数据可以使系统从出事状态变更到当前状态
* datastore : 数据存储，存储和访问数据的地方，可能通过文件、数据库、闪存等方式存储
* configiuration datastore : 配置数据存储，用于存储配置数据
* message : 消息，会话上的协议元素，XML格式的数据
* notification : 消息通知，服务端发起
* protocil operaiton : 协议操作，特定rpc调用
* remote procedure call : 远程过程调用，在消息中通过<rpc>和<rpc-reply>实现
* running configuration datastore : 运行时配置数据存储，存储设备当前运行时配置，始终存在
* server : 服务器，处理客户端的请求
* session : 会话，客户端和服务器通过全的，面向连接的会话交换数据
* startup configuration datastore : 启动时配置数据存储
* state data : 状态数据，只读的状态信息和统计数据
* user : 用户，客户端授权的标示


### 协议概况
NETCONF使用RPC-based进制进行通讯，设备和服务器，客户端和应用程序在本文档指代相同的概念。
设备至少支持单会话，应该支持多会话。全局配置属性，会影响所有会话。会话专属的属性，只会影响当前会话。

NETCONF协议可分为四层：

          Layer                 Example
       +-------------+      +-----------------+      +----------------+
   (4) |   Content   |      |  Configuration  |      |  Notification  |
       |             |      |      data       |      |      data      |
       +-------------+      +-----------------+      +----------------+
              |                       |                      |
       +-------------+      +-----------------+              |
   (3) | Operations  |      |  <edit-config>  |              |
       |             |      |                 |              |
       +-------------+      +-----------------+              |
              |                       |                      |
       +-------------+      +-----------------+      +----------------+
   (2) |  Messages   |      |     <rpc>,      |      | <notification> |
       |             |      |   <rpc-reply>   |      |                |
       +-------------+      +-----------------+      +----------------+
              |                       |                      |
       +-------------+      +-----------------------------------------+
   (1) |   Secure    |      |  SSH, TLS, BEEP/TLS, SOAP/HTTP/TLS, ... |
       |  Transport  |      |                                         |
       +-------------+      +-----------------------------------------+

1. 会话层：提供服务器和客户端通讯路径，可使用任何实现传输层需求的协议
2. 消息层：为RPC和通知提供简单，传输独立的封包机制
3. 操作层：定义了一系列操作，使用XML编码的参数，通过RPC方法调用
4. 内容层：超出本文档范围，该部分预期独立发展并标准化

### NETCONF功能
NETCONF功能使用URI定义。为支持一种功能，必须支持其依赖的所有功能。

## 传输层需求

### 面向连接的操作
NETCONF是面向连接的，需要两端保持长连接。

### 认证，完整，机密
NETCONF连接必须提供身份认证，数据完整性和机密性，以及重放保护。常用协议有TLS和SSH。

### 强制性传输协议
NETCONF实现必须支持SSH传输协议映射[RFC6242]。

## 基于XML的考虑

NETCONF消息必须是XML格式良好的。如果一端收到<rpc>消息不是XML格式或者不是UTF-8编码，需要返回"malformed-message"错误。

### 命名空间
所有NETCONF协议都必须定义在如下的命名空间中：
```
urn:ietf:params:xml:ns:netconf:base:1.0
```

### 文档类型声明
文档类型声明不允许出现在NETCONF内容中

## RPC模块

### <rpc>元素
### <rpc-reply>元素 
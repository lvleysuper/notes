1. VIM配置文件路径：
```
查看全局配置
:echo $VIM

查看用户目录
:echo $HOME

配置文件windows名称为_vimrc, Unix/Linux下面为.vimrc
```

2. 更改字体
普通版本vim字体与终端字体一致，gvim可以根据需要随意修改：
```
Linux

:set guifont=Courier\ 14

Windows

:set guifont=Courier:14

```

3. 配色方案
配色文件在colors目录中，colors位于VIM的安装目录，配色方案配置：
```
:colorscheme scheme
```
键入colorscheme，在键入一个空格，按Tab可以查看可用的配色方案

4. 个性化高亮
`:match Group /pattern/`命令可以实现高亮匹配，Group代表色彩组，`/pattern/`是正则表达式；
`:so $VIMRUNTIME/syntax/hitest.vim`可查看所有色彩组

匹配Error开头的单词，使用ErrorMsg色彩组标记：
```
:match ErrroMsg /^Error/
```

自定义色彩组：
```
:highlight MyGroup ctermbg=red guibg=red gctermfg=yellow guifg=yellow term=bold
```
* ctermbg 控制台环境背景色
* guibg Gvim背景色
* ctermfg 控制台环境文本颜色
* guifg Gvim文本颜色
* gui Gvim环境字体格式
* term 控制台环境字体格式

示例1：用彩色标记某列后面的文字
```
:match ErrorMsg /\%>73v.\+/

\%> 匹配该列之后的内容，列号紧跟在尖括号的右边
73 列号
v 只能在可见的列上面
.\+ 匹配一个或多个任意字符
```

实例2：标记代码中未被用作缩进的制表符
```
:match errorMsg /[^\t]\zs\t\+/

[^	字符组开始标记，匹配字符数组头部
\t  制表符
]   字符组结束标记
\zs 一个宽度为0的匹配，将匹配置于一行的开始，并忽略任意的空格
\t\+ 匹配一个或多个制表符
```
匹配所有制表符：`:match errorMsg /[\t]/`

示例3：检查IP地址的有效性
```
match errorMsg /\(2[5][6-9]\|2[6-9][0-9]\|[3-9][0-9][0-9]\)[.]
\[0-9]\{1,3\}[.][0-9]\{1,3\}[.][0-9]\{1,3\}\|
\[0-9]\{1,3\}[.]\(2[5][6-9]\|2[6-9][0-9]\|\
\\ \[3-9][0-9][0-9]\)[.][0-9]\{1,3\}[.][0-9]
\\{1,3\}\|\[0-9]\{1,3\}[.][0-9]\{1,3\}[.]\(2[5]
\\ \[6-9]\|\2[6-9][0-9]|[3-9][0-9][0-9]\)[.][0-9]\{1,3\}
\\|[0-9]\{1,3\}[.][0-9]\{1,3\}[.][0-9]\{1,3\}[.]
\\(2[5][6-9]\|2[6-9][0-9]\|\[3-9][0-9][0-9]\)/
```

匹配有效的IP地址：
```
match todo
/\(\(25[0-5]\|2[0-4][0-9]\|[01]\?[0-9]
[0-9]\?\)\.\)
\\
\{3\}\(25[0-5]\|2[0-4][0-9]\|[01]\?
[0-9][0-9]\?\)/
```

5. 设置状态行
```
:set statusline format
```

6. 定制工作区
* 跟踪鼠标位置
```
显示行
:set cursorline

显示列
:set cursorcolumn
```

* 显示行号
```
:set number
:set nu

:xxx 调到xxx行
```

7. 常用按键映射
```
" save file (ctrl-s)
:map <C-s> :w<cr>
" copy selected text (ctrl-c)
:vmap <C-c> y
" Paste clipboard contents (ctrl-v)
:imap <C-p> <esc>P
" cut selected text (ctrl-x)
:vmap <C-x> x
```
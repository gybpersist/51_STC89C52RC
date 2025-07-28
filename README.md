# 51_STC89C52RC

## 更换Keil开发环境为VS Code
Keil编写代码没有变量提示、不会自动补全括号等，体验非常不友好，选择VS Code作为替代。

## VSCode软件安装

### EIDE插件安装
EIDE（Embedded IDE）插件用于提供单片机开发环境，借助该插件，我们可以在VSCode中实现单片机的开发、编译以及烧录等工作。在插件市场搜索“eide”，安装下图所示的插件。    

安装完成后，侧边栏便会出现该插件。

### EIDE插件使用
#### 创建项目
（1）点击新建项目

（2）选择空项目  

（3）选择8位MCU项目

（4）选择8051项目

（5）填写项目名称

（6）选择项目路径
选择Workspace即可，EIDE会自动为当前项目创建单独目录。

（7）项目创建完成后，切换到新项目

（8）切换之后会有如下错误提示，暂时忽略即可

#### 配置项目
由于EIDE需要承接代码的编辑、编译等一整套工作流程，所以我们需要为配置相应的工具链。  

1）编译相关配置  

（1）选择编译器
选择Keil中的C51 Compiler作为编译器，如果默认不是Keil_C51，可点击后边的按钮进行选择。

（2）为EIDE制定Keil安装目录
由于EIDE需要使用Keil中的C51 Compiler，所以需要为EIDE指定Keil的安装路径，具体操作如下图所示。
- ①点击设置工具链

- ②选择要配置的工具链
EIDE支持多种芯片的开发，所以可以为不同的芯片配置不同的工具链。我们目前所使用的是Keil C51，因此选择第一个进行设置。设置的内容为Keil程序的路径。

具体路径如下。

2）设置Include Path
将STC芯片的头文件添加到项目的Include Path，方便项目引用。具体操作步骤如下：
- （1）点击添加包含路径按钮

- （2）选择STC头文件所在目录


## VS Code 烧录配置
1. 安装 python 运行环境
2. 在 win+R cmd 命令行安装
```
pip install pyserial -i https://pypi.tuna.tsinghua.edu.cn/simple
```
```
pip install stcgal -i https://pypi.tuna.tsinghua.edu.cn/simple
```
4. 侧边栏上方，烧录配置，点击“切换烧录器”的符号，选择 stcgal


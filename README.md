# 51_STC89C52RC

## 更换Keil开发环境为VS Code
Keil编写代码没有变量提示、不会自动补全括号等，体验非常不友好，选择VS Code作为替代。

## VSCode软件安装

### EIDE插件安装
EIDE（Embedded IDE）插件用于提供单片机开发环境，借助该插件，我们可以在VSCode中实现单片机的开发、编译以及烧录等工作。在插件市场搜索“eide”，安装下图所示的插件。  
![图片1.png](https://img.picui.cn/free/2025/07/04/686731402d286.png)
安装完成后，侧边栏便会出现该插件。
![图片2.png](https://img.picui.cn/free/2025/07/04/6867343f3291b.png)
### EIDE插件使用
#### 创建项目
（1）点击新建项目
![图片3.png](https://img.picui.cn/free/2025/07/04/68673456c91dd.png)
（2）选择空项目  
![图片4.png](https://img.picui.cn/free/2025/07/04/68673458997db.png)
（3）选择8位MCU项目
![图片5.png](https://img.picui.cn/free/2025/07/04/6867345807bcb.png)
（4）选择8051项目
![图片6.png](https://img.picui.cn/free/2025/07/04/686734588ec80.png)
（5）填写项目名称
![图片7.png](https://img.picui.cn/free/2025/07/04/68673458d9ee8.png)
（6）选择项目路径
选择Workspace即可，EIDE会自动为当前项目创建单独目录。
![图片8.png](https://img.picui.cn/free/2025/07/04/6867345b0871d.png)
（7）项目创建完成后，切换到新项目
![图片9.png](https://img.picui.cn/free/2025/07/04/6867345cb2642.png)
（8）切换之后会有如下错误提示，暂时忽略即可
![图片10.png](https://img.picui.cn/free/2025/07/04/6867345db0cfe.png)
#### 配置项目
由于EIDE需要承接代码的编辑、编译等一整套工作流程，所以我们需要为配置相应的工具链。  

1）编译相关配置  

（1）选择编译器
选择Keil中的C51 Compiler作为编译器，如果默认不是Keil_C51，可点击后边的按钮进行选择。
![图片11.png](https://img.picui.cn/free/2025/07/04/6867345def7cf.png)
（2）为EIDE制定Keil安装目录
由于EIDE需要使用Keil中的C51 Compiler，所以需要为EIDE指定Keil的安装路径，具体操作如下图所示。
- ①点击设置工具链
![图片12.png](https://img.picui.cn/free/2025/07/04/6867345f95324.png)
- ②选择要配置的工具链
EIDE支持多种芯片的开发，所以可以为不同的芯片配置不同的工具链。我们目前所使用的是Keil C51，因此选择第一个进行设置。设置的内容为Keil程序的路径。
![图片13.png](https://img.picui.cn/free/2025/07/04/686734601c779.png)
具体路径如下。
![图片14.png](https://img.picui.cn/free/2025/07/04/68673461376cd.png)
2）设置Include Path
将STC芯片的头文件添加到项目的Include Path，方便项目引用。具体操作步骤如下：
- （1）点击添加包含路径按钮
![图片15.png](https://img.picui.cn/free/2025/07/04/686734624a6c0.png)
- （2）选择STC头文件所在目录
![图片16.png](https://img.picui.cn/free/2025/07/04/686734635af16.png)

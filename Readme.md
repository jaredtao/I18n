# Qt5.10 多语言动态翻译

[![Build Status](https://travis-ci.org/wentaojia2014/I18n.svg?branch=master)](https://travis-ci.org/wentaojia2014/I18n)
* 不需要重启程序 

![I18n](I18n.gif)
### 编译运行

qmake && make -j8 && ./I18n

或者使用qtcreator导入pro并运行

###  翻译步骤整理
1. qml 中使用qsTr 标记要翻译的文本

2. 在pro中添加翻译文件ts,例如：
```
TRANSLATIONS += I18n_zh.ts \
        I18n_en.ts
```
3. 使用lupdate （通过命令行，或者qtcreator->Tools->External->Linguist->lupdate），会在源码路径下生成ts文件

4. 使用linguist （Qt5.10.0/5.10.0/gcc_64/bin/linguist）导入ts文件，进行翻译

5. 使用lrelease，（通过命令行，qtcreator 或者 linguist）,生成qm文件。


ts文件是xml格式的文本，qm文件是对其压缩过的二进制格式。两者都可以使用linguist导入

6. qm文件放入运行路径，或者加入qrc资源

7. 使用QTranslator加载qm文件并安装到QCoreApplication


8. 在需要切换语言的地方，调用reTrans，并触发QQmlEngine::retranslate



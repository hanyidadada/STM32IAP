# 串口IAP测试
本项目主要实现通过串口完成代码下载并执行跳转，主文件夹IAP包含bootloader部分，子文件夹USART_IAPAPP则是串口回显app程序，可以编译生成bin文件并且串口下载后执行

## IAP
    1.编译下载到开发板
    2.按下KEY1可以进行app程序更新，先输入bin文件长度，再传输bin文件
    3.完成2后可以进行app程序跳转，按下KEY2就完成跳转执行

## USARTAPP
    该项目为串口回显以及串口控制LED灯，通过宏定义来选择编译部分。执行app时，可以通过KEY2来返回IAPbootloader部分
# 针对WUTE车队电动方程式赛车开发的多功能仪表 WUTE_Dashboard

本人负责设计开发的WUTE第一代多功能自制仪表（该项目也是2023自创项目“针对电动方程式赛车开发的车身电子监控与人机交互系统”的人机交互部分），该仪表基于STM32H7B0VET6，采用5寸TFT高亮屏(800nit)，使用LVGL图形库绘制GUI界面并实时刷新赛车监测数据，具体功能如下：

功能说明：
1. 实时采集整车跑动数据，并在屏幕上实时刷新显示
2. 具备屏幕亮度随环境光自动调节功能
3. 集成跑马灯功能
4. 支持与整车CAN通讯
5. 集成2.4G无线数传模块（ESP8266模块）
6. 集成激活按钮、待驶按钮以及TSOFF、BMS、IMD指示灯

# 设计说明

## 硬件说明

硬件设计方面，采用立创EDA开发，四层板设计

PCB设计展示：

![E33_Panel_3D.png](Hardware/E33_Panel_3D.png)

## 软件说明

开发平台：STM32H7B0VET6

开发环境：STM32cubeMX+Keil+VSCode

WUTE_Dashboard嵌入式软件分为Bootloader+App（为实现外部flash加载），App软件基于前后台的裸机系统开发，GUI采用LVGL图形库开发

App软件架构：基于CORE层+BSP层（+中间层LVGL）+APP层的架构开发

项目代码展示：

![E33_Panel_Firmware.png](Firmware/E33_Panel_Firmware.png)

## 模型设计

仪表外壳分为前板和后板，仪表驱动板和屏幕封装在模型内部，通过沉头螺栓和热熔螺母进行固定，前后板之间采用密封胶填充间隙

![WUTE_Dashboard_Model.bmp](Model/WUTE_Dashboard_Model.bmp)

## GUI设计

仪表板界面UI采用单界面设计，在单界面整合了包括高压电池（电压、电流、温度、电量）、电机控制器（温度）、电机（转速、温度、功率）、各车身设备工作状态、DRS和TCS开启状态，以及制动油压、加速开度、转矩千分比等信息

GUI设计界面：

![WUTE_Dashboard_GUI.png](WUTE_Dashboard_GUI.png)

# 测试

屏幕静态显示测试，屏幕可正常显示设计的UI界面：

![WUTE_Dashboard_Test.png](WUTE_Dashboard_Test.png)

屏幕动态刷新测试，仪表可正常解析CAN总线报文并将相关信息实时在屏幕和跑马灯上刷新：

![WUTE_Dashboard_Test_Video.gif](WUTE_Dashboard_Test_Video.gif)

# 项目成果

该仪表已顺利搭载在了WUTE车队2023赛季E33赛车和2024赛季E10赛车上并持续稳定运行，成为了赛车状况监测与可视化的重要途径，同时验证了其具备良好的抗振性与防水性

![WUTE_Dashboard_Racingcar.png](WUTE_Dashboard_Racingcar.png)


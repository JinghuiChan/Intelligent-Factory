# Arm_Jackal

五邑大学学习馆Mini智慧工厂

## 目录
### <a href="#1">1.Mini智慧工厂简介</a>
### <a href="#2">2.Mini智慧工厂网络配置</a>
### <a href="#3">3.Mini智慧工厂常见问题及解决方法</a>
### <a href="#4">4.Mini智慧工厂资料汇总</a>

<hr>
<br><br><br><br><br>

### <a id="1">1.Mini智慧工厂简介</a>
&nbsp;&nbsp;&nbsp;&nbsp;本系统由两台机械臂与一辆小车构成，其主要功能为全自动自主搬运货物。系统简单流程如下图所示。任务分配中心根据设置好的分配任务列表向小车发送消息(机械臂ID，货物ID，动作)；小车收到消息后向指定机械臂移动；在移动过程中只需要告知小车目标点即可，中间路径规划，躲避障碍物等动作小车自主作为决策，最终到达目标点，甚至转至指定角度；此时小车会通过TCP/IP协议与机械臂通信，告知机械臂抓/放货物；机械臂在收到命令后首先使用摄像头采集图片信息，利用计算机视觉相关知识识别并定位小车以及货物的位置，移动机械臂到达货物上方，打开机械爪抓起物体；完成以此抓放后小车会再次收到任务中心安排的下趟任务，小车又会自主移动至指定位置执行以上步骤 .

![Mini智慧工厂简介](https://github.com/JinghuiChan/Smart-Factory/blob/master/Pic/%E7%AE%80%E4%BB%8B.png)  

### <a id="2">2.Mini智慧工厂网络配置</a>


![Mini智慧工厂网络配置](https://github.com/JinghuiChan/Smart-Factory/blob/master/Pic/%E7%BD%91%E7%BB%9C%E9%85%8D%E7%BD%AE.png)

### <a id="3">3.Mini智慧工厂常见问题及解决方法</a>
* #### Ubuntu系统无法打开终端，或打开终端闪退，怎么办？
   - #### 解决方法：
   ```
   从文件夹 ~/ 中打开 .bashrc文档，将
   export LC_ALL=“C” 注释掉
   #export LC_ALL=“C” 
   然后重启电脑
   
   ```
  
* #### SSH远程连接至Jackal后在终端中无法补全命令，无法执行launch文件，且报如下绿色圆圈中的错误：  
   ![Ubuntu语言环境错误](https://github.com/JinghuiChan/Smart-Factory/blob/master/Pic/%E8%AF%AD%E8%A8%80%E7%8E%AF%E5%A2%83%E9%94%99%E8%AF%AF.jpg)  
   - #### 解决方法：
   
   ```shell script
      gedit ~/.bashrc 在文档顶部添加
      export LC_ALL="C"
      source ~/.bashrc
   ```


### <a id="4">4.Mini智慧工厂资料汇总</a>
* #### [智慧工厂源码地址](https://github.com/JinghuiChan/Smart-Factory)
* #### [智慧工厂操作手册](https://pan.baidu.com/s/18jfcN2WZpvsG_RaCaBAW4w)
* #### [Jackal小车硬件介绍](https://pan.baidu.com/s/1liKlBWl-v6j2zwpgwdpZAw)
* #### [Jackal小车基本使用](https://pan.baidu.com/s/1Ir6l1NsXGMpsDKLMsGs3Qg)
* #### [机械臂开发资料集](https://pan.baidu.com/s/11TC7MMhq3Lxt03hxlup9Rw)

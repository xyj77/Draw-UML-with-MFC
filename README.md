# Imitate-Visio-to-draw-class-diagram-of-MFC-implementation
模仿Visio绘制类图的MFC程序实现

## Introduction
UML类图编辑系统包含四个功能：图元的创建及对齐、图元的移动、图元的删除、图元的文字编辑

1 图元创建
> 点击工具栏中的图标，点击界面，在界面创建相应的图元并显示在鼠标点击的位置，当绘制多个图元之后可以通过Ctrl键选中多个图元，并可以采用多种对齐方式如顶端对齐、居中对齐、底端对齐、左对齐、右对齐等对选中的图元进行对齐。

2 图元移动
> 鼠标点击单个图元选中，并移动鼠标使其移动；按住ctrl键再点击图元进行选中多个图元，用鼠标拖动被选中的图元移动。图元移动的同时，与该图元相连的关系图元也能跟着移动。

3 图元删除
> 点击选中单个图元或按住Ctrl键选中多个图元，点击delete删除选中的图元，并且删除该选中图元相连的关系图元。

4 文字编辑
> 双击图元的某个位置调用相应的包含编辑控件的对话框；各图元均可添加名称（包名、类名、接口名、关系名）；类可添加属性和方法、接口添加方法，并且可以区分public、private和protected；关系图元两端可添加多重性（0、1、*）。


## Class Structure：

<div align="center">

<img align="center" width="600" src="https://github.com/xyj77/Imitate-Visio-to-draw-class-diagram-of-MFC-implementation/raw/master/figures/class.png">

</div>

## Example：

<div align="center">

<img align="center" width="600" src="https://github.com/xyj77/Imitate-Visio-to-draw-class-diagram-of-MFC-implementation/raw/master/figures/visio.png">

</div>
</br>
如上图所示，最左侧为绘制各类UML类图图元的工具栏选项，工具栏的具体图元从上往下依次为：  

   **类、接口、包、注释、继承关系、实现关系、依赖关系、聚合关系、组合关系**

### Usage
绘制类图：鼠标点击左侧工具栏的类图标在右侧空白位置单击绘制图元，单击类图类名一栏可以实现选中该类图；鼠标分别双击类名称栏、成员变量栏和成员函数栏会弹出相应对话框实现类名编辑、成员变量添加、成员函数添加。绘制接口、包、注释的步骤与绘制类图的步骤类似。

绘制关系：以绘制聚合关系为例，先点击左侧聚合关系图标，在右侧绘制一个聚合关系的线段，可以通过移动线段的起点和终点位置来连接类图；同样鼠标双击起点或者终点附近区域，会弹出对话框实现对起点终点聚合关系数目的设定。

## Acknowledgments
Thanks to my team members @wuleng & @y823621915

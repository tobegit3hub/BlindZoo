# BlindZoo ![MapEditor.ico](https://raw.github.com/tobegit3hub/BlindZoo/master/MapEditer.ico)

Windows command-line game and map editor.

## BlindZoo

BlindZoo首先是被设计为一个盲人游戏，但是如果没有相应音效和读屏软件它就无法吸引玩家。所以，它被超级改造为非盲人的体验游戏。而且，此程序的源代码很快将在互联网发布，所以没有专利保留。

游戏进程：现在你在动物园的入口（1,1），你要去找到并到达出口（8,8）。在路上，你应该会“看到”一些动物。那就尝试去触摸它们并且猜猜它们是什么动物，这会让你知道盲人的艰辛与乐趣。

1. 每次命令输入两个字符串，格式如“go 空格 east 回车”。常用命令如下：“go east”，“go south”，“go north”，“go west”，“touch head”，“touch body”，“touch more”等等。
2. 起点为（1,1），到达终点（8,8）则结束。
3. 在发现动物的地方可以“touch”各个部位如“head”,“neck”,“body”,“tail”,“more”,然后用“is”命令猜是什么动物。
4. 通过命令“kill myself”可快速退出游戏，注意命令都要区分大小写。
5. 地图信息是读取相同目录下的Map.txt文件得到的。
6. 内含多个隐藏的“crack”命令。
    
## MapEditer

1. 通过点击地图来设置墙或者路。
2. 可从菜单的Built A Map中选取算法来生成。
3. 可从菜单的Test中选取算法来测试是否连接。
4. 也可以打开相应的txt文件来读取。
5. 填满而且正确可以保存，自动生成Map.txt文件。
6. 修改后没有保存或者地图不正确都会提醒。

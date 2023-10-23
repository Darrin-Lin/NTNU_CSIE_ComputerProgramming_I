hw03
===

### 41247022S 林德恩

---

## How to build my code
在 HW03 directory 下 make 指令。

---

## header files

----

### mycircle.h

#### set_radius(double)
It will set the radius.
If input $\gt 0$, return 0.
If input $\le 0$, return -1.
If input is not reasonable first, seen as radius isn't set.
If input is not reasonable, but it had set, it will use the old value.

#### get_circle_circumference()

If the radius is not set return -1.
Otherwise, return the circumference.

#### get_circle_area()
If the radius is not set return -1.
Otherwise, return the area.

#### get_tangent_area(double)
If the radius is not set return -1. 
If input is not reasonable, return -2.
If cannot form a triangle, return -3.
Otherwise, return the tangent area ().

####  get_inner_regular_polygon_area(int32_t) / get_outer_regular_polygon_area(int32_t)
If the radius is not set return -1.
If $n \lt 3$, return -2.
Otherwise, return the inner / outer regular polygon area.

----

### mycontrol.h

#### initialize(double, double, double)
Set the position(x,y,radian).

#### forward(double)
Move forward length with your given direction.
If the position not set return -1.
Else return 0.

#### clock_turn(double)
Clock turn the given radian.
If the position not set return -1.
Else return 0.

#### counterclock_turn(double)
Counterclock turn the given radian.
If the position not set return -1.
Else return 0.

#### print()
It will print "position : (x,y), angle : a" in stdout.
If the position not set return -1.
Otherwise, return 0;

----

### hw0304.h

#### the_hanoi_tower(int32_t)
It will print the step of hanoi tower.
Please input the number of disk.
Because no DP so it just for int32_t.

----

### diceRolls.h

---

## log

----

### hw0301 

#### 10/20 開始寫
今天開始寫並創建了需要的檔案，然後把 mycircle.h 的 README 寫完。

#### 10/21 完成
今天把 function 寫完，也修了 Makefile。

#### 10/23 fix tangent
我發現我 tangent 那邊看錯要的東西，所以先求斜率再求點斜式。

----

### hw0302

#### 10/21 完成
今天把 function 寫完，並在要 print 之前用 fmod 把徑度設在 $0 \le radian \lt 2\pi$。

----

### hw0303 暫時解法
因為不能用 bitwise operator 也不能用 array 跟 loop，而且我也暫時想不到解法，所以先手刻一個位元運算。

----

### hw0304

#### 10/22 完成
因為不能用陣列，所以不能 DP，因此我只開 int32_t，因為還不用到上限計算時間就很久了，而我在執行的 objet file 又寫了一個 static function，我 iterative 是先寫 recursive 再去用它跑出來的值推要怎麼寫 iterative。

----

### hw0305
<!--要不要寫 hw0305 主程式-->
----

### hw0306

#### 10/22 完成
因為我之前就會一點 diff 了所以就是去查 patch 怎麼用，發現只要把 diff 匯出的檔案用 patch 匯入要改的原始檔就好了。

----

### hw0307
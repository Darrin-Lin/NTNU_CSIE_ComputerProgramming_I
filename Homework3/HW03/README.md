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

#### clock_turn(double)
Clock turn the given radian.
If the position not set return -1.

#### counterclock_turn(double)
Counterclock turn the given radian.
If the position not set return -1.

#### print()
It will print "position : (x,y), angle : a" in stdout.
If the position not set return -1.
Otherwise, return 0;

----

### hw0304.h



----

### diceRolls.h

---

## log

----

### hw0301 

#### 10/20 開始寫
今天開始寫並創建了需要的檔案，然後把 mycircle.h 的 README 寫完。

### 10/21 完成
今天把 function 寫完，也修了 Makefile。

----

### hw0302

#### 10/21 完成
今天把 function 寫完，並在要 print 之前用 fmod 把徑度設在 $0 \le radian \lt 2\pi$。

----

### hw0303


----

### hw0304

----

### hw0305
<!--makefile有問題-->
----

### hw0306

----

### hw0307
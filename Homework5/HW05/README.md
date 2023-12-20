hw05
===

### 41247022S 林德恩

---

## How to build my code
在 HW05 directory 下 make 指令。

---

## log

---

### hw0501

#### 12/1 Finish
快速的把第一題寫好了，還沒測。

----

### hw0502

#### 12/1 Finish
不知道當無解或多組解要把 vector x 怎麼處理，所以寫信去問，也不確定 calloc 可不可以用，所以先寫好了，等回信再改。
助教回信了說 多組解把 pointer 設為 NULL
然後又在計算過程中用 double 避免誤差擴大。

#### 12/4 Debug
把 NULL 化後忘了 free 補上。

#### 12/7 Debug
處理複數問題。

----

### hw0503

#### 12/1 Finish
no such a plane 不知道跟 inputs are invalid 有什麼差別，所以之後再改。

#### 12/3 Update
助教回信了，說需要在回傳時四捨五入到小數點第二位。

#### 12/6 Update
發現是要去求圓面積，更改。

#### 12/7 Update
平面不成立是當係數都為 0

#### 12/8 Update
助教發公告了，不成平面是 -1 沒交叉面積是 0，不知道相切要回傳 1 or 0。助教回信了，是 return 0。

----

### hw0504

#### 12/2 Finish
不確定 skip 會有 value 跟 length 以及 length 計算方式還有 print 格式。

#### 12/4 Edit
助教回信了，說就把 length 當成 uint16_t 解釋，skip 也要算 length，print 只要 print 數字（可換行）
invald input 是包含未 set/init 第一歩用 cancel。
問題現在出在 cancel 掉第一個 init 再進行運算的 invalid input 不知道怎處理，應該用最初的值設為 -1 就行了。

#### 12/6 Update
不知道會不會有溢位問題還有 cancel 再 cancel 的問題。
然後也會有 cancel print 的問題。
老師保證一定會再 uint64_t 範圍內，所以不用擔心溢位問題。
cancel 也問助教，會有這個問題，所以我改了一下。

#### 12/15 Update
改了 `printf` 成 `%lu`

#### 12/17 Update
修了 type = 6, number = 0 要 * 10 的問題跟 type = 7, value = 0 要 * 10 的問題，還有過程中 value 要用 `uint64_t` 存的問題。

#### 12/17 Update
更新了 type 7 length 的問題。

#### 12/20 Update
更新了 NULL 的問題。

----

### hw0505

#### 12/2 Finish
不知道 decode.c 要怎麼用，先寫完其他部分並寫信問助教了。

####　12/3 Update
助教回信了，說 decode.c 只要在 Makefile 連結就好，~~然後 free 那邊有問題~~ realloc 會自動釋放。

#### 12/20 Update
更新了 NULL 的問題。

----

### hw0506

#### 12/1 Finish
寫完了。
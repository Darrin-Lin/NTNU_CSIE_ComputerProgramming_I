hw02
===

### 41247022S 林德恩

---

## How to build my code
在 HW02 directory 下 make 指令。

---

## [hw0201](./hw0201/)

### 10/6 完成
先用數學推出每一個的算法使得複雜度 = O(n)，公式如下：第 $n$ 個數 $c_n\over m_n$ 是 ，第 $n$ 是 $2c_{n-1} + c_{n-2}\over 2m_{n-1} + m_{n-2}$，所以複雜度為 $O(n)$，就不用一個一個算變成 $O(n!)$。
但在寫的時候又遇到 `double` 不準的問題 $7\over 5$ 會是 $1.39999999999999991118$

### 10/7 加上例外處理
因為不知道會不會有 $n \lt 0$ 的情況，所以就加上例外處理。
今天助教回答了說 `double` 誤差可接受，但也有方法可以全域解決，但我先放著。

### 10/10 公式有問題
因為在對測資時發現好像是會在 $n$ 極大時溢位，已經用 64bit 的 unsigned 也會，而改用 `double` 則是最後會變 `nan`，所以最後還是用一般解。

### 10/11 修改輸出
先把變數改成 `long double`，然後再因更新輸出規範所以把輸出改成 `%.15Lf`。

---

## [hw0202](./hw0202/)

### 10/5 完成
今天開始寫 hw0202，先寫計算位數的 function 跟在進行輸出時位數分離的 $10^n$ function，再把輸入跟計算結果處理好，然後再處理中間計算過程，後來又修了 second number $\lt 10$ 的狀況。

---

## [hw0203](./hw0203/)

### 10/7 完成
這題我第一個想到的解法是遞迴，但不知道能不能用，而且目前沒想到能不用陣列的解法，我後來想到可以先執行判斷要跑哪些狀態，再將狀態附加上去，最後再 print 出來，並再 print 前確定是不是第一個 print 的狀態，如果不是就加一個 `", "`。  
然後我不確定負數算不算奇偶數，先把負的奇數跟偶數當作是。

---

## [hw0204](./hw0204/)

### 10/7 完成
今天開始寫 hw0204，但是不知道 input 的範圍，所以就先設都是 `int64_t` 然後也不知道輸出目前金錢的值跟每月獲利要輸出到第幾位，都預設輸出到小數點下兩位。  
然後投資報酬率輸出時它都會自動四捨五入，所以也不確定要不要再手動進行修正。  
在用測資的時候發現當存入金額都為 0 時，會出現 `nan`，所以就加上例外處理。

### 10/9 修改報錯訊息
因為公布了輸入的範圍，所以就把 `int64_t` 改成 `int32_t`，又刪了存入為 0 的狀況，最後修了輸入範圍的報錯，就等剩下輸出範圍的公布了，還有之後要多加測資。
修改了輸出範圍，並因為是存在 `double` 不用考慮數字會在小於 $10^{15}$ 就溢位，然後其實本金的例外除=處理可以部用做，因為最大值不會超過 $10^{15}$，在輸出時也運用了 `%f` 的特性，如果是 `%.0f` 會自動四捨五入，然後其他值要無條件捨去地為了避免錯誤就都加了 $1E-9$ 來使它們小於所要的數會自動進位成實際值。

### 10/10 修改輸出
因為看到對於輸出有要求，所以又改了投資報酬率的輸出，預設是小數點後兩位，然後如果那位是零就變成輸出前一位，還有看到是累積淨收入，所以又改了程式。

### 10/11 修改
因為淨利寫成了 `+=` 所以改成 `=`，然後今天問助教錯誤訊息輸出方式，助教說都可以，所以我就在輸入時就及時報錯並停止程式。

### 10/14 修改自動四捨五入
因為在輸出小數點後第二位的數值不會無條捨去，所以我就將會四捨五入的數字減 $0.005$。

### 10/15 修改四捨五入
因為我看錯看成要無條件捨去，但是要先四捨五入，所我就先處理要四捨五入的數字把它們扣掉 $5E-3$，然後再進位，之後再處理輸出。

---

## hw0205

### 10/8 開始
今天開始寫 hw0205 先進行例外處理，然後去算了各個橫線的條件，並把圖形分為上下部、$N$ 是奇偶數、是否為碰到底的那些線，然後先把斜線放著，先去計算圖形直線的部分之規律，也把起始值設為 1 還有從後面數來的數字來方便處理下半部圖形。  

那些碰到邊的 row 會出現在第 $N\times (L-1)$ 行到倒數第 $N\times (L-1)$ 行，而在 N 為奇數時會剛好在正中間，所以在輸出中間沒碰到邊的橫線就不用考慮，但偶數要，但其實先考慮碰到邊的就可以不用額外設條件。  
那些剩下的橫線在 $L$ 為奇數時對 $L-1$ 取餘數會是 1，在偶數則是 $L$，而前面的空白格數會是 $(L - 1) \times ((2 \times N - 1) - 2 \times ({row} \div (L - 1)))$，但在 ${row} \div (L - 1) \gt N$ 都是一樣長度，所以就要加一個條件來判斷，下半部的就用倒數的行數來算。

### 10/9 完成
斜線的部分一直寫錯，不停修終於把它搞好了，果然還是要自己在旁邊用筆去畫圖來對坐標並計算比較好寫。

### 10/12 Error Message 更新
今天把 Error Message 更新到等輸入完畢再輸出。 

---

## [hw0206](./hw0206.txt/)

### 10/6 完成
先根據自己的知識猜，再去翻 C11 的說明。
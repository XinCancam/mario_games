# 2025 OOPL Final Report

## 組別資訊

組別：40組
組員：林信頤 胡育鈞
復刻遊戲：超級馬力歐兄弟

## 專案簡介
### 遊戲簡介
我們這一組的遊戲關卡總共三關，三關都是自創的地圖。遊戲中，將會有怪物試圖阻止你通關的去路，你可以透過精湛的移動技巧或者吃花朵獲取技能去躲過或殺死它們。
### 組別分工
胡育鈞: 地圖物件製作與載入
林信頤: 人物、怪物與地圖物件的互動
## 遊戲介紹
### 遊戲規則
透過WASD去控制人物穿越障礙和怪物到達終點
P鍵可開關作弊模式(在牆內關閉作弊模式可能會導致人物錯位)
U鍵可發射火球(前提是馬力歐在火焰狀態)
R鍵可從起始畫面進入到第一關
### 遊戲畫面
![image](https://github.com/XinCancam/mario_games/blob/main/picture/image-1.png)
![image](https://github.com/XinCancam/mario_games/blob/main/picture/image-2.png)
![image](https://github.com/XinCancam/mario_games/blob/main/picture/image-3.png)
![image](https://github.com/XinCancam/mario_games/blob/main/picture/image-4.png)
![image](https://github.com/XinCancam/mario_games/blob/main/picture/image-5.png)
## 程式設計
### 程式架構
AppStart.cpp：遊戲開始畫面邏輯。
Appone.cpp / Apptwo.cpp / Appzero.cpp：可能代表第 0 關、第 1 關、第 2 關。
Appgameover.cpp：玩家失敗後的畫面處理。
Appwin.cpp：遊戲勝利後的畫面處理。
AppUpdate.cpp：主遊戲邏輯的狀態更新，遊戲循環的更新。
### 程式技術
封裝、繼承、
## 結語
透過這個架構即可完成超級馬力歐兄弟。其實還有許多可添加的細節的地方。
### 問題與解決方法
最常遇到的問題是有指標跑到NULL_Ptr導致程式崩潰。解決方法是用debug去看程式停在哪一行，或是看自己最近更改的指標有無跑到NULL_Ptr。
### 自評
| 項次 | 項目                   | 完成 |
|------|------------------------|-------|
| 1    | 這是範例 |  V  |
| 2    | 完成專案權限改為 public |  V  |
| 3    | 具有 debug mode 的功能  |  V  |
| 4    | 解決專案上所有 Memory Leak 的問題  |  V  |
| 5    | 報告中沒有任何錯字，以及沒有任何一項遺漏  |  V  |
| 6    | 報告至少保持基本的美感，人類可讀  |  V  |

### 心得
此次專案我們一致認為難度不算高，製作過程中還是挺放鬆的。這種一步一步完成專案的方式也能給予我很大的成就感。花費最多時間的大概是刻地圖和一開始碰撞箱檢測，也是這遊戲最重要的兩樣東西。我認為此次專案的缺點是沒有做好架構規劃，不能很整齊的分類，如果專案是中型專案的話大概會出事。這是我認為可以改進的地方。
### 貢獻比例
胡育鈞:50%
林信頤:50%
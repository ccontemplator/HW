# HW1
use command python3 hw1.py in terminal and it'll show the output
the result will be the same pattern as the sample output

the output will be:
[['C0A880', 1018.2818181818182], ['COF9A0', 'None'], ['C0G640', 1016.5083333333333], ['C0R190', 1011.6041666666666], ['C0X260', 1011.8875]]

# HW2
output voltage: 
  by using two for loops each takes 7/10 and 3/10 of period respectively 
  we'll see a 7:3 triangular wave over there 
 
Three buttons b0,b1,b2 each respectively means increase,decrease,and comfirm the weight which can influence the generated wave frequency .

open a thread to start sampling function which constantly sampling from ain(wave after rc filter) at specific rates.

# HW3
首先初始化及連線m至網路（ssid :2F WIFI)
Enter後顯示有哪些RPC function可使用

接著執行gesture_ui 這個rpc function 
這個function 會先讓板子亮一下燈，表示可以開始以手勢選擇threshold angle(每個手勢對應一個threshold angle,分別為30、35、40,譬如ring手勢對應的angle為30)

選擇會不斷改變直到我按下userbutton後，將publish 我剛剛最後選擇的threshold angle到mqttbroker，而python可以看到在左邊的部分會註冊同一個topic，python收到剛剛publish 的threshold angle後,會傳送一個stop_gesture_ui的rpc function ,
 這會終止gestur_ui.

下一步是angle_detection 這個rpc function 會先閃燈表示開始測量reference vector.
測量完後等待約1秒鐘開始測量與reference vector 呈大於 threshold angle的角度 ，如果大於threshold angle則publish，總共10筆大於threshold angle 的數據，這十筆角度最後會在python code一起印出來，同時ulcd上也會有這十筆數據。


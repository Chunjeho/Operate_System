# Avoid Detector

## Problem  
맵이 주어지고 셀에는 센서가 있는 경우 0으로 표시되어 있다.

A map is givien, and 0 is representing a detector sensor.


센서가 있는 상하좌우대각선 8개의 인접한 셀을 지나가는 경우 센서가 켜진다.

Whenever you pass up, down, left, right, diagonal 8 blocks surrounded in sensor, sensor will be exert.
 
 
센서를 켜지 않고 맵의 가장 왼쪽 열에서 가장 오른쪽 열까지 이동하는 최단 경로의 길이를 구하시오.

Find a length of a shortest path moving left-end to right-end without exerting sensor.


(상하좌우 4 방향으로 이동할 수 있고, 시작과 끝의 행의 위치는 어느 곳이든 상관 없음)

(You can move up, down, left, right; column of start-point and end-point doesn't matter)

### Input:  
  
[0, 1, 1, 1, 0, 1, 1, 1, 1, 1]

[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

[1, 1, 1, 1, 1, 1, 1, 1, 0, 1]

[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

[1, 1, 1, 1, 1, 0, 1, 1, 1, 1]

[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

[1, 0, 1, 1, 1, 1, 1, 1, 1, 1]

[1, 1, 1, 1, 1, 1, 1, 1, 1, 0]

[1, 1, 1, 1, 1, 0, 1, 1, 1, 1]

[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
  
### Output:  
 
11
 
## Problems from here
https://mailprogramming.com/ 

# [Platinum V] Circular Barn Revisited - 11994 

[문제 링크](https://www.acmicpc.net/problem/11994) 

### 성능 요약

메모리: 2156 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 4월 18일 15:19:26

### 문제 설명

<p>After the last debacle involving Farmer John's circular barn, one would think he had learned his lesson about non-traditional architecture. However, he thinks he can still make his circular barn (from the preceding problem) function properly by allowing multiple cows into each room. To recap, the barn consists of a ring of \(n\) rooms, numbered clockwise from \(1 \ldots n\) around the perimeter of the barn (\(3 \leq n \leq 100\)). Each room has doors to its two neighboring rooms, and also a door opening to the exterior of the barn.</p>

<p>Farmer John wants exactly \(r_i\) cows to end up in room \(i\) (\(1 \leq r_i \leq 1,000,000\)). To herd the cows into the barn in an orderly fashion, he plans to unlock \(k\) exterior doors (\(1 \leq k \leq 7\)), allowing the cows to enter through only those doors. Each cow then walks clockwise through the rooms until she reaches a suitable destination. Farmer John wants to unlock the exterior doors that will cause his cows to collectively walk a minimum total amount of distance after entering the barn (they can initially line up however they like outside the \(k\) unlocked doors; this does not contribute to the total distance in question). Please determine the minimum total distance his cows will need to walk, if he chooses the best \(k\) such doors to unlock.</p>

### 입력 

 <p>The first line of input contains \(n\) and \(k\). Each of the remaining \(n\) lines contain \(r_1 \ldots r_n\).</p>

### 출력 

 <p>Please write out the minimum amount of distance the cows need to travel.</p>


# [Platinum V] 전시회 - 15554 

[문제 링크](https://www.acmicpc.net/problem/15554) 

### 성능 요약

메모리: 13748 KB, 시간: 196 ms

### 분류

그리디 알고리즘, 정렬, 누적 합

### 제출 일자

2024년 7월 4일 20:36:38

### 문제 설명

<p>An art exhibition will be held in Republic of JOI. Many artworks from all over the country will be displayed in the art exhibition.</p>

<p>There are N artworks which are candidates for the exhibition. The artworks are numbered from 1 to N. Two integers are defined for each artwork: its size and its value. The size of the artwork i (1 ≤ i ≤ N) is A<sub>i</sub>, and the value of the artwork i is B<sub>i</sub>.</p>

<p>In the art exhibition, at least one artwork will be chosen and displayed. Since the exhibition hall is large enough, it is possible to display all of the N artworks. However, due to the aesthetic sense of people in Republic of JOI, we want to choose artworks for the exhibition so that the difference between the sizes of the displayed artworks is not too large. On the other hand, we want to display many artworks with large value. We decided to choose the artworks for the exhibition by the following rule:</p>

<ul>
	<li>Among chosen artworks for the exhibition, let A<sub>max</sub> be the largest size of the chosen artworks, and A<sub>min</sub> be the smallest size of the chosen artworks. Let S be the total value of the chosen artworks.</li>
	<li>Then, we want to maximize S − (A<sub>max</sub> − A<sub>min</sub>).</li>
</ul>

<p>Given the number of candidates of artworks for the exhibition, and the size and the value of each artwork, write a program which calculates the maximum of S − (A<sub>max</sub> − A<sub>min</sub>).</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<ul>
	<li>The first line contains an integer N, the number of candidates of artworks for the exhibition.</li>
	<li>The i-th line (1 ≤ i ≤ N) of the following N lines contains two space separated integers A<sub>i</sub>, B<sub>i</sub>. This means the size of the artwork i is A<sub>i</sub>, and the value of the artwork i is B<sub>i</sub>.</li>
</ul>

### 출력 

 <p>Write one line to the standard output. The output should contain the maximum of S − (A<sub>max</sub> − A<sub>min</sub>).</p>


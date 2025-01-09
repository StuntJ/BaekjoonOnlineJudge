# [Gold III] Military Recruit - 7539 

[문제 링크](https://www.acmicpc.net/problem/7539) 

### 성능 요약

메모리: 2316 KB, 시간: 8 ms

### 분류

플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2025년 1월 9일 15:21:05

### 문제 설명

<p>Tom is a military recruit for an elite army unit. As the last part of his final exams, he will be put into unknown terrain and has to find his way to a designated exit point, carrying all his heavy military gear.</p>

<p>As Tom is a little bit afraid of this task, he has used Google Maps to obtain satellite images of the training area. He has identified all the possible entry and exit spots and possible connections with their estimated length. This relation between sites does not need to be symmetric due to different terrain heights.</p>

<p>However, he does not know, from which site to which site he will have to march. Unfortunately, he quickly realizes that he won’t be able to successfully perform the march in the worst-case of the two sites that have the maximum distance to each other, no matter how hard he practices.</p>

<p>Common sense tells him that his instructors will always pick distinct sites for the entry and exit sites, and he assumes that every pair of distinct sites has equal probability to become his task.</p>

<p>Given a set of sites, possible connections between some of the sites together with their length and Tom’s desired success probability p, you are to compute the minimum distance Tom must be comfortable with so that he will pass his exam with at least probability p, assuming that every pair of distinct sites is equally likely.</p>

### 입력 

 <p>The first line contains the number of scenarios.</p>

<p>The next line contains an integer p (1 ≤ p ≤ 100) specifying Tom’s minimum success probability. Then follows a line with the number of sites n (2 ≤ n ≤ 100). The subsequent n lines contain n integers each, separated by a space. The i-th line contains the distances from site i to all other sites, e.g. the distance from site i to site j can be found in the i-th line at position j. Distances are non-negative integers less than 1000. The distance from a site to itself will always be zero. If the distance between two sites is “-1” there is no direct connection between those sites in the corresponding direction. You can assume that every site can be reached somehow from every other site.</p>

### 출력 

 <p>The output for every scenario begins with a line containing “Scenario #i:”, where i is the number of the scenario starting at 1.</p>

<p>Then print a single line with the minimum distance Tom has to practice for followed by an empty line.</p>


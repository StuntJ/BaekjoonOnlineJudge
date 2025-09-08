# [Silver I] 사막에서 선배찾기 - 34197 

[문제 링크](https://www.acmicpc.net/problem/34197) 

### 성능 요약

메모리: 13676 KB, 시간: 12 ms

### 분류

구현, 브루트포스 알고리즘, 많은 조건 분기

### 제출 일자

2025년 9월 8일 20:46:25

### 문제 설명

<p><strong>이 문제는 인터랙티브 문제입니다.</strong></p>

<blockquote>
<p>???: 여기 있었군요. 정말이지, 한참 찾았잖아요. 선배.</p>
</blockquote>

<p>연세대학교를 졸업한 국렬이는 고대 이집트의 아비도스 신전을 관광하던 중, 나침반 없이 사막을 횡단하다가 행방불명이 되고 말았다. 소식을 들은 후배 태윤이는 국렬이를 찾기 위해 즉시 이집트로 향했다.</p>

<p>사막은 한 변의 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>인 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times N$</span></mjx-container> 크기의 격자로 구성되어 있으며, 사막의 좌우와 상하가 서로 연결된 형태이다. 즉, 거주지에서 상하좌우 어느 한 방향으로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>칸 움직이면 거주지로 돌아오게 된다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>14</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5 \le N \le 14$</span></mjx-container>)</p>

<p>태윤이는 현재 사막 어딘가에 위치한 거주지에 머무르고 있다. 거주지는 정확히 한 칸을 차지하고 있다. 국렬이는 거주지가 아닌 다른 칸에 위치하고 있으며, 현재 기절한 상태이기에 태윤이가 찾기 전까지는 움직이지 못한다.</p>

<p>사막에서는 인터넷 연결이 불가능해 태윤이는 국렬이 및 자신이 위치한 좌표 및 거주지의 좌표, 심지어 사막의 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>도 알지 못한다.</p>

<p>다만, 태윤이는 자신 주변의 정보를 탐지하는 장치를 가지고 있다. 이 탐지기는 태윤이의 현재 위치를 중심으로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>×</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 \times 3$</span></mjx-container> 영역에 대해 각 칸에 대한 정보를 제공한다.</p>

<p>상하좌우로 인접한 칸으로 이동할 때마다 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>분이 소요되며, 이동할 때마다 탐지기를 사용하여 주변 칸의 정보를 얻는다. 단, 대각선으로는 한 번에 이동할 수 없다.</p>

<p>태윤이가 국렬이가 위치한 칸에 도착하면 기절한 국렬이를 즉시 깨우고 국렬이는 태윤이와 동행 상태가 된다. 국렬이를 깨우는데 걸리는 시간은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>분으로 간주한다. 국렬이를 발견한 뒤에도 이동 시간은 동일하게 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>분이다.</p>

<p>태윤이는 총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>240</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$240$</span></mjx-container>분 내에 국렬이를 찾아 거주지로 돌아와야 한다. 제한 시간 내에 태윤이가 국렬이를 무사히 구출할 수 있도록 도와주자.</p>

### 입력 

 <p>초기 입력으로 태윤이가 위치한 거주지를 중심으로 한 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>×</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 \times 3$</span></mjx-container> 영역의 정보가 세 줄에 걸쳐 주어진다. 각 줄은 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3$</span></mjx-container>의 문자열로 구성되어 있으며, 아래의 문자로 표기된다.</p>

<ul>
	<li><code><span style="color:#e74c3c;">.</span></code>: 빈칸</li>
	<li><span style="color:#e74c3c;"><code>R</code></span>: 거주지</li>
	<li><span style="color:#e74c3c;"><code>G</code></span>: 국렬이의 위치</li>
</ul>

### 출력 

 <p>다음 중 하나를 표준 출력 스트림(stdout)으로 한 줄에 출력한다.</p>

<ul>
	<li><code><span style="color:#e74c3c;">?</span></code> <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>D</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$D$</span></mjx-container> : 태윤이는 방향 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>D</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$D$</span></mjx-container>로 한 칸 이동한다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>D</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$D$</span></mjx-container>는 <span style="color:#e74c3c;"><code>U</code></span>(위), <span style="color:#e74c3c;"><code>D</code></span>(아래), <span style="color:#e74c3c;"><code>L</code></span>(왼쪽), <span style="color:#e74c3c;"><code>R</code></span>(오른쪽) 중 하나이며, 이동 후 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>분이 흐른다.</li>
	<li><span style="color:#e74c3c;"><code>!</code></span> : 태윤이는 국렬이를 구출하고 난 뒤 거주지로 복귀했음을 알린다. 이 명령을 출력한 후 시간은 흐르지 않는다.</li>
</ul>

<p>태윤이가 인접한 칸으로 이동했다면, 해당 칸을 중심으로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>×</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 \times 3$</span></mjx-container> 영역에 대해 각 칸에 대한 정보를 제공한다. 단, 태윤이가 국렬이를 찾고 동행중일 때는 국렬이의 위치 정보는 제공되지 않는다.</p>

<p>만약 이동 횟수가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>240</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$240$</span></mjx-container>회를 초과하거나, 국렬이를 구출하지 않았거나, 거주지로 돌아오지 않는 상태에서 완료 명령을 출력한 경우 <span style="color:#c0392b;"><strong>틀렸습니다</strong></span>를 받는다.</p>

<p>각 질문을 출력한 후에는 반드시 표준 출력 버퍼를 flush해 주어야 하고, 표준 입력 스트림(stdin)을 통해 질문에 대한 답을 입력받아야 한다. 질문에 대한 답을 입력받지 않으면 <strong><span style="color:#4e5f70;">런타임 에러</span></strong>를 받게 된다.</p>

<p>언어별로 표준 출력 버퍼를 flush하는 방법은 다음과 같다. 기타 언어의 경우 각 언어의 문서를 참조하라.</p>

<ul>
	<li>C: <code>fflush(stdout)</code></li>
	<li>C++: <code>std::cout << std::flush</code></li>
	<li>Java: <code>System.out.flush()</code></li>
	<li>Python: <code>sys.stdout.flush()</code></li>
</ul>


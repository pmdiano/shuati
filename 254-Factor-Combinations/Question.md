# 254. Factor Combinations

[Original Page](https://leetcode.com/problems/factor-combinations/)

Numbers can be regarded as product of its factors. For example,

<pre>8 = 2 x 2 x 2;
  = 2 x 4.
</pre>

Write a function that takes an integer _n_ and return all possible combinations of its factors.

**Note:**  

1.  You may assume that _n_ is always positive.
2.  Factors should be greater than 1 and less than _n_.

**Examples:**  
input: `1`  
output:  

<pre>[]
</pre>

input: `37`  
output:  

<pre>[]
</pre>

input: `12`  
output:  

<pre>[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
</pre>

input: `32`  
output:  

<pre>[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
</pre>

<div>

<div id="company_tags" class="btn btn-xs btn-warning">Show Company Tags</div>

<span class="hidebutton">[LinkedIn](/company/linkedin/) [Uber](/company/uber/)</span></div>

<div>

<div id="tags" class="btn btn-xs btn-warning">Show Tags</div>

<span class="hidebutton">[Backtracking](/tag/backtracking/)</span></div>

<div>

<div id="similar" class="btn btn-xs btn-warning">Show Similar Problems</div>

<span class="hidebutton">[(M) Combination Sum](/problems/combination-sum/)</span></div>
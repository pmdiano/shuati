# 296. Best Meeting Point

[Original Page](https://leetcode.com/problems/best-meeting-point/)

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using [Manhattan Distance](http://en.wikipedia.org/wiki/Taxicab_geometry), where distance(p1, p2) = `|p2.x - p1.x| + |p2.y - p1.y|`.

For example, given three people living at `(0,0)`, `(0,4)`, and `(2,2)`:

<pre>1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0</pre>

The point `(0,2)` is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

**Hint:**

[Show Hint](#)

1.  Try to solve it in one dimension first. How can this solution apply to the two dimension case?

<div>

<div id="company_tags" class="btn btn-xs btn-warning">Show Company Tags</div>

<span class="hidebutton" style="display: none;">[Twitter](/company/twitter/)</span></div>

<div>

<div id="tags" class="btn btn-xs btn-warning">Show Tags</div>

<span class="hidebutton" style="display: none;">[Math](/tag/math/) [Sort](/tag/sort/)</span></div>

<div>

<div id="similar" class="btn btn-xs btn-warning">Show Similar Problems</div>

<span class="hidebutton">[(H) Shortest Distance from All Buildings](/problems/shortest-distance-from-all-buildings/)</span></div>
# 401. Binary Watch

[Original Page](https://leetcode.com/problems/binary-watch/)

A binary watch has 4 LEDs on the top which represent the **hours** (**0-11**), and the 6 LEDs on the bottom represent the **minutes** (**0-59**).

Each LED represents a zero or one, with the least significant bit on the right.

![](https://upload.wikimedia.org/wikipedia/commons/8/8b/Binary_clock_samui_moon.jpg)

For example, the above binary watch reads "3:25".

Given a non-negative integer _n_ which represents the number of LEDs that are currently on, return all possible times the watch could represent.

**Example:**

<pre>Input: n = 1  
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]</pre>

**Note:**  

*   The order of output does not matter.
*   The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
*   The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

<div>

<div id="company_tags" class="btn btn-xs btn-warning">Show Company Tags</div>

<span class="hidebutton">[Google](/company/google/)</span></div>

<div>

<div id="tags" class="btn btn-xs btn-warning">Show Tags</div>

<span class="hidebutton">[Backtracking](/tag/backtracking/) [Bit Manipulation](/tag/bit-manipulation/)</span></div>

<div>

<div id="similar" class="btn btn-xs btn-warning">Show Similar Problems</div>

<span class="hidebutton">[(M) Letter Combinations of a Phone Number](/problems/letter-combinations-of-a-phone-number/) [(E) Number of 1 Bits](/problems/number-of-1-bits/)</span></div>
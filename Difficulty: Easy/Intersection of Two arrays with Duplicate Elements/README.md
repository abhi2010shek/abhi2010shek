<h2><a href="https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1">Intersection of Two arrays with Duplicate Elements</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;"><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">Given two integer</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">&nbsp;</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">arrays</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">&nbsp;</span><span style="box-sizing: border-box; font-weight: bolder; line-height: 1.7em; color: var(--text-color) !important; font-family: var(--gfg-font-secondary) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">a[]</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">&nbsp;</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">and</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">&nbsp;</span><span style="box-sizing: border-box; font-weight: bolder; line-height: 1.7em; color: var(--text-color) !important; font-family: var(--gfg-font-secondary) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">b[]</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">, you have to find</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">&nbsp;the</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">&nbsp;</span><span style="box-sizing: border-box; font-weight: bolder; line-height: 1.7em; color: var(--text-color) !important; font-family: var(--gfg-font-secondary) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">intersection</span><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color=""> of the two arrays. </span></span><span style="font-size: 14pt;"><span style="color: var(--text-color); font-family: var(--gfg-font-primary); --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not have duplicate elements and the result should contain items in any order.</span></span></p>
<p><span style="box-sizing: border-box; line-height: 1.7em; font-size: 14pt; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">Note:<strong>&nbsp;</strong>The driver code will sort the resulting array in increasing order before printing.</span></p>
<p><span style="font-size: 14pt;"><strong><span style="box-sizing: border-box; line-height: 1.7em; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">Examples:</span></strong></span></p>
<pre><span style="font-size: 14pt;"><strong><span style="box-sizing: border-box; line-height: 1.7em; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">Input: </span></strong><span style="box-sizing: border-box; line-height: 1.7em; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]<br><strong>Output: </strong>[1, 3]<br><strong>Explanation: </strong>1 and 3 are the only common elements and we need to print only one occurrence of common elements.<br></span></span></pre>
<pre><span style="box-sizing: border-box; line-height: 1.7em; font-size: 14pt; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color=""><strong>Input: </strong>a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]<br><strong>Output: </strong>[1]<br><strong>Explanation: </strong>1 is the only common element present in both the arrays.<br></span></pre>
<pre><span style="box-sizing: border-box; line-height: 1.7em; font-size: 14pt; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color=""><strong>Input: </strong>a[] = [1, 2, 3], b[] = [4, 5, 6]<br><strong>Output: </strong>[]<br><strong>Explanation: </strong>No common element in both the arrays.</span></pre>
<p><span style="font-size: 14pt;"><span style="box-sizing: border-box; line-height: 1.7em; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color=""><strong>Constraints:</strong><br style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; white-space: normal;">1 ≤ a.size(), b.size() ≤ 10<sup>5<br></sup></span><span style="box-sizing: border-box; line-height: 1.7em; font-family: var(--gfg-font-primary) !important; color: var(--text-color) !important; --darkreader-inline-color: var(--darkreader-text--text-color, #e8e6e3);" data-darkreader-inline-color="">1 ≤ a[i], b[i] ≤ 10<sup>5</sup><br></span></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Sorting</code>&nbsp;<code>two-pointer-algorithm</code>&nbsp;<code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;
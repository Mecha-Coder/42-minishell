

/* >>> exp_wild
Purpose: 
- Match wildcard pattern against files/folders in the current dir.
- Loop: For each match, create a <STR> token.
- Free token that has the pattern
- Relinking master token with the new accumulated token

NOTE: Only <STR> token. Wildcard for redirect do @ redirect stage
===========================================================================
Example

Current dir    Pattern: du*m*
==========
dummy.txt <MATCH>
dm.txt 
dump.log  <MATCH>
text.jpg
===========================================================================
Return: NONE



Return
- No match   : NULL
- Found match: accumulated token (linked-list head)
                 <STR >  ⇋   <STR>
               dummy.txt    dump.log
*/

//- Return all accumulated tokens after checking all files/folders
# matchstick

matchstick is a game that is also called "mardienbad game" or "nim game".

the rule is easy: the last to remove a stick lose. you can remove x stick per turn, x being the second parameters given
```
./matchstick [game board's length in row] [number of maximum stick to be removed each turn]
```
you can only remove 1 to max stick each turn, on a single line.

### example
```
$> ./matchstick 4 5
*********
*   |   *
*  |||  *
* ||||| *
*|||||||*
*********

Your turn:
Line: Matches: Player removed 3 match(es) from line 3
*********
*   |   *
*  |||  *
* ||    *
*|||||||*
*********

AI's turn...
AI removed 5 match(es) from line 4
*********
*   |   *
*  |||  *
* ||    *
*||     *
*********

Your turn:
Line: (EOF simulated with CTRL+D)$>
```
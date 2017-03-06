Max' 15-puzzle solver
=====================

Jag representerar pusslet som en int[16]. X representeras med 16.
Rader kan man räkna ut med heltalsdivision 4, och kolumner med modulus 4.

Kostnadsfunktionen är manhattanDistance och linear conflicts (rader+kolumner).

IDA*-lösaren håller reda på vilka states den besökt tidigare (i samma "path") och låter bli att söka om den märker att den loopat. 99% av vinsten här kommer av att inte backa till förra statet.

Successor-funktionen sorterar de nya state:sen i kostnadsordning. Verkar hjälpa väldigt lite.

Där finns en implementation av paritetskontrollen för att upptäcka olösliga pussel i FifteenUtil-klassen.

Det finns lite fler pussel-exempel i puzzles-katalogen, döpta efter antalet moves. Jag har döpt om 3.txt -> 28

Lite statistik:

| File (moves)   | Initial estimate | States searched | Time (ms) | States/sec |
| -------------- | ---------------- | --------------- | --------- | ---------- |
| 28.txt (3.txt) | 20               |         2 587   |       1   | 2 587 000  |
| 47.txt         | 35               |       552 647   |     311   | 1 777 000  |
| 53.txt         | 45               |       534 993   |     300   | 1 783 310  |
| 55.txt         | 37               |    69 947 750   |  59 431   | 1 176 957  |
| 57.txt         | 41               |    25 946 252   |  14 437   | 1 797 205  |
| 61.txt         | 41 (!)           |   370 654 596   | 219 660   | 1 687 401  |


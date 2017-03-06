Bussproblemet
============================

Lösning med en depth-first search. Ganska lik IDA*-implementationen i förra uppgiften.

Läser in filen och genererar en lista med grupper som jag sorterar i fallande storleksordning.

Sen testar jag rekursivt "alla" kombinationer, men slutar ifall jag hittar en lösning som fyller bussen, samt ifall bussen blir överfull.
Och i varje steg så kapar jag bort alla grupper som är före den jag är på, för att undvika att jämföra samma kombinationer igen. 

Jag håller kontinuerligt reda på vilken lösning som varit bäst hittills, globalt.

Och så testar jag i varje steg ifall de kvarvarande grupperna neråt ens i bästa fall skulle kunna ge bättre värde än nuvarande "best" solution. Om inte så ger jag upp den "branchen" direkt. 


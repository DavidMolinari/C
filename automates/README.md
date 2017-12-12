## AUTOMATE avec REGEX : a ( a * b a ( b a ) * a b * )

- input : Chaine de caractère | Taille de la chaine 
```bash
./automate aaaaabababaab 13
```


- Output : 
```bash
REGEX : a(a*ba(ba)*ab*)
Etat : 1 => a
Etat : 2 => a
Etat : 3 => a
Etat : 3 => a
Etat : 3 => a
Etat : 3 => b
Etat : 4 => a
Etat : 5 => b
Etat : 4 => a
Etat : 5 => b
Etat : 4 => a
Etat : 5 => a
Etat : 6 => b
Etat : 7 => END OF THE GAME
```

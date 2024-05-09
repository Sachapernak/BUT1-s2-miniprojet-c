# Projet : Chiffrement de message

<h3>Ce programme permet de chiffrer et déchiffrer des messages via le chiffrement César et Vigenère.</h2>

<p>Il possède une interface intéractive en ligne de commande:
<br><br>
<img src="./ressources/icli.jpg" alt="Exemple d'usage en interface intéractive" width="800"/>
<br><br>
Il est également possible de directement chiffrer ou dechiffrer en une seule ligne de commande :
<br><br>
<img src="./ressources/scl.jpg" alt="Exemple d'usage ligne de commande seule" width="800"/></p>


## Installation

Ce programme ne nécessite pas d'être installer.<br>
<br>Il suffit de lancer 'chiffrementC.exe' sur windows ou,'chiffrementC' sur linux.
<br>Il est possible de recompiler le programme sur linux a l'aide du fichier makefile inclut.
<br><br>Le programme peut aussi etre recompilé sur windows, a condition d'avoir installé l'utilitaire make a l'aide chocolatey
<br><br>Il suffit de se placer dans mini-projet-c/exec et faire:
```bash
make
```

## Utilisation

<h3>Pour utiliser le programme :<h3> 

<h4> - Interactif - <h4>

Linux:<br>
&emsp;./chiffrementC<br>
Windows:<br>
&emsp;chifrementC.exe<br>

<h4> - Ligne de commande - <h4>

Linux:<br>
&emsp;./chiffrementC&emsp;\[operation] \[cle] \[texte]<br>
Windows:<br>
&emsp;chiffrementC.exe&ensp; \[operation] \[cle] \[texte]<br>
<br>
Operations:<br>
&emsp;cc - chiffrement César<br>
&emsp;cd - dechiffrement César<br>
&emsp;vc - chiffrement Vigenère<br>
&emsp;vd - dechiffrement Vigenère<br>
<br>
Cle:<br>
&emsp;Nombre entier (César)<br>
&emsp;Texte alphanumérique, pas d'espaces (Vigenère)<br>
<br>
Exemple:<br>
&emsp;./chiffrementC cc "MaCleSecrete" "Mon texte ultra secret"<br>


## Contributeurs

Les contributeurs de ce projets sont :<br>
DA SILVA Olivier, PERNAK Sacha

## License

[GPLv3](https://www.gnu.org/licenses/gpl-3.0.fr.html)

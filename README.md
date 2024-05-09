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

Linux&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: ./chiffrementC<br>
Windows&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: chifrementC.exe<br>

<h4> - Ligne de commande - <h4>

Linux&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: ./chiffrementC   \[operation] \[cle] \[texte]<br>
Windows&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: chiffrementC.exe \[operation] \[cle] \[texte]<br>
<br>
Operations&nbsp;&nbsp;: cc - chiffrement César<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: cd - dechiffrement César<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: vc - chiffrement Vigenère<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: vd - dechiffrement Vigenère<br>
<br>
Cle&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: Nombre entier (César)<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: Texte alphanumérique, pas d'espaces (Vigenère)<br>
<br>
Exemple&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: ./chiffrementC cc "MaCleSecrete" "Mon texte ultra secret"<br>


## Contributeurs

Les contributeurs de ce projets sont :<br>
DA SILVA Olivier, PERNAK Sacha

## License

[GPLv3](https://www.gnu.org/licenses/gpl-3.0.fr.html)

# bfrShellArduino

Ce programme permet d'acceder au contenu d'une carte SD connectée a un arduino et d'executer des commande "style Unix" pour explorer le contenu de la carte SD.

les commandes sont entrées via le port moniteur de l'arduino
pour avoir la liste des commandes disponibles il suffit de taper la commande aide


initialisation de l'arduino

afin de pouvoir utiliser ce programme sur un arduino, il faut executer les instructions suivantes :
- il faut enfin transferer en memoire flash les fichiers de code :
    - les fichiers listés ci-dessous doivent etres dans le repertoire data :
        - index.html
        - style.css
        - favicon.png
        - bundle.js
        - pageNotFound.html
    - pour transferer il faut executer les deux actions platformIO suivantes (attention il ne doit y avoir aucune autre tache utilisant le port USB ex : monitor) :
        - Build Filesystem Image
        - Upload Filesystem Image

- il faut copier les fichiers suivants du repertoire carteSD local dans le repertoire "arduinoChaudiere" de la carte SD : 
    - calendrier.json
    - config.txt
    - environnements.json
    - README.md (ce fichier)

- dans le repertoire carteSD :
    - il faut generer le fichier bundle.js (dans le repertoire data) qui doit contenir les fichier suivants
        - npm run prod 

- executer ensuite le televersement du code dans l'arduino avec la commande du menu platformIO suivante :
    - Upload and Monitor
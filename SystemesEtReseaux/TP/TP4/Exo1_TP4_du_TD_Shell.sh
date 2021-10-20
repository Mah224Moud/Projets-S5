#!/bin/bash

FichNom=$1
FichPDF=$2


while read NOM PRENOM
do
    DIR=`echo $NOM $PRENOM | tr -d ' ' | tr [:lower] [:upper]`
    mkdir $DIR
    cp $FichPDF $DIR
    LISTDIR="$DIR $LISTDIR"

done < $FichNom
tar -cf arhiveDir.tar $LISTDIR && echo Archivage terminer avec succes
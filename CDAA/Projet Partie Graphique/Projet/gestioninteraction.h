/**
    *@file gestioninteraction.h
    *@brief Fichier d'en-tete de la classe GestionInteraction
    *@author BAH Saikou Oumar
    *@author DIALLO Mamoudou
*/

#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include <list>

#include "interaction.h"
#include "contact.h"

/**
    *@class GestionInteraction GestionInteraction.h "GestionInteraction.h"
    *@brief Cette classe permet de gérer une liste d'interaction ainsi que les taches (todo) liées à chaque intéraction.
    *@details Elle permet notamment l'ajout d'une interaction, d'un todo, leur suppression et l'affichage de toutes les intéractions d'un contact
*/
class GestionInteraction
{
    private:
        /// La liste des intéractions
        std::list<Interaction> listInteraction;

    public:
        /// Constructeur par défaut du gestionnaire d'intéraction
        GestionInteraction();
        /// Destructeur du gestionnaire d'intéraction
        ~GestionInteraction();

        ///
        std::list<Interaction> getListInteraction() const{ return listInteraction; }

        /// Taille de la liste
        inline unsigned getSize(){return listInteraction.size();}

        /// Ajouter une interaction
        void addInteraction(const Interaction&);
        /// Supprimer une intéraction
        bool removeInteraction(const QString&);
        /// Récuperer une intéraction
        Interaction getInteraction(const QString&);
        Interaction* getInteractionAdr(const QString&);
        /// Récuperer toutes les intéractions liées à un contact
        GestionInteraction getAllContactInteraction(const QString&);
        /// Supprimer toutes les intéractions liées à un contact
        void removeAllContactInteraction(const QString&);

        friend QDebug operator<<(QDebug, const GestionInteraction&);
};

#endif // GESTIONINTERACTION_H

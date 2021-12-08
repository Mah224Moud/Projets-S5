/**
    *@file Todo.cpp
    *@brief Fichier CPP de la classe Todo
    *@author
*/

#include "todo.h"
/**
    *@brief Constructeur par défaut de la classe Todo
    *@details Ce constructeur initialise à la date courante un Todo avec un contenu vide n'étant relié à aucune interaction;
*/
Todo::Todo()
{
    id = "";
    date = QDate::currentDate();
    this->contenu = "";
}

/**
    *@brief Constructeur avec paramètres de la classe Todo
    *@details Ce constructeur initialise à la date courant un Todo avec un contenu associé à une intéraction.
*/
Todo::Todo(Interaction* i, const QString& c)
{
    id ="";
    this -> date = QDate::currentDate();
    lienInteraction = i;
    this->setContenu(c);
}

Todo::Todo(const Todo& td)
{
    id = td.getID();
    date = td.getDate();
    lienInteraction = td.getInteraction();
    contenu = td.getContenu();
}

/**
    *@brief Constructeur avec paramètres de la classe Todo
    *@details Ce constructeur initialise à une date donnée un Todo avec un contenu associé à une intéraction.
*/
Todo::Todo(Interaction* i, const QString& c, const QDate& d)
{
    id = "";
    this -> date = d;
    lienInteraction = i;
    this->setContenu(c);
}

/**
    *@brief Pour récuperer l'identifiant de la tâche.
    *@details Cette fonction renvoie l'identifiant de la tâche.
    *return QString : l'id de la tâche.
*/
QString Todo::getID() const
{
    return id;
}

/**
    *@brief Pour récuperer l'intéraction à laquelle apppartient le Todo.
    *@details Cette fontion renvoie l'adresse de l'instance Intéraction à laquelle appartient le Todo.
*/
Interaction* Todo::getInteraction() const
{
    return lienInteraction;
}

/**
    *@brief Pour récupérer la date.
    *@details Cette fonction renvoie la date de création de l'intéraction.
    *@return QDate : la date de création de la tache.
*/
QDate Todo::getDate() const
{
    return date;
}

/**
    *@brief Pour récupérer la date.
    *@details Cette fonction renvoie la date de création de l'intéraction dans une QString.
    *@return QString : la date de création de la tache dans une QString au format (dd/MM/yyyy).
*/
QString Todo::getStringDate() const
{
    return date.toString("dd/MM/yyyy");
}

/**
    *@brief Pour recupérer le contenu de l'interaction.
    *@details Cette fonction renvoie la chaine contenu de l'interaction.
    *@return le contenu dans une QString.
*/
QString Todo::getContenu() const
{
    return contenu;
}

/**
    *@brief Pour définir l'identifiant de la tâche
    *@param l'identifiant de la tâche
*/
void Todo::setID(const QString& i)
{
    id = i;
}

/**
    *@brief Pour lier une intéraction à la classe Todo.
    *@param inter : l'intéraction à lier au Todo.
*/
void Todo::setInteraction(Interaction * inter)
{
    lienInteraction = inter;
}

/**
    *@brief Pour affecter une date à l'interaction.
    *@param t : QDate représentant la date à affecter.
    *@details La QDate passée en paramètre est copié dans la date.
*/
void Todo::setDate(const QDate & t)
{
    date = t;
}

/**
    *@brief Pour affecter une date à l'interaction.
    *@param t : QString représentant la date à affecter au format dd/MM/yyyy.
*/
void Todo::setDateFromString(const QString& t)
{
    date = QDate::fromString(t, "dd/MM/yyyy");
}

/**
    *@brief Pour affecter un contenu à l'interaction.
    *@param c : string à affecter au contenu.
*/
void Todo::setContenu(const QString & c)
{
    contenu= c;
}

/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type ostream.
    *@param td: de type Todo qui represente le Todo à afficher.
    *@details Pour afficher un Todo, on affiche son contenu suivie de sa date si elle est différente de la date courante (Aujourd'hui).
    *@return os;
*/
QDebug operator<<(QDebug os, const Todo& td)
{
    os << "It " << td.getInteraction()->getID() << " : @todo " << td.getContenu() << " ";
    if(td.getDate() != QDate::currentDate())
        os << "@date " << td.getStringDate();
    os << "\n";
    return os;
}

QString Todo::toString()
{
    QString t = "@todo ("+id+") " + getContenu();
    if(date != QDate::currentDate())
        t += " @date " + getStringDate();
    return t;
}

/**
    *@brief Surchage de l'opérateur de comparaison (==)
    *@details On considère que deux intéractions sont identiques si elles ont même identifiant.
    *@param autre : l'intéraction à comparer avec l'intéraction courante.
    *@return un booléen : true si elles ont le même contenu, false sinon.
*/
bool Todo::operator==(const Todo& autre)
{
    return getID() == autre.getID();
}

/**
    *@brief Surchage de l'opérateur d'affectation (=)
    *@details L'affectation concerne l'identifiant, le contenu, la date et l'intéraction
    *@param autre : l'intéraction à comparer avec l'intéraction courante.
    *@return un booléen : true si elles ont le même contenu, false sinon.
*/
void Todo::operator=(const Todo& autre)
{
    id = autre.getID();
    contenu = autre.getContenu();
    date = autre.getDate();
    lienInteraction = autre.getInteraction();
}

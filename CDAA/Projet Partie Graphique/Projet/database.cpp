#include "database.h"

#include <QSqlRecord>

DataBase::DataBase()
{
    connexion();
}

DataBase::~DataBase()
{
    if(isOpen())
        database.close();
}

void DataBase::connexion()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/bah/Bureau/L3/CDAA/Projet/Projet/Files/base.sqlite");

    if(database.open())
    // Ouverture avec succès de la base de données
        open = true;
    else
    {
        // Erreur lors de l'ouverture de la base de données
        open = false;
        // Envoie un signal d'erreur;
        emit errorDataBase("Erreur!! Problème rencontré lors de l'ouverture de la base de données");
    }
}

/**
 * @brief DataBase::refreshingContacts Cette fonction permet de mettre à jour la liste des contacts
 * @param gest: le gestionnaire de contact à mettre à jour
 */
void DataBase::refreshingContacts(GestionContact& gest)
{
    if(isOpen())
    {
        QSqlQuery query("SELECT * FROM CONTACT");
        if(!query.exec())
            emit errorDataBase("ERREUR !! Rafraichissement liste des contacts");
        else
        {
            gest.getListContact().clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreationFromString(query.value(6).toString());
                contact.setDateLastModifFromString(query.value(7).toString());
                contact.setEmail(query.value(8).toString());
                gest.addContact(contact);
            }
        }
    }
}

/**
 * @brief DataBase::refreshingInteractions Cette fonction permet de charger toutes les intéractions dans la base de données
 * @param gest : le gestionnaire de contact dans lequel se trouve également toutes les intéractions
 */
void DataBase::refreshingInteractions(GestionContact& gest)
{
    if(isOpen())
    {
        QSqlQuery query("SELECT * FROM INTERACTION");
        if(!query.exec())
            emit errorDataBase("ERREUR !! Rafraichissement liste des interactions");
        else
        {
            gest.getGestInteraction()->getListInteraction().clear();
            Interaction interact;
            QString idcontact;
            while(query.next())
            {
                interact.setID(query.value(0).toString());
                interact.setContenu(query.value(1).toString());
                interact.setDateFromString(query.value(2).toString());
                idcontact = query.value(3).toString();
                gest.addContactInteraction(idcontact, interact);
            }
        }
    }
}

/**
 * @brief DataBase::refreshTodos Cette fonction permet de charger toutes les tâches dans la base de données
 * @param gest : le gestionnaire de contact dans lequel se trouve également toutes les tâches
 */
void DataBase::refreshingTodos(GestionContact& gest)
{
    if(isOpen())
    {
        QSqlQuery query("SELECT * FROM TODO");
        if(!query.exec())
            emit errorDataBase("ERREUR !! Rafraichissement liste des tâches");
        else
        {
            gest.getGestInteraction()->getListInteraction().clear();
            Todo todo;
            QString idinteract;
            while(query.next())
            {
                todo.setID(query.value(0).toString());
                todo.setContenu(query.value(1).toString());
                todo.setDateFromString(query.value(2).toString());
                idinteract = query.value(3).toString();
                gest.addInteractionTodo(idinteract, todo);
            }
        }
    }
}

/**
 * @brief DataBase::refresh
 * @param gest
 */
void DataBase::refreshing(GestionContact& gest)
{
    refreshingContacts(gest);
    refreshingInteractions(gest);
    refreshingTodos(gest);
    emit refreshed();
}

/**
 * @brief DataBase::addContact Ajouter un contact à la base de données
 * @param contact : le contact à ajouter dans la base
 * @return true si l'insertion a été faite, false sinon;
 * @warning un message informera de l'ajout dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::addContact(const Contact & contact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO CONTACT(nom, prenom, entreprise, telephone, uriphoto, datecreation, datelastmodif, mail) VALUES (:name, :lastname, :ent, :tel, :url, :dtc, :dtl, :m)");
        query.bindValue(":name", contact.getNom());
        query.bindValue(":lastname", contact.getPrenom());
        query.bindValue(":ent", contact.getEntreprise());
        query.bindValue(":tel", contact.getTelephone());
        query.bindValue(":url", contact.getTelephone());
        query.bindValue(":dtc", contact.getStringDateCreation());
        query.bindValue(":dtl", contact.getStringDateLastModif());
        query.bindValue(":m", contact.getEmail());
        if(!query.exec())
            emit errorDataBase("ERREUR !! Le contact "+contact.getNom()+"  "+contact.getPrenom()+"n'a pas été inséré");
        else
        {
            emit infoDataBase("Nouveau contact inséré : "+contact.getNom()+" "+contact.getPrenom());
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::removeConctact Supprimer un contact de la base de données
 * @param idContact : l'identifiant du contact à supprimer
 * @return true si la suppression est une réussite, false sinon
 * @warning un message informera de la suppression de la base de données ou de l'échec de l'opération.
 */
bool DataBase::removeConctact(const QString& idContact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM CONTACT WHERE idcontact = :id");
        query.bindValue(":id",idContact);
        if(!query.exec())
            emit errorDataBase("ERREUR !! Le contact n'a pas été supprimé");
        else
        {
            emit infoDataBase("Contact Supprimé");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::getContact Ce fonction permet de recupérer un contact en connaissant son nom, son prenom et son entreprise
 * @param nom : le nom du contact à recupérer
 * @param prenom : son prenom
 * @param entreprise : son entreprise
 * @return le contact
 * @warning Si le contact est absent de la base on retourne un contact avec un id à NULL
 */
Contact DataBase::getContact(const QString& nom, const QString& prenom, const QString& entreprise)
{
    Contact contact; contact.setID("NULL");
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE nom = :n AND prenom = :p AND entreprise = :e");
        query.bindValue(":n", nom);
        query.bindValue(":p", prenom);
        query.bindValue(":e", entreprise);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact");
        else
        {
            contact.setID(query.value(0).toString());
            contact.setNom(query.value(1).toString());
            contact.setPrenom(query.value(2).toString());
            contact.setEntreprise(query.value(3).toString());
            contact.setTelephone(query.value(4).toString());
            contact.setPhoto(query.value(5).toString());
            contact.setDateCreationFromString(query.value(6).toString());
            contact.setDateLastModifFromString(query.value(7).toString());
            contact.setEmail(query.value(8).toString());
        }
    }
    return contact;
}

/**
 * @brief DataBase::updateContact Modifier les informations sur un contact
 * @param oldContact : il contient les anciennes informations sur le contact
 * @param newContact : il contient les nouvelles informations sur le contact
 * @return true si la modification se passe sans problème, false sinon
 * @warning un message informera de la mise à jour des informations dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::updateContact(const Contact& oldContact, const Contact& newContact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE CONTACT SET nom = :newNom, prenom = :newPrenom, entreprise = :newEnt, telephone = :newTel, uriphoto = :newPhoto, datecreation = :newDC, datelastmodif = :newDL, mail = :newMail WHERE idcontact = :oldID");
        query.bindValue(":newNom", newContact.getNom());
        query.bindValue(":newPrenom", newContact.getPrenom());
        query.bindValue(":newEnt", newContact.getEntreprise());
        query.bindValue(":newTel", newContact.getTelephone());
        query.bindValue(":newPhoto", newContact.getPhoto());
        query.bindValue(":newDC", newContact.getStringDateCreation());
        query.bindValue(":newDL", newContact.getStringDateLastModif());
        query.bindValue(":newMail", newContact.getEmail());
        query.bindValue(":oldID", oldContact.getID());

        if(!query.exec())
            emit errorDataBase("ERREUR !! Le contact n'a pas été mis à jour");
        else
        {
            emit infoDataBase("Contact mis à jour");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::addInteraction Ajouter une intéraction dans la base de données;
 * @param interact : l'intéraction à ajouter dans la base
 * @return true si l'insertion a été faite, false sinon;
 * @warning un message informera de l'ajout dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::addInteraction(const Interaction & interact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO INTERACTION (contenu, date, idcontact) VALUES (:c, :d, :id)");
        query.bindValue(":c", interact.getContenu());
        query.bindValue(":d", interact.getStringDate());
        query.bindValue(":id", interact.getContact()->getID());


        if(!query.exec())
            emit errorDataBase("ERREUR !! Impossible d'ajouter une nouvelle intéraction dans la base de données");
        else
        {
            emit infoDataBase("Nouvelle interaction ajouté");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::removeInteraction Supprimer une intéraction de la base de données
 * @param idinteract : l'identifiant de l'intéraction à supprimer
 * @return true si la suppression est une réussite, false sinon
 * @warning un message informera de la suppression de la base de données ou de l'échec de l'opération.
 */
bool DataBase::removeInteraction(const QString& idinteract)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM INTERACTION WHERE idinter = :id");
        query.bindValue(":id",idinteract);
        if(!query.exec())
            emit errorDataBase("ERREUR !! L'interaction n'a pas été supprimé");
        else
        {
            emit infoDataBase("Interaction Supprimé");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::updateInteraction Modifier les informations d'une intéraction
 * @param oldInter : il contient les anciennes informations de l'intéraction
 * @param newInter : il contient les nouvelles informations de l'intéraction
 * @return true si la modification se passe sans problème, false sinon
 * @warning un message informera de la mise à jour des informations dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::updateInteraction(const Interaction& oldInter, const Interaction& newInter)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE INTERACTION SET contenu = :c, date = :d WHERE idinter = :id");
        query.bindValue(":c", newInter.getContenu());
        query.bindValue(":d", newInter.getStringDate());
        query.bindValue(":id", oldInter.getID());
        if(!query.exec())
            emit errorDataBase("ERREUR !! L'interaction n'a pas été modifiée");
        else
        {
            emit infoDataBase("Interaction modifiée");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::addTodo ajouter une tâche dans la base de données
 * @param td : la tâche à ajouter
 * @return true si l'insertion a été faite, false sinon;
 * @warning un message informera de l'ajout dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::addTodo(const Todo & td)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO TODO (contenu, date, idinter) VALUES (:c, :d, :id)");
        query.bindValue(":c", td.getContenu());
        query.bindValue(":d", td.getStringDate());
        query.bindValue(":id", td.getInteraction()->getID());

        if(!query.exec())
            emit errorDataBase("ERREUR !! Impossible d'ajouter une nouvelle tâche dans la base de données");
        else
        {
            emit infoDataBase("Nouvelle tâche ajoutée");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::removeTodo Supprimer une tâche de la base de données
 * @param idtodo : l'identifiant de la tâche à supprimer
 * @return true si la suppression est une réussite, false sinon
 * @warning un message informera de la suppression de la base de données ou de l'échec de l'opération.
 */
bool DataBase::removeTodo(const QString & idtodo)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM TODO WHERE idTodo = :id");
        query.bindValue(":id",idtodo);
        if(!query.exec())
            emit errorDataBase("ERREUR !! La tâche n'a pas été supprimée");
        else
        {
            emit infoDataBase("Tâche Supprimée");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::updateTodo Modifier les informations sur une tâche
 * @param oldTodo : il contient les anciennes informations sur la tâche
 * @param newTodo : il contient les nouvelles informations sur la tâche
 * @return true si la modification se passe sans problème, false sinon
 * @warning un message informera de la mise à jour des informations dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::updateTodo(const Todo & oldTodo, const Todo & newTodo)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE TODO SET contenu = :c, date = :d WHERE idTodo = :id");
        query.bindValue(":c", newTodo.getContenu());
        query.bindValue(":d", newTodo.getStringDate());
        query.bindValue(":id", oldTodo.getID());
        if(!query.exec())
            emit errorDataBase("ERREUR !! La tâche n'a pas été modifiée");
        else
        {
            emit infoDataBase("Tâche modifiée");
            return true;
        }
    }
    return false;
}

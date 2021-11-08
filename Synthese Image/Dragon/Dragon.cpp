#include <cstdio>
#include <cstdlib>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <jpeglib.h>
#include <jerror.h>
#include <math.h>

#include <iostream>

#define PI 3.1415

/* Class Point */
class Point{
    public :
	//coordonnées x, y et z du point
	double x;
	double y;
	double z;
};

/* ============> Prototype des fonctions <============ */
void dragon();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void idle();
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);
void animation();

/* ============> Corps */
void initCorps();
/* ============> Queue */
void initQueue();
/* ============> Pattes */
void initMembre(double, double, double);
void Membre();
void patteAvantDroite();
void patteAvantGauche();
void patteArriereDroite();
void patteArriereGauche();


/* ===============> Valeurs globales <=============== */
double zoom = 6.0;
//
const int nbCercle = 20;
const int nbPointParCercle = 20;
// Tableau contenant les points
Point ptMembre[nbCercle * nbPointParCercle];
// Tableau contenant les faces
int fMembre[(nbCercle-1)*nbPointParCercle][4];

char presse;
int anglex,angley,x,y,xold,yold;


int main(int argc,char **argv)
{
  /* initialisation de glut et creation de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(2000,1000);
  glutCreateWindow("Dragon");

  /* Initialisation d'OpenGL */
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);

  /* enregistrement des fonctions de rappel */
  glutDisplayFunc(dragon);
  //glutIdleFunc(animation);
  glutKeyboardFunc(clavier);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);

  /* Entree dans la boucle principale glut */
  glutMainLoop();
  return 0;
}

/**
    *@brief Fonction intéraction avec le clavier
*/
void clavier(unsigned char touche,int x,int y)
{
    switch (touche)
    {
        case 'p': /* affichage du carre plein */
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glutPostRedisplay();
            break;
        case 'f': /* affichage en mode fil de fer */
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            glutPostRedisplay();
            break;
        case 's' : /* Affichage en mode sommets seuls */
            glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
            glutPostRedisplay();
            break;
        case 'd':
            glEnable(GL_DEPTH_TEST);
            glutPostRedisplay();
            break;
        case 'D':
            glDisable(GL_DEPTH_TEST);
            glutPostRedisplay();
            break;
        case 'z':
            zoom ++;
            glutPostRedisplay();
            break;
        case 'Z':
            zoom --;
            glutPostRedisplay();
            break;
        case 'q' : /*la touche 'q' permet de quitter le programme */
          exit(0);
    }
}

/**
    *@brief Fonction de rappel de remodelage de la fenetre
*/
void reshape(int x,int y)
{
  if (x<y)
    glViewport(0,(y-x)/2,x,x);
  else
    glViewport((x-y)/2,0,y,y);
}

/**
    *@brief Fonction de
*/
void mouse(int button, int state,int x,int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    presse=0; /* le booleen presse passe a 0 (faux) */
}

/**
    *@brief Fonction de
*/
void mousemotion(int x,int y)
{
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      anglex=anglex+(x-xold);
      angley=angley+(y-yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }

    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
}

void dragon()
{
    /* effacement de l'image avec la couleur de fond */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glLoadIdentity();
    glRotatef(angley,1.0,0.0,0.0);
    glRotatef(anglex,0.0,1.0,0.0);
    glOrtho(-zoom, zoom, -zoom, zoom, -zoom, zoom);


    glMatrixMode(GL_MODELVIEW);

        // Corps
        glPushMatrix();
            initCorps();
            Membre();
        glPopMatrix();

        // Cou
        glPushMatrix();
            glTranslatef(0, 1.5, -0.8);
            glRotatef(55, 1, 0, 0);
            glutSolidCylinder(1.15, 4, 20, 20);
        glPopMatrix();


        //Cabeza
        glPushMatrix();

            //Crane
            glPushMatrix();
                glTranslatef(0, 1.25, -1.5);
                glRotatef(55, 1, 0, 0);
                glScalef(1,2,1);
                glColor3f(1.0, 1.0, 0.0);
                glutSolidSphere(1, 20, 20);
            glPopMatrix();

            //corne gauche
                glPushMatrix();
                glTranslatef(0.5, 1.85, -1.5);
                glRotatef(-100, 1, 0, 0);
                    glColor3f(1.0, 0.0, 0.0);
                    glutSolidCone(0.2, 1.5, 10, 10);
                glPopMatrix();

            //corne droite
                glPushMatrix();
                glTranslatef(-0.5, 1.85, -1.5);
                glRotatef(-100, 1, 0, 0);
                    glColor3f(1.0, 0.0, 0.0);
                    glutSolidCone(0.2, 1.5, 10, 10);
                glPopMatrix();

            //Oeil droite
            glPushMatrix();
                glTranslatef(-0.50, 1.35, -2.5);
                glRotatef(45, 1, 0, 0);
                glScalef(1,2,1);

                glColor3f(0.0, 1.0, 0.0);
                glutSolidSphere(0.25, 20, 20);

            glPopMatrix();

            //Oeil gauche
            glPushMatrix();
                glTranslatef(0.50, 1.35, -2.5);
                glRotatef(45, 1, 0, 0);
                glScalef(1,2,1);

                glColor3f(0.0, 1.0, 0.0);
                glutSolidSphere(0.25, 20, 20);

            glPopMatrix();
        glPopMatrix();

        // Queue
        glPushMatrix();
            glTranslatef(0, 0, 7);
            initQueue();
            Membre();
        glPopMatrix();

        // Patte devant droite
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(-2.5, -7.5, 0);
            glRotatef(90, 1, 0, 0);
            glColor3f(0.5, 0.5, 0.5);
            patteAvantDroite();
        glPopMatrix();

        //Patte avant gauche
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(2.5, -7.5, 0);
            glRotatef(90, 1, 0, 0);
            glColor3f(0.5, 0.5, 0.5);
            patteAvantGauche();
        glPopMatrix();

        //Patte arriere droite
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(2.5, -7.5, 13.5);
            glRotatef(90, 1, 0, 0);
            glRotatef(2*90, 0, 0, 1);
            glColor3f(0.5, 0.5, 0.5);
            patteArriereDroite();
        glPopMatrix();

        //Patte arriere gauche
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(-2.5, -7.5, 13.5);
            glRotatef(90, 1, 0, 0);
            glRotatef(2*90, 0, 0, 1);
            glColor3f(0.5, 0.5, 0.5);
            patteArriereGauche();
        glPopMatrix();

       /* // Aile
        glPushMatrix();
            glBegin(GL_POLYGON);
                glVertex3f(0,0,0);
                glVertex3f(5,0,0);
                glVertex3f(0,5,0);
            glEnd();
        glPopMatrix();*/
    glEnd();

    //Repère
    //axe x en rouge
    glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
    	glVertex3f(0, 0,0.0);
    	glVertex3f(1, 0,0.0);
    glEnd();
    //axe des y en vert
    glBegin(GL_LINES);
    	glColor3f(0.0,1.0,0.0);
    	glVertex3f(0, 0,0.0);
    	glVertex3f(0, 1,0.0);
    glEnd();
    //axe des z en bleu
    glBegin(GL_LINES);
    	glColor3f(0.0,0.0,1.0);
    	glVertex3f(0, 0,0.0);
    	glVertex3f(0, 0,1.0);
    glEnd();

  glFlush();
  //On echange les buffers
  glutSwapBuffers();

}

void animation()
{

}

/*=====================================================================================================================*/
/**
   *@brief Initialisation de la primitive de contruction d'un membre du dragon
*/
void initMembre(double r1, double r2, double taille)
{
    double decremat = 0;
    for(int i = 0; i < nbCercle; i++)
    {
        decremat += (r1 - r2) / nbCercle;
        for(int j = 0; j < nbPointParCercle; j++)
        {
            ptMembre[(i*nbPointParCercle+j)].x = (r1-decremat) * cos(2*PI*j/nbPointParCercle);
            ptMembre[(i*nbPointParCercle+j)].y = (r1-decremat) * sin(2*PI*j/nbPointParCercle);
            ptMembre[(i*nbPointParCercle+j)].z = i * taille / nbCercle;
        }
    }

    for(int i = 0; i < nbCercle -1 ; i++)
    {
        for(int j = 0; j < nbPointParCercle; j++)
        {
            fMembre[i * nbPointParCercle + j][0] = i * nbPointParCercle + j;
            fMembre[i * nbPointParCercle + j][1] = i * nbPointParCercle + (j+1) % nbPointParCercle;
            fMembre[i * nbPointParCercle + j][2] = (i+1) * nbPointParCercle + (j+1) % nbPointParCercle;
            fMembre[i * nbPointParCercle + j][3] = (i+1) * nbPointParCercle + j;
        }
    }
}

/**
    *@brief
*/
void Membre()
{
    int nbFaces = (nbCercle - 1) * nbPointParCercle;

    for(int i = 0; i < nbFaces; i++)
    {
        glBegin(GL_POLYGON);
            //glColor3f(1.0, 1.0, 1.0);
            glVertex3f(ptMembre[fMembre[i][0]].x, ptMembre[fMembre[i][0]].y, ptMembre[fMembre[i][0]].z);
            glVertex3f(ptMembre[fMembre[i][1]].x, ptMembre[fMembre[i][1]].y, ptMembre[fMembre[i][1]].z);
            glVertex3f(ptMembre[fMembre[i][2]].x, ptMembre[fMembre[i][2]].y, ptMembre[fMembre[i][2]].z);
            glVertex3f(ptMembre[fMembre[i][3]].x, ptMembre[fMembre[i][3]].y, ptMembre[fMembre[i][3]].z);
        glEnd();
    }
}

/*=====================================================================================================================*/
/**
   *@brief Initialisation de la primitive de contruction de la queue du dragon
*/
void initQueue()
{
    double r = 0.5, decremat = 0.0, translation = 0.0, save;
    double tailleQueue = 10.0;
    for(int i = 0; i < nbCercle; i++)
    {
        decremat += r/nbCercle;
        for(int j = 0; j < nbPointParCercle; j++)
        {
            ptMembre[(i*nbPointParCercle+j)].x = (r-decremat) * cos(2*PI*j/nbPointParCercle);
            ptMembre[(i*nbPointParCercle+j)].y = (r-decremat) * sin(2*PI*j/nbPointParCercle);
            ptMembre[(i*nbPointParCercle+j)].z = i * tailleQueue / nbCercle;
                translation = log((i+1) * nbCercle + nbPointParCercle);
                if(i==0) save = translation;
                ptMembre[(i*nbPointParCercle+j)].y -= translation - save;
        }
    }

    for(int i = 0; i < nbCercle -1; i++)
    {
        for(int j = 0; j < nbPointParCercle; j++)
        {
            fMembre[i * nbPointParCercle + j][0] = i * nbPointParCercle + j;
            fMembre[i * nbPointParCercle + j][1] = i * nbPointParCercle + (j+1) % nbPointParCercle;
            fMembre[i * nbPointParCercle + j][2] = (i+1) * nbPointParCercle + (j+1) % nbPointParCercle;
            fMembre[i * nbPointParCercle + j][3] = (i+1) * nbPointParCercle + j;
        }
    }
}

/*=====================================================================================================================*/
/**
    *@brief
*/
void patteAvantDroite()
{
    glPushMatrix();
        glutSolidSphere(1, 20, 20);
    glPopMatrix();
    // Avant Bras
    glPushMatrix();
        glTranslatef(0, 3, -3);
        glRotatef(45, 1, 0, 0);
        initMembre(1.5, 0.9, 4);
        Membre();
    glPopMatrix();
    // Bras
    glPushMatrix();
        glTranslatef(0, 0, 0.6);
        //glRotatef(50, 1, 0, 0);
        initMembre(0.8, 0.25, 4);
        Membre();
    glPopMatrix();
    // Pied
    glPushMatrix();
        glTranslatef(0, -0.5, 4.75);
        glColor3f(1,1,1);
        glScalef(1, 2, 1);
        glutSolidCube(1);
    glPopMatrix();
}

/**
    *@brief
*/
void patteAvantGauche()
{
    glPushMatrix();
        glutSolidSphere(1, 20, 20);
    glPopMatrix();
    // Avant Bras
    glPushMatrix();
        glTranslatef(0, 3, -3);
        glRotatef(45, 1, 0, 0);
        initMembre(1.5, 0.9, 4);
        Membre();
    glPopMatrix();
    // Bras
    glPushMatrix();
        glTranslatef(0, 0, 0.6);
        //glRotatef(50, 1, 0, 0);
        initMembre(0.8, 0.25, 4);
        Membre();
    glPopMatrix();
    // Pied
    glPushMatrix();
        glTranslatef(0, -0.5, 4.75);
        glColor3f(1,1,1);
        glScalef(1, 2, 1);
        glutSolidCube(1);
    glPopMatrix();
}

/**
    *@brief
*/
void patteArriereDroite()
{
    glPushMatrix();
        glutSolidSphere(1, 20, 20);
    glPopMatrix();
    // Avant Bras
    glPushMatrix();
        glTranslatef(0, 3, -3);
        glRotatef(45, 1, 0, 0);
        initMembre(1.5, 0.9, 4);
        Membre();
    glPopMatrix();
    // Bras
    glPushMatrix();
        glTranslatef(0, 0, 0.6);
        //glRotatef(50, 1, 0, 0);
        initMembre(0.8, 0.25, 4);
        Membre();
    glPopMatrix();
    // Pied
    glPushMatrix();
        glTranslatef(0, 0.5, 4.75);
        glColor3f(1,1,1);
        glScalef(1, 2, 1);
        glutSolidCube(1);
    glPopMatrix();
}

/**
    *@brief
*/
void patteArriereGauche()
{
    glPushMatrix();
        glutSolidSphere(1, 20, 20);
    glPopMatrix();
    // Avant Bras
    glPushMatrix();
        glTranslatef(0, 3, -3);
        glRotatef(45, 1, 0, 0);
        initMembre(1.5, 0.9, 4);
        Membre();
    glPopMatrix();
    // Bras
    glPushMatrix();
        glTranslatef(0, 0, 0.6);
        //glRotatef(50, 1, 0, 0);
        initMembre(0.8, 0.25, 4);
        Membre();
    glPopMatrix();
    // Pied
    glPushMatrix();
        glTranslatef(0, 0.5, 4.75);
        glColor3f(1,1,1);
        glScalef(1, 2, 1);
        glutSolidCube(1);
    glPopMatrix();
}
/*=====================================================================================================================*/
/**
    *@brief
*/
void initCorps()
{
    double decremat = 0, r = 0.5, taille = 7.5;
    for(int i = 0; i < nbCercle; i++)
    {
        if(i <= nbCercle/6) decremat += r * nbPointParCercle / nbCercle;
        else if (i >= 5*nbCercle/6) decremat -= r * nbPointParCercle / nbCercle;

        for(int j = 0; j < nbPointParCercle; j++)
        {
            ptMembre[(i*nbPointParCercle+j)].x = (r+decremat) * cos(2*PI*j/nbPointParCercle);
            ptMembre[(i*nbPointParCercle+j)].y = (r+decremat) * sin(2*PI*j/nbPointParCercle);
            ptMembre[(i*nbPointParCercle+j)].z = i * taille / nbCercle;

            ptMembre[(i*nbPointParCercle+j)].y -= decremat * 0.60;
        }
    }

    for(int i = 0; i < nbCercle -1 ; i++)
    {
        for(int j = 0; j < nbPointParCercle; j++)
        {
            fMembre[i * nbPointParCercle + j][0] = i * nbPointParCercle + j;
            fMembre[i * nbPointParCercle + j][1] = i * nbPointParCercle + (j+1) % nbPointParCercle;
            fMembre[i * nbPointParCercle + j][2] = (i+1) * nbPointParCercle + (j+1) % nbPointParCercle;
            fMembre[i * nbPointParCercle + j][3] = (i+1) * nbPointParCercle + j;
        }
    }
}

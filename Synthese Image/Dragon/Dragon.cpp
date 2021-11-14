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
void clavier(unsigned char touche, int x, int y);
void sclavier(int touche, int x, int y);
void reshape(int x,int y);

/* ============> Animation*/
bool anim = false;
double animationAiles = 0; bool fin = false;
double animationMonteedragon = 0; bool finMontee = false;

double animationMarche1 = 45; bool finMarche1 = false;
double animationMarche2 = 0; bool finMarche2 = false;
double animationMarche3 = 0; bool finMarche3 = false;
double animationMarche4 = 45; bool finMarche4 = false;

void animation();
/* ============> Corps */
void initCorps();
void Corps();
/* ============> Queue */
void initQueue();
/* ============> Pattes */
void initMembre(double, double, double);
void Membre();
void patteAvantDroite();
void patteAvantGauche();
void patteArriereDroite();
void patteArriereGauche();
/* ============> Ailes */
void Aile(int i);

/* ===============> Textures <=============== */

void loadImage1(char* fichier);
const int hautimg1 = 255, largimg1 = 256;
unsigned char imageEcaille1[hautimg1*largimg1*3];
unsigned char textureEcaille1[hautimg1][largimg1][3];

void loadImage2(char* fichier);
const int hautimg2 = 512, largimg2 = 512;
unsigned char imageEcaille2[hautimg2*largimg2*3];
unsigned char textureEcaille2[hautimg2][largimg2][3];


/* ===============> Illumination <=============== */
    // Lumière
    GLfloat couleur[] = {1.0, 1.0, 0.75, 1.0};

void illumination_ambiant();


    // Lumière spot
        // position
    GLfloat source_spot[] = {0.0, 5.0, 0.0, 1.0};
        // direction
    GLfloat direction_spot[] = {0.0, -1.0, 0.0};
        // composante diffuse
    GLfloat dif_spot[] = {1.0, 0.0, 0.0, 1.0};
        // composante ambiante
    GLfloat amb_spot[] = {0.75, 0.0, 0.0, 1.0};
        // composante spéculaire
    GLfloat spec_spot[] = {1.0, 1.0, 1.0, 1.0};

    double move_spot_light = 0;
    bool spot_light_on = false;

void illumination_spot();

/* ===============> Valeurs globales <=============== */
double zoom = 10;
const int nbCercle = 20;
const int nbPointParCercle = 20;
// Tableau contenant les points
Point ptMembre[nbCercle * nbPointParCercle];
// Tableau contenant les faces
int fMembre[(nbCercle-1)*nbPointParCercle][4];

int anglex =  90,angley = 0;


int main(int argc,char **argv)
{
    /* chargement des textures */
    loadImage1("./textures/ecailles1.jpg");
    loadImage2("./textures/ecailles2.jpg");

    /* initialisation de glut et creation de la fenetre */
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(2000,1000);
    glutCreateWindow("Dragon");

    /* Initialisation d'OpenGL */
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    /* Mise en place de la projection perspective */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    /* Parametrage du placage de textures */
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    /* Lumières */
    glEnable(GL_LIGHTING);
    illumination_ambiant();
    illumination_spot();


    /* enregistrement des fonctions de rappel */
    glutDisplayFunc(dragon);
    glutIdleFunc(animation);
    glutKeyboardFunc(clavier);
    glutSpecialFunc(sclavier);
    glutReshapeFunc(reshape);

    /* Entree dans la boucle principale glut */
    glutMainLoop();
    return 0;
}

/**
    *@brief Fonction intéraction avec le clavier
*/
void clavier(unsigned char touche, int x, int y)
{
    switch (touche)
    {
        case 'z': // Zoomer
            zoom ++;
            glutPostRedisplay();
            break;
        case 'Z': // Dezoomer
            zoom --;
            glutPostRedisplay();
            break;
        case 'a':
        case 'A': // Lancer l'animation vol
            anim = true;
            break;
        case 's':
        case 'S': // Activer et desativer la lumière spot
            spot_light_on = !spot_light_on;
            break;
        case 'q' : // Quitter
          exit(0);
    }
}

/**
    *@brief Fonction intéraction avec le clavier touches spéciales
*/
void sclavier(int touche, int x, int y)
{
    switch(touche)
    {
        case GLUT_KEY_UP:
            angley -= 2; //activer la rotation vers le haut
            glutPostRedisplay();
        break;

        case GLUT_KEY_DOWN:
            angley += 2; //activer la rotation vers le bas
            glutPostRedisplay();
        break;

        case GLUT_KEY_RIGHT:
            anglex += 2; //activer la rotation vers la droite
            glutPostRedisplay();
        break;

        case GLUT_KEY_LEFT:
            anglex -= 2; //activer la rotation vers la gauche
            glutPostRedisplay();
        break;
    }

}

/**
    * @brief Redefinition de la fenetre lorsqu'elle est redimensionnée
*/
void reshape(int x,int y)
{
  if (x<y)
    glViewport(0,(y-x)/2,x,x);
  else
    glViewport((x-y)/2,0,y,y);
}


/**
    * @brief Chargement de la texture 1 qui represente le corps
*/
void loadImage1(char* fichier)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *file;
    unsigned char *ligne;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    #ifdef __WIN32
    if (fopen_s(&file,fichier,"rb") != 0)
    {
        fprintf(stderr,"Erreur : impossible d'ouvrir le fichier texture.jpg\n");
        exit(1);
    }
    #elif __GNUC__
    if ((file = fopen(fichier,"rb")) == 0)
    {
        fprintf(stderr,"Erreur : impossible d'ouvrir le fichier %s\n", fichier);
        exit(1);
    }
    #endif
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);

    if ((cinfo.image_width!=largimg1)||(cinfo.image_height!=hautimg1)) {
    fprintf(stdout,"Erreur : l'image doit etre de taille %dx%d\n", hautimg1, largimg1);
    exit(1);
    }
    if (cinfo.jpeg_color_space==JCS_GRAYSCALE) {
    fprintf(stdout,"Erreur : l'image doit etre de type RGB\n");
    exit(1);
    }

    jpeg_start_decompress(&cinfo);
    ligne = imageEcaille1;
    while (cinfo.output_scanline<cinfo.output_height)
    {
        ligne=imageEcaille1+3*largimg1*cinfo.output_scanline;
        jpeg_read_scanlines(&cinfo,&ligne,1);
    }
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

  //============================================================
    for(int i = 0; i < hautimg1; i++){
        for(int j = 0; j < largimg1; j++){
            textureEcaille1[i][j][0] = imageEcaille1[i*largimg1*3 + j*3];
            textureEcaille1[i][j][1] = imageEcaille1[i*largimg1*3 + j*3 + 1];
            textureEcaille1[i][j][2] = imageEcaille1[i*largimg1*3 + j*3 + 2];
        }
    }
}

/**
    * @brief Chargement de la texture 2 qui represente les autres membres du corp
*/
void loadImage2(char* fichier)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *file;
    unsigned char *ligne;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    #ifdef __WIN32
    if (fopen_s(&file,fichier,"rb") != 0)
    {
        fprintf(stderr,"Erreur : impossible d'ouvrir le fichier texture.jpg\n");
        exit(1);
    }
    #elif __GNUC__
    if ((file = fopen(fichier,"rb")) == 0)
    {
        fprintf(stderr,"Erreur : impossible d'ouvrir le fichier %s\n", fichier);
        exit(1);
    }
    #endif
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);

    if ((cinfo.image_width!=largimg2)||(cinfo.image_height!=hautimg2)) {
    fprintf(stdout,"Erreur : l'image doit etre de taille %dx%d\n", hautimg2, largimg2);
    exit(1);
    }
    if (cinfo.jpeg_color_space==JCS_GRAYSCALE) {
    fprintf(stdout,"Erreur : l'image doit etre de type RGB\n");
    exit(1);
    }

    jpeg_start_decompress(&cinfo);
    ligne = imageEcaille2;
    while (cinfo.output_scanline<cinfo.output_height)
    {
        ligne=imageEcaille2+3*largimg2*cinfo.output_scanline;
        jpeg_read_scanlines(&cinfo,&ligne,1);
    }
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

  //============================================================
    for(int i = 0; i < hautimg2; i++){
        for(int j = 0; j < largimg2; j++){
            textureEcaille2[i][j][0] = imageEcaille2[i*largimg2*3 + j*3];
            textureEcaille2[i][j][1] = imageEcaille2[i*largimg2*3 + j*3 + 1];
            textureEcaille2[i][j][2] = imageEcaille2[i*largimg2*3 + j*3 + 2];
        }
    }
}
/*========================================================================================*/
/**
    *@brief Montage des differentes parties du dragon i.e de la tête à la queue
    @details Fonction permettant d'afficher le dragon
*/
void dragon()
{
    /* effacement de l'image avec la couleur de fond */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_COLOR_MATERIAL);

    glLoadIdentity();
    glRotatef(angley,1.0,0.0,0.0);
    glRotatef(anglex,0.0,1.0,0.0);

    glOrtho(-zoom, zoom, -zoom, zoom, -zoom, zoom);


    glMatrixMode(GL_MODELVIEW);

        glTranslatef(0, animationMonteedragon, 0);

        glPushMatrix();
            glTranslatef(0.0, 0.0, move_spot_light);
            glLightfv(GL_LIGHT0, GL_POSITION,source_spot);
        glPopMatrix();

        glColor3f(0.75, 0.75, 0.75);

        // Corps
        glPushMatrix();
            initCorps();
            Corps();
        glPopMatrix();
        // Cou
        glPushMatrix();
            glColor3f(0.25, 0.25, 0.25);
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
                glColor3f(0.25, 0.25, 0.25);
                glutSolidSphere(1, 20, 20);
            glPopMatrix();

            //corne gauche
            glPushMatrix();
                glTranslatef(0.5, 1.85, -1.5);
                glRotatef(-100, 1, 0, 0);
                glColor3f(0.5, 0.5, 0.5);
                glutSolidCone(0.2, 1.5, 10, 10);
            glPopMatrix();

            //corne droite
                glPushMatrix();
                glTranslatef(-0.5, 1.85, -1.5);
                glRotatef(-100, 1, 0, 0);
                    glColor3f(0.5, 0.5, 0.5);
                    glutSolidCone(0.2, 1.5, 10, 10);
                glPopMatrix();

            //Oeil droite
            glPushMatrix();
                glTranslatef(-0.50, 1.35, -2.5);
                glRotatef(45, 1, 0, 0);
                glScalef(1,2,1);
                glColor3f(1.0, 0.0, 0.0);
                glutSolidSphere(0.25, 20, 20);
            glPopMatrix();

            //Oeil gauche
            glPushMatrix();
                glTranslatef(0.50, 1.35, -2.5);
                glRotatef(45, 1, 0, 0);
                glScalef(1,2,1);
                glColor3f(1.0, 0.0, 0.0);
                glutSolidSphere(0.25, 20, 20);

            glPopMatrix();
        glPopMatrix();

        // Queue
        glPushMatrix();
            glColor3f(0.5, 0.5, 0.5);
            glTranslatef(0, 0, 7);
            initQueue();
            Membre();
        glPopMatrix();

        // Patte devant droite
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(-2.5, -7.5, 0);
            glRotatef(90, 1, 0, 0);
            patteAvantDroite();
        glPopMatrix();

        //Patte avant gauche
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(2.5, -7.5, 0);
            glRotatef(90, 1, 0, 0);
            patteAvantGauche();
        glPopMatrix();

        //Patte arriere droite
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(2.5, -7.5, 13.5);
            glRotatef(90, 1, 0, 0);
            glRotatef(2*90, 0, 0, 1);
            patteArriereDroite();
        glPopMatrix();

        //Patte arriere gauche
        glPushMatrix();
            glScalef(0.5, 0.5, 0.5);
            glTranslatef(-2.5, -7.5, 13.5);
            glRotatef(90, 1, 0, 0);
            glRotatef(2*90, 0, 0, 1);
            patteArriereGauche();
        glPopMatrix();

        // Aile Gauche
        glPushMatrix();
            glTranslatef(0, 0, 4);
            glRotatef(animationAiles, 0, 0, 1);
            glRotatef(-50, 0, 1, 1);
            glRotatef(-90, 1, 0, 0);
            Aile(0);
        glPopMatrix();

        // Aile Gauche
        glPushMatrix();
            glTranslatef(0,  0, 4);
            glRotatef(-animationAiles, 0, 0, 1);
            glRotatef(210, 0, 1, 0);
            glRotatef(-30, 0, 0, 1);
            glRotatef(90, 1, 0, 0);
            Aile(1);
        glPopMatrix();

  glFlush();
  //On echange les buffers
  glutSwapBuffers();

}

/**
    * @brief Animations des ailes, montée et lumière
*/
void animation()
{
    if(anim)
    {
        if(fin) animationAiles -= 2;
        else animationAiles += 2;
        if(animationAiles <= 0) fin = false;
        if(animationAiles >= 60) fin = true;

        if(finMontee) animationMonteedragon -= 0.05;
        else animationMonteedragon += 0.05;
        if(animationMonteedragon >= 15) finMontee = true;
        if(animationMonteedragon <= 0)
        {
            finMontee = false;
            anim = false;
        }

        if(!anim)
        {
            animationMarche1 = 45;
            animationMarche2 = 0;
            animationMarche3 = 0;
            animationMarche4 = 45;
        }
        else
        {
            animationMarche1 = 45;
            animationMarche2 = 45;
            animationMarche3 = -45;
            animationMarche4 = -45;
        }
    }
    else
    {
        // Patte avant gauche
        if(finMarche1) animationMarche1 -= 0.5;
        else animationMarche1 += 0.5;
        if(animationMarche1 <= -45) finMarche1 = false;
        if(animationMarche1 >= 45) finMarche1 = true;

        // Patte avant droite
        if(finMarche2) animationMarche2 -= 0.5;
        else animationMarche2 += 0.5;
        if(animationMarche2 <= -45) finMarche2 = false;
        if(animationMarche2 >= 45) finMarche2 = true;


        // Patte arriere droite
        if(finMarche3) animationMarche3 -= 0.5;
        else animationMarche3 += 0.5;
        if(animationMarche3 <= -45) finMarche3 = false;
        if(animationMarche3 >= 45) finMarche3 = true;

        // Patte Arriere gauche
        if(finMarche4) animationMarche4 -= 0.5;
        else animationMarche4 += 0.5;
        if(animationMarche4 <= -45) finMarche4 = false;
        if(animationMarche4 >= 45) finMarche4 = true;

    }

    //lumière
    if(spot_light_on)
    {
        glEnable(GL_LIGHT0);
        move_spot_light += 0.025;
        if(move_spot_light >= 15) move_spot_light = 0;
    }
    else
    {
        glDisable(GL_LIGHT0);
        move_spot_light = 0;
    }
    glutPostRedisplay( );
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
    *@brief Fonction d'affiche du membre du dragon
*/
void Membre()
{
    int nbFaces = (nbCercle - 1) * nbPointParCercle;
    double x, y;
    // Texture 2
    // Application d'une seule texture sur toutes les faces
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,hautimg2,largimg2,0,GL_RGB,GL_UNSIGNED_BYTE,textureEcaille2);
    glEnable(GL_TEXTURE_2D);
    for(int i = 0; i < nbFaces; i++)
    {
        glBegin(GL_POLYGON);

            x = (ptMembre[fMembre[i][0]].x+ptMembre[fMembre[i][2]].x)/2.0;
            y = (ptMembre[fMembre[i][0]].y+ptMembre[fMembre[i][2]].y)/2.0;
            glNormal3f(x, y, 0);

            glTexCoord2f((i % nbPointParCercle)/(float)nbPointParCercle, ((nbCercle-1)-(i/nbPointParCercle))/(float)(nbCercle-1));
            glVertex3f(ptMembre[fMembre[i][0]].x, ptMembre[fMembre[i][0]].y, ptMembre[fMembre[i][0]].z);

            glTexCoord2f(((i % nbPointParCercle)+1)/(float)nbPointParCercle, ((nbCercle-1)-(i/nbPointParCercle))/(float)(nbCercle-1));
            glVertex3f(ptMembre[fMembre[i][1]].x, ptMembre[fMembre[i][1]].y, ptMembre[fMembre[i][1]].z);

            glTexCoord2f(((i % nbPointParCercle)+1)/(float)nbPointParCercle, ((nbCercle-2)-(i/nbPointParCercle))/(float)(nbCercle-1));
            glVertex3f(ptMembre[fMembre[i][2]].x, ptMembre[fMembre[i][2]].y, ptMembre[fMembre[i][2]].z);

            glTexCoord2f((i % nbPointParCercle)/(float)nbPointParCercle, ((nbCercle-2)-(i/nbPointParCercle))/(float)(nbCercle-1));
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
    *@brief Fonction affichage de la patte avant droite
*/
void patteAvantDroite()
{
    glColor3f(0.5, 0.5, 0.5);

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

    glPushMatrix();
        glRotated(animationMarche1, 1, 0, 0);
        // Bras
        glPushMatrix();
            glTranslatef(0, 0, 0.6);
            initMembre(0.8, 0.25, 4);
            Membre();
        glPopMatrix();
        // Pied
        glPushMatrix();
            glTranslatef(0, -0.5, 4.75);
            glScalef(1, 2, 1);
            glutSolidCube(1);
        glPopMatrix();

        ///Orteilles
        //gauche
        glPushMatrix();
            glTranslatef(-0.3, -1.1, 5);
            glRotatef(70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

            //milieu
        glPushMatrix();
            glTranslatef(0, -1.1, 5);
            glRotatef(70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

        //droite
        glPushMatrix();
            glTranslatef(0.3, -1.1, 5);
            glRotatef(70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();
    glPopMatrix();
}

/**
    *@brief Fonction affichage de la patte avant gauche
*/
void patteAvantGauche()
{
    glColor3f(0.5, 0.5, 0.5);

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

    glPushMatrix();
        glRotatef(animationMarche2, 1, 0, 0);
        // Bras
        glPushMatrix();
            glTranslatef(0, 0, 0.6);
            initMembre(0.8, 0.25, 4);
            Membre();
        glPopMatrix();
        // Pied
        glPushMatrix();
            glTranslatef(0, -0.5, 4.75);
            glScalef(1, 2, 1);
            glutSolidCube(1);
        glPopMatrix();

        ///Orteilles
        //gauche
        glPushMatrix();
            glTranslatef(0.3, -1.1, 5);
            glRotatef(70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

            //milieu
        glPushMatrix();
            glTranslatef(0, -1.1, 5);
            glRotatef(70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

        //droite
        glPushMatrix();
            glTranslatef(-0.3, -1.1, 5);
            glRotatef(70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();
    glPopMatrix();
}

/**
    *@brief Fonction affichage de la patte arrière droite
*/
void patteArriereDroite()
{
    glColor3f(0.5, 0.5, 0.5);

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

    glPushMatrix();
        glRotatef(-animationMarche3, 1, 0, 0);
        // Bras
        glPushMatrix();
            glTranslatef(0, 0, 0.6);
            initMembre(0.8, 0.25, 4);
            Membre();
        glPopMatrix();
        // Pied
        glPushMatrix();
            glTranslatef(0, 0.5, 4.75);
            glScalef(1, 2, 1);
            glutSolidCube(1);
        glPopMatrix();

        ///Orteilles
        //gauche
        glPushMatrix();
            glTranslatef(-0.3, 1, 5);
            glRotatef(-70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

            //milieu
        glPushMatrix();
            glTranslatef(0, 1, 5);
            glRotatef(-70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

        //droite
        glPushMatrix();
            glTranslatef(0.3, 1, 5);
            glRotatef(-70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();
    glPopMatrix();
}

/**
    *@brief Fonction affichage de la patte arrière gauche
*/
void patteArriereGauche()
{
    glColor3f(0.5, 0.5, 0.5);

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

    glPushMatrix();
        // Bras
        glRotatef(-animationMarche4, 1, 0, 0);

        glPushMatrix();
            glTranslatef(0, 0, 0.6);
            initMembre(0.8, 0.25, 4);
            Membre();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0.5, 4.75);
            glScalef(1, 2, 1);
            glutSolidCube(1);
        glPopMatrix();

        ///Orteilles
        //gauche
        glPushMatrix();
            glTranslatef(0.3, 1, 5);
            glRotatef(-70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

        //milieu
        glPushMatrix();
            glTranslatef(0, 1, 5);
            glRotatef(-70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();

        //droite
        glPushMatrix();
            glTranslatef(-0.3, 1, 5);
            glRotatef(-70, 1, 0, 0);
            glutSolidCone(0.15, 2, 10, 10);
        glPopMatrix();
    glPopMatrix();
}
/*=====================================================================================================================*/
/**
    *@brief Initialisation primitive de construction du corps
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

/**
    *@brief Fonction affiche du coprs
*/
void Corps()
{
    int nbFaces = (nbCercle - 1) * nbPointParCercle;
    double x, y;

    // Texture 1
    // Application de la texture sur chaque face
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,hautimg1,largimg1,0,GL_RGB,GL_UNSIGNED_BYTE,textureEcaille1);
    glEnable(GL_TEXTURE_2D);

    for(int i = 0; i < nbFaces; i++)
    {
        glBegin(GL_POLYGON);

            x = (ptMembre[fMembre[i][0]].x+ptMembre[fMembre[i][2]].x)/2.0;
            y = (ptMembre[fMembre[i][0]].y+ptMembre[fMembre[i][2]].y)/2.0;
            glNormal3f(x, y, 0);

            glTexCoord2d(0.0, 0.0);
            glVertex3f(ptMembre[fMembre[i][0]].x, ptMembre[fMembre[i][0]].y, ptMembre[fMembre[i][0]].z);
            glTexCoord2d(0.0, 1.0);
            glVertex3f(ptMembre[fMembre[i][1]].x, ptMembre[fMembre[i][1]].y, ptMembre[fMembre[i][1]].z);
            glTexCoord2d(1.0, 1.0);
            glVertex3f(ptMembre[fMembre[i][2]].x, ptMembre[fMembre[i][2]].y, ptMembre[fMembre[i][2]].z);
            glTexCoord2d(1.0, 0.0);
            glVertex3f(ptMembre[fMembre[i][3]].x, ptMembre[fMembre[i][3]].y, ptMembre[fMembre[i][3]].z);
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);

}

/*=====================================================================================================================*/

/**
    * @brief Fonction de contrcution des ailes
*/
void Aile(int i)
{
    glLineWidth(5.0);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,hautimg1,largimg1,0,GL_RGB,GL_UNSIGNED_BYTE,textureEcaille1);
    glEnable(GL_TEXTURE_2D);

//======================================//
    glPushMatrix();
        glBegin(GL_LINES);
            glColor3f(0.5,0.5,0.5);
            glVertex3f(2,5,0);
            glVertex3f(1.5,1.5,0);
            glVertex3f(1.5,1.5,0);
            glVertex3f(0,0,0);
            glVertex3f(0,0,0);
            glVertex3f(2,5,0);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3f(0.5,0.5,0.5);
            if(i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0);
            if(i)glTexCoord2d(0, 1);
            glVertex3f(1.5,1.5,0);
            if(i)glTexCoord2d(1, 0.5);
            glVertex3f(0,0,0);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3f(0.5,0.5,0.5);
            if(!i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0.01);
            if(!i)glTexCoord2d(0, 1);
            glVertex3f(1.5,1.5,0.01);
            if(!i)glTexCoord2d(1, 0.5);
            glVertex3f(0,0,0.01);
        glEnd();
    glPopMatrix();
//======================================//
    glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
            glVertex3f(2,5,0);
            glVertex3f(3.7,2.4,0);
            glVertex3f(3.7,2.4,0);
            glVertex3f(2.5,2.25,0);
            glVertex3f(2.5,2.25,0);
            glVertex3f(1.5,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
            if(i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0);
            if(i)glTexCoord2d(0, 1);
            glVertex3f(3.7,2.4,0);
            if(i)glTexCoord2d(1, 1);
            glVertex3f(2.5,2.25,0);
            if(i)glTexCoord2d(1, 0);
            glVertex3f(1.5,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
            if(!i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0.01);
            if(!i)glTexCoord2d(0, 1);
            glVertex3f(3.7,2.4,0.01);
            if(!i)glTexCoord2d(1, 1);
            glVertex3f(2.5,2.25,0.01);
            if(!i)glTexCoord2d(1, 0);
            glVertex3f(1.5,1.5,0.01);
        glEnd();
    glPopMatrix();
//======================================//
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
            glVertex3f(2,5,0);
            glVertex3f(7,3,0);
            glVertex3f(7,3,0);
            glVertex3f(5.25,3.25,0);
            glVertex3f(5.25,3.25,0);
            glVertex3f(3.7,2.4,0);
        glEnd();
        glBegin(GL_POLYGON);
            if(i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0);
            if(i)glTexCoord2d(0, 1);
            glVertex3f(7,3,0);
            if(i)glTexCoord2d(1, 1);
            glVertex3f(5.25,3.25,0);
            if(i)glTexCoord2d(1, 0);
            glVertex3f(3.7,2.4,0);
        glEnd();
        glBegin(GL_POLYGON);
            if(!i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0.01);
            if(!i)glTexCoord2d(0, 1);
            glVertex3f(7,3,0.01);
            if(!i)glTexCoord2d(1, 1);
            glVertex3f(5.25,3.25,0.01);
            if(!i)glTexCoord2d(1, 0);
            glVertex3f(3.7,2.4,0.01);
        glEnd();
    glPopMatrix();
//======================================//
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
            glVertex3f(2,5,0);
            glVertex3f(8,6,0);
            glVertex3f(8,6,0);
            glVertex3f(7,4.5,0);
            glVertex3f(7,4.5,0);
            glVertex3f(7,3,0);
        glEnd();
        glBegin(GL_POLYGON);
            if(i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0);
            if(i)glTexCoord2d(0, 1);
            glVertex3f(8,6,0);
            if(i)glTexCoord2d(1, 1);
            glVertex3f(7,4.5,0);
            if(i)glTexCoord2d(1, 0);
            glVertex3f(7,3,0);
        glEnd();
        glBegin(GL_POLYGON);
            if(!i)glTexCoord2d(0, 0);
            glVertex3f(2,5,0.01);
            if(!i)glTexCoord2d(0, 1);
            glVertex3f(8,6,0.01);
            if(!i)glTexCoord2d(1, 1);
            glVertex3f(7,4.5,0.01);
            if(!i)glTexCoord2d(1, 0);
            glVertex3f(7,3,0.01);
        glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);
}


/**
    * @brief Création de la lumière ambiante
*/
void illumination_ambiant()
{
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, couleur);
}


/**
    * @brief Création de la lumière de type spot
*/
void illumination_spot()
{
    //spécification des propriétés
    glLightfv(GL_LIGHT0, GL_POSITION,source_spot);

    glLightfv(GL_LIGHT0, GL_AMBIENT, amb_spot);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif_spot);
    glLightfv(GL_LIGHT0, GL_SPECULAR, spec_spot);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 4.0);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction_spot);

}

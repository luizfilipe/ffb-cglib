/******************
 *  Luiz Ricardo  *
 *   Luiz Filipe  *
 *   LuÌs Hiluy   *
 * Mateus Gadelha *
 *****************/

#include "../../src/ffb_cglib.h"

#define CLOUDS_AMOUNT 400
#define BUILDINGS_AMOUNT 100
#define GROUND_PIECES 100

Camera* cam = NULL;
Car* car = NULL;
SkyBox* sk = NULL;
Object3d* ground = NULL;
Object3d* rock = NULL;
Object3d* buildings[BUILDINGS_AMOUNT];
//Light* light = NULL;
GLfloat LightAmbient[]  = {1, 1, 1, 1};
GLfloat LightDiffuse[]  = {1, 1, 1, 1};
GLfloat LightPosition[] = {0, 2, 10, 1};
Billboard* clouds[CLOUDS_AMOUNT];

#define FALSE 0
#define TRUE 1
char keys[256];

void initialize()
{
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_FOG);
  glClearColor(.5, .8, 1, 0);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  
  glShadeModel(GL_SMOOTH);
  
  //cam = newCamera(initPoint3df(0,100,100), initPoint3df(0,180,0));

  char* path = "examples/environment/assets/";
  cam = newCamera(initPoint3df(0,2,10), initPoint3df(0,180,0));
  sk = newSkyBox(cam,
		  concat(path, "front.bmp"),
		  concat(path, "back.bmp"),
		  concat(path, "left.bmp"),
		  concat(path, "right.bmp"),
		  concat(path, "bottom.bmp"),
		  concat(path, "top.bmp"));

  car = newCar(cam);

  Model3d* plane = newModel3d(newMeshPlane(loadTexture(concat(path, "grass.bmp"))), newMaterial());

  ground = newObject3d(plane);
  ground->rotation.X = 90;
  ground->scale = initVector3df(10000, 1, 10000);
  ground->model->material->ambient = initColorf(0.4,0.4,0.4,1);
  
  /**/
  redefineTextureMap(&ground->model->mesh->vertexes[0], initPoint2df(0, 800));
  redefineTextureMap(&ground->model->mesh->vertexes[1], initPoint2df(800, 800));
  redefineTextureMap(&ground->model->mesh->vertexes[2], initPoint2df(800, 0));
  redefineTextureMap(&ground->model->mesh->vertexes[3], initPoint2df(0, 0));
  /**/
  
  Model3d* cube = newModel3d(newMeshCube(loadTexture(concat(path, "box.bmp"))), newMaterial() );
  rock = newObject3d(cube);
  rock->translation.Y = 2;
  
  srand((unsigned int)clock());
  
  int i;
  for(i=0; i<CLOUDS_AMOUNT; i++)
  {
    clouds[i] = newBillboard(PERPENDICULAR, cam, loadTexture(concat(path, "Cloud.bmp")));
    clouds[i]->object->translation = initPoint3df(1000 - (rand()%2000), (rand()%100) + 150, 1000 - (rand()%2000));
    clouds[i]->object->scale = initVector3df(160,80,160);
  }
  
  for(i=0; i<BUILDINGS_AMOUNT; i++)
  {
    buildings[i] = newObject3d( newModel3d(newMeshCube(loadTexture(concat(path, "outline.bmp"))), newMaterial()) );
    buildings[i]->scale = initVector3df(20, (rand()%90)+10, 20);
    
    buildings[i]->translation.X = ((i%(BUILDINGS_AMOUNT/10))*(buildings[i]->scale.X*2)) - ((BUILDINGS_AMOUNT/20) * 40) + 20;
    buildings[i]->translation.Y = buildings[i]->scale.Y/2;
    buildings[i]->translation.Z = ((i/(BUILDINGS_AMOUNT/10))*(buildings[i]->scale.Z*2)) - ((BUILDINGS_AMOUNT/20) * 40) + 20;
  }
  
  glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
};

void updateInput()
{
  if(keys[27])
  {
    exit(0);
  }
  
  if(keys[GLUT_KEY_UP])
  {
    accelerateCar(car);
  }
  else if(keys[GLUT_KEY_DOWN])
  {
    breakCar(car);
  }
  else
  {
    deccelerateCar(car);
  }
  
  if(keys[GLUT_KEY_LEFT])
  {
    steerLeftCar(car);
  }
  else if(keys[GLUT_KEY_RIGHT])
  {
    steerRightCar(car);
  }
  /**/
  if (keys['w'] || keys['W']) {
    cam->rotation.X += .4f;
  }
  
  if (keys['S'] || keys['s']) {
    cam->rotation.X -= .4f;
  }
  /**/
};

void update()
{
  updateInput();
  updateCar(car);
  
  int i;
  for(i=0; i<CLOUDS_AMOUNT; i++)
  {
    clouds[i]->object->translation.X += 0.1;
    
    if(clouds[i]->object->translation.X >= 1000)
    {
      clouds[i]->object->translation.X = -1000;
    }
  }
  
  //rock->translation.X += .01f;
  //rock->translation.Y += .01f;
  //rock->translation.Z += .01f;
  
  rock->rotation = initVector3df(++rock->rotation.X, ++rock->rotation.Y, ++rock->rotation.Z);
};

void draw()
{
  int i;
  
  drawCamera(cam);
  drawSkyBox(sk);
  
  glEnable(GL_BLEND);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  glColor4f(1, 1, 1, 0.2);
  for(i=0; i<CLOUDS_AMOUNT; i++)
  {
    drawBillboard(clouds[i]);
  }
  glColor4f(1, 1, 1, 1);
  glDisable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  
  drawObject3d(ground);
  
  for(i=0; i<BUILDINGS_AMOUNT; i++)
  {
    drawObject3d(buildings[i]);
  }
  
  drawObject3d(rock);
  
  glPushMatrix();
  glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
  glPopMatrix();
};

void destruction()
{
  
};

void reshapeFunction(GLsizei width, GLsizei height)
{
  if(height == 0)
  {
    height = 1;
  }
  
  glViewport(0, 0, width, height);		// Reset The Current Viewport And Perspective Transformation
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //GLKMatrix4makePerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 1400.0f);
  gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 1400.0f);
  glMatrixMode(GL_MODELVIEW);
};

void displayFunction()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
  glLoadIdentity();
  
  draw();
  
  glutSwapBuffers();
};

void keyboardFunction(unsigned char key, int x, int y)
{
  keys[key] = TRUE;
};

void specialKeyboardFuntion(int key, int x, int y)
{
  keys[key] = TRUE;
};

void keyboardUpFunction(unsigned char key, int x, int y)
{
  keys[key] = FALSE;
};

void specialKeyboardUpFunction(int key, int x, int y)
{
  keys[key] = FALSE;
};

void timerFunction(int t)
{
  update();
  glutPostRedisplay();
  glutTimerFunc(10, timerFunction, 0);
};

void runApplication()
{
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("3d environment");
  glutDisplayFunc(displayFunction);
  glutFullScreen();
  glutReshapeFunc(reshapeFunction);
  glutKeyboardFunc(keyboardFunction);
  glutKeyboardUpFunc(keyboardUpFunction);
  glutSpecialFunc(specialKeyboardFuntion);
  glutSpecialUpFunc(specialKeyboardUpFunction);
  glutTimerFunc(10, timerFunction, 0);
  initialize();
  glutMainLoop();
  destruction();
};

int main(int argc, char * argv[])
{
  glutInit(&argc, argv);
  runApplication();
  return EXIT_SUCCESS;
}

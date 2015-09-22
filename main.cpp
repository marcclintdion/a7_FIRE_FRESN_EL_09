////////////________#pragma comment(lib, "Opengl32.lib")


#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <iostream.h>

//using namespace std; //___used for string object

#include <GL/gl.h>
#include <GL/glu.h>

#include <fstream.h>

#include "headerFiles/freeImage.h"

#include <math.h>


#include "headerFiles/glext.h" 

bool keys[256], keypressed[256];
bool active=TRUE;
bool fullscreen=TRUE;

float screenWidth  = 1600;
float screenHeight = 1200;




double screenSpin = 0.0f;




DWORD GLOBAL_TIME;

DWORD inTheBeginning = 0;
DWORD frameStart = 0;
DWORD frameEnd = 0;


float eyePosition[]   = {0.16, -0.160003, -8.2};
float look_LEFT_RIGHT = 0.300048;
float look_UP_DOWN = 33.0999;





struct Vertex
{
	float tu, tv;                                    
	float r, g, b;                                  
	float x, y, z;                                   
}; 
struct Texture
{
    float u, v;                                   
};
struct Normals
{
    float r, g, b;                                   
}; 
struct Vertices
{
    float x, y, z;                                   
}; 




float spinFloat = 0.0f;

ofstream out("frameRate.cpp");

float frameNumber = 0.0f;

float pinWheelMainT = 0.0f;




           GLhandleARB fireFresnel;
           GLhandleARB fireFresnel_Vertex;
           GLhandleARB fireFresnel_Fragment;

           GLfloat lightPos_fireFresnel[]           =  {-104.68, 636.81, -732.19};
           GLfloat quadraticAttenuation_fireFresnel = 2.2;
           GLfloat LightAmbient_fireFresnel[]       = {1.0f, 1.0f, 1.0f, 1.0f};
           GLfloat LightDiffuse_fireFresnel[]       = {1.0f, 1.0f, 1.0f, 1.0f};
           GLfloat LightSpecular_fireFresnel[]      = {1.0f, 1.0f, 1.0f, 1.0f};
           GLfloat MaterialAmbient_fireFresnel[]    = {1.0f, 1.0f, 1.0f, 1.0f};
           GLfloat MaterialDiffuse_fireFresnel[]    = {1.0f, 1.0f, 1.0f, 1.0f};
           GLfloat MaterialEmission_fireFresnel[]   = {1.0f, 1.0f, 1.0f, 1.0f};
           GLfloat MaterialSpecular_fireFresnel[]   = {6.93007, 3.81, 1};
           GLfloat MaterialShininess_fireFresnel    = 36.6398;





GLuint    textureMap[300];
GLuint    normalMap[300];





#include <math.h>




HDC	hDC = NULL;
  HGLRC hRC = NULL;
    HWND hWnd = NULL;
      HINSTANCE hInstance = NULL;


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, int nCmdShow);
   LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

      void render  (void);
        void Init    (void);
          void shutDown(void);
            unsigned char *readShaderFile(const char *fileName);
              void initShader(void);
 
                 
                    int LoadGLTextureBMP(char *textureFileName, char *normalMapFileName, GLuint &textureMapID, GLuint &normalMapID);
                    int LoadGLTextureBMP(char *textureFileName, char *normalMapFileName,char *specularMapFileName, GLuint &textureMapID, GLuint &normalMapID, GLuint &specularMapID); 
                    int LoadGLTextureBMP(char *textureFileName, GLuint &textureMapID);                           
                          void readstr(FILE *f,char *string);
                           void setShaderConstants(void);
                           void runNmapShader(int numTriangles, const GLvoid *ArrayName, GLuint texMap, GLuint normMap);
                           void loadTexture(char *textureFileName, GLuint &textureMapID);
                           void ProcessKeyboard(void); 


void Dot3shader(void);



        #include "cpp/winInit.cpp"


        #include "cpp/SHADERtech.cpp"


#include "_MODEL_FOLDERS_/BLOCKISH_OBJECTS/sphere.cpp"








GLfloat movePiece[]  = {0,0,0};
GLfloat moveModel[]  = {0,0,0};
GLfloat moveObject[] = {0,0,0};


float rotateScene = 0;

GLfloat mainPosition[] = {0,0,0};

void render(void)//////////////////////_______RENDER_____RENDER____RENDER_______RENDER_____RENDER____RENDER_______RENDER_____RENDER____RENDER
{      
                              ProcessKeyboard();                              
                              glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
    
                              glMatrixMode( GL_PROJECTION );
                              glLoadIdentity();
                              gluPerspective( 45.24, screenWidth / screenHeight, 0.1, 1000.0);
                              
                              glTranslatef(eyePosition[0],eyePosition[1],eyePosition[2]);//glTranslatef(eyePosition[0],eyePosition[1],eyePosition[2]);
                              glRotatef(look_UP_DOWN, 1.0, 0.0, 0.0); 
                              glRotatef(look_LEFT_RIGHT, 0.0, 1.0, 0.0);
                              
                              
                              glMatrixMode( GL_MODELVIEW );
                                                               
                                                               
                                                               glLoadIdentity();

spinFloat += .5;
                                                
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glEnable(GL_LINE_SMOOTH);





                            glPushMatrix();
                                   //glTranslatef(1.5, 0, 1.5);
                                   glRotatef(spinFloat*2.0, 0.0, 1.0, 0.0);          
                                   
                                   glPushMatrix();
                                        glLoadIdentity();
                                        glRotatef(-spinFloat*2.0, 0.0, -1.0, 0.0);
                                        glLightfv(GL_LIGHT0,GL_POSITION,               lightPos_fireFresnel);
                                        glLightf (GL_LIGHT0,GL_QUADRATIC_ATTENUATION,  quadraticAttenuation_fireFresnel);                                    
                                   glPopMatrix();            
                                       
                                       
                                             glLightfv(GL_LIGHT0, GL_AMBIENT,     LightAmbient_fireFresnel);
                                             glLightfv(GL_LIGHT0, GL_DIFFUSE,     LightDiffuse_fireFresnel);
                                             glLightfv(GL_LIGHT0, GL_SPECULAR,    LightSpecular_fireFresnel);
                                             glMaterialfv(GL_FRONT, GL_AMBIENT,   MaterialAmbient_fireFresnel);
                                             glMaterialfv(GL_FRONT, GL_DIFFUSE,   MaterialDiffuse_fireFresnel);
                                             glMaterialfv(GL_FRONT, GL_EMISSION,  MaterialEmission_fireFresnel);
                                             glMaterialfv(GL_FRONT, GL_SPECULAR,  MaterialSpecular_fireFresnel);
                                             glMaterialf(GL_FRONT, GL_SHININESS, MaterialShininess_fireFresnel);   
                                   
                                   
                                       glUseProgramObjectARB(fireFresnel);
        
                                           int DOT3_textureID;
                                           DOT3_textureID = glGetUniformLocationARB(fireFresnel,"NormalMap");
                                           glUniform1iARB(DOT3_textureID,1);
                                           glActiveTextureARB(GL_TEXTURE1_ARB);
                                           glBindTexture(GL_TEXTURE_2D, normalMap[98]);

                                           int textureID;
                                           textureID = glGetUniformLocationARB(fireFresnel,"env");
                                           glUniform1iARB(textureID,0);    
                                           glActiveTextureARB(GL_TEXTURE0_ARB);//_____shaderParameters-->>>___RGB_tex
                                           glBindTexture(GL_TEXTURE_2D, textureMap[98]);//____shaderParameters-->>>___RGB_tex

	
                                           glInterleavedArrays( GL_T2F_N3F_V3F, 0, sphere);
                                       	   glDrawArrays( GL_TRIANGLES, 0, 1584);
                                      glUseProgramObjectARB(0);
                                  
                              glPopMatrix();      
                                  





//moveModel[0], moveModel[1], moveModel[2]   




SwapBuffers( hDC );
}


void ProcessKeyboard()
{
     
     if(keys['J'])
     {   
          MaterialSpecular_fireFresnel[0] -=  .01;             
     }
     if(keys['L'])
     {   
          MaterialSpecular_fireFresnel[0] +=  .01;             
     }     
     if(keys['I'])
     {   
          MaterialSpecular_fireFresnel[1] +=  .01;             
     }
     if(keys['K'])
     {   
          MaterialSpecular_fireFresnel[1] -=  .01;             
     }
     if(keys['U'])
     {   
          MaterialSpecular_fireFresnel[2] -=  .01;             
     }
     if(keys['O'])
     {   
          MaterialSpecular_fireFresnel[2] +=  .01;             
     }
    
     if(keys['V'])
     {   
           MaterialShininess_fireFresnel -= .01;             
     }
     if(keys['B'])
     {   
           MaterialShininess_fireFresnel += .01;             
     }    
    
    
    if (keys[VK_F8]) 			
	{
        ofstream out("lightPosition.cpp");
        
        out << "GLfloat MaterialSpecular_fireFresnel[] = {"<< MaterialSpecular_fireFresnel[0] << ", " << MaterialSpecular_fireFresnel[1] << ", " << MaterialSpecular_fireFresnel[2] << "};\n";
        out << "GLfloat MaterialShininess_fireFresnel   = " << MaterialShininess_fireFresnel  << ";\n\n"; 
    
        out << "   //-----------------------------------------------------------------------------------------------------------------------\n";            
        out << "   look_LEFT_RIGHT                  = "  << look_LEFT_RIGHT   << ";\n";
        out << "   look_UP_DOWN                     = "  << look_UP_DOWN      << ";\n";
        out << "   eyePosition[0]                   = "  << eyePosition[0]    << ";\n";
        out << "   eyePosition[1]                   = "  << eyePosition[1]    << ";\n";
        out << "   eyePosition[2]                   = "  << eyePosition[2]    << ";\n\n";    
        out << "   //-----------------------------------------------------------------------------------------------------------------------\n";      
    }
    


    if (keys['A'])
	{
          eyePosition[0]    += .05;
    }	
    if (keys['D'])
	{
          eyePosition[0]    -= .05;
    }

    if (keys['W'])
	{
          eyePosition[2] += .05;
    }
          if (keys['W'] && keys[VK_SHIFT])
	      {
                eyePosition[2] += .1;
          }    
	if (keys['S'])
	{
          eyePosition[2] -= .05;       
    }    
	      if (keys['S'] && keys[VK_SHIFT])
	      {
                eyePosition[2] -= .1;      
          }	
    
    if (keys['E'])
	{
          eyePosition[1] -= 0.05;
    }
	if (keys['Q'])
	{
          eyePosition[1] += 0.05;      
    }  

}




void Init( void )
{
	GLuint PixelFormat;
	
    PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW |PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 32;
	
	hDC = GetDC( hWnd );
	PixelFormat = ChoosePixelFormat( hDC, &pfd );
	SetPixelFormat( hDC, PixelFormat, &pfd);
	hRC = wglCreateContext( hDC );
	wglMakeCurrent( hDC, hRC );

	glEnable( GL_TEXTURE_2D );
	glEnable( GL_DEPTH_TEST );
    glDepthFunc(GL_LEQUAL);	
	
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

                  glMatrixMode( GL_PROJECTION );
                  glLoadIdentity();
                  gluPerspective( 45.24, screenWidth / screenHeight, 0.1, 1000);


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER,0.1f);
                             
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);   
    
glEnable(GL_LIGHT0);


   //-----------------------------------------------------------------------------------------------------------------------
   look_LEFT_RIGHT                  = -8.0999;
   look_UP_DOWN                     = 33.3999;
   eyePosition[0]                   = 0.16;
   eyePosition[1]                   = 0.0900001;
   eyePosition[2]                   = -2.95004;

   //-----------------------------------------------------------------------------------------------------------------------

                                         


loadTexture("_MODEL_FOLDERS_/BLOCKISH_OBJECTS/light_brownMarble.jpg",              textureMap[98]);
loadTexture("_MODEL_FOLDERS_/BLOCKISH_OBJECTS/squashedBox_2_DOT3.bmp",          normalMap[98]);





inTheBeginning = GetTickCount();

}

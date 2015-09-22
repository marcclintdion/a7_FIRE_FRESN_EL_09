varying vec4 V;
varying vec4 position;
varying vec3 lightPosMinusPos;

void main(void)
{
   V                  = gl_ModelViewMatrix * gl_Vertex;
   
       
   lightPosMinusPos =  gl_LightSource[0].position.xyz - position.xyz;
   
 
   gl_TexCoord[0]     = gl_MultiTexCoord0; 
   
   position           = gl_ModelViewProjectionMatrix * gl_Vertex;
   gl_Position        = position;
}


varying vec3 lightPosMinusPos;

varying vec4  position;	
varying vec4 V;			// vertex position
    
      
      
        vec3 normal;	// surface normal



//direction of brightest point in environment map
const vec3 Ln = vec3(-.913, 0.365, 0.183);

uniform sampler2D   env;
uniform sampler2D   NormalMap;

//lighting parameters -- could pass in as uniform
float r0 = .11;		// Fresnel reflectance at zero angle
vec4  ka = vec4(0.1, 0.1, 0.1, 0);
vec4  kd = vec4(0.1, 0.1, 0.1, 0);
vec4  ks = vec4(0.1, 0.1, 0.1, 0);
float es = 16.0;

		    
        vec3  lightDir1;
        float NdotL1;

        vec4  specular;

void main()
{
    vec3 NormalTex   =  texture2D(NormalMap,  gl_TexCoord[0].st).xyz;
    NormalTex        = (NormalTex - 0.5) ;
	normal           =  normalize(NormalTex);    
    

    lightDir1        =  normalize(lightPosMinusPos);     
     
    NdotL1           =  dot(normal,lightDir1);
    specular         =  vec4(6.93007, 3.81, 1.0, 0.0) *  pow(NdotL1, gl_FrontMaterial.shininess*3.0);     
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
           
    vec3  In         =  V.xyz; 
    vec3  Hn         =  Ln - In;

    vec4  col        =  kd  * 4.0;

    vec3  R          =  reflect(In, normal);
    vec3  RH         =  normalize(R - In);
    float fresnel    =  r0 + (1.0 - r0)*pow(1.0 + dot(In, RH), 5.0);
    vec4  tex        =  texture2D(env, 0.5 + 0.5 * normalize(R + vec3(0,0,1)).xy) * 2.0 * NdotL1;

    gl_FragColor     =  mix(col, tex, fresnel)* NdotL1+specular;
}



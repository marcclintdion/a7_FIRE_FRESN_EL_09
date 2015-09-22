


unsigned char *readShaderFile( const char *fileName )
{
    FILE *file = fopen( fileName, "r" );

    if( file == NULL )
    {
        MessageBox( NULL, "Cannot open shader file!", "ERROR",
            MB_OK | MB_ICONEXCLAMATION );
		return 0;
    }

    struct _stat fileStats;

    if( _stat( fileName, &fileStats ) != 0 )
    {
        MessageBox( NULL, "Cannot get file stats for shader file!", "ERROR",
                    MB_OK | MB_ICONEXCLAMATION );
        return 0;
    }

    unsigned char *buffer = new unsigned char[fileStats.st_size];

	int bytes = fread( buffer, 1, fileStats.st_size, file );

    buffer[bytes] = 0;

	fclose( file );

	return buffer;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP
   
     PFNGLCREATEPROGRAMOBJECTARBPROC  glCreateProgramObjectARB  = NULL;
     PFNGLDELETEOBJECTARBPROC         glDeleteObjectARB         = NULL;
     PFNGLUSEPROGRAMOBJECTARBPROC     glUseProgramObjectARB     = NULL;
     PFNGLCREATESHADEROBJECTARBPROC   glCreateShaderObjectARB   = NULL;
     PFNGLSHADERSOURCEARBPROC         glShaderSourceARB         = NULL;
     PFNGLCOMPILESHADERARBPROC        glCompileShaderARB        = NULL;
     PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB = NULL;
     PFNGLATTACHOBJECTARBPROC         glAttachObjectARB         = NULL;
     PFNGLGETINFOLOGARBPROC           glGetInfoLogARB           = NULL;
     PFNGLLINKPROGRAMARBPROC          glLinkProgramARB          = NULL;
     PFNGLGETUNIFORMLOCATIONARBPROC   glGetUniformLocationARB   = NULL;
     PFNGLUNIFORM1IARBPROC			  glUniform1iARB		    = NULL;
     PFNGLUNIFORM1FARBPROC            glUniform1fARB            = NULL; 
     PFNGLUNIFORM3FARBPROC			  glUniform3fARB			= NULL;     
     PFNGLUNIFORM4FARBPROC			  glUniform4fARB			= NULL;
     PFNGLUNIFORM3FVARBPROC           glUniform3fvARB           = NULL;     
     PFNGLUNIFORM4FVARBPROC           glUniform4fvARB           = NULL;
     PFNGLACTIVETEXTUREARBPROC		  glActiveTextureARB		= NULL;
     PFNGLUNIFORMMATRIX4FVARBPROC     glUniformMatrix4fvARB     = NULL;
     PFNGLMULTITEXCOORD2FARBPROC      glMultiTexCoord2fARB      = NULL;
     PFNGLMULTITEXCOORD3FARBPROC      glMultiTexCoord3fARB      = NULL;
     PFNGLMULTITEXCOORD2FVARBPROC      glMultiTexCoord2fvARB      = NULL;
     PFNGLMULTITEXCOORD3FVARBPROC      glMultiTexCoord3fvARB      = NULL;          
     PFNGLCLIENTACTIVETEXTUREARBPROC  glClientActiveTextureARB  = NULL;     
     


	   //glMultiTexCoord2fvARB      = (PFNGLMULTITEXCOORD2FvARBPROC)wglGetProcAddress("glMultiTexCoord2fvARB");
	  // glMultiTexCoord3fvARB      = (PFNGLMULTITEXCOORD3FvARBPROC)wglGetProcAddress("glMultiTexCoord3fvARB");
void Dot3shader( void )
{
    char *ext = (char*)glGetString( GL_EXTENSIONS );

    if( strstr( ext, "GL_ARB_shading_language_100" ) == NULL )
    {
        // This extension string indicates that the OpenGL Shading Language,
        // version 1.00, is supported.
        MessageBox(NULL,"GL_ARB_shading_language_100 extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
        return;
    }

    if( strstr( ext, "GL_ARB_shader_objects" ) == NULL )
    {
        MessageBox(NULL,"GL_ARB_shader_objects extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
        return;
    }
    else
    {
       glCreateProgramObjectARB  = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
       glDeleteObjectARB         = (PFNGLDELETEOBJECTARBPROC)wglGetProcAddress("glDeleteObjectARB");
       glUseProgramObjectARB     = (PFNGLUSEPROGRAMOBJECTARBPROC)wglGetProcAddress("glUseProgramObjectARB");
       glCreateShaderObjectARB   = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
       glShaderSourceARB         = (PFNGLSHADERSOURCEARBPROC)wglGetProcAddress("glShaderSourceARB");
       glCompileShaderARB        = (PFNGLCOMPILESHADERARBPROC)wglGetProcAddress("glCompileShaderARB");
       glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
       glAttachObjectARB         = (PFNGLATTACHOBJECTARBPROC)wglGetProcAddress("glAttachObjectARB");
       glGetInfoLogARB           = (PFNGLGETINFOLOGARBPROC)wglGetProcAddress("glGetInfoLogARB");
       glLinkProgramARB          = (PFNGLLINKPROGRAMARBPROC)wglGetProcAddress("glLinkProgramARB");
       glGetUniformLocationARB   = (PFNGLGETUNIFORMLOCATIONARBPROC)wglGetProcAddress("glGetUniformLocationARB");
       glUniform1iARB			 = (PFNGLUNIFORM1IARBPROC)wglGetProcAddress("glUniform1iARB");
       glUniform3fARB			 = (PFNGLUNIFORM3FARBPROC)wglGetProcAddress("glUniform3fARB");       
       glUniform4fARB			 = (PFNGLUNIFORM4FARBPROC)wglGetProcAddress("glUniform4fARB");
       glActiveTextureARB        = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
       glUniform1fARB            = (PFNGLUNIFORM1FARBPROC)wglGetProcAddress("glUniform1fARB");       
       glUniform3fvARB           = (PFNGLUNIFORM3FVARBPROC)wglGetProcAddress("glUniform3fvARB");       
       glUniform4fvARB           = (PFNGLUNIFORM4FVARBPROC)wglGetProcAddress("glUniform4fvARB");
       glUniformMatrix4fvARB     = (PFNGLUNIFORMMATRIX4FVARBPROC)wglGetProcAddress("glUniformMatrix4fvARB");
	   glMultiTexCoord2fARB      = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
	   glMultiTexCoord3fARB      = (PFNGLMULTITEXCOORD3FARBPROC)wglGetProcAddress("glMultiTexCoord3fARB");
	   glMultiTexCoord2fvARB      = (PFNGLMULTITEXCOORD2FVARBPROC)wglGetProcAddress("glMultiTexCoord2fvARB");
	   glMultiTexCoord3fvARB      = (PFNGLMULTITEXCOORD3FVARBPROC)wglGetProcAddress("glMultiTexCoord3fvARB");                     	   
       glClientActiveTextureARB  = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");       
     

        if( !glCreateProgramObjectARB  || !glDeleteObjectARB       || !glUseProgramObjectARB ||
            !glCreateShaderObjectARB   || !glCreateShaderObjectARB || !glCompileShaderARB    || 
            !glGetObjectParameterivARB || !glAttachObjectARB       || !glGetInfoLogARB       || 
            !glLinkProgramARB          || !glGetUniformLocationARB || !glUniform4fARB        ||
			!glUniform1iARB            || !glMultiTexCoord2fARB    || !glClientActiveTextureARB)
        {
            MessageBox(NULL,"One or more GL_ARB_shader_objects functions were not found",
                "ERROR",MB_OK|MB_ICONEXCLAMATION);
            return;
        }
    }


/////////////////____________________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP_____________SHADER_SETUP  

  
    const char *fireFresnel_VertexStrings[1];
    const char *fireFresnel_FragmentStrings[1];
   
    fireFresnel_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );    

	unsigned char *fireFresnel_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/BLOCKISH_OBJECTS/fireFresnel.vert" );
    fireFresnel_VertexStrings[0] = (char*)fireFresnel_VertexAssembly;
    glShaderSourceARB( fireFresnel_Vertex, 1, fireFresnel_VertexStrings, NULL );
    glCompileShaderARB( fireFresnel_Vertex);
    delete fireFresnel_VertexAssembly;

    fireFresnel_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *fireFresnel_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/BLOCKISH_OBJECTS/fireFresnel.frag" );
    fireFresnel_FragmentStrings[0] = (char*)fireFresnel_FragmentAssembly;
    glShaderSourceARB( fireFresnel_Fragment, 1, fireFresnel_FragmentStrings, NULL );
    glCompileShaderARB( fireFresnel_Fragment );
    
    delete fireFresnel_FragmentAssembly;

	fireFresnel = glCreateProgramObjectARB();
    glAttachObjectARB( fireFresnel, fireFresnel_Vertex );
    glAttachObjectARB( fireFresnel, fireFresnel_Fragment );

    glLinkProgramARB(fireFresnel);    

}



/////////////___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC
/////////////___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC
/////////////___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC
/////////////___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC
/////////////___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC___________________ANISOTROPIC
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
/////////////////////////////////_______________________LOAD___BMP__TEXTURE_MAPS_______________________LOAD___BMP__TEXTURE_MAPS
void loadTexture(char *textureFileName, GLuint &textureMapID)	
{
	FREE_IMAGE_FORMAT fifmt = FreeImage_GetFileType(textureFileName, 0);

	FIBITMAP *dib = FreeImage_Load(fifmt, textureFileName,0);

	dib = FreeImage_ConvertTo24Bits(dib);
	
    if( dib != NULL )
	{
        glGenTextures( 1, &textureMapID );
		glBindTexture( GL_TEXTURE_2D, textureMapID );
        
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT_ARB );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT_ARB );		
        glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );

		
		// This is important to note, FreeImage loads textures in
		// BGR format. Now we could just use the GL_BGR extension
		// But, we will simply swap the B and R components ourselves.
		// Firstly, allocate the new bit data doe the image.
		BYTE *bits = new BYTE[FreeImage_GetWidth(dib) * FreeImage_GetHeight(dib) * 3];

		// get a pointer to FreeImage's data.
		BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);

		// Iterate through the pixels, copying the data
		// from 'pixels' to 'bits' except in RGB format.
		for(int pix=0; pix<FreeImage_GetWidth(dib) * FreeImage_GetHeight(dib); pix++)
		{
			bits[pix*3+0]=pixels[pix*3+2];
			bits[pix*3+1]=pixels[pix*3+1];
			bits[pix*3+2]=pixels[pix*3+0];

		}
	     
        // The new 'glTexImage2D' function, the prime difference
		// being that it gets the width, height and pixel information
		// from 'bits', which is the RGB pixel data..
		glTexImage2D( GL_TEXTURE_2D, 0, 3, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_RGB, GL_UNSIGNED_BYTE, bits );
		
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), GL_RGB, GL_UNSIGNED_BYTE, bits);
		
		// Unload the image.
		// and free the bit data.
		FreeImage_Unload(dib);
		delete bits;
	}

}








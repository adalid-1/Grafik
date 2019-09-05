#pragma once


#include "core/app.h"


class MeshResource
{

public:
	//vertexbuffer 
	GLfloat* buf;
	GLuint vbo = 0;
	GLuint VbufferLen = 0;
	GLuint VbufferSize = 0;

	//Indexbuffer
	GLuint* ibuf;
	GLuint ibo = 0;
	GLuint IbufferLen;
	GLuint IbufferSize;

	//Vertex array object
	GLuint vao = 0;
	//Specifies the number of elements to be rendered. 
	GLuint numIndices;




	MeshResource(GLfloat* Vbuf, GLuint Vlength, GLuint* Ibuf, GLuint Ilength);

	void SetupVertexBuffer();
	void SetupIndexBuffer();
	void SetupVertexArrayObject();

	//Sets some things up
	void Setup();

	void DrawMesh(void);
	//Draws mesh without vao
	void DrawMesh2(void);

	void Test(void);



};




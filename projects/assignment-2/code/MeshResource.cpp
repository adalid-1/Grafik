#include "MeshResource.h"
#include <iostream>
MeshResource::MeshResource(GLfloat* Vbuf, GLuint Vlength, GLuint* Ibuf, GLuint Ilength)
{


    buf = Vbuf;
    ibuf = Ibuf;
	VbufferLen = Vlength;
	IbufferLen = Ilength;

}


//testar git kraken
int betson= 3;
char alfa = 'a';

//Fixa den h�r deklarationen om det inte g�r ha dynamiskt
void MeshResource::SetupVertexBuffer()
{

	//before all this load data into buf

	//Generate vertex buffer object (vbo), bind vbo
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//Uppload bufferdata to GPU
	VbufferSize = sizeof(GLfloat) * VbufferLen;
	glBufferData(GL_ARRAY_BUFFER, VbufferSize, buf, GL_STATIC_DRAW);

	//Setting up Vertex attribute pointers

	//tells the system that we are using 0th place in the shader
	glEnableVertexAttribArray(0);
	//tells the GPU what layout the vertex-buffer has ((is nullptr ok here?))
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, NULL);




}

void MeshResource::SetupIndexBuffer()
{
	//before all this load data into buf

	//Generate index buffer object (ibo), bind that b-boy
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	//Upload buffer data to GPU
	IbufferSize = sizeof(GLuint) * IbufferLen;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, IbufferSize, ibuf, GL_STATIC_DRAW);


}

void MeshResource::SetupVertexArrayObject()
{


	//Generate, Bind the vertex array object
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Placeholder arguments
	SetupVertexBuffer();
	SetupIndexBuffer();

	//Unbind vao
	glBindVertexArray(0);



}

void MeshResource::DrawMesh()
{
	//Bind the vao
	glBindVertexArray(vao);

	//Draw ((is nullptr ok here?))
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, NULL);

	//Unbind the VAO
	glBindVertexArray(0);


}

//Draw without Vertex Array Objects
void MeshResource::DrawMesh2(void)
{
	//Bind vbo
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//Set up vertex attribute pointers
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, NULL);

	//Bind ibo
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	//Draw
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, NULL);

	//Maybe unbind buffers here to be safe
}

void MeshResource::Test(void) {


    std::cout << "hejhopp" << std::endl;

}

void MeshResource::Setup() {
    SetupVertexArrayObject();
    SetupVertexBuffer();
    SetupIndexBuffer();
}

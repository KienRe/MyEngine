#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL.h>

#include "Shader.h"
#include "Texture.h"
#include "Window.h"
#include "Camera.h"

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"

float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};

float lightVertices[] = {
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,

	-0.5f, -0.5f,  0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	-0.5f, -0.5f,  0.5f,

	-0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,

	0.5f,  0.5f,  0.5f,
	0.5f,  0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,

	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f, -0.5f,  0.5f,
	-0.5f, -0.5f,  0.5f,
	-0.5f, -0.5f, -0.5f,

	-0.5f,  0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	0.5f,  0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f, -0.5f,
};

VertexArray vao;
Shader shader;
Texture t1;
Texture t2;
Camera camera;

VertexArray lightVAO;
Shader lightShader;

class Scene
{
public:
	Scene()
	{
		//Light
		VertexArray lightArray;
		VertexBuffer lightBuffer(lightVertices, sizeof(lightVertices));
		VertexBufferLayout lightLayout;

		lightLayout.Push<float>(3);

		lightArray.AddBuffer(lightBuffer, lightLayout);

		Shader lShader("res/shaders/light.vs", "res/shaders/light.fs");

		lightVAO = lightArray;
		lightShader = lShader;

		//Vertex Array Object / Vertex Buffer Object / Vertex Buffer Layout Setup
		VertexArray vertexArray;
		VertexBuffer vertexBuffer(vertices, sizeof(vertices));
		VertexBufferLayout vertexBufferLayout;

		vertexBufferLayout.Push<float>(3);
		vertexBufferLayout.Push<float>(3);

		vertexArray.AddBuffer(vertexBuffer, vertexBufferLayout);

		//Texture Setup
		Texture tex1("res/textures/test1.png", GL_RGB, 0);
		Texture tex2("res/textures/test2.png", GL_RGBA, 1);

		//Shader Setup
		Shader ourShader("res/shaders/shader.vs", "res/shaders/shader.fs");
		ourShader.use();

		ourShader.setInt("texture1", 0);
		ourShader.setInt("texture2", 1);

		//Assign members
		vao = vertexArray;
		shader = ourShader;
		t1 = tex1;
		t2 = tex2;
	}

	void Render()
	{
		camera.Update();

		//Create Transformation Matrixes
		glm::mat4 projection = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);

		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
		view = camera.GetViewMatrix();

		//Clear Color
		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Light
		glm::vec3 lightPos(0.0f, 0.0f, -1.0f);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f));

		lightShader.use();

		lightShader.setMat4("projection", projection);
		lightShader.setMat4("view", view);
		lightShader.setMat4("model", model);
		lightShader.setVec3("lightPos", lightPos);
		lightShader.setVec3("viewPos", camera.Position);

		lightShader.setVec3("material.ambient", 1.0f, 0.5f, 0.81f);
		lightShader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
		lightShader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
		lightShader.setFloat("material.shininess", 32.0f);

		lightVAO.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//Bind Shader
		shader.use();

		shader.setMat4("projection", projection);
		shader.setMat4("view", view);
		shader.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
		shader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));

		//Bind Textures
		//t1.Bind();
		//t2.Bind();


		//Bind Vertey Array Object
		vao.Bind();

		for (unsigned int i = 0; i < 10; i++)
		{
			// calculate the model matrix for each object and pass it to shader before drawing
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, -1.0f, -2.0f * i));
			float angle = 20.0f * i * (SDL_GetTicks() / 1000.0f);
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.7f));
			shader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glCheckError();
	}
};
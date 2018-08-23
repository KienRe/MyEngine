#version 330 core					
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 WorldPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	WorldPos = vec3(model * vec4(aPos,1.0));

	//Normal
	//Fixes distorted normals when non Uniform Scaling is applied
	//Transpose of the inverse of the rotation and scaling part of the model matrix
	Normal = mat3(transpose(inverse(model))) * aNormal;
}
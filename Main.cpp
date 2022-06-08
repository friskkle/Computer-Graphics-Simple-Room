#include "Mesh.h"
#include "objClass.h"
#include <iostream>


const int width = 800;
const int height = 800;

Vertex vertices[] =
{
	//     COORDINATES     //		NORMALS        /        COLORS            //   TexCoord 
	Vertex{glm::vec3(-25.0f,  10.0f,  25.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 4.0f)},	// Left 0
	Vertex{glm::vec3(-25.0f,  10.0f, -25.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 4.0f)}, 	// Left 1
	Vertex{glm::vec3(-25.0f, -10.0f, -25.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},	// Left 2
	Vertex{glm::vec3(-25.0f, -10.0f,  25.0f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 0.0f)},	// Left 3
														 
	Vertex{glm::vec3(-25.0f,  10.0f, -25.0f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 4.0f)},	// Back 4
	Vertex{glm::vec3(25.0f,  10.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 4.0f)}, 	// Back 5
	Vertex{glm::vec3(25.0f, -10.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 0.0f)},	// Back 6
	Vertex{glm::vec3(-25.0f, -10.0f, -25.0f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},	// Back 7
														 			   
	Vertex{glm::vec3( 25.0f,  10.0f,  25.0f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 4.0f)},	// Front 8
	Vertex{glm::vec3(-25.0f,  10.0f,  25.0f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 4.0f)}, 	// Front 9
	Vertex{glm::vec3(-25.0f, -10.0f,  25.0f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},	// Front 10
	Vertex{glm::vec3( 25.0f, -10.0f,  25.0f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 0.0f)},	// Front 11

	Vertex{glm::vec3(25.0f,  10.0f, -25.0f),  glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 4.0f)},	// Right 12
	Vertex{glm::vec3(25.0f,  10.0f,  25.0f),  glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 4.0f)}, 	// Right 13
	Vertex{glm::vec3(25.0f, -10.0f,  25.0f),  glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},	// Right 14
	Vertex{glm::vec3(25.0f, -10.0f, -25.0f),  glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 0.0f)},	// Right 15
											  
	Vertex{glm::vec3(-15.0f,  6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.2f, 3.2f)},		// Back-inner 16
	Vertex{glm::vec3( -5.0f,  6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.6f, 3.2f)},		// Back-inner 17
	Vertex{glm::vec3( -5.0f, -6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.6f, 0.8f)},		// Back-inner 18
	Vertex{glm::vec3(-15.0f, -6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.2f, 0.8f)},		// Back-inner 19
											  			 			  
	Vertex{glm::vec3(-25.0f,  6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 3.2f)},		// Back-side 20
	Vertex{glm::vec3( 25.0f,  6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 3.2f)}, 		// Back-side 21
	Vertex{glm::vec3( 25.0f, -6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(4.0f, 0.8f)},		// Back-side 22
	Vertex{glm::vec3(-25.0f, -6.0f, -25.0f),  glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.8f)},		// Back-side 23
};

Vertex vertices2[] =
{	//     COORDINATES     /     NORMALS	         //	COLORS	   / TexCoord  
	Vertex{glm::vec3(-25.0f, -10.0f,  25.0f),  glm::vec3(0.0f, 1.0f, 0.0f),   glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(0.0f, 3.0f)},	 // 0
	Vertex{glm::vec3(-25.0f, -10.0f, -25.0f),  glm::vec3(0.0f, 1.0f, 0.0f),   glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(0.0f, 0.0f)},    // 1
	Vertex{glm::vec3(25.0f, -10.0f, -25.0f),  glm::vec3(0.0f, 1.0f, 0.0f),   glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(3.0f, 0.0f)},    // 2
	Vertex{glm::vec3(25.0f, -10.0f,  25.0f),  glm::vec3(0.0f, 1.0f, 0.0f),   glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(3.0f, 3.0f)},    // 3
	Vertex{glm::vec3(-25.0f,  10.0f,  25.0f),  glm::vec3(0.0f, -1.0f,  0.0f),  glm::vec3(0.0f, -1.0f, 0.0f),    glm::vec2(4.0f, 4.0f)},    // 4
	Vertex{glm::vec3(-25.0f,  10.0f, -25.0f),  glm::vec3(0.0f, -1.0f,  0.0f),  glm::vec3(0.0f, -1.0f, 0.0f),    glm::vec2(0.0f, 4.0f)},     // 5
	Vertex{glm::vec3(25.0f,  10.0f, -25.0f),   glm::vec3(0.0f, -1.0f,  0.0f),   glm::vec3(0.0f, -1.0f, 0.0f),   glm::vec2(0.0f, 0.0f)},    // 6
	Vertex{glm::vec3(25.0f,  10.0f,  25.0f),   glm::vec3(0.0f, -1.0f,  0.0f),   glm::vec3(0.0f, -1.0f, 0.0f),   glm::vec2(4.0f, 0.0f)}    // 7
};

GLuint indices[] =
{
	0, 1, 2, // left 
	0, 3, 2,
	4, 5, 21, // back 
	4, 20, 21,
	20, 23, 19,
	20, 16, 19,
	17, 21, 22,
	17, 18, 22,
	23, 7, 6,
	23, 22, 6,
	8, 9, 10, // front
	8, 11, 10,
	12, 13, 14, // right
	12, 15, 14
};

GLuint indices2[] =
{
	0, 1, 2,
	0, 3, 2,
	4, 5, 6,
	4, 7, 6
};

Vertex lightVertices[] =
{ //     COORDINATES     //
	 Vertex{glm::vec3(-0.1f, -0.1f,   0.1f)},
	 Vertex{glm::vec3(-0.1f, -0.1f,  -0.1f)},
	 Vertex{glm::vec3( 0.1f, -0.1f,  -0.1f)},
	 Vertex{glm::vec3( 0.1f, -0.1f,   0.1f)},
	 Vertex{glm::vec3(-0.1f,  0.1f,   0.1f)},
	 Vertex{glm::vec3(-0.1f,  0.1f,  -0.1f)},
	 Vertex{glm::vec3( 0.1f,  0.1f,  -0.1f)},
	 Vertex{glm::vec3( 0.1f,  0.1f,   0.1f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

float rectangleVertices[] =
{
	// Coords    // texCoords
	 1.0f, -1.0f,  1.0f, 0.0f,
	-1.0f, -1.0f,  0.0f, 0.0f,
	-1.0f,  1.0f,  0.0f, 1.0f,

	 1.0f,  1.0f,  1.0f, 1.0f,
	 1.0f, -1.0f,  1.0f, 0.0f,
	-1.0f,  1.0f,  0.0f, 1.0f
};

int main() {
	printf("program start\n");
	// Initialize GLFW
	glfwInit();


	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels,
	GLFWwindow* window = glfwCreateWindow(width, height, "TestApp", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window\n";
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);


	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	Texture textures[]
	{
		Texture("whiteBrickWall.png", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};

	Texture textures2[]
	{
		Texture("woodenFloor.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};

	Texture textures3[]
	{
		Texture("desktex.png", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};

	Texture textures4[]
	{
		Texture("gray.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};

	Texture textures5[]
	{
		Texture("wood_albedo.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create wall mesh
	Mesh wall(verts, ind, tex);

	// Floor
	Shader shaderProgram2("default.vert", "default.frag");
	std::vector <Vertex> verts2(vertices2, vertices2 + sizeof(vertices2) / sizeof(Vertex));
	std::vector <GLuint> ind2(indices2, indices2 + sizeof(indices2) / sizeof(GLuint));
	std::vector <Texture> tex2(textures2, textures2 + sizeof(textures2) / sizeof(Texture));
	// Create floor mesh
	Mesh floor(verts2, ind2, tex2);

	Shader objShader("default.vert", "default.frag");
	std::vector <Vertex> verts3;
	std::vector <GLuint> ind3;
	std::vector <Texture> tex3(textures3, textures3 + sizeof(textures3) / sizeof(Texture));
	Object cat("MiltonDesk.OBJ");
	cat.prep(verts3, ind3);
	Mesh neko(verts3, ind3, tex3);

	Shader obj2("default.vert", "default.frag");
	std::vector <Vertex> verts4;
	std::vector <GLuint> ind4;
	std::vector <Texture> tex4(textures4, textures4 + sizeof(textures4) / sizeof(Texture));
	Object bed("scaledbed.OBJ");
	bed.prep(verts4, ind4);
	Mesh sleep(verts4, ind4, tex4);

	Shader windows("default.vert", "default.frag");
	std::vector <Vertex> wvert;
	std::vector <GLuint> wind;
	std::vector <Texture> wtex(textures5, textures5 + sizeof(textures4) / sizeof(Texture));
	Object windowl("windowframe.obj");
	windowl.prep(wvert, wind);
	Mesh windf(wvert, wind, wtex);


	Shader lightShader("light.vert", "light.frag");
	// Store mesh data in vectors for the mesh
	std::vector <Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector <GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	// Crate light mesh
	Mesh light(lightVerts, lightInd, tex);


	std::vector <Vertex> cvert;
	std::vector <GLuint> cind;
	Object cube1("Cube.obj");
	cube1.prep(cvert, cind);
	Mesh cube(cvert, cind, tex);


	Shader frameBufferProgram("frameBuffer.vert", "frameBuffer.frag");
	Shader shadowMapProgram("shadowMap.vert", "shadowMap.frag");
	Shader shadowCubeMapProgram("shadowCubeMap.vert", "shadowCubeMap.frag", "shadowCubeMap.geom");

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(1.0f, 6.0f, 10.0f);

	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	frameBufferProgram.Activate();
	glUniform1i(glGetUniformLocation(frameBufferProgram.ID, "screenTexture"), 0);

	
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 roomPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 roomModel = glm::mat4(1.0f);
	roomModel = glm::translate(roomModel, roomPos);

	glm::vec3 objPos = glm::vec3(-150.0f, -100.0f, 0.0f);
	glm::mat4 objModel = glm::mat4(0.1f);
	objModel = glm::translate(objModel, objPos);

	glm::vec3 objPos2 = glm::vec3(15.0f, -10.0f, 0.0f);
	glm::mat4 objModel2 = glm::mat4(1.0f);
	objModel2 = glm::translate(objModel2, objPos2);

	glm::vec3 windPos = glm::vec3(-100.0f, 0.0f, -250.0f);
	glm::mat4 windModel = glm::mat4(0.1f);
	windModel = glm::translate(windModel, windPos);

	glm::vec3 cubePos = glm::vec3(0.0f, -0.0f, -10.0f);
	glm::mat4 cubeModel = glm::mat4(1.0f);
	cubeModel = glm::translate(cubeModel, cubePos);


	// Prepare framebuffer rectangle VBO and VAO
	unsigned int rectVAO, rectVBO;
	glGenVertexArrays(1, &rectVAO);
	glGenBuffers(1, &rectVBO);
	glBindVertexArray(rectVAO);
	glBindBuffer(GL_ARRAY_BUFFER, rectVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), &rectangleVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));


	// Creates the frame buffer object
	unsigned int FBO;
	glGenFramebuffers(1, &FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);

	// Create Framebuffer Texture
	unsigned int framebufferTexture;
	glGenTextures(1, &framebufferTexture);
	glBindTexture(GL_TEXTURE_2D, framebufferTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // Prevents edge bleeding
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Prevents edge bleeding
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebufferTexture, 0);

	// Create Render Buffer Object
	unsigned int RBO;
	glGenRenderbuffers(1, &RBO);
	glBindRenderbuffer(GL_RENDERBUFFER, RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);


	// Error checking framebuffer
	auto fboStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (fboStatus != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "Framebuffer error: " << fboStatus << std::endl;


	// Framebuffer for Shadow Map
	unsigned int shadowMapFBO;
	glGenFramebuffers(1, &shadowMapFBO);

	// Texture for Shadow Map FBO
	unsigned int shadowMapWidth = 2048, shadowMapHeight = 2048;
	unsigned int shadowMap;
	glGenTextures(1, &shadowMap);
	glBindTexture(GL_TEXTURE_2D, shadowMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapWidth, shadowMapHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	// Prevents darkness outside the frustrum
	float clampColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, clampColor);

	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMap, 0);
	// Needed since we don't touch the color buffer
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// Matrices needed for the light's perspective
	float farPlane = 150.0f;
	glm::mat4 orthgonalProjection = glm::ortho(-35.0f, 35.0f, -35.0f, 35.0f, 0.1f, farPlane);
	glm::mat4 perspectiveProjection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, farPlane);
	glm::mat4 lightView = glm::lookAt(lightPos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 lightProjection = perspectiveProjection * lightView;
	
	shadowMapProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shadowMapProgram.ID, "lightProjection"), 1, GL_FALSE, glm::value_ptr(lightProjection));
	

	// Framebuffer for Cubemap Shadow Map
	unsigned int pointShadowMapFBO;
	glGenFramebuffers(1, &pointShadowMapFBO);

	// Texture for Cubemap Shadow Map FBO
	unsigned int depthCubemap;
	glGenTextures(1, &depthCubemap);

	glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubemap);
	for (unsigned int i = 0; i < 6; ++i)
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT,
			shadowMapWidth, shadowMapHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glBindFramebuffer(GL_FRAMEBUFFER, pointShadowMapFBO);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthCubemap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);


	// Matrices needed for the light's perspective on all faces of the cubemap
	glm::mat4 shadowProj = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, farPlane);
	glm::mat4 shadowTransforms[] =
	{
	shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(1.0, 0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)),
	shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(-1.0, 0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)),
	shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 0.0, 1.0)),
	shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0, 0.0, -1.0)),
	shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)),
	shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, -1.0, 0.0))
	};
	// Export all matrices to shader
	shadowCubeMapProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shadowCubeMapProgram.ID, "shadowMatrices[0]"), 1, GL_FALSE, glm::value_ptr(shadowTransforms[0]));
	glUniformMatrix4fv(glGetUniformLocation(shadowCubeMapProgram.ID, "shadowMatrices[1]"), 1, GL_FALSE, glm::value_ptr(shadowTransforms[1]));
	glUniformMatrix4fv(glGetUniformLocation(shadowCubeMapProgram.ID, "shadowMatrices[2]"), 1, GL_FALSE, glm::value_ptr(shadowTransforms[2]));
	glUniformMatrix4fv(glGetUniformLocation(shadowCubeMapProgram.ID, "shadowMatrices[3]"), 1, GL_FALSE, glm::value_ptr(shadowTransforms[3]));
	glUniformMatrix4fv(glGetUniformLocation(shadowCubeMapProgram.ID, "shadowMatrices[4]"), 1, GL_FALSE, glm::value_ptr(shadowTransforms[4]));
	glUniformMatrix4fv(glGetUniformLocation(shadowCubeMapProgram.ID, "shadowMatrices[5]"), 1, GL_FALSE, glm::value_ptr(shadowTransforms[5]));
	glUniform3f(glGetUniformLocation(shadowCubeMapProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	glUniform1f(glGetUniformLocation(shadowCubeMapProgram.ID, "farPlane"), farPlane);



	// Creates the camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.1f, 0.13f, 0.2f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

		// Depth testing needed for Shadow Map
		glEnable(GL_DEPTH_TEST);

		// Preparations for the Shadow Map
		glViewport(0, 0, shadowMapWidth, shadowMapHeight);
		glBindFramebuffer(GL_FRAMEBUFFER, pointShadowMapFBO);
		glClear(GL_DEPTH_BUFFER_BIT);
		
		floor.Draw(shadowCubeMapProgram, camera, roomModel, lightPos, lightColor, 1);
		wall.Draw(shadowCubeMapProgram, camera, roomModel, lightPos, lightColor, 1);
		windf.Draw(shadowCubeMapProgram, camera, windModel, lightPos, lightColor, 1);
		sleep.Draw(shadowCubeMapProgram, camera, objModel2, lightPos, lightColor, 1);
		neko.Draw(shadowCubeMapProgram, camera, objModel, lightPos, lightColor, 1);
		cube.Draw(shadowCubeMapProgram, camera, cubeModel, lightPos, lightColor, 1);
		

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		// Switch back to the default viewport
		glViewport(0, 0, width, height);
		// Bind the custom framebuffer
		glBindFramebuffer(GL_FRAMEBUFFER, FBO);
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Enable depth testing since it's disabled when drawing the framebuffer rectangle
		glEnable(GL_DEPTH_TEST);

		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, farPlane);
		
		// Send the light matrix to the shader
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "lightProjection"), 1, GL_FALSE, glm::value_ptr(lightProjection));
		glUniform1f(glGetUniformLocation(shaderProgram.ID, "farPlane"), farPlane);

		// Bind the Shadow Map
		glActiveTexture(GL_TEXTURE0 + 1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubemap);
		glUniform1i(glGetUniformLocation(shaderProgram.ID, "shadowCubeMap"), 1);

		//Draws different meshes
		wall.Draw(shaderProgram, camera, roomModel, lightPos, lightColor, 1);
		floor.Draw(shaderProgram, camera, roomModel, lightPos, lightColor, 1);
		sleep.Draw(shaderProgram, camera, objModel2, lightPos, lightColor, 1);
		neko.Draw(shaderProgram, camera, objModel, lightPos, lightColor, 1);
		windf.Draw(shaderProgram, camera, windModel, lightPos, lightColor, 1);
		cube.Draw(shaderProgram, camera, cubeModel, lightPos, lightColor, 1);
		light.Draw(lightShader, camera, lightModel, lightPos, lightColor, 0);

		// Bind the default framebuffer
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		// Draw the framebuffer rectangle
		frameBufferProgram.Activate();
		glBindVertexArray(rectVAO);
		glDisable(GL_DEPTH_TEST); // prevents framebuffer rectangle from being discarded
		glBindTexture(GL_TEXTURE_2D, framebufferTexture);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


	// Delete all the objects we've created
	shaderProgram.Delete();
	shaderProgram2.Delete();
	objShader.Delete();
	obj2.Delete();
	windows.Delete();
	lightShader.Delete();
	glDeleteFramebuffers(1, &FBO);
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}
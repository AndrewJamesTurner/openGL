// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const int WIDTH = 800;
const int HEIGHT = 600;

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "void main()\n"
                                   "{\n"
                                   "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                   "}\0";
const GLchar* fragmentShaderSourceOrange = "#version 330 core\n"
                                     "out vec4 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                     "}\n\0";

const GLchar* fragmentShaderSourceYellow = "#version 330 core\n"
                                     "out vec4 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
                                     "}\n\0";

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, WIDTH, HEIGHT);
    glfwSetKeyCallback(window, key_callback);

    // wire frame
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // solid
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint fragmentShaderOrange;
    fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderOrange, 1, &fragmentShaderSourceOrange, NULL);
    glCompileShader(fragmentShaderOrange);

    glGetShaderiv(fragmentShaderOrange, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

	GLuint fragmentShaderYellow;
    fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceYellow, NULL);
    glCompileShader(fragmentShaderYellow);

    glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint shaderProgramOrange;
    shaderProgramOrange = glCreateProgram();
    glAttachShader(shaderProgramOrange, vertexShader);
    glAttachShader(shaderProgramOrange, fragmentShaderOrange);
    glLinkProgram(shaderProgramOrange);

    glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgramOrange, 512, NULL, infoLog);
        std::cout << "ERROR:LinkProgram\n" << infoLog << std::endl;
    }

	GLuint shaderProgramYellow;
    shaderProgramYellow = glCreateProgram();
    glAttachShader(shaderProgramYellow, vertexShader);
    glAttachShader(shaderProgramYellow, fragmentShaderYellow);
    glLinkProgram(shaderProgramYellow);

    glGetProgramiv(shaderProgramYellow, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgramYellow, 512, NULL, infoLog);
        std::cout << "ERROR:LinkProgram\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShaderOrange);
	glDeleteShader(fragmentShaderYellow);


    GLfloat vertices[] = {
        0.0f,  0.5f, 0.0f,  // Top Right
        0.0f, -0.5f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  // Bottom Left
        -0.5f,  0.5f, 0.0f,   // Top Left
		0.5f,   -0.5f,  0.0f
    };
    
	GLuint indicesA[] = {  // Note that we start from 0!
        3, 2, 1
    };

	GLuint indicesB[] = {  // Note that we start from 0!
        0, 1, 4    
    };

    
	GLuint VAO_A;
    GLuint VBO_A;
    GLuint EBO_A;

    glGenVertexArrays(1, &VAO_A);
    glGenBuffers(1, &VBO_A);
    glGenBuffers(1, &EBO_A);

    glBindVertexArray(VAO_A);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_A);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_A);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesA), indicesA, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);


	GLuint VAO_B;
    GLuint VBO_B;
    GLuint EBO_B;

    glGenVertexArrays(1, &VAO_B);
    glGenBuffers(1, &VBO_B);
    glGenBuffers(1, &EBO_B);

    glBindVertexArray(VAO_B);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_B);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_B);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesB), indicesB, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);


    // Program loop
    while(!glfwWindowShouldClose(window)) {

        // Check and call events
        glfwPollEvents();

        // Rclear screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		// load shaderprogram 
        glUseProgram(shaderProgramOrange);

		// bind the VOA of the thing to draw
        glBindVertexArray(VAO_A);

		// draw it
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// unbind the thing to draw
        glBindVertexArray(0);



		// load shaderprogram 
        glUseProgram(shaderProgramYellow);

		// bind the VOA of the thing to draw
        glBindVertexArray(VAO_B);

		// draw it
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// unbind the thing to draw
        glBindVertexArray(0);




        // Swap the buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


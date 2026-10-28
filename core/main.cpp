// import Engine;
// import Math;

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
import std;

const char *vertexShaderSource = R"(

#version 460 core

layout (location = 0) in vec3 aPos;

uniform float u_speed;

void main(){
    gl_Position = vec4(sin(aPos.x + u_speed) ,cos(aPos.y + u_speed),aPos.z,1.0);
}

)";

const char *fragmentShaderSource = R"(

#version 460 core

#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
out vec4 color;

void main(){
    color = vec4(abs(sin(u_time)),0.5,0.0,1.0);
}


)";

void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main()
{

    // Engine engine;

    // const bool engineStarted = engine.InitEngine();

    // if (!engineStarted)
    // {
    //     std::println("Could Initialize Engine.");
    //     return -1;
    // }

    // engine.CoreLoop();

    glfwSetErrorCallback(error_callback);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1000, 500, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glViewport(0, 0, 1000, 500);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_DEPTH_TEST);
    glPointSize(5.0);

    // Create open gl buffers
    float vertices[] = {
        0.0f, 0.1f, 0.0f,
        0.1f, 0.2f, 0.0f,
        0.0f, 0.3f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.3f, 0.5f, 0.0f,
        0.2f, 0.25f, 0.0f,
        0.4f, 0.2f, .5f,
        0.4f, 0.5f, 1.0f,
        0.0f, 0.1f, 0.0f,
        0.1f, 0.2f, 0.0f,
        0.0f, 0.3f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.3f, 0.5f, 0.0f,
        0.2f, 0.25f, 0.0f,
        0.4f, 0.2f, .5f,
        0.4f, 0.5f, 1.0f,
        0.0f, 0.1f, 0.0f,
        0.1f, 0.2f, 0.0f,
        0.0f, 0.3f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.3f, 0.5f, 0.0f,
        0.2f, 0.25f, 0.0f,
        0.4f, 0.2f, .5f,
        0.4f, 0.5f, 1.0f,
        0.0f, 0.1f, 0.0f,
        0.1f, 0.2f, 0.0f,
        0.0f, 0.3f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.1f, 0.4f, 0.0f,
        0.3f, 0.5f, 0.0f,
        0.2f, 0.25f, 0.0f,
        0.4f, 0.2f, .5f,
        0.4f, 0.5f, 1.0f};

    // float vertices[] = {
    //         -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    //         0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    //         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    //         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    //         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    //         -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

    //         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    //         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    //         0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    //         0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    //         -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
    //         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

    //         -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    //         -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    //         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    //         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    //         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    //         -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

    //         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    //         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    //         0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    //         0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    //         0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    //         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

    //         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    //         0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
    //         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    //         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    //         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    //         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

    //         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    //         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    //         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    //         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    //         -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
    //         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};

    // create vertext buffer object
    unsigned int vbo;

    // Create VBO and VAO and Generate buffers and arrays.
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &vbo);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind buffer data
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set Vertex Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Create Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Create Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    int success;
    char infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Create Program
    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // Delete Shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLint timeLocation = glGetUniformLocation(program, "u_time");

    GLfloat speed = glGetUniformLocation(program, "u_speed");

    float previousTime = 0.0f;
    float lag = 0.16f;
    float currentSpeed = 1.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        float time = static_cast<float>(glfwGetTime());

        float currentTime = static_cast<float>(glfwGetTime());

        float deltaTime = static_cast<float>((currentTime - previousTime) * 1000.0f);

        previousTime = currentTime;

        // std::println("delta time: {}", time);

        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(program);
        glDrawArrays(GL_POINTS, 0, 36);
        glDrawArrays(GL_LINES, 0, 36);
        // glDrawArrays(GL_TRIANGLES, 0, 36);
        glUniform1f(timeLocation, time);
        glUniform1f(speed, time * 0.8);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &vbo);

    // glDeleteBuffers(0, &vbo);
    glfwTerminate();
    return 0;
}
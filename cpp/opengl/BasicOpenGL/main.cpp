#include <stdlib.h>
#include <iostream>
#include <string>
#include <GLUT/glut.h>

const int height = 800;
const int width = 1280;
uint32_t* data = 0;
GLint glsl_texture;

const GLchar vertex_shader_code[] =
    "attribute vec4 vPosition;\n"
    "varying vec2 yuvTexCoords;\n"
    "void main(void) {\n"
        "yuvTexCoords = vec2(vPosition.x/2.0, vPosition.y/2.0) + vec2(0.5, 0.5);"
        "gl_Position = vPosition;\n"
    "}";

const GLchar color_shader_code[] =
    //"#version 330 core\n"
    "varying vec2 yuvTexCoords;\n"
    "uniform sampler2D myTexture;\n"
    "void main() {\n"
    "   float r = texture2D(myTexture, yuvTexCoords).r;\n"
    "   float g = texture2D(myTexture, yuvTexCoords).g;\n"
    "   float b = texture2D(myTexture, yuvTexCoords).b;\n"
    "   gl_FragColor = vec4(r, g, b, 1.0);\n"
    "}";

GLuint texture;
GLuint prog;
GLuint gvPositionHandle;

void display(void)
{
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glUseProgram(prog);
    glActiveTexture(GL_TEXTURE0);

    glsl_texture = glGetUniformLocation(prog, "myTexture");
    if(glsl_texture < 0) throw;

    glUniform1i(glsl_texture, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    float sz = 1.0f;
    glTexCoord2f(0.0f, 1.0f);glVertex2f(-sz, -sz);
    glTexCoord2f(1.0f, 1.0f);glVertex2f( sz, -sz);
    glTexCoord2f(1.0f, 0.0f);glVertex2f( sz,  sz);
    glTexCoord2f(0.0f, 0.0f);glVertex2f(-sz,  sz);
    glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void idle(void)
{
    glutPostRedisplay();
}

extern int load_texture (const char * filename,
        unsigned char * dest,
        const int format,
        const unsigned int size);

GLuint compile(GLuint type, const GLchar* source) {
    GLuint shader = glCreateShader(type); //TODO check
    glShaderSource(shader, 1, (const GLchar**) &source, 0); //TODO check
    glCompileShader(shader); //TODO check

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled); //TODO check

    GLint length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length); //TODO check

    std::string log(length, ' ');
    glGetShaderInfoLog(shader, length, &length, &log[0]); //TODO check
    std::cout<<log<<"\n";

    if (!compiled) {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length); //TODO check

        std::string log(length, ' ');
        glGetShaderInfoLog(shader, length, &length, &log[0]); //TODO check

        //throw std::logic_error(log);
        printf("Error\n");
        return false;
    }

    return shader;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);

    glutCreateWindow("GLUT Program");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    data = new uint32_t[width * height];

    GLuint vertex_shader = compile(GL_VERTEX_SHADER, vertex_shader_code); //TODO check vertex shader
    GLuint fragment_shader = compile(GL_FRAGMENT_SHADER, color_shader_code); //TODO check fragment shader

    prog = glCreateProgram(); //TODO check program
    glAttachShader(prog, vertex_shader); //TODO check
    glAttachShader(prog, fragment_shader); //TODO check
    glLinkProgram(prog); //TODO check

    glGenTextures(1, &texture); //TODO check
    glBindTexture(GL_TEXTURE_2D, texture); //TODO check
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //TODO check
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //TODO check

    int rc = load_texture("input.jpg", (uint8_t*) data, 0, width); //TODO check

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); //TODO check

    glutMainLoop();

    delete[] data;
    return EXIT_SUCCESS;
}

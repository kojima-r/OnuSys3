#version 120
invariant gl_Position;
attribute vec3 qt_Vertex;
attribute vec2 qt_cood;
varying vec2 qt_TexCoord0;

void main(void)
{
    gl_Position = vec4(qt_Vertex,1);
    qt_TexCoord0 = qt_cood;
}


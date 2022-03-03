#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aUv;

uniform mat4 uProjectionMatrix;
uniform mat4 uViewMatrix;

out vec2 TexCoord;
void main()
{
    // mat4 vp = mat4(
    //     2.639568, 0       ,  0   , 0,
    //     0       , 2.414213,  0   , 0,
    //     0       , 0       , -1   ,-1,
    //     0       , 0       ,  0.98, 1
    // );
    // mat4 p = mat4(
    //     2.639568, 0       ,  0   , 0,
    //     0       , 2.414213,  0   , 0,
    //     0       , 0       , -1   ,-1,
    //     0       , 0       , -0.02, 0
    // );
    // mat4 v = mat4(
    //     1       , 0       ,  0   , 0,
    //     0       , 1       ,  0   , 0,
    //     0       , 0       ,  1   , 0,
    //     0       , 0       , -1   , 1
    // );
    gl_Position = uProjectionMatrix * uViewMatrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    TexCoord = vec2(aUv.x, aUv.y);
}
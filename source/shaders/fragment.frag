#version 430 core

out vec4 FragColor;

float random (vec2 st) 
{
    return fract(sin(dot(st.xy, vec2(12.9898,78.233))) * 43758.5453123);
}

vec3 random_color () 
{
    vec2 st = gl_FragCoord.xy / 16.0;
    float R = random(floor(st * 1.0));
    float G = random(floor(st * 1.1));
    float B = random(floor(st * 0.9));
    return vec3(R, G, B);
}

void main()
{
    vec3 color = random_color();
    //vec3 color = vec3(0.0, 0.68, 0.0); // hacker green

    FragColor = vec4(color, 1.0);
}
#version 430 core

uniform float uTime;
out vec4 FragColor;

float random (vec2 st) 
{
    float minVal = 0.33;
    float maxVal = 1.0;
    float r = fract(sin(dot(st.xy, vec2(12.9898,78.233))) * 43758.5453123);
    return minVal + r * (maxVal - minVal);
}

vec3 random_color () 
{
    vec2 st = gl_FragCoord.xy / 16.0;
    float R = random(floor(st * 1.0));
    float G = random(floor(st * 1.1));
    float B = random(floor(st * 0.9));
    return vec3(R, G, B);
}

float DiscreteTimeUpdate(float updatesPerSecond) 
{
    return floor(uTime * updatesPerSecond);
}

void main()
{
    //vec3 color = random_color();
    //vec3 color = vec3(0.0, 0.68, 0.0); // hacker green

    vec2 uv = floor(gl_FragCoord.xy / 32.0);
    float randomDiscreteGreens = random(uv + DiscreteTimeUpdate(4.0));
    float randomContinuousGreens = 0.8 + 0.5 * sin(uTime + random(floor(uv)) * 10.0);

    //vec3 color = vec3(0.0, randomDiscreteGreens, 0.0); // Random greens only (Discrete)
    vec3 color = vec3(0.0, randomContinuousGreens, 0.0); // Random greens only (Continuous)

    FragColor = vec4(color, 1.0);
}
#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

void main()
{
    gl_Position = position;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform float u_Color;
uniform vec2 u_Resolution;

vec3 palette( in float t)
{
    vec3 a = vec3(0.5, 0.5, 0.5);
    vec3 b = vec3(0.5, 0.5, 0.5);
    vec3 c = vec3(1., 1., 1.);
    vec3 d = vec3(0.263, 0.416, 0.557);
    return a + b * cos(6.28318 * (c * t + d) );
}

void main() {
    vec2 fragCoord = gl_FragCoord.xy;

    vec2 uv = (fragCoord * 2.0 - u_Resolution) / u_Resolution;

    float d = length(uv);
    // float teta = atan(uv.y, uv.x);
    // if (teta < 0.0) {
    //     teta += 2.0 * 3.14159;
    // }

    // float radius = 0.5 - sin(teta)*0.5;

    // float intensity = abs(sin(20*d + u_Color*2) - radius);
    // intensity = smoothstep (0.f, 0.2f, intensity);

    // intensity = 0.3 / intensity;

    // vec3 FragColor = palette(d) * intensity;
    
    // // Map radius to color intensity

    // color = vec4(FragColor, 1.0);

    vec3 col = palette(d);

    // d *= (1 - cos(8.0f * d + u_Color) / 8);

    d = sin(4.0f * d + u_Color) / 8;
    d = abs(d);

    d = smoothstep(0.0f, 0.1f, d);
    
    d = 0.4 / d;
    

    col *= d;

    color = vec4(col, 1.0);
};
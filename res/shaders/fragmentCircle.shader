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

    vec2 uv0 = (fragCoord * 2.0 - u_Resolution) / u_Resolution.y;
    vec2 uv = uv0;

    float d = length(uv);
    vec3 col = palette(d);

    d = sin(4.0f * d + u_Color) / 8;
    d = abs(d);

    d = smoothstep(0.0f, 0.1f, d);
    
    d = 0.4 / d;
    

    col *= d;

    color = vec4(col, 1.0);
};
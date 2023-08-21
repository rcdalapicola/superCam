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

    vec2 uv0 = (fragCoord * 2.0 - u_Resolution) / u_Resolution.y;
    vec2 uv = uv0;

    float d = length(uv);
    // """"HEART SHAPED"""""
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

    // REGULAR CIRCLE
    // vec3 col = palette(d);

    // d = sin(4.0f * d + u_Color) / 8;
    // d = abs(d);

    // d = smoothstep(0.0f, 0.1f, d);
    
    // d = 0.4 / d;
    

    // col *= d;

    // color = vec4(col, 1.0);

    // CRAZY FRACTAL
    vec3 finalColor = vec3(0.0);
    for (float i = 0; i < 4; i++) {
        uv = 1.7 * uv;
        uv = fract(uv);
        uv -= 0.5;
        d = length(uv);
        vec3 col = palette(length(uv0) + u_Color / (2 * i + 2));

        d = sin(8.0f * d + u_Color * (i + 1) / 4) / 8;
        d = abs(d);

        // d = smoothstep(0.0f, 0.1f, d);
        
        // d = pow(0.01 / d, 1.2);
        d = pow(d, 0.6);
        
        finalColor += col * d;
    }
    color = vec4(finalColor, 1.0);
};
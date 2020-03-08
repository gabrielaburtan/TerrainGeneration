#version 330

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
    vec4 texColor=texture(texture1, TexCoord);
    if(texColor.a < 0.3)
        discard;
    FragColor=texColor;
}

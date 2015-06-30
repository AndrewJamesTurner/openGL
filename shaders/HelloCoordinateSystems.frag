#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform float mixture;

void main()
{
	//color = texture(ourTexture2, TexCoord);
    color = mix( texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), mixture );
    //color = texture(ourTexture1, TexCoord) * vec4(ourColor, 1.0f);  
    
    //vec2 faceOtherWay = vec2(1 - TexCoord.x, TexCoord.y);
    
    //color = mix( texture(ourTexture1, TexCoord), texture(ourTexture2, faceOtherWay), 0.2 ) * vec4(ourColor, 1.0f);  
}

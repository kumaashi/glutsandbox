#version 450

layout(binding=0) uniform sampler2D color_tex0;
layout(binding=1) uniform sampler2D color_tex1;
layout(binding=2) uniform sampler2D color_tex2;
layout(binding=3) uniform sampler2D color_tex3;
layout(binding=4) uniform sampler2D depth_tex ;

in  vec2 v_uv;
out vec4 FragColor;

void main() {
	FragColor = vec4(0.0);
	FragColor += texture(color_tex0, v_uv);
	FragColor += texture(color_tex1, v_uv);
	FragColor += texture(color_tex2, v_uv);
	FragColor += texture(color_tex3, v_uv);
	FragColor += texture(depth_tex , v_uv);
	FragColor /= 5.0;
}


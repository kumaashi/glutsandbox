#version 450

layout(binding=0) uniform sampler2D color_tex0;
layout(binding=1) uniform sampler2D color_tex1;
layout(binding=2) uniform sampler2D color_tex2;
layout(binding=3) uniform sampler2D color_tex3;
layout(binding=4) uniform sampler2D depth_tex ;

uniform vec4 info;

in  vec2 v_uv;
out vec4 FragColor;

void main() {
	vec2 uv = v_uv * 0.5 + 0.5;
	FragColor = vec4(0.0);
	FragColor += texture(color_tex0, uv);
	vec3 N = texture(color_tex1, uv).xyz;
	float cn = cos(0.5);
	float sn = sin(0.5);
	vec3 L = normalize(vec3(5.0 * cn, 5.0, -5.0 * sn));
	FragColor *= max(0.2, dot(L, N));
	FragColor += texture(color_tex2, uv);
	FragColor += texture(color_tex3, uv);
	if(uv.x > 0.5) {
		FragColor = vec4(N, 1.0);
		//FragColor *= vec4( pow(texture(depth_tex , uv).r, 32.0) );
	}
}


#version 450

layout(binding=0) uniform sampler2D color_tex_gbuffer0;
layout(binding=1) uniform sampler2D color_tex_gbuffer1;
layout(binding=2) uniform sampler2D color_tex_gbuffer2;
layout(binding=3) uniform sampler2D color_tex_blur0   ;

uniform vec4 info;
uniform vec4 eyepos;
uniform vec4 lightdir;
uniform vec4 lightcolor;
uniform mat4 view;
uniform mat4 proj;
in      vec2 v_uv;
out     vec4 FragColor;

void main() {
	vec2 uv = v_uv * 0.5 + 0.5;
	FragColor = vec4(0.0);
	vec3  albedo      = texture(color_tex_gbuffer0, uv).xyz;
	float shadow      = texture(color_tex_gbuffer0, uv).w;
	vec3  N           = texture(color_tex_gbuffer1, uv).xyz;
	float D           = texture(color_tex_gbuffer1, uv).w;
	vec3  world_pos   = texture(color_tex_gbuffer2, uv).xyz;
	float S           = texture(color_tex_gbuffer2, uv).w;
	vec4  blur_color  = texture(color_tex_blur0, uv);
	float ssao        = pow(blur_color.x, 2.0);
	float emit        = pow(blur_color.y, 5.0);
	float blur_shadow = blur_color.z;
	vec3 color        = albedo;
	if(true) {
		color *= (D + S + 0.5) * lightcolor.xyz;
		//color += emit * lightcolor.xyz;
		color *= mix(shadow, blur_shadow, 0.25);
		color *= ssao;
	}
	if(uv.x > 0.5) {
		color = vec3(ssao);
	}
	FragColor.xyz   = color;
	FragColor.w     = 1.0;
	return;
}

